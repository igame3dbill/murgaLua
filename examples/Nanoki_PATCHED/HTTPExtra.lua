--------------------------------------------------------------------------------
-- Title:               HTTPExtra.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- import dependencies
local HTTP = require( 'HTTP' )

local io = require( 'io' )
local os = require( 'os' )
local table = require( 'table' )

local getfenv = getfenv
local getmetatable = getmetatable
local ipairs = ipairs
local module = module
local package = package
local pairs = pairs
local pcall = pcall
local rawget = rawget
local require = require
local setmetatable = setmetatable
local tonumber = tonumber
local tostring = tostring
local type = type
local unpack = unpack

--------------------------------------------------------------------------------
-- HTTPRequest (Extra)
--------------------------------------------------------------------------------

module( 'HTTPRequest' )

local self = _M

local function Forward( aValue )
    if aValue and aValue:len() > 0 then
        aValue = aValue:match( '^([^,]+)' )
        
        if aValue and aValue:len() > 0 then
            return aValue
        end
    end
end

function AddressFilter( aRequest, aResponse )
    if not aRequest.address then
        local anAddress = os.getenv( 'TCPREMOTEIP' )
        local anEnvironment = getfenv() or {}
        local isForwarded = anEnvironment[ 'forwarded' ]
        
        if isForwarded then
            local aForward = Forward( aRequest.header[ 'x-forwarded-for' ] )

            anAddress = aForward or anAddress
        end
        
        if anAddress then
            -- Requires Diego Nehab's LuaSocket library
            -- http://www.tecgraf.puc-rio.br/~diego/professional/luasocket/home.html
            local ok, socket = pcall( require, 'socket' )
            
            if ok and socket then
                anAddress = socket.dns.toip( anAddress ) or anAddress
            end
        end
        
        aRequest.address = anAddress
    end
end

function HostFilter( aRequest, aResponse )
    if not aRequest.host then
        -- Requires Diego Nehab's LuaSocket library
        -- http://www.tecgraf.puc-rio.br/~diego/professional/luasocket/home.html
        local ok, socket = pcall( require, 'socket' )
        local anAddress = aRequest.address
        local aHost = os.getenv( 'TCPREMOTEHOST' )
        
        if ok and socket and anAddress then
            aHost = socket.dns.tohostname( anAddress ) or anAddress
        end

        aRequest.host = aHost
    end
end

function AuthorizationFilter( aRequest, aResponse )
    if not aRequest.authorization and not aResponse.authorization then
        local aHeader = aRequest.header[ 'authorization' ]
    
        aRequest.authorization = {}
        aResponse.authorization = { scheme = 'Basic' }
    
        if aHeader then
            local aScheme, aCredential = aHeader:match( '(%S+)%s(%S+)' )
            
            if aScheme and aCredential and aScheme:find( 'Basic' ) then
                -- Requires Luiz Henrique de Figueiredo's lbase64 library
                -- http://www.tecgraf.puc-rio.br/~lhf/ftp/lua/5.1/lbase64.tar.gz
                local ok, base64 = pcall( require, 'base64' )

                if ok and base64 then
                    local URL = require( 'URL' )
                    local URLParameter = require( 'URLParameter' )
                    local aUser, aPassword = base64.decode( aCredential ):match( '(.*):(.*)' )
                    local aParameter = URLParameter( ( 'user=%s&password=%s' ):format( aUser, aPassword ) )
                    local aUser = aParameter.user
                    local aPassword = aParameter.password
                    local anAuthorization = { scheme = aScheme, user = aUser, password = aPassword }

                    aRequest.authorization = anAuthorization
                end
            end
        end
    end
end

function CookieFilter( aRequest, aResponse )
    if not aRequest.cookie and aResponse.cookie then
        local HTTPCookie = require( 'HTTPCookie' )
        local aHeader = aRequest.header[ 'cookie' ]
        local aCookie = HTTPCookie( aHeader )
        
        aRequest.cookie = aCookie
        aResponse.cookie = HTTPCookie( aCookie )
    end
end

self.filter[ #self.filter + 1 ] = AddressFilter
self.filter[ #self.filter + 1 ] = HostFilter
self.filter[ #self.filter + 1 ] = AuthorizationFilter
self.filter[ #self.filter + 1 ] = CookieFilter

--------------------------------------------------------------------------------
-- HTTPResponse (Extra)
--------------------------------------------------------------------------------

module( 'HTTPResponse' )

local self = _M

function AuthorizationFilter( aRequest, aResponse )
    if not aResponse.header[ 'www-authenticate' ] then
        local anAuthorization = aResponse.authorization or {}
        local aScheme = anAuthorization.scheme
        local aRealm = anAuthorization.realm
        
        if aScheme == 'Basic' and aRealm then
            aResponse.status.code = 401
            aResponse.status.description = 'Unauthorised'
            aResponse.header[ 'www-authenticate' ] = ( '%s realm="%s"' ):format( aScheme, aRealm )
            
            if not aResponse.content then
            aResponse.header[ 'content-type' ] = 'text/plain'
            aResponse.content = '401 Unauthorised'
        end
    end
end
end

function CookieFilter( aRequest, aResponse )
    if aResponse.cookie and not aResponse.header[ 'set-cookie' ] then
        aResponse.header[ 'set-cookie' ] = tostring( aResponse.cookie )
    end
end

function GZIPFilter( aRequest, aResponse )
    local aCode = aResponse.status.code
    local anEncoding = ( aResponse.header[ 'content-encoding' ] or '' ):lower()
    
    if aCode >= 200 and aCode <= 299 and not anEncoding:find( 'gzip', 1, true ) then
        local aLength = tonumber( aResponse.header[ 'content-length' ] ) or 0
        local anEncoding = ( aRequest.header[ 'accept-encoding' ] or '' ):lower()
        
        if aLength > 0 and anEncoding:find( 'gzip', 1, true ) then
            -- Requires Tiago Dionizio's lzlib library
            -- http://luaforge.net/projects/lzlib/
            local ok, zlib = pcall( require, 'zlib' )
            
            if ok and zlib then
                local aContent = tostring( aResponse.content )
                local zContent = zlib.compress( aContent, 9, nil, 15 + 16 )
                
                if zContent:len() < aContent:len() then
                    local aVary = ( aResponse.header[ 'vary' ] or 'accept-encoding' ):lower()
                    
                    if aVary ~= 'accept-encoding' then
                        aVary = aVary .. ',' .. 'accept-encoding'
                    end
                
                    aResponse.header[ 'content-encoding' ] = 'gzip'
                    aResponse.header[ 'vary' ] = aVary
                    aResponse.content = zContent
                end
            end
        end
    end
end

function ETagFilter( aRequest, aResponse )
    local aCode = aResponse.status.code
    
    if aCode >= 200 and aCode <= 299 then
        local aLength = tonumber( aResponse.header[ 'content-length' ] ) or 0
        local anEtag = aResponse.header[ 'etag' ]

        if aLength > 0 and not anEtag then
            -- Requires Luiz Henrique de Figueiredo's lmd5 library
            -- http://www.tecgraf.puc-rio.br/~lhf/ftp/lua/5.1/lmd5.tar.gz
            local ok, md5 = pcall( require, 'md5' )
        
            -- if ok and md5 then
                aResponse.header[ 'etag' ] = md5.sumhexa( tostring( aResponse.content ) )
            -- end
        end
    end
end

function RangeFilter( aRequest, aResponse )
    local aCode = aResponse.status.code
    
    if aCode >= 200 and aCode <= 299 then
        local aLength = tonumber( aResponse.header[ 'content-length' ] ) or 0
        local aRange = ( aRequest.header[ 'range' ] or '' ):lower()

        if aLength > 0 and aRange ~= '' then
        end
    end
end

function ConditionalFilter( aRequest, aResponse )
    local aCode = aResponse.status.code
    
    if aCode >= 200 and aCode <= 299 then
        local modifiedSince = aRequest.header[ 'if-modified-since' ] or 0
        local lastModified = aResponse.header[ 'last-modified' ] or 1
        local noneMatch = aRequest.header[ 'if-none-match' ] or 0
        local etag = aResponse.header[ 'etag' ] or 1
        
        if modifiedSince == lastModified or noneMatch == etag then
            aResponse.status.code = 304
            aResponse.status.description = 'Not Modified'
        end
    end    
end

function MD5Filter( aRequest, aResponse )
    local aLength = tonumber( aResponse.header[ 'content-length' ] ) or 0
    local aMD5 = aResponse.header[ 'content-md5' ]
    
    if aLength > 0 and not aMD5 then
        -- Requires Luiz Henrique de Figueiredo's lmd5 library
        -- http://www.tecgraf.puc-rio.br/~lhf/ftp/lua/5.1/lmd5.tar.gz
        local ok, md5 = pcall( require, 'md5' )
        
        -- if ok and md5 then
            aResponse.header[ 'content-md5' ] = md5.sumhexa( tostring( aResponse.content ) )
        -- end
    end
end

function ContentFilter( aRequest, aResponse )
    local aMethod = ( aRequest.status.method or '' ):lower()
    local aCode = aResponse.status.code or 200
    
    if aMethod == 'head' or ( aCode >= 100 and aCode < 200 ) or aCode == 204 or aCode == 304 then
        aResponse.content = nil
    end
end

local months = { jan = 1, feb = 2, mar = 3, apr = 4, may = 5, jun = 6, jul = 7, aug = 8, sep = 9, oct = 10, nov = 11, dec = 12 }

local function DateTime( aValue )
    -- e.g. "Fri, 05 Jan 2007 17:27:31 GMT"
    local aPattern = '(%d%d?) (%a%a%a) (%d%d%d%d) (%d%d):(%d%d):(%d%d)'
    local aDay, aMonth, aYear, aHour, aMinute, aSecond = aValue:match( aPattern )
    local aYear = tonumber( aYear )
    local aMonth = months[ aMonth:lower() ]
    local aDay = tonumber( aDay )
    local aHour = tonumber( aHour )
    local aMinute = tonumber( aMinute )
    local aSecond = tonumber( aSecond )
    local aDate = { year = aYear, month = aMonth, day = aDay, hour = aHour, min = aMinute, sec = aSecond }
    local aTime = os.time( aDate )
    
    return aTime
end

function ExpiresFilter( aRequest, aResponse )
    local lastModified = aResponse.header[ 'last-modified' ]
    local aDate = aResponse.header[ 'date' ]
    local anExpires = aResponse.header[ 'expires' ]
    
    if lastModified and aDate and not anExpires then
        local lastModified = DateTime( lastModified )
        local aDate = DateTime( aDate )
        local anInterval = aDate - lastModified
        
        if anInterval > 0 then
            aResponse.header[ 'expires' ] = os.date( '!%a, %d %b %Y %H:%M:%S GMT', aDate + ( anInterval / 2 ) )
        end
    end
end

function LogFilter( aRequest, aResponse )
    local aWriter = io.stderr
    local aHost = aRequest.host or '-'
    local anAuthorization = aRequest.authorization or {}
    local aUser = anAuthorization.user or '-'
    local aDate = ( '[%s]' ):format( os.date( '!%d/%b/%Y:%H:%M:%S -0000', os.time() ) )
    local aLine = ( '"%s %s %s"' ):format( aRequest.status.method, aRequest.status.uri, aRequest.status.version )
    local aStatus = aResponse.status.code or '-'
    local aLength = aResponse.header[ 'content-length' ] or '-'
    local aReferer = aRequest.header[ 'referer' ] or '-'
    local anAgent = aRequest.header[ 'user-agent' ] or '-'

    if aReferer ~= '-' then
        aReferer = ( '%q' ):format( aReferer )
    end

    if anAgent ~= '-' then
        anAgent = ( '%q' ):format( anAgent )
    end

    aWriter:write( aHost, ' ' )
    aWriter:write( '-', ' ' )
    aWriter:write( aUser, ' ' )
    aWriter:write( aDate, ' ' )
    aWriter:write( aLine, ' ' )
    aWriter:write( aStatus, ' ' )
    aWriter:write( aLength, ' ' )
    aWriter:write( aReferer, ' ' )
    aWriter:write( anAgent, '\n' )
    aWriter:flush()
end

self.filter[ #self.filter + 1 ] = AuthorizationFilter
self.filter[ #self.filter + 1 ] = CookieFilter
self.filter[ #self.filter + 1 ] = GZIPFilter
self.filter[ #self.filter + 1 ] = ETagFilter
self.filter[ #self.filter + 1 ] = RangeFilter
self.filter[ #self.filter + 1 ] = ConditionalFilter
self.filter[ #self.filter + 1 ] = MD5Filter
self.filter[ #self.filter + 1 ] = ContentFilter
self.filter[ #self.filter + 1 ] = ExpiresFilter
self.filter[ #self.filter + 1 ] = LogFilter

--------------------------------------------------------------------------------
-- HTTPCookie
-- as per Xavante's Cookies module 
-- http://www.keplerproject.org/xavante/
--------------------------------------------------------------------------------

module( 'HTTPCookie' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

local function ReadCookie( aValue )
    local someCookies = {}
    local aName = nil
    
    for aKey, aValue in ( aValue or '' ):gmatch( '([^%s;=]+)%s*=%s*"([^"]*)"' ) do
        aKey = aKey:lower()
    
        if aKey:byte() == 36 then -- $option
            if aName then
                local anOption = aKey:sub( 2 )
                    
                someCookies[ aName ].option[ anOption ] = aValue
            end
        else
            someCookies[ aKey ] = { value = aValue, option = {} }
            aName = aKey
        end
    end
    
    return someCookies
end

local function WriteCookie( aValue )
    local aBuffer = {}
        
    for aName, aCookie in pairs( aValue or {} ) do
        local aFormat = ( '%s="%s";version="1"' ):format( aName, aCookie.value )
        local anOption = aCookie.option
        
        if anOption then
            for aKey, aValue in pairs( anOption ) do
                aFormat = aFormat .. ( ';%s="%s"' ):format( aKey:lower(), tostring( aValue ) )
            end
        end
                        
        aBuffer[ #aBuffer + 1 ] = aFormat
    end
        
    if #aBuffer > 0 then
        return table.concat( aBuffer, '' )
    end
    
    return nil
end

local function NewCookie( aValue )
    local aCookie = nil
    
    if type( aValue ) == 'table' then
        aCookie = ReadCookie( WriteCookie( aValue ) )
    else
        aCookie = ReadCookie( tostring( aValue or '' ) )
    end
    
    setmetatable( aCookie, self )
    
    return aCookie
end

function meta:__call( aValue )
    return NewCookie( aValue )
end

function self:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function self:__tostring()
    return WriteCookie( self )
end

--------------------------------------------------------------------------------
-- HTTPFile
--------------------------------------------------------------------------------

module( 'HTTPFile' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

local function File( aDirectory, aName )
    if aDirectory and aName then
        local aSeparator = package.path:match( '(%p)%?%.' ) or '/'
        local aPath = aDirectory .. aName:gsub( '%.%.', '' ):gsub( '\\', '' ):gsub( '/', aSeparator )
        local aFile = io.open( aPath, 'rb' )
        
        return aFile, aPath
    end
end

local function Size( aFile )
    local aSize = aFile:seek( 'end' )
    
    aFile:seek( 'set' )
    
    return aSize
end

local function Modification( aPath )
    -- Requires Kepler's LuaFileSystem
    -- http://www.keplerproject.org/luafilesystem/
    local ok, lfs = pcall( require, 'lfs' )
    
    if ok and lfs then
        return lfs.attributes( aPath, 'modification' )
    end
end

local function Hash( aPath, aSize, aModification  )
    if aPath and aSize and aModification then
        -- Requires Luiz Henrique de Figueiredo's lmd5 library
        -- http://www.tecgraf.puc-rio.br/~lhf/ftp/lua/5.1/lmd5.tar.gz
        local ok, md5 = pcall( require, 'md5' )
    
        -- if ok and md5 then
            return md5.sumhexa( aPath .. ':' .. aSize .. ':' .. aModification )
        -- end
    end
end

local function Type( aName )
    local MIME = require( 'MIME' )
    local MIMEType = require( 'MIMEType' )
    local anExtension = ( aName:match( '^.+%.(%w+)$' ) or '' ):lower()
    
    return MIMEType[ anExtension ] or 'application/octet-stream'
end

local function Content( aFile, aSize, aChunk )
    if aSize <= aChunk * 10 then
        local aContent = aFile:read( '*a' )

        aFile:close()
        
        return aContent
    end

    return function()
        local aContent = aFile:read( aChunk )
        
        if aContent then
            return aContent
        end
        
        aFile:close()
    end
end

function meta:__call( aDirectory, aChunk )
    aDirectory = tostring( aDirectory or '' ) 
    aChunk = tonumber( aChunk ) or 8192

    return function( aName )
        local aFile, aPath = File( aDirectory, aName )

        if aFile then
            local aSize = Size( aFile )
            local aModification = Modification( aPath )
        
            if aModification then
                HTTP.response.header[ 'last-modified' ] = os.date( '!%a, %d %b %Y %H:%M:%S GMT', aModification )
                HTTP.response.header[ 'etag' ] = Hash( aPath, aSize, aModification )
            end
            
            HTTP.response.header[ 'content-disposition' ] = ( 'inline; filename="%s"' ):format( aName )
            HTTP.response.header[ 'content-type' ] = Type( aName )

            return Content( aFile, aSize, aChunk )
        end
    end
end

--------------------------------------------------------------------------------
-- HTTPService
--------------------------------------------------------------------------------

module( 'HTTPService' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

local function Type( anObject )
    if type( anObject ) == 'table' then
        return anObject._NAME or ( getmetatable( anObject ) or {} )._NAME
    end
    
    return type( anObject )
end

local function Capitalize( aValue )
    return ( aValue:lower():gsub( '(%l)([%w_\']*)', function( first, rest ) return first:upper() .. rest end ) )
end

local function Argument( anObject, anAction )
    local someArguments = { anObject }
    local aReader = function( aValue )
        someArguments[ #someArguments + 1 ] = tonumber( aValue ) or aValue
    end

    anAction:gsub( '([^%.]+)', aReader )
    
    return someArguments
end

local function Handler( anObject, aMethod, anAction, isLast )
    local aHandlerAction, anArgument = ( anAction or '' ):match( '([^%.]*)%.?(.*)' )
    
    if not isLast then
        aMethod = 'get'
    end
    
    aHandlerAction = aMethod:lower() .. Capitalize( aHandlerAction )

    if type( anObject ) == 'table' and type( anObject[ aHandlerAction ] ) == 'function' then
        local someArguments = Argument( anObject, anArgument )
        
        return anObject[ aHandlerAction ], someArguments
    end
    
    if type( anObject ) == 'string' then
        return function() return anObject end, {}
    end

    if type( anObject ) == 'function' then
        return function() return anObject end, {}
    end

    if aMethod:lower() == 'head' then
        return Handler( anObject, 'get', anAction, isLast )
    end
    
    return function() end, {}
end

local function Action()
    for aKey, aValue in pairs( HTTP.request.parameter ) do
        local aParameter = aKey:match( '^action%.([%w%p]+)$' )
        
        if aParameter then
            return aParameter
        end
    end
end

local function Iterator( aURL, aBase )
    local URL = require( 'URL' )
    local URLPath = require( 'URLPath' )
    local aPath = URLPath( tostring( aURL.path ):sub( tostring( aBase.path ):len() + 1 ) )
    local aServicePath = URLPath( aBase.path )
    local anAction = Action()
    local aCount = #aPath + 1
    local anIndex = 1
    
    if anAction then
        aPath[ #aPath + 1 ] = anAction
        aCount = #aPath
    else
        aPath[ #aPath + 1 ] = ''
        aCount = #aPath
    end
    
    return function()
        if anIndex <= aCount then
            local isLast = anIndex == aCount
            local aComponent = aPath[ anIndex ]
            
            if anIndex > 1 then
                aServicePath = aServicePath( aPath[ anIndex - 1 ] )
            end

            anIndex = anIndex + 1

            return URLPath( aServicePath ), aComponent, isLast
        end
    end
end

local function Dispatch( aService, aURL, anObject, aMethod )
    local aBase = aService[ anObject ]
    local aLocation = nil

    if not aBase then
        return nil
    end
    
    if not tostring( aURL.path ):find( tostring( aBase.path ), 1, true ) then
        return nil, aBase
    end

    for aPath, anAction, isLast in Iterator( aURL, aBase ) do
        local aHandler, someArguments = Handler( anObject, aMethod, anAction, isLast )
        
        if type( anObject ) == 'table' then
            anObject.path = aPath
        end

        anObject, aLocation = aHandler( unpack( someArguments ) )

        if aLocation then
            return anObject, aLocation
        end
    end
            
    return anObject, aLocation
end

function meta:__call( aPrefix, anObject, toURL, toObject )
    local aPattern = aPrefix  .. '.*'
    local toURL = toURL or anObject[ 'toURL' ]
    local toObject = toObject or anObject[ 'toObject' ]
    local aType = Type( anObject )
    local aService = { prefix = aPrefix, pattern = aPattern, type = aType, toURL = toURL, toObject = toObject }
    
    self[ aType ] = aService
    
    setmetatable( aService, self )
    
    return aService
end

function meta:__index( aKey )
    local aService = rawget( self, Type( aKey ) )
    
    if aService then
        return aService[ aKey ]
    end
end

function self:__call()
    return function()
        local aRequest = HTTP.request
        local aURL = aRequest.url
                
        if tostring( aURL.path ) == '/' or not aURL.path.directory then
            local anObject = self[ aURL ]
            local aMethod = aRequest.status.method
            
            return Dispatch( self, aURL, anObject, aMethod )
        end
        
        HTTP.request.url.path.directory = false
        
        return nil, HTTP.request.url
    end
end

function self:__index( aKey )
    if Type( aKey ) == self.type then
        return HTTP.request.url + self:toURL( aKey )
    elseif Type( aKey ) == 'URL' then
        aKey = require( 'URL' )( tostring( aKey ):gsub( '(%.[^/]*)', '' ) )
    
        return self:toObject( aKey )
    end
end

function self:__eq( aValue )
    return tostring( self ) == tostring( aValue )
end

function self:__lt( aValue )
    return tostring( self ) < tostring( aValue )
end

function self:__tostring()
    return self.prefix
end


