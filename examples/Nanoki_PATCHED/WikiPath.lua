--------------------------------------------------------------------------------
-- Title:               WikiPath.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- import dependencies
local Template = require( 'Template' )
local string = require( 'string' )

local getmetatable = getmetatable
local rawset = rawset
local select = select
local setmetatable = setmetatable
local tostring = tostring

--------------------------------------------------------------------------------
-- WikiPath
--------------------------------------------------------------------------------

module( 'WikiPath' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

local function Encode( aValue )
    local anEncoder = function( aValue ) 
        return ( '&#%02d;' ):format( aValue:byte() ) 
    end
    
    return ( tostring( aValue or '' ):gsub( '([<>&\'"])', anEncoder ) )
end

local function AddComponent( aList, aComponent )
    local aPrevious = aList[ #aList ] or {}
    
    if tostring( aPrevious.href ) ~= tostring( aComponent.href ) then
        rawset( aList, #aList + 1, aComponent )
    end 
end

--------------------------------------------------------------------------------
-- Metamethods
--------------------------------------------------------------------------------

function meta:__call( ... )
    local aPath = {}
    
    aPath[ #aPath + 1 ] = { href = '/main', title = 'Main' }
    
    for anIndex = 1, select( '#', ... ) do
        AddComponent( aPath, select( anIndex, ... ) )
    end

    setmetatable( aPath, self )
    
    return aPath
end

function self:__newindex( aKey, aValue )
    AddComponent( self, aValue )
end

function self:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function self:__tostring()
    if #self > 1 then
        local aTemplate = Template[ 'WikiPath.txt' ]
        local aComponentTemplate = aTemplate[ 'components' ]
        local aTitle = nil
        
        aTemplate[ 'components' ] = nil
        
        for anIndex = 1, #self - 1 do
            local aComponent = self[ anIndex ]
            local aComponentTemplate = aTemplate[ 'components' ]
            
            aComponentTemplate[ 'href' ] = aComponent.href
            aComponentTemplate[ 'title' ] = Encode( aComponent.title )
            aTemplate[ 'components' ] = aComponentTemplate 
        end
        
        aTemplate[ 'title' ] = Encode( self[ #self ].title )
        
        return tostring( aTemplate )
    end
    
    return '&nbsp;'
end
