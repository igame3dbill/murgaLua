--------------------------------------------------------------------------------
-- Title:               WikiDiffService.lua
-- Description:         Like a square peg in a round hole
-- Author:              Raphaël Szwarc http://alt.textdrive.com/lua/
-- Creation Date:       January 30, 2007
-- Legal:               Copyright (C) 2007 Raphaël Szwarc
--                      Under the terms of the MIT License
--                      http://www.opensource.org/licenses/mit-license.html
--------------------------------------------------------------------------------

-- import dependencies
local HTTP = require( 'HTTP' )
local Template = require( 'Template' )
local WikiContent = require( 'WikiContent' )
local WikiService = require( 'WikiService' )

local BaseLink = WikiService.BaseLink
local DateLink = WikiService.DateLink
local FeedLink = WikiService.FeedLink
local IndexLink = WikiService.IndexLink

local Encode = WikiService.Encode
local Path = WikiService.Path

local os = require( 'os' )

local getfenv = getfenv
local getmetatable = getmetatable
local require = require
local setfenv = setfenv
local setmetatable = setmetatable
local tostring = tostring

--------------------------------------------------------------------------------
-- WikiDiffService
--------------------------------------------------------------------------------

module( 'WikiDiffService' )
_VERSION = '1.0'

local self = setmetatable( _M, {} )
local meta = getmetatable( self )

--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

local function Title( self, isLong )
    local aTitle = ''
    
    if isLong then
        aTitle = self.content.data.title
        aTitle = aTitle .. ' — '
    end
    
    aTitle = aTitle .. '№ '
    aTitle = aTitle .. self.content.version
    aTitle = aTitle .. ' Δ № '
    aTitle = aTitle .. self.version
    
    return aTitle
end

local function TitleHandler()
    local anEnvironment = {}
    local aFunction = function( aType, aValue )
        if aType == '+' then
            local anInsert = anEnvironment.insert or 0
            
            anEnvironment.insert = anInsert + 1
        
            return ( ' <ins>%s</ins> ' ):format( aValue )
        elseif aType == '-' then
            local aDelete = anEnvironment.delete or 0
            
            anEnvironment.delete = aDelete + 1

            return ( ' <del>%s</del> ' ):format( aValue )
        end
        
        return ( ' %s ' ):format( aValue )
    end
    
    setfenv( aFunction, anEnvironment )
    
    return aFunction
end

local function TextHandler()
    local anEnvironment = {}
    local aFunction = function( aType, aValue )
        if aType == '+' then
            local anInsert = anEnvironment.insert or 0
            
            anEnvironment.insert = anInsert + 1
        
            return ( '<p><ins>%s</ins></p>' ):format( aValue )
        elseif aType == '-' then
            local aDelete = anEnvironment.delete or 0
            
            anEnvironment.delete = aDelete + 1

            return ( '<p><del>%s</del></p>' ):format( aValue )
        end
        
        return ( '<p>%s</p>' ):format( aValue )
    end
    
    setfenv( aFunction, anEnvironment )
    
    return aFunction
end

local function Delta( aText, anotherText, aHandler, aPattern )
    local Diff = require( 'Diff' )
    local anEnvironment = getfenv( aHandler )
    local aDiff, hasMore = Diff( aText, anotherText, aHandler, aPattern ) 
    
    return aDiff, anEnvironment.insert or 0, anEnvironment.delete or 0, hasMore
end

local function Description( anInsert, aDelete, hasMore )
    local aCount = anInsert + aDelete

    if aCount > 0 then
        local aDescription = ''
        
        if hasMore then
            aDescription = aDescription .. 'Partial comparison. Around '
        end
        
        if aCount == 1 then
            aDescription = aDescription .. '1 difference: '
        elseif aCount > 1 then
            aDescription = aDescription .. aCount .. ' differences — '
        end

        if anInsert == 0 then
            aDescription = aDescription .. 'no insert and '
        elseif anInsert == 1 then
            aDescription = aDescription .. '1 insert and '
        elseif anInsert > 1 then
            aDescription = aDescription .. anInsert .. ' inserts and '
        end

        if aDelete == 0 then
            aDescription = aDescription .. 'no delete '
        elseif aDelete == 1 then
            aDescription = aDescription .. '1 delete '
        elseif aDelete > 1 then
            aDescription = aDescription .. aDelete .. ' deletes '
        end
        
        return aDescription
    end
    
    return 'No visible differences'
end

--------------------------------------------------------------------------------
-- Service methods
--------------------------------------------------------------------------------

function self:get()
    local aVersion = self.version
    
    if aVersion then
        local aNewContent = WikiContent( self.content.name, aVersion )
        
        if aNewContent.exists then
            local aLayoutTemplate = Template[ 'WikiLayout.txt' ]
            local aTemplate = Template[ 'WikiDiffService.txt' ]
            local aDate = os.date( '!*t', self.content.creation )
            local aDateLink = DateLink( aDate.year, aDate.month, aDate.day )
            local aTitle = Encode( self.content.data.title )
            local aNewTitle = Encode( aNewContent.data.title )
            local aTitleDelta, aTitleInsert, aTitleDelete = Delta( aTitle, aNewTitle, TitleHandler(), '([%S]+)' )
            local aText = Encode( self.content.text )
            local aNewText = Encode( aNewContent.text )
            local aTextDelta, aTextInsert, aTextDelete, hasMore = Delta( aText, aNewText, TextHandler() )
            local anInsert = aTitleInsert + aTextInsert
            local aDelete = aTitleDelete + aTextDelete
            
            aTemplate[ 'title' ] = aTitleDelta or Encode( self.content.data.title )
            aTemplate[ 'description' ] = Encode( Description( anInsert, aDelete, hasMore ) )
            aTemplate[ 'content' ] = aTextDelta or Encode( self.content.text ):gsub( '%c', '<br/>' )
    
            aLayoutTemplate[ 'baseLink' ] = Encode( BaseLink() )
            aLayoutTemplate[ 'indexLink' ] = Encode( IndexLink( self.content.prefix ) )
            aLayoutTemplate[ 'dateLink' ] = Encode( aDateLink )
            aLayoutTemplate[ 'feedLink' ] = FeedLink()
            aLayoutTemplate[ 'path' ] = Path( self )
            aLayoutTemplate[ 'query' ] = nil
            aLayoutTemplate[ 'robot' ] = 'noindex,nofollow'
            aLayoutTemplate[ 'title' ] = Encode( Title( self, true ) )
            aLayoutTemplate[ 'content' ] = aTemplate
        
            return tostring( aLayoutTemplate )
        end
        
        return nil
    end

    return nil, ( HTTP.request.url + ( 'n.' .. self.content.version ) ).path( 'n.' .. self.content.lastVersion )
end

--------------------------------------------------------------------------------
-- Metamethods
--------------------------------------------------------------------------------

function meta:__call( aContent, aParent, aVersion )
    local aDiff = { content = aContent, parent = aParent, version = aVersion }
    
    setmetatable( aDiff, self )
    self.__index = self    

    return aDiff
end

function self:__concat( aValue )
    return tostring( self ) .. tostring( aValue )
end

function self:__tostring()
    return Title( self, false )
end
