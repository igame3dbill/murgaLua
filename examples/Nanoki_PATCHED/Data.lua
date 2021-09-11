--------------------------------------------------------------------------------
-- Title:               Data.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- import dependencies
local io = require( 'io' )
local string = require( 'string' )
local table = require( 'table' )

local assert = assert
local getfenv = getfenv
local getmetatable = getmetatable
local loadstring = loadstring
local pairs = pairs
local setfenv = setfenv
local setmetatable = setmetatable
local tonumber = tonumber
local tostring = tostring
local type = type

--------------------------------------------------------------------------------
-- Data
--------------------------------------------------------------------------------

module( 'Data' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )
local encoders = {}

local function HexDecode( aString )
    local aCoder = function( aValue )
        return string.char( tonumber( aValue, 16 ) )
    end

    return aString:gsub( '(%x%x)', aCoder )
end

local function HexEncode( aString )
    local aCoder = function( aValue )
        return ( '%02x' ):format( aValue:byte() )
    end

    return aString:gsub( '.', aCoder )
end

local function DecodeFunction( aFunction )
    return assert( loadstring( HexDecode( aFunction ) ) )
end

local function Decode( anObject )
    local aChunk = assert( loadstring( anObject ) )
    
    setfenv( aChunk, { _ = {}, f = DecodeFunction } )
    aChunk()
        
    return getfenv( aChunk )._
end

local function Encode( anObject, someReferences, aName )
    local anEncoder = encoders[ type( anObject ) ] 
    
    if anEncoder then
        return anEncoder( anObject, someReferences or {}, aName )
    end
    
    return 'nil'
end

local function EncodeBoolean( aBoolean )
    return tostring( aBoolean )
end

local function EncodeFunction( aFunction )
    return 'f"' .. HexEncode( string.dump( aFunction ) ) .. '"'
end

local function EncodeNumber( aNumber )
    return tostring( aNumber )
end

local function EncodeString( aString )
    return ( '%q' ):format( aString )
end

local function EncodeTable( aTable, someReferences, aName )
    if not someReferences[ aTable ] then
        local aBuffer = {}
    
        if aName then
            aBuffer[ #aBuffer + 1 ] = '{}'
        end
    
        aName = aName or '_'
        someReferences[ aTable ] = aName
        
        for aKey, aValue in pairs( aTable ) do
            local aLocalName = ( '%s[%s]' ):format( aName, Encode( aKey, someReferences, aName ) )
            
            aKey = Encode( aKey, someReferences, aLocalName )
            aValue = Encode( aValue, someReferences, aLocalName )
            
            aBuffer[ #aBuffer + 1 ] = ( '%s[%s]=%s' ):format( aName, aKey, aValue ) 
        end
        
        return table.concat( aBuffer, '\n' )
    end

    return someReferences[ aTable ]
end

encoders[ 'boolean' ] = EncodeBoolean
encoders[ 'function' ] = EncodeFunction 
encoders[ 'number' ] = EncodeNumber
encoders[ 'string' ] = EncodeString
encoders[ 'table' ] = EncodeTable

function meta:__call( anObject )
    if type( anObject ) == 'table' then
        return Encode( anObject )
    end
    
    return Decode( tostring( anObject ) )
end

function meta:__index( aKey )
    local aFile = assert( io.open( aKey, 'rb' ) )
    local aContent = aFile:read( '*a' )
    
    aFile:close()

    return self( aContent )
end

function meta:__newindex( aKey, aValue )
    local aFile = assert( io.open( aKey, 'wb' ) )

    aFile:write( self( aValue ) )
    aFile:close()
end

