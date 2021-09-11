--------------------------------------------------------------------------------
-- Title:               NaturalComparator.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- Based on Andre Bogus implementation of David Koelle's Alphanum algorithm:
-- http://www.davekoelle.com/files/alphanum.lua
-- http://www.davekoelle.com/alphanum.html

-- import dependencies
local math = require( 'math' )

local getmetatable = getmetatable
local setmetatable = setmetatable
local tonumber = tonumber
local tostring = tostring
local type = type

--------------------------------------------------------------------------------
-- NaturalComparator
--------------------------------------------------------------------------------

module( 'NaturalComparator' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

local function Token( aString )
    local aList = {}
    
    for aNumber, aString in aString:gmatch( '(%d*)(%D*)' ) do
        if aNumber:len() > 0 then
            aList[ #aList + 1 ] = tonumber( aNumber )
        end
        
        if aString:len() > 0 then
            aList[ #aList + 1 ] = aString
        end
    end
    
    return aList
end

local function Compare( aString, anotherString )
    local aToken = Token( tostring( aString or '' ) )
    local anotherToken = Token( tostring( anotherString or '' ) )
    
    for anIndex = 1, math.min( #aToken, #anotherToken ) do
        local aValue = aToken[ anIndex ]
        local anotherValue = anotherToken[ anIndex ]
        
        if type( aValue ) == 'string' then 
            anotherValue = tostring( anotherValue )
        elseif type( anotherValue ) == 'string' then 
            aValue = tostring( aValue ) 
        end
        
        if aValue ~= anotherValue then 
            return aValue < anotherValue 
        end
    end
    
    return #aToken < #anotherToken
end

--------------------------------------------------------------------------------
-- Metamethods
--------------------------------------------------------------------------------

function meta:__call()
    return Compare
end

function meta:__tostring()
    return ( '%s/%s' ):format( self._NAME, self._VERSION )
end
