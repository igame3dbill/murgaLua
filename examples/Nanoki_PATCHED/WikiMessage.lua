--------------------------------------------------------------------------------
-- Title:               WikiMessage.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- import dependencies
local Template = require( 'Template' )
local WikiService = require( 'WikiService' )

local Capitalize = WikiService.Capitalize
local Encode = WikiService.Encode

local getmetatable = getmetatable
local setmetatable = setmetatable
local tostring = tostring

--------------------------------------------------------------------------------
-- WikiMessage
--------------------------------------------------------------------------------

module( 'WikiMessage' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

local types = { info = 'info', warning = 'warning', error = 'error' }
local tags = { info = 'span', warning = 'em', error = 'strong' }

function meta:__call( aText, aType )
    local aMessage = { text = tostring( aText ), type = types[ tostring( aType ) ] or 'info' }

    setmetatable( aMessage, self )
    
    return aMessage
end

function self:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function self:__tostring()
    local aTemplate = Template[ 'WikiMessage.txt' ]
    
    aTemplate[ 'title' ] = Encode( Capitalize( self.type ) .. ':' )
    aTemplate[ 'type' ] = self.type
    aTemplate[ 'tag' ] = tags[ self.type ]
    aTemplate[ 'text' ] = Encode( self.text )
    
    return tostring( aTemplate )
end
