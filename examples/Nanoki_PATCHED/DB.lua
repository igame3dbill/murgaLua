--------------------------------------------------------------------------------
-- Title:               DB.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- import dependencies
local assert = assert
local getmetatable = getmetatable
local ipairs = ipairs
local module = module
local require = require
local select = select
local setmetatable = setmetatable
local tostring = tostring
local type = type
local unpack = unpack

--------------------------------------------------------------------------------
-- DB
--------------------------------------------------------------------------------

module( 'DB' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

local function NewEnvironment( aURL, ... )
    local aType = assert( aURL.scheme, 'missing scheme in ' .. aURL )
    local aModule = require( 'luasql.' .. aType )
    local LuaSQL = require( 'luasql' )
    local aFunction = assert( LuaSQL[ aType ], 'missing ' .. aType .. ' initialization function in luasql'  )
    local anEnvironment = assert( aFunction( ... ) )
    
    return anEnvironment
end

local function NewConnection( anEnvironment, aURL )
    local aSource = aURL.path[ 1 ]
    local aUser = aURL.user
    local aPassword = aURL.password
    local aHost = aURL.host
    local aPort = aURL.port
    local aConnection = assert( anEnvironment:connect( aSource, aUser, aPassword, aHost, aPort ) )
    
    aConnection:setautocommit( true )
    
    return aConnection
end

function meta:__call( aURL, ... )
    local URL = require( 'URL' )
    local aURL = URL( aURL )
    local anEnvironment = NewEnvironment( aURL, ... )
    local aConnection = NewConnection( anEnvironment, aURL )
    local aDB = { url = aURL, environment = anEnvironment, connection = aConnection }

    setmetatable( aDB, self )
    
    return aDB
end

function self:__call( aStatement, ... )
    return require( 'DBCursor' )( self, aStatement, ... )
end

function self:__newindex( aKey, aValue )
    if aKey == 'autocommit' then
        self.connection:setautocommit( aValue )
    elseif aKey == 'commit' and aValue then
        self.connection:commit()
    elseif aKey == 'commit' and not aValue then
        self.connection:rollback()
    elseif aKey == 'close' and aValue then
        self.connection:close()
        self.environment:close()
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
    return tostring( self.url )
end

--------------------------------------------------------------------------------
-- DBCursor
--------------------------------------------------------------------------------

module( 'DBCursor' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

local function PreparedStatement( aStatement, ... )
    local aCount =  select( '#', ... )
    
    if aCount > 0 then
        local someBindings = {}
        
        for anIndex = 1, aCount do
            local aValue = select( anIndex, ... )
            local aType = type( aValue )
            
            if aType == 'string' then
                aValue = '\'' .. aValue:gsub( '\'', '\'\'' ) .. '\''
            elseif aType == 'nil' then
                aValue = 'null'
            else
                aValue = tostring( aValue )
            end 
            
            someBindings[ anIndex ] = aValue
        end
        
        aStatement = aStatement:format( unpack( someBindings ) )
    end

    return aStatement
end

local function ColumnNames( someNames )
    for anIndex, aValue in ipairs( someNames ) do
        someNames[ anIndex ] = aValue:lower()
    end
    
    return someNames
end

local function ColumnTypes( someTypes )
    for anIndex, aValue in ipairs( someTypes ) do
        someTypes[ anIndex ] = aValue:lower()
    end
    
    return someTypes
end

function meta:__call( aDB, aStatement, ... )
    local aConnection = aDB.connection
    local aStatement = PreparedStatement( aStatement, ... )
    local aResult = assert( aConnection:execute( aStatement ) )
    
    if type( aResult ) ~= 'number' then
        local someNames = ColumnNames( aResult:getcolnames() )
        local someTypes = ColumnTypes( aResult:getcoltypes() )
        local aCursor = { db = aDB, cursor = aResult, statement = aStatement, names = someNames, types = someTypes, row = {} }
        
        if aResult[ 'numrows' ] then
            aCursor[ 'count' ] = aResult:numrows()
        end
        
        setmetatable( aCursor, self )
        
        return aCursor
    end
    
    return aResult
end

function self:__call()
    local aCursor = self.cursor
    local aRow = aCursor:fetch( self.row, 'n' )
    
    if aRow then
        local someNames = self.names
        local aResult = {}
        
        for anIndex, aValue in ipairs( aRow ) do
            local aName = someNames[ anIndex ]
            
            aResult[ aName ] = aValue
        end
        
        return aResult
    end
    
    aCursor:close()
end

function self:__newindex( aKey, aValue )
    if aKey == 'close' and aValue then
        self.cursor:close()
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
    return tostring( self.statement )
end
