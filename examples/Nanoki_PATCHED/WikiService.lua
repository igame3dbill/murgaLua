--------------------------------------------------------------------------------
-- Title:               WikiService.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- import dependencies
local HTTP = require( 'HTTP' )

local os = require( 'os' )
local table = require( 'table' )

local getmetatable = getmetatable
local next = next
local pairs = pairs
local require = require
local select = select
local setmetatable = setmetatable
local tonumber = tonumber
local tostring = tostring
local type = type

--------------------------------------------------------------------------------
-- WikiService
--------------------------------------------------------------------------------

module( 'WikiService' )
_VERSION = '1.0'

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

function Capitalize( aValue )
    return ( tostring( aValue or '' ):lower():gsub( '(%l)([%w_\']*)', function( first, second ) return first:upper() .. second end ) )
end

function Encode( aValue )
    local anEncoder = function( aValue ) 
        return ( '&#%02d;' ):format( aValue:byte() ) 
    end
    
    return ( tostring( aValue or '' ):gsub( '([<>&\'"])', anEncoder ) )
end

function Trim( aValue )
    return ( tostring( aValue or '' ):gsub( '^[%c%s]+', '' ):gsub( '[%s%c]+$', '' ) )
end

--------------------------------------------------------------------------------
-- Name utilities
--------------------------------------------------------------------------------

function Names( anIterator )
    local NaturalComparator = require( 'NaturalComparator' )
    local aMap = {}
    local aList = {}
    local anIndex = 1
    local hasMore = false
    
    for aName in anIterator do
        aMap[ aName ] = true
        
        anIndex = anIndex + 1

        if anIndex == 1000 then
            hasMore = true
            break
        end
    end
    
    anIndex = 1
    
    for aName, aValue in pairs( aMap ) do
        aList[ anIndex ] = aName
        anIndex = anIndex + 1
    end
    
    table.sort( aList, NaturalComparator() )
    
    return aList, hasMore
end

function NameIterator( someNames )
    local HTTPExtra = require( 'HTTPExtra' )
    local HTTPService = require( 'HTTPService' )
    local WikiContent = require( 'WikiContent' )
    local WikiContentService = require( 'WikiContentService' )
    local aCount = #someNames
    local anIndex = 1
    
    return function()
        if anIndex <= aCount then
            local aName = someNames[ anIndex ]
            local aContent = WikiContent( aName )
            local aService = WikiContentService( aContent )
            local aURL = HTTPService[ aService ]
            
            anIndex = anIndex + 1
            
            return aContent, aURL
        end
    end
end

function ContentIterator( anIterator )
    local someNames, hasMore = Names( anIterator )
    
    return NameIterator( someNames ), #someNames, hasMore
end

function Description( aCount, hasMore )
    aCount = aCount or 0
    
    if aCount == 0 then
        return 'no item'
    elseif aCount == 1 then
        return '1 item'
    else
        local aDescription = ( '%d items' ):format( aCount )
        
        if hasMore then
            aDescription = 'over ' .. aDescription
        end
        
        return aDescription
    end
end

--------------------------------------------------------------------------------
-- Format utilities
--------------------------------------------------------------------------------

local suffixes = { 'st', 'nd', 'rd' }

local function Suffix( aNumber )
    local aSuffix = 'th'
    
    if aNumber ~= 11 and aNumber ~= 12 and aNumber ~= 13 then
        if aNumber > 9 then
            aNumber = aNumber % 10    
        end
        
        aSuffix = suffixes[ aNumber ] or aSuffix
    end
    
    return aSuffix
end

local function FormatDay( aDay )
    local aDay = tonumber( aDay )
    local aSuffix = Suffix( aDay )
    
    return ' ' .. aDay .. aSuffix .. ' '
end

function FormatDate( aTime )
    return os.date( '!%A, %B %d %Y', aTime ):gsub( '%s(%d%d)%s', FormatDay )
end

function FormatTime( aTime )
    return os.date( '!%I:%M %p', aTime ):gsub( '^0(%d)', '%1' )
end

function FormatDateTime( aTime )
    return ( '%s at %s' ):format( FormatDate( aTime), FormatTime( aTime ) )
end

function Today( aModification )
    local aModification = aModification or 0
    local aDate = os.date( '*t' )
    local aStartDate = { year = aDate.year, month = aDate.month, day = aDate.day, hour = 0, min = 0, sec = 0, isdst = aDate.isdst }
    local aStartTime = os.time( aStartDate )
    local anEndDate = { year = aDate.year, month = aDate.month, day = aDate.day, hour = 23, min = 59, sec = 59, isdst = aDate.isdst }
    local anEndTime = os.time( anEndDate )
    local isToday = aModification >= aStartTime and aModification <= anEndTime

    return isToday, aStartTime, anEndTime
end

function Yesterday( aModification )
    local _, aStartTime, anEndTime = Today( aModification )
    local aStartTime = aStartTime - 86400
    local anEndTime = anEndTime - 86400
    local isYesterday = aModification >= aStartTime and aModification <= anEndTime

    return isYesterday, aStartTime, anEndTime
end

function LastWeek( aModification )
    local _, aStartTime, anEndTime = Today( aModification )
    local aStartTime = aStartTime - ( 7 * 86400 )
    local isLastWeek = aModification >= aStartTime and aModification <= anEndTime
    
    return isLastWeek, aStartTime, anEndTime
end

--------------------------------------------------------------------------------
-- Content utilities
--------------------------------------------------------------------------------

function BaseLink()
    return HTTP.request.url + '/'
end

function FeedLink( aService, aCount )
    if aService and aCount and aCount > 0 then
        local aQuery = HTTP.request.url.query
        local aLink = tostring( aService.path )
        
        if not aLink:find( '%.xml$' ) then
            aLink = aLink .. '.xml'
        end
        
        aLink = Encode( aLink )
        
        if aQuery and next( aQuery ) then
            aLink = aLink .. '?' .. aQuery
        end
        
        return ( '<link rel=\'alternate\' type=\'application/atom+xml\' href=\'%s\'/>' ):format( aLink )
    end
end

function IndexLink( aPrefix )
    local HTTPExtra = require( 'HTTPExtra' )
    local HTTPService = require( 'HTTPService' )
    local WikiIndexService = require( 'WikiIndexService' )
    local aFirst, aSecond = ( aPrefix or '' ):match( '^(%w)(%w?)' )
    local aService = WikiIndexService( aFirst, aSecond )
    local aURL = HTTPService[ aService ]
    
    return aURL.path
end

function DateLink( aYear, aMonth, aDay )
    local HTTPExtra = require( 'HTTPExtra' )
    local HTTPService = require( 'HTTPService' )
    local WikiDateService = require( 'WikiDateService' )
    local aService = WikiDateService( aYear, aMonth, aDay )
    local aURL = HTTPService[ aService ]
    
    return aURL.path
end

function Path( aService, ... )
    local WikiPath = require( 'WikiPath' )
    local aPath = WikiPath()
    local aList = {}
    
    aList[ #aList + 1 ] = { href = aService.path, title = tostring( aService ) }
    aService = aService.parent
    
    for anIndex = 1, select( '#', ... ) do
        local aService = select( anIndex, ... )
        
        if aService then
            aList[ #aList + 1 ] = { href = aService.path, title = tostring( aService ) }
        end
    end

    while aService do
        aList[ #aList + 1 ] = { href = aService.path, title = tostring( aService ) }
        aService = aService.parent
    end

    for anIndex = #aList, 1, -1 do
        aPath[ #aPath + 1 ] = aList[ anIndex ]
    end
    
    return aPath
end

function HTML( aContent )
    local Cache = require( 'Cache' )
    local File = require( 'File' )
    local aTime = aContent.modification
    local aPath = aContent.directory.path
    local aFile = File( aPath, 'data.html' )
    local aContent = function()
        local markdown = require( 'markdown' )
        local aText = aContent.text
        
        if aText then
            return markdown( aText )
        end
    end
    
    return Cache( aFile.path, aContent, aTime )
end

function GetType( self, aType )
    local aMethod = 'get' .. Capitalize( aType or 'html' )
    
    if type( self[ aMethod ] ) == 'function' then
        return self[ aMethod ]( self )
    end
end

