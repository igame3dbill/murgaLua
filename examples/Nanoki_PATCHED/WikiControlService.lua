--------------------------------------------------------------------------------
-- Title:               WikiControlService.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- import dependencies
local HTTP = require( 'HTTP' )
local HTTPExtra = require( 'HTTPExtra' )
local HTTPService = require( 'HTTPService' )
local Template = require( 'Template' )
local Wiki = require( 'Wiki' )
local WikiContent = require( 'WikiContent' )
local WikiContentService = require( 'WikiContentService' )
local WikiService = require( 'WikiService' )

local BaseLink = WikiService.BaseLink
local DateLink = WikiService.DateLink
local FeedLink = WikiService.FeedLink
local IndexLink = WikiService.IndexLink

local Encode = WikiService.Encode
local Path = WikiService.Path

local os = require( 'os' )

local getmetatable = getmetatable
local ipairs = ipairs
local pairs = pairs
local pcall = pcall
local require = require
local setmetatable = setmetatable
local tonumber = tonumber
local tostring = tostring
local type = type

--------------------------------------------------------------------------------
-- WikiControlService
--------------------------------------------------------------------------------

module( 'WikiControlService' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

local function Message( self )
    local aMessage = self.message
    
    if aMessage then
        local someTypes = { authorization = 'warning', check = 'error', count = 'warning', delete = 'error', rename = 'error', time = 'warning', token = 'error', value = 'warning' }
        local aType = someTypes[ self.type ] or 'warning'
        local WikiMessage = require( 'WikiMessage' )
        local aMessage = WikiMessage( aMessage, aType )
        
        return aMessage
    end
end

local function Token()
    local Token = require( 'Token' )
    local aToken = Token( HTTP.request.url )
    local aList = { 'check', 'count', 'delete', 'rename', 'time', 'token', 'value' }
    local aMap = {}
    
    for _, aValue in ipairs( aList ) do
        aMap[ aValue ] = aToken[ aValue ]
    end
    
    return aMap
end

local function Context()
    local someTypes = { check = nil, count = 'number', delete = 'string', rename = 'string', time = 'number', token = 'string', value = 'string' }
    local someFunctions = { check = nil, count = tonumber, delete = tostring, rename = tostring, time = tonumber, token = tostring, value = tostring }
    local aToken = Token()
    local aParameter = HTTP.request.parameter
    local aContext = {}
    
    for aKey, aValue in pairs( aToken ) do
        local aType = someTypes[ aKey ]
        local aFunction = someFunctions[ aKey ]
        local aValue = aParameter[ aValue ]

        if aValue and aFunction then
            aValue = aFunction( aValue )
        end

        if aValue and tostring( aValue ):len() == 0 then
            aValue = nil
        end
        
        if not aType or type( aValue ) == aType then
            aContext[ aKey ] = aValue
        end
    end
    
    return aContext
end

local function Validate( aKey, aValue, aName )
    local aContext = Context()
    local anAuthorization = HTTP.request.authorization
    
    if aContext.check then
        return false, 'check', 'Invalid data. Try again.'
    end
    
    if not aContext.time or ( os.time() - aContext.time ) < 3 then
        return false, 'time', 'Too fast. Try again, but slowly.'
    end
    
    if not aContext.token or aContext.token ~= Token()[ 'token' ] then
        return false, 'token', 'Invalid data. Try again.'
    end
    
    if aKey == 'rename' 
    and ( not aContext.value
    or not WikiContent[ aContext.value ] 
    or WikiContent[ aContext.value ] == aName ) then
        return false, 'name', 'Invalid name. Try to a different one.'
    end

    if aValue ~= Token()[ aKey ] then
        return false, aKey, 'Invalid data. Try again.'
    end

    if aKey == 'delete' 
    and ( not aContext.count or aContext.count < 2 ) then
        local aMessage = ( 'Are you sure you want to %s “%s”? If yes, press “%s” again.' ):format( aKey, aName, aKey )
    
        return false, 'count', aMessage
    end

    if aKey == 'rename' 
    and ( not aContext.count or aContext.count < 2 ) then
        local aValue = WikiContent[ aContext.value ]
        local aMessage = ( 'Are you sure you want to %s “%s” to “%s”? If yes, press “%s” again.' ):format( aKey, aName, aValue, aKey )
    
        return false, 'count', aMessage
    end

    if not anAuthorization.user 
    or not anAuthorization.password 
    or anAuthorization.password ~= aName then
        HTTP.response.authorization.realm = 'Nanoki'
    
        return false, 'authorization', 'Invalid authorization. Please identify yourself, using the page name as the password.'
    end
            
    return true
end

--------------------------------------------------------------------------------
-- Service methods
--------------------------------------------------------------------------------

function self:get()
    local aLayoutTemplate = Template[ 'WikiLayout.txt' ]
    local aTemplate = Template[ 'WikiControlService.txt' ]
    local aContent = self.content
    local aDate = os.date( '!*t', aContent.creation )
    local aDateLink = DateLink( aDate.year, aDate.month, aDate.day )
    local aContext = Context()
    local aToken = Token()
    
    aTemplate[ 'actionPath' ] = Encode( HTTP.request.url.path )
    aTemplate[ 'title' ] = Encode( aContent.data.title .. ' — Control' )
    aTemplate[ 'message' ] = Message( self )
    aTemplate[ 'name' ] = Encode( aContent.name )

    aTemplate[ 'checkToken' ] = Encode( aToken.check )
    aTemplate[ 'check' ] = Encode( aContext.check )
    aTemplate[ 'countToken' ] = Encode( aToken.count )
    aTemplate[ 'count' ] = Encode( ( aContext.count or 0 ) + 1 )
    aTemplate[ 'deleteToken' ] = Encode( aToken.delete )
    aTemplate[ 'renameToken' ] = Encode( aToken.rename )
    aTemplate[ 'timeToken' ] = Encode( aToken.time )
    aTemplate[ 'time' ] = Encode( os.time() )
    aTemplate[ 'token' ] = Encode( aToken.token )
    aTemplate[ 'valueToken' ] = Encode( aToken.value )
    aTemplate[ 'value' ] = Encode( aContext.value or aContent.name )

    aLayoutTemplate[ 'baseLink' ] = Encode( BaseLink() )
    aLayoutTemplate[ 'indexLink' ] = Encode( IndexLink( aContent.prefix ) )
    aLayoutTemplate[ 'dateLink' ] = Encode( aDateLink )
    aLayoutTemplate[ 'feedLink' ] = FeedLink()
    aLayoutTemplate[ 'path' ] = Path( self )
    aLayoutTemplate[ 'query' ] = nil
    aLayoutTemplate[ 'robot' ] = 'noindex,nofollow'
    aLayoutTemplate[ 'title' ] = Encode( aContent.data.title .. ' — Control' )    
    aLayoutTemplate[ 'content' ] = aTemplate

    return tostring( aLayoutTemplate )
end

function self:postDelete( aToken )
    local aContent = self.content
    local isValid, aType, aMessage = Validate( 'delete', aToken, aContent.name )
    
    if isValid then
        local aName = aContent.name
        local aCall = function()
            Wiki[ aName ] = false
        end
        local aStatus, anException = pcall( aCall )

        if aStatus then
            local WikiEditorService = require( 'WikiEditorService' )
            local aLogContent = WikiContent( 'log' )
            local aMessage = ( 'Deleted “%s”.' ):format( aName )
            local aText = ( '%s    \n_%s_    ' ):format( aLogContent.text, aMessage )
            local aContext = { title = aLogContent.data.title, text = aText, version = aLogContent.version }
            local aService = WikiEditorService( aLogContent )

            aService( aLogContent.name, aContext )
            
            return nil, HTTPService[ WikiContentService( aLogContent ) ]
        end

        self.message = anException
        self.type = 'delete'
    end

    self.message = aMessage
    self.type = aType
    
    return self:get()
end

function self:postRename( aToken )
    local aContent = self.content
    local isValid, aType, aMessage = Validate( 'rename', aToken, aContent.name )
    
    if isValid then
        local aName = aContent.name
        local aNewName = Context()[ 'value' ]
        local aCall = function()
            Wiki[ aName ] = aNewName
        end
        local aStatus, anException = pcall( aCall )
        
        if aStatus then
            local WikiEditorService = require( 'WikiEditorService' )
            local aNewContent = WikiContent( aNewName )
            local aMessage = ( 'Renamed from “%s” to “%s”.' ):format( aName, aNewName )
            local aText = ( '%s    \n_%s_    ' ):format( aNewContent.text, aMessage )
            local aContext = { title = aNewContent.data.title, text = aText, version = aNewContent.version }
            local aService = WikiEditorService( aNewContent )

            aService( aNewContent.name, aContext )
            
            return nil, HTTPService[ WikiContentService( aNewContent ) ]
        end
        
        self.message = anException
        self.type = 'rename'
    end

    self.message = aMessage
    self.type = aType
    
    return self:get()
end

--------------------------------------------------------------------------------
-- Metamethods
--------------------------------------------------------------------------------

function meta:__call( aContent, aParent )
    local aControl = { content = aContent, parent = aParent }
    
    setmetatable( aControl, self )
    self.__index = self    
    
    return aControl
end

function self:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function self:__tostring()
    return 'Control'
end
