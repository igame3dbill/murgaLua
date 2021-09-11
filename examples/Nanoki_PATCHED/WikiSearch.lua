--------------------------------------------------------------------------------
-- Title:               WikiSearch.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- import dependencies
local Wiki = require( 'Wiki' )

local math = require( 'math' )
local string = require( 'string' )
local table = require( 'table' )

local error = error
local getmetatable = getmetatable
local ipairs = ipairs
local pairs = pairs
local require = require
local setmetatable = setmetatable
local type = type
local unpack = unpack

--------------------------------------------------------------------------------
-- WikiSearch
--------------------------------------------------------------------------------

module( 'WikiSearch' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

local location = Wiki.Location()

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

local stop = { [ 'and' ] = true, [ 'are' ] = true, [ 'but' ] = true, [ 'for' ] = true, [ 'into' ] = true, [ 'not' ] = true, [ 'such' ] = true, [ 'that' ] = true, [ 'the' ] = true, [ 'their' ] = true, [ 'then' ] = true, [ 'there' ] = true, [ 'these' ] = true, [ 'they' ] = true, [ 'this' ] = true, [ 'will' ] = true, [ 'with' ] = true, [ 'yes' ] = true, [ 'you' ] = true, [ 'your' ] = true }

local function Directory( shouldCreate )
    local File = require( 'File' )
    local aDirectory = File( location, 'wiki', 'index' )
    
    if shouldCreate then
        local lfs = require( 'lfs' )
        
        lfs.mkdir( aDirectory.path )
    end
    
    return aDirectory
end

local function TokenComparator( aToken, anotherToken )
    local aLength = #aToken
    local anotherLength = #anotherToken
    
    if aLength == anotherLength then
        return aToken > anotherToken
    end
    
    return aLength > anotherLength
end

local function Tokens( aValue )
    local Unidecode = require( 'Unidecode' )
    local aValue = Unidecode( aValue or '' ):lower()
    local aMap = {}
    local aList = {}
    
    for aToken in aValue:gsub( '%p', ' ' ):gmatch( '([%S]+)' ) do
        if #aToken > 2 and not stop[ aToken ] then
            aMap[ aToken ] = true
        end
    end
    
    for aKey in pairs( aMap ) do
        aList[ #aList + 1 ] = aKey
    end
    
    table.sort( aList, TokenComparator )
    
    return aList
end

function MatchToken( aValue, aToken )
    local aCount = math.floor( #aToken / 3 )
    
    if aCount < 2 then
        aCount = 0
    end
    
    for anIndex = 0, aCount do
        local aToken = aToken:sub( 1, #aToken - anIndex )
        
        if aValue:find( '^' .. aToken ) or aValue:find( '%-' .. aToken ) then
            return true
        end
    end
    
    return false
end

function MatchTokens( aValue,  someTokens )
    for _, aToken in ipairs( someTokens ) do
        if not MatchToken( aValue, aToken ) then
            return false
        end
    end
    
    return true
end

function Tries( someTokens )
    local Trie = require( 'Trie' )
    local aDirectory = Directory()
    local aPath = aDirectory.path
    local someTries = {}

    for _, aToken in ipairs( someTokens ) do
        someTries[ #someTries + 1 ] = Trie( aPath )[ aToken ]
    end

    return someTries
end

function Hits( someTokens, aLimit )
    local NaturalComparator = require( 'NaturalComparator' )
    local someTries = Tries( someTokens )
    local aLimit = aLimit or 1000
    local aMap = {}
    local aList = {}
    local anIndex = 1
    local hasData = true
    
    while #someTokens > 0 and anIndex < aLimit and hasData do
        for _, aTrie in ipairs( someTries ) do
            local aName = aTrie()
            
            if not aName then
                hasData = false
                break
            end
            
            if MatchTokens( aName, someTokens ) then
                aMap[ aName ] = true
            end
            
            anIndex = anIndex + 1
        end
    end
    
    for aName, _ in pairs( aMap ) do
        aList[ #aList + 1 ] = aName
    end
    
    table.sort( aList, NaturalComparator() )
    
    return aList
end

local function Iterator( aText )
    local someTokens = Tokens( aText )
    local someHits = Hits( someTokens )
    local aCount = #someHits
    local anIndex = 0
    
    return function()
        anIndex = anIndex + 1

        if anIndex <= aCount then
            return someHits[ anIndex ]
        end 
    end, aCount
end

local function Index( aText, aName )
    local Trie = require( 'Trie' )
    local aDirectory = Directory( true )
    local aTrie = Trie( aDirectory.path )
    local someTokens = Tokens( aText )
    
    for _, aToken in ipairs( someTokens ) do
        aTrie[ aToken ] = aName
    end
end

local function Unpack( aKey, aName )
    local aList = {}
    
    for anIndex = 1, aKey:len() do
        aList[ #aList + 1 ] = string.char( aKey:byte( anIndex ) )
    end
    
    aList[ #aList + 1 ] = ( '%s.id' ):format( aName )
    
    return unpack( aList )
end

local function Delete( aName )
    local Trie = require( 'Trie' )
    local File = require( 'File' )
    local aDirectory = Directory()
    local someTokens = Tokens( aName )
    
    for _, aToken in ipairs( someTokens ) do
        local aKey = Trie[ aToken ]
        local aFile = File( aDirectory.path, Unpack( aKey, aName ) )
        
        if aFile.exists then
            aFile.delete = true
        end
    end
end

--------------------------------------------------------------------------------
-- Metamethods
--------------------------------------------------------------------------------

function meta:__index( aText )
    return Iterator( aText )
end

function meta:__newindex( aKey, aValue )
    if type( aKey ) == 'string' and type( aValue ) == 'boolean' and aValue == false then
        return Delete( aKey )
    elseif type( aKey ) == 'string' and type( aValue ) == 'string' then
        return Index( aKey, aValue )
    end

    error( ( 'Invalid parameters: %q = %q' ):format( tostring( aKey ), tostring( aValue ) ) )
end

function meta:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function meta:__tostring()
    return ( '%s/%s' ):format( self._NAME, self._VERSION )
end
