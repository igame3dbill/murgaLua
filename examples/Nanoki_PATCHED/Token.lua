--------------------------------------------------------------------------------
-- Title:               Token.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

local md5 = require( 'md5' )
local os = require( 'os' )
local package = require( 'package' )
local random = random
local string = require( 'string' )

local getmetatable = getmetatable
local rawset = rawset
local setmetatable = setmetatable
local tostring = tostring

local version = _VERSION

--------------------------------------------------------------------------------
-- Token
--------------------------------------------------------------------------------

module( 'Token' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

local context = setmetatable( {}, { __mode = 'k' } )

local function Base( aTime )
    local aTime = aTime or os.time()
    local aDate = os.date( '*t', aTime )
    local aDateFormat = os.date( '!%A, %B %d %Y, %p %Z ', aTime )
    local aBase = md5.sumhexa( ( '%s %s %s' ):format( aDateFormat, package.path, version ) )
    
    aDate = { year = aDate.year, month = aDate.month, day = aDate.day }
    aTime = os.time( aDate )
    
    return aBase, aTime
end

local function Range( aContext )
    local aRandom = aContext.random
    local aLength = aRandom( 3, 9 )
    local aStart = aRandom( 1, 32 - aLength ) 
    local anEnd = aStart + aLength - 1
    
    return aStart, anEnd
end

local function Convert( aValue, anIndex )
    return string.char( 103 + aValue + anIndex )
end

local function ID( aContext )
    local aPrefix = aContext.prefix
    local aBase = aContext.base
    local aRandom = aContext.random
    local aSuffix = md5.sumhexa( tostring( aRandom() ) )
    local anID = ( '%s %s %s' ):format( aPrefix, aBase, aSuffix )
    
    anID = md5.sumhexa( anID )
    anID = anID:sub( Range( aContext ) )
    anID = anID:gsub( '(%d)()', Convert )
    
    if not aContext[ anID ] then
        aContext[ anID ] = true
        
        return anID
    end
    
    return ID( aContext )
end

local function Random( aSeed )
    local aRandom = random.new( aSeed )

    return function( aStart, anEnd )
        if aStart and anEnd then
            return aRandom:valuei( aStart, anEnd )
        elseif aStart then
            return aRandom:valuei( aStart )
        end
        
        return aRandom:value()
    end
end

function meta:__call( aPrefix, aTime )
    local aPrefix = md5.sumhexa( tostring( aPrefix ) )
    local aBase, aSeed = Base( aTime )
    local aRandom = Random( aSeed )
    local aContext = { prefix = aPrefix, base = aBase, random = aRandom }
    local aToken = {}
    
    setmetatable( aToken, self )
    context[ aToken ] = aContext
    
    return aToken
end

function self:__call()
    return ID( context[ self ] )
end

function self:__index( aKey )
    local anID = self()
    
    rawset( self, aKey, anID )
    
    return anID
end
