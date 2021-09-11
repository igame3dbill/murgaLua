--------------------------------------------------------------------------------
-- Title:               WikiAbout.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- import dependencies
local os = require( 'os' )
local package = require( 'package' )
local table = require( 'table' )

local collectgarbage = collectgarbage
local getmetatable = getmetatable
local pairs = pairs
local require = require
local setmetatable = setmetatable
local tostring = tostring
local type = type

local runtime = _VERSION

--------------------------------------------------------------------------------
-- WikiAbout
--------------------------------------------------------------------------------

module( 'WikiAbout' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

local function Memory()
    local aMemory = collectgarbage( 'count' )
    local anUnit = 'KB'
    local aPrecision = 0
    
    if aMemory > 999 then
        aMemory = aMemory / 1024
        anUnit = 'MB'
        aPrecision = 1
    end
    
    return aMemory, anUnit, aPrecision
end

local function Module()
    local aList = {}

    for aName, aPackage in pairs( package[ 'loaded' ] ) do
        if aName == aName:lower() and type( aPackage ) == 'table' then
            aList[ #aList + 1 ] = aName
        end
    end
    
    table.sort( aList )
    
    return aList
end

--------------------------------------------------------------------------------
-- Metamethods
--------------------------------------------------------------------------------

function meta:__call()
    return function()
        return tostring( self )
    end
end

function meta:__tostring()
    local Nanoki = require( 'Nanoki' )
    local Template = require( 'Template' )
    local aTemplate = Template[ 'WikiAbout.txt' ]
    local aMemory, anUnit, aPrecision = Memory()
    
    aTemplate[ 'version' ] = Nanoki._VERSION
    aTemplate[ 'year' ] = os.date( '!*t' ).year
    aTemplate[ 'runtime' ] = runtime
    aTemplate[ 'memory' ] = ( '%.' .. aPrecision .. 'f %s' ):format( aMemory, anUnit )
    aTemplate[ 'module' ] = table.concat( Module(), ', ' )
    
    return tostring( aTemplate )
end
