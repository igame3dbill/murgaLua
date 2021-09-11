--------------------------------------------------------------------------------
-- Title:               WikiEditorService.lua
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
local WikiContent = require( 'WikiContent' )
local WikiDate = require( 'WikiDate' )
local WikiRecent = require( 'WikiRecent' )
local WikiSearch = require( 'WikiSearch' )
local WikiContentService = require( 'WikiContentService' )
local WikiService = require( 'WikiService' )

local BaseLink = WikiService.BaseLink
local DateLink = WikiService.DateLink
local FeedLink = WikiService.FeedLink
local IndexLink = WikiService.IndexLink

local Encode = WikiService.Encode
local Path = WikiService.Path

local os = require( 'os' )

local assert = assert
local getmetatable = getmetatable
local ipairs = ipairs
local pairs = pairs
local require = require
local setmetatable = setmetatable
local tonumber = tonumber
local tostring = tostring
local type = type

--------------------------------------------------------------------------------
-- WikiEditorService
--------------------------------------------------------------------------------

module( 'WikiEditorService' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

local function Message( self )
    local aMessage = self.message
    
    if aMessage then
        local someTypes = { check = 'error', count = 'error', time = 'warning', title = 'warning', text = 'warning', token = 'error', version = 'warning' }
        local aType = someTypes[ self.type ] or 'warning'
        local WikiMessage = require( 'WikiMessage' )
        local aMessage = WikiMessage( aMessage, aType )
        
        return aMessage
    end
end

local function Token()
    local Token = require( 'Token' )
    local aToken = Token( HTTP.request.url )
    local aList = { 'check', 'count', 'time', 'title', 'text', 'token', 'version' }
    local aMap = {}
    
    for _, aValue in ipairs( aList ) do
        aMap[ aValue ] = aToken[ aValue ]
    end
    
    return aMap
end

local function Context()
    local someTypes = { check = nil, count = 'number', time = 'number', title = 'string', text = 'string', token = 'string', version = 'number' }
    local someFunctions = { check = nil, count = tonumber, time = tonumber, title = tostring, text = tostring, token = tostring, version = tonumber }
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

local function Validate( aName )
    local aContext = Context()
    
    if aContext.check then
        return false, 'check', 'Invalid data. Try again.'
    end
    
    if not aContext.count or aContext.count < 1 then
        return false, 'count', 'Invalid data. Try again.'
    end
    
    if not aContext.time or ( os.time() - aContext.time ) < 3 then
        return false, 'time', 'Too fast. Try again, but slowly.'
    end
    
    if not aContext.title or not WikiContent[ aContext.title ] then
        return false, 'title', 'Empty title. Try to add some text.'
    end
    
    if not aContext.text or not WikiContent[ aContext.text ] then
        return false, 'text', 'Empty content. Try to add some text.'
    end
    
    if not aContext.token or aContext.token ~= Token()[ 'token' ] then
        return false, 'token', 'Invalid data. Try again.'
    end
    
    if not aContext.version or aContext.version ~= WikiContent( aName ).version then
        return false, 'version', 'Version mismatch. Try to edit the latest version.'
    end
    
    return true
end

local function ID()
    local aRequest = HTTP.request
    local aScheme = aRequest.url.scheme or 'http'
    local aUser = WikiContent[ aRequest.authorization.user or 'anonymous' ]
    local anAddress = WikiContent[ aRequest.address or '127.0.0.1' ]:gsub( '-', '.' )
    local aHost = aRequest.host or 'localhost'
    local anID = ( '%s://%s:%s@%s' ):format( aScheme, aUser, anAddress, aHost )
    
    return anID
end

local function Save( aName, aContext )
    local aName = assert( aName )
    local aContext = assert( aContext )
    local aVersion = assert( aContext.version )
    local aNewVersion = aVersion + 1
    local aContent = WikiContent( aName, aVersion )
    
    if not aContent.exists then
        aNewVersion = aContent.version
    end
    
    if aContent.data.title ~= aContext.title
    or aContent.text ~= aContext.text then
        local aNewContent = WikiContent( aName, aNewVersion )
        
        aNewContent.title = aContext.title
        aNewContent.text = aContext.text
        aNewContent.by = ID()
        aNewContent()

        if aVersion == 1 then
            WikiDate[ aNewContent.creation ] = aNewContent.name
            WikiSearch[ aNewContent.name ] = aNewContent.name
        end

        WikiRecent[ aNewContent.modification ] = aNewContent.name
        
        return aNewContent
    end
    
    return aContent
end

local function Title( aContent, aContext )
    return aContext.title or aContent.data.title
end

local function Text( aContent, aContext )
    return aContext.text or aContent.text
end

local function Version( aContent, aContext )
    return aContext.version or aContent.lastVersion
end

local function TitleLink( aContent )
    local aTitle = Encode( aContent.data.title )
    
    if aContent.exists then
        local aLink = Encode( HTTP.request.url.path( 'revision' ) )
        
        return ( '<a href=\'%s\' title=\'Revision history\' rel=\'nofollow\'>%s</a>' ):format( aLink, aTitle )
    end
    
    return aTitle
end

local function ControlLink( aContent )
    if aContent.exists then
        local aLink = Encode( HTTP.request.url.path( 'control' ) )
    
        return ( '<a href=\'%s\' title=\'Control\'><img src=\'/etc/control.png\' title=\'Control\' alt=\'control\' height=\'16\' width=\'16\' style=\'vertical-align: text-bottom;\'/></a>' ):format( aLink )
    end
end

local function FileCount( aContent )
    if aContent.exists then
        local aCount = 0
    
        for aFile in aContent.file do
            aCount = aCount + 1
        end
        
        return aCount
    end
end

local function FileLink( aContent )
    local aCount = FileCount( aContent )
    
    if aCount then
        local anImage = '<img src=\'/etc/file.png\' title=\'File:\' alt=\'File\' height=\'16\' width=\'16\' style=\'vertical-align: text-bottom;\'/>'
        local aLink = HTTP.request.url.path( 'file' )
        local aTitle = ''
    
        if aCount == 0 then
            aTitle = 'Add a file'
        elseif aCount == 1 then
            aTitle = '1 file'
        else
            aTitle = ( '%d files' ):format( aCount )
        end
        
        aLink = Encode( aLink )
        aTitle = Encode( aTitle )
    
        return ( '<p><a href=\'%s\' title=\'%s\'>%s %s</a></p>' ):format( aLink, aTitle, anImage, aTitle )
    end
end

--------------------------------------------------------------------------------
-- Service methods
--------------------------------------------------------------------------------

function self:get()
    local aLayoutTemplate = Template[ 'WikiLayout.txt' ]
    local aTemplate = Template[ 'WikiEditorService.txt' ]
    local aContent = self.content
    local aDate = os.date( '!*t', aContent.creation )
    local aDateLink = DateLink( aDate.year, aDate.month, aDate.day )
    local aContext = Context()
    local aToken = Token()
    
    aTemplate[ 'actionPath' ] = Encode( HTTP.request.url.path )
    aTemplate[ 'titleLink' ] = TitleLink( aContent )
    aTemplate[ 'message' ] = Message( self )
    aTemplate[ 'controlLink' ] = ControlLink( aContent )
    aTemplate[ 'fileLink' ] = FileLink( aContent )
    
    aTemplate[ 'checkToken' ] = Encode( aToken.check )
    aTemplate[ 'check' ] = Encode( aContext.check )
    aTemplate[ 'countToken' ] = Encode( aToken.count )
    aTemplate[ 'count' ] = Encode( aContext.count or 0 )
    aTemplate[ 'timeToken' ] = Encode( aToken.time )
    aTemplate[ 'time' ] = Encode( os.time() )
    aTemplate[ 'token' ] = Encode( aToken.token )
    
    aTemplate[ 'titleToken' ] = Encode( aToken.title )
    aTemplate[ 'title' ] = Encode( Title( aContent, aContext ) )
    aTemplate[ 'textToken' ] = Encode( aToken.text )
    aTemplate[ 'text' ] = Encode( Text( aContent, aContext ) )
    aTemplate[ 'versionToken' ] = Encode( aToken.version )
    aTemplate[ 'version' ] = Encode( Version( aContent, aContext ) )

    aLayoutTemplate[ 'baseLink' ] = Encode( BaseLink() )
    aLayoutTemplate[ 'indexLink' ] = Encode( IndexLink( aContent.prefix ) )
    aLayoutTemplate[ 'dateLink' ] = Encode( aDateLink )
    aLayoutTemplate[ 'feedLink' ] = FeedLink()
    aLayoutTemplate[ 'path' ] = Path( self )
    aLayoutTemplate[ 'query' ] = nil
    aLayoutTemplate[ 'robot' ] = 'noindex,nofollow'
    aLayoutTemplate[ 'title' ] = Encode( aContent.data.title .. ' — Editor' )
    aLayoutTemplate[ 'content' ] = aTemplate

    return tostring( aLayoutTemplate )
end

function self:getControl()
    if self.content.exists then
        local WikiControlService = require( 'WikiControlService' )
    
        return WikiControlService( self.content, self )
    end

    return nil, HTTPService[ WikiContentService( self.content ) ]
end

function self:getFile()
    if self.content.exists then
        local WikiFileService = require( 'WikiFileService' )
    
        return WikiFileService( self.content, self )
    end

    return nil, HTTPService[ WikiContentService( self.content ) ]
end

function self:getRevision()
    if self.content.exists then
        local WikiRevisionService = require( 'WikiRevisionService' )
    
        return WikiRevisionService( self.content, self )
    end
    
    return nil, HTTPService[ WikiContentService( self.content ) ]
end

function self:postEdit()
    return self:get()    
end

function self:postPreview()
    local WikiPreview = require( 'WikiPreview' )
    local aContext = Context()
    local aPath = Path( self )
    
    aPath[ #aPath ].title = 'Preview'
    aContext.path = aPath
    aContext.token = Token()
    
    return tostring( WikiPreview( self.content, self, aContext ) )
end

function self:postSave()
    local aName = self.content.name 
    local isValid, aType, aMessage = Validate( aName )
    
    if isValid then
        local aContext = Context()
        local aContent = Save( aName, aContext )
        
        return nil, HTTPService[ WikiContentService( aContent ) ]
    end
    
    self.message = aMessage
    self.type = aType
    
    return self:get()
end

--------------------------------------------------------------------------------
-- Metamethods
--------------------------------------------------------------------------------

function meta:__call( aContent, aParent )
    local anEditor = { content = aContent, parent = aParent }
    
    setmetatable( anEditor, self )
    self.__index = self    
    
    return anEditor
end

function self:__call( aName, aContext )
    return Save( aName, aContext )
end

function self:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function self:__tostring()
    return 'Editor'
end
