--------------------------------------------------------------------------------
-- Title:               WikiPreview.lua
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
local WikiService = require( 'WikiService' )

local BaseLink = WikiService.BaseLink
local DateLink = WikiService.DateLink
local FeedLink = WikiService.FeedLink
local IndexLink = WikiService.IndexLink

local Encode = WikiService.Encode

local os = require( 'os' )

local getmetatable = getmetatable
local require = require
local setmetatable = setmetatable
local tostring = tostring

--------------------------------------------------------------------------------
-- WikiPreview
--------------------------------------------------------------------------------

module( 'WikiPreview' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

--------------------------------------------------------------------------------
-- Metamethods
--------------------------------------------------------------------------------

function meta:__call( aContent, aParent, aContext )
    local aPreview = { content = aContent, parent = aParent, context = aContext }

    setmetatable( aPreview, self )
    self.__index = self    
    
    return aPreview
end

function self:__tostring()
    local markdown = require( 'markdown' )
    local aLayoutTemplate = Template[ 'WikiLayout.txt' ]
    local aTemplate = Template[ 'WikiPreview.txt' ]
    local aContext = self.context
    local aDate = os.date( '!*t', self.content.creation )
    local aDateLink = DateLink( aDate.year, aDate.month, aDate.day )
    local aToken = aContext.token

    aTemplate[ 'actionPath' ] = Encode( HTTP.request.url.path )

    aTemplate[ 'titlePreview' ] = Encode( aContext.title or '' )
    aTemplate[ 'textPreview' ] = markdown( aContext.text or '' )

    aTemplate[ 'checkToken' ] = Encode( aToken.check )
    aTemplate[ 'check' ] = Encode( aContext.check )
    aTemplate[ 'countToken' ] = Encode( aToken.count )
    aTemplate[ 'count' ] = Encode( ( aContext.count or -1 ) + 1 )
    aTemplate[ 'timeToken' ] = Encode( aToken.time )
    aTemplate[ 'time' ] = Encode( aContext.time or os.time() )
    aTemplate[ 'token' ] = Encode( aToken.token )

    aTemplate[ 'titleToken' ] = Encode( aToken.title )
    aTemplate[ 'title' ] = Encode( aContext.title )
    aTemplate[ 'textToken' ] = Encode( aToken.text )
    aTemplate[ 'text' ] = Encode( aContext.text )
    aTemplate[ 'versionToken' ] = Encode( aToken.version )
    aTemplate[ 'version' ] = Encode( aContext.version )

    aLayoutTemplate[ 'baseLink' ] = Encode( BaseLink() )
    aLayoutTemplate[ 'indexLink' ] = Encode( IndexLink( self.content.prefix ) )
    aLayoutTemplate[ 'dateLink' ] = Encode( aDateLink )
    aLayoutTemplate[ 'feedLink' ] = FeedLink()
    aLayoutTemplate[ 'path' ] = aContext.path
    aLayoutTemplate[ 'query' ] = nil
    aLayoutTemplate[ 'robot' ] = 'noindex,nofollow'
    aLayoutTemplate[ 'title' ] = Encode( ( aContext.title or '' ) .. ' — Preview' )
    aLayoutTemplate[ 'content' ] = aTemplate
    
    return tostring( aLayoutTemplate )
end


