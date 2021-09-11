--------------------------------------------------------------------------------
-- Title:               WikiDate.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- import dependencies
local Wiki = require( 'Wiki' )

local os = require( 'os' )

local error = error
local getmetatable = getmetatable
local ipairs = ipairs
local require = require
local setmetatable = setmetatable
local tonumber = tonumber
local type = type

--------------------------------------------------------------------------------
-- WikiDate
--------------------------------------------------------------------------------

module( 'WikiDate' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

local location = Wiki.Location()

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

local function Directory( aDate, shouldCreate )
    local File = require( 'File' )
    local lfs = require( 'lfs' )
    local aDirectory = File( location, 'wiki', 'date' )
    local someFormats = { '%04d', '%02d', '%02d' }
    local aDate = aDate or {}
    local someValues = { aDate.year, aDate.month, aDate.day }
    
    if shouldCreate then
        lfs.mkdir( aDirectory.path )
    end
    
    for anIndex, aValue in ipairs( someValues ) do
        if aValue then
            local aFormat = someFormats[ anIndex ]
        
            aDirectory = File( aDirectory.path, ( aFormat ):format( aValue ) )
            
            if shouldCreate then
                lfs.mkdir( aDirectory.path )
            end
        end
    end
    
    return aDirectory
end

local function DateIterator( aDate )
    local aDirectory = Directory( aDate, false )
    
    if aDirectory.exists then
        local anIterator = aDirectory()

        return function()            
            local aFile = anIterator()

            while aFile and not aFile.name:find( '^%d+$' ) do
                aFile = anIterator()
            end
            
            if aFile and aFile.name:find( '^%d+$' ) then                
                return tonumber( aFile.name )
            end

        end
    end
    
    return function() end
end

local function Iterator( aDate )
    local aDirectory = Directory( aDate, false )
    
    return Wiki.NameIterator( aDirectory, true )
end

local function Index( aName, aTime )
    local File = require( 'File' )
    local lfs = require( 'lfs' )
    local aDate = os.date( '!*t', aTime )
    local aDirectory = Directory( aDate, true )
    local anID = File( aDirectory.path, ( '%s.id' ):format( aName )  )
    
    lfs.mkdir( anID.path )
end

local function Delete( aName )
    local WikiContent = require( 'WikiContent' )
    local aContent = WikiContent( aName )
    
    if aContent.exists then
        local File = require( 'File' )
        local aTime = aContent.creation
        local aDate = os.date( '!*t', aTime )
        local aDirectory = Directory( aDate )
        local aFile = File( aDirectory.path, ( '%s.id' ):format( aName )  )

        if aFile.exists then
            aFile.delete = true
        end
        
        return
    end
    
    error( ( '%q doesn\'t exist' ):format( aName ) )
end

--------------------------------------------------------------------------------
-- Metamethods
--------------------------------------------------------------------------------

function meta:__call( aDate )
    return DateIterator( aDate )
end

function meta:__index( aDate )
    return Iterator( aDate )
end

function meta:__newindex( aKey, aValue )
    if type( aKey ) =='string' and type( aValue ) == 'boolean' and aValue == false then
        return Delete( aKey )
    elseif type( aKey ) == 'number' and type( aValue ) == 'string' then
        return Index( aValue, aKey )
    end
    
    error( ( 'Invalid parameters: %q = %q' ):format( tostring( aKey ), tostring( aValue ) ) )
end

function meta:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function meta:__tostring()
    return ( '%s/%s' ):format( self._NAME, self._VERSION )
end
