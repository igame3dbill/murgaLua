--------------------------------------------------------------------------------
-- Title:               Trie.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- import dependencies
local File = require( 'File' )
local lfs = require( 'lfs' )
local string = require( 'string' )

local getmetatable = getmetatable
local setmetatable = setmetatable
local tostring = tostring

--------------------------------------------------------------------------------
-- Trie
--------------------------------------------------------------------------------

module( 'Trie' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

local paths = setmetatable( {}, { __mode = 'k' } )

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

local function SetPath( self, aPath )
    paths[ self ] = tostring( aPath )
end

local function GetPath( self )
    return paths[ self ]
end

local function Key( aKey )
    return tostring( aKey ):lower():gsub( '%W', '' ):sub( 1, 9 )
end

local function KeyPath( self, aKey, shouldMake )
    local aKey = Key( aKey )
    
    if aKey:len() > 1 then
        local aPath = GetPath( self )
        
        if shouldMake == nil then
            shouldMake = true
        end
    
        if shouldMake then
            lfs.mkdir( aPath )
        end
        
        for anIndex = 1, aKey:len() do
            local aChar = string.char( aKey:byte( anIndex ) )
            
            aPath = aPath .. File.separator .. aChar
            
            if shouldMake then
                lfs.mkdir( aPath )
            end
        end
        
        return aPath
    end
end

--------------------------------------------------------------------------------
-- Metamethods
--------------------------------------------------------------------------------

function meta:__call( aPath )
    local aTrie = {}

    setmetatable( aTrie, self )
    SetPath( aTrie, aPath or '.' )
    
    return aTrie
end

function meta:__index( aKey )
    return Key( aKey )
end

function self:__call()
    local aPath = GetPath( self )
    local aDirectory = File( aPath )
    
    if aDirectory.exists then
        local anIterator = aDirectory( true )
        
        return function()
            local aFile = anIterator()
            
            while aFile and aFile.extension ~= 'id' do
                aFile = anIterator()
            end
            
            if aFile and aFile.extension == 'id' then
                local aKey = aFile.path:sub( aPath:len() + 1, aFile.path:len() - aFile.name:len() ):gsub( File.separator, '' )
                local aValue = aFile.name:sub( 1, aFile.name:len() - aFile.extension:len() - 1 )
                
                return aKey, aValue
            end
        end
    end
    
    return function() end
end

function self:__newindex( aKey, aValue )
    local aPath = KeyPath( self, aKey )
    
    if aPath then
        local anID = File( aPath, aValue .. '.id' )
        
        lfs.mkdir( anID.path )
    end
end

function self:__index( aKey )
    local aPath = KeyPath( self, aKey, false )
    
    if aPath then
        local aDirectory = File( aPath )
        
        if aDirectory.exists then
            local anIterator = aDirectory( true )
            
            return function()
                local aFile = anIterator()
                
                while aFile and aFile.extension ~= 'id' do
                    aFile = anIterator()
                end
                
                if aFile and aFile.extension == 'id' then
                    local anID = aFile.name:sub( 1, aFile.name:len() - aFile.extension:len() - 1 )
                    
                    return anID
                end
            end
        end
    end
    
    return function() end
end
