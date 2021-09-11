--------------------------------------------------------------------------------
-- Title:               WikiContent.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- import dependencies
local Wiki = require( 'Wiki' )

local io = require( 'io' )
local os = require( 'os' )
local table = require( 'table' )

local assert = assert
local error = error
local getmetatable = getmetatable
local rawget = rawget
local rawset = rawset
local require = require
local setmetatable = setmetatable
local tonumber = tonumber
local tostring = tostring

--------------------------------------------------------------------------------
-- WikiContent
--------------------------------------------------------------------------------

module( 'WikiContent' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

local location = Wiki.Location()

--------------------------------------------------------------------------------
-- Name utilities
--------------------------------------------------------------------------------

local function Capitalize( aValue )
    return ( aValue:lower():gsub( '^(.)([%w_\']*)', function( first, rest ) return first:upper() .. rest end ) )
end

local function Name( aName, aLength )
    local aLength = aLength or 2
    local Unidecode = require( 'Unidecode' )
    
    aName = aName or ''
    aName = Unidecode( aName )
    aName = aName:gsub( '%W', ' ' )
    aName = aName:gsub( '(%l)(%u)', '%1 %2' )
    aName = aName:gsub( '(%u)(%u)(%l)', "%1 %2%3" )
    aName = aName:gsub( '%s+', ' ' )
    aName = aName:gsub( '^%s', '' )
    aName = aName:sub( 1, 128 )
    aName = aName:gsub( '%s$', '' )
    aName = aName:gsub( ' ', '-' )
    aName = aName:lower()
    
    if aName:len() > aLength then
        return aName
    end
end

local function Title( aName )
    local aBuffer = {}
    local aReader = function( aValue )
        aBuffer[ #aBuffer + 1 ] = Capitalize( aValue )
    end

    aName:gsub( '([^-]+)', aReader )
    
    return table.concat( aBuffer, ' ' )
end

local function Prefix( aName )
    return aName:gsub( '-', '' ):match( '^(%w)(%w)' )
end

--------------------------------------------------------------------------------
-- IO utilities
--------------------------------------------------------------------------------

local function Directory( aName )
    local File = require( 'File' )
    local aFirst, aSecond = Prefix( aName )
    local aDirectory = File( location, 'wiki', 'content', aFirst, aSecond, aName )
    
    return aDirectory
end

local function DataFile( aName, aVersion )
    local File = require( 'File' )
    local aDirectory = Directory( aName )
    local aFile = File( aDirectory.path, ( 'data.txt;%d' ):format( aVersion ) )
    
    return aFile
end

local function VersionIterator( aName )
    local aDirectory = Directory( aName )

    if aDirectory.exists then
        local anIterator = aDirectory()

        return function()
            local aFile = anIterator()
            
            while aFile and not aFile.name:find( '^data%.txt;%d+$' ) do
                aFile = anIterator()
            end
            
            if aFile and aFile.name:find( '^data%.txt;%d+$' ) then
                local aVersion = tonumber( aFile.name:match( '^data%.txt;(%d+)$' ) )
                
                return aVersion, aFile
            end
        end
    end  
    
    return function() end
end

local function FirstVersion( aName )
    local firstVersion = nil
    
    for aVersion in VersionIterator( aName ) do
        if not firstVersion or aVersion < firstVersion then
            firstVersion = aVersion
        end
    end
    
    return firstVersion or 1
end

local function LastVersion( aName )
    local lastVersion = nil
    
    for aVersion in VersionIterator( aName ) do
        if not lastVersion or aVersion > lastVersion then
            lastVersion = aVersion
        end
    end
    
    return lastVersion or 1
end

local function PreviousVersion( aName, aCurrentVersion )
    local previousVersion = nil
    local anInterval = nil
    
    for aVersion in VersionIterator( aName ) do
        if aVersion < aCurrentVersion
        and ( not previousVersion 
        or not anInterval
        or ( aCurrentVersion - aVersion ) < anInterval ) then
            previousVersion = aVersion
            anInterval = aCurrentVersion - previousVersion
        end
    end

    return previousVersion
end

local function PurgeVersion( aName, aLimit )
    local aLimit = aLimit or 100
    local aList = {}
    
    for aVersion in VersionIterator( aName ) do
        aList[ #aList + 1 ] = aVersion
    end
    
    if #aList > aLimit then
        table.sort( aList )
        
        for anIndex = 1, #aList - aLimit do
            local aVersion = aList[ anIndex ]
            local aFile = DataFile( aName, aVersion )
            
            aFile.delete = true
        end
    end
end

local function ReadData( aPath, aCount )
    local lfs = require( 'lfs' )
    local aCount = aCount or 1
    local aReader = assert( io.open( aPath, 'rb' ) )
    
    if lfs.lock( aReader, 'r' ) then
        local aContent = aReader:read( '*a' )
        
        lfs.unlock( aReader )
        aReader:close()
        
        return aContent
    end
    
    aReader:close()
    
    aCount = aCount + 1
    
    if aCount > 10 then
        error( ( 'Failed to read data from %q' ):format( aPath ) )
    end
    
    return ReadData( aPath, aCount ) 
end

local function WriteData( aPath, aData )
    local lfs = require( 'lfs' )
    local aWriter = assert( io.open( aPath, 'wb' ) )
    
    if lfs.lock( aWriter, 'w' ) then
        aWriter:write( aData )
        aWriter:flush()
        lfs.unlock( aWriter )
        aWriter:close()
        
        return
    end
    
    aWriter:close()

    error( ( 'Failed to write data to %q' ):format( aPath ) )
end

local function ContentCreation( aName )
    local aDirectory = Directory( aName )
    local aFile = DataFile( aName, FirstVersion( aName ) )

    if aFile.exists then
        local Data = require( 'Data' )
        
        return Data( ReadData( aFile.path ) ).creation
    end
    
    return os.time()
end

local function ContentData( aName, aVersion )
    local aDirectory = Directory( aName )
    local aFile = DataFile( aName, aVersion )
    
    if aFile.exists then
        local Data = require( 'Data' )
        
        return Data( ReadData( aFile.path ) )
    end
    
    return { title = Title( aName ), type = 'text/markdown', encoding = 'utf-8', creation = ContentCreation( aName ) }
end

local function Lock( aName )
    local File = require( 'File' )
    local aDirectory = Directory( aName )
    local aFile = File( aDirectory.path, '.lock' )
    local aLock = assert( io.open( aFile.path, 'wb' ) )
    
    return aLock
end

local function MakeDirectory( aName )
    local lfs = require( 'lfs' )
    local File = require( 'File' )
    local aDirectory = Directory( aName )
    local aPath = ''
    local aMaker = function( aValue )
        aPath = aPath .. aValue .. File.separator
        
        lfs.mkdir( aPath )
    end

    aDirectory.path:gsub( '([^' .. File.separator .. ']+)', aMaker )
    
    return aDirectory
end

local function Save( aContent, aCount )
    local lfs = require( 'lfs' )
    local aCount = aCount or 0
    local aDirectory = MakeDirectory( aContent.name )
    local aLock = Lock( aContent.name )

    if lfs.lock( aLock, 'w' ) then
        local Data = require( 'Data' )
        local aFile = DataFile( aContent.name, aContent.version )
        local aData = Data( aContent.data )
        local aPath = ''
        
        WriteData( aFile.path, aData )
        
        PurgeVersion( aContent.name )
        
        lfs.unlock( aLock )
        aLock:close()
        
        return aContent
    end
    
    aLock:close()
    aCount = aCount + 1
    
    if aCount > 2 then
        error( ( 'Failed to lock %q' ):format( aContent.name ) )
    end
    
    return Save( aContent, aCount )
end

local function CanWrite( aName )
    local File = require( 'File' )
    local aDirectory = Directory( aName )
    local aFile = File( aDirectory.path, 'nowrite' )
    
    if aFile.exists then
        return false
    end
    
    return true
end

local function SetWrite( aName, aValue )
    local File = require( 'File' )
    local aDirectory = Directory( aName )
    local aFile = File( aDirectory.path, 'nowrite' )
    
    if aValue then
        aFile.delete = true
    else
        aFile.content = 'nowrite'
    end    
end

--------------------------------------------------------------------------------
-- File utilities
--------------------------------------------------------------------------------

local function FileDirectory( aName )
    local File = require( 'File' )
    local lfs = require( 'lfs' )
    local aDirectory = Directory( aName )
    local aFileDirectory = File( aDirectory.path, 'file' )
    
    lfs.mkdir( aFileDirectory.path )

    return aFileDirectory
end

local function FileIterator( aName )
    local aDirectory = FileDirectory( aName )
    
    return aDirectory()
end

local function AddFile( aName, aFile )
    if aFile and aFile.name:byte() ~= 46 then
        local File = require( 'File' )
        local aDirectory = FileDirectory( aName )
        local aFileExtension = aFile.extension
        local aFileName = aFile.name:sub( 1, aFile.name:len() - aFileExtension:len() - 1 )
        local aFileName = ( '%s.%s' ):format( Name( aFileName, 0 ), Name( aFileExtension, 0 ) )
        local aNewFile = File( aDirectory.path, aFileName )
        
        aNewFile.content = aFile.content
        aNewFile.modification = aFile.modification or os.time()
    end
end

--------------------------------------------------------------------------------
-- Link utilities
--------------------------------------------------------------------------------

local function LinkDirectory( aName )
    local File = require( 'File' )
    local lfs = require( 'lfs' )
    local aDirectory = Directory( aName )
    local aFileDirectory = File( aDirectory.path, 'link' )
    
    lfs.mkdir( aFileDirectory.path )

    return aFileDirectory
end

local function LinkIterator( aName )
    return Wiki.NameIterator( LinkDirectory( aName ) )
end

local function AddLink( aName, aLink )
    if aName ~= aLink then
        local File = require( 'File' )
        local lfs = require( 'lfs' )
        local aDirectory = LinkDirectory( aName )
        local aFile = File( aDirectory.path, ( '%s.id' ):format( aLink ) )
        
        lfs.mkdir( aFile.path )
        aFile.modification = os.time()
        
        Wiki.PurgeDirectory( aDirectory )
    end
end

--------------------------------------------------------------------------------
-- Metamethods
--------------------------------------------------------------------------------

local cache = setmetatable( {}, { __mode = 'v' } )

function meta:__call( aName, aVersion )
    local aName = Name( aName )

    if aName then
        local aVersion = aVersion or LastVersion( aName )
        local aKey = ( '%s;%d' ):format( aName, aVersion )
        local aContent = cache[ aKey ]
        
        if not aContent then
            aContent = { name = aName, version = aVersion }
            setmetatable( aContent, self )
            cache[ aKey ] = aContent
        end
        
        return aContent
    end
end

function meta:__index( aKey )
    return Name( aKey, 0 )
end

function self:__call()
    local aKey = ( '%s;%d' ):format( self.name, self.version )

    cache[ aKey ] = nil

    return Save( self )
end

function self:__index( aKey )
    if aKey == 'canWrite' then
        return CanWrite( self.name )
    elseif aKey == 'data' then
        local someData = ContentData( self.name, self.version )
        rawset( self, 'data', someData )
        
        return someData
    elseif aKey == 'directory' then
        return Directory( self.name )
    elseif aKey == 'exists' then
        return DataFile( self.name, self.version ).exists
    elseif aKey == 'file' then
        return FileIterator( self.name )
    elseif aKey == 'firstVersion' then
        return FirstVersion( self.name )
    elseif aKey == 'lastVersion' then
        return LastVersion( self.name )
    elseif aKey == 'link' then
        return LinkIterator( self.name )
    elseif aKey == 'lock' then
        return Lock( self.name )
    elseif aKey == 'modification' then
        return DataFile( self.name, self.version ).modification
    elseif aKey == 'prefix' then
        return table.concat( { Prefix( self.name ) } )
    elseif aKey == 'previousVersion' then
        return PreviousVersion( self.name, self.version )
    elseif aKey == 'title' and not rawget( self, 'data' ) then
        return Title( self.name )
    elseif aKey == 'versions' then
        return VersionIterator( self.name )
    end

    return self.data[ aKey ]
end

function self:__newindex( aKey, aValue )
    if aKey == 'canWrite' then
        return SetWrite( self.name, aValue )
    elseif aKey == 'file' then
        return AddFile( self.name, aValue )
    elseif aKey == 'link' then
        return AddLink( self.name, aValue )
    elseif aKey == 'modification' then
        DataFile( self.name, self.version ).modification = aValue
        
        return
    end

    self.data[ aKey ] = aValue
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
    return tostring( self.title )
end
