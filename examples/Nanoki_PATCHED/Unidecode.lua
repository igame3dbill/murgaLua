--------------------------------------------------------------------------------
-- Title:               Unidecode.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       August 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- import dependencies
local io = require( 'io' )

local getmetatable = getmetatable
local pairs = pairs
local package = package
local rawget = rawget
local rawset = rawset
local require = require
local setmetatable = setmetatable

--------------------------------------------------------------------------------
-- bits
-- as per Stephane Arnold's Validate Unicode String
-- http://lua-users.org/wiki/ValidateUnicodeString
--------------------------------------------------------------------------------

local bits = { max = 64 }

for i = 0, bits.max do
    bits[i] = 2 ^ i
    -- integer overflow detection
    if tostring(bits[i]) == tostring(bits[i]-1) then
        bits.max = i - 1
        break
    end
end

function bits:lshift(int, shift)
    assert(shift ~= nil, "lshift(int,shift)")
    assert(self[shift] ~= nil, "bad shift " .. shift)
    local i
    for i = 1, shift do
        int= (int * 2) % self[self.max]
    end
    return int
end

function bits:rshift(int, shift)
    assert(shift ~= nil, "lshift(int,shift)")
    assert(self[shift] ~= nil, "bad shift " .. shift)
    return math.floor(int / self[shift])
end

local charnum = {}
for i = 3, 7 do
    charnum[i] = bits:lshift(1, i) - 2
end

function bits:read(str)
    return string.byte(string.sub(str, 1, 1)), string.sub(str,2)
end

function bits:utf8(str)
    local char, num, i, v
    local result = 0
    char, str = self:read(str)
    -- a simple ASCII 7 bit character
    if char < 128 then return char, str end

    for i, v in pairs(charnum) do
        if v == self:rshift(char, 8 - i) then
            num = i
            break
        end
    end
    assert(num ~= nil, "invalid char : " .. char)
    -- takes the first bits of the digits
    local n = 8 - num
    result = char % self[n]
    for i = 1, num - 2 do
        char, str = self:read(str)
        assert(2 == self:rshift(char, 6), "invalid char " .. char ..
            " at position " .. i)
        result = self:lshift(result, 6) + char % self[6]
    end
    return result, str
end

--------------------------------------------------------------------------------
-- Unidecode
-- as per Sean M. Burke's Text::Unidecode
-- http://search.cpan.org/~sburke/Text-Unidecode-0.04/lib/Text/Unidecode.pm
-- http://interglacial.com/~sburke/tpj/as_html/tpj22.html
--------------------------------------------------------------------------------

module( 'Unidecode' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )
local data = setmetatable( {}, {} )
local metadata = getmetatable( data )

function metadata:__index( aKey )
    local aBlock = ( '%02x' ):format( bits:rshift( bits:utf8( aKey ), 8 ) ):upper()
    local aSeparator = package.path:match( '(%p)%?%.' ) or '/'
    local aPath = 'Unidecode' .. aSeparator .. aBlock .. '.txt'
    
    if io.open( aPath, 'rb' ) then
        local Data = require( 'Data' )
        local aData = Data[ aPath ]
        
        for aKey, aValue in pairs( aData ) do
            if #aValue > 1 and aValue:byte( #aValue ) == 32 then
                aValue = aValue:gsub( '[%s%c]+$', '' ):lower()
            end
            
            rawset( self, aKey, aValue )
        end
    end
    
    if not rawget( self, aKey ) then
        rawset( self, aKey, '' )
    end
    
    return rawget( self, aKey )
end

function meta:__call( aValue )
    if aValue then
        -- UTF-8 sequences
        -- as per http://lua-users.org/wiki/LuaUnicode
        return ( aValue:gsub( '([%z\1-\127\194-\244][\128-\191]*)', data ) )
    end
end

