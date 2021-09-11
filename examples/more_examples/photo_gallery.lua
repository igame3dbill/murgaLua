-- Slideshow 
-- Based on code by mikshaw (http://damnsmalllinux.org/cgi-bin/forums/ikonboard.cgi)
pathToMurgaLua = string.gsub(murgaLua_ExePath,"(.*)/.*","%1") .. "/"
gameroot=pathToMurgaLua
-- will return correct path if cd to scripts path prior to running script
CurDir = lfs.currentdir() .. "/"
print(CurDir)
ww=400 --window width
wh=400 --window height
pw=ww-40 -- photo dims
ph=ww-160
sh=90 -- scroll height
images={}
inc=0
if lfs.attributes(CurDir.."images") ~= nil then
dir=CurDir.."Images/" -- ending slash is vital
else
dir=pathToMurgaLua.."Images/"
end

fltk.fl_register_images()

for file in lfs.dir(dir) do
dn,nd=string.find(file,"%.")
if dn > 2 and file ~= nil then 
print(file,dn,inc)
images[inc] = file
inc=inc+1
end
end


function scale_touchingBoundingRect(w,h,maxW,maxH)
  if math.max(w,h) == w then
    ratio = (maxW / w) 
  else 
    ratio = (maxH / h) 
  end
  if math.min(h*ratio,maxH) == maxH then
    ratio = (maxH / h) 
  end
  w,h = scale_ratio(w, h, ratio)
  return w,h
end

function scale_ratio(w, h, ratio)
  w,h = math.floor(w * ratio), math.floor(h * ratio)
  return w,h
end

function get_image_data(self)
  for i=0,table.getn(images) do
    if self:tooltip() == dir..images[i] then -- find the right image
      iw= icon[i]:w()
      ih = icon[i]:h()
      cw,ch=scale_touchingBoundingRect(iw,ih,pw,ph)
      display:image(icon[i]:copy(cw,ch)) --show it bigger!
      display_label:label(images[i].."\n"..icon[i]:w().."x"..icon[i]:h()) -- show height and width
      display:redraw()
      break
    end
  end
end

w=fltk:Fl_Window(ww,wh,"Photo Gallery")
w:color(55)

display=fltk:Fl_Box(15,15,pw+10,ph+10) -- big image
display_label=fltk:Fl_Box(20,20+ph,pw,40)
display_label:label("")
display:box(fltk.FL_BORDER_BOX)
display:color(55)

scroll_box=fltk:Fl_Scroll(15,300,pw+10,sh)
scroll_box:color(57)
scroll=fltk:Fl_Scroll(16,301,pw+8,sh-2)
scroll:type(1)
scroll:color(55)
pack=fltk:Fl_Pack(20,290,pw,sh)
pack:type(1)
pack:spacing(10)
icon={}; butt={}
row=1;col=1
-- since the images table contains more than just images (*.lnk gets in too)
-- i'm building the icons from specific items in the table.
for i=0,table.getn(images) do
if images[i] ~= nil then 
  if string.find(images[i],".png",-4,plain) or string.find (images[i],".jpg",-4,plain)
  then
    icon[i]=Fl_Shared_Image.get(dir..images[i])
    butt[i]=fltk:Fl_Button(0,0,80,80)
    butt[i]:align(fltk.FL_ALIGN_CLIP)
    cw,ch=scale_touchingBoundingRect(icon[i]:w(),icon[i]:h(),200,75)
    butt[i]:image(icon[i]:copy(cw,ch))
    butt[i]:tooltip(dir..images[i])
    butt[i]:callback(get_image_data)
    butt[i]:color(55)
    butt[i]:box(fltk.FL_NO_BOX)
  end
 end
end
w:show()
Fl:run()
