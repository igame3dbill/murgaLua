--------------------------------------------------------------------------------
-- Title:               WikiIndex.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- import dependencies
local Wiki = require( 'Wiki' )

local getmetatable = getmetatable
local ipairs = ipairs
local require = require
local setmetatable = setmetatable

--------------------------------------------------------------------------------
-- WikiIndex
--------------------------------------------------------------------------------

module( 'WikiIndex' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

local location = Wiki.Location()

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

local function Directory( aPrefix )
    local File = require( 'File' )
    local aDirectory = File( location, 'wiki', 'content' )
    local someValues = { ( aPrefix or '' ):lower():match( '^(%w?)(%w?)' ) }
    
    for anIndex, aValue in ipairs( someValues ) do
        aDirectory = File( aDirectory.path, aValue )
    end
    
    return aDirectory
end

local function PrefixIterator( aPrefix )
    local aDirectory = Directory( aPrefix )
    
    if aDirectory.exists then
        local anIterator = aDirectory()

        return function()            
            local aFile = anIterator()

            while aFile and not aFile.name:find( '^%w$' ) do
                aFile = anIterator()
            end
            
            if aFile and aFile.name:find( '^%w$' ) then                
                return aFile.name
            end

        end
    end
    
    return function() end
end

local function Iterator( aPrefix )
    local File = require( 'File' )
    local aDirectory = Directory( aPrefix )
    
    if aDirectory.exists then
        local anIterator = aDirectory( true )
        
        return function()
            local aFile = anIterator()
            
            while aFile and not aFile.name:find( '^data%.txt;%d+$' ) do
                aFile = anIterator()
            end
            
            if aFile and aFile.name:find( '^data%.txt;%d+$' ) then
                local aName = aFile.path:sub( 1, aFile.path:len() - aFile.name:len() - 1 )
                local aName = File( aName ).name
                
                return aName
            end
        end
    end
    
    return function() end
end

--------------------------------------------------------------------------------
-- Metamethods
--------------------------------------------------------------------------------

function meta:__call( aPrefix )        
    return PrefixIterator( aPrefix )
end

function meta:__index( aKey )
    if aKey == 'creation' then
        return Directory().modification
    end
    
    return Iterator( aKey )
end

function meta:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function meta:__tostring()
    return ( '%s/%s' ):format( self._NAME, self._VERSION )
end
