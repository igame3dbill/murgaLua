--------------------------------------------------------------------------------
-- Title:               File.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- import dependencies
local io = require( 'io' )
local lfs = require( 'lfs' )
local os = require( 'os' )
local table = require( 'table' )

local assert = assert
local getmetatable = getmetatable
local package = package
local pairs = pairs
local require = require
local setmetatable = setmetatable
local tostring = tostring

--------------------------------------------------------------------------------
-- File
--------------------------------------------------------------------------------

module( 'File' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

self.separator = package.path:match( '(%p)%?%.' ) or '/'

local function Reader( aPath )
    return assert( io.open( aPath, 'rb' ) )
end

local function Writer( aPath )
    return assert( io.open( aPath, 'wb' ) )
end

local function ReadContent( aPath )
    local aReader = Reader( aPath )
    local aContent = aReader:read( '*a' )
    
    aReader:close()
        
    return aContent
end

local function WriteContent( aPath, aContent )
    local aWriter = Writer( aPath )
    
    aWriter:write( aContent )
    aWriter:close()
end

local function Exists( aPath )
    if lfs.attributes( aPath, 'size' ) then
        return true
    end
    
    return false
end

local function Name( aPath )
    local anIndex = aPath:reverse():find( self.separator, 1, true )
    
    if anIndex == 1 then
        return Name( aPath:sub( 1, aPath:len() - 1 ) )
    end
    
    if anIndex then
        return aPath:sub( aPath:len() - anIndex + 2 )
    end
    
    return aPath
end

local function Extension( aPath )
    local aName = Name( aPath )
    
    if aName then
        local anIndex = aName:reverse():find( '.', 1, true )
        
        if anIndex then
            return aName:sub( aName:len() - anIndex + 2 )
        end
    end
end

function meta:__call( ... )
    local aPath = table.concat( { ... }, self.separator )
    local aFile = { path = aPath }
    
    if aPath == '' then
        aFile.path = lfs.currentdir()
    end

    setmetatable( aFile, self )
    
    return aFile
end

function self:__call( isDeep )
    local File = require( 'File' )
    local aPath = self.path
    local anIterator = lfs.dir( aPath )
    local somePaths = nil
    local aPathIterator = nil
    
    aPathIterator = function()
        local aName = anIterator()

        while aName and ( aName == '.' or aName == '..' ) do
            aName = anIterator()
        end

        if aName then
            local aFile = File( aPath, aName )
            
            if isDeep == true and aFile.mode == 'directory' then
                somePaths = somePaths or {}
                somePaths[ #somePaths + 1 ] = aFile.path
            end
            
            return aFile
        end
        
        if isDeep and somePaths and #somePaths > 0 then
            aPath = table.remove( somePaths )
            anIterator = lfs.dir( aPath )
            
            return aPathIterator()
        end
    end
    
    return aPathIterator
end

function self:__index( aKey )
    if aKey == 'content' then
        return ReadContent( self.path )
    elseif aKey == 'exists' then
        return Exists( self.path )
    elseif aKey == 'extension' then
        return Extension( self.path )
    elseif aKey == 'name' then
        return Name( self.path )
    elseif aKey == 'reader' then
        return Reader( self.path )
    elseif aKey == 'writer' then
        return Writer( self.path )
    end
    
    return lfs.attributes( self.path, aKey )
end

function self:__newindex( aKey, aValue )
    if aKey == 'content' then
        WriteContent( self.path, aValue )
    elseif aKey == 'delete' and aValue == true then
        assert( os.remove( self.path ) )
    elseif aKey == 'modification' then
        assert( lfs.touch( self.path, aValue ) )
    end
end

function self:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function self:__eq( aValue )
    return tostring( self ) == tostring( aValue )
end

function self:__lt( aValue )
    return tostring( self ) < tostring( aValue )
end

function self:__tostring()
    return tostring( self.path )
end


