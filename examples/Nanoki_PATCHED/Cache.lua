--------------------------------------------------------------------------------
-- Title:               Cache.lua
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

local assert = assert
local getmetatable = getmetatable
local setmetatable = setmetatable

--------------------------------------------------------------------------------
-- Cache
--------------------------------------------------------------------------------

module( 'Cache' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

local function Read( aPath, aContent, aTime )
    local aReader = assert( io.open( aPath, 'rb' ) )
    
    if lfs.lock( aReader, 'r' ) then
        local aContent = aReader:read( '*a' )
        
        lfs.unlock( aReader )
        aReader:close()
        
        return aContent
    end
    
    aReader:close()
    
    return self( aPath, aContent, aTime ) 
end

local function Write( aPath, aContent, aTime )
    local aWriter = assert( io.open( aPath, 'wb' ) )
    
    if lfs.lock( aWriter, 'w' ) then
        local aContent = aContent()
        
        aWriter:write( aContent )
        aWriter:flush()
        lfs.unlock( aWriter )
        aWriter:close()
        
        return aContent
    end 
    
    aWriter:close()
    
    return self( aPath, aContent, aTime ) 
end

function meta:__call( aPath, aContent, aTime )
    local aModification = lfs.attributes( aPath, 'modification' )
    local aSize = lfs.attributes( aPath, 'size' )
    
    if aModification and aModification > aTime
    and aSize and aSize > 0 then
        return Read( aPath, aContent, aTime )
    end
    
    return Write( aPath, aContent, aTime )
end
