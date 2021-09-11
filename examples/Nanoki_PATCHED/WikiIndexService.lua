--------------------------------------------------------------------------------
-- Title:               WikiIndexService.lua
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
local WikiIndex = require( 'WikiIndex' )
local WikiService = require( 'WikiService' )

local BaseLink = WikiService.BaseLink
local DateLink = WikiService.DateLink
local FeedLink = WikiService.FeedLink
local IndexLink = WikiService.IndexLink

local ContentIterator = WikiService.ContentIterator
local Description = WikiService.Description
local Encode = WikiService.Encode
local GetType = WikiService.GetType
local HTML = WikiService.HTML
local Path = WikiService.Path

local getmetatable = getmetatable
local require = require
local rawset = rawset
local setmetatable = setmetatable
local tostring = tostring

--------------------------------------------------------------------------------
-- WikiIndexService
--------------------------------------------------------------------------------

module( 'WikiIndexService' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

local function PathArgument( self )
    if self.second then
        local WikiIndexService = require( 'WikiIndexService' )
        local aService = WikiIndexService( self.first )
        
        aService.path = self.path()
        
        return self, aService
    end
    
    return self
end

--------------------------------------------------------------------------------
-- Service methods
--------------------------------------------------------------------------------

self.toURL =function( aService, anObject )
    local aPath = URLPath()
    
    aPath.absolute = true

    if anObject.first then
        aPath[ #aPath + 1 ] = anObject.first
    end
    
    if anObject.second then
        aPath[ #aPath + 1 ] = anObject.second
    end

    return URL( aService.prefix .. aPath )
end

self.toObject = function( aService, aURL )
    local aPath = aURL.path
    local aFirst = aPath[ 2 ]
    local aSecond = aPath[ 3 ]
    local WikiIndexService = require( 'WikiIndexService' )
    local aService = WikiIndexService( aFirst, aSecond )    

    return aService
end

function self:getHtml()
    local WikiIndexNavigation = require( 'WikiIndexNavigation' )
    local aLayoutTemplate = Template[ 'WikiLayout.txt' ]
    local aTemplate = Template[ 'WikiIndexService.txt' ]
    local aNameTemplate = aTemplate[ 'names' ]
    local anIterator, aCount, hasMore = ContentIterator( WikiIndex[ self.prefix ] )
    local aTitle = self.first:upper() .. ( self.second or '' ):lower()

    aTemplate[ 'names' ] = nil
    aTemplate[ 'description' ] = Encode( Description( aCount, hasMore ) )
    aTemplate[ 'navigation' ] = WikiIndexNavigation( self.prefix )
        
    if aCount == 0 then
        HTTP.response.status.code = 404
        HTTP.response.status.description = 'Not Found'
    end
    
    for aContent, aURL in anIterator do
        local aNameTemplate = aTemplate[ 'names' ]
        
        aNameTemplate[ 'href' ] = Encode( aURL.path )
        aNameTemplate[ 'name' ] = aContent.title
        
        aTemplate[ 'names' ] = aNameTemplate
    end

    aTemplate[ 'title' ] = aTitle
    
    aLayoutTemplate[ 'baseLink' ] = Encode( BaseLink() )
    aLayoutTemplate[ 'indexLink' ] = Encode( IndexLink( self.prefix ) )
    aLayoutTemplate[ 'dateLink' ] = Encode( DateLink() )
    aLayoutTemplate[ 'feedLink' ] = FeedLink( self, aCount )
    aLayoutTemplate[ 'path' ] = Path( PathArgument( self ) )
    aLayoutTemplate[ 'query' ] = nil
    aLayoutTemplate[ 'robot' ] = 'noindex'
    aLayoutTemplate[ 'title' ] = Encode( aTitle .. ' — Index'  )
    aLayoutTemplate[ 'content' ] = aTemplate
    
    return tostring( aLayoutTemplate )
end

function self:getXml()
    local WikiFeed = require( 'WikiFeed' )
    local anIterator = ContentIterator( WikiIndex[ self.prefix ] )
    local aGenerator = HTML
    local aTitle = self.first:upper() .. ( self.second or '' ):lower() .. ' — Index'
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

function meta:__call( aFirst, aSecond )
    local aFirst = ( aFirst or 'a' ):match( '^(%w)' ) or 'a'
    local aSecond = ( aSecond or '' ):match( '^(%w)' )
    local aPrefix = nil
    local aService = {}
    
    if aFirst then
        aService.first = aFirst:lower()
        aPrefix = aService.first
    end
    
    if aSecond then
        aService.second = aSecond:lower()
        aPrefix = aService.first .. aService.second
    end
    
    aService.prefix = aPrefix
    
    setmetatable( aService, self )
    self.__index = self    
    
    return aService
end

function self:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function self:__tostring()
    return self.second or self.first:upper()
end
