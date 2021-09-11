--------------------------------------------------------------------------------
-- Title:               WikiVersionService.lua
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
local WikiService = require( 'WikiService' )

local BaseLink = WikiService.BaseLink
local DateLink = WikiService.DateLink
local FeedLink = WikiService.FeedLink
local IndexLink = WikiService.IndexLink

local Encode = WikiService.Encode
local FormatDateTime = WikiService.FormatDateTime
local Path = WikiService.Path

local os = require( 'os' )

local getmetatable = getmetatable
local require = require
local setmetatable = setmetatable
local tonumber = tonumber
local tostring = tostring

--------------------------------------------------------------------------------
-- WikiVersionService
--------------------------------------------------------------------------------

module( 'WikiVersionService' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

--------------------------------------------------------------------------------
-- Service methods
--------------------------------------------------------------------------------

function self:get()
    local aLayoutTemplate = Template[ 'WikiLayout.txt' ]
    local aTemplate = Template[ 'WikiVersionService.txt' ]
    local aDate = os.date( '!*t', self.content.creation )
    local aDateTitle = FormatDateTime( self.content.modification )
    local aDateLink = DateLink( aDate.year, aDate.month, aDate.day )

    aTemplate[ 'diffLink' ] = Encode( HTTP.request.url.path( 'n' ) )
    aTemplate[ 'actionPath' ] = Encode( HTTP.request.url.path )
    aTemplate[ 'title' ] = Encode( self.content.data.title )
    aTemplate[ 'creation' ] = Encode( aDateTitle )
    aTemplate[ 'by' ] = Encode( URL( self.content.by ).host or 'localhost' )
    
    aTemplate[ 'content' ] = Encode( self.content.text ):gsub( '(%c%c)', '<br/>' ):gsub( '(%c)', '<br/>' )

    aLayoutTemplate[ 'baseLink' ] = Encode( BaseLink() )
    aLayoutTemplate[ 'indexLink' ] = Encode( IndexLink( self.content.prefix ) )
    aLayoutTemplate[ 'dateLink' ] = Encode( aDateLink )
    aLayoutTemplate[ 'feedLink' ] = FeedLink()
    aLayoutTemplate[ 'path' ] = Path( self )
    aLayoutTemplate[ 'query' ] = nil
    aLayoutTemplate[ 'robot' ] = 'noindex,nofollow'
    aLayoutTemplate[ 'title' ] = Encode( self.content.data.title .. ' — № ' .. self.content.version )
    aLayoutTemplate[ 'content' ] = aTemplate

    return tostring( aLayoutTemplate )
end

function self:getN( aVersion )
    local WikiDiffService = require( 'WikiDiffService' )
    local aVersion = tonumber( aVersion )
    local aService = WikiDiffService( self.content, self, aVersion )
    
    return aService
end

function self:postRestore()
    return nil, HTTPService[ WikiContentService( self.content ) ] .. '/editor.' .. self.content.version
end

--------------------------------------------------------------------------------
-- Metamethods
--------------------------------------------------------------------------------

function meta:__call( aContent, aParent )
    local aVersion = { content = aContent, parent = aParent }
    
    setmetatable( aVersion, self )
    self.__index = self    

    return aVersion
end

function self:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function self:__tostring()
    return ( '№ %d' ):format( self.content.version )
end
