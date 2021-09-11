--------------------------------------------------------------------------------
-- Title:               Template.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- import dependencies
local io = require( 'io' )
local table = require( 'table' )

local assert = assert
local getmetatable = getmetatable
local pairs = pairs
local require = require
local setmetatable = setmetatable
local tostring = tostring

--------------------------------------------------------------------------------
-- Template
--------------------------------------------------------------------------------

module( 'Template' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

local contents = setmetatable( {}, { __mode = 'k' } )
local templates = setmetatable( {}, { __mode = 'k' } )
local variables = setmetatable( {}, { __mode = 'k' } )

local function SetContent( self, aContent )
    contents[ self ] = tostring( aContent )
end

local function GetContent( self )
    return contents[ self ]
end

local function GetTemplates( self )
    local someTemplates = templates[ self ]
    
    if not someTemplates then
        someTemplates = {}
        templates[ self ] = someTemplates
    end
    
    return someTemplates
end

local function GetVariables( self )
    local someVariables = variables[ self ]
    
    if not someVariables then
        someVariables = {}
        variables[ self ] = someVariables
    end
    
    return someVariables
end

function meta:__call( aContent )
    local aTemplate = {}

    setmetatable( aTemplate, self )
    
    SetContent( aTemplate, aContent )

    return aTemplate
end

function meta:__index( aKey )
    local aFile = assert( io.open( aKey, 'rb' ) )
    local aContent = aFile:read( '*a' )
    
    aFile:close()
    
    return self( aContent )
end

function self:__index( aKey )
    local Template = require( 'Template' )
    local someTemplates = GetTemplates( self )
    local aTemplate = someTemplates[ aKey ]
    
    if not aTemplate then
        local aContent = GetContent( self )
        local anOpenStart, anOpenEnd = aContent:find( '[t:' .. aKey .. ']', 1, true )
        local aCloseStart, aCloseEnd = aContent:find( '[/t:' .. aKey .. ']', anOpenEnd, true )
                
        aTemplate = Template( aContent:sub( anOpenEnd + 1, aCloseStart - 1 ) )
        someTemplates[ aKey ] = aTemplate
        
        aContent = aContent:sub( 1, anOpenStart - 1 ) .. '[v:' .. aKey .. ']' .. aContent:sub( aCloseEnd + 1 )
        SetContent( self, aContent )
    end
    
    return Template( GetContent( aTemplate ) )
end

function self:__newindex( aKey, aValue )
    local someVariables = GetVariables( self )
    local aBuffer = someVariables[ aKey ]
    
    if not aBuffer then
        aBuffer = {}
        someVariables[ aKey ] = aBuffer
    end
        
    aBuffer[ #aBuffer + 1 ] = tostring( aValue or '' )
end

function self:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function self:__tostring()
    local aContent = GetContent( self )
    local someVariables = GetVariables( self )
    local aTable = {}
    
    for aKey, aBuffer in pairs( someVariables ) do
        aKey = ( '[v:%s]' ):format( aKey )
        aTable[ aKey ] = table.concat( aBuffer, '' )
    end
    
    aContent = aContent:gsub( '(%[v%:%w-%])', aTable )
    
    return aContent
end

