--------------------------------------------------------------------------------
-- Title:               WikiSearchService.lua
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
local WikiIndex = require( 'WikiIndex' )
local WikiSearch = require( 'WikiSearch' )
local WikiService = require( 'WikiService' )

local BaseLink = WikiService.BaseLink
local DateLink = WikiService.DateLink
local FeedLink = WikiService.FeedLink
local IndexLink = WikiService.IndexLink

local ContentIterator = WikiService.ContentIterator
local NameIterator = WikiService.NameIterator

local Description = WikiService.Description
local Encode = WikiService.Encode
local GetType = WikiService.GetType
local HTML = WikiService.HTML
local Path = WikiService.Path

local getmetatable = getmetatable
local pairs = pairs
local require = require
local setmetatable = setmetatable
local table = table
local tostring = tostring

--------------------------------------------------------------------------------
-- WikiSearchService
--------------------------------------------------------------------------------

module( 'WikiSearchService' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

function DirectHits( aValue )
    local NaturalComparator = require( 'NaturalComparator' )
    local WikiContent = require( 'WikiContent' )
    local aContent = WikiContent( aValue )
    local aMap = {}
    local aList = {}
    
    if aContent and aContent.exists then
        aMap[ aContent.name ] = true
    end
    
    for aToken in ( aValue or '' ):gsub( '%p', ' ' ):gmatch( '([%S]+)' ) do
        local aContent = WikiContent( aToken )
        
        if aContent and aContent.exists then
            aMap[ aContent.name ] = true
        end
    end
    
    for aName, _ in pairs( aMap ) do
        aList[ #aList + 1 ] = aName
    end
    
    table.sort( aList, NaturalComparator() )
    
    return aList
end

local function SearchIterator( aQuery )
    if aQuery then
        return ContentIterator( WikiSearch[ aQuery ] )
    end
    
    return ContentIterator( WikiIndex[ '' ] )
end

--------------------------------------------------------------------------------
-- Service methods
--------------------------------------------------------------------------------

self.toURL =function( aService, anObject )
    return URL( aService.prefix )
end

self.toObject = function( aService, aURL )
    local WikiSearchService = require( 'WikiSearchService' )
    local aQuery = HTTP.request.parameter[ 'q' ]
    local aService = WikiSearchService( aQuery )    

    return aService
end

function self:getHtml()
    local aLayoutTemplate = Template[ 'WikiLayout.txt' ]
    local aTemplate = Template[ 'WikiSearchService.txt' ]
    local aHitTemplate = aTemplate[ 'hits' ]
    local aNameTemplate = aTemplate[ 'names' ]
    local someHits = DirectHits( self.query )
    local anIterator, aCount, hasMore = SearchIterator( self.query )
    local aQuery = self.query or ''
    local aTitle = aQuery .. ' — Search'
    local someNames = {}

    aTemplate[ 'hits' ] = nil
    aTemplate[ 'names' ] = nil
    aTemplate[ 'status' ] = nil

    if ( aCount + #someHits ) == 0 then
        local aStatusTemplate = Template[ 'WikiSearchStatus.txt' ]
        
        aStatusTemplate[ 'query' ] = Encode( aQuery )
        aTemplate[ 'status' ] = aStatusTemplate

        HTTP.response.status.code = 404
        HTTP.response.status.description = 'Not Found'
    end
    
    for aContent, aURL in NameIterator( someHits ) do
        local aNameTemplate = aTemplate[ 'hits' ]

        aNameTemplate[ 'href' ] = Encode( aURL.path )
        aNameTemplate[ 'name' ] = Encode( aContent.title )
        
        aTemplate[ 'hits' ] = aNameTemplate
        someNames[ aContent.name ] = true
    end
    
    for aContent, aURL in anIterator do
        local aNameTemplate = aTemplate[ 'names' ]

        aNameTemplate[ 'href' ] = Encode( aURL.path )
        aNameTemplate[ 'name' ] = Encode( aContent.title )
        
        if not someNames[ aContent.name ] then
            aTemplate[ 'names' ] = aNameTemplate
        else
            aCount = aCount - 1
        end
        
        someNames[ aContent.name ] = true
    end

    aTemplate[ 'description' ] = Encode( Description( aCount + #someHits, hasMore ) ) 
    aTemplate[ 'title' ] = Encode( aTitle )
    
    aLayoutTemplate[ 'baseLink' ] = Encode( BaseLink() )
    aLayoutTemplate[ 'indexLink' ] = Encode( IndexLink( aQuery ) )
    aLayoutTemplate[ 'dateLink' ] = Encode( DateLink() )
    aLayoutTemplate[ 'feedLink' ] = FeedLink( self, ( aCount + #someHits ) )
    aLayoutTemplate[ 'path' ] = Path( self )
    aLayoutTemplate[ 'query' ] = Encode( aQuery )
    aLayoutTemplate[ 'robot' ] = 'noindex'
    aLayoutTemplate[ 'title' ] = Encode( aTitle )
    aLayoutTemplate[ 'content' ] = aTemplate
    
    return tostring( aLayoutTemplate )
end

function self:getXml()
    local WikiFeed = require( 'WikiFeed' )
    local WikiIndex = require( 'WikiIndex' )
    local anIterator, aCount, hasMore = SearchIterator( self.query )
    local aGenerator = HTML
    local aTitle = ( self.query or '' )  .. ' — Search'
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

function meta:__call( aQuery )
    local aService = { query = aQuery }
    
    setmetatable( aService, self )
    self.__index = self    
    
    return aService
end

function self:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function self:__tostring()
    return 'Search'
end
