--------------------------------------------------------------------------------
-- Title:               WikiRevisionService.lua
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
local WikiContent = require( 'WikiContent' )
local WikiService = require( 'WikiService' )

local BaseLink = WikiService.BaseLink
local DateLink = WikiService.DateLink
local FeedLink = WikiService.FeedLink
local IndexLink = WikiService.IndexLink

local Description = WikiService.Description
local Encode = WikiService.Encode
local FormatDate = WikiService.FormatDate
local FormatDateTime = WikiService.FormatDateTime
local Path = WikiService.Path

local os = require( 'os' )
local table = require( 'table' )

local getmetatable = getmetatable
local ipairs = ipairs
local pairs = pairs
local require = require
local setmetatable = setmetatable
local tonumber = tonumber
local tostring = tostring

--------------------------------------------------------------------------------
-- WikiRevisionService
--------------------------------------------------------------------------------

module( 'WikiRevisionService' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

local function EntryComparator( anEntry, anotherEntry )
    local aTime = anEntry.time
    local anotherTime = anotherEntry.time
    
    return aTime > anotherTime
end

local function ItemComparator( anItem, anotherItem )
    local aTime = anItem.modification
    local anotherTime = anotherItem.modification
    
    if aTime == anotherTime then
        local aVersion = anItem.version
        local anotherVersion = anotherItem.version
        
        return aVersion > anotherVersion
    end
    
    return aTime > anotherTime
end

local function Entries( aName, anIterator )
    local aMap = {}
    local aList = {}

    for aVersion in anIterator do
        local aContent = WikiContent( aName, aVersion )
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
        table.sort( someItems, ItemComparator )
    
        aList[ #aList + 1 ] = { time = aTime, items = someItems }
    end
    
    table.sort( aList, EntryComparator )
    
    return aList
end

--------------------------------------------------------------------------------
-- Service methods
--------------------------------------------------------------------------------

function self:get()
    local aLayoutTemplate = Template[ 'WikiLayout.txt' ]
    local aTemplate = Template[ 'WikiRevisionService.txt' ]
    local aContent = self.content
    local aDate = os.date( '!*t', aContent.creation )
    local aDateTitle = FormatDate( aContent.creation )
    local aDateLink = DateLink( aDate.year, aDate.month, aDate.day )
    local aVersion = aContent.previousVersion or aContent.version
    local aLink = HTTP.request.url.path( ( 'n.%d' ):format( aVersion ) )
    local someEntries = Entries( aContent.name, aContent.versions )
    local aCount = 0
    
    aTemplate[ 'version' ] = Encode( aVersion )
    aTemplate[ 'link' ] = Encode( aLink )
    aTemplate[ 'title' ] = Encode( aContent.data.title )
    aTemplate[ 'creation' ] = Encode( aDateTitle )

    for _, anEntry in ipairs( someEntries ) do
        local anEntryTemplate = aTemplate[ 'entries' ]
        local aTime = anEntry.time
        local aDate = os.date( '!*t', aTime )
        local aTitle = FormatDate( aTime )
        
        anEntryTemplate[ 'description' ] = Encode( Description( #anEntry.items ) )
        anEntryTemplate[ 'title' ] = Encode( aTitle )
        
        for _, aContent in ipairs( anEntry.items ) do        
            local anItemTemplate = anEntryTemplate[ 'items' ]
            local aPath = HTTP.request.url.path( ( 'n.%d' ):format( aContent.version ) )

            anItemTemplate[ 'link' ] = Encode( aPath )
            anItemTemplate[ 'version' ] = Encode( aContent.version )
            anItemTemplate[ 'date' ] = Encode( FormatDateTime( aContent.modification ) )
            anItemTemplate[ 'time' ] = Encode( os.date( '!%I:%M %p', aContent.modification ):gsub( '^0(%d)', ' %1' ) )
            anItemTemplate[ 'by' ] = Encode( URL( aContent.by ).host or 'localhost' )
            
            aCount = aCount + 1
            
            anEntryTemplate[ 'items' ] = anItemTemplate
        end
        
        aTemplate[ 'entries' ] = anEntryTemplate
    end

    aTemplate[ 'description' ] = Encode( Description( aCount ) )

    aLayoutTemplate[ 'baseLink' ] = Encode( BaseLink() )
    aLayoutTemplate[ 'indexLink' ] = Encode( IndexLink( aContent.prefix ) )
    aLayoutTemplate[ 'dateLink' ] = Encode( aDateLink )
    aLayoutTemplate[ 'feedLink' ] = FeedLink()
    aLayoutTemplate[ 'path' ] = Path( self )
    aLayoutTemplate[ 'query' ] = nil
    aLayoutTemplate[ 'robot' ] = 'noindex,nofollow'
    aLayoutTemplate[ 'title' ] = Encode( aContent.title .. ' — Revision' )
    aLayoutTemplate[ 'content' ] = aTemplate

    return tostring( aLayoutTemplate )
end

function self:getN( aVersion )
    local aVersion = tonumber( aVersion )

    if aVersion then
        local WikiContent = require( 'WikiContent' )
        local aContent = WikiContent( self.content.name, aVersion )
        
        if aContent.exists then
            local WikiVersionService = require( 'WikiVersionService' )
        
            return WikiVersionService( aContent, self )
        end
    end
end

--------------------------------------------------------------------------------
-- Metamethods
--------------------------------------------------------------------------------

function meta:__call( aContent, aParent )
    local aRevision = { content = aContent, parent = aParent }
    
    setmetatable( aRevision, self )
    self.__index = self    

    return aRevision
end

function self:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function self:__tostring()
    return 'Revision'
end
