--------------------------------------------------------------------------------
-- Title:               Wiki.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- import dependencies
local table = require( 'table' )

local assert = assert
local error = error
local getmetatable = getmetatable
local require = require
local setmetatable = setmetatable
local type = type

--------------------------------------------------------------------------------
-- Wiki
--------------------------------------------------------------------------------

module( 'Wiki' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

self.location = '.'

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

function Location()
    return self.location or '.'
end

function NameIterator( aDirectory, isDeep )
    if aDirectory.exists then
        local anIterator = aDirectory( isDeep )
        
        return function()
            local aFile = anIterator()
            
            while aFile and aFile.extension ~= 'id' do
                aFile = anIterator()
            end
            
            if aFile and aFile.extension == 'id' then
                local aName = aFile.name:sub( 1, aFile.name:len() - aFile.extension:len() - 1 )
                
                return aName, aFile
            end
        end
    end
        
    return function() end
end

local function FileComparator( aFile, anotherFile )
    local aModification = aFile.modification
    local anotherModification = anotherFile.modification
    
    if aModification == anotherModification then
        return aFile.name > anotherFile.name
    end
    
    return aModification > anotherModification
end

function PurgeDirectory( aDirectory, aLimit )
    local aLimit = aLimit or 100
    local aList = {}
    
    for aName, aFile in NameIterator( aDirectory ) do
        aList[ #aList + 1 ] = aFile
    end
    
    if #aList > aLimit then
        table.sort( aList, FileComparator )
        
        for anIndex = aLimit + 1, #aList do
            local aFile = aList[ anIndex ]
            
            aFile.delete = true
        end
    end
end

local function Copy( aName, aNewName )
    local WikiContent = require( 'WikiContent' )
    local lfs = require( 'lfs' )
    local aContent = WikiContent( aName )
    local aLock = aContent.lock
    local aNewContent = WikiContent( aNewName )
    
    if not aContent.exists then
        error( ( '%q doesn\'t exist' ):format( aName ) )
    elseif aNewContent.exists then
        error( ( '%q already exists' ):format( aNewName ) )
    elseif aName == aNewName then
        error( ( '%q same as %q' ):format( aName, aNewName ) )
    elseif aLock and lfs.lock( aLock, 'w' ) then
        local File = require( 'File' )
        local WikiDate = require( 'WikiDate' )
        local WikiSearch = require( 'WikiSearch' )
        local WikiRecent = require( 'WikiRecent' )
        local aNewDirectory = aNewContent().directory
        
        for aVersion, aFile in aNewContent.versions do
            aFile.delete = true
        end
        
        for aFile in aContent.file do
            aNewContent.file = aFile
        end
        
        for aLink in aContent.link do
            aNewContent.link = aLink
        end
        
        for aVersion, aFile in aContent.versions do
            local aVersionFile = File( aNewDirectory.path, aFile.name )
            
            aVersionFile.content = aFile.content
            aVersionFile.modification = aFile.modification
        end

        WikiDate[ aNewContent.creation ] = aNewContent.name
        WikiRecent[ aNewContent.modification ] = aNewContent.name
        WikiSearch[ aNewContent.name ] = aNewContent.name

        lfs.unlock( aLock )
        aLock:close()
    
        return aNewContent
    end
    
    error( ( 'Failed to lock %q' ):format( aName ) )
end

local function DeleteDirectory( aDirectory )
    for aFile in aDirectory( false, true ) do
        if aFile.mode == 'file' then
            aFile.delete = true
        elseif aFile.mode == 'directory' then
            DeleteDirectory( aFile )
        end
    end
    
    aDirectory.delete = true
end

local function Delete( aName )
    local WikiContent = require( 'WikiContent' )
    local lfs = require( 'lfs' )
    local aContent = WikiContent( aName )
    local aLock = aContent.lock
    
    if not aContent.exists then
        error( ( '%q doesn\'t exist' ):format( aName ) )
    elseif aLock and lfs.lock( aLock, 'w' ) then
        local WikiDate = require( 'WikiDate' )
        local WikiSearch = require( 'WikiSearch' )
        local WikiRecent = require( 'WikiRecent' )

        WikiDate[ aContent.name ] = false
        WikiRecent[ aContent.name ] = false
        WikiSearch[ aContent.name ] = false

        DeleteDirectory( aContent.directory )

        lfs.unlock( aLock )
        aLock:close()
        
        return
    end
    
    error( ( 'Failed to lock %q' ):format( aName ) )
end

local function Move( aName, aNewName )
    Copy( aName, aNewName )
    Delete( aName )
end

--------------------------------------------------------------------------------
-- Metamethods
--------------------------------------------------------------------------------

function meta:__index( aKey )
    local WikiContent = require( 'WikiContent' )
    
    return WikiContent( aKey )
end

function meta:__newindex( aKey, aValue )
    if type( aKey ) == 'string' and type( aValue ) == 'string' then
        return Move( aKey, aValue )
    elseif type( aKey ) == 'string' and type( aValue ) == 'boolean' and aValue == false then
        return Delete( aKey )
    end
    
    error( ( 'Invalid parameters: %q = %q' ):format( tostring( aKey ), tostring( aValue ) ) )
end

function meta:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function meta:__tostring()
    return ( '%s/%s' ):format( self._NAME, self._VERSION )
end
