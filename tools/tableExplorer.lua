Fl:set_boxtype(fltk.FL_UP_BOX,fltk.FL_THIN_UP_BOX)
Fl:set_boxtype(fltk.FL_DOWN_BOX,fltk.FL_THIN_DOWN_BOX)

my_depth=0
my_level={}
my_title={}
my_line={}

-- text colors
col_tab="@b"
col_func="@C1"
col_str="@C4"
col_num="@C13"
col_usr="@C8@B17"
--col_thr="@C9"
--col_bool="@C5"

function lookittable()
  outpoot:clear()
  local my_value,my_string
  local tmptab={} -- temporary table for alphabetizing the list of my_string's
  for k,v in pairs(current_table) do
    my_value=tostring(k).."\t\t"..tostring(v)
    if     type(v)=="table" then my_string=col_tab..tostring(k)
    elseif type(v)=="function" then my_string=col_func..my_value
    elseif type(v)=="number" then my_string=col_num..my_value
    elseif type(v)=="userdata" then my_string=col_usr..my_value
    elseif type(v)=="string" then my_string=col_str..string.gsub(my_value,"\n"," %* ")
    --elseif type(v)=="thread" then my_string=col_thr..my_value
    --elseif type(v)=="boolean" then my_string=col_bool..my_value
    else my_string=tostring(k)
    end
    table.insert(tmptab,my_string)
  end
  table.sort(tmptab) -- alphabetize
  for i,v in ipairs(tmptab) do outpoot:add(v) end -- add the sorted list to the browser
  title:label(my_title[my_depth])
  if my_depth==0 then backbutt:deactivate() else backbutt:activate() end
  outpoot:middleline(my_line[my_depth])
end

function move_forward(k,v)
  my_depth=my_depth+1 -- move up a level
  my_level[my_depth]=current_table
  my_title[my_depth]=tostring(k).." ("..type(v)..")"
  my_line[my_depth]=1
  lookittable()
end

function move_back()
if my_depth > 0 then
  current_table=my_level[my_depth-1]
  my_depth=my_depth-1
  lookittable()
end
end

function which_is_it()
  local this_text=outpoot:text(outpoot:value())
  if outpoot:value() > 0 and type(current_table) == "table" then
    my_line[my_depth]=outpoot:value()
    -- Compare the browser text with each key in current_table until a match is found
    -- This could probably be streamlined
    for k,v in pairs(current_table) do
      -- it's a table
      if this_text == col_tab..tostring(k) then
        my_level[my_depth]=current_table --set a table to return to with "back"
        current_table=v
    move_forward(k,v)
        break
      end
--[[
      -- it's a string
      if string.find(this_text,"^"..col_str..tostring(k)) then
        print(v)
        break
      end
]]
      -- it's userdata
      if string.find(this_text,"^"..col_usr..tostring(k)) then
        my_level[my_depth]=current_table
        current_table=getmetatable(v)
    move_forward(k,v)
        break
      end
      -- it's a function
      if string.find(this_text,"^"..col_func..tostring(k))  then
        -- is there a way to get more useful info?
        my_level[my_depth]=current_table
        -- this test fixes a crash, but doesn't supply the right info
        if string.find(this_text,"which_is_it") then getinfo_level=1 else getinfo_level=v end
        current_table=debug.getinfo(getinfo_level,"nSlufL")
    move_forward(k,v)
        break
      end
    end
  end
end

ww=400
wh=360

w=fltk:Fl_Double_Window(ww,wh,"view murga tables")

outpoot=fltk:Fl_Select_Browser(10,40,ww-20,wh-50)
--outpoot:column_widths((ww-20)/2) -- not supported?
outpoot:selection_color(0)
outpoot:callback(which_is_it)

title=fltk:Fl_Box(90,10,ww-100,30)
title:box(fltk.FL_THIN_UP_BOX)

backbutt=fltk:Fl_Button(10,10,80,30,"@<- back")
backbutt:callback(move_back)

w:resizable(outpoot)
current_table=_G
my_title[my_depth]="Global Environment (table: _G)"
my_line[my_depth]=1
lookittable()
w:show()
Fl:run()
