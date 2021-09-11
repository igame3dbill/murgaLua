--------------------------------------------------------------------------------
-- Title:               Diff.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- As per Reuben Thomas's stdlib LCS module:
-- http://luaforge.net/projects/stdlib/
-- Based on pseudo-code in
-- http://www.ics.uci.edu/~eppstein/161/960229.html
-- Lecture notes by David Eppstein, eppstein@ics.uci.edu

-- import dependencies
local math = require( 'math' )
local table = require( 'table' )

local getmetatable = getmetatable
local setmetatable = setmetatable
local tostring = tostring

--------------------------------------------------------------------------------
-- Diff
--------------------------------------------------------------------------------

module( 'Diff' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

local function Token( aValue, aPattern, aLimit )
    local aPattern = aPattern or '([%C]+)'
    local aLimit = aLimit or 1000
    local aList = {}
    local hasMore = false
    
    for aToken in tostring( aValue ):gmatch( aPattern ) do
        if #aList >= aLimit then
            hasMore = true
            break
        end
        
        aList[ #aList + 1 ] = aToken
    end
    
    return aList, hasMore
end

local function Sequence( listA, listB )
    local max = math.max
    local aList = {}
    local lengthA = #listA
    local lengthB = #listB

    for indexA = lengthA + 1, 1, -1 do
        aList[ indexA ] = {}
        
        for indexB = lengthB + 1, 1, -1 do
            if indexA > lengthA or indexB > lengthB then
                aList[ indexA ][ indexB ] = 0
            elseif listA[ indexA ] == listB[ indexB ] then
                aList[ indexA ][ indexB ] =  1 + aList[ indexA + 1 ][ indexB + 1 ]
            else
                aList[ indexA ][ indexB ] = max( aList[ indexA + 1][ indexB ], aList[ indexA ][ indexB + 1 ] )
            end
        end
    end

    return aList, lengthA, lengthB
end

local function Diff( listA, listB, aHandler )
    local aList, lengthA, lengthB = Sequence( listA, listB )
    local indexA, indexB = 1, 1
    local aBuffer = {}

    while indexA <= lengthA or indexB <= lengthB do
        if indexA > lengthA then
            aBuffer[ #aBuffer + 1 ] = aHandler( '+', listB[ indexB ] )
            indexB = indexB + 1
        elseif indexB > lengthB then
            aBuffer[ #aBuffer + 1 ] = aHandler( '-', listA[ indexA ] )
            indexA = indexA + 1
        elseif listA[ indexA ] == listB[ indexB ] then
            aBuffer[ #aBuffer + 1 ] = aHandler( '=', listA[ indexA ] )
            indexA = indexA + 1
            indexB = indexB + 1
        elseif aList[ indexA + 1 ][ indexB ] >= aList[ indexA ][ indexB + 1 ] then
            aBuffer[ #aBuffer + 1 ] = aHandler( '-', listA[ indexA ] )
            indexA = indexA + 1
        else
            aBuffer[ #aBuffer + 1 ] = aHandler( '+', listB[ indexB ] )
            indexB = indexB + 1
        end
    end

    return table.concat( aBuffer, ' ' ) 
end

local function Handler( aType, aValue )
    if aType == '=' then
        return aValue
    end
    
    return ( '%s%s%s' ):format( aType, aValue, aType )    
end

--------------------------------------------------------------------------------
-- Metamethods
--------------------------------------------------------------------------------

function meta:__call( aTextA, aTextB, aHandler, aPattern, aLimit )
    if aTextA and aTextB and aTextA ~= aTextB then
        local aListA, hasMoreA = Token( aTextA, aPattern, aLimit )
        local aListB, hasMoreB = Token( aTextB, aPattern, aLimit )
        local aHandler = aHandler or Handler
        
        return Diff( aListA, aListB, aHandler ), hasMoreA or hasMoreB
    end
end


