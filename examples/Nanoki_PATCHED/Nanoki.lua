--------------------------------------------------------------------------------
-- Title:               Nanoki.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

package.cpath = package.cpath .. ';lib/?.so'
os.setlocale( 'en_US.US-ASCII', 'all' )

-- import dependencies
local io = require( 'io' )
local os = require( 'os' )
local table = require( 'table' )

local assert = assert
local error = error
local getfenv = getfenv
local getmetatable = getmetatable
local require = require
local select = select
local setfenv = setfenv
local setmetatable = setmetatable
local tonumber = tonumber
local tostring = tostring

local _G = _G

--------------------------------------------------------------------------------
-- Nanoki
--------------------------------------------------------------------------------

module( 'Nanoki' )
_VERSION = '1.03'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

local function Log( ... )
    local aWriter = io.stderr
    local aBuffer = { os.date( '!%Y-%m-%d %H:%M:%S', os.time() ) }

    for anIndex = 1, select( '#', ... ) do
        aBuffer[ #aBuffer + 1 ] = tostring( select( anIndex, ... ) )
    end

    aWriter:write( table.concat( aBuffer, ' ' ), '\n' )
    aWriter:flush()
end

local function Environment( aFunction, aKey, aValue )
    local anEnvironment = getfenv( assert( aFunction, 'invalid function' ) )
    
    if not anEnvironment or anEnvironment == _G then
        anEnvironment = {}
        setfenv( aFunction, anEnvironment )
    end
    
    if aKey then
        anEnvironment[ aKey ] = aValue
    end
    
    return anEnvironment
end

local function Location( ... )
    local aLocation = select( 1, ... ) or '.'

    Log( 'Location', '\t', aLocation )
    
    return aLocation
end

local function Server( ... )
    local anAddress = select( 2, ... )   
    local aPort = tonumber( select( 3, ... ) or nil )
    
    if anAddress and not aPort then
        error( 'Missing port number for address \'' .. anAddress .. '\'' )
    end
    
    if anAddress and aPort then
        local TCPServer = require( 'TCPServer' )
        local aServer = TCPServer( anAddress, aPort )

        Log( 'Server', '\t', 'tcp', anAddress, aPort )

        return aServer
    end

    Log( 'Server', '\t', 'io', 'stdin' )
end

local function Forwarded( ... )
    local isForwarded = select( 4, ... ) == 'forwarded'

    Log( 'Forwarded', '\t', isForwarded )

    return isForwarded
end

local function Secure( ... )
    local isSecure = select( 5, ... ) == 'secure'

    Log( 'Secure', '\t', isSecure )

    return isSecure
end

local function ConnectionFilter( aRequest, aResponse )
    aResponse.header[ 'connection' ] = 'close'
end

local function ServerFilter( aRequest, aResponse )
    aResponse.header[ 'server' ] = tostring( self )
end

--------------------------------------------------------------------------------
-- Metamethods
--------------------------------------------------------------------------------

function meta:__call( ... )
    local HTTP = require( 'HTTP' )
    local HTTPExtra = require( 'HTTPExtra' )
    local HTTPFile = require( 'HTTPFile' )
    local HTTPRequest = require( 'HTTPRequest' )
    local HTTPResponse = require( 'HTTPResponse' )
    local HTTPService = require( 'HTTPService' )
    local Wiki = require( 'Wiki' )
          Wiki.location = Location( ... )
    local WikiAbout = require( 'WikiAbout' )
    local WikiContentService = require( 'WikiContentService' )
    local WikiDateService = require( 'WikiDateService' )
    local WikiIndexService = require( 'WikiIndexService' )
    local WikiRecentService = require( 'WikiRecentService' )
    local WikiSearchService = require( 'WikiSearchService' )
    local aServer = Server( ... )
    local aService = nil
    
    HTTP[ '/a' ] = WikiAbout()
    HTTP[ '/etc/(.+)' ] = HTTPFile( 'etc/' )
    
    HTTPResponse.filter[ #HTTPResponse.filter + 1 ] = ServerFilter
    Environment( HTTPRequest.AddressFilter, 'forwarded', Forwarded( ... ) )
    HTTPRequest.secure = Secure( ... )
    
    aService = HTTPService( '/date', WikiDateService )
    HTTP[ aService.pattern ] = aService()
    
    aService = HTTPService( '/index', WikiIndexService )
    HTTP[ aService.pattern ] = aService()
    
    aService = HTTPService( '/recent', WikiRecentService )
    HTTP[ aService.pattern ] = aService()
    
    aService = HTTPService( '/search', WikiSearchService )
    HTTP[ aService.pattern ] = aService()
    
    aService = HTTPService( '/', WikiContentService )
    HTTP[ aService.pattern ] = aService()
    
    if aServer then
        HTTPResponse.filter[ #HTTPResponse.filter + 1 ] = ConnectionFilter
        
        aServer( HTTP )
    else
        HTTP()
    end
end

function meta:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function meta:__tostring()
    return ( '%s/%s' ):format( self._NAME, self._VERSION )
end

--------------------------------------------------------------------------------
-- Main
--------------------------------------------------------------------------------

Log( 'Version', '\t', self )

self( ... )
