
sym_scroll=fltk:Fl_Scroll(10,10,320,300)
--sym_scroll:box(fltk.FL_THIN_DOWN_FRAME)
fltk:Fl_End()

sym_pack=fltk:Fl_Pack(10,10,150,300)
fltk:Fl_End()

sym_pack2=fltk:Fl_Pack(160,10,150,300)
fltk:Fl_End()

sym_scroll:add(sym_pack)
sym_scroll:add(sym_pack2)

sym_buttons={}

for i=1,50 do
sym_buttons[i]=fltk:Fl_Box(0,0,150,30)
sym_buttons[i]:box(fltk.FL_THIN_UP_BOX)
sym_buttons[i]:align(20)
if i > 25 then
sym_pack2:add(sym_buttons[i])
else
sym_pack:add(sym_buttons[i])
end
end

sym_buttons[1]:label("@@->   @->")
sym_buttons[2]:label("@@>   @>")
sym_buttons[3]:label("@@>>   @>>")
sym_buttons[4]:label("@@>|   @>|")
sym_buttons[5]:label("@@>[]   @>[]")
sym_buttons[6]:label("@@|>   @|>")
sym_buttons[7]:label("@@<-   @<-")
sym_buttons[8]:label("@@<   @<")
sym_buttons[9]:label("@@<<   @<<")
sym_buttons[10]:label("@@|<   @|<")
sym_buttons[11]:label("@@[]<   @[]<")
sym_buttons[12]:label("@@<|   @<|")
sym_buttons[13]:label("@@<->   @<->")
sym_buttons[14]:label("@@-->   @-->")
sym_buttons[15]:label("@@+   @+")
sym_buttons[16]:label("@@->|   @->|")
sym_buttons[17]:label("@@||   @||")
sym_buttons[18]:label("@@arrow   @arrow")
sym_buttons[19]:label("@@returnarrow   @returnarrow")
sym_buttons[20]:label("@@square   @square")
sym_buttons[21]:label("@@circle   @circle")
sym_buttons[22]:label("@@line   @line")
sym_buttons[23]:label("@@menu   @menu")
sym_buttons[24]:label("@@UpArrow   @UpArrow")
sym_buttons[25]:label("@@DnArrow   @DnArrow")
sym_buttons[26]:label("@@$->|   @$->|")
sym_buttons[27]:label("@@%menu   @%menu")
sym_buttons[28]:label("@@9->   @9->")
sym_buttons[29]:label("@@8->   @8->")
sym_buttons[30]:label("@@7->   @7->")
sym_buttons[31]:label("@@4->   @4->")
sym_buttons[32]:label("@@1->   @1->")
sym_buttons[33]:label("@@2->   @2->")
sym_buttons[34]:label("@@3->   @3->")
sym_buttons[35]:label("@@7+   @7+")
sym_buttons[36]:label("@@+32->   @+32->")
sym_buttons[37]:label("@@+92->   @+92->")
sym_buttons[38]:label("@@+93->   @+93->")
sym_buttons[39]:label("@@-43->   @-43->")
sym_buttons[40]:label("@@-27->   @-27->")
sym_buttons[41]:label("@@+57line   @+57line")
sym_buttons[42]:label("@@-1square   @-1square")
sym_buttons[43]:label("@@-2square   @-2square")
sym_buttons[44]:label("@@-3square   @-3square")
sym_buttons[45]:label("@@-4square   @-4square")
sym_buttons[46]:label("@@-5square   @-5square")
sym_buttons[47]:label("@@-6square   @-6square")
sym_buttons[48]:label("@@-7square   @-7square")
sym_buttons[49]:label("@@-8square   @-8square")
sym_buttons[50]:label("@@-9square   @-9square")



