--------------------------------------------------------------------------------
-- Title:               WikiDateNavigation.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- import dependencies
local HTTPService = require( 'HTTPService' )
local Template = require( 'Template' )
local WikiDate = require( 'WikiDate' )
local WikiDateService = require( 'WikiDateService' )
local WikiService = require( 'WikiService' )

local FormatDate = WikiService.FormatDate

local os = require( 'os' )

local getmetatable = getmetatable
local ipairs = ipairs
local mod = math.mod
local setmetatable = setmetatable
local tostring = tostring

--------------------------------------------------------------------------------
-- WikiDateNavigation
--------------------------------------------------------------------------------

module( 'WikiDateNavigation' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

local lengths = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }

local function IsLeap( aYear )
    return ( ( mod( aYear, 4 ) == 0 ) and ( mod( aYear, 100 ) ~= 0 ) ) or ( mod( aYear, 400 ) == 0 )
end

local function MonthLength( aDate )
    local aLength = lengths[ aDate.month ]
    
    if aDate.month == 2 and IsLeap( aDate.year ) then
        aLength = aLength + 1
    end
    
    return aLength
end

local function Years()
    local thisYear = os.date( '!*t' ).year
    local aList = {} 

    for aYear = thisYear - 11, thisYear do
        aList[ #aList + 1 ] = aYear
    end
    
    return aList
end

local function Values()
    return 
    {
        Years(),
        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 },
        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 },
        { 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 },
        { 25, 26, 27, 28, 29, 30, 31, 0, 0, 0, 0, 0 }
    }
end

local function HasValue( anIterator, aValue )
    for aLocalValue in anIterator do
        if aLocalValue == aValue then
            return true
        end
    end
    
    return false
end

local function FormatYear( aDate, aValue )
    local aLocalDate = { year = aValue, month = 1, day = 1 }
    local aFormat = os.date( '!\'%y', os.time( aLocalDate ) )
    local isCurrent = aDate.year == aValue
    local firstYear = WikiDate()() or 0
    
    if HasValue( WikiDate(), aValue ) then
        aLocalDate.month = nil
        aLocalDate.day = nil
    else
        aLocalDate = nil
    end
    
    if aValue < firstYear then
        aFormat = nil
    end
    
    return aFormat, aLocalDate, isCurrent
end

local function FormatMonth( aDate, aValue )
    local aLocalDate = { year = aDate.year, month = aValue, day = 1 }
    local aFormat = os.date( '!%b', os.time( aLocalDate ) )
    local isCurrent = aDate.month == aValue

    if HasValue( WikiDate( { year = aDate.year } ), aValue ) then
        aLocalDate.day = nil
    else
        aLocalDate = nil
    end

    return aFormat, aLocalDate, isCurrent
end

local function FormatDay( aDate, aValue )
    local aLocalDate = { year = aDate.year, month = aDate.month or 1, day = aValue }
    local aLength = MonthLength( aLocalDate )
    local isCurrent = aDate.day == aValue
    
    if aValue < 1 or aValue > aLength then
        aValue = nil
        aLocalDate = nil
        isCurrent = false
    end
    
    if not HasValue( WikiDate( { year = aDate.year, month = aDate.month or 1 } ), aValue ) then
        aLocalDate = nil
    end
    
    return aValue, aLocalDate, isCurrent
end

local types = { 'year', 'month', 'day', 'day', 'day' }
local formats = { year = FormatYear, month = FormatMonth, day =  FormatDay }

local function Title( aYear, aMonth, aDay )
    local aTime = os.time( { year = aYear or 1, month = aMonth or 1, day = aDay or 1 } )
    local aFormat = nil
    
    if aDay then
        return FormatDate( aTime )
    elseif aMonth then
        aFormat = '!%B %Y'
    else
        aFormat = '!%Y'
    end
    
    return os.date( aFormat, aTime )
end

local function FormatValue( aType, aDate, aValue )
    local aValue, aDate, isCurrent = formats[ aType ]( aDate, aValue )

    if aValue and isCurrent then
        aValue = ( '<b>%s</b>' ):format( aValue )
    end
    
    if aValue and aDate then
        local aService = WikiDateService( aDate.year, aDate.month, aDate.day )
        local anURL = HTTPService[ aService ]
        local aPath = tostring( anURL.path )
        local aTitle = Title( aDate.year, aDate.month, aDate.day )

        aValue = ( '<a href=\'%s\' title=\'%s\'>%s</a>' ):format( aPath, aTitle, aValue )
    end
        
    return aValue or '&nbsp;'
end

--------------------------------------------------------------------------------
-- Metamethods
--------------------------------------------------------------------------------

function meta:__call( aDate )
    local aNavigation = { date = aDate }

    setmetatable( aNavigation, self )

    return aNavigation
end

function self:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function self:__tostring()
    local aTemplate = Template[ 'WikiNavigation.txt' ]
    local someValues = Values()
    local aDate = self.date
    
    for aRowIndex, aRowValue in ipairs( someValues ) do
        local aRowTemplate = aTemplate[ 'rows' ]
        local aRowType = types[ aRowIndex ]
        
        for aColumnIndex, aColumnValue in ipairs( aRowValue ) do
            local aColumnTemplate = aRowTemplate[ 'columns' ]
            
            aColumnTemplate[ 'value' ] = FormatValue( aRowType, aDate, aColumnValue )
            
            aRowTemplate[ 'columns' ] = aColumnTemplate
        end

        aTemplate[ 'rows' ] = aRowTemplate
    end

    return tostring( aTemplate )
end


