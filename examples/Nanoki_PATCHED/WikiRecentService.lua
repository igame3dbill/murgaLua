--------------------------------------------------------------------------------
-- Title:               WikiRecentService.lua
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
local URL = require( 'URL' )
local WikiContent = require( 'WikiContent' )
local WikiContentService = require( 'WikiContentService' )
local WikiDateService = require( 'WikiDateService' )
local WikiRecent = require( 'WikiRecent' )
local WikiService = require( 'WikiService' )

local BaseLink = WikiService.BaseLink
local DateLink = WikiService.DateLink
local FeedLink = WikiService.FeedLink
local IndexLink = WikiService.IndexLink

local ContentIterator = WikiService.ContentIterator
local Description = WikiService.Description
local Encode = WikiService.Encode
local FormatDate = WikiService.FormatDate
local FormatTime = WikiService.FormatTime
local GetType = WikiService.GetType
local HTML = WikiService.HTML
local Path = WikiService.Path
local Today = WikiService.Today
local Yesterday = WikiService.Yesterday

local os = require( 'os' )
local table = require( 'table' )

local getmetatable = getmetatable
local ipairs = ipairs
local pairs = pairs
local setmetatable = setmetatable
local require = require
local tostring = tostring

--------------------------------------------------------------------------------
-- WikiRecentService
--------------------------------------------------------------------------------

module( 'WikiRecentService' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

local function ContentComparator( aContent, anotherContent )
    local aTime = aContent.modification or 0
    local anotherTime = anotherContent.modification or 0
    
    if aTime == anotherTime then
        return aContent.title < anotherContent.title
    end
    
    return aTime > anotherTime
end

local function EntryComparator( anEntry, anotherEntry )
    local aTime = anEntry.time
    local anotherTime = anotherEntry.time
    
    return aTime > anotherTime
end

local function Entries()
    local aMap = {}
    local aList = {}

    for aName in WikiRecent[ '' ] do
        local aContent = WikiContent( aName )
        local aModification = aContent.modification
        local aDate = os.date( '!*t', aModification )
        local aTime = os.time( { year = aDate.year, month = aDate.month, day = aDate.day } )
        local someItems = aMap[ aTime ]
        
        if not someItems then
            someItems = {}
            aMap[ aTime ] = someItems
        end
        
        someItems[ #someItems + 1 ] = aContent
    end
    
    for aTime, someItems in pairs( aMap ) do
        table.sort( someItems, ContentComparator )
    
        aList[ #aList + 1 ] = { time = aTime, items = someItems }
    end
    
    table.sort( aList, EntryComparator )
    
    return aList
end

--------------------------------------------------------------------------------
-- Service methods
--------------------------------------------------------------------------------

self.toURL =function( aService, anObject )
    return URL( aService.prefix )
end

self.toObject = function( aService, aURL )
    local WikiRecentService = require( 'WikiRecentService' )
    local aService = WikiRecentService()    

    return aService
end

function self:getHtml()
    local aLayoutTemplate = Template[ 'WikiLayout.txt' ]
    local aTemplate = Template[ 'WikiRecentService.txt' ]
    local anEntryTemplate = aTemplate[ 'entries' ]
    local aCount = 0

    aTemplate[ 'title' ] = 'Recent'
    aTemplate[ 'entries' ] = nil
    
    for _, anEntry in ipairs( Entries() ) do
        local anEntryTemplate = aTemplate[ 'entries' ]
        local aTime = anEntry.time
        local aDate = os.date( '!*t', aTime )
        local aService = WikiDateService( aDate.year, aDate.month, aDate.day )
        local aURL = HTTPService[ aService ]
        local aTitle = FormatDate( aTime )
        
        if Today( aTime ) then
            aTitle = ( 'Today — %s' ):format( aTitle )
        elseif Yesterday( aTime ) then
            aTitle = ( 'Yesterday — %s' ):format( aTitle )
        end 
        
        anEntryTemplate[ 'description' ] = Encode( Description( #anEntry.items ) )
        anEntryTemplate[ 'title' ] = Encode( aTitle )
        
        for _, aContent in ipairs( anEntry.items ) do        
            local anItemTemplate = anEntryTemplate[ 'items' ]
            local aService = WikiContentService( aContent )
            local aURL = HTTPService[ aService ]

            anItemTemplate[ 'link' ] = Encode( aURL.path )
            anItemTemplate[ 'modification' ] = Encode( FormatTime( aContent.modification ) )
            anItemTemplate[ 'by' ] = Encode( URL( aContent.by ).host or 'localhost' )
            anItemTemplate[ 'title' ] = Encode( aContent.title )
            
            aCount = aCount + 1
            
            anEntryTemplate[ 'items' ] = anItemTemplate
        end
        
        aTemplate[ 'entries' ] = anEntryTemplate
    end

    aTemplate[ 'description' ] = Encode( Description( aCount ) )

    aLayoutTemplate[ 'baseLink' ] = Encode( BaseLink() )
    aLayoutTemplate[ 'indexLink' ] = Encode( IndexLink() )
    aLayoutTemplate[ 'dateLink' ] = Encode( DateLink() )
    aLayoutTemplate[ 'feedLink' ] = FeedLink( self, aCount )
    aLayoutTemplate[ 'path' ] = Path( self )
    aLayoutTemplate[ 'query' ] = nil
    aLayoutTemplate[ 'robot' ] = 'noindex'
    aLayoutTemplate[ 'title' ] = 'Recent'
    aLayoutTemplate[ 'content' ] = aTemplate

    return tostring( aLayoutTemplate )
end

function self:getXml()
    local WikiFeed = require( 'WikiFeed' )
    local WikiIndex = require( 'WikiIndex' )
    local anIterator = ContentIterator( WikiRecent[ '' ] )
    local aGenerator = HTML
    local aTitle = 'Recent'
    local aContext = { title = aTitle, link = HTTP.request.url, creation = WikiIndex[ 'creation' ] }
            
    HTTP.response.header[ 'content-type' ] = 'application/atom+xml; charset=utf-8'

    return tostring( WikiFeed( anIterator, aGenerator, aContext ) )
end

function self:get( aType )
    return GetType( self, aType )
end

--------------------------------------------------------------------------------
-- Metamethods
--------------------------------------------------------------------------------

function meta:__call()
    local aService = {}
    
    setmetatable( aService, self )
    self.__index = self    
    
    return aService
end

function self:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function self:__tostring()
    return 'Recent'
end
