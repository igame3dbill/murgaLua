--------------------------------------------------------------------------------
-- Title:               HTTP.lua
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
local table = require( 'table' )

local getmetatable = getmetatable
local ipairs = ipairs
local module = module
local pairs = pairs
local rawset = rawset
local require = require
local select = select
local setmetatable = setmetatable
local tonumber = tonumber
local tostring = tostring
local type = type
local unpack = unpack
local xpcall = xpcall

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

local function Capitalize( aValue )
    return ( aValue:lower():gsub( '(%l)([%w_\']*)', function( first, second ) return first:upper() .. second end ) )
end

local function Trim( aValue )
    return ( aValue:gsub( '^[%c%s]+', '' ):gsub( '[%s%c]+$', '' ) )
end

--------------------------------------------------------------------------------
-- HTTPRequest
--------------------------------------------------------------------------------

module( 'HTTPRequest' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

function RequestFilter( aRequest, aResponse )
    local aStatus = aRequest.status

    if not aStatus
    or not aStatus.method
    or not aStatus.uri
    or not aStatus.version
    or aStatus.method:len() == 0
    or aStatus.uri:len() == 0
    or aStatus.version:len() == 0
    or aStatus.method ~= aStatus.method:upper()
    or not aStatus.version:find( '^HTTP/%d%.%d$' )
    or not aRequest.header[ 'host' ] then
        aResponse.status.code = 400
        aResponse.status.description = 'Bad Request'
        aResponse.content = ( '%d %s' ):format( aResponse.status.code, aResponse.status.description )
        aResponse.header[ 'connection' ] = 'close'
        aResponse.header[ 'content-length' ] = aResponse.content:len()
        aResponse.header[ 'content-type' ] = 'text/plain'
    
        return false
    end
end

self.filter = { RequestFilter }

local function ReadStatus( aReader )
    local aLine = Trim( aReader:read() or '' )
    local aMethod, aURI, aVersion = aLine:match( '(%S+)%s(%S+)%s(%S+)' )
    local aStatus = { method = aMethod or '', uri = aURI or '', version = aVersion or '' }
    
    return aStatus
end

local function ReadHeader( aReader )
    local aHeader = {}
    
    for aLine in aReader:lines() do
        local aKey, aValue = Trim( aLine ):match( '(%S-): (.*)' )
    
        if aKey then
            local aKey = Trim( aKey ):lower()
            local aPreviousValue = aHeader[ aKey ]
            
            aValue = Trim( aValue )
            
            if aPreviousValue then
                aValue = aPreviousValue .. ',' .. aValue
            end
    
            aHeader[ aKey ] = aValue
        else
            break
        end
    end
    
    return aHeader
end

local function ReadChunkedContent( aReader )
    local aBuffer = {}
    local aLine = aReader:read()
    local aSize = tonumber( aLine, 16 )
    
    while aSize and aSize > 0 do
        aBuffer[ #aBuffer + 1 ] = aReader:read( aSize )
        aReader:read()
    
        aLine = aReader:read()
        aSize = tonumber( aLine, 16 )
    end
    
    aLine = aReader:read()
    
    while aLine and aLine ~= '' do
        aLine = aReader:read()
    end
    
    return table.concat( aBuffer )
end

local function ReadContent( aReader, aHeader )
    local anEncoding = aHeader[ 'transfer-encoding' ] or ''
    local aLength = tonumber( aHeader[ 'content-length' ] ) or 0
    
    if anEncoding:find( 'chunked', 1, true ) then
        return ReadChunkedContent( aReader )
    end
    
    if aLength > 0 then
        return aReader:read( aLength )
    end
    
    return nil
end

local function LocalAddress()
    local HTTP = require( 'HTTP' )
    local anAddress = HTTP.address
    local aPort = HTTP.port
    
    if aPort and aPort ~= 80 then
        anAddress = ( '%s:%d' ):format( anAddress, aPort )
    end
    
    return anAddress
end

local function GetURL( aRequest )
    local URL = require( 'URL' )
    local aURL = URL( aRequest.status.uri or '/' )

    aURL.path.absolute = true
    
    if not aURL.host then
        aURL.host = aRequest.header[ 'host' ]
        aURL = URL( aURL )
    end

    if not aURL.scheme then
        local HTTPRequest = require( 'HTTPRequest' )
        local isSecure = HTTPRequest.secure
        
        aURL.scheme = 'http'
        
        if isSecure or tostring( aURL.port ):find( '443$' ) then
            aURL.scheme = aURL.scheme .. 's'
        end
    end
    
    return aURL
end

local function GetParameter( aRequest )
    local aParameter = {}
    local aType = aRequest.header[ 'content-type' ] or ''
    
    for aKey, aValue in pairs( aRequest.url.query ) do
        aParameter[ aKey ] = aValue
    end
    
    if aType:lower():find( 'multipart/form-data', 1, true ) then
        local MIME = require( 'MIME' )
        local aContent = 'content-type: ' .. aType .. '\r\n\r\n' .. ( aRequest.content or '' )
        local aMIME = MIME( aContent )
        
        for anIndex, aValue in ipairs( aMIME.content ) do
            aParameter[ aValue.key ] = aValue.value
            aParameter[ aValue.key .. '.filename' ] = aValue.filename
        end
    elseif aType:lower():find( 'application/x-www-form-urlencoded', 1, true ) then
        local URLParameter = require( 'URLParameter' )
        local aFormParameter = URLParameter( aRequest.content )

        for aKey, aValue in pairs( aFormParameter ) do
            aParameter[ aKey ] = aValue
        end
    end

    return aParameter
end

local function NewRequest( aReader )
    local aStatus = ReadStatus( aReader )
    local aHeader = ReadHeader( aReader )
    local aContent = ReadContent( aReader, aHeader )
    local aRequest = { status = aStatus, header = aHeader, content = aContent }
    
    aRequest.url = GetURL( aRequest )
    aRequest.parameter = GetParameter( aRequest )
    
    setmetatable( aRequest, self )
    
    return aRequest
end

local function WriteRequest( aRequest )
    local aBuffer = {}
    local aStatus = aRequest.status or {}
    local aMethod = tostring( aStatus.method or 'GET' )
    local aURI = tostring( aStatus.uri or '/' )
    local aVersion = tostring( aStatus.version or 'HTTP/1.1' )
    local aHeader = aRequest.header or {}
    local aContent = aRequest.content or ''
    
    aBuffer[ #aBuffer + 1 ] = ( '%s %s %s' ):format( aMethod, aURI, aVersion )
    
    for aKey, aValue in pairs( aHeader ) do
        aBuffer[ #aBuffer + 1 ] = ( '%s: %s' ):format( Capitalize( tostring( aKey ) ), tostring( aValue ) )
    end
    
    aBuffer[ #aBuffer + 1 ] = ''
    aBuffer[ #aBuffer + 1 ] = tostring( aContent )
    
    return table.concat( aBuffer, '\r\n' )
end

function meta:__call( aReader )
    return NewRequest( aReader )
end

function self:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function self:__tostring()
    return WriteRequest( self )
end

--------------------------------------------------------------------------------
-- HTTPResponse
--------------------------------------------------------------------------------

module( 'HTTPResponse' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

function ConnectionFilter( aRequest, aResponse )
    local aConnection = aRequest.header[ 'connection' ]
    
    if aConnection then
        aConnection = aConnection:lower()

        if aConnection:find( 'close', 1, true ) then
            aResponse.header[ 'connection' ] = 'close'
        end
        
        if aConnection:find( 'keep-alive', 1, true ) then
            aResponse.header[ 'connection' ] = 'keep-alive'
        end
    elseif aRequest.status.version == aResponse.status.version then
        aResponse.header[ 'connection' ] = 'keep-alive'
    end
end

self.filter = { ConnectionFilter }

local function NewResponse()
    local aStatus = { version = 'HTTP/1.1', code = 200, description = 'OK' }
    local aHeader = { connection = 'close', date = os.date( '!%a, %d %b %Y %H:%M:%S GMT', os.time() ) }
    local aResponse = { status = aStatus, header = aHeader }
        
    setmetatable( aResponse, self )
    
    return aResponse
end

local function WriteResponse( aResponse, aWriter )
    local aStatus = aResponse.status or {}
    local aVersion = tostring( aStatus.version or 'HTTP/1.1' )
    local aCode = tostring( aStatus.code or 200 )
    local aDescription = tostring( aStatus.description or 'OK' )
    local aHeader = aResponse.header or {}
    local aContent = aResponse.content
    
    aWriter( ( '%s %s %s ' ):format( aVersion, aCode, aDescription ), '\r\n' )
    
    for aKey, aValue in pairs( aHeader ) do
        aWriter( ( '%s: %s' ):format( Capitalize( tostring( aKey ) ), tostring( aValue ) ), '\r\n' )
    end
    
    aWriter( '\r\n' )
    
    if type( aContent ) == 'function' then
        for aValue in aContent do
            aValue = tostring( aValue )
            aWriter( ( '%X' ):format( aValue:len() ), '\r\n' )
            aWriter( aValue, '\r\n' )
        end
        aWriter( '0\r\n\r\n' )
    elseif aContent then
        aWriter( tostring( aContent ) )
    end
end

function meta:__call()
    return NewResponse()
end

function self:__call( aWriter )
    local aWriter = function( ... )
        aWriter:write( ... )
    end

    WriteResponse( self, aWriter )
    
    return self
end

function self:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function self:__tostring()
    local aBuffer = {}
    local aWriter = function( ... )
        for anIndex = 1, select( '#', ... ) do
            aBuffer[ #aBuffer + 1 ] = select( anIndex, ... )
        end
    end
    
    WriteResponse( self, aWriter )
    
    return table.concat( aBuffer )
end

--------------------------------------------------------------------------------
-- HTTP
--------------------------------------------------------------------------------

module( 'HTTP' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

self.request = {}
self.response = {}

local function Filter( someFilters, aRequest, aResponse )
    for anIndex, aFilter in ipairs( someFilters or {} ) do
        if aFilter( aRequest, aResponse ) == false then
            return false
        end
    end
    
    return true
end

local function Pattern( aMethod, aHost, aPath )
    local aBuffer = {}
    
    aBuffer[ #aBuffer + 1 ] = tostring( aMethod or '.*' ):lower()
    aBuffer[ #aBuffer + 1 ] = tostring( aHost or '.*' ):lower()
    aBuffer[ #aBuffer + 1 ] = tostring( aPath or '.*' )
    
    return table.concat( aBuffer, '|' )
end

local function Argument( ... )
    local someArguments = { n = select( '#', ... ) - 1, ... }

    for anIndex = 1, someArguments.n do
        local aValue = someArguments[ anIndex ]
        
        if aValue:len() == 0 then
            aValue = nil
        end
        
        aValue = tonumber( aValue ) or aValue
        
        someArguments[ anIndex ] = aValue
    end
    
    return someArguments
end

local function Method( aHandler, aMethod, someArguments )
    if type( aHandler ) == 'string' then
        aHandler = require( aHandler )
    end
    
    if type( aHandler ) == 'table' and aHandler[ aMethod:lower() ] then
        someArguments = { n = someArguments.n + 1, aHandler, unpack( someArguments, 1, someArguments.n ) }
        aHandler = aHandler[ aMethod:lower() ]
    end

    if type( aHandler ) == 'function' then
        return aHandler, someArguments
    end
    
    return function() end, {}
end

local function Handler( someHandlers, aRequest )
    local aMethod = aRequest.status.method
    local aHost = aRequest.url.host
    local aPath = aRequest.url.path
    local aValue = Pattern( aMethod, aHost, aPath )
    
    for anIndex, aList in ipairs( someHandlers ) do
        local aPattern = '^' .. aList[ 1 ] .. '(%z?)$'
        
        if aValue:find( aPattern ) then
            local aHandler = aList[ 2 ]
            local someArguments = Argument( aValue:match( aPattern ) )
            
            return Method( aHandler, aMethod, someArguments )
        end
    end
    
    return function() end, {}
end

local function Content( someHandlers, aRequest, aResponse )
    local aHandler, someArguments = Handler( someHandlers, aRequest )
    local aContent, aLocation = aHandler( unpack( someArguments, 1, someArguments.n ) )
    
    if aContent then
        aResponse.header[ 'content-type' ] = aResponse.header[ 'content-type' ] or 'text/html; charset=utf-8'
        aResponse.content = aContent
    end
    
    if aLocation then
        aResponse.status.code = 302
        aResponse.status.description = 'Found'
        aResponse.header[ 'location' ] = aRequest.url + aLocation
        aResponse.header[ 'content-type' ] = 'text/plain'
        aResponse.content = aResponse.header[ 'location' ]
    end
    
    if not aContent and not aLocation then
        aResponse.status.code = 404
        aResponse.status.description = 'Not Found'
        aResponse.header[ 'content-type' ] = 'text/plain'
        aResponse.content = '404 Not Found'
    end
end

local function Length( aRequest, aResponse )
    local aContent = aResponse.content

    if type( aContent ) == 'function' and aRequest.status.version ~= aResponse.status.version then
        local aBuffer = {}
        
        for aValue in aContent do
            aBuffer[ #aBuffer + 1 ] = tostring( aValue )
        end
        
        aResponse.content = table.concat( aBuffer )
        aContent = aResponse.content
    end

    aResponse.header[ 'content-length' ] = nil

    if type( aContent ) == 'function' then
        aResponse.header[ 'transfer-encoding' ] = 'chunked'
    elseif aContent then
        aResponse.content = tostring( aContent )
        aResponse.header[ 'content-length' ] = aResponse.content:len()
    end
end

local function Dispatch( someHandlers, aRequest, aResponse )    
    local HTTP = require( 'HTTP' )
    local HTTPRequest = require( 'HTTPRequest' )
    local HTTPResponse = require( 'HTTPResponse' )

    HTTP.request = aRequest
    HTTP.response = aResponse
            
    if Filter( HTTPRequest.filter, aRequest, aResponse ) then
        Content( someHandlers, aRequest, aResponse )
    end
    
    Length( aRequest, aResponse )
    Filter( HTTPResponse.filter, aRequest, aResponse )
    Length( aRequest, aResponse )
            
    return not ( aResponse.header[ 'connection' ] or '' ):lower():find( 'close', 1, true )
end

local function Call( someHandlers, aReader, aWriter )
    aWriter:flush()

    return function()
        local HTTPRequest = require( 'HTTPRequest' )
        local aRequest = HTTPRequest( aReader )
        
        if aRequest.status.method:len() > 0 then
            local HTTPResponse = require( 'HTTPResponse' )
            local aResponse = HTTPResponse()
            local shouldContinue = Dispatch( someHandlers, aRequest, aResponse ) 
            
            aResponse( aWriter )
            
            return shouldContinue
        end

        return false
    end
end

function meta:__call( aReader, aWriter )
    local aReader = aReader or io.stdin
    local aWriter = aWriter or io.stdout
    local aCall = Call( self, aReader, aWriter )
    local aStatus, aResult = xpcall( aCall, debug.traceback )
    
    if not aStatus then
        local HTTPResponse = require( 'HTTPResponse' )
        local aResponse = HTTPResponse()
        
        aResponse.status.code = 500
        aResponse.status.description = 'Internal Server Error'
        aResponse.header[ 'connection' ] = 'close'
        aResponse.header[ 'content-type' ] = 'text/plain'
        aResponse.header[ 'content-length' ] = tostring( aResult ):len()
        aResponse.content = aResult

        aResponse( aWriter )
        
        return self
    elseif not aResult then
        return self
    end
    
    return self( aReader, aWriter )
end

function meta:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function meta:__tostring()
    return _NAME
end

function meta:__index( aKey )
    if aKey == 'address' then
        return os.getenv( 'TCPLOCALHOST' ) or os.getenv( 'TCPLOCALIP' )
    elseif aKey == 'port' then
        return tonumber( os.getenv( 'TCPLOCALPORT' ) )
    end
end

function meta:__newindex( aKey, aValue )
    if type( aKey ) == 'table' then
        if #aKey == 1 then
            aKey = { nil, nil, aKey[ 1 ] }
        elseif #aKey == 2 then
            aKey = { aKey[ 1 ], nil, aKey[ 2 ] }
        end
    else
        aKey = { nil, nil, aKey }
    end
    
    rawset( self, #self + 1, { Pattern( unpack( aKey, 1, 3 ) ), aValue } )
end
