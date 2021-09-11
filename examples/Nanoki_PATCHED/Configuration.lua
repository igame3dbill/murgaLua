--------------------------------------------------------------------------------
-- Title:               Configuration.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- import dependencies
local io = require( 'io' )
local table = require( 'table' )

local assert = assert
local getmetatable = getmetatable
local loadstring = loadstring
local setfenv = setfenv
local setmetatable = setmetatable
local tostring = tostring

--------------------------------------------------------------------------------
-- Configuration
--------------------------------------------------------------------------------

module( 'Configuration' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

local function Trim( aValue )
    return ( aValue:gsub( '^[%c%s]+', '' ):gsub( '[%s%c]+$', '' ) )
end

local function Format( aValue )
    local aBuffer = {}
    
    for aLine in aValue:gmatch( '(%C+)' ) do
        aLine = Trim( aLine )
        
        if aLine:len() > 0 then
            aBuffer[ #aBuffer + 1 ] = aLine
        end
    end
    
    return ( 'return { %s }' ):format( table.concat( aBuffer, ',\n' ) )
end

local function Read( aValue )
    local aValue = Format( aValue )
    local aChunk = assert( loadstring( aValue ) )
    
    setfenv( aChunk, {} )
    
    return aChunk()
end

--------------------------------------------------------------------------------
-- Metamethods
--------------------------------------------------------------------------------

function meta:__call( aValue )
    return Read( tostring( aValue ) )
end

function meta:__index( aKey )
    local aFile = assert( io.open( aKey, 'rb' ) )
    local aContent = aFile:read( '*a' )
    
    aFile:close()

    return self( aContent )
end

function meta:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function meta:__tostring()
    return ( '%s/%s' ):format( self._NAME, self._VERSION )
end


