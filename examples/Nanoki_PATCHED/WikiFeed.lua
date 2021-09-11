--------------------------------------------------------------------------------
-- Title:               WikiFeed.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- import dependencies
local os = require( 'os' )
local table = require( 'table' )
local Template = require( 'Template' )
local URL = require( 'URL' )

local getmetatable = getmetatable
local setmetatable = setmetatable
local tostring = tostring

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

local function Encode( aValue )
    local anEncoder = function( aValue ) 
        return ( '&#%02d;' ):format( aValue:byte() ) 
    end
    
    return ( tostring( aValue or '' ):gsub( '([<>&\'"])', anEncoder ) )
end

local function Link( aURL, shouldAdd )
    local aSuffix = '.xml'
    local aLink = tostring( aURL )
    
    if shouldAdd and not aLink:find( aSuffix, aLink:len() - aSuffix:len(), true ) then
        aLink = aLink .. aSuffix
    end
    
    if not shouldAdd and aLink:find( aSuffix, aLink:len() - aSuffix:len(), true ) then
        aLink = aLink:sub( 1, aLink:len() - aSuffix:len() )
    end
    
    return Encode( aLink )
end

local function Date( aTime )
    return os.date( '!%Y-%m-%dT%H:%M:%SZ', aTime )
end

local function ID( aContext, aContent )
    local aBuffer = {}
    
    aBuffer[ #aBuffer + 1 ] = 'tag'
    aBuffer[ #aBuffer + 1 ] = ':'
    aBuffer[ #aBuffer + 1 ] = tostring( aContext.link.host )
    aBuffer[ #aBuffer + 1 ] = ','
    aBuffer[ #aBuffer + 1 ] = os.date( '!%Y-%m-%d', aContext.creation )
    aBuffer[ #aBuffer + 1 ] = ':'
    
    if aContent then
        aBuffer[ #aBuffer + 1 ] = aContent.name
    else
        aBuffer[ #aBuffer + 1 ] = tostring( aContext.link.path )
    end
    
    return table.concat( aBuffer )
end

--------------------------------------------------------------------------------
-- WikiFeed
--------------------------------------------------------------------------------

module( 'WikiFeed' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

function meta:__call( anIterator, aGenerator, aContext )
    local aFeed = { iterator = anIterator, generator = aGenerator, context = aContext }

    setmetatable( aFeed, self )
    
    return aFeed
end

function self:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function self:__tostring()
    local aTemplate = Template[ 'WikiFeed.txt' ]
    local anIterator = self.iterator
    local aGenerator = self.generator
    local aContext = self.context
    local aLimit = aContext.limit or 100
    local aCount = 0
    local lastModification = 0
    
    aTemplate[ 'title' ] = Encode( aContext.title )
    aTemplate[ 'link' ] = Link( aContext.link )
    aTemplate[ 'selfLink' ] = Link( aContext.link, true )
    aTemplate[ 'id' ] = ID( aContext )
    
    for aContent, aURL in anIterator do
        local anEntryTemplate = aTemplate[ 'entries' ]
        local byURL = URL( aContent.by )
        local aUser = byURL.user or 'anonymous'
        local aHost = ( '%s://%s' ):format( byURL.scheme or 'http', byURL.host or 'localhost' )
        
        anEntryTemplate[ 'title' ] = Encode( aContent.data.title )
        anEntryTemplate[ 'link' ] = Link( aURL )
        anEntryTemplate[ 'selfLink' ] = Link( aURL, true )
        anEntryTemplate[ 'updated' ] = Date( aContent.modification )
        anEntryTemplate[ 'user' ] = Encode( aUser )
        anEntryTemplate[ 'host' ] = Encode( aHost )
        anEntryTemplate[ 'id' ] = ID( aContext, aContent )
        anEntryTemplate[ 'content' ] = Encode( aGenerator( aContent ) )
        
        if aContent.modification > lastModification then
            lastModification = aContent.modification
        end
        
        aTemplate[ 'entries' ] = anEntryTemplate

        aCount = aCount + 1
        
        if aCount >= aLimit then
            break
        end
    end

    aTemplate[ 'updated' ] = Date( lastModification )
    
    if lastModification > 0 then
        return tostring( aTemplate )
    end
end
