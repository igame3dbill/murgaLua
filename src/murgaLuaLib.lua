local base = _G
local socket = require("socket")

--
-- Quick override to the FLTK functions
--

murgaLua__global = {}

function getMenu(self)
	if (murgaLua__global[self:serial()]) then
		return murgaLua__global[self:serial()].menu
	else
		return nil
	end
end

bind_lua_addtovtable(Fl_Menu_Item, 'getMenu', getMenu)

function setMenu(self, parentMenu)
	if (murgaLua__global[self:serial()]) then
		murgaLua__global[self:serial()].menu = parentMenu
	else
		murgaLua__global[self:serial()] = {menu = parentMenu}
	end
end

bind_lua_addtovtable(Fl_Menu_Item, 'setMenu', setMenu)

function getUserData(self, userData)
	key = self:serial()
	if (userData) then -- Set userdata
		if (murgaLua__global[key]) then
			murgaLua__global[key].user_data = userData
		else
			murgaLua__global[key] = {user_data = userData}
		end
	else -- Get userdata
		if (murgaLua__global[key]) then
			return murgaLua__global[key].user_data
		else
			return nil
		end
	end
end

bind_lua_addtovtable(Fl_Widget, 'user_data', getUserData)
bind_lua_addtovtable(Fl_Menu_Item, 'user_data', getUserData)

function add(self, label, shortcut, callback, userdata, flags)
	base.assert(label, "bad arguments in function call")
	menuItemIndex = self:add_overriden(label)
	menuItemInstance = self:menu(menuItemIndex)
	menuItemInstance:setMenu(self)
	if (shortcut) then self:shortcut(menuItemIndex, shortcut) end
	if (callback) then menuItemInstance:callback(callback) end
	if (userdata) then menuItemInstance:user_data(userdata) end
	if (flags) then self:mode(menuItemIndex, flags) end
	return menuItemIndex
end

bind_lua_addtovtable(Fl_Menu_, 'add', add)

module("murgaLua")

--
-- This is where interesting functions impleted in the lua language itself go.
--
-- The first two in the series are inspired by code I had seen at :
--  http://www.gammon.com.au/welcome.html
--


-- Nice table filter / copy function :-)

-- Basically provide a function that returns true when you want an item to
-- copied ... That way you can filter your table..

function filterTable (myTable, myFunction)

  -- Check your parameters
  base.assert (base.type (myTable) == "table")
  base.assert (base.type (myFunction) == "function")

  -- Work variables
  local myKey, myValue
  local resultTable = {}

  -- And then just a simple loop to perfom the filter/insert
  base.table.foreach(myTable, function (myKey, myValue)
    if myFunction (myValue) then
    resultTable[myKey] = myValue
 --     base.table.insert (resultTable, myValue)
 --     resultTable.__public[# resultTable] = myKey
    end
  end
  )
  
  -- Return the new table
  return resultTable
  
end

-- This is pretty much a copy of what I saw at the gammon web-site ...
-- Just a nice little debig print thing :-)

function printDebug (myTable, indent, done)
    done = done or {}
    indent = indent or 0
    if base.type(myTable) == "table" then
        for key, value in base.pairs (myTable) do
            base.io.write(base.string.rep (" ", indent)) -- indent it
            if base.type (value) == "table" and not done [value] then
              done [value] = true
              base.io.write(base.string.format("[%s] => table\n", base.tostring (key)));
              base.io.write(base.string.rep (" ", indent+4)) -- indent it
              base.io.write("(\n");
              printDebug (value, indent + 7, done)
              base.io.write(base.string.rep (" ", indent+4)) -- indent it
              base.io.write(")\n");
            else
              base.io.write(base.string.format("[%s] => %s\n", base.tostring (key),value))
            end
        end
    else
        base.io.write(myTable .. "\n")
    end
end

function findXmlNode (xmlTable, elementPath)
  currentNode = xmlTable
  
  for currentElement in base.string.gmatch(elementPath, "([^/]+)") do
    currentNode = findNextXmlNode(currentNode, currentElement)
    if not currentNode then break end
  end
  
  return currentNode
end

function findNextXmlNode (xmlTable, nodeName, instance)
  if not xmlTable.n then return nil end
  if not instance then instance = 1 end
  
  currentInstance = 1
  
  for counter=1,xmlTable.n do
    if (xmlTable[counter].name == nodeName) then
      if (currentInstance == instance) then
        return xmlTable[counter]
      end
      currentInstance = currentInstance + 1
    end 
  end
  
  return nil
end

function exportXml(xmlNode, outFile, indent)
  if not indent then indent=-4 end -- Big HACK
    
  if base.type(xmlNode) == "table" then
      exportXmlTable(xmlNode, outFile, indent)
  else
      exportXmlString(xmlNode, outFile, indent)
  end
end

function exportXmlTable(xmlNode, outFile, indent)

  endChars = ">\n"
  if (xmlNode.n == nil) then endChars = "/>\n" end
  
  if (xmlNode.name ~= nil) then
    outFile:write(base.string.rep (" ", indent) .. "<" .. xmlNode.name .. exportXmlAttrs(xmlNode.attr) .. endChars)
  end
  
  if (xmlNode.n ~= nil) then
    for counter=1,xmlNode.n do
      exportXml(xmlNode[counter], outFile, indent+4)
    end
  end
  
  if (xmlNode.name ~= nil and xmlNode.n ~= nil) then
    outFile:write(base.string.rep (" ", indent) .. "</" .. xmlNode.name .. ">\n")
  end
end

function exportXmlString(xmlNode, outFile, indent)
  if (base.string.find(xmlNode, "  ") or base.string.find(xmlNode, "\n")
      or base.string.find(xmlNode, "<") or base.string.find(xmlNode, "&")) then
    outFile:write(base.string.rep (" ", indent) .. "<![CDATA[" .. xmlNode .. "]]>\n")
  else
    outFile:write(base.string.rep (" ", indent) .. xmlNode .. "\n")
  end
end

function exportXmlAttrs(myTable, outFile)
  attrStr = ""
  if (myTable) then
    for key, value in base.pairs (myTable) do
      if (base.string.find(value, "\"") or base.string.find(value, "&")) then
        value = base.string.gsub(value, "&", "&amp;")
        value = base.string.gsub(value, "\"", "&quot;")
      end
      attrStr = attrStr .. " " .. key .. "=\"" .. value .. "\""
    end
  end
  
  return attrStr
end

-- This call is a clone of sleep that I created in the socket library
function sleep (milliseconds)
    socket.sleepMilliseconds(milliseconds)
end

-- This creates a dummy time control
function createFltkTimer()
    return base.fltk:Fl_murgaLuaTimer(0,0,0,0,"")
end

-- This creates an offscreen buffer
function createOffscreenBuffer(width, height)
    return base.fltk:Fl_murgaLuaOffScreen(width, height)
end

function compileMurgaLua (in_filename, in_executable, out_filename)

  base.print ("MurgaLua compiler 1.0")
  base.print ("=====================")
  
  inf  = base.io.open(in_executable,  "rb")
  outf = base.io.open(out_filename, "wb")
  
  outf:write(inf:read("*a"))
  
  endOfFile = outf:seek("end")
  
  outf:close()
  inf:close()
  
  base.print ("Loading core murgaLua executable ...")
  
  inf  = base.io.open(in_filename,  "rb")
  outf = base.io.open(out_filename, "ab")
  
  base.print ("Binding compressed code ...")
  -- Read, compress & write
  outf:write(base.lzo.compress(inf:read("*a")))

  base.print ("Writing executable stub info ...")
  -- Write executable information
  outf:write("_murgaLuaBinary_" .. base.string.format("%8i", endOfFile))
  
  outf:close()
  inf:close()

  base.print ("Done !!")
  
end

function decompileMurgaLua (in_filename, out_filename)

  if out_filename then
    base.print ("MurgaLua deCompiler 1.0")
    base.print ("=======================")
  end

	inf  = base.io.open(in_filename,  "rb")
	
	-- base.print("Filename " .. in_filename)
	-- Under Windows the executable may be invoked without a ".exe"
	if (getHostOsName() == "windows" and inf == nil) then
		inf  = base.io.open(in_filename .. ".exe",  "rb")
	end
	
	endOfFile = inf:seek("end")

	endOfFile = endOfFile - 24
	inf:seek("set", endOfFile)
	marker = inf:read("*line")

  if out_filename then
  	base.print("Looking for executable stub info at : " .. endOfFile)
  end

  if not marker then
    marker = ""
  end

	startOfLz = 0
	if (base.string.find(marker, "_murgaLuaBinary_")) then
	   startOfLz = base.string.sub(marker, 17)
	else
     if out_filename then
	     base.print ("No executable stub info found !!")
	   end
	   return
	end
	
	inf:seek("set", startOfLz)
	
	-- Read, de-compress & write
	programCode = base.lzo.decompress(inf:read("*a"));
	inf:close()
	
	if out_filename then
    base.print ("Writing original murgaLua source code ...")
  	outf = base.io.open(out_filename, "wb")
  	outf:write(programCode)
  	outf:close()
    base.print ("Done !!")
  else
    newFunc = base.loadstring(programCode)
    newFunc()
    base.os.exit()
  end
end

function roundNumber(num, idp)
  local mult = 10^(idp or 0)
  return base.math.floor(num * mult + 0.5) / mult
end

-- Taken from FL/Enumerations.H
function getFltkEventText(event)
	local events = {
	  "FL_NO_EVENT",
	  "FL_PUSH",
	  "FL_RELEASE",
	  "FL_ENTER",
	  "FL_LEAVE",
	  "FL_DRAG",
	  "FL_FOCUS",
	  "FL_UNFOCUS",
	  "FL_KEYDOWN",
	  "FL_KEYUP",
	  "FL_CLOSE",
	  "FL_MOVE",
	  "FL_SHORTCUT",
	  "FL_DEACTIVATE",
	  "FL_ACTIVATE",
	  "FL_HIDE",
	  "FL_SHOW",
	  "FL_PASTE",
	  "FL_SELECTIONCLEAR",
	  "FL_MOUSEWHEEL",
	  "FL_DND_ENTER",
	  "FL_DND_DRAG",
	  "FL_DND_LEAVE",
	  "FL_DND_RELEASE" }
	return(events[event+1])
end

-- Host OS name command should be concatenated here.
