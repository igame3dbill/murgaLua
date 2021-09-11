--------------------------------------------------------------------------------
-- Title:               URL.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- Based on Diego Nehab's URL:
-- http://www.cs.princeton.edu/~diego/professional/luasocket/url.html

-- import dependencies
local string = require( 'string' )
local table = require( 'table' )

local getmetatable = getmetatable
local ipairs = ipairs
local module = module
local next = next
local pairs = pairs
local require = require
local setmetatable = setmetatable
local tonumber = tonumber
local tostring = tostring
local type = type

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

local function Decode( aValue )
    local aDecoder = function( aValue ) 
        return string.char( tonumber( aValue, 16 ) ) 
    end

    return ( aValue:gsub( '%%(%x%x)', aDecoder ) )
end

local function Encode( aValue )
    local anEncoder = function( aValue )
        return string.format( '%%%02x', string.byte( aValue ) )
    end
    
    return ( aValue:gsub( '([^A-Za-z0-9_])', anEncoder ) )
end

--------------------------------------------------------------------------------
-- URLPath
--------------------------------------------------------------------------------

module( 'URLPath' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

local function ReadPath( aValue )
    local aPath = {}
    local aReader = function( aValue )
        aPath[ #aPath + 1 ] = Decode( aValue ) 
    end

    aValue:gsub( '([^/]+)', aReader )
    
    aPath.absolute = aValue:sub( 1, 1 ) == '/' 
    aPath.directory = aValue:sub( -1, -1 ) == '/' 

    return aPath
end

local PathValue = { [ '-' ] = true, [ '_' ] = true, [ '.' ] = true, [ '!' ] = true, [ '~' ] = true, [ '*' ] = true , [ '\'' ] = true, ['(' ] = true, [ ')' ] = true, [ ':' ] = true, [ '@' ] = true, [ '&' ] = true, [ '=' ] = true, [ '+' ] = true, [ '$' ] = true, [ ',' ] = true }

local function EncodePath( aValue )
    local anEncoder = function ( aValue )
        if PathValue[ aValue ] then 
          return aValue
        end
        
        return Encode( aValue )
    end

    return ( aValue:gsub( '([^A-Za-z0-9_])', anEncoder ) )
end

local function WritePath( aValue )
    local aBuffer = {}
    
    if aValue.absolute then
        aBuffer[ #aBuffer + 1 ] = ''
    end

    for anIndex, aValue in ipairs( aValue ) do
        aBuffer[ #aBuffer + 1 ] = EncodePath( aValue )
    end
    
    if aValue.directory then
        aBuffer[ #aBuffer + 1 ] = ''
    end
    
    return table.concat( aBuffer, '/' )
end

local function NewPath( aValue )
    local aPath = ReadPath( tostring( aValue or '' ) )
    
    setmetatable( aPath, self )
    
    return aPath
end

local function AddPath( aBase, aRelative )
    local aPath = aRelative
    
    if not aPath.absolute then
        local aNormalizer = function( aValue ) 
            if aValue == './' then 
                return '' 
            end 
            
            return aValue
        end
        local aNormalizedPath = nil

        aPath = tostring( aBase ):gsub( '[^/]*$', '' )
        aPath = aPath .. aRelative  
        aPath = aPath:gsub( '([^/]*%./)', aNormalizer )
        aPath = aPath:gsub( '/%.$', '/' )

        aNormalizer = function( aValue )
            if aValue == '../../' then 
                return aValue
            end
            
            return '' 
        end
        
        while aNormalizedPath ~= aPath do
            aNormalizedPath = aPath
            aPath = aNormalizedPath:gsub( '([^/]*/%.%./)', aNormalizer )
        end

        aNormalizer = function( aValue )
            if aValue == '../..' then 
                return aValue
            end
            
            return ''
        end
        
        aPath = aPath:gsub( '([^/]*/%.%.)$', aNormalizer )
        aPath = NewPath( aPath )
    end
    
    return aPath
end

function meta:__call( aValue )
    return NewPath( aValue )
end

function self:__call( aValue )
    local aPath = NewPath( self )
    
    if aValue then
        aPath[ #aPath + 1 ] = tostring( aValue )
    else
        aPath[ #aPath ] = nil
    end

    return aPath
end

function self:__add( aValue )
    return AddPath( self(), NewPath( aValue ) )
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
    return WritePath( self )
end

--------------------------------------------------------------------------------
-- URLParameter
--------------------------------------------------------------------------------

module( 'URLParameter' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

local function ReadParameter( aValue )
    local aParameter = {}

    for aKey, aValue in aValue:gmatch( '([^&=]+)=([^&=]+)' ) do
        aKey = Decode( aKey:gsub( '+', ' ' ) )
        aValue = Decode( aValue:gsub( '+', ' ' ) )
        
        aParameter[ aKey:lower() ] = aValue
    end
    
    return aParameter
end

local function WriteParameter( aValue )
    local aBuffer = {}
    
    if next( aValue ) then
        for aKey, aValue in pairs( aValue ) do
            aBuffer[ #aBuffer + 1 ] = Encode( aKey:lower() ):gsub( '%%20', '+' )
            aBuffer[ #aBuffer + 1 ] = '='
            aBuffer[ #aBuffer + 1 ] = Encode( aValue ):gsub( '%%20', '+' )
            aBuffer[ #aBuffer + 1 ] = '&'
        end
        
        table.remove( aBuffer )
    end

    return table.concat( aBuffer )
end

local function NewParameter( aValue )
    local aParameter = ReadParameter( tostring( aValue or '' ) )
    
    setmetatable( aParameter, self )
    
    return aParameter
end

function meta:__call( aValue )
    return NewParameter( aValue )
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
    return WriteParameter( self )
end

--------------------------------------------------------------------------------
-- URL
--------------------------------------------------------------------------------

module( 'URL' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

local function ReadURL( aURL )
    local URLParameter = require( 'URLParameter' )
    local URLPath = require( 'URLPath' )
    local someComponents = {}
    
    -- fragment
    aURL = aURL:gsub( '#(.*)$', function( aValue ) someComponents.fragment = aValue return '' end )
    
    -- scheme
    aURL = aURL:gsub( '^([%w][%w%+%-%.]*)%:', function( aValue ) someComponents.scheme = aValue:lower() return '' end )
    
    -- authority
    aURL = aURL:gsub( '^//([^/]*)', function( aValue ) someComponents.authority = aValue return '' end )
    
    -- query
    aURL = aURL:gsub( '%?(.*)', function( aValue ) someComponents.query = aValue return '' end )
    someComponents.query = URLParameter( someComponents.query )
    
    -- parameter
    aURL = aURL:gsub( '%;(.*)', function( aValue ) someComponents.parameter = aValue return '' end )
    someComponents.parameter = URLParameter( someComponents.parameter )
    
    -- path
    someComponents.path = URLPath( aURL )
    
    if someComponents.authority then
        local anAuthority = someComponents.authority
    
        -- user info
        anAuthority = anAuthority:gsub( '^([^@]*)@', function( aValue ) someComponents.userInfo = aValue return '' end )
    
        -- port
        anAuthority = anAuthority:gsub( ':([^:]*)$', function( aValue ) someComponents.port = tonumber( aValue ) return '' end )
    
        -- host
        if anAuthority ~= '' then 
            someComponents.host = anAuthority:lower()
        end
    
        if someComponents.userInfo then
            local anUserInfo = someComponents.userInfo
    
            -- password
            anUserInfo = anUserInfo:gsub( ':([^:]*)$', function( aValue ) someComponents.password = aValue return '' end )
    
            -- user
            someComponents.user = anUserInfo
        end
    end
    
    return someComponents
end

local function WriteURL( someComponents )
    local aURL = ''
    local aPath = someComponents.path
    local aParameter = someComponents.parameter
    local aQuery = someComponents.query
    local anAuthority = someComponents.authority
    local anHost = someComponents.host
    local aScheme = someComponents.scheme
    local aFragment = someComponents.fragment
    
    if aPath then
        aURL = aURL .. aPath
    end
    
    if aParameter  and next( aParameter ) then
        aURL = aURL .. ';' .. aParameter
    end
    
    if aQuery and next( aQuery ) then
        aURL = aURL .. '?' .. aQuery
    end
    
    if anHost then
        local aPort = someComponents.port
        local anUserInfo = someComponents.userInfo
        local anUser = someComponents.user
    
        anAuthority = anHost
        
        if aPort then
            anAuthority = anAuthority .. ':' .. aPort
        end
        
        if anUser then
            local aPassword = someComponents.password
            
            anUserInfo = anUser
            
            if aPassword then
                anUserInfo = anUserInfo .. ':' .. aPassword
            end
        end
    
        if anUserInfo then 
            anAuthority = anUserInfo .. '@' .. anAuthority 
        end
        
        if anAuthority then
            aURL = '//' .. anAuthority .. aURL
        end
    end
    
    if aScheme then
        aURL = aScheme .. ':' .. aURL
    end
    
    if aFragment then
        aURL = aURL .. '#' .. aFragment
    end
    
    return aURL
end

local function NewURL( aValue )
    local aURL = ReadURL( tostring( aValue or '' ) )
    
    setmetatable( aURL, self )
    
    return aURL
end

local function AddURL( aBase, aRelative )
    if not aRelative.scheme then
        aRelative.scheme = aBase.scheme
        
        if not aRelative.authority then
            aRelative.authority = aBase.authority
            aRelative.userInfo = aBase.userInfo
            aRelative.user = aBase.user
            aRelative.password = aBase.password
            aRelative.host = aBase.host
            aRelative.port = aBase.port
            
            if tostring( aRelative.path ):len() == 0 then
                aRelative.path = aBase.path
                
                if tostring( aRelative.parameter ):len() == 0 then
                    aRelative.parameter = aBase.parameter
                    
                    if tostring( aRelative.query ):len() == 0 then
                        aRelative.query = aBase.query
                    end
                end
            else    
                aRelative.path = aBase.path + aRelative.path
            end
        end
    end
    
    return aRelative
end

function meta:__call( aValue )
    return NewURL( aValue )
end

function self:__add( aValue )
    return AddURL( self, NewURL( aValue ) )
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
    return WriteURL( self )
end

