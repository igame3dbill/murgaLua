--------------------------------------------------------------------------------
-- Title:               WikiRecent.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- import dependencies
local Wiki = require( 'Wiki' )

local error = error
local getmetatable = getmetatable
local require = require
local setmetatable = setmetatable
local type = type

--------------------------------------------------------------------------------
-- WikiRecent
--------------------------------------------------------------------------------

module( 'WikiRecent' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

local location = Wiki.Location()

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

local function Directory( shouldCreate )
    local File = require( 'File' )
    local aDirectory = File( location, 'wiki', 'recent' )
    
    if shouldCreate then
        local lfs = require( 'lfs' )
        
        lfs.mkdir( aDirectory.path )
    end
    
    return aDirectory
end

local function Index( aName, aTime )
    local File = require( 'File' )
    local lfs = require( 'lfs' )
    local aDirectory = Directory( true )
    local aFile = File( aDirectory.path, ( '%s.id' ):format( aName ) )
    
    lfs.mkdir( aFile.path )
    aFile.modification = aTime
    
    Wiki.PurgeDirectory( aDirectory )
end

local function Delete( aName )
    local File = require( 'File' )
    local aDirectory = Directory()
    local aFile = File( aDirectory.path, ( '%s.id' ):format( aName ) )
    
    if aFile.exists then
        aFile.delete = true
    end
end

--------------------------------------------------------------------------------
-- Metamethods
--------------------------------------------------------------------------------

function meta:__call( aDate )
    return Wiki.NameIterator( Directory() )
end

function meta:__index( aKey )
    return Wiki.NameIterator( Directory() )
end

function meta:__newindex( aKey, aValue )
    if type( aKey ) == 'string' and type( aValue ) == 'boolean' and aValue == false then
        return Delete( aKey )
    elseif type( aKey ) == 'number' and type( aValue ) == 'string' then
        return Index( aValue, aKey )
    end

    error( ( 'Invalid parameters: %q = %q' ):format( tostring( aKey ), tostring( aValue ) ) )
end

function meta:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function meta:__tostring()
    return ( '%s/%s' ):format( self._NAME, self._VERSION )
end
