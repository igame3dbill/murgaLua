--------------------------------------------------------------------------------
-- Title:               TCPServer.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- import dependencies
local debug = require( 'debug' )
local io = require( 'io' )
local os = require( 'os' )
local socket = require( 'socket' )
local table = require( 'table' )

local assert = assert
local getfenv = getfenv
local getmetatable = getmetatable
local select = select
local setfenv = setfenv
local setmetatable = setmetatable
local tostring = tostring
local unpack = unpack
local xpcall = xpcall

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

local getenv = os.getenv

function os.getenv( aVariable )
    local anEnvironment = assert( getfenv() )
    
    return getenv( aVariable ) or anEnvironment[ aVariable ]
end

--------------------------------------------------------------------------------
-- TCPServer
--------------------------------------------------------------------------------

module( 'TCPServer' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

function Server( anAddress, aPort, aBacklog )
    local aServer = assert( socket.tcp() )
    
    assert( aServer:setoption( 'keepalive', true ) )
    assert( aServer:setoption( 'linger', { on = false, timeout = 0 } ) )
    assert( aServer:setoption( 'reuseaddr', true ) )
    assert( aServer:setoption( 'tcp-nodelay', true ) )
    assert( aServer:settimeout( nil ) )
    assert( aServer:bind( anAddress, aPort ) )
    assert( aServer:listen( aBacklog ) )

    return aServer
end

function ServerEnvironment( aServer )
    local anEnvironment = { PROTO = 'TCP' }
    local anAddress, aPort = assert( aServer:getsockname() )
    local aHost = socket.dns.tohostname( anAddress )
        
    anEnvironment[ 'TCPLOCALIP' ] = anAddress
    anEnvironment[ 'TCPLOCALPORT' ] = aPort
    anEnvironment[ 'TCPLOCALHOST' ] = aHost
    
    return anEnvironment
end

function meta:__call( anAddress, aPort, aBacklog )
    local aServer = Server( anAddress, aPort, aBacklog )
    local anEnvironment = ServerEnvironment( aServer )
    local aTCPServer = { server = aServer, environment =  anEnvironment }
    
    setmetatable( aTCPServer, self )
    self.__index = self    
    
    return aTCPServer
end

function meta:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function meta:__tostring()
    return _NAME
end

local function ClientEnvironment( aClient, anEnvironment )
    local anAddress, aPort = assert( aClient:getpeername() )
    local aHost = socket.dns.tohostname( anAddress )

    anEnvironment[ 'TCPREMOTEIP' ] = anAddress
    anEnvironment[ 'TCPREMOTEPORT' ] = aPort
    anEnvironment[ 'TCPREMOTEHOST' ] = aHost
    
    return anEnvironment
end

local function Call( aTCPServer, aHandler )
    return function()
        local aServer = aTCPServer.server
        local aClient = assert( aServer:accept() )
        local anEnvironment = ClientEnvironment( aClient, aTCPServer.environment )

        aTCPServer.client = aClient
        assert( aClient:setoption( 'linger', { on = false, timeout = 0 } ) )
        assert( aClient:setoption( 'tcp-nodelay', true ) )
        assert( aClient:settimeout( nil ) )
        setfenv( os.getenv, anEnvironment )
        
        aHandler( aTCPServer, aTCPServer )

        aClient:close()
        
        return true
    end
end

function self:__call( aHandler )
    local aCall = Call( self, aHandler )
    local aStatus, aResult = xpcall( aCall, debug.traceback )
    
    if not aStatus then
        io.stderr:write( aResult )
        io.stderr:flush()
    end
    
    return self( aHandler )
end

function self:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function self:__tostring()
    local anEnvironment = self.environment
    local aHost = anEnvironment[ 'TCPLOCALHOST' ] or anEnvironment[ 'TCPLOCALIP' ]
    local aPort = anEnvironment[ 'TCPLOCALPORT' ]
    
    return ( '%s:%s' ):format( tostring( aHost ), tostring( aPort ) )
end

function self:close()
    -- no op
end

function self:read( aPattern, ... )
    local aClient = self.client
    local aBuffer = {}
    
    aBuffer[ #aBuffer + 1 ] = assert( aClient:receive( aPattern ) )

    for anIndex = 1, select( '#', ... ) do
        aBuffer[ #aBuffer + 1 ] = aClient:receive( select( anIndex, ... ) )
    end
    
    return unpack( aBuffer )
end

function self:lines()
    local aClient = self.client
    
    return function()
        return aClient:receive()
    end
end

function self:write( ... )
    local aClient = self.client
    local aBuffer = {}
    
    for anIndex = 1, select( '#', ... ) do
        aBuffer[ #aBuffer + 1 ] = tostring( select( anIndex, ... ) )
    end

    return aClient:send( table.concat( aBuffer ) )
end

function self:flush()
    -- no op
end


