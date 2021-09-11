--------------------------------------------------------------------------------
-- Title:               WikiContentService.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- import dependencies
local HTTP = require( 'HTTP' )
local Template = require( 'Template' )
local URL = require( 'URL' )
local URLPath = require( 'URLPath' )
local WikiContent = require( 'WikiContent' )
local WikiService = require( 'WikiService' )

local BaseLink = WikiService.BaseLink
local DateLink = WikiService.DateLink
local FeedLink = WikiService.FeedLink
local IndexLink = WikiService.IndexLink

local ContentIterator = WikiService.ContentIterator
local NameIterator = WikiService.NameIterator
local Today = WikiService.Today
local Yesterday = WikiService.Yesterday
local LastWeek = WikiService.LastWeek

local Encode = WikiService.Encode
local FormatDate = WikiService.FormatDate
local FormatDateTime = WikiService.FormatDateTime
local GetType = WikiService.GetType
local HTML = WikiService.HTML
local Path = WikiService.Path

local os = require( 'os' )
local table = require( 'table' )

local getmetatable = getmetatable
local require = require
local setmetatable = setmetatable
local tonumber = tonumber
local tostring = tostring

--------------------------------------------------------------------------------
-- WikiContentService
--------------------------------------------------------------------------------

module( 'WikiContentService' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

local function Message( self )
    local aModification = self.content.modification
    local aTime = os.time()
    local anInterval = aTime - aModification
    
    if anInterval < 30 then
        local WikiMessage = require( 'WikiMessage' )
        local aText = FormatDateTime( self.content.modification )
        local aMessage = WikiMessage( ( 'Updated on %s.' ):format( aText ) )
        
        return aMessage
    end
end

local function EditorLink( self ) 
    local aContent = self.content
    local aTitle = Encode( aContent.data.title )
    
    if aContent.canWrite then
        local aLink = Encode( self.path( 'editor' ) )
    
        return ( '<a href=\'%s\' title=\'Editor\' rel=\'nofollow\'>%s</a>' ):format( aLink, aTitle )
    
    end
    
    return aTitle
end

local function Tag( aModification )
    local aDay = os.date( '!%A', aModification )
    local anHour = tonumber( os.date( '!%I', aModification ) )
    local aMeridian = os.date( '!%p', aModification )
    local aTag = nil
    local aLabel = nil
    
    if Today( aModification ) then
        aLabel = ( 'Edited today around %d %s' ):format( anHour, aMeridian )
        aTag = 1
    elseif Yesterday( aModification ) then
        aLabel = ( 'Edited yesterday around %d %s' ):format( anHour, aMeridian )
        aTag = 2
    elseif LastWeek( aModification ) then
        aLabel = ( 'Edited last %s around %d %s' ):format( aDay, anHour, aMeridian )
        aTag = 3
    end
    
    if aTag and aLabel then
        return ( '<img src=\'/etc/tag%d.png\' alt=\'tag\' title=\'%s\' class=\'navigation\' style=\'vertical-align: text-bottom;\' height=\'16\' width=\'16\'/>' ):format( aTag, aLabel )
    end
end

local function Robot( aModification )
    local aTime = os.time()
    local anInterval = aTime - ( aModification or aTime )
    
    if anInterval > 86400 then
        return 'index,follow'
    end
    
    return 'noindex,nofollow'
end

local function Referer( self )
    if self.content.name ~= 'main' 
    and self.content.name ~= 'markdown-syntax-reference' 
    and HTTP.request.header[ 'referer' ] then
        local URL = require( 'URL' )
        local aURL = URL( HTTP.request.header[ 'referer' ] )
        local aReferer = self.toObject( self, aURL )
        
        if aReferer 
        and aReferer.content.name ~= 'date' 
        and aReferer.content.name ~= 'index' 
        and aReferer.content.name ~= 'main' 
        and aReferer.content.name ~= 'markdown-syntax-reference' 
        and aReferer.content.name ~= 'recent' 
        and aReferer.content.name ~= 'search' 
        and aReferer.content.exists then
            self.content.link = aReferer.content.name
        end
    end
end

local function ValidFile( aContent, aName )
    local aReference = ( '%s/file.%s' ):format( aContent.name, aName )
    local isValid = aContent.text:find( aReference, 1, true )

    if not isValid then
    
        for aFile in aContent.file do
            if aFile.name == aName then
                local aTime = os.time()
                local anInterval = aTime - aFile.modification
                
                if anInterval < 3600 then
                    isValid = true
                else
                    aFile.delete = true
                end
            end
        end
    end
    
    return isValid
end

--------------------------------------------------------------------------------
-- Default content
--------------------------------------------------------------------------------

local function Log()
    local aContent = WikiContent( 'Log' )
    
    if not aContent.exists then
        local WikiDate = require( 'WikiDate' )
        local WikiRecent = require( 'WikiRecent' )
        local WikiSearch = require( 'WikiSearch' )
        
        aContent.by = 'file://nanoki@localhost/'
        aContent.title = 'Log'
        aContent.text = '   '
        aContent()
        
        WikiDate[ aContent.creation ] = aContent.name
        WikiRecent[ aContent.modification ] = aContent.name
        WikiSearch[ aContent.name ] = aContent.name
    end
end

local function Nanoki()
    local aContent = WikiContent( 'nanoki' )
    
    if not aContent.exists then
        local File = require( 'File' )
        local WikiDate = require( 'WikiDate' )
        local WikiRecent = require( 'WikiRecent' )
        local WikiSearch = require( 'WikiSearch' )
        local aDirectory = File( 'Nanoki' )
        local aTemplate = Template[ 'Nanoki.txt' ]
        
        aContent.by = 'file://nanoki@localhost/'
        aContent.title = 'Nanoki'
        aContent.text = tostring( aTemplate )
        aContent()
        
        for aFile in aDirectory() do
            aContent.file = aFile
        end
        
        aContent.canWrite = false
        WikiDate[ aContent.creation ] = aContent.name
        WikiRecent[ aContent.modification ] = aContent.name
        WikiSearch[ aContent.name ] = aContent.name
    end
end

local function Syntax()
    local aContent = WikiContent( 'markdown-syntax-reference' )
    
    if not aContent.exists then
        local WikiDate = require( 'WikiDate' )
        local WikiRecent = require( 'WikiRecent' )
        local WikiSearch = require( 'WikiSearch' )
        local aTemplate = Template[ 'MarkdownSyntaxReference.txt' ]
        
        aContent.by = 'file://nanoki@localhost/'
        aContent.title = 'Markdown syntax reference'
        aContent.text = tostring( aTemplate )
        aContent()
        
        WikiDate[ aContent.creation ] = aContent.name
        WikiRecent[ aContent.modification ] = aContent.name
        WikiSearch[ aContent.name ] = aContent.name
    end
end

Log()
Nanoki()
Syntax()

--------------------------------------------------------------------------------
-- Service methods
--------------------------------------------------------------------------------

self.toURL = function( aService, anObject )
    if anObject.content then
        local aPath = URLPath()
        
        aPath[ #aPath + 1 ] = anObject.content.name
        
        return URL( aService.prefix .. aPath )
    end
end

self.toObject = function( aService, aURL )
    local aPath = aURL.path
    local aName = aPath[ 1 ] or 'main'
    local aContent = WikiContent( aName )
    
    if aContent then
        local WikiContentService = require( 'WikiContentService' )
        local aService = WikiContentService( aContent )    
    
        return aService
    end
end

function self:getHtml()
    if self.content.exists then
        local aLayoutTemplate = Template[ 'WikiLayout.txt' ]
        local aTemplate = Template[ 'WikiContentService.txt' ]
        local aLinkTemplate = aTemplate[ 'link' ]
        local aLinkIterator, aLinkCount = ContentIterator( self.content.link )
        local aDate = os.date( '!*t', self.content.creation )
        local aDateLink = DateLink( aDate.year, aDate.month, aDate.day )
        
        Referer( self )

        aTemplate[ 'editorLink' ] = EditorLink( self )
        aTemplate[ 'version' ] = Encode(self.content.version )
        aTemplate[ 'title' ] = Encode( self.content.data.title )
        aTemplate[ 'dateLink' ] = Encode( aDateLink )
        aTemplate[ 'creation' ] = Encode( FormatDate( self.content.creation ) )
        aTemplate[ 'modification' ] = Encode( FormatDateTime( self.content.modification ) )
        aTemplate[ 'tag' ] = Tag( self.content.modification )
        aTemplate[ 'by' ] = Encode( URL( self.content.by ).host or 'localhost' )
        aTemplate[ 'message' ] = Message( self )
        aTemplate[ 'content' ] = HTML( self.content )
        
        for aContent, aURL in aLinkIterator do
            local aNameTemplate = aLinkTemplate[ 'names' ]
    
            aNameTemplate[ 'href' ] = Encode( aURL.path )
            aNameTemplate[ 'name' ] = Encode( aContent.title )
            
            aLinkTemplate[ 'names' ] = aNameTemplate
        end
        
        if aLinkCount == 0 then
            aLinkTemplate = nil
        end
        
        aTemplate[ 'link' ] = aLinkTemplate
        
        aLayoutTemplate[ 'baseLink' ] = Encode( BaseLink() )
        aLayoutTemplate[ 'indexLink' ] = Encode( IndexLink( self.content.prefix ) )
        aLayoutTemplate[ 'dateLink' ] = Encode( aDateLink )
        aLayoutTemplate[ 'feedLink' ] = FeedLink( self, 1 )
        aLayoutTemplate[ 'path' ] = Path( self )
        aLayoutTemplate[ 'query' ] = nil
        aLayoutTemplate[ 'robot' ] = Robot( self.content.modification )
        aLayoutTemplate[ 'title' ] = Encode( self.content.title )
        aLayoutTemplate[ 'content' ] = aTemplate
                
        return tostring( aLayoutTemplate )
    else
        return nil, self.path( 'editor' )
    end
end

function self:getLua()
    if self.content.exists then
        local Data = require( 'Data' )
    
        HTTP.response.header[ 'content-type' ] = 'text/plain; charset=utf-8'

        return Data( self.content.data )
    end
end

function self:getTxt()
    if self.content.exists then
        HTTP.response.header[ 'content-type' ] = 'text/plain; charset=utf-8'

        return self.content.text
    end
end

function self:getXml()
    if self.content.exists then
        local WikiFeed = require( 'WikiFeed' )
        local anIterator = NameIterator( { self.content.name } )
        local aGenerator = HTML
        local aContext = { title = self.content.data.title, link = HTTP.request.url, creation = self.content.creation }
                
        HTTP.response.header[ 'content-type' ] = 'application/atom+xml; charset=utf-8'

        return tostring( WikiFeed( anIterator, aGenerator, aContext ) )
    end
end

function self:get( aType )
    return GetType( self, aType )
end

function self:getEditor( aVersion )
    local WikiEditorService = require( 'WikiEditorService' )
    local aVersion = tonumber( aVersion )
    local aContent = WikiContent( self.content.name, aVersion )
    
    if aContent.canWrite then
        if not aContent.exists then
            aContent = self.content
        end
        
        if not aContent.exists then
            HTTP.response.status.code = 404
            HTTP.response.status.description = 'Not Found'
        end
        
        return WikiEditorService( aContent, self )
    end
end

function self:getFile( ... )
    local aName = table.concat( { ... }, '.' )
    
    if ValidFile( self.content, aName ) then
        local File = require( 'File' )
        local HTTPFile = require( 'HTTPFile' )
        local aDirectory = File( self.content.directory.path, 'file', '' )
        local aHandler = HTTPFile( aDirectory.path )
        
        return aHandler( aName )
    end
end

--------------------------------------------------------------------------------
-- Metamethods
--------------------------------------------------------------------------------

function meta:__call( aContent )
    local aService = { content = aContent }
    
    setmetatable( aService, self )
    self.__index = self    
    
    return aService
end

function self:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function self:__tostring()
    return tostring( self.content.data.title )
end
