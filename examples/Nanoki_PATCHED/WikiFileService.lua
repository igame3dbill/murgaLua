--------------------------------------------------------------------------------
-- Title:               WikiFileService.lua
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
local MIME = require( 'MIME' )
local MIMEType = require( 'MIMEType' )
local NaturalComparator = require( 'NaturalComparator' )
local Template = require( 'Template' )
local WikiContentService = require( 'WikiContentService' )
local WikiService = require( 'WikiService' )

local BaseLink = WikiService.BaseLink
local DateLink = WikiService.DateLink
local FeedLink = WikiService.FeedLink
local IndexLink = WikiService.IndexLink

local Description = WikiService.Description
local Encode = WikiService.Encode
local FormatDateTime = WikiService.FormatDateTime
local Path = WikiService.Path

local os = require( 'os' )
local table = require( 'table' )

local getmetatable = getmetatable
local ipairs = ipairs
local pairs = pairs
local setmetatable = setmetatable
local require = require
local tonumber = tonumber
local tostring = tostring
local type = type

--------------------------------------------------------------------------------
-- WikiFileService
--------------------------------------------------------------------------------

module( 'WikiFileService' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

local function Message( self )
    local aMessage = self.message
    
    if aMessage then
        local someTypes = { add = 'info', check = 'error', count = 'warning', delete = 'info', name = 'warning', time = 'warning', token = 'error' }
        local aType = someTypes[ self.type ] or 'warning'
        local WikiMessage = require( 'WikiMessage' )
        local aMessage = WikiMessage( aMessage, aType )
        
        return aMessage
    end
end

local function SizeFormat( aSize )
    local aFormat = tostring( aSize )
    
    if aFormat:len() > 3 then 
        aFormat = aFormat:reverse()
        aFormat = aFormat:gsub( "(%d%d%d)", "%1," )
        aFormat = aFormat:reverse()
        
        if aFormat:sub( 1, 1 ) == "," then
            aFormat = aFormat:sub( 2 )
        end
    end

    if aSize > 1 then
        aFormat = aFormat .. ' bytes'
    else
        aFormat = aFormat .. ' byte'
    end
    
    return aFormat
end

local function Size( aSize )
    local anUnit = { 'KB', 'MB', 'GB' }
    local aType = 1
    
    aSize = aSize / 1024
    
    while aSize > 999 do
        aSize = aSize / 1024
        aType = aType + 1
    end
    
    return ( '%.1f %s' ):format( aSize, anUnit[ aType ] or '' )
end

local function FileToken( anIterator )
    local Token = require( 'Token' )
    local aToken = Token( HTTP.request.url .. '.file' )
    local aMap = {}
    
    for aFile in anIterator do
        aMap[ aFile.name ] = aToken[ aFile.name ]   
    end
    
    return aMap
end

local function FileContext( aContent, aNameToken, aSizeToken, aTimeToken )
    local aFileToken = FileToken( aContent.file )
    local aFileName = nil 
    
    for aKey, aValue in pairs( aFileToken ) do
        if aValue == aNameToken then
            aFileName = aKey
            break
        end
    end
    
    for aFile in aContent.file do
        if aFile.name == aFileName then
            local aParameter = HTTP.request.parameter
            local aSizeKey = ( '%s.%s' ):format( aNameToken, aSizeToken )
            local aSize = tonumber( aParameter[ aSizeKey ] ) 
            local aTimeKey = ( '%s.%s' ):format( aNameToken, aTimeToken )
            local aTime = tonumber( aParameter[ aTimeKey ] ) 
            
            if aFile.size == aSize 
            and aFile.modification == aTime then
                return aFile
            end
        end
    end
end

local function HasFile( anIterator, aName )
    for aFile in anIterator do
        if aFile.name == aName then
            return true
        end
    end

    return false
end

local function Token()
    local Token = require( 'Token' )
    local aToken = Token( HTTP.request.url )
    local aList = { 'check', 'count', 'file', 'time', 'size', 'token' }
    local aMap = {}
    
    for _, aValue in ipairs( aList ) do
        aMap[ aValue ] = aToken[ aValue ]
    end
    
    return aMap
end

local function Context()
    local someTypes = { check = nil, count = 'number', time = 'number', token = 'string' }
    local someFunctions = { check = nil, count = tonumber, time = tonumber, token = tostring }
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

local function Validate( aKey, aValue )
    local aContext = Context()
    
    if aContext.check then
        return false, 'check', 'Invalid data. Try again.'
    end

    if type( aValue ) ~= 'string' or aValue:len() < 3 then
        return false, 'name', 'Invalid file name. Try again.'
    end

    if not aContext.time or ( os.time() - aContext.time ) < 3 then
        return false, 'time', 'Too fast. Try again, but slowly.'
    end
    
    if not aContext.token or aContext.token ~= Token()[ 'token' ] then
        return false, 'token', 'Invalid data. Try again.'
    end

    if not aContext.count or aContext.count < 2 then
        local aMessage = ( 'Are you sure you want to %s this file? If yes, press “%s” again.' ):format( aKey, aKey )
    
        return false, 'count', aMessage
    end
        
    return true
end

local function FileComparator( aFile, anotherFile )
    return NaturalComparator()( aFile.name, anotherFile.name )
end

local function FileIterator( anIterator )
    local aList = {}
    local anIndex = 0
    
    for aFile in anIterator do
        aList[ #aList + 1 ] = aFile
    end
    
    table.sort( aList, FileComparator )
    
    return function()
        anIndex = anIndex + 1
    
        if anIndex <= #aList then
            return aList[ anIndex ]
        end
        
    end
end

--------------------------------------------------------------------------------
-- Service methods
--------------------------------------------------------------------------------

function self:get()
    local aLayoutTemplate = Template[ 'WikiLayout.txt' ]
    local aTemplate = Template[ 'WikiFileService.txt' ]
    local aFileTemplate = aTemplate[ 'files' ]
    local aContent = self.content
    local aFileToken = FileToken( aContent.file )
    local aToken = Token()
    local aContext = Context()
    local aContentPath = HTTPService[ WikiContentService( aContent ) ].path
    local aDate = os.date( '!*t', aContent.creation )
    local aDateLink = DateLink( aDate.year, aDate.month, aDate.day )
    local aCount = 0

    aTemplate[ 'action' ] = Encode( HTTP.request.url.path )
    aTemplate[ 'title' ] = Encode( aContent.data.title .. ' — File' )
    aTemplate[ 'message' ] = Message( self )

    aTemplate[ 'checkToken' ] = Encode( aToken.check )
    aTemplate[ 'check' ] = Encode( aContext.check )
    aTemplate[ 'countToken' ] = Encode( aToken.count )
    aTemplate[ 'count' ] = Encode( ( aContext.count or 0 ) + 1 )
    aTemplate[ 'fileToken' ] = Encode( aToken.file )
    aTemplate[ 'timeToken' ] = Encode( aToken.time )
    aTemplate[ 'time' ] = Encode( os.time() )
    aTemplate[ 'token' ] = Encode( aToken.token )
    
    aTemplate[ 'files' ] = nil
    
    for aFile in FileIterator( aContent.file ) do
        local aFileTemplate = aTemplate[ 'files' ]
        local aType = MIMEType[ aFile.extension ] or 'application/octet-stream'
        
        aFileTemplate[ 'nameLink' ] = Encode( aContentPath( 'file.' .. aFile.name ) )
        aFileTemplate[ 'name' ] = Encode( aFile.name )
        aFileTemplate[ 'type' ] = Encode( aType )
        aFileTemplate[ 'sizeTitle' ] = Encode( SizeFormat( aFile.size ) )
        aFileTemplate[ 'size' ] = Encode( Size( aFile.size ) )
        aFileTemplate[ 'dateTitle' ] = Encode( FormatDateTime( aFile.modification ) )
        aFileTemplate[ 'date' ] = Encode( os.date( '%b. %d %Y', aFile.modification ) )
        aFileTemplate[ 'nameToken' ] = Encode( aFileToken[ aFile.name ] )
        aFileTemplate[ 'fileSizeToken' ] = Encode( aToken.size )
        aFileTemplate[ 'fileSize' ] = Encode( aFile.size )
        aFileTemplate[ 'fileTimeToken' ] = Encode( aToken.time )
        aFileTemplate[ 'fileTime' ] = Encode( aFile.modification )
        
        aTemplate[ 'files' ] = aFileTemplate
        aCount = aCount + 1
    end
    
    aTemplate[ 'description' ] = Encode( Description( aCount ) )
    
    aLayoutTemplate[ 'baseLink' ] = Encode( BaseLink() )
    aLayoutTemplate[ 'indexLink' ] = Encode( IndexLink( aContent.prefix ) )
    aLayoutTemplate[ 'dateLink' ] = Encode( aDateLink )
    aLayoutTemplate[ 'feedLink' ] = FeedLink()
    aLayoutTemplate[ 'path' ] = Path( self )
    aLayoutTemplate[ 'query' ] = nil
    aLayoutTemplate[ 'robot' ] = 'noindex,nofollow'
    aLayoutTemplate[ 'title' ] = Encode( aContent.data.title .. ' — File' )
    aLayoutTemplate[ 'content' ] = aTemplate

    return tostring( aLayoutTemplate )
end

function self:postAdd()
    local File = require( 'File' )
    local aParameter = HTTP.request.parameter
    local aToken = Token()[ 'file' ]
    local aFileKey = ( '%s.filename' ):format( aToken )
    local aFileName = aParameter[ aFileKey ]
    local isValid, aType, aMessage = Validate( 'add', aFileName )
    
    if isValid then
        local WikiContent = require( 'WikiContent' )
        local aFileName = aFileName:gsub( '[\\/]', File.separator )
        local aFile = File( aFileName )
        
        if aFile.name and aFile.name:len() and WikiContent[ aFile.name ] 
        and aFile.extension and aFile.extension:len() > 0 and WikiContent[ aFile.extension ] then
            local aFileExtension = aFile.extension
            local aFileName = aFile.name:sub( 1, aFile.name:len() - aFileExtension:len() - 1 )
            local aFileName = ( '%s.%s' ):format( WikiContent[ aFileName ], WikiContent[ aFileExtension ] )
            local aFile = { name = aFileName, extension = aFileExtension, content = aParameter[ aToken ] }
            
            if HasFile( self.content.file, aFile.name ) then
                self.message = ( 'The file “%s” already exists. Try a different one.' ):format( aFile.name )
                self.type = 'name'
            else
                local WikiEditorService = require( 'WikiEditorService' )
                local aContent = self.content
                local aMessage = ( 'Added the file “%s”.' ):format( aFile.name )
                local aText = ( '%s    \n_%s_    ' ):format( aContent.text, aMessage )
                local aContext = { title = aContent.data.title, text = aText, version = aContent.version }
                local aService = WikiEditorService( aContent )
                
                aContent.file = aFile
                aService( aContent.name, aContext )
        
                self.message = aMessage
                self.type = 'add'
            end
        else
            self.message = 'Invalid file name. Try again.'
            self.type = 'name'
        end
    else
        self.message = aMessage
        self.type = aType
    end
    
    return self:get()
end

function self:postDelete( aNameToken )
    local isValid, aType, aMessage = Validate( 'delete', aNameToken )
    
    if isValid then
        local aToken = Token()
        local aFile = FileContext( self.content, aNameToken, aToken.size, aToken.time )

        if aFile then
            local WikiEditorService = require( 'WikiEditorService' )
            local aContent = self.content
            local aMessage = ( 'Deleted the file “%s”.' ):format( aFile.name )
            local aText = ( '%s    \n_%s_    ' ):format( aContent.text, aMessage )
            local aContext = { title = aContent.data.title, text = aText, version = aContent.version }
            local aService = WikiEditorService( aContent )

            aFile.delete = true
            aService( aContent.name, aContext )
            
            self.message = aMessage
            self.type = 'delete'
        else
            self.message = 'File mismatch. Try again.'
            self.type = 'name'
        end
    else
        self.message = aMessage
        self.type = aType
    end

    return self:get()
end

--------------------------------------------------------------------------------
-- Metamethods
--------------------------------------------------------------------------------

function meta:__call( aContent, aParent )
    local aFile = { content = aContent, parent = aParent }
    
    setmetatable( aFile, self )
    self.__index = self    
    
    return aFile
end

function self:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function self:__tostring()
    return 'File'
end

