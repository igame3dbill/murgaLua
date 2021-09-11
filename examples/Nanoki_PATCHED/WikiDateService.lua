--------------------------------------------------------------------------------
-- Title:               WikiDateService.lua
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
local Template = require( 'Template' )
local URL = require( 'URL' )
local URLPath = require( 'URLPath' )
local WikiDate = require( 'WikiDate' )
local WikiService = require( 'WikiService' )

local BaseLink = WikiService.BaseLink
local DateLink = WikiService.DateLink
local FeedLink = WikiService.FeedLink
local IndexLink = WikiService.IndexLink

local ContentIterator = WikiService.ContentIterator
local Description = WikiService.Description
local Encode = WikiService.Encode
local FormatDate = WikiService.FormatDate
local GetType = WikiService.GetType
local HTML = WikiService.HTML
local Path = WikiService.Path

local os = require( 'os' )

local getmetatable = getmetatable
local setmetatable = setmetatable
local require = require
local tonumber = tonumber
local tostring = tostring

--------------------------------------------------------------------------------
-- WikiDateService
--------------------------------------------------------------------------------

module( 'WikiDateService' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

local function Title( aYear, aMonth, aDay )
    local aTime = os.time( { year = aYear or 1, month = aMonth or 1, day = aDay or 1 } )
    local aFormat = nil
    
    if aDay then
        return FormatDate( aTime )
    elseif aMonth then
        aFormat = '!%B %Y'
    else
        aFormat = '!%Y'
    end
    
    return os.date( aFormat, aTime )
end

local function PathArgument( self )
    if self.day then
        local WikiDateService = require( 'WikiDateService' )
        local aMonthService = WikiDateService( self.year, self.month )
        local aYearService = WikiDateService( self.year )
        
        aMonthService.path = self.path()
        aYearService.path = aMonthService.path()
        
        return self, aMonthService, aYearService
    end

    if self.month then
        local WikiDateService = require( 'WikiDateService' )
        local aYearService = WikiDateService( self.year )
        
        aYearService.path = self.path()
        
        return self, aYearService
    end
    
    return self
end

--------------------------------------------------------------------------------
-- Service methods
--------------------------------------------------------------------------------

self.toURL =function( aService, anObject )
    local aPath = URLPath()
    
    aPath.absolute = true

    if anObject.year then
        aPath[ #aPath + 1 ] = ( '%04d' ):format( anObject.year )
    end
    
    if anObject.month then
        aPath[ #aPath + 1 ] = ( '%02d' ):format( anObject.month )
    end
    
    if anObject.day then
        aPath[ #aPath + 1 ] = ( '%02d' ):format( anObject.day )
    end
    
    return URL( aService.prefix .. aPath )
end

self.toObject = function( aService, aURL )
    local aPath = aURL.path
    local aYear = tonumber( aPath[ 2 ] ) or 0
    local aMonth = tonumber( aPath[ 3 ] )
    local aDay = tonumber( aPath[ 4 ] )
    local WikiDateService = require( 'WikiDateService' )
    local aService = WikiDateService( aYear, aMonth, aDay )    

    return aService
end

function self:getHtml()
    local WikiDateNavigation = require( 'WikiDateNavigation' )
    local aLayoutTemplate = Template[ 'WikiLayout.txt' ]
    local aTemplate = Template[ 'WikiDateService.txt' ]
    local aNameTemplate = aTemplate[ 'names' ]
    local anIterator, aCount, hasMore = ContentIterator( WikiDate[ self ] )
    local aTitle = Title( self.year, self.month, self.day )
    
    aTemplate[ 'names' ] = nil
    aTemplate[ 'description' ] = Encode( Description( aCount, hasMore ) )
    aTemplate[ 'navigation' ] = WikiDateNavigation( self )
    
    if aCount == 0 then
        HTTP.response.status.code = 404
        HTTP.response.status.description = 'Not Found'
    end
    
    for aContent, aURL in anIterator do
        local aNameTemplate = aTemplate[ 'names' ]
        
        aNameTemplate[ 'href' ] = Encode( aURL.path )
        aNameTemplate[ 'name' ] = Encode( aContent.title )
        
        aTemplate[ 'names' ] = aNameTemplate
    end

    aTemplate[ 'title' ] = Encode( aTitle )
    
    aLayoutTemplate[ 'baseLink' ] = Encode( BaseLink() )
    aLayoutTemplate[ 'indexLink' ] = Encode( IndexLink() )
    aLayoutTemplate[ 'dateLink' ] = Encode( DateLink( self.year, self.month, self.day ) )
    aLayoutTemplate[ 'feedLink' ] = FeedLink( self, aCount )
    aLayoutTemplate[ 'path' ] = Path( PathArgument( self ) )
    aLayoutTemplate[ 'query' ] = nil
    aLayoutTemplate[ 'robot' ] = 'noindex'
    aLayoutTemplate[ 'title' ] = Encode( aTitle .. ' — Date' )
    aLayoutTemplate[ 'content' ] = aTemplate
    
    return tostring( aLayoutTemplate )
end

function self:getXml()
    local WikiFeed = require( 'WikiFeed' )
    local WikiIndex = require( 'WikiIndex' )
    local anIterator = ContentIterator( WikiDate[ self ] )
    local aGenerator = HTML
    local aTitle = Title( self.year, self.month, self.day ) .. ' — Date' 
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

function meta:__call( aYear, aMonth, aDay )
    local aTime = os.time( { year = aYear or 1, month = aMonth or 1, day = aDay or 1 } )
    local aDate = os.date( '!*t', aTime )
    local aService = { year = aYear, month = aMonth, day = aDay }
    
    if aYear and aYear ~= aDate.year then
        aService.year = aDate.year
    end
    
    if aMonth and aMonth ~= aDate.month then
        aService.month = aDate.month
    end
    
    if aDay and aDay ~= aDate.day then
        aService.day = aDate.day
    end
    
    setmetatable( aService, self )
    self.__index = self    
    
    return aService
end

function self:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function self:__tostring()
    return Title( self.year, self.month, self.day )
end
