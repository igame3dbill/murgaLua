--------------------------------------------------------------------------------
-- Title:               XML.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- Follows David Sklar's BadgerFish convention for translating an XML document into a Lua table.
--
-- http://badgerfish.ning.com/
--
-- 1. Element names become table keys.
-- 
-- 2. Text content of elements goes in the '$' key of a table.
--    <alice>bob</alice>
--    becomes
--    { alice  = { [ '$' ] = 'bob' } }
-- 
-- 3. Nested elements become nested tables.
--    <alice><bob>charlie</bob><david>edgar</david></alice>
--    becomes
--    { alice = { bob = { [ '$' ] = 'charlie' }, david = { [ '$' ] = 'edgar' } } }
--
-- 4. Multiple elements at the same level become list elements.
--    <alice><bob>charlie</bob><bob>david</bob></alice>
--    becomes
--    { alice = { bob = { { [ '$' ] = 'charlie' }, { [ '$' ]  = 'david' } } } }
--
-- 5. Attributes go in keys whose names begin with '@'.
--    <alice charlie="david">bob</alice>
--    becomes
--    { alice: { [ '$' ] = 'bob', [ '@charlie' ] = 'david' } }
--

-- import dependencies
local string = require( 'string' )

local assert = assert
local getmetatable = getmetatable
local pairs = pairs
local setmetatable = setmetatable
local tonumber = tonumber
local tostring = tostring
local type = type
local unpack = unpack

--------------------------------------------------------------------------------
-- XML
--------------------------------------------------------------------------------

module( 'XML' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

local function Encode( aTable )
    -- to do
end

local function GFind( aString, aPattern, anIndex )
    local anIndex = anIndex or 1
    
    return function()
        local aResult = { aString:find( aPattern, anIndex ) }
        
        if #aResult > 0 then
            anIndex = aResult[ 2 ] + 1
            
            return unpack( aResult )
        end
    end
end

local function Trim( aValue )
    return ( aValue:gsub( '^[%c%s]+', '' ):gsub( '[%s%c]+$', '' ) )
end

local entities = { lt = '<', gt = '>', amp = '&', apos = '\'', quot = '"' }

local function DecodeEntity( aType, anEntity )
    if aType == '#' then
        local aCode = tonumber( ( anEntity:gsub( '^x', '0x' ) ) )
        
        if aCode ~= nil and aCode < 256 then
            return string.char( aCode )
        end
    else
        local aValue = entities[ anEntity ]
        
        if aValue ~= nil then
            return aValue
        end
    end
    
    return ( '&%s%s;' ):format( aType, anEntity )
end

local function DecodeValue( aValue )
    return Trim( aValue:gsub( '&(#?)(%w+);', DecodeEntity ) )
end

local function Name( aValue )
    if not aValue:find( '^xml' ) then
        local anIndex = aValue:find( ':', 1, true )
    
        if anIndex then
            aValue = aValue:sub( anIndex + 1 )
        end
    end
    
    return aValue
end

local function Text( aContent, aStart, anEnd )
    local aText = aContent:sub( aStart, anEnd )

    if not aText:find( '^%s*$' ) then
        return DecodeValue( aText )
    end
end

local function Node( aValue )
    local aNode = {}
    local aDecoder = function( aName, _, aValue )
        aName = Name( aName )
        aName = '@' .. aName
        aNode[ aName ] = DecodeValue( aValue )
    end
    
    aValue:gsub( '([%w%.%-%_%:]+)=([\"\'])(.-)%2', aDecoder )
    
    return aNode
end

local function Merge( aNode )
    for aKey, aValue in pairs( aNode ) do
        if type( aValue ) == 'table' and #aValue == 1 then
            aNode[ aKey ] = aValue[ 1 ]
        end
    end
    
    return aNode
end

local function Decode( aString )
    local aStack = {}
    local anIndex = 1

    aStack[ #aStack + 1 ] = {}

    for aStart, anEnd, isClose, aName, aContent, isEmpty in GFind( aString, '<(%/?)([%w%.%-%_%:]+)(.-)(%/?)>' ) do
        if isClose == '' then
            local aName = Name( aName )
            local aParent = assert( aStack[ #aStack ] )
            local someNodes = aParent[ aName ] or {}
            local aNode = Node( aContent )
            
            someNodes[ #someNodes + 1 ] = aNode
            aParent[ aName ] = someNodes
            
            if isEmpty == '' then
                aStack[ #aStack + 1 ] = aNode
            end
        else
            local aNode = assert( aStack[ #aStack ] )
            local aText = Text( aString, anIndex, aStart - 1 )
            
            aNode[ '$' ] = aText
            Merge( aNode )
            
            aStack[ #aStack ] = nil
        end
        
        anIndex = anEnd + 1
    end
    
    return Merge( assert( aStack[ 1 ] ) )
end

function meta:__call( anObject )
    if type( anObject ) == 'table' then
        return Encode( anObject )
    end
    
    return Decode( tostring( anObject ) )
end
