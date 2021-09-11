--------------------------------------------------------------------------------
-- Title:               WikiIndexNavigation.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- import dependencies
local HTTPExtra = require( 'HTTPExtra' )
local HTTPService = require( 'HTTPService' )
local Template = require( 'Template' )
local WikiIndex = require( 'WikiIndex' )
local WikiIndexService = require( 'WikiIndexService' )

local string = require( 'string' )

local getmetatable = getmetatable
local ipairs = ipairs
local mod = math.mod
local setmetatable = setmetatable
local tostring = tostring
local unpack = unpack

--------------------------------------------------------------------------------
-- WikiIndexNavigation
--------------------------------------------------------------------------------

module( 'WikiIndexNavigation' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

local function HasValue( anIterator, aValue )
    for aLocalValue in anIterator do
        if aLocalValue == aValue then
            return true
        end
    end
    
    return false
end

local function FormatFirst( aPrefix, aValue )
    local aFormat = aValue:upper()
    local isCurrent = aPrefix:lower():byte() == aValue:lower():byte()

    if not HasValue( WikiIndex(), aValue:lower() ) then
        aValue = nil
    end

    return aFormat, aValue, isCurrent
end

local function FormatSecond( aPrefix, aValue )
    local aFormat = aValue:lower()
    local isCurrent = aPrefix:len() == 2 and aPrefix:lower():byte( 2 ) == aValue:lower():byte()

    if HasValue( WikiIndex( aPrefix:sub( 1, 1 ) ), aValue:lower() ) then
        aValue = aPrefix:sub( 1, 1 ) .. aValue
    else
        aValue = nil
    end

    return aFormat, aValue, isCurrent
end

local values =
{
    { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L' },
    { 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X' },
    { 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' },
    { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l' },
    { 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x' },
    { 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' }
}

local types = { 'first', 'first', 'first', 'second', 'second', 'second' }
local formats = { first = FormatFirst, second = FormatSecond }

local function Unpack( aString )
    local aList = {}
    
    for anIndex = 1, aString:len() do
        aList[ #aList + 1 ] = string.char( aString:byte( anIndex ) )
    end
    
    return unpack( aList )
end

local function FormatValue( aType, aPrefix, aValue )
    local aValue, aPrefix, isCurrent = formats[ aType ]( aPrefix, aValue )

    if aValue and isCurrent then
        aValue = ( '<b>%s</b>' ):format( aValue )
    end
    
    if aValue and aPrefix then
        local aService = WikiIndexService( Unpack( aPrefix ) )
        local anURL = HTTPService[ aService ]
        local aPath = tostring( anURL.path )

        aValue = ( '<a href=\'%s\' title=\'%s\'>%s</a>' ):format( aPath, aPrefix, aValue )
    end
        
    return aValue or '&nbsp;'
end

--------------------------------------------------------------------------------
-- Metamethods
--------------------------------------------------------------------------------

function meta:__call( aPrefix )
    local aNavigation = { prefix = aPrefix }

    setmetatable( aNavigation, self )

    return aNavigation
end

function self:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function self:__tostring()
    local aTemplate = Template[ 'WikiNavigation.txt' ]
    local aPrefix = self.prefix
    
    for aRowIndex, aRowValue in ipairs( values ) do
        local aRowTemplate = aTemplate[ 'rows' ]
        local aRowType = types[ aRowIndex ]
        
        for aColumnIndex, aColumnValue in ipairs( aRowValue ) do
            local aColumnTemplate = aRowTemplate[ 'columns' ]
            
            aColumnTemplate[ 'value' ] = FormatValue( aRowType, aPrefix, aColumnValue )
            
            aRowTemplate[ 'columns' ] = aColumnTemplate
        end

        aTemplate[ 'rows' ] = aRowTemplate
    end

    return tostring( aTemplate )
end


