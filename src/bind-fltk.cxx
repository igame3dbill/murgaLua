/*

  murgaLua
  Copyright (C) 2006-2008 John Murga
  
  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the :
  
    Free Software Foundation, Inc.
    51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
  
*/


#ifdef __cplusplus
extern "C" {
#endif

#include <lua.h>
#include <lauxlib.h>

#ifdef __cplusplus
}
#endif

#include "png.h"

bool saveRgbAsPng( const uchar *pixels, int w, int h, int d, const char *filename )
{   
    FILE *fp = fopen( filename, "wb" );
    if( fp == NULL ) {
        return false;
    }

    // write png header information
    png_structp pp = png_create_write_struct(PNG_LIBPNG_VER_STRING, 0, 0, 0);
    png_infop info = png_create_info_struct(pp);
    png_init_io(pp, fp);
    png_set_compression_level(pp, Z_BEST_COMPRESSION);
    png_set_IHDR( pp, info, w, h, 8, d == 1 ? PNG_COLOR_TYPE_GRAY : PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
    png_write_info(pp, info);
    
    // write pixels
    for( int y=0; y < h; y++ )
        png_write_row( pp, (png_byte *) pixels + d*y*w );
 
    png_write_end(pp, info);
    png_destroy_write_struct(&pp, 0);
    fclose(fp);
    
    return true;
}


typedef struct lua_type_t lua_type_t;
struct lua_type_t {
  const char * name;
};


/* End of template 1
 */
  lua_type_t type__Fl_Awake_Handler;
  lua_type_t type__Fl;
  lua_type_t type__float;
  lua_type_t type__Fl_Damage;
  lua_type_t type__void;
  lua_type_t type__Fl_Help_Dialog;
  lua_type_t type__Fl_Text_Display__Style_Table_Entry;
  lua_type_t type__Fl_Callback1;
  lua_type_t type__Fl_End;
  lua_type_t type__Fl_Text_Display__Unfinished_Style_Cb;
  lua_type_t type__Fl_Callback;
  lua_type_t type__Fl_Browser__Fl_Line_Position;
  lua_type_t type__Fl_Menu;
  lua_type_t type__wchar_t;
  lua_type_t type__Fl_Widget;
  lua_type_t type__Fl_Labeltype;
  lua_type_t type__Fl_Color;
  lua_type_t type__Fl_Label_Draw_F;
  lua_type_t type__Fl_Box_Draw_F;
  lua_type_t type__Fl_Cursor;
  lua_type_t type__Fl_Boxtype;
  lua_type_t type__Fl_When;
  lua_type_t type__Fl_Align;
  lua_type_t type__Fl_Event;
  lua_type_t type__Fl_Draw_Image_Cb;
  lua_type_t type__Fl_Shared_Handler;
  lua_type_t type__FL_CHART_ENTRY;
  lua_type_t type__FL_BLINE;
  lua_type_t type__double;
  lua_type_t type__Fl_Menu_Item;
  lua_type_t type__Fl_Mode;
  lua_type_t type__short;
  lua_type_t type__bool;
  lua_type_t type__Fl_murgaLuaOffScreen;
  lua_type_t type__Fl_Font;
  lua_type_t type__Fl_Timeout_Handler;
  lua_type_t type__long;
  lua_type_t type__Fl_Label;
  lua_type_t type____builtin_va_list;
  lua_type_t type__Fl_Callback_p;
  lua_type_t type__Fl_Preferences__Root;
  lua_type_t type__Fl_Preferences__Name;
  lua_type_t type__Fl_Callback0;
  lua_type_t type__Fl_File_Sort_F;
  lua_type_t type__Fl_Check_Browser__cb_item;
  lua_type_t type__Fl_File_Icon;
  lua_type_t type__Fl_Preferences__Entry;
  lua_type_t type__Fl_Label_Measure_F;
  lua_type_t type__int;
  lua_type_t type__Fl_File_Chooser;
  lua_type_t type__Fl_Preferences;
  lua_type_t type__Fl_Image;
  lua_type_t type__Fl_Help_Func;
  lua_type_t type__main_namespace;
  lua_type_t type__Fl_Help_Block;
  lua_type_t type__Fl_Text_Buffer;
  lua_type_t type__Fl_Tooltip;
  lua_type_t type__Fl_Text_Selection;
  lua_type_t type__Fl_Text_Modify_Cb;
  lua_type_t type__Fl_Text_Editor__Key_Binding;
  lua_type_t type__Fl_Multi_Label;
  lua_type_t type__Fl_Text_Editor__Key_Func;
  lua_type_t type__Fl_Text_Predelete_Cb;
  lua_type_t type__char;
  lua_type_t type__Fl_Offscreen;
  lua_type_t type__Fl_Region;
  lua_type_t type__Fl_Help_Target;
  lua_type_t type__Fl_Bitmask;
  lua_type_t type__Fl_Help_Link;
  lua_type_t type__Fl_Box;
  lua_type_t type__Fl_Shared_Image;
  lua_type_t type__Fl_Progress;
  lua_type_t type__Fl_Group;
  lua_type_t type__Fl_Timer;
  lua_type_t type__Fl_Chart;
  lua_type_t type__Fl_murgaLuaTimer;
  lua_type_t type__Fl_Menu_;
  lua_type_t type__Fl_Button;
  lua_type_t type__Fl_Valuator;
  lua_type_t type__Fl_Positioner;
  lua_type_t type__Fl_Input_;
  lua_type_t type__Fl_FormsBitmap;
  lua_type_t type__Fl_Clock_Output;
  lua_type_t type__Fl_FormsPixmap;
  lua_type_t type__Fl_Tiled_Image;
  lua_type_t type__Fl_RGB_Image;
  lua_type_t type__Fl_Pixmap;
  lua_type_t type__Fl_Bitmap;
  lua_type_t type__Fl_Toggle_Button;
  lua_type_t type__Fl_Value_Output;
  lua_type_t type__Fl_Return_Button;
  lua_type_t type__Fl_Counter;
  lua_type_t type__Fl_PNG_Image;
  lua_type_t type__Fl_Radio_Button;
  lua_type_t type__Fl_Scroll;
  lua_type_t type__Fl_Window;
  lua_type_t type__Fl_Color_Chooser;
  lua_type_t type__Fl_Input;
  lua_type_t type__Fl_Menu_Bar;
  lua_type_t type__Fl_PNM_Image;
  lua_type_t type__Fl_Adjuster;
  lua_type_t type__Fl_Dial;
  lua_type_t type__Fl_BMP_Image;
  lua_type_t type__Fl_Menu_Button;
  lua_type_t type__Fl_GIF_Image;
  lua_type_t type__Fl_XPM_Image;
  lua_type_t type__Fl_Input_Choice;
  lua_type_t type__Fl_Help_View;
  lua_type_t type__Fl_Wizard;
  lua_type_t type__Fl_Slider;
  lua_type_t type__Fl_Choice;
  lua_type_t type__Fl_XBM_Image;
  lua_type_t type__Fl_Clock;
  lua_type_t type__Fl_Spinner;
  lua_type_t type__Fl_JPEG_Image;
  lua_type_t type__Fl_Browser_;
  lua_type_t type__Fl_Tile;
  lua_type_t type__Fl_Text_Display;
  lua_type_t type__Fl_Pack;
  lua_type_t type__Fl_Repeat_Button;
  lua_type_t type__Fl_Light_Button;
  lua_type_t type__Fl_Roller;
  lua_type_t type__Fl_Tabs;
  lua_type_t type__Fl_Value_Input;
  lua_type_t type__Fl_Nice_Slider;
  lua_type_t type__Fl_Fill_Dial;
  lua_type_t type__Fl_Browser;
  lua_type_t type__Fl_Radio_Light_Button;
  lua_type_t type__Fl_Single_Window;
  lua_type_t type__Fl_Multiline_Input;
  lua_type_t type__Fl_Output;
  lua_type_t type__Fl_Round_Button;
  lua_type_t type__Fl_Scrollbar;
  lua_type_t type__Fl_Secret_Input;
  lua_type_t type__Fl_Value_Slider;
  lua_type_t type__Fl_Hor_Slider;
  lua_type_t type__Fl_Check_Button;
  lua_type_t type__Fl_Fill_Slider;
  lua_type_t type__Fl_Int_Input;
  lua_type_t type__Fl_File_Input;
  lua_type_t type__Fl_Check_Browser;
  lua_type_t type__Fl_Simple_Counter;
  lua_type_t type__Fl_Line_Dial;
  lua_type_t type__Fl_Double_Window;
  lua_type_t type__Fl_Round_Clock;
  lua_type_t type__Fl_Float_Input;
  lua_type_t type__Fl_Text_Editor;
  lua_type_t type__Fl_Hor_Fill_Slider;
  lua_type_t type__Fl_Hor_Nice_Slider;
  lua_type_t type__Fl_Multi_Browser;
  lua_type_t type__Fl_File_Browser;
  lua_type_t type__Fl_Overlay_Window;
  lua_type_t type__Fl_Radio_Round_Button;
  lua_type_t type__Fl_Menu_Window;
  lua_type_t type__Fl_Select_Browser;
  lua_type_t type__Fl_Hold_Browser;
  lua_type_t type__Fl_Multiline_Output;
  lua_type_t type__Fl_Hor_Value_Slider;
/* Start of template 2 */


#define lua_fltk_dostring(L, s, info) do { const char * buf = s; lua_dobuffer(L, buf, strlen(buf), info); } while (0)


static char * badargs_error = "bad arguments in function call";



/* this exists in lua 5.1 but not lua 5.0 */
static void _lua_setfield(lua_State * __S__, int p, const char * idx)
{
  if (p < 0) p--;
  lua_pushstring(__S__, idx);
  lua_pushvalue(__S__, -2);
  lua_remove(__S__, -3);
  lua_settable(__S__, p);
}


static void _lua_push_class(lua_State * __S__, 
			    void * __PTR__, lua_type_t * type)
{
  if (__PTR__) {
    void * * u = (void * *) lua_newuserdata(__S__, sizeof(void *));
    luaL_getmetatable(__S__, type->name);
    lua_setmetatable(__S__, -2);
    *u = __PTR__;
  } else
    lua_pushnil(__S__);
}

static void * _lua_to_class(lua_State * __S__, int pos, int * __ERROR__, lua_type_t * wanted_type)
{
  int iscompat;
  {
    if (!lua_getmetatable(__S__, pos))
      goto error;
    lua_pushlightuserdata(__S__, wanted_type);
    lua_gettable(__S__, -2);
    iscompat = !lua_isnil(__S__, -1);
    lua_pop(__S__, 2);
    if (iscompat)
      return *(void * *)lua_touserdata(__S__, pos);
  error:
/*     printf("bind-lua : could not cast from %s to %s !\n",  */
/* 	   tn, wanted_type->name); */
    *__ERROR__ = -1;
    return 0;
  }
}

static int lua_settable_tagmethod(lua_State * S)
{
  lua_pushvalue(S, 2);
  lua_gettable(S, lua_upvalueindex(1));
  lua_pushvalue(S, 1);
  lua_pushvalue(S, 3);
  lua_call(S, 2, 0);
  return 0;
}

static int lua_gettable_tagmethod_f(lua_State * S)
{
  lua_remove(S, 1);
  lua_gettable(S, lua_upvalueindex(1));
  return 1;
}

static int lua_gettable_tagmethod_v(lua_State * S)
{
  lua_gettable(S, lua_upvalueindex(1));
  lua_pushvalue(S, 1);
  lua_remove(S, 1);
  lua_call(S, 1, 1);
  return 1;
}

static int lua_gettable_tagmethod_fv(lua_State * S)
{
  lua_pushvalue(S, 2);
  lua_gettable(S, lua_upvalueindex(2));
  if (lua_isnil(S, 3)) {
    lua_remove(S, 3);
    lua_gettable(S, lua_upvalueindex(1));
  } else {
    lua_remove(S, 2);
    lua_pushvalue(S, 1);
    lua_remove(S, 1);
    lua_call(S, 1, 1);
  }
  return 1;
}


/* End of template 2
 */
#define lua_push_Fl(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl)
#define lua_to_Fl(__S__, pos, __ERROR__) \
((Fl *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl))
#define lua_push_Fl_Help_Dialog(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Help_Dialog)
#define lua_to_Fl_Help_Dialog(__S__, pos, __ERROR__) \
((Fl_Help_Dialog *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Help_Dialog))
#define lua_push_Fl_Text_Display__Style_Table_Entry(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Text_Display__Style_Table_Entry)
#define lua_to_Fl_Text_Display__Style_Table_Entry(__S__, pos, __ERROR__) \
((Fl_Text_Display::Style_Table_Entry *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Text_Display__Style_Table_Entry))
#define lua_push_Fl_End(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_End)
#define lua_to_Fl_End(__S__, pos, __ERROR__) \
((Fl_End *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_End))
#define lua_push_Fl_Menu(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Menu)
#define lua_to_Fl_Menu(__S__, pos, __ERROR__) \
((Fl_Menu *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Menu))
#define lua_push_Fl_Widget(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Widget)
#define lua_to_Fl_Widget(__S__, pos, __ERROR__) \
((Fl_Widget *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Widget))
#define lua_push_FL_CHART_ENTRY(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__FL_CHART_ENTRY)
#define lua_to_FL_CHART_ENTRY(__S__, pos, __ERROR__) \
((FL_CHART_ENTRY *) _lua_to_class(__S__, pos, __ERROR__, &type__FL_CHART_ENTRY))
#define lua_push_FL_BLINE(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__FL_BLINE)
#define lua_to_FL_BLINE(__S__, pos, __ERROR__) \
((FL_BLINE *) _lua_to_class(__S__, pos, __ERROR__, &type__FL_BLINE))
#define lua_push_Fl_Menu_Item(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Menu_Item)
#define lua_to_Fl_Menu_Item(__S__, pos, __ERROR__) \
((Fl_Menu_Item *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Menu_Item))
#define lua_push_Fl_murgaLuaOffScreen(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_murgaLuaOffScreen)
#define lua_to_Fl_murgaLuaOffScreen(__S__, pos, __ERROR__) \
((Fl_murgaLuaOffScreen *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_murgaLuaOffScreen))
#define lua_push_Fl_Label(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Label)
#define lua_to_Fl_Label(__S__, pos, __ERROR__) \
((Fl_Label *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Label))
#define lua_push_Fl_Preferences__Name(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Preferences__Name)
#define lua_to_Fl_Preferences__Name(__S__, pos, __ERROR__) \
((Fl_Preferences::Name *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Preferences__Name))
#define lua_push_Fl_Check_Browser__cb_item(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Check_Browser__cb_item)
#define lua_to_Fl_Check_Browser__cb_item(__S__, pos, __ERROR__) \
((Fl_Check_Browser::cb_item *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Check_Browser__cb_item))
#define lua_push_Fl_File_Icon(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_File_Icon)
#define lua_to_Fl_File_Icon(__S__, pos, __ERROR__) \
((Fl_File_Icon *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_File_Icon))
#define lua_push_Fl_Preferences__Entry(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Preferences__Entry)
#define lua_to_Fl_Preferences__Entry(__S__, pos, __ERROR__) \
((Fl_Preferences::Entry *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Preferences__Entry))
#define lua_push_Fl_File_Chooser(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_File_Chooser)
#define lua_to_Fl_File_Chooser(__S__, pos, __ERROR__) \
((Fl_File_Chooser *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_File_Chooser))
#define lua_push_Fl_Preferences(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Preferences)
#define lua_to_Fl_Preferences(__S__, pos, __ERROR__) \
((Fl_Preferences *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Preferences))
#define lua_push_Fl_Image(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Image)
#define lua_to_Fl_Image(__S__, pos, __ERROR__) \
((Fl_Image *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Image))
#define lua_push_Fl_Help_Block(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Help_Block)
#define lua_to_Fl_Help_Block(__S__, pos, __ERROR__) \
((Fl_Help_Block *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Help_Block))
#define lua_push_Fl_Text_Buffer(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Text_Buffer)
#define lua_to_Fl_Text_Buffer(__S__, pos, __ERROR__) \
((Fl_Text_Buffer *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Text_Buffer))
#define lua_push_Fl_Tooltip(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Tooltip)
#define lua_to_Fl_Tooltip(__S__, pos, __ERROR__) \
((Fl_Tooltip *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Tooltip))
#define lua_push_Fl_Text_Selection(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Text_Selection)
#define lua_to_Fl_Text_Selection(__S__, pos, __ERROR__) \
((Fl_Text_Selection *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Text_Selection))
#define lua_push_Fl_Text_Editor__Key_Binding(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Text_Editor__Key_Binding)
#define lua_to_Fl_Text_Editor__Key_Binding(__S__, pos, __ERROR__) \
((Fl_Text_Editor::Key_Binding *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Text_Editor__Key_Binding))
#define lua_push_Fl_Multi_Label(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Multi_Label)
#define lua_to_Fl_Multi_Label(__S__, pos, __ERROR__) \
((Fl_Multi_Label *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Multi_Label))
#define lua_push_Fl_Help_Target(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Help_Target)
#define lua_to_Fl_Help_Target(__S__, pos, __ERROR__) \
((Fl_Help_Target *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Help_Target))
#define lua_push_Fl_Help_Link(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Help_Link)
#define lua_to_Fl_Help_Link(__S__, pos, __ERROR__) \
((Fl_Help_Link *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Help_Link))
#define lua_push_Fl_Box(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Box)
#define lua_to_Fl_Box(__S__, pos, __ERROR__) \
((Fl_Box *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Box))
#define lua_push_Fl_Shared_Image(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Shared_Image)
#define lua_to_Fl_Shared_Image(__S__, pos, __ERROR__) \
((Fl_Shared_Image *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Shared_Image))
#define lua_push_Fl_Progress(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Progress)
#define lua_to_Fl_Progress(__S__, pos, __ERROR__) \
((Fl_Progress *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Progress))
#define lua_push_Fl_Group(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Group)
#define lua_to_Fl_Group(__S__, pos, __ERROR__) \
((Fl_Group *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Group))
#define lua_push_Fl_Timer(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Timer)
#define lua_to_Fl_Timer(__S__, pos, __ERROR__) \
((Fl_Timer *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Timer))
#define lua_push_Fl_Chart(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Chart)
#define lua_to_Fl_Chart(__S__, pos, __ERROR__) \
((Fl_Chart *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Chart))
#define lua_push_Fl_murgaLuaTimer(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_murgaLuaTimer)
#define lua_to_Fl_murgaLuaTimer(__S__, pos, __ERROR__) \
((Fl_murgaLuaTimer *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_murgaLuaTimer))
#define lua_push_Fl_Menu_(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Menu_)
#define lua_to_Fl_Menu_(__S__, pos, __ERROR__) \
((Fl_Menu_ *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Menu_))
#define lua_push_Fl_Button(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Button)
#define lua_to_Fl_Button(__S__, pos, __ERROR__) \
((Fl_Button *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Button))
#define lua_push_Fl_Valuator(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Valuator)
#define lua_to_Fl_Valuator(__S__, pos, __ERROR__) \
((Fl_Valuator *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Valuator))
#define lua_push_Fl_Positioner(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Positioner)
#define lua_to_Fl_Positioner(__S__, pos, __ERROR__) \
((Fl_Positioner *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Positioner))
#define lua_push_Fl_Input_(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Input_)
#define lua_to_Fl_Input_(__S__, pos, __ERROR__) \
((Fl_Input_ *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Input_))
#define lua_push_Fl_FormsBitmap(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_FormsBitmap)
#define lua_to_Fl_FormsBitmap(__S__, pos, __ERROR__) \
((Fl_FormsBitmap *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_FormsBitmap))
#define lua_push_Fl_Clock_Output(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Clock_Output)
#define lua_to_Fl_Clock_Output(__S__, pos, __ERROR__) \
((Fl_Clock_Output *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Clock_Output))
#define lua_push_Fl_FormsPixmap(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_FormsPixmap)
#define lua_to_Fl_FormsPixmap(__S__, pos, __ERROR__) \
((Fl_FormsPixmap *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_FormsPixmap))
#define lua_push_Fl_Tiled_Image(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Tiled_Image)
#define lua_to_Fl_Tiled_Image(__S__, pos, __ERROR__) \
((Fl_Tiled_Image *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Tiled_Image))
#define lua_push_Fl_RGB_Image(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_RGB_Image)
#define lua_to_Fl_RGB_Image(__S__, pos, __ERROR__) \
((Fl_RGB_Image *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_RGB_Image))
#define lua_push_Fl_Pixmap(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Pixmap)
#define lua_to_Fl_Pixmap(__S__, pos, __ERROR__) \
((Fl_Pixmap *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Pixmap))
#define lua_push_Fl_Bitmap(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Bitmap)
#define lua_to_Fl_Bitmap(__S__, pos, __ERROR__) \
((Fl_Bitmap *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Bitmap))
#define lua_push_Fl_Toggle_Button(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Toggle_Button)
#define lua_to_Fl_Toggle_Button(__S__, pos, __ERROR__) \
((Fl_Toggle_Button *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Toggle_Button))
#define lua_push_Fl_Value_Output(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Value_Output)
#define lua_to_Fl_Value_Output(__S__, pos, __ERROR__) \
((Fl_Value_Output *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Value_Output))
#define lua_push_Fl_Return_Button(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Return_Button)
#define lua_to_Fl_Return_Button(__S__, pos, __ERROR__) \
((Fl_Return_Button *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Return_Button))
#define lua_push_Fl_Counter(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Counter)
#define lua_to_Fl_Counter(__S__, pos, __ERROR__) \
((Fl_Counter *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Counter))
#define lua_push_Fl_PNG_Image(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_PNG_Image)
#define lua_to_Fl_PNG_Image(__S__, pos, __ERROR__) \
((Fl_PNG_Image *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_PNG_Image))
#define lua_push_Fl_Radio_Button(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Radio_Button)
#define lua_to_Fl_Radio_Button(__S__, pos, __ERROR__) \
((Fl_Radio_Button *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Radio_Button))
#define lua_push_Fl_Scroll(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Scroll)
#define lua_to_Fl_Scroll(__S__, pos, __ERROR__) \
((Fl_Scroll *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Scroll))
#define lua_push_Fl_Window(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Window)
#define lua_to_Fl_Window(__S__, pos, __ERROR__) \
((Fl_Window *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Window))
#define lua_push_Fl_Color_Chooser(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Color_Chooser)
#define lua_to_Fl_Color_Chooser(__S__, pos, __ERROR__) \
((Fl_Color_Chooser *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Color_Chooser))
#define lua_push_Fl_Input(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Input)
#define lua_to_Fl_Input(__S__, pos, __ERROR__) \
((Fl_Input *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Input))
#define lua_push_Fl_Menu_Bar(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Menu_Bar)
#define lua_to_Fl_Menu_Bar(__S__, pos, __ERROR__) \
((Fl_Menu_Bar *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Menu_Bar))
#define lua_push_Fl_PNM_Image(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_PNM_Image)
#define lua_to_Fl_PNM_Image(__S__, pos, __ERROR__) \
((Fl_PNM_Image *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_PNM_Image))
#define lua_push_Fl_Adjuster(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Adjuster)
#define lua_to_Fl_Adjuster(__S__, pos, __ERROR__) \
((Fl_Adjuster *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Adjuster))
#define lua_push_Fl_Dial(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Dial)
#define lua_to_Fl_Dial(__S__, pos, __ERROR__) \
((Fl_Dial *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Dial))
#define lua_push_Fl_BMP_Image(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_BMP_Image)
#define lua_to_Fl_BMP_Image(__S__, pos, __ERROR__) \
((Fl_BMP_Image *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_BMP_Image))
#define lua_push_Fl_Menu_Button(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Menu_Button)
#define lua_to_Fl_Menu_Button(__S__, pos, __ERROR__) \
((Fl_Menu_Button *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Menu_Button))
#define lua_push_Fl_GIF_Image(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_GIF_Image)
#define lua_to_Fl_GIF_Image(__S__, pos, __ERROR__) \
((Fl_GIF_Image *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_GIF_Image))
#define lua_push_Fl_XPM_Image(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_XPM_Image)
#define lua_to_Fl_XPM_Image(__S__, pos, __ERROR__) \
((Fl_XPM_Image *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_XPM_Image))
#define lua_push_Fl_Input_Choice(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Input_Choice)
#define lua_to_Fl_Input_Choice(__S__, pos, __ERROR__) \
((Fl_Input_Choice *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Input_Choice))
#define lua_push_Fl_Help_View(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Help_View)
#define lua_to_Fl_Help_View(__S__, pos, __ERROR__) \
((Fl_Help_View *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Help_View))
#define lua_push_Fl_Wizard(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Wizard)
#define lua_to_Fl_Wizard(__S__, pos, __ERROR__) \
((Fl_Wizard *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Wizard))
#define lua_push_Fl_Slider(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Slider)
#define lua_to_Fl_Slider(__S__, pos, __ERROR__) \
((Fl_Slider *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Slider))
#define lua_push_Fl_Choice(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Choice)
#define lua_to_Fl_Choice(__S__, pos, __ERROR__) \
((Fl_Choice *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Choice))
#define lua_push_Fl_XBM_Image(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_XBM_Image)
#define lua_to_Fl_XBM_Image(__S__, pos, __ERROR__) \
((Fl_XBM_Image *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_XBM_Image))
#define lua_push_Fl_Clock(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Clock)
#define lua_to_Fl_Clock(__S__, pos, __ERROR__) \
((Fl_Clock *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Clock))
#define lua_push_Fl_Spinner(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Spinner)
#define lua_to_Fl_Spinner(__S__, pos, __ERROR__) \
((Fl_Spinner *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Spinner))
#define lua_push_Fl_JPEG_Image(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_JPEG_Image)
#define lua_to_Fl_JPEG_Image(__S__, pos, __ERROR__) \
((Fl_JPEG_Image *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_JPEG_Image))
#define lua_push_Fl_Browser_(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Browser_)
#define lua_to_Fl_Browser_(__S__, pos, __ERROR__) \
((Fl_Browser_ *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Browser_))
#define lua_push_Fl_Tile(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Tile)
#define lua_to_Fl_Tile(__S__, pos, __ERROR__) \
((Fl_Tile *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Tile))
#define lua_push_Fl_Text_Display(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Text_Display)
#define lua_to_Fl_Text_Display(__S__, pos, __ERROR__) \
((Fl_Text_Display *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Text_Display))
#define lua_push_Fl_Pack(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Pack)
#define lua_to_Fl_Pack(__S__, pos, __ERROR__) \
((Fl_Pack *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Pack))
#define lua_push_Fl_Repeat_Button(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Repeat_Button)
#define lua_to_Fl_Repeat_Button(__S__, pos, __ERROR__) \
((Fl_Repeat_Button *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Repeat_Button))
#define lua_push_Fl_Light_Button(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Light_Button)
#define lua_to_Fl_Light_Button(__S__, pos, __ERROR__) \
((Fl_Light_Button *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Light_Button))
#define lua_push_Fl_Roller(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Roller)
#define lua_to_Fl_Roller(__S__, pos, __ERROR__) \
((Fl_Roller *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Roller))
#define lua_push_Fl_Tabs(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Tabs)
#define lua_to_Fl_Tabs(__S__, pos, __ERROR__) \
((Fl_Tabs *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Tabs))
#define lua_push_Fl_Value_Input(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Value_Input)
#define lua_to_Fl_Value_Input(__S__, pos, __ERROR__) \
((Fl_Value_Input *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Value_Input))
#define lua_push_Fl_Nice_Slider(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Nice_Slider)
#define lua_to_Fl_Nice_Slider(__S__, pos, __ERROR__) \
((Fl_Nice_Slider *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Nice_Slider))
#define lua_push_Fl_Fill_Dial(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Fill_Dial)
#define lua_to_Fl_Fill_Dial(__S__, pos, __ERROR__) \
((Fl_Fill_Dial *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Fill_Dial))
#define lua_push_Fl_Browser(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Browser)
#define lua_to_Fl_Browser(__S__, pos, __ERROR__) \
((Fl_Browser *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Browser))
#define lua_push_Fl_Radio_Light_Button(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Radio_Light_Button)
#define lua_to_Fl_Radio_Light_Button(__S__, pos, __ERROR__) \
((Fl_Radio_Light_Button *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Radio_Light_Button))
#define lua_push_Fl_Single_Window(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Single_Window)
#define lua_to_Fl_Single_Window(__S__, pos, __ERROR__) \
((Fl_Single_Window *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Single_Window))
#define lua_push_Fl_Multiline_Input(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Multiline_Input)
#define lua_to_Fl_Multiline_Input(__S__, pos, __ERROR__) \
((Fl_Multiline_Input *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Multiline_Input))
#define lua_push_Fl_Output(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Output)
#define lua_to_Fl_Output(__S__, pos, __ERROR__) \
((Fl_Output *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Output))
#define lua_push_Fl_Round_Button(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Round_Button)
#define lua_to_Fl_Round_Button(__S__, pos, __ERROR__) \
((Fl_Round_Button *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Round_Button))
#define lua_push_Fl_Scrollbar(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Scrollbar)
#define lua_to_Fl_Scrollbar(__S__, pos, __ERROR__) \
((Fl_Scrollbar *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Scrollbar))
#define lua_push_Fl_Secret_Input(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Secret_Input)
#define lua_to_Fl_Secret_Input(__S__, pos, __ERROR__) \
((Fl_Secret_Input *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Secret_Input))
#define lua_push_Fl_Value_Slider(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Value_Slider)
#define lua_to_Fl_Value_Slider(__S__, pos, __ERROR__) \
((Fl_Value_Slider *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Value_Slider))
#define lua_push_Fl_Hor_Slider(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Hor_Slider)
#define lua_to_Fl_Hor_Slider(__S__, pos, __ERROR__) \
((Fl_Hor_Slider *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Hor_Slider))
#define lua_push_Fl_Check_Button(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Check_Button)
#define lua_to_Fl_Check_Button(__S__, pos, __ERROR__) \
((Fl_Check_Button *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Check_Button))
#define lua_push_Fl_Fill_Slider(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Fill_Slider)
#define lua_to_Fl_Fill_Slider(__S__, pos, __ERROR__) \
((Fl_Fill_Slider *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Fill_Slider))
#define lua_push_Fl_Int_Input(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Int_Input)
#define lua_to_Fl_Int_Input(__S__, pos, __ERROR__) \
((Fl_Int_Input *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Int_Input))
#define lua_push_Fl_File_Input(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_File_Input)
#define lua_to_Fl_File_Input(__S__, pos, __ERROR__) \
((Fl_File_Input *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_File_Input))
#define lua_push_Fl_Check_Browser(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Check_Browser)
#define lua_to_Fl_Check_Browser(__S__, pos, __ERROR__) \
((Fl_Check_Browser *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Check_Browser))
#define lua_push_Fl_Simple_Counter(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Simple_Counter)
#define lua_to_Fl_Simple_Counter(__S__, pos, __ERROR__) \
((Fl_Simple_Counter *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Simple_Counter))
#define lua_push_Fl_Line_Dial(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Line_Dial)
#define lua_to_Fl_Line_Dial(__S__, pos, __ERROR__) \
((Fl_Line_Dial *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Line_Dial))
#define lua_push_Fl_Double_Window(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Double_Window)
#define lua_to_Fl_Double_Window(__S__, pos, __ERROR__) \
((Fl_Double_Window *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Double_Window))
#define lua_push_Fl_Round_Clock(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Round_Clock)
#define lua_to_Fl_Round_Clock(__S__, pos, __ERROR__) \
((Fl_Round_Clock *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Round_Clock))
#define lua_push_Fl_Float_Input(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Float_Input)
#define lua_to_Fl_Float_Input(__S__, pos, __ERROR__) \
((Fl_Float_Input *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Float_Input))
#define lua_push_Fl_Text_Editor(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Text_Editor)
#define lua_to_Fl_Text_Editor(__S__, pos, __ERROR__) \
((Fl_Text_Editor *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Text_Editor))
#define lua_push_Fl_Hor_Fill_Slider(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Hor_Fill_Slider)
#define lua_to_Fl_Hor_Fill_Slider(__S__, pos, __ERROR__) \
((Fl_Hor_Fill_Slider *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Hor_Fill_Slider))
#define lua_push_Fl_Hor_Nice_Slider(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Hor_Nice_Slider)
#define lua_to_Fl_Hor_Nice_Slider(__S__, pos, __ERROR__) \
((Fl_Hor_Nice_Slider *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Hor_Nice_Slider))
#define lua_push_Fl_Multi_Browser(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Multi_Browser)
#define lua_to_Fl_Multi_Browser(__S__, pos, __ERROR__) \
((Fl_Multi_Browser *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Multi_Browser))
#define lua_push_Fl_File_Browser(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_File_Browser)
#define lua_to_Fl_File_Browser(__S__, pos, __ERROR__) \
((Fl_File_Browser *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_File_Browser))
#define lua_push_Fl_Overlay_Window(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Overlay_Window)
#define lua_to_Fl_Overlay_Window(__S__, pos, __ERROR__) \
((Fl_Overlay_Window *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Overlay_Window))
#define lua_push_Fl_Radio_Round_Button(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Radio_Round_Button)
#define lua_to_Fl_Radio_Round_Button(__S__, pos, __ERROR__) \
((Fl_Radio_Round_Button *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Radio_Round_Button))
#define lua_push_Fl_Menu_Window(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Menu_Window)
#define lua_to_Fl_Menu_Window(__S__, pos, __ERROR__) \
((Fl_Menu_Window *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Menu_Window))
#define lua_push_Fl_Select_Browser(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Select_Browser)
#define lua_to_Fl_Select_Browser(__S__, pos, __ERROR__) \
((Fl_Select_Browser *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Select_Browser))
#define lua_push_Fl_Hold_Browser(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Hold_Browser)
#define lua_to_Fl_Hold_Browser(__S__, pos, __ERROR__) \
((Fl_Hold_Browser *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Hold_Browser))
#define lua_push_Fl_Multiline_Output(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Multiline_Output)
#define lua_to_Fl_Multiline_Output(__S__, pos, __ERROR__) \
((Fl_Multiline_Output *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Multiline_Output))
#define lua_push_Fl_Hor_Value_Slider(__S__,  v) \
_lua_push_class(__S__, (void *) v, &type__Fl_Hor_Value_Slider)
#define lua_to_Fl_Hor_Value_Slider(__S__, pos, __ERROR__) \
((Fl_Hor_Value_Slider *) _lua_to_class(__S__, pos, __ERROR__, &type__Fl_Hor_Value_Slider))

int lua_delete_Fl(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl * p = lua_to_Fl(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Help_Dialog(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Help_Dialog * p = lua_to_Fl_Help_Dialog(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_new_Fl_Text_Display__Style_Table_Entry(lua_State * __S__)
{
  lua_settop(__S__, 0);
  lua_push_Fl_Text_Display__Style_Table_Entry(__S__, new Fl_Text_Display::Style_Table_Entry);
  return 1;
}

int lua_delete_Fl_Text_Display__Style_Table_Entry(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Text_Display::Style_Table_Entry * p = lua_to_Fl_Text_Display__Style_Table_Entry(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_End(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_End * p = lua_to_Fl_End(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_new_Fl_Menu(lua_State * __S__)
{
  lua_settop(__S__, 0);
  lua_push_Fl_Menu(__S__, new Fl_Menu);
  return 1;
}

int lua_delete_Fl_Menu(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Menu * p = lua_to_Fl_Menu(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Widget(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Widget * p = lua_to_Fl_Widget(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_new_FL_CHART_ENTRY(lua_State * __S__)
{
  lua_settop(__S__, 0);
  lua_push_FL_CHART_ENTRY(__S__, new FL_CHART_ENTRY);
  return 1;
}

int lua_delete_FL_CHART_ENTRY(lua_State * __S__)
{
  int __ERROR__ = 0;
  FL_CHART_ENTRY * p = lua_to_FL_CHART_ENTRY(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_new_Fl_Menu_Item(lua_State * __S__)
{
  lua_settop(__S__, 0);
  lua_push_Fl_Menu_Item(__S__, new Fl_Menu_Item);
  return 1;
}

int lua_delete_Fl_Menu_Item(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Menu_Item * p = lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_murgaLuaOffScreen(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_murgaLuaOffScreen * p = lua_to_Fl_murgaLuaOffScreen(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_new_Fl_Label(lua_State * __S__)
{
  lua_settop(__S__, 0);
  lua_push_Fl_Label(__S__, new Fl_Label);
  return 1;
}

int lua_delete_Fl_Label(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Label * p = lua_to_Fl_Label(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Preferences__Name(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Preferences::Name * p = lua_to_Fl_Preferences__Name(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_new_Fl_Check_Browser__cb_item(lua_State * __S__)
{
  lua_settop(__S__, 0);
  lua_push_Fl_Check_Browser__cb_item(__S__, new Fl_Check_Browser::cb_item);
  return 1;
}

int lua_delete_Fl_Check_Browser__cb_item(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Check_Browser::cb_item * p = lua_to_Fl_Check_Browser__cb_item(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_File_Icon(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_File_Icon * p = lua_to_Fl_File_Icon(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_new_Fl_Preferences__Entry(lua_State * __S__)
{
  lua_settop(__S__, 0);
  lua_push_Fl_Preferences__Entry(__S__, new Fl_Preferences::Entry);
  return 1;
}

int lua_delete_Fl_Preferences__Entry(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Preferences::Entry * p = lua_to_Fl_Preferences__Entry(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_File_Chooser(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_File_Chooser * p = lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Preferences(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Preferences * p = lua_to_Fl_Preferences(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Image(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Image * p = lua_to_Fl_Image(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_new_Fl_Help_Block(lua_State * __S__)
{
  lua_settop(__S__, 0);
  lua_push_Fl_Help_Block(__S__, new Fl_Help_Block);
  return 1;
}

int lua_delete_Fl_Help_Block(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Help_Block * p = lua_to_Fl_Help_Block(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Text_Buffer(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Text_Buffer * p = lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_new_Fl_Tooltip(lua_State * __S__)
{
  lua_settop(__S__, 0);
  lua_push_Fl_Tooltip(__S__, new Fl_Tooltip);
  return 1;
}

int lua_delete_Fl_Tooltip(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Tooltip * p = lua_to_Fl_Tooltip(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_new_Fl_Text_Selection(lua_State * __S__)
{
  lua_settop(__S__, 0);
  lua_push_Fl_Text_Selection(__S__, new Fl_Text_Selection);
  return 1;
}

int lua_delete_Fl_Text_Selection(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Text_Selection * p = lua_to_Fl_Text_Selection(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_new_Fl_Text_Editor__Key_Binding(lua_State * __S__)
{
  lua_settop(__S__, 0);
  lua_push_Fl_Text_Editor__Key_Binding(__S__, new Fl_Text_Editor::Key_Binding);
  return 1;
}

int lua_delete_Fl_Text_Editor__Key_Binding(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Text_Editor::Key_Binding * p = lua_to_Fl_Text_Editor__Key_Binding(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_new_Fl_Multi_Label(lua_State * __S__)
{
  lua_settop(__S__, 0);
  lua_push_Fl_Multi_Label(__S__, new Fl_Multi_Label);
  return 1;
}

int lua_delete_Fl_Multi_Label(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Multi_Label * p = lua_to_Fl_Multi_Label(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_new_Fl_Help_Target(lua_State * __S__)
{
  lua_settop(__S__, 0);
  lua_push_Fl_Help_Target(__S__, new Fl_Help_Target);
  return 1;
}

int lua_delete_Fl_Help_Target(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Help_Target * p = lua_to_Fl_Help_Target(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_new_Fl_Help_Link(lua_State * __S__)
{
  lua_settop(__S__, 0);
  lua_push_Fl_Help_Link(__S__, new Fl_Help_Link);
  return 1;
}

int lua_delete_Fl_Help_Link(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Help_Link * p = lua_to_Fl_Help_Link(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Box(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Box * p = lua_to_Fl_Box(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Progress(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Progress * p = lua_to_Fl_Progress(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Group(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Group * p = lua_to_Fl_Group(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Timer(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Timer * p = lua_to_Fl_Timer(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Chart(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Chart * p = lua_to_Fl_Chart(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_murgaLuaTimer(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_murgaLuaTimer * p = lua_to_Fl_murgaLuaTimer(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Menu_(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Menu_ * p = lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Button(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Button * p = lua_to_Fl_Button(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Positioner(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Positioner * p = lua_to_Fl_Positioner(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Input_(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Input_ * p = lua_to_Fl_Input_(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_FormsBitmap(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_FormsBitmap * p = lua_to_Fl_FormsBitmap(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Clock_Output(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Clock_Output * p = lua_to_Fl_Clock_Output(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_FormsPixmap(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_FormsPixmap * p = lua_to_Fl_FormsPixmap(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Tiled_Image(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Tiled_Image * p = lua_to_Fl_Tiled_Image(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_RGB_Image(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_RGB_Image * p = lua_to_Fl_RGB_Image(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Pixmap(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Pixmap * p = lua_to_Fl_Pixmap(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Bitmap(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Bitmap * p = lua_to_Fl_Bitmap(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Toggle_Button(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Toggle_Button * p = lua_to_Fl_Toggle_Button(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Value_Output(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Value_Output * p = lua_to_Fl_Value_Output(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Return_Button(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Return_Button * p = lua_to_Fl_Return_Button(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Counter(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Counter * p = lua_to_Fl_Counter(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_PNG_Image(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_PNG_Image * p = lua_to_Fl_PNG_Image(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Radio_Button(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Radio_Button * p = lua_to_Fl_Radio_Button(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Scroll(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Scroll * p = lua_to_Fl_Scroll(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Window(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Window * p = lua_to_Fl_Window(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Color_Chooser(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Color_Chooser * p = lua_to_Fl_Color_Chooser(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Input(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Input * p = lua_to_Fl_Input(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Menu_Bar(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Menu_Bar * p = lua_to_Fl_Menu_Bar(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_PNM_Image(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_PNM_Image * p = lua_to_Fl_PNM_Image(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Adjuster(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Adjuster * p = lua_to_Fl_Adjuster(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Dial(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Dial * p = lua_to_Fl_Dial(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_BMP_Image(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_BMP_Image * p = lua_to_Fl_BMP_Image(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Menu_Button(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Menu_Button * p = lua_to_Fl_Menu_Button(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_GIF_Image(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_GIF_Image * p = lua_to_Fl_GIF_Image(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_XPM_Image(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_XPM_Image * p = lua_to_Fl_XPM_Image(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Input_Choice(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Input_Choice * p = lua_to_Fl_Input_Choice(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Help_View(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Help_View * p = lua_to_Fl_Help_View(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Wizard(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Wizard * p = lua_to_Fl_Wizard(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Slider(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Slider * p = lua_to_Fl_Slider(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Choice(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Choice * p = lua_to_Fl_Choice(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_XBM_Image(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_XBM_Image * p = lua_to_Fl_XBM_Image(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Clock(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Clock * p = lua_to_Fl_Clock(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Spinner(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Spinner * p = lua_to_Fl_Spinner(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_JPEG_Image(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_JPEG_Image * p = lua_to_Fl_JPEG_Image(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Tile(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Tile * p = lua_to_Fl_Tile(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Text_Display(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Text_Display * p = lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Pack(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Pack * p = lua_to_Fl_Pack(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Repeat_Button(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Repeat_Button * p = lua_to_Fl_Repeat_Button(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Light_Button(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Light_Button * p = lua_to_Fl_Light_Button(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Roller(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Roller * p = lua_to_Fl_Roller(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Tabs(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Tabs * p = lua_to_Fl_Tabs(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Value_Input(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Value_Input * p = lua_to_Fl_Value_Input(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Nice_Slider(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Nice_Slider * p = lua_to_Fl_Nice_Slider(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Fill_Dial(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Fill_Dial * p = lua_to_Fl_Fill_Dial(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Browser(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Browser * p = lua_to_Fl_Browser(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Radio_Light_Button(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Radio_Light_Button * p = lua_to_Fl_Radio_Light_Button(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Single_Window(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Single_Window * p = lua_to_Fl_Single_Window(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Multiline_Input(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Multiline_Input * p = lua_to_Fl_Multiline_Input(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Output(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Output * p = lua_to_Fl_Output(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Round_Button(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Round_Button * p = lua_to_Fl_Round_Button(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Scrollbar(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Scrollbar * p = lua_to_Fl_Scrollbar(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Secret_Input(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Secret_Input * p = lua_to_Fl_Secret_Input(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Value_Slider(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Value_Slider * p = lua_to_Fl_Value_Slider(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Hor_Slider(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Hor_Slider * p = lua_to_Fl_Hor_Slider(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Check_Button(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Check_Button * p = lua_to_Fl_Check_Button(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Fill_Slider(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Fill_Slider * p = lua_to_Fl_Fill_Slider(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Int_Input(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Int_Input * p = lua_to_Fl_Int_Input(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_File_Input(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_File_Input * p = lua_to_Fl_File_Input(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Check_Browser(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Check_Browser * p = lua_to_Fl_Check_Browser(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Simple_Counter(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Simple_Counter * p = lua_to_Fl_Simple_Counter(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Line_Dial(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Line_Dial * p = lua_to_Fl_Line_Dial(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Double_Window(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Double_Window * p = lua_to_Fl_Double_Window(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Round_Clock(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Round_Clock * p = lua_to_Fl_Round_Clock(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Float_Input(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Float_Input * p = lua_to_Fl_Float_Input(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Text_Editor(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Text_Editor * p = lua_to_Fl_Text_Editor(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Hor_Fill_Slider(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Hor_Fill_Slider * p = lua_to_Fl_Hor_Fill_Slider(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Hor_Nice_Slider(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Hor_Nice_Slider * p = lua_to_Fl_Hor_Nice_Slider(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Multi_Browser(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Multi_Browser * p = lua_to_Fl_Multi_Browser(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_File_Browser(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_File_Browser * p = lua_to_Fl_File_Browser(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Overlay_Window(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Overlay_Window * p = lua_to_Fl_Overlay_Window(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Radio_Round_Button(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Radio_Round_Button * p = lua_to_Fl_Radio_Round_Button(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Menu_Window(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Menu_Window * p = lua_to_Fl_Menu_Window(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Select_Browser(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Select_Browser * p = lua_to_Fl_Select_Browser(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Hold_Browser(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Hold_Browser * p = lua_to_Fl_Hold_Browser(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Multiline_Output(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Multiline_Output * p = lua_to_Fl_Multiline_Output(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

int lua_delete_Fl_Hor_Value_Slider(lua_State * __S__)
{
  int __ERROR__ = 0;
  Fl_Hor_Value_Slider * p = lua_to_Fl_Hor_Value_Slider(__S__, 1, &__ERROR__);
  delete p;
  return 0;
}

/* Fl_Image::data() */
int lua_call1_Fl_Image__data(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;

  if (nparam < 1) goto error;
  {
     class Fl_Image * __self__;
    __self__ = ( class Fl_Image * )lua_to_Fl_Image(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    if (__self__->data() == NULL) goto error;

	if (__self__->count() == 0) goto error;

	/* create result table */
	lua_newtable(__S__);
		
	// For RGB and Bitmap images
	if (__self__->count() == 1)
	{
		int depth = __self__->d();
		if ( depth == 0) depth = 1;
		
		lua_pushnumber(__S__, 1);  /* push key */
		lua_pushlstring(__S__, __self__->data()[0], __self__->w()*__self__->h()*depth);  /* push value */
		lua_settable(__S__, -3);
    }
	else
	{
		// For Pixmap images
		int	arraySize, ncolors, chars_per_pixel, chars_per_line, color_line=0;
		
		sscanf(__self__->data()[0],"%*d%*d%d%d", &ncolors, &chars_per_pixel);
		chars_per_line = chars_per_pixel * __self__->w() + 1;

		if (ncolors < 0)
		{
			color_line = (-ncolors) * 4;
			arraySize  = __self__->h() + 2;	
		}
		else
		{
			arraySize  = __self__->h() + ncolors + 1;
		}
		
	    for (int i = 1; i <= arraySize; i++)
		{
	      lua_pushnumber(__S__, i);  /* push key */
		  
		  if (i == 1)
			lua_pushlstring(__S__, __self__->data()[i-1], chars_per_line);  /* push value */
		  else if (i == 2 && color_line != 0)
			lua_pushlstring(__S__, __self__->data()[i-1], color_line);  /* push value */
	      else
			lua_pushstring(__S__, __self__->data()[i-1]);  /* push value */

		  lua_settable(__S__, -3);
	    }
	}
	lua_pushstring(__S__, "w");  /* push key */
	lua_pushnumber(__S__, __self__->w());  /* push value */
	lua_settable(__S__, -3);
	lua_pushstring(__S__, "h");  /* push key */
	lua_pushnumber(__S__, __self__->h());  /* push value */
	lua_settable(__S__, -3);
	lua_pushstring(__S__, "d");  /* push key */
	lua_pushnumber(__S__, __self__->d());  /* push value */
	lua_settable(__S__, -3);
	lua_pushstring(__S__, "ld");  /* push key */
	lua_pushnumber(__S__, __self__->ld());  /* push value */
	lua_settable(__S__, -3);
	
    return 1;
  }
error:
  luaL_error(__S__, badargs_error);
  return 0;
}

/*  Fl_Pixmap::Fl_Pixmap(const char * * D) */
/* SKIPPED (argument #1) */
/*  Fl_Pixmap::Fl_Pixmap(const const char * * D) */
/* SKIPPED (argument #1) */
/*  Fl_Pixmap::Fl_Pixmap(const const uchar * * D) */
/* SKIPPED (argument #1) */
/*  Fl_Pixmap::Fl_Pixmap(const uchar * * D) */
/* SKIPPED (argument #1) */

int lua_call1_Fl_Pixmap__Fl_Pixmap(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
//  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
    lua_pushnil(__S__);
	int counter = 0;
	
    while(lua_next(__S__, -2) != 0)
    {
		lua_pop(__S__, 1);
		counter++;
    }

    lua_pushnil(__S__);

	char **imageData = new char *[counter];
	counter=0;

    while(lua_next(__S__, -2) != 0)
    {
		// stack issues ... See : http://lua-users.org/lists/lua-l/2007-09/msg00435.html
		// This code is only good for string data
    // printf("Data : \"%s\"\n", lua_tostring(__S__, -1));
		imageData[counter] = (char *) lua_tostring(__S__, -1);

		lua_pop(__S__, 1);
		counter++;
    }

    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_Pixmap(__S__, new Fl_Pixmap((char*const*) imageData));
    return 1;
  }  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}

/* const int * Fl_Browser::column_widths()const  */
/* SKIPPED (return type) */
/* void Fl_Browser::column_widths(const int * l) */
/* SKIPPED (argument #2) */

int lua_call1_Fl_Browser__column_widths(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
      class Fl_Browser * __self__;
      __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
	  if (__ERROR__) goto error;

  	  if (nparam == 1)
	  {
		const int *columnData = __self__->column_widths();
		
	  	/* create result table */
		lua_newtable(__S__);
		int counter = 0;
	    do
		{
	      lua_pushnumber(__S__, counter+1);  /* push key */
    	  lua_pushnumber(__S__, columnData[counter++]);  /* push value */
		  lua_settable(__S__, -3);  /* Finalize row */
	    } while (columnData[counter] != 0);
		// Specifically for Fl_Browser the last item is ZERO
		lua_pushnumber(__S__, counter+1);  /* push key */
		lua_pushnumber(__S__, columnData[counter]);  /* push value */
	    lua_settable(__S__, -3); /* Finalize row */

	    return 1;
	  }
	  else
	  {
		// Array setting code
		lua_pushnil(__S__);
		int counter = 0;
		
		while(lua_next(__S__, -2) != 0)
		{
			lua_pop(__S__, 1);
			counter++;
		}

		lua_pushnil(__S__);
		int *columnData = new int [counter];
		counter=0;

	    while(lua_next(__S__, -2) != 0)
	    {
			// stack issues ... See : http://lua-users.org/lists/lua-l/2007-09/msg00435.html
			columnData[counter] = (int) lua_tonumber(__S__, -1);

			lua_pop(__S__, 1);
			counter++;
	    }

	    __self__->column_widths(columnData);
	    return 1;

	  }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}

/* void Fl_RGB_Image::saveAsPng(char *) */
int lua_call1_Fl_RGB_Image__saveAsPng(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_RGB_Image * __self__;
     char *val;
    
    __self__ = ( class Fl_RGB_Image * )lua_to_Fl_RGB_Image(__S__, 1, &__ERROR__);
    val = (char  *) lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    if(!saveRgbAsPng( (const uchar *) __self__->data()[0], __self__->w(), __self__->h(), __self__->d(), val ))
	{
		luaL_error(__S__, "File error saving PNG");
	}
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}

/* Extracted and modifed */

int lua_call1_fl_read_image(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     int alpha;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_pushlstring(__S__, (const char * ) fl_read_image(NULL, x, y, w, h), w*h*3);
      return 1;
    } else {
      alpha = ( int )(int)lua_tonumber(__S__, 5);
      lua_settop(__S__, 0);
      lua_pushlstring(__S__, (const char * ) fl_read_image(NULL, x, y, w, h, alpha), w*h*4);
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}

int lua_call1_Fl_Menu___menu(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Menu_ * __self__;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    int pos = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Menu_Item(__S__, (Fl_Menu_Item*)&(__self__->menu()[pos]));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}


/* int Fl_Widget::serial()const  */
int lua_call1_Fl_Widget__serial(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, (unsigned int) __self__);
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}


/* int Fl_Menu_Item::serial()const  */
int lua_call1_Fl_Menu_Item__serial(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( class Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, (unsigned int) __self__);
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}

/* Fl_RGB_Image::getTiles(xSize, ySize) */
int lua_call1_Fl_RGB_Image__getTiles(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;

  if (nparam < 1) goto error;
  {
     class Fl_Image * __self__;
    __self__ = ( class Fl_Image * )lua_to_Fl_Image(__S__, 1, &__ERROR__);
	int xSize = (int)lua_tonumber(__S__, 2);
    int ySize = (int)lua_tonumber(__S__, 3);
	
    /* Actual call */
    if (__ERROR__) goto error;
    
	/* create result table */
	lua_newtable(__S__);

	int xTiles = __self__->w() / xSize;
	int yTiles = __self__->h() / ySize;
	int depth = __self__->d();
	int width = __self__->w();
	
	if (depth ==0) depth = 1;
	
	int totalTiles = xTiles * yTiles;
	const uchar *sourceImage = (const uchar *) __self__->data()[0];
		
	for (int counter=0; counter < totalTiles; counter++)
	{
		int destLine, srcLine, tileOffset, verticalOffset;
		uchar *buffer = (uchar *) malloc(xSize*ySize*depth*sizeof(uchar));
			
		for (int line=0; line < ySize; line++)
		{
			verticalOffset = (counter / xTiles) * ySize * width * depth;
			destLine   = line * xSize * depth;
			srcLine    = line * width * depth;
			tileOffset = counter * xSize * depth;
			memmove(buffer + destLine, sourceImage + srcLine + tileOffset + verticalOffset, xSize * depth);
		}
		
		lua_pushnumber(__S__, counter+1);
		lua_push_Fl_RGB_Image(__S__, new Fl_RGB_Image(buffer, xSize, ySize, depth));
		lua_settable(__S__, -3);
	}
	
    return 1;
  }
error:
  luaL_error(__S__, badargs_error);
  return 0;
}

/* double Fl_Spinner::step()const  */
int lua_call1_Fl_Spinner__step(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Spinner * __self__;
    
    __self__ = ( class Fl_Spinner * )lua_to_Fl_Spinner(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->step());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Spinner::step(double s) */
int lua_call2_Fl_Spinner__step(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Spinner * __self__;
     double s;
    
    __self__ = ( class Fl_Spinner * )lua_to_Fl_Spinner(__S__, 1, &__ERROR__);
    s = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->step(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Spinner__step(__S__);
}
/*  Fl_Round_Button::Fl_Round_Button(int x, int y, int w, int h, const char * l=0) */
int lua_call1_Fl_Round_Button__Fl_Round_Button(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Round_Button(__S__, new Fl_Round_Button(x, y, w, h));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Round_Button(__S__, new Fl_Round_Button(x, y, w, h, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_text_drag_me(int pos, class Fl_Text_Display * d) */
int lua_call1_fl_text_drag_me(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int pos;
     class Fl_Text_Display * d;
    
    pos = ( int )(int)lua_tonumber(__S__, 1);
    d = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    fl_text_drag_me(pos, d);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Image::h()const  */
int lua_call1_Fl_Image__h(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Image * __self__;
    
    __self__ = ( class Fl_Image * )lua_to_Fl_Image(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->h());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::has_check(Fl_Timeout_Handler , void * =0) */
/* SKIPPED (argument #1) */
/* void Fl_Tooltip::enter_(class Fl_Widget * w) */
int lua_call1_Fl_Tooltip__enter_(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     class Fl_Widget * w;
    
    w = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    Fl_Tooltip::enter_(w);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* uchar Fl_Input_Choice::textfont()const  */
int lua_call1_Fl_Input_Choice__textfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Input_Choice * __self__;
    
    __self__ = ( class Fl_Input_Choice * )lua_to_Fl_Input_Choice(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textfont());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Input_Choice::textfont(uchar f) */
int lua_call2_Fl_Input_Choice__textfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Input_Choice * __self__;
     unsigned char f;
    
    __self__ = ( class Fl_Input_Choice * )lua_to_Fl_Input_Choice(__S__, 1, &__ERROR__);
    f = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textfont(f);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Input_Choice__textfont(__S__);
}
/* int Fl_Valuator::format(char * ) */
int lua_call1_Fl_Valuator__format(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Valuator * __self__;
     char * __2__;
    
    __self__ = ( class Fl_Valuator * )lua_to_Fl_Valuator(__S__, 1, &__ERROR__);
    __2__ = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->format(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const char * Fl::scheme() */
int lua_call1_Fl__scheme(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) Fl::scheme());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::scheme(const char * ) */
int lua_call2_Fl__scheme(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * __1__;
    
    __1__ = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::scheme(__1__));
    return 1;
  }
  
error:
  return lua_call1_Fl__scheme(__S__);
}
/* double Fl::version() */
int lua_call1_Fl__version(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::version());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Buffer::add_modify_callback(Fl_Text_Modify_Cb bufModifiedCB, void * cbArg) */
/* SKIPPED (argument #2) */
/* int Fl_Menu_Item::checkbox()const  */
int lua_call1_Fl_Menu_Item__checkbox(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->checkbox());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_Item::set() */
int lua_call1_Fl_Menu_Item__set(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->set();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* double Fl_Valuator::maximum()const  */
int lua_call1_Fl_Valuator__maximum(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Valuator * __self__;
    
    __self__ = ( class Fl_Valuator * )lua_to_Fl_Valuator(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->maximum());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Valuator::maximum(double a) */
int lua_call2_Fl_Valuator__maximum(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Valuator * __self__;
     double a;
    
    __self__ = ( class Fl_Valuator * )lua_to_Fl_Valuator(__S__, 1, &__ERROR__);
    a = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->maximum(a);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Valuator__maximum(__S__);
}
/* Fl_Boxtype Fl_Slider::slider()const  */
int lua_call1_Fl_Slider__slider(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Slider * __self__;
    
    __self__ = ( class Fl_Slider * )lua_to_Fl_Slider(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->slider());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Slider::slider(Fl_Boxtype c) */
int lua_call2_Fl_Slider__slider(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Slider * __self__;
     Fl_Boxtype c;
    
    __self__ = ( class Fl_Slider * )lua_to_Fl_Slider(__S__, 1, &__ERROR__);
    c = ( Fl_Boxtype )(Fl_Boxtype)(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->slider(c);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Slider__slider(__S__);
}
/* void * Fl_Menu_Item::user_data()const  */
/* SKIPPED (return type) */
/* void Fl_Menu_Item::user_data(void * v) */
/* SKIPPED (argument #2) */
/* int Fl_Scroll::xposition()const  */
int lua_call1_Fl_Scroll__xposition(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Scroll * __self__;
    
    __self__ = ( class Fl_Scroll * )lua_to_Fl_Scroll(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->xposition());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Progress::Fl_Progress(int x, int y, int w, int h, const char * l=0) */
int lua_call1_Fl_Progress__Fl_Progress(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Progress(__S__, new Fl_Progress(x, y, w, h));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Progress(__S__, new Fl_Progress(x, y, w, h, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Check_Browser::Fl_Check_Browser(int x, int y, int w, int h, const char * l=0) */
int lua_call1_Fl_Check_Browser__Fl_Check_Browser(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Check_Browser(__S__, new Fl_Check_Browser(x, y, w, h));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Check_Browser(__S__, new Fl_Check_Browser(x, y, w, h, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const struct Fl_Menu_Item * Fl_Menu_::mvalue()const  */
int lua_call1_Fl_Menu___mvalue(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Menu_ * __self__;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Menu_Item(__S__, __self__->mvalue());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::get_mouse(int & , int & ) */
int lua_call1_Fl__get_mouse(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int __1__;
     int __2__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    Fl::get_mouse(__1__, __2__);
    lua_settop(__S__, 0);
    ;
    lua_pushnumber(__S__, __1__);
    lua_pushnumber(__S__, __2__);
    return 2;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_push_no_clip() */
int lua_call1_fl_push_no_clip(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    fl_push_no_clip();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Boxtype fl_define_FL_RSHADOW_BOX() */
int lua_call1_fl_define_FL_RSHADOW_BOX(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_define_FL_RSHADOW_BOX());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Value_Input::draw() */
int lua_call1_Fl_Value_Input__draw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Value_Input * __self__;
    
    __self__ = ( class Fl_Value_Input * )lua_to_Fl_Value_Input(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->draw();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Scroll::yposition()const  */
int lua_call1_Fl_Scroll__yposition(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Scroll * __self__;
    
    __self__ = ( class Fl_Scroll * )lua_to_Fl_Scroll(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->yposition());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Dial::Fl_Dial(int x, int y, int w, int h, const char * l=0) */
int lua_call1_Fl_Dial__Fl_Dial(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Dial(__S__, new Fl_Dial(x, y, w, h));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Dial(__S__, new Fl_Dial(x, y, w, h, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::ready() */
int lua_call1_Fl__ready(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::ready());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* char * Fl_Text_Buffer::text() */
int lua_call1_Fl_Text_Buffer__text(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Buffer * __self__;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->text());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Buffer::text(const char * text) */
int lua_call2_Fl_Text_Buffer__text(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Buffer * __self__;
     char * text;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    text = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->text(text);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Text_Buffer__text(__S__);
}
/* void Fl_Check_Browser::check_all() */
int lua_call1_Fl_Check_Browser__check_all(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Check_Browser * __self__;
    
    __self__ = ( class Fl_Check_Browser * )lua_to_Fl_Check_Browser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->check_all();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_::clear() */
int lua_call1_Fl_Menu___clear(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Menu_ * __self__;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->clear();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_File_Icon::label(class Fl_Widget * w) */
int lua_call1_Fl_File_Icon__label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_File_Icon * __self__;
     class Fl_Widget * w;
    
    __self__ = ( class Fl_File_Icon * )lua_to_Fl_File_Icon(__S__, 1, &__ERROR__);
    w = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->label(w);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Group::remove(class Fl_Widget * o) */
int lua_call1_Fl_Group__remove(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Group * __self__;
     class Fl_Widget * o;
    
    __self__ = ( class Fl_Group * )lua_to_Fl_Group(__S__, 1, &__ERROR__);
    o = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->remove(o);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Group::remove(class Fl_Widget & ) */
int lua_call2_Fl_Group__remove(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Group * __self__;
    
    __self__ = ( class Fl_Group * )lua_to_Fl_Group(__S__, 1, &__ERROR__);
     class Fl_Widget & __2__ = ( class Fl_Widget & )(*lua_to_Fl_Widget(__S__, 2, &__ERROR__));
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->remove(__2__);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Group__remove(__S__);
}
/* int Fl_Text_Editor::kf_page_down(int c, class Fl_Text_Editor * e) */
int lua_call1_Fl_Text_Editor__kf_page_down(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int c;
     class Fl_Text_Editor * e;
    
    c = ( int )(int)lua_tonumber(__S__, 1);
    e = ( class Fl_Text_Editor * )lua_to_Fl_Text_Editor(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Text_Editor::kf_page_down(c, e));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const struct Fl_Menu_Item * Fl_Menu_Button::popup() */
int lua_call1_Fl_Menu_Button__popup(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Menu_Button * __self__;
    
    __self__ = ( class Fl_Menu_Button * )lua_to_Fl_Menu_Button(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Menu_Item(__S__, __self__->popup());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_begin_loop() */
int lua_call1_fl_begin_loop(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    fl_begin_loop();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::x() */
int lua_call1_Fl__x(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::x());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Display::line_end(int pos, bool start_pos_is_line_start) */
int lua_call1_Fl_Text_Display__line_end(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Text_Display * __self__;
     int pos;
     bool start_pos_is_line_start;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    pos = ( int )(int)lua_tonumber(__S__, 2);
    start_pos_is_line_start = ( bool )(bool)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->line_end(pos, start_pos_is_line_start));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const char * Fl_Shared_Image::name() */
int lua_call1_Fl_Shared_Image__name(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Shared_Image * __self__;
    
    __self__ = ( class Fl_Shared_Image * )lua_to_Fl_Shared_Image(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->name());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Editor::kf_home(int , class Fl_Text_Editor * e) */
int lua_call1_Fl_Text_Editor__kf_home(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int __1__;
     class Fl_Text_Editor * e;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    e = ( class Fl_Text_Editor * )lua_to_Fl_Text_Editor(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Text_Editor::kf_home(__1__, e));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Labeltype Fl_Widget::labeltype()const  */
int lua_call1_Fl_Widget__labeltype(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->labeltype());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::labeltype(Fl_Labeltype a) */
int lua_call2_Fl_Widget__labeltype(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Widget * __self__;
     Fl_Labeltype a;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    a = ( Fl_Labeltype )(Fl_Labeltype)(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->labeltype(a);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Widget__labeltype(__S__);
}
/* Fl_Font Fl_Input_::textfont()const  */
int lua_call1_Fl_Input___textfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Input_ * __self__;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textfont());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Input_::textfont(uchar s) */
int lua_call2_Fl_Input___textfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Input_ * __self__;
     unsigned char s;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    s = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textfont(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Input___textfont(__S__);
}
/* const char * fl_mac_roman_to_local(const char * , int n=-1) */
int lua_call1_fl_mac_roman_to_local(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * __1__;
     int n;
    
    __1__ = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    if (nparam <= 1) {
      lua_settop(__S__, 0);
      lua_pushstring(__S__, (const char * ) fl_mac_roman_to_local(__1__));
      return 1;
    } else {
      n = ( int )(int)lua_tonumber(__S__, 2);
      lua_settop(__S__, 0);
      lua_pushstring(__S__, (const char * ) fl_mac_roman_to_local(__1__, n));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Clock::Fl_Clock(int x, int y, int w, int h, const char * l=0) */
int lua_call1_Fl_Clock__Fl_Clock(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Clock(__S__, new Fl_Clock(x, y, w, h));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Clock(__S__, new Fl_Clock(x, y, w, h, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Clock::Fl_Clock(uchar t, int x, int y, int w, int h, const char * l) */
int lua_call2_Fl_Clock__Fl_Clock(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 6) goto error;
  {
     unsigned char t;
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    t = ( unsigned char )(char)lua_tonumber(__S__, 1);
    x = ( int )(int)lua_tonumber(__S__, 2);
    y = ( int )(int)lua_tonumber(__S__, 3);
    w = ( int )(int)lua_tonumber(__S__, 4);
    h = ( int )(int)lua_tonumber(__S__, 5);
    l = ( char * )(char  *)lua_tostring(__S__, 6);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_Clock(__S__, new Fl_Clock(t, x, y, w, h, l));
    return 1;
  }
  
error:
  return lua_call1_Fl_Clock__Fl_Clock(__S__);
}
/* int Fl_Text_Editor::kf_delete(int c, class Fl_Text_Editor * e) */
int lua_call1_Fl_Text_Editor__kf_delete(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int c;
     class Fl_Text_Editor * e;
    
    c = ( int )(int)lua_tonumber(__S__, 1);
    e = ( class Fl_Text_Editor * )lua_to_Fl_Text_Editor(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Text_Editor::kf_delete(c, e));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* HBRUSH fl_brush() */
/* SKIPPED (return type) */
/* void Fl_Input_Choice::resize(int X, int Y, int W, int H) */
int lua_call1_Fl_Input_Choice__resize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Input_Choice * __self__;
     int X;
     int Y;
     int W;
     int H;
    
    __self__ = ( class Fl_Input_Choice * )lua_to_Fl_Input_Choice(__S__, 1, &__ERROR__);
    X = ( int )(int)lua_tonumber(__S__, 2);
    Y = ( int )(int)lua_tonumber(__S__, 3);
    W = ( int )(int)lua_tonumber(__S__, 4);
    H = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->resize(X, Y, W, H);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int fl_filename_relative(char * to, const char * from) */
int lua_call1_fl_filename_relative(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     char * to;
     char * from;
    
    to = ( char * )(char  *)lua_tostring(__S__, 1);
    from = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_filename_relative(to, from));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int fl_filename_relative(char * to, int tolen, const char * from) */
int lua_call2_fl_filename_relative(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 3) goto error;
  {
     char * to;
     int tolen;
     char * from;
    
    to = ( char * )(char  *)lua_tostring(__S__, 1);
    tolen = ( int )(int)lua_tonumber(__S__, 2);
    from = ( char * )(char  *)lua_tostring(__S__, 3);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_filename_relative(to, tolen, from));
    return 1;
  }
  
error:
  return lua_call1_fl_filename_relative(__S__);
}
/* char Fl_Text_Buffer::null_substitution_character() */
int lua_call1_Fl_Text_Buffer__null_substitution_character(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Buffer * __self__;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->null_substitution_character());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::set_visible_focus() */
int lua_call1_Fl_Widget__set_visible_focus(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->set_visible_focus();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::paste(class Fl_Widget & receiver) */
int lua_call1_Fl__paste(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
    
     class Fl_Widget & receiver = ( class Fl_Widget & )(*lua_to_Fl_Widget(__S__, 1, &__ERROR__));
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    Fl::paste(receiver);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::paste(class Fl_Widget & receiver, int clipboard) */
int lua_call2_Fl__paste(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     class Fl_Widget & receiver = ( class Fl_Widget & )(*lua_to_Fl_Widget(__S__, 1, &__ERROR__));
     int clipboard;
    
    clipboard = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    Fl::paste(receiver, clipboard);
    lua_settop(__S__, 0);
    ;
    lua_push_Fl_Widget(__S__, &(receiver));
    return 1;
  }
  
error:
  return lua_call1_Fl__paste(__S__);
}
/* int Fl_Help_View::size()const  */
int lua_call1_Fl_Help_View__size(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Help_View * __self__;
    
    __self__ = ( class Fl_Help_View * )lua_to_Fl_Help_View(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->size());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Help_View::size(int W, int H) */
int lua_call2_Fl_Help_View__size(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Help_View * __self__;
     int W;
     int H;
    
    __self__ = ( class Fl_Help_View * )lua_to_Fl_Help_View(__S__, 1, &__ERROR__);
    W = ( int )(int)lua_tonumber(__S__, 2);
    H = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->size(W, H);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Help_View__size(__S__);
}
/*  Fl_Tabs::Fl_Tabs(int , int , int , int , const char * =0) */
int lua_call1_Fl_Tabs__Fl_Tabs(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int __1__;
     int __2__;
     int __3__;
     int __4__;
     char * __5__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Tabs(__S__, new Fl_Tabs(__1__, __2__, __3__, __4__));
      return 1;
    } else {
      __5__ = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Tabs(__S__, new Fl_Tabs(__1__, __2__, __3__, __4__, __5__));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Buffer::highlight_rectangular(int start, int end, int rectStart, int rectEnd) */
int lua_call1_Fl_Text_Buffer__highlight_rectangular(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Text_Buffer * __self__;
     int start;
     int end;
     int rectStart;
     int rectEnd;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    start = ( int )(int)lua_tonumber(__S__, 2);
    end = ( int )(int)lua_tonumber(__S__, 3);
    rectStart = ( int )(int)lua_tonumber(__S__, 4);
    rectEnd = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->highlight_rectangular(start, end, rectStart, rectEnd);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Spinner::Fl_Spinner(int X, int Y, int W, int H, const char * L=0) */
int lua_call1_Fl_Spinner__Fl_Spinner(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     char * L;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Spinner(__S__, new Fl_Spinner(X, Y, W, H));
      return 1;
    } else {
      L = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Spinner(__S__, new Fl_Spinner(X, Y, W, H, L));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Buffer::search_forward(int startPos, const char * searchString, int * foundPos, int matchCase=0) */
/* SKIPPED (argument #4) */
/* const char * Fl_File_Icon::pattern() */
int lua_call1_Fl_File_Icon__pattern(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Icon * __self__;
    
    __self__ = ( class Fl_File_Icon * )lua_to_Fl_File_Icon(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->pattern());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Output::Fl_Output(int X, int Y, int W, int H, const char * l=0) */
int lua_call1_Fl_Output__Fl_Output(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     char * l;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Output(__S__, new Fl_Output(X, Y, W, H));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Output(__S__, new Fl_Output(X, Y, W, H, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_Item::image(class Fl_Image & a) */
int lua_call1_Fl_Menu_Item__image(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
     class Fl_Image & a = ( class Fl_Image & )(*lua_to_Fl_Image(__S__, 2, &__ERROR__));
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->image(a);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_Item::image(class Fl_Image * a) */
int lua_call2_Fl_Menu_Item__image(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     struct Fl_Menu_Item * __self__;
     class Fl_Image * a;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    a = ( class Fl_Image * )lua_to_Fl_Image(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->image(a);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Menu_Item__image(__S__);
}
/* int Fl_Tooltip::font() */
int lua_call1_Fl_Tooltip__font(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Tooltip::font());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Tooltip::font(int i) */
int lua_call2_Fl_Tooltip__font(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     int i;
    
    i = ( int )(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    Fl_Tooltip::font(i);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Tooltip__font(__S__);
}
/* void Fl_Menu_::copy(const struct Fl_Menu_Item * m, void * user_data=0) */
int lua_call1_Fl_Menu___copy(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Menu_ * __self__;
     struct Fl_Menu_Item * m;
     void * user_data;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    m = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (nparam <= 2) {
      if (__ERROR__) goto error;
      
      __self__->copy(m);
    } else {
      if (__ERROR__) goto error;
      
      __self__->copy(m, user_data);
    }
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::redraw() */
int lua_call1_Fl__redraw(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    Fl::redraw();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color Fl_Input_Choice::textcolor()const  */
int lua_call1_Fl_Input_Choice__textcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Input_Choice * __self__;
    
    __self__ = ( class Fl_Input_Choice * )lua_to_Fl_Input_Choice(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textcolor());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Input_Choice::textcolor(Fl_Color c) */
int lua_call2_Fl_Input_Choice__textcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Input_Choice * __self__;
     Fl_Color c;
    
    __self__ = ( class Fl_Input_Choice * )lua_to_Fl_Input_Choice(__S__, 1, &__ERROR__);
    c = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textcolor(c);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Input_Choice__textcolor(__S__);
}
/* void Fl_Valuator::bounds(double a, double b) */
int lua_call1_Fl_Valuator__bounds(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Valuator * __self__;
     double a;
     double b;
    
    __self__ = ( class Fl_Valuator * )lua_to_Fl_Valuator(__S__, 1, &__ERROR__);
    a = ( double )(double)lua_tonumber(__S__, 2);
    b = ( double )(double)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->bounds(a, b);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Input_Choice::Fl_Input_Choice(int x, int y, int w, int h, const char * l=0) */
int lua_call1_Fl_Input_Choice__Fl_Input_Choice(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Input_Choice(__S__, new Fl_Input_Choice(x, y, w, h));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Input_Choice(__S__, new Fl_Input_Choice(x, y, w, h, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Shared_Image::uncache() */
int lua_call1_Fl_Shared_Image__uncache(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Shared_Image * __self__;
    
    __self__ = ( class Fl_Shared_Image * )lua_to_Fl_Shared_Image(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->uncache();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::event_button3() */
int lua_call1_Fl__event_button3(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::event_button3());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Browser_::scrollbar_width() */
int lua_call1_Fl_Browser___scrollbar_width(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Browser_::scrollbar_width());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser_::scrollbar_width(int b) */
int lua_call2_Fl_Browser___scrollbar_width(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     int b;
    
    b = ( int )(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    Fl_Browser_::scrollbar_width(b);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Browser___scrollbar_width(__S__);
}
/* void Fl_File_Icon::clear() */
int lua_call1_Fl_File_Icon__clear(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Icon * __self__;
    
    __self__ = ( class Fl_File_Icon * )lua_to_Fl_File_Icon(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->clear();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Valuator::range(double a, double b) */
int lua_call1_Fl_Valuator__range(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Valuator * __self__;
     double a;
     double b;
    
    __self__ = ( class Fl_Valuator * )lua_to_Fl_Valuator(__S__, 1, &__ERROR__);
    a = ( double )(double)lua_tonumber(__S__, 2);
    b = ( double )(double)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->range(a, b);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Window::size_range(int a, int b, int c=0, int d=0, int e=0, int f=0, int g=0) */
int lua_call1_Fl_Window__size_range(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Window * __self__;
     int a;
     int b;
     int c;
     int d;
     int e;
     int f;
     int g;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    a = ( int )(int)lua_tonumber(__S__, 2);
    b = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (nparam <= 3) {
      if (__ERROR__) goto error;
      
      __self__->size_range(a, b);
    } else {
      c = ( int )(int)lua_tonumber(__S__, 4);
      if (nparam <= 4) {
        if (__ERROR__) goto error;
        
        __self__->size_range(a, b, c);
      } else {
        d = ( int )(int)lua_tonumber(__S__, 5);
        if (nparam <= 5) {
          if (__ERROR__) goto error;
          
          __self__->size_range(a, b, c, d);
        } else {
          e = ( int )(int)lua_tonumber(__S__, 6);
          if (nparam <= 6) {
            if (__ERROR__) goto error;
            
            __self__->size_range(a, b, c, d, e);
          } else {
            f = ( int )(int)lua_tonumber(__S__, 7);
            if (nparam <= 7) {
              if (__ERROR__) goto error;
              
              __self__->size_range(a, b, c, d, e, f);
            } else {
              g = ( int )(int)lua_tonumber(__S__, 8);
              if (__ERROR__) goto error;
              
              __self__->size_range(a, b, c, d, e, f, g);
            }
          }
        }
      }
    }
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_Item::do_callback(class Fl_Widget * o)const  */
int lua_call1_Fl_Menu_Item__do_callback(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     struct Fl_Menu_Item * __self__;
     class Fl_Widget * o;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    o = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->do_callback(o);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_Item::do_callback(class Fl_Widget * o, void * arg)const  */
/* SKIPPED (argument #3) */
/* void Fl_Menu_Item::do_callback(class Fl_Widget * o, long arg)const  */
int lua_call3_Fl_Menu_Item__do_callback(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     struct Fl_Menu_Item * __self__;
     class Fl_Widget * o;
     long arg;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    o = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 2, &__ERROR__);
    arg = ( long )(long)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->do_callback(o, arg);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Menu_Item__do_callback(__S__);
}
/* int Fl_Adjuster::soft()const  */
int lua_call1_Fl_Adjuster__soft(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Adjuster * __self__;
    
    __self__ = ( class Fl_Adjuster * )lua_to_Fl_Adjuster(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->soft());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Adjuster::soft(int s) */
int lua_call2_Fl_Adjuster__soft(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Adjuster * __self__;
     int s;
    
    __self__ = ( class Fl_Adjuster * )lua_to_Fl_Adjuster(__S__, 1, &__ERROR__);
    s = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->soft(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Adjuster__soft(__S__);
}
/* void Fl_Text_Display::resize(int X, int Y, int W, int H) */
int lua_call1_Fl_Text_Display__resize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Text_Display * __self__;
     int X;
     int Y;
     int W;
     int H;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    X = ( int )(int)lua_tonumber(__S__, 2);
    Y = ( int )(int)lua_tonumber(__S__, 3);
    W = ( int )(int)lua_tonumber(__S__, 4);
    H = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->resize(X, Y, W, H);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Boxtype fl_down(Fl_Boxtype b) */
int lua_call1_fl_down(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     Fl_Boxtype b;
    
    b = ( Fl_Boxtype )(Fl_Boxtype)(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_down(b));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Color_Chooser::rgb2hsv(double , double , double , double & , double & , double & ) */
int lua_call1_Fl_Color_Chooser__rgb2hsv(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 6) goto error;
  {
     double __1__;
     double __2__;
     double __3__;
     double __4__;
     double __5__;
     double __6__;
    
    __1__ = ( double )(double)lua_tonumber(__S__, 1);
    __2__ = ( double )(double)lua_tonumber(__S__, 2);
    __3__ = ( double )(double)lua_tonumber(__S__, 3);
    __4__ = ( double )(double)lua_tonumber(__S__, 4);
    __5__ = ( double )(double)lua_tonumber(__S__, 5);
    __6__ = ( double )(double)lua_tonumber(__S__, 6);
    
    /* Actual call */
    Fl_Color_Chooser::rgb2hsv(__1__, __2__, __3__, __4__, __5__, __6__);
    lua_settop(__S__, 0);
    ;
    lua_pushnumber(__S__, __4__);
    lua_pushnumber(__S__, __5__);
    lua_pushnumber(__S__, __6__);
    return 3;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Display::insert_position() */
int lua_call1_Fl_Text_Display__insert_position(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Display * __self__;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->insert_position());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Display::insert_position(int newPos) */
int lua_call2_Fl_Text_Display__insert_position(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Display * __self__;
     int newPos;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    newPos = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->insert_position(newPos);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Text_Display__insert_position(__S__);
}
/* void Fl_Overlay_Window::flush() */
int lua_call1_Fl_Overlay_Window__flush(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Overlay_Window * __self__;
    
    __self__ = ( class Fl_Overlay_Window * )lua_to_Fl_Overlay_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->flush();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void * Fl::thread_message() */
/* SKIPPED (return type) */
/* const char * Fl::get_font_name(Fl_Font , int * attributes=0) */
int lua_call1_Fl__get_font_name(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     Fl_Font __1__;
     int * attributes;
    
    __1__ = ( Fl_Font )(Fl_Font)(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    if (nparam <= 1) {
      lua_settop(__S__, 0);
      lua_pushstring(__S__, (const char * ) Fl::get_font_name(__1__));
      return 1;
    } else {
      lua_settop(__S__, 0);
      lua_pushstring(__S__, (const char * ) Fl::get_font_name(__1__, attributes));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const class Fl_Widget * * Fl_Group::array()const  */
/* SKIPPED (return type) */
/*  Fl_Hold_Browser::Fl_Hold_Browser(int X, int Y, int W, int H, const char * l=0) */
int lua_call1_Fl_Hold_Browser__Fl_Hold_Browser(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     char * l;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Hold_Browser(__S__, new Fl_Hold_Browser(X, Y, W, H));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Hold_Browser(__S__, new Fl_Hold_Browser(X, Y, W, H, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Dial::handle(int ) */
int lua_call1_Fl_Dial__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Dial * __self__;
     int __2__;
    
    __self__ = ( class Fl_Dial * )lua_to_Fl_Dial(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* char Fl_Preferences::deleteEntry(const char * entry) */
int lua_call1_Fl_Preferences__deleteEntry(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Preferences * __self__;
     char * entry;
    
    __self__ = ( class Fl_Preferences * )lua_to_Fl_Preferences(__S__, 1, &__ERROR__);
    entry = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->deleteEntry(entry));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Clock_Output::Fl_Clock_Output(int x, int y, int w, int h, const char * l=0) */
int lua_call1_Fl_Clock_Output__Fl_Clock_Output(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Clock_Output(__S__, new Fl_Clock_Output(x, y, w, h));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Clock_Output(__S__, new Fl_Clock_Output(x, y, w, h, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::event_dx() */
int lua_call1_Fl__event_dx(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::event_dx());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_End::Fl_End() */
int lua_call1_Fl_End__Fl_End(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_End(__S__, new Fl_End());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Overlay_Window::redraw_overlay() */
int lua_call1_Fl_Overlay_Window__redraw_overlay(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Overlay_Window * __self__;
    
    __self__ = ( class Fl_Overlay_Window * )lua_to_Fl_Overlay_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->redraw_overlay();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Valuator::precision(int ) */
int lua_call1_Fl_Valuator__precision(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Valuator * __self__;
     int __2__;
    
    __self__ = ( class Fl_Valuator * )lua_to_Fl_Valuator(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->precision(__2__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::event_button2() */
int lua_call1_Fl__event_button2(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::event_button2());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_message_font(unsigned char f, unsigned char s) */
int lua_call1_fl_message_font(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     unsigned char f;
     unsigned char s;
    
    f = ( unsigned char )(char)lua_tonumber(__S__, 1);
    s = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    fl_message_font(f, s);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color fl_rgb_color(uchar g) */
int lua_call1_fl_rgb_color(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     unsigned char g;
    
    g = ( unsigned char )(char)lua_tonumber(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_rgb_color(g));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color fl_rgb_color(uchar r, uchar g, uchar b) */
int lua_call2_fl_rgb_color(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 3) goto error;
  {
     unsigned char r;
     unsigned char g;
     unsigned char b;
    
    r = ( unsigned char )(char)lua_tonumber(__S__, 1);
    g = ( unsigned char )(char)lua_tonumber(__S__, 2);
    b = ( unsigned char )(char)lua_tonumber(__S__, 3);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_rgb_color(r, g, b));
    return 1;
  }
  
error:
  return lua_call1_fl_rgb_color(__S__);
}
/* void Fl::release() */
int lua_call1_Fl__release(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    Fl::release();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Widget::takesevents()const  */
int lua_call1_Fl_Widget__takesevents(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->takesevents());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Group::begin() */
int lua_call1_Fl_Group__begin(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Group * __self__;
    
    __self__ = ( class Fl_Group * )lua_to_Fl_Group(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->begin();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  ( Fl_Preferences::Name::operator constchar*)() */
/* SKIPPED (operator) */
/* void Fl_Window::show() */
int lua_call1_Fl_Window__show(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Window * __self__;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->show();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Window::show(int , char * * ) */
/* SKIPPED (argument #3) */
/* int Fl_Widget::w()const  */
int lua_call1_Fl_Widget__w(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->w());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Buffer::remove(int start, int end) */
int lua_call1_Fl_Text_Buffer__remove(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Text_Buffer * __self__;
     int start;
     int end;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    start = ( int )(int)lua_tonumber(__S__, 2);
    end = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->remove(start, end);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Scrollbar::handle(int ) */
int lua_call1_Fl_Scrollbar__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Scrollbar * __self__;
     int __2__;
    
    __self__ = ( class Fl_Scrollbar * )lua_to_Fl_Scrollbar(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* double Fl_Spinner::minimum()const  */
int lua_call1_Fl_Spinner__minimum(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Spinner * __self__;
    
    __self__ = ( class Fl_Spinner * )lua_to_Fl_Spinner(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->minimum());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Spinner::minimum(double m) */
int lua_call2_Fl_Spinner__minimum(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Spinner * __self__;
     double m;
    
    __self__ = ( class Fl_Spinner * )lua_to_Fl_Spinner(__S__, 1, &__ERROR__);
    m = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->minimum(m);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Spinner__minimum(__S__);
}
/* uchar Fl_Value_Slider::textsize()const  */
int lua_call1_Fl_Value_Slider__textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Value_Slider * __self__;
    
    __self__ = ( class Fl_Value_Slider * )lua_to_Fl_Value_Slider(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textsize());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Value_Slider::textsize(uchar s) */
int lua_call2_Fl_Value_Slider__textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Value_Slider * __self__;
     unsigned char s;
    
    __self__ = ( class Fl_Value_Slider * )lua_to_Fl_Value_Slider(__S__, 1, &__ERROR__);
    s = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textsize(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Value_Slider__textsize(__S__);
}
/*  Fl_Choice::Fl_Choice(int , int , int , int , const char * =0) */
int lua_call1_Fl_Choice__Fl_Choice(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int __1__;
     int __2__;
     int __3__;
     int __4__;
     char * __5__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Choice(__S__, new Fl_Choice(__1__, __2__, __3__, __4__));
      return 1;
    } else {
      __5__ = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Choice(__S__, new Fl_Choice(__1__, __2__, __3__, __4__, __5__));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color fl_color() */
int lua_call1_fl_color(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_color());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_color(int c) */
int lua_call2_fl_color(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     int c;
    
    c = ( int )(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    fl_color(c);
    ;
    return 0;
  }
  
error:
  return lua_call1_fl_color(__S__);
}
/* void fl_color(Fl_Color ) */
int lua_call3_fl_color(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     Fl_Color __1__;
    
    __1__ = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    fl_color(__1__);
    ;
    return 0;
  }
  
error:
  return lua_call2_fl_color(__S__);
}
/* void fl_color(uchar , uchar , uchar ) */
int lua_call4_fl_color(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 3) goto error;
  {
     unsigned char __1__;
     unsigned char __2__;
     unsigned char __3__;
    
    __1__ = ( unsigned char )(char)lua_tonumber(__S__, 1);
    __2__ = ( unsigned char )(char)lua_tonumber(__S__, 2);
    __3__ = ( unsigned char )(char)lua_tonumber(__S__, 3);
    
    /* Actual call */
    fl_color(__1__, __2__, __3__);
    ;
    return 0;
  }
  
error:
  return lua_call3_fl_color(__S__);
}
/* void Fl_Widget::draw() */
int lua_call1_Fl_Widget__draw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->draw();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_File_Icon * Fl_File_Icon::find(const char * filename, int filetype=ANY) */
int lua_call1_Fl_File_Icon__find(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * filename;
     int filetype;
    
    filename = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    if (nparam <= 1) {
      lua_settop(__S__, 0);
      lua_push_Fl_File_Icon(__S__, Fl_File_Icon::find(filename));
      return 1;
    } else {
      filetype = ( int )(int)lua_tonumber(__S__, 2);
      lua_settop(__S__, 0);
      lua_push_Fl_File_Icon(__S__, Fl_File_Icon::find(filename, filetype));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Shared_Image::add_handler(Fl_Shared_Handler f) */
/* SKIPPED (argument #1) */
/* uchar Fl_Chart::textsize()const  */
int lua_call1_Fl_Chart__textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Chart * __self__;
    
    __self__ = ( class Fl_Chart * )lua_to_Fl_Chart(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textsize());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Chart::textsize(uchar s) */
int lua_call2_Fl_Chart__textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Chart * __self__;
     unsigned char s;
    
    __self__ = ( class Fl_Chart * )lua_to_Fl_Chart(__S__, 1, &__ERROR__);
    s = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textsize(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Chart__textsize(__S__);
}
/* int Fl::event_buttons() */
int lua_call1_Fl__event_buttons(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::event_buttons());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_end_line() */
int lua_call1_fl_end_line(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    fl_end_line();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::arg(int , char * * , int & ) */
/* SKIPPED (argument #2) */
/*  Fl_GIF_Image::Fl_GIF_Image(const char * filename) */
int lua_call1_Fl_GIF_Image__Fl_GIF_Image(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * filename;
    
    filename = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_GIF_Image(__S__, new Fl_GIF_Image(filename));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Value_Output::Fl_Value_Output(int x, int y, int w, int h, const char * l=0) */
int lua_call1_Fl_Value_Output__Fl_Value_Output(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Value_Output(__S__, new Fl_Value_Output(x, y, w, h));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Value_Output(__S__, new Fl_Value_Output(x, y, w, h, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Value_Output::handle(int ) */
int lua_call1_Fl_Value_Output__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Value_Output * __self__;
     int __2__;
    
    __self__ = ( class Fl_Value_Output * )lua_to_Fl_Value_Output(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Image * Fl_Tiled_Image::copy() */
int lua_call1_Fl_Tiled_Image__copy(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Tiled_Image * __self__;
    
    __self__ = ( class Fl_Tiled_Image * )lua_to_Fl_Tiled_Image(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Image(__S__, __self__->copy());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Image * Fl_Tiled_Image::copy(int W, int H) */
int lua_call2_Fl_Tiled_Image__copy(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Tiled_Image * __self__;
     int W;
     int H;
    
    __self__ = ( class Fl_Tiled_Image * )lua_to_Fl_Tiled_Image(__S__, 1, &__ERROR__);
    W = ( int )(int)lua_tonumber(__S__, 2);
    H = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Image(__S__, __self__->copy(W, H));
    return 1;
  }
  
error:
  return lua_call1_Fl_Tiled_Image__copy(__S__);
}
/* void Fl::add_check(Fl_Timeout_Handler , void * =0) */
/* SKIPPED (argument #1) */
/* void Fl_FormsBitmap::set(int W, int H, const uchar * bits) */
int lua_call1_Fl_FormsBitmap__set(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 4) goto error;
  {
     class Fl_FormsBitmap * __self__;
     int W;
     int H;
     unsigned char * bits;
    
    __self__ = ( class Fl_FormsBitmap * )lua_to_Fl_FormsBitmap(__S__, 1, &__ERROR__);
    W = ( int )(int)lua_tonumber(__S__, 2);
    H = ( int )(int)lua_tonumber(__S__, 3);
    bits = ( unsigned char * )(char  *)lua_tostring(__S__, 4);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->set(W, H, bits);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Font Fl_Chart::textfont()const  */
int lua_call1_Fl_Chart__textfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Chart * __self__;
    
    __self__ = ( class Fl_Chart * )lua_to_Fl_Chart(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textfont());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Chart::textfont(uchar s) */
int lua_call2_Fl_Chart__textfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Chart * __self__;
     unsigned char s;
    
    __self__ = ( class Fl_Chart * )lua_to_Fl_Chart(__S__, 1, &__ERROR__);
    s = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textfont(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Chart__textfont(__S__);
}
/* int Fl_Menu_::add(const char * ) */
int lua_call1_Fl_Menu___add(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Menu_ * __self__;
     char * __2__;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    __2__ = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->add(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Menu_::add(const char * a, const char * b, Fl_Callback * c, void * d=0, int e=0) */
/* SKIPPED (argument #4) */
/* int Fl_Menu_::add(const char * , int shortcut, Fl_Callback * , void * =0, int =0) */
/* SKIPPED (argument #4) */
/* void Fl_Text_Buffer::remove_rectangular(int start, int end, int rectStart, int rectEnd) */
int lua_call1_Fl_Text_Buffer__remove_rectangular(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Text_Buffer * __self__;
     int start;
     int end;
     int rectStart;
     int rectEnd;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    start = ( int )(int)lua_tonumber(__S__, 2);
    end = ( int )(int)lua_tonumber(__S__, 3);
    rectStart = ( int )(int)lua_tonumber(__S__, 4);
    rectEnd = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->remove_rectangular(start, end, rectStart, rectEnd);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Boxtype fl_define_FL_RFLAT_BOX() */
int lua_call1_fl_define_FL_RFLAT_BOX(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_define_FL_RFLAT_BOX());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* HDC fl_GetDC(Window ) */
/* SKIPPED (return type) */
/*  Fl_FormsBitmap::Fl_FormsBitmap(Fl_Boxtype , int , int , int , int , const char * =0) */
int lua_call1_Fl_FormsBitmap__Fl_FormsBitmap(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 5) goto error;
  {
     Fl_Boxtype __1__;
     int __2__;
     int __3__;
     int __4__;
     int __5__;
     char * __6__;
    
    __1__ = ( Fl_Boxtype )(Fl_Boxtype)(int)lua_tonumber(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    __5__ = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (nparam <= 5) {
      lua_settop(__S__, 0);
      lua_push_Fl_FormsBitmap(__S__, new Fl_FormsBitmap(__1__, __2__, __3__, __4__, __5__));
      return 1;
    } else {
      __6__ = ( char * )(char  *)lua_tostring(__S__, 6);
      lua_settop(__S__, 0);
      lua_push_Fl_FormsBitmap(__S__, new Fl_FormsBitmap(__1__, __2__, __3__, __4__, __5__, __6__));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Editor::handle(int e) */
int lua_call1_Fl_Text_Editor__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Editor * __self__;
     int e;
    
    __self__ = ( class Fl_Text_Editor * )lua_to_Fl_Text_Editor(__S__, 1, &__ERROR__);
    e = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(e));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Boxtype Fl_Button::down_box()const  */
int lua_call1_Fl_Button__down_box(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Button * __self__;
    
    __self__ = ( class Fl_Button * )lua_to_Fl_Button(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->down_box());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Button::down_box(Fl_Boxtype b) */
int lua_call2_Fl_Button__down_box(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Button * __self__;
     Fl_Boxtype b;
    
    __self__ = ( class Fl_Button * )lua_to_Fl_Button(__S__, 1, &__ERROR__);
    b = ( Fl_Boxtype )(Fl_Boxtype)(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->down_box(b);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Button__down_box(__S__);
}
/* Fl_Boxtype Fl_Input_Choice::down_box()const  */
int lua_call1_Fl_Input_Choice__down_box(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Input_Choice * __self__;
    
    __self__ = ( class Fl_Input_Choice * )lua_to_Fl_Input_Choice(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->down_box());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Input_Choice::down_box(Fl_Boxtype b) */
int lua_call2_Fl_Input_Choice__down_box(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Input_Choice * __self__;
     Fl_Boxtype b;
    
    __self__ = ( class Fl_Input_Choice * )lua_to_Fl_Input_Choice(__S__, 1, &__ERROR__);
    b = ( Fl_Boxtype )(Fl_Boxtype)(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->down_box(b);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Input_Choice__down_box(__S__);
}
/* Fl_Font Fl_Menu_::textfont()const  */
int lua_call1_Fl_Menu___textfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Menu_ * __self__;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textfont());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_::textfont(uchar c) */
int lua_call2_Fl_Menu___textfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Menu_ * __self__;
     unsigned char c;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    c = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textfont(c);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Menu___textfont(__S__);
}
/* void Fl_Chart::bounds(double a, double b) */
int lua_call1_Fl_Chart__bounds(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Chart * __self__;
     double a;
     double b;
    
    __self__ = ( class Fl_Chart * )lua_to_Fl_Chart(__S__, 1, &__ERROR__);
    a = ( double )(double)lua_tonumber(__S__, 2);
    b = ( double )(double)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->bounds(a, b);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Chart::bounds(double * a, double * b)const  */
/* SKIPPED (argument #2) */
/*  Fl_Secret_Input::Fl_Secret_Input(int X, int Y, int W, int H, const char * l=0) */
int lua_call1_Fl_Secret_Input__Fl_Secret_Input(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     char * l;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Secret_Input(__S__, new Fl_Secret_Input(X, Y, W, H));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Secret_Input(__S__, new Fl_Secret_Input(X, Y, W, H, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Widget::y()const  */
int lua_call1_Fl_Widget__y(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->y());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_Item::uncheck() */
int lua_call1_Fl_Menu_Item__uncheck(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->uncheck();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Value_Input::resize(int , int , int , int ) */
int lua_call1_Fl_Value_Input__resize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Value_Input * __self__;
     int __2__;
     int __3__;
     int __4__;
     int __5__;
    
    __self__ = ( class Fl_Value_Input * )lua_to_Fl_Value_Input(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    __5__ = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->resize(__2__, __3__, __4__, __5__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Image::label(class Fl_Widget * w) */
int lua_call1_Fl_Image__label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Image * __self__;
     class Fl_Widget * w;
    
    __self__ = ( class Fl_Image * )lua_to_Fl_Image(__S__, 1, &__ERROR__);
    w = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->label(w);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Image::label(struct Fl_Menu_Item * m) */
int lua_call2_Fl_Image__label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Image * __self__;
     struct Fl_Menu_Item * m;
    
    __self__ = ( class Fl_Image * )lua_to_Fl_Image(__S__, 1, &__ERROR__);
    m = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->label(m);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Image__label(__S__);
}
/* char Fl_Browser::format_char()const  */
int lua_call1_Fl_Browser__format_char(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Browser * __self__;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->format_char());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser::format_char(char c) */
int lua_call2_Fl_Browser__format_char(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Browser * __self__;
     char c;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    c = ( char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->format_char(c);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Browser__format_char(__S__);
}
/* class Fl_Widget * Fl_Tabs::push()const  */
int lua_call1_Fl_Tabs__push(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Tabs * __self__;
    
    __self__ = ( class Fl_Tabs * )lua_to_Fl_Tabs(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Widget(__S__, __self__->push());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Tabs::push(class Fl_Widget * ) */
int lua_call2_Fl_Tabs__push(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Tabs * __self__;
     class Fl_Widget * __2__;
    
    __self__ = ( class Fl_Tabs * )lua_to_Fl_Tabs(__S__, 1, &__ERROR__);
    __2__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->push(__2__));
    return 1;
  }
  
error:
  return lua_call1_Fl_Tabs__push(__S__);
}
/* class Fl_Image * Fl_Widget::deimage() */
int lua_call1_Fl_Widget__deimage(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Image(__S__, __self__->deimage());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::deimage(class Fl_Image & a) */
int lua_call2_Fl_Widget__deimage(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
     class Fl_Image & a = ( class Fl_Image & )(*lua_to_Fl_Image(__S__, 2, &__ERROR__));
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->deimage(a);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Widget__deimage(__S__);
}
/* void Fl_Widget::deimage(class Fl_Image * a) */
int lua_call3_Fl_Widget__deimage(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Widget * __self__;
     class Fl_Image * a;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    a = ( class Fl_Image * )lua_to_Fl_Image(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->deimage(a);
    ;
    return 0;
  }
  
error:
  return lua_call2_Fl_Widget__deimage(__S__);
}
/* uchar * fl_read_image(uchar * p, int x, int y, int w, int h, int alpha=0) */
/* short * Fl_File_Icon::value() */
/* SKIPPED (return type) */
/* int Fl_Help_Dialog::h() */
int lua_call1_Fl_Help_Dialog__h(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Help_Dialog * __self__;
    
    __self__ = ( class Fl_Help_Dialog * )lua_to_Fl_Help_Dialog(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->h());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Buffer::replace_rectangular(int start, int end, int rectStart, int rectEnd, const char * text) */
int lua_call1_Fl_Text_Buffer__replace_rectangular(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 6) goto error;
  {
     class Fl_Text_Buffer * __self__;
     int start;
     int end;
     int rectStart;
     int rectEnd;
     char * text;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    start = ( int )(int)lua_tonumber(__S__, 2);
    end = ( int )(int)lua_tonumber(__S__, 3);
    rectStart = ( int )(int)lua_tonumber(__S__, 4);
    rectEnd = ( int )(int)lua_tonumber(__S__, 5);
    text = ( char * )(char  *)lua_tostring(__S__, 6);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->replace_rectangular(start, end, rectStart, rectEnd, text);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser_::scrollbar_right() */
int lua_call1_Fl_Browser___scrollbar_right(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Browser_ * __self__;
    
    __self__ = ( class Fl_Browser_ * )lua_to_Fl_Browser_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->scrollbar_right();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* double fl_transform_dx(double x, double y) */
int lua_call1_fl_transform_dx(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     double x;
     double y;
    
    x = ( double )(double)lua_tonumber(__S__, 1);
    y = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_transform_dx(x, y));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int fl_casealphasort(struct dirent * * , struct dirent * * ) */
/* SKIPPED (argument #1) */
/* int fl_font() */
int lua_call1_fl_font(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_font());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_font(int face, int size) */
int lua_call2_fl_font(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int face;
     int size;
    
    face = ( int )(int)lua_tonumber(__S__, 1);
    size = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    fl_font(face, size);
    ;
    return 0;
  }
  
error:
  return lua_call1_fl_font(__S__);
}
/* void Fl_Value_Slider::draw() */
int lua_call1_Fl_Value_Slider__draw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Value_Slider * __self__;
    
    __self__ = ( class Fl_Value_Slider * )lua_to_Fl_Value_Slider(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->draw();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_RGB_Image::Fl_RGB_Image(const uchar * bits, int W, int H, int D=3, int LD=0) */
int lua_call1_Fl_RGB_Image__Fl_RGB_Image(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 3) goto error;
  {
     unsigned char * bits;
     int W;
     int H;
     int D;
     int LD;
    
    bits = ( unsigned char * )(char  *)lua_tostring(__S__, 1);
    W = ( int )(int)lua_tonumber(__S__, 2);
    H = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (nparam <= 3) {
      lua_settop(__S__, 0);
      lua_push_Fl_RGB_Image(__S__, new Fl_RGB_Image(bits, W, H));
      return 1;
    } else {
      D = ( int )(int)lua_tonumber(__S__, 4);
      if (nparam <= 4) {
        lua_settop(__S__, 0);
        lua_push_Fl_RGB_Image(__S__, new Fl_RGB_Image(bits, W, H, D));
        return 1;
      } else {
        LD = ( int )(int)lua_tonumber(__S__, 5);
        lua_settop(__S__, 0);
        lua_push_Fl_RGB_Image(__S__, new Fl_RGB_Image(bits, W, H, D, LD));
        return 1;
      }
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Chart::Fl_Chart(int , int , int , int , const char * =0) */
int lua_call1_Fl_Chart__Fl_Chart(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int __1__;
     int __2__;
     int __3__;
     int __4__;
     char * __5__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Chart(__S__, new Fl_Chart(__1__, __2__, __3__, __4__));
      return 1;
    } else {
      __5__ = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Chart(__S__, new Fl_Chart(__1__, __2__, __3__, __4__, __5__));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const char * Fl::get_font(Fl_Font ) */
int lua_call1_Fl__get_font(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     Fl_Font __1__;
    
    __1__ = ( Fl_Font )(Fl_Font)(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) Fl::get_font(__1__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const char * fl_filename_name(const char * ) */
int lua_call1_fl_filename_name(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * __1__;
    
    __1__ = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) fl_filename_name(__1__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Single_Window::flush() */
int lua_call1_Fl_Single_Window__flush(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Single_Window * __self__;
    
    __self__ = ( class Fl_Single_Window * )lua_to_Fl_Single_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->flush();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Buffer::highlight_position(int * start, int * end) */
/* SKIPPED (argument #2) */
/* int Fl_Text_Buffer::highlight_position(int * start, int * end, int * isRect, int * rectStart, int * rectEnd) */
/* SKIPPED (argument #2) */
/* void Fl_Tiled_Image::draw(int X, int Y) */
int lua_call1_Fl_Tiled_Image__draw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Tiled_Image * __self__;
     int X;
     int Y;
    
    __self__ = ( class Fl_Tiled_Image * )lua_to_Fl_Tiled_Image(__S__, 1, &__ERROR__);
    X = ( int )(int)lua_tonumber(__S__, 2);
    Y = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->draw(X, Y);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Tiled_Image::draw(int X, int Y, int W, int H, int cx, int cy) */
int lua_call2_Fl_Tiled_Image__draw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 7) goto error;
  {
     class Fl_Tiled_Image * __self__;
     int X;
     int Y;
     int W;
     int H;
     int cx;
     int cy;
    
    __self__ = ( class Fl_Tiled_Image * )lua_to_Fl_Tiled_Image(__S__, 1, &__ERROR__);
    X = ( int )(int)lua_tonumber(__S__, 2);
    Y = ( int )(int)lua_tonumber(__S__, 3);
    W = ( int )(int)lua_tonumber(__S__, 4);
    H = ( int )(int)lua_tonumber(__S__, 5);
    cx = ( int )(int)lua_tonumber(__S__, 6);
    cy = ( int )(int)lua_tonumber(__S__, 7);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->draw(X, Y, W, H, cx, cy);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Tiled_Image__draw(__S__);
}
/* void Fl_Browser::lineposition(int , Fl_Browser::Fl_Line_Position ) */
int lua_call1_Fl_Browser__lineposition(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Browser * __self__;
     int __2__;
     Fl_Browser::Fl_Line_Position __3__;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( Fl_Browser::Fl_Line_Position )(Fl_Browser::Fl_Line_Position)(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->lineposition(__2__, __3__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser::display(int , int =1) */
int lua_call1_Fl_Browser__display(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Browser * __self__;
     int __2__;
     int __3__;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (nparam <= 2) {
      if (__ERROR__) goto error;
      
      __self__->display(__2__);
    } else {
      __3__ = ( int )(int)lua_tonumber(__S__, 3);
      if (__ERROR__) goto error;
      
      __self__->display(__2__, __3__);
    }
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* float Fl_Tooltip::hoverdelay() */
int lua_call1_Fl_Tooltip__hoverdelay(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Tooltip::hoverdelay());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Tooltip::hoverdelay(float f) */
int lua_call2_Fl_Tooltip__hoverdelay(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     float f;
    
    f = ( float )(float)lua_tonumber(__S__, 1);
    
    /* Actual call */
    Fl_Tooltip::hoverdelay(f);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Tooltip__hoverdelay(__S__);
}
/* void Fl_Browser::clear() */
int lua_call1_Fl_Browser__clear(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Browser * __self__;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->clear();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* uchar Fl_Value_Input::textsize()const  */
int lua_call1_Fl_Value_Input__textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Value_Input * __self__;
    
    __self__ = ( class Fl_Value_Input * )lua_to_Fl_Value_Input(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textsize());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Value_Input::textsize(uchar s) */
int lua_call2_Fl_Value_Input__textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Value_Input * __self__;
     unsigned char s;
    
    __self__ = ( class Fl_Value_Input * )lua_to_Fl_Value_Input(__S__, 1, &__ERROR__);
    s = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textsize(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Value_Input__textsize(__S__);
}
/* void Fl_Widget::draw_label(int , int , int , int , Fl_Align )const  */
int lua_call1_Fl_Widget__draw_label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 6) goto error;
  {
     class Fl_Widget * __self__;
     int __2__;
     int __3__;
     int __4__;
     int __5__;
     Fl_Align __6__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    __5__ = ( int )(int)lua_tonumber(__S__, 5);
    __6__ = ( Fl_Align )(Fl_Align)(int)lua_tonumber(__S__, 6);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->draw_label(__2__, __3__, __4__, __5__, __6__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Spinner::handle(int event) */
int lua_call1_Fl_Spinner__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Spinner * __self__;
     int event;
    
    __self__ = ( class Fl_Spinner * )lua_to_Fl_Spinner(__S__, 1, &__ERROR__);
    event = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(event));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Buffer::word_start(int pos) */
int lua_call1_Fl_Text_Buffer__word_start(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Buffer * __self__;
     int pos;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    pos = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->word_start(pos));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser::add(const char * , void * =0) */
int lua_call1_Fl_Browser__add(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Browser * __self__;
     char * __2__;
     void * __3__;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    __2__ = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (nparam <= 2) {
      if (__ERROR__) goto error;
      
      __self__->add(__2__);
    } else {
      if (__ERROR__) goto error;
      
      __self__->add(__2__, __3__);
    }
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Tiled_Image::desaturate() */
int lua_call1_Fl_Tiled_Image__desaturate(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Tiled_Image * __self__;
    
    __self__ = ( class Fl_Tiled_Image * )lua_to_Fl_Tiled_Image(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->desaturate();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const char * Fl_Help_View::title() */
int lua_call1_Fl_Help_View__title(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Help_View * __self__;
    
    __self__ = ( class Fl_Help_View * )lua_to_Fl_Help_View(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->title());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_point(int x, int y) */
int lua_call1_fl_point(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int x;
     int y;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    fl_point(x, y);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Shared_Image * Fl_Shared_Image::find(const char * n, int W=0, int H=0) */
int lua_call1_Fl_Shared_Image__find(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * n;
     int W;
     int H;
    
    n = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    if (nparam <= 1) {
      lua_settop(__S__, 0);
      lua_push_Fl_Shared_Image(__S__, Fl_Shared_Image::find(n));
      return 1;
    } else {
      W = ( int )(int)lua_tonumber(__S__, 2);
      if (nparam <= 2) {
        lua_settop(__S__, 0);
        lua_push_Fl_Shared_Image(__S__, Fl_Shared_Image::find(n, W));
        return 1;
      } else {
        H = ( int )(int)lua_tonumber(__S__, 3);
        lua_settop(__S__, 0);
        lua_push_Fl_Shared_Image(__S__, Fl_Shared_Image::find(n, W, H));
        return 1;
      }
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_circle(double x, double y, double r) */
int lua_call1_fl_circle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 3) goto error;
  {
     double x;
     double y;
     double r;
    
    x = ( double )(double)lua_tonumber(__S__, 1);
    y = ( double )(double)lua_tonumber(__S__, 2);
    r = ( double )(double)lua_tonumber(__S__, 3);
    
    /* Actual call */
    fl_circle(x, y, r);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Round_Clock::Fl_Round_Clock(int x, int y, int w, int h, const char * l=0) */
int lua_call1_Fl_Round_Clock__Fl_Round_Clock(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Round_Clock(__S__, new Fl_Round_Clock(x, y, w, h));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Round_Clock(__S__, new Fl_Round_Clock(x, y, w, h, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Radio_Light_Button::Fl_Radio_Light_Button(int X, int Y, int W, int H, const char * l=0) */
int lua_call1_Fl_Radio_Light_Button__Fl_Radio_Light_Button(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     char * l;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Radio_Light_Button(__S__, new Fl_Radio_Light_Button(X, Y, W, H));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Radio_Light_Button(__S__, new Fl_Radio_Light_Button(X, Y, W, H, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Widget::contains(const class Fl_Widget * )const  */
int lua_call1_Fl_Widget__contains(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Widget * __self__;
     class Fl_Widget * __2__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    __2__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->contains(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Pixmap::draw(int X, int Y) */
int lua_call1_Fl_Pixmap__draw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Pixmap * __self__;
     int X;
     int Y;
    
    __self__ = ( class Fl_Pixmap * )lua_to_Fl_Pixmap(__S__, 1, &__ERROR__);
    X = ( int )(int)lua_tonumber(__S__, 2);
    Y = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->draw(X, Y);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Pixmap::draw(int X, int Y, int W, int H, int cx=0, int cy=0) */
int lua_call2_Fl_Pixmap__draw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Pixmap * __self__;
     int X;
     int Y;
     int W;
     int H;
     int cx;
     int cy;
    
    __self__ = ( class Fl_Pixmap * )lua_to_Fl_Pixmap(__S__, 1, &__ERROR__);
    X = ( int )(int)lua_tonumber(__S__, 2);
    Y = ( int )(int)lua_tonumber(__S__, 3);
    W = ( int )(int)lua_tonumber(__S__, 4);
    H = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (nparam <= 5) {
      if (__ERROR__) goto error;
      
      __self__->draw(X, Y, W, H);
    } else {
      cx = ( int )(int)lua_tonumber(__S__, 6);
      if (nparam <= 6) {
        if (__ERROR__) goto error;
        
        __self__->draw(X, Y, W, H, cx);
      } else {
        cy = ( int )(int)lua_tonumber(__S__, 7);
        if (__ERROR__) goto error;
        
        __self__->draw(X, Y, W, H, cx, cy);
      }
    }
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Pixmap__draw(__S__);
}
/* class Fl_Widget * fl_message_icon() */
int lua_call1_fl_message_icon(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_Widget(__S__, fl_message_icon());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Labeltype fl_define_FL_ENGRAVED_LABEL() */
int lua_call1_fl_define_FL_ENGRAVED_LABEL(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_define_FL_ENGRAVED_LABEL());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Box::handle(int ) */
int lua_call1_Fl_Box__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Box * __self__;
     int __2__;
    
    __self__ = ( class Fl_Box * )lua_to_Fl_Box(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Text_Selection * Fl_Text_Buffer::highlight_selection() */
int lua_call1_Fl_Text_Buffer__highlight_selection(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Buffer * __self__;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Text_Selection(__S__, __self__->highlight_selection());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* double Fl_Positioner::xvalue()const  */
int lua_call1_Fl_Positioner__xvalue(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Positioner * __self__;
    
    __self__ = ( class Fl_Positioner * )lua_to_Fl_Positioner(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->xvalue());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Positioner::xvalue(double ) */
int lua_call2_Fl_Positioner__xvalue(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Positioner * __self__;
     double __2__;
    
    __self__ = ( class Fl_Positioner * )lua_to_Fl_Positioner(__S__, 1, &__ERROR__);
    __2__ = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->xvalue(__2__));
    return 1;
  }
  
error:
  return lua_call1_Fl_Positioner__xvalue(__S__);
}
/* int Fl::event_original_key() */
int lua_call1_Fl__event_original_key(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::event_original_key());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Help_Dialog::show() */
int lua_call1_Fl_Help_Dialog__show(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Help_Dialog * __self__;
    
    __self__ = ( class Fl_Help_Dialog * )lua_to_Fl_Help_Dialog(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->show();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Help_Dialog::show(int argc, char * * argv) */
/* SKIPPED (argument #3) */
/* int Fl_Window::border()const  */
int lua_call1_Fl_Window__border(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Window * __self__;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->border());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Window::border(int b) */
int lua_call2_Fl_Window__border(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Window * __self__;
     int b;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    b = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->border(b);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Window__border(__S__);
}
/* int Fl_Text_Buffer::findchars_backward(int startPos, const char * searchChars, int * foundPos) */
/* SKIPPED (argument #4) */
/*  Fl_Input_::Fl_Input_(int , int , int , int , const char * =0) */
/* SKIPPED (pure virtual class) */
/* int Fl_Choice::value()const  */
int lua_call1_Fl_Choice__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Choice * __self__;
    
    __self__ = ( class Fl_Choice * )lua_to_Fl_Choice(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->value());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Choice::value(const struct Fl_Menu_Item * ) */
int lua_call2_Fl_Choice__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Choice * __self__;
     struct Fl_Menu_Item * __2__;
    
    __self__ = ( class Fl_Choice * )lua_to_Fl_Choice(__S__, 1, &__ERROR__);
    __2__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->value(__2__));
    return 1;
  }
  
error:
  return lua_call1_Fl_Choice__value(__S__);
}
/* int Fl_Choice::value(int i) */
int lua_call3_Fl_Choice__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Choice * __self__;
     int i;
    
    __self__ = ( class Fl_Choice * )lua_to_Fl_Choice(__S__, 1, &__ERROR__);
    i = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->value(i));
    return 1;
  }
  
error:
  return lua_call2_Fl_Choice__value(__S__);
}
/* int Fl::event() */
int lua_call1_Fl__event(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::event());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser::show() */
int lua_call1_Fl_Browser__show(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Browser * __self__;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->show();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser::show(int n) */
int lua_call2_Fl_Browser__show(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Browser * __self__;
     int n;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    n = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->show(n);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Browser__show(__S__);
}
/* Fl_Color Fl_File_Chooser::color() */
int lua_call1_Fl_File_Chooser__color(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Chooser * __self__;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->color());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_File_Chooser::color(Fl_Color c) */
int lua_call2_Fl_File_Chooser__color(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_File_Chooser * __self__;
     Fl_Color c;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    c = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->color(c);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_File_Chooser__color(__S__);
}
/*  Fl_Preferences::Fl_Preferences(class Fl_Preferences * , const char * group) */
int lua_call1_Fl_Preferences__Fl_Preferences(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     class Fl_Preferences * __1__;
     char * group;
    
    __1__ = ( class Fl_Preferences * )lua_to_Fl_Preferences(__S__, 1, &__ERROR__);
    group = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Preferences(__S__, new Fl_Preferences(__1__, group));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Preferences::Fl_Preferences(class Fl_Preferences & , const char * group) */
int lua_call2_Fl_Preferences__Fl_Preferences(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     class Fl_Preferences & __1__ = ( class Fl_Preferences & )(*lua_to_Fl_Preferences(__S__, 1, &__ERROR__));
     char * group;
    
    group = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Preferences(__S__, new Fl_Preferences(__1__, group));
    lua_push_Fl_Preferences(__S__, &(__1__));
    return 2;
  }
  
error:
  return lua_call1_Fl_Preferences__Fl_Preferences(__S__);
}
/*  Fl_Preferences::Fl_Preferences(const char * path, const char * vendor, const char * application) */
int lua_call3_Fl_Preferences__Fl_Preferences(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 3) goto error;
  {
     char * path;
     char * vendor;
     char * application;
    
    path = ( char * )(char  *)lua_tostring(__S__, 1);
    vendor = ( char * )(char  *)lua_tostring(__S__, 2);
    application = ( char * )(char  *)lua_tostring(__S__, 3);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_Preferences(__S__, new Fl_Preferences(path, vendor, application));
    return 1;
  }
  
error:
  return lua_call2_Fl_Preferences__Fl_Preferences(__S__);
}
/*  Fl_Preferences::Fl_Preferences(Fl_Preferences::Root root, const char * vendor, const char * application) */
int lua_call4_Fl_Preferences__Fl_Preferences(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 3) goto error;
  {
     Fl_Preferences::Root root;
     char * vendor;
     char * application;
    
    root = ( Fl_Preferences::Root )(Fl_Preferences::Root)(int)lua_tonumber(__S__, 1);
    vendor = ( char * )(char  *)lua_tostring(__S__, 2);
    application = ( char * )(char  *)lua_tostring(__S__, 3);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_Preferences(__S__, new Fl_Preferences(root, vendor, application));
    return 1;
  }
  
error:
  return lua_call3_Fl_Preferences__Fl_Preferences(__S__);
}
/* void fl_end_points() */
int lua_call1_fl_end_points(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    fl_end_points();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Scrollbar::Fl_Scrollbar(int x, int y, int w, int h, const char * l=0) */
int lua_call1_Fl_Scrollbar__Fl_Scrollbar(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Scrollbar(__S__, new Fl_Scrollbar(x, y, w, h));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Scrollbar(__S__, new Fl_Scrollbar(x, y, w, h, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Help_View::select_all() */
int lua_call1_Fl_Help_View__select_all(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Help_View * __self__;
    
    __self__ = ( class Fl_Help_View * )lua_to_Fl_Help_View(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->select_all();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Group::end() */
int lua_call1_Fl_Group__end(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Group * __self__;
    
    __self__ = ( class Fl_Group * )lua_to_Fl_Group(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->end();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Buffer::skip_lines(int startPos, int nLines) */
int lua_call1_Fl_Text_Buffer__skip_lines(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Text_Buffer * __self__;
     int startPos;
     int nLines;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    startPos = ( int )(int)lua_tonumber(__S__, 2);
    nLines = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->skip_lines(startPos, nLines));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Buffer::expand_character(int pos, int indent, char * outStr) */
int lua_call1_Fl_Text_Buffer__expand_character(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 4) goto error;
  {
     class Fl_Text_Buffer * __self__;
     int pos;
     int indent;
     char * outStr;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    pos = ( int )(int)lua_tonumber(__S__, 2);
    indent = ( int )(int)lua_tonumber(__S__, 3);
    outStr = ( char * )(char  *)lua_tostring(__S__, 4);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->expand_character(pos, indent, outStr));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Buffer::expand_character(char c, int indent, char * outStr, int tabDist, char nullSubsChar) */
int lua_call2_Fl_Text_Buffer__expand_character(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 5) goto error;
  {
     char c;
     int indent;
     char * outStr;
     int tabDist;
     char nullSubsChar;
    
    c = ( char )(char)lua_tonumber(__S__, 1);
    indent = ( int )(int)lua_tonumber(__S__, 2);
    outStr = ( char * )(char  *)lua_tostring(__S__, 3);
    tabDist = ( int )(int)lua_tonumber(__S__, 4);
    nullSubsChar = ( char )(char)lua_tonumber(__S__, 5);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Text_Buffer::expand_character(c, indent, outStr, tabDist, nullSubsChar));
    return 1;
  }
  
error:
  return lua_call1_Fl_Text_Buffer__expand_character(__S__);
}
/* void Fl_File_Chooser::callback(void ( * cb)(class Fl_File_Chooser * , void * ), void * d=0) */
/* SKIPPED (argument #2) */
/* int Fl_Text_Buffer::line_start(int pos) */
int lua_call1_Fl_Text_Buffer__line_start(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Buffer * __self__;
     int pos;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    pos = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->line_start(pos));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Selection::includes(int pos, int lineStartPos, int dispIndex) */
int lua_call1_Fl_Text_Selection__includes(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 4) goto error;
  {
     class Fl_Text_Selection * __self__;
     int pos;
     int lineStartPos;
     int dispIndex;
    
    __self__ = ( class Fl_Text_Selection * )lua_to_Fl_Text_Selection(__S__, 1, &__ERROR__);
    pos = ( int )(int)lua_tonumber(__S__, 2);
    lineStartPos = ( int )(int)lua_tonumber(__S__, 3);
    dispIndex = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->includes(pos, lineStartPos, dispIndex));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Choice::handle(int ) */
int lua_call1_Fl_Choice__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Choice * __self__;
     int __2__;
    
    __self__ = ( class Fl_Choice * )lua_to_Fl_Choice(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Window::fullscreen() */
int lua_call1_Fl_Window__fullscreen(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Window * __self__;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->fullscreen();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Display::insert(const char * text) */
int lua_call1_Fl_Text_Display__insert(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Display * __self__;
     char * text;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    text = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->insert(text);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Positioner::xbounds(double , double ) */
int lua_call1_Fl_Positioner__xbounds(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Positioner * __self__;
     double __2__;
     double __3__;
    
    __self__ = ( class Fl_Positioner * )lua_to_Fl_Positioner(__S__, 1, &__ERROR__);
    __2__ = ( double )(double)lua_tonumber(__S__, 2);
    __3__ = ( double )(double)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->xbounds(__2__, __3__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color Fl_Text_Display::textcolor()const  */
int lua_call1_Fl_Text_Display__textcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Display * __self__;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textcolor());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Display::textcolor(unsigned int n) */
int lua_call2_Fl_Text_Display__textcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Display * __self__;
     unsigned int n;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    n = ( unsigned int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textcolor(n);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Text_Display__textcolor(__S__);
}
/* void Fl_Text_Display::overstrike(const char * text) */
int lua_call1_Fl_Text_Display__overstrike(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Display * __self__;
     char * text;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    text = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->overstrike(text);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_File_Chooser::filter_value() */
int lua_call1_Fl_File_Chooser__filter_value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Chooser * __self__;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->filter_value());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_File_Chooser::filter_value(int f) */
int lua_call2_Fl_File_Chooser__filter_value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_File_Chooser * __self__;
     int f;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    f = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->filter_value(f);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_File_Chooser__filter_value(__S__);
}
/* class Fl_Widget * Fl::readqueue() */
int lua_call1_Fl__readqueue(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_Widget(__S__, Fl::readqueue());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* double Fl_Positioner::xminimum()const  */
int lua_call1_Fl_Positioner__xminimum(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Positioner * __self__;
    
    __self__ = ( class Fl_Positioner * )lua_to_Fl_Positioner(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->xminimum());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Positioner::xminimum(double a) */
int lua_call2_Fl_Positioner__xminimum(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Positioner * __self__;
     double a;
    
    __self__ = ( class Fl_Positioner * )lua_to_Fl_Positioner(__S__, 1, &__ERROR__);
    a = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->xminimum(a);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Positioner__xminimum(__S__);
}
/* void Fl::delete_widget(class Fl_Widget * w) */
int lua_call1_Fl__delete_widget(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     class Fl_Widget * w;
    
    w = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    Fl::delete_widget(w);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Editor::kf_undo(int c, class Fl_Text_Editor * e) */
int lua_call1_Fl_Text_Editor__kf_undo(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int c;
     class Fl_Text_Editor * e;
    
    c = ( int )(int)lua_tonumber(__S__, 1);
    e = ( class Fl_Text_Editor * )lua_to_Fl_Text_Editor(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Text_Editor::kf_undo(c, e));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* short * Fl_File_Icon::add_vertex(float x, float y) */
/* SKIPPED (return type) */
/* short * Fl_File_Icon::add_vertex(int x, int y) */
/* SKIPPED (return type) */
/* int Fl_Input_::wrap()const  */
int lua_call1_Fl_Input___wrap(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Input_ * __self__;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->wrap());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Input_::wrap(int b) */
int lua_call2_Fl_Input___wrap(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Input_ * __self__;
     int b;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    b = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->wrap(b);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Input___wrap(__S__);
}
/* void Fl_Bitmap::uncache() */
int lua_call1_Fl_Bitmap__uncache(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Bitmap * __self__;
    
    __self__ = ( class Fl_Bitmap * )lua_to_Fl_Bitmap(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->uncache();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::get_system_colors() */
int lua_call1_Fl__get_system_colors(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    Fl::get_system_colors();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Wizard::prev() */
int lua_call1_Fl_Wizard__prev(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Wizard * __self__;
    
    __self__ = ( class Fl_Wizard * )lua_to_Fl_Wizard(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->prev();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Display::show_insert_position() */
int lua_call1_Fl_Text_Display__show_insert_position(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Display * __self__;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->show_insert_position();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Editor::kf_left(int c, class Fl_Text_Editor * e) */
int lua_call1_Fl_Text_Editor__kf_left(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int c;
     class Fl_Text_Editor * e;
    
    c = ( int )(int)lua_tonumber(__S__, 1);
    e = ( class Fl_Text_Editor * )lua_to_Fl_Text_Editor(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Text_Editor::kf_left(c, e));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_File_Chooser::Fl_File_Chooser(const char * d, const char * p, int t, const char * title) */
int lua_call1_Fl_File_Chooser__Fl_File_Chooser(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     char * d;
     char * p;
     int t;
     char * title;
    
    d = ( char * )(char  *)lua_tostring(__S__, 1);
    p = ( char * )(char  *)lua_tostring(__S__, 2);
    t = ( int )(int)lua_tonumber(__S__, 3);
    title = ( char * )(char  *)lua_tostring(__S__, 4);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_File_Chooser(__S__, new Fl_File_Chooser(d, p, t, title));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::h() */
int lua_call1_Fl__h(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::h());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::redraw() */
int lua_call1_Fl_Widget__redraw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->redraw();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* char * Fl_Check_Browser::text(int item)const  */
int lua_call1_Fl_Check_Browser__text(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Check_Browser * __self__;
     int item;
    
    __self__ = ( class Fl_Check_Browser * )lua_to_Fl_Check_Browser(__S__, 1, &__ERROR__);
    item = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->text(item));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Widget * Fl::pushed() */
int lua_call1_Fl__pushed(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_Widget(__S__, Fl::pushed());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::pushed(class Fl_Widget * ) */
int lua_call2_Fl__pushed(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __1__;
    
    __1__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    Fl::pushed(__1__);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl__pushed(__S__);
}
/* const const char * * Fl_Image::data()const  */
/* SKIPPED (return type) */
/* int Fl_Overlay_Window::can_do_overlay() */
int lua_call1_Fl_Overlay_Window__can_do_overlay(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Overlay_Window * __self__;
    
    __self__ = ( class Fl_Overlay_Window * )lua_to_Fl_Overlay_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->can_do_overlay());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color Fl_Menu_::down_color()const  */
int lua_call1_Fl_Menu___down_color(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Menu_ * __self__;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->down_color());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_::down_color(unsigned int c) */
int lua_call2_Fl_Menu___down_color(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Menu_ * __self__;
     unsigned int c;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    c = ( unsigned int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->down_color(c);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Menu___down_color(__S__);
}
/* int Fl_Widget::handle(int ) */
int lua_call1_Fl_Widget__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Widget * __self__;
     int __2__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Browser_::select_only(void * , int docallbacks=0) */
/* SKIPPED (argument #2) */
/* class Fl_Pixmap * Fl_FormsPixmap::Pixmap()const  */
int lua_call1_Fl_FormsPixmap__Pixmap(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_FormsPixmap * __self__;
    
    __self__ = ( class Fl_FormsPixmap * )lua_to_Fl_FormsPixmap(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Pixmap(__S__, __self__->Pixmap());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_FormsPixmap::Pixmap(class Fl_Pixmap * B) */
int lua_call2_Fl_FormsPixmap__Pixmap(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_FormsPixmap * __self__;
     class Fl_Pixmap * B;
    
    __self__ = ( class Fl_FormsPixmap * )lua_to_Fl_FormsPixmap(__S__, 1, &__ERROR__);
    B = ( class Fl_Pixmap * )lua_to_Fl_Pixmap(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->Pixmap(B);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_FormsPixmap__Pixmap(__S__);
}
/* void Fl_Shared_Image::color_average(Fl_Color c, float i) */
int lua_call1_Fl_Shared_Image__color_average(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Shared_Image * __self__;
     Fl_Color c;
     float i;
    
    __self__ = ( class Fl_Shared_Image * )lua_to_Fl_Shared_Image(__S__, 1, &__ERROR__);
    c = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 2);
    i = ( float )(float)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->color_average(c, i);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Preferences::entries() */
int lua_call1_Fl_Preferences__entries(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Preferences * __self__;
    
    __self__ = ( class Fl_Preferences * )lua_to_Fl_Preferences(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->entries());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Shared_Image::desaturate() */
int lua_call1_Fl_Shared_Image__desaturate(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Shared_Image * __self__;
    
    __self__ = ( class Fl_Shared_Image * )lua_to_Fl_Shared_Image(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->desaturate();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Input_Choice::changed()const  */
int lua_call1_Fl_Input_Choice__changed(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Input_Choice * __self__;
    
    __self__ = ( class Fl_Input_Choice * )lua_to_Fl_Input_Choice(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->changed());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::damage() */
int lua_call1_Fl__damage(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::damage());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::damage(int d) */
int lua_call2_Fl__damage(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     int d;
    
    d = ( int )(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    Fl::damage(d);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl__damage(__S__);
}
/* void Fl_Text_Buffer::canUndo(char flag=1) */
int lua_call1_Fl_Text_Buffer__canUndo(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Buffer * __self__;
     char flag;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (nparam <= 1) {
      if (__ERROR__) goto error;
      
      __self__->canUndo();
    } else {
      flag = ( char )(char)lua_tonumber(__S__, 2);
      if (__ERROR__) goto error;
      
      __self__->canUndo(flag);
    }
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color Fl_Widget::selection_color()const  */
int lua_call1_Fl_Widget__selection_color(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->selection_color());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::selection_color(unsigned int a) */
int lua_call2_Fl_Widget__selection_color(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Widget * __self__;
     unsigned int a;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    a = ( unsigned int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->selection_color(a);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Widget__selection_color(__S__);
}
/* int Fl_Help_View::find(const char * s, int p=0) */
int lua_call1_Fl_Help_View__find(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Help_View * __self__;
     char * s;
     int p;
    
    __self__ = ( class Fl_Help_View * )lua_to_Fl_Help_View(__S__, 1, &__ERROR__);
    s = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (nparam <= 2) {
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, __self__->find(s));
      return 1;
    } else {
      p = ( int )(int)lua_tonumber(__S__, 3);
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, __self__->find(s, p));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* uchar Fl_Text_Display::textsize()const  */
int lua_call1_Fl_Text_Display__textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Display * __self__;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textsize());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Display::textsize(uchar s) */
int lua_call2_Fl_Text_Display__textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Display * __self__;
     unsigned char s;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    s = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textsize(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Text_Display__textsize(__S__);
}
/* void Fl_Text_Buffer::select(int start, int end) */
int lua_call1_Fl_Text_Buffer__select(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Text_Buffer * __self__;
     int start;
     int end;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    start = ( int )(int)lua_tonumber(__S__, 2);
    end = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->select(start, end);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* uchar Fl_Browser_::textsize()const  */
int lua_call1_Fl_Browser___textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Browser_ * __self__;
    
    __self__ = ( class Fl_Browser_ * )lua_to_Fl_Browser_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textsize());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser_::textsize(uchar s) */
int lua_call2_Fl_Browser___textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Browser_ * __self__;
     unsigned char s;
    
    __self__ = ( class Fl_Browser_ * )lua_to_Fl_Browser_(__S__, 1, &__ERROR__);
    s = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textsize(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Browser___textsize(__S__);
}
/* void Fl_Spinner::resize(int X, int Y, int W, int H) */
int lua_call1_Fl_Spinner__resize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Spinner * __self__;
     int X;
     int Y;
     int W;
     int H;
    
    __self__ = ( class Fl_Spinner * )lua_to_Fl_Spinner(__S__, 1, &__ERROR__);
    X = ( int )(int)lua_tonumber(__S__, 2);
    Y = ( int )(int)lua_tonumber(__S__, 3);
    W = ( int )(int)lua_tonumber(__S__, 4);
    H = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->resize(X, Y, W, H);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Widget::visible()const  */
int lua_call1_Fl_Widget__visible(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->visible());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Shared_Image * * Fl_Shared_Image::images() */
/* SKIPPED (return type) */
/* const char * Fl_Browser::data(int )const  */
int lua_call1_Fl_Browser__data(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Browser * __self__;
     int __2__;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->data(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser::data(int , const char * v) */
int lua_call2_Fl_Browser__data(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Browser * __self__;
     int __2__;
     char * v;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    v = ( char * )(char  *)lua_tostring(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->data(__2__, v);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Browser__data(__S__);
}
/* int Fl_Window::handle(int ) */
int lua_call1_Fl_Window__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Window * __self__;
     int __2__;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_File_Chooser::count() */
int lua_call1_Fl_File_Chooser__count(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Chooser * __self__;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->count());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Window * Fl::next_window(const class Fl_Window * ) */
int lua_call1_Fl__next_window(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     class Fl_Window * __1__;
    
    __1__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Window(__S__, Fl::next_window(__1__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Roller::handle(int ) */
int lua_call1_Fl_Roller__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Roller * __self__;
     int __2__;
    
    __self__ = ( class Fl_Roller * )lua_to_Fl_Roller(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::event_alt() */
int lua_call1_Fl__event_alt(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::event_alt());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Selection::set(int start, int end) */
int lua_call1_Fl_Text_Selection__set(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Text_Selection * __self__;
     int start;
     int end;
    
    __self__ = ( class Fl_Text_Selection * )lua_to_Fl_Text_Selection(__S__, 1, &__ERROR__);
    start = ( int )(int)lua_tonumber(__S__, 2);
    end = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->set(start, end);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Pack::Fl_Pack(int x, int y, int w, int h, const char * l=0) */
int lua_call1_Fl_Pack__Fl_Pack(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Pack(__S__, new Fl_Pack(x, y, w, h));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Pack(__S__, new Fl_Pack(x, y, w, h, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Window * Fl_Widget::window()const  */
int lua_call1_Fl_Widget__window(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Window(__S__, __self__->window());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Tile::position(int , int , int , int ) */
int lua_call1_Fl_Tile__position(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Tile * __self__;
     int __2__;
     int __3__;
     int __4__;
     int __5__;
    
    __self__ = ( class Fl_Tile * )lua_to_Fl_Tile(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    __5__ = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->position(__2__, __3__, __4__, __5__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* HPEN fl_pen() */
/* SKIPPED (return type) */
/* void Fl_File_Chooser::rescan() */
int lua_call1_Fl_File_Chooser__rescan(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Chooser * __self__;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->rescan();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Image::uncache() */
int lua_call1_Fl_Image__uncache(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Image * __self__;
    
    __self__ = ( class Fl_Image * )lua_to_Fl_Image(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->uncache();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color Fl_Menu_::textcolor()const  */
int lua_call1_Fl_Menu___textcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Menu_ * __self__;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textcolor());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_::textcolor(unsigned int c) */
int lua_call2_Fl_Menu___textcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Menu_ * __self__;
     unsigned int c;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    c = ( unsigned int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textcolor(c);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Menu___textcolor(__S__);
}
/* int Fl_Menu_::value()const  */
int lua_call1_Fl_Menu___value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Menu_ * __self__;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->value());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Menu_::value(const struct Fl_Menu_Item * ) */
int lua_call2_Fl_Menu___value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Menu_ * __self__;
     struct Fl_Menu_Item * __2__;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    __2__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->value(__2__));
    return 1;
  }
  
error:
  return lua_call1_Fl_Menu___value(__S__);
}
/* int Fl_Menu_::value(int i) */
int lua_call3_Fl_Menu___value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Menu_ * __self__;
     int i;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    i = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->value(i));
    return 1;
  }
  
error:
  return lua_call2_Fl_Menu___value(__S__);
}
/* char Fl_Timer::direction()const  */
int lua_call1_Fl_Timer__direction(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Timer * __self__;
    
    __self__ = ( class Fl_Timer * )lua_to_Fl_Timer(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->direction());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Timer::direction(char d) */
int lua_call2_Fl_Timer__direction(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Timer * __self__;
     char d;
    
    __self__ = ( class Fl_Timer * )lua_to_Fl_Timer(__S__, 1, &__ERROR__);
    d = ( char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->direction(d);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Timer__direction(__S__);
}
/* int Fl::wait() */
int lua_call1_Fl__wait(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::wait());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* double Fl::wait(double time) */
int lua_call2_Fl__wait(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     double time;
    
    time = ( double )(double)lua_tonumber(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::wait(time));
    return 1;
  }
  
error:
  return lua_call1_Fl__wait(__S__);
}
/* const char * Fl_File_Input::value() */
int lua_call1_Fl_File_Input__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Input * __self__;
    
    __self__ = ( class Fl_File_Input * )lua_to_Fl_File_Input(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->value());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_File_Input::value(const char * ) */
int lua_call2_Fl_File_Input__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_File_Input * __self__;
     char * __2__;
    
    __self__ = ( class Fl_File_Input * )lua_to_Fl_File_Input(__S__, 1, &__ERROR__);
    __2__ = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->value(__2__));
    return 1;
  }
  
error:
  return lua_call1_Fl_File_Input__value(__S__);
}
/* int Fl_File_Input::value(const char * , int ) */
int lua_call3_Fl_File_Input__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_File_Input * __self__;
     char * __2__;
     int __3__;
    
    __self__ = ( class Fl_File_Input * )lua_to_Fl_File_Input(__S__, 1, &__ERROR__);
    __2__ = ( char * )(char  *)lua_tostring(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->value(__2__, __3__));
    return 1;
  }
  
error:
  return lua_call2_Fl_File_Input__value(__S__);
}
/* uchar Fl_File_Chooser::iconsize() */
int lua_call1_Fl_File_Chooser__iconsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Chooser * __self__;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->iconsize());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_File_Chooser::iconsize(uchar s) */
int lua_call2_Fl_File_Chooser__iconsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_File_Chooser * __self__;
     unsigned char s;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    s = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->iconsize(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_File_Chooser__iconsize(__S__);
}
/* int Fl_Text_Editor::kf_copy(int c, class Fl_Text_Editor * e) */
int lua_call1_Fl_Text_Editor__kf_copy(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int c;
     class Fl_Text_Editor * e;
    
    c = ( int )(int)lua_tonumber(__S__, 1);
    e = ( class Fl_Text_Editor * )lua_to_Fl_Text_Editor(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Text_Editor::kf_copy(c, e));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* uchar Fl_Input_Choice::textsize()const  */
int lua_call1_Fl_Input_Choice__textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Input_Choice * __self__;
    
    __self__ = ( class Fl_Input_Choice * )lua_to_Fl_Input_Choice(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textsize());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Input_Choice::textsize(uchar s) */
int lua_call2_Fl_Input_Choice__textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Input_Choice * __self__;
     unsigned char s;
    
    __self__ = ( class Fl_Input_Choice * )lua_to_Fl_Input_Choice(__S__, 1, &__ERROR__);
    s = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textsize(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Input_Choice__textsize(__S__);
}
/*  Fl_XBM_Image::Fl_XBM_Image(const char * filename) */
int lua_call1_Fl_XBM_Image__Fl_XBM_Image(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * filename;
    
    filename = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_XBM_Image(__S__, new Fl_XBM_Image(filename));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* char Fl_Value_Input::soft()const  */
int lua_call1_Fl_Value_Input__soft(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Value_Input * __self__;
    
    __self__ = ( class Fl_Value_Input * )lua_to_Fl_Value_Input(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->soft());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Value_Input::soft(char s) */
int lua_call2_Fl_Value_Input__soft(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Value_Input * __self__;
     char s;
    
    __self__ = ( class Fl_Value_Input * )lua_to_Fl_Value_Input(__S__, 1, &__ERROR__);
    s = ( char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->soft(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Value_Input__soft(__S__);
}
/* class Fl_Widget * Fl::belowmouse() */
int lua_call1_Fl__belowmouse(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_Widget(__S__, Fl::belowmouse());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::belowmouse(class Fl_Widget * ) */
int lua_call2_Fl__belowmouse(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __1__;
    
    __1__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    Fl::belowmouse(__1__);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl__belowmouse(__S__);
}
/*  Fl_BMP_Image::Fl_BMP_Image(const char * filename) */
int lua_call1_Fl_BMP_Image__Fl_BMP_Image(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * filename;
    
    filename = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_BMP_Image(__S__, new Fl_BMP_Image(filename));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Boxtype Fl_File_Input::down_box()const  */
int lua_call1_Fl_File_Input__down_box(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Input * __self__;
    
    __self__ = ( class Fl_File_Input * )lua_to_Fl_File_Input(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->down_box());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_File_Input::down_box(Fl_Boxtype b) */
int lua_call2_Fl_File_Input__down_box(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_File_Input * __self__;
     Fl_Boxtype b;
    
    __self__ = ( class Fl_File_Input * )lua_to_Fl_File_Input(__S__, 1, &__ERROR__);
    b = ( Fl_Boxtype )(Fl_Boxtype)(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->down_box(b);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_File_Input__down_box(__S__);
}
/*  Fl_Fill_Dial::Fl_Fill_Dial(int x, int y, int w, int h, const char * l=0) */
int lua_call1_Fl_Fill_Dial__Fl_Fill_Dial(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Fill_Dial(__S__, new Fl_Fill_Dial(x, y, w, h));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Fill_Dial(__S__, new Fl_Fill_Dial(x, y, w, h, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Scroll::position(int , int ) */
int lua_call1_Fl_Scroll__position(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Scroll * __self__;
     int __2__;
     int __3__;
    
    __self__ = ( class Fl_Scroll * )lua_to_Fl_Scroll(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->position(__2__, __3__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Editor::kf_up(int c, class Fl_Text_Editor * e) */
int lua_call1_Fl_Text_Editor__kf_up(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int c;
     class Fl_Text_Editor * e;
    
    c = ( int )(int)lua_tonumber(__S__, 1);
    e = ( class Fl_Text_Editor * )lua_to_Fl_Text_Editor(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Text_Editor::kf_up(c, e));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Help_View::clear_selection() */
int lua_call1_Fl_Help_View__clear_selection(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Help_View * __self__;
    
    __self__ = ( class Fl_Help_View * )lua_to_Fl_Help_View(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->clear_selection();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Buffer::call_predelete_callbacks() */
int lua_call1_Fl_Text_Buffer__call_predelete_callbacks(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Buffer * __self__;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->call_predelete_callbacks();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color Fl_Value_Input::cursor_color()const  */
int lua_call1_Fl_Value_Input__cursor_color(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Value_Input * __self__;
    
    __self__ = ( class Fl_Value_Input * )lua_to_Fl_Value_Input(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->cursor_color());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Value_Input::cursor_color(unsigned int n) */
int lua_call2_Fl_Value_Input__cursor_color(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Value_Input * __self__;
     unsigned int n;
    
    __self__ = ( class Fl_Value_Input * )lua_to_Fl_Value_Input(__S__, 1, &__ERROR__);
    n = ( unsigned int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->cursor_color(n);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Value_Input__cursor_color(__S__);
}
/* int Fl_Browser_::deselect(int docallbacks=0) */
int lua_call1_Fl_Browser___deselect(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Browser_ * __self__;
     int docallbacks;
    
    __self__ = ( class Fl_Browser_ * )lua_to_Fl_Browser_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (nparam <= 1) {
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, __self__->deselect());
      return 1;
    } else {
      docallbacks = ( int )(int)lua_tonumber(__S__, 2);
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, __self__->deselect(docallbacks));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Check_Browser::set_checked(int item) */
int lua_call1_Fl_Check_Browser__set_checked(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Check_Browser * __self__;
     int item;
    
    __self__ = ( class Fl_Check_Browser * )lua_to_Fl_Check_Browser(__S__, 1, &__ERROR__);
    item = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->set_checked(item);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_loop(int , int , int , int , int , int ) */
int lua_call1_fl_loop(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 6) goto error;
  {
     int __1__;
     int __2__;
     int __3__;
     int __4__;
     int __5__;
     int __6__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    __5__ = ( int )(int)lua_tonumber(__S__, 5);
    __6__ = ( int )(int)lua_tonumber(__S__, 6);
    
    /* Actual call */
    fl_loop(__1__, __2__, __3__, __4__, __5__, __6__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_loop(int , int , int , int , int , int , int , int ) */
int lua_call2_fl_loop(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 8) goto error;
  {
     int __1__;
     int __2__;
     int __3__;
     int __4__;
     int __5__;
     int __6__;
     int __7__;
     int __8__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    __5__ = ( int )(int)lua_tonumber(__S__, 5);
    __6__ = ( int )(int)lua_tonumber(__S__, 6);
    __7__ = ( int )(int)lua_tonumber(__S__, 7);
    __8__ = ( int )(int)lua_tonumber(__S__, 8);
    
    /* Actual call */
    fl_loop(__1__, __2__, __3__, __4__, __5__, __6__, __7__, __8__);
    ;
    return 0;
  }
  
error:
  return lua_call1_fl_loop(__S__);
}
/* HBRUSH fl_brush_action(int ) */
/* SKIPPED (return type) */
/* void Fl_Input_::resize(int , int , int , int ) */
int lua_call1_Fl_Input___resize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Input_ * __self__;
     int __2__;
     int __3__;
     int __4__;
     int __5__;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    __5__ = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->resize(__2__, __3__, __4__, __5__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Buffer::insert_column(int column, int startPos, const char * text, int * charsInserted, int * charsDeleted) */
/* SKIPPED (argument #5) */
/* Fl_Font Fl_Text_Display::textfont()const  */
int lua_call1_Fl_Text_Display__textfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Display * __self__;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textfont());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Display::textfont(uchar s) */
int lua_call2_Fl_Text_Display__textfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Display * __self__;
     unsigned char s;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    s = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textfont(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Text_Display__textfont(__S__);
}
/* void Fl_Text_Buffer::replace_selection(const char * text) */
int lua_call1_Fl_Text_Buffer__replace_selection(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Buffer * __self__;
     char * text;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    text = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->replace_selection(text);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::event_y_root() */
int lua_call1_Fl__event_y_root(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::event_y_root());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_FormsPixmap::set(const char * * bits) */
/* SKIPPED (argument #2) */
/* int fl_filename_match(const char * name, const char * pattern) */
int lua_call1_fl_filename_match(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     char * name;
     char * pattern;
    
    name = ( char * )(char  *)lua_tostring(__S__, 1);
    pattern = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_filename_match(name, pattern));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Window::set_modal() */
int lua_call1_Fl_Window__set_modal(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Window * __self__;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->set_modal();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::clear_widget_pointer(const class Fl_Widget * w) */
int lua_call1_Fl__clear_widget_pointer(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     class Fl_Widget * w;
    
    w = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    Fl::clear_widget_pointer(w);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* char Fl_Input_::index(int i)const  */
int lua_call1_Fl_Input___index(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Input_ * __self__;
     int i;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    i = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->index(i));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Positioner::ystep(double a) */
int lua_call1_Fl_Positioner__ystep(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Positioner * __self__;
     double a;
    
    __self__ = ( class Fl_Positioner * )lua_to_Fl_Positioner(__S__, 1, &__ERROR__);
    a = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->ystep(a);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Tooltip::enabled() */
int lua_call1_Fl_Tooltip__enabled(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Tooltip::enabled());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::default_callback(class Fl_Widget * , void * ) */
/* SKIPPED (argument #2) */
/* uchar Fl_Help_Dialog::textsize() */
int lua_call1_Fl_Help_Dialog__textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Help_Dialog * __self__;
    
    __self__ = ( class Fl_Help_Dialog * )lua_to_Fl_Help_Dialog(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textsize());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Help_Dialog::textsize(uchar s) */
int lua_call2_Fl_Help_Dialog__textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Help_Dialog * __self__;
     unsigned char s;
    
    __self__ = ( class Fl_Help_Dialog * )lua_to_Fl_Help_Dialog(__S__, 1, &__ERROR__);
    s = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textsize(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Help_Dialog__textsize(__S__);
}
/* int Fl_Window::non_modal()const  */
int lua_call1_Fl_Window__non_modal(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Window * __self__;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->non_modal());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::y() */
int lua_call1_Fl__y(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::y());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Preferences::flush() */
int lua_call1_Fl_Preferences__flush(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Preferences * __self__;
    
    __self__ = ( class Fl_Preferences * )lua_to_Fl_Preferences(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->flush();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Editor::default_key_function(Fl_Text_Editor::Key_Func f) */
/* SKIPPED (argument #2) */
/* int Fl_Image::ld()const  */
int lua_call1_Fl_Image__ld(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Image * __self__;
    
    __self__ = ( class Fl_Image * )lua_to_Fl_Image(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->ld());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int fl_draw_pixmap(const char * * data, int x, int y, Fl_Color =FL_BACKGROUND_COLOR) */
/* SKIPPED (argument #1) */
/* int fl_draw_pixmap(const const char * * data, int x, int y, Fl_Color =FL_BACKGROUND_COLOR) */
/* SKIPPED (argument #1) */
/* int Fl_Browser_::position()const  */
int lua_call1_Fl_Browser___position(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Browser_ * __self__;
    
    __self__ = ( class Fl_Browser_ * )lua_to_Fl_Browser_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->position());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser_::position(int ) */
int lua_call2_Fl_Browser___position(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Browser_ * __self__;
     int __2__;
    
    __self__ = ( class Fl_Browser_ * )lua_to_Fl_Browser_(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->position(__2__);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Browser___position(__S__);
}
/* void Fl_Window::cursor(Fl_Cursor , Fl_Color =FL_BLACK, Fl_Color =FL_WHITE) */
int lua_call1_Fl_Window__cursor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Window * __self__;
     Fl_Cursor __2__;
     Fl_Color __3__;
     Fl_Color __4__;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    __2__ = ( Fl_Cursor )(Fl_Cursor)(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (nparam <= 2) {
      if (__ERROR__) goto error;
      
      __self__->cursor(__2__);
    } else {
      __3__ = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 3);
      if (nparam <= 3) {
        if (__ERROR__) goto error;
        
        __self__->cursor(__2__, __3__);
      } else {
        __4__ = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 4);
        if (__ERROR__) goto error;
        
        __self__->cursor(__2__, __3__, __4__);
      }
    }
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const char * Fl_Input_Choice::value()const  */
int lua_call1_Fl_Input_Choice__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Input_Choice * __self__;
    
    __self__ = ( class Fl_Input_Choice * )lua_to_Fl_Input_Choice(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->value());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Input_Choice::value(const char * val) */
int lua_call2_Fl_Input_Choice__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Input_Choice * __self__;
     char * val;
    
    __self__ = ( class Fl_Input_Choice * )lua_to_Fl_Input_Choice(__S__, 1, &__ERROR__);
    val = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->value(val);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Input_Choice__value(__S__);
}
/* void Fl_Input_Choice::value(int val) */
int lua_call3_Fl_Input_Choice__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Input_Choice * __self__;
     int val;
    
    __self__ = ( class Fl_Input_Choice * )lua_to_Fl_Input_Choice(__S__, 1, &__ERROR__);
    val = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->value(val);
    ;
    return 0;
  }
  
error:
  return lua_call2_Fl_Input_Choice__value(__S__);
}
/* uchar Fl_Help_View::textfont()const  */
int lua_call1_Fl_Help_View__textfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Help_View * __self__;
    
    __self__ = ( class Fl_Help_View * )lua_to_Fl_Help_View(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textfont());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Help_View::textfont(uchar f) */
int lua_call2_Fl_Help_View__textfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Help_View * __self__;
     unsigned char f;
    
    __self__ = ( class Fl_Help_View * )lua_to_Fl_Help_View(__S__, 1, &__ERROR__);
    f = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textfont(f);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Help_View__textfont(__S__);
}
/* void Fl_Help_Dialog::position(int xx, int yy) */
int lua_call1_Fl_Help_Dialog__position(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Help_Dialog * __self__;
     int xx;
     int yy;
    
    __self__ = ( class Fl_Help_Dialog * )lua_to_Fl_Help_Dialog(__S__, 1, &__ERROR__);
    xx = ( int )(int)lua_tonumber(__S__, 2);
    yy = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->position(xx, yy);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_RGB_Image::draw(int X, int Y) */
int lua_call1_Fl_RGB_Image__draw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_RGB_Image * __self__;
     int X;
     int Y;
    
    __self__ = ( class Fl_RGB_Image * )lua_to_Fl_RGB_Image(__S__, 1, &__ERROR__);
    X = ( int )(int)lua_tonumber(__S__, 2);
    Y = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->draw(X, Y);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_RGB_Image::draw(int X, int Y, int W, int H, int cx=0, int cy=0) */
int lua_call2_Fl_RGB_Image__draw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_RGB_Image * __self__;
     int X;
     int Y;
     int W;
     int H;
     int cx;
     int cy;
    
    __self__ = ( class Fl_RGB_Image * )lua_to_Fl_RGB_Image(__S__, 1, &__ERROR__);
    X = ( int )(int)lua_tonumber(__S__, 2);
    Y = ( int )(int)lua_tonumber(__S__, 3);
    W = ( int )(int)lua_tonumber(__S__, 4);
    H = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (nparam <= 5) {
      if (__ERROR__) goto error;
      
      __self__->draw(X, Y, W, H);
    } else {
      cx = ( int )(int)lua_tonumber(__S__, 6);
      if (nparam <= 6) {
        if (__ERROR__) goto error;
        
        __self__->draw(X, Y, W, H, cx);
      } else {
        cy = ( int )(int)lua_tonumber(__S__, 7);
        if (__ERROR__) goto error;
        
        __self__->draw(X, Y, W, H, cx, cy);
      }
    }
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_RGB_Image__draw(__S__);
}
/* void Fl_Pixmap::label(struct Fl_Menu_Item * m) */
int lua_call1_Fl_Pixmap__label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Pixmap * __self__;
     struct Fl_Menu_Item * m;
    
    __self__ = ( class Fl_Pixmap * )lua_to_Fl_Pixmap(__S__, 1, &__ERROR__);
    m = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->label(m);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Pixmap::label(class Fl_Widget * w) */
int lua_call2_Fl_Pixmap__label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Pixmap * __self__;
     class Fl_Widget * w;
    
    __self__ = ( class Fl_Pixmap * )lua_to_Fl_Pixmap(__S__, 1, &__ERROR__);
    w = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->label(w);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Pixmap__label(__S__);
}
/* void Fl_Text_Display::wrap_mode(int wrap, int wrap_margin) */
int lua_call1_Fl_Text_Display__wrap_mode(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Text_Display * __self__;
     int wrap;
     int wrap_margin;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    wrap = ( int )(int)lua_tonumber(__S__, 2);
    wrap_margin = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->wrap_mode(wrap, wrap_margin);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Boxtype fl_define_FL_SHADOW_BOX() */
int lua_call1_fl_define_FL_SHADOW_BOX(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_define_FL_SHADOW_BOX());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::selection(class Fl_Widget & owner, const char * , int len) */
int lua_call1_Fl__selection(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 3) goto error;
  {
     class Fl_Widget & owner = ( class Fl_Widget & )(*lua_to_Fl_Widget(__S__, 1, &__ERROR__));
     char * __2__;
     int len;
    
    __2__ = ( char * )(char  *)lua_tostring(__S__, 2);
    len = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    Fl::selection(owner, __2__, len);
    lua_settop(__S__, 0);
    ;
    lua_push_Fl_Widget(__S__, &(owner));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* uchar Fl_Spinner::textfont()const  */
int lua_call1_Fl_Spinner__textfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Spinner * __self__;
    
    __self__ = ( class Fl_Spinner * )lua_to_Fl_Spinner(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textfont());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Spinner::textfont(uchar f) */
int lua_call2_Fl_Spinner__textfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Spinner * __self__;
     unsigned char f;
    
    __self__ = ( class Fl_Spinner * )lua_to_Fl_Spinner(__S__, 1, &__ERROR__);
    f = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textfont(f);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Spinner__textfont(__S__);
}
/* int Fl::add_awake_handler_(Fl_Awake_Handler , void * ) */
/* SKIPPED (argument #1) */
/* void Fl_Menu_Window::clear_overlay() */
int lua_call1_Fl_Menu_Window__clear_overlay(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Menu_Window * __self__;
    
    __self__ = ( class Fl_Menu_Window * )lua_to_Fl_Menu_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->clear_overlay();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::do_widget_deletion() */
int lua_call1_Fl__do_widget_deletion(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    Fl::do_widget_deletion();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Shared_Image::reload() */
int lua_call1_Fl_Shared_Image__reload(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Shared_Image * __self__;
    
    __self__ = ( class Fl_Shared_Image * )lua_to_Fl_Shared_Image(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->reload();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_FormsPixmap::Fl_FormsPixmap(Fl_Boxtype , int , int , int , int , const char * =0) */
int lua_call1_Fl_FormsPixmap__Fl_FormsPixmap(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 5) goto error;
  {
     Fl_Boxtype __1__;
     int __2__;
     int __3__;
     int __4__;
     int __5__;
     char * __6__;
    
    __1__ = ( Fl_Boxtype )(Fl_Boxtype)(int)lua_tonumber(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    __5__ = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (nparam <= 5) {
      lua_settop(__S__, 0);
      lua_push_Fl_FormsPixmap(__S__, new Fl_FormsPixmap(__1__, __2__, __3__, __4__, __5__));
      return 1;
    } else {
      __6__ = ( char * )(char  *)lua_tostring(__S__, 6);
      lua_settop(__S__, 0);
      lua_push_Fl_FormsPixmap(__S__, new Fl_FormsPixmap(__1__, __2__, __3__, __4__, __5__, __6__));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Check_Browser::add(char * s) */
int lua_call1_Fl_Check_Browser__add(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Check_Browser * __self__;
     char * s;
    
    __self__ = ( class Fl_Check_Browser * )lua_to_Fl_Check_Browser(__S__, 1, &__ERROR__);
    s = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->add(s));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Check_Browser::add(const char * s) */
int lua_call2_Fl_Check_Browser__add(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Check_Browser * __self__;
     char * s;
    
    __self__ = ( class Fl_Check_Browser * )lua_to_Fl_Check_Browser(__S__, 1, &__ERROR__);
    s = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->add(s));
    return 1;
  }
  
error:
  return lua_call1_Fl_Check_Browser__add(__S__);
}
/* int Fl_Check_Browser::add(const char * s, int b) */
int lua_call3_Fl_Check_Browser__add(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Check_Browser * __self__;
     char * s;
     int b;
    
    __self__ = ( class Fl_Check_Browser * )lua_to_Fl_Check_Browser(__S__, 1, &__ERROR__);
    s = ( char * )(char  *)lua_tostring(__S__, 2);
    b = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->add(s, b));
    return 1;
  }
  
error:
  return lua_call2_Fl_Check_Browser__add(__S__);
}
/* int Fl_Check_Browser::add(char * s, int b) */
int lua_call4_Fl_Check_Browser__add(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Check_Browser * __self__;
     char * s;
     int b;
    
    __self__ = ( class Fl_Check_Browser * )lua_to_Fl_Check_Browser(__S__, 1, &__ERROR__);
    s = ( char * )(char  *)lua_tostring(__S__, 2);
    b = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->add(s, b));
    return 1;
  }
  
error:
  return lua_call3_Fl_Check_Browser__add(__S__);
}
/* void Fl_Color_Chooser::hsv2rgb(double , double , double , double & , double & , double & ) */
int lua_call1_Fl_Color_Chooser__hsv2rgb(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 6) goto error;
  {
     double __1__;
     double __2__;
     double __3__;
     double __4__;
     double __5__;
     double __6__;
    
    __1__ = ( double )(double)lua_tonumber(__S__, 1);
    __2__ = ( double )(double)lua_tonumber(__S__, 2);
    __3__ = ( double )(double)lua_tonumber(__S__, 3);
    __4__ = ( double )(double)lua_tonumber(__S__, 4);
    __5__ = ( double )(double)lua_tonumber(__S__, 5);
    __6__ = ( double )(double)lua_tonumber(__S__, 6);
    
    /* Actual call */
    Fl_Color_Chooser::hsv2rgb(__1__, __2__, __3__, __4__, __5__, __6__);
    lua_settop(__S__, 0);
    ;
    lua_pushnumber(__S__, __4__);
    lua_pushnumber(__S__, __5__);
    lua_pushnumber(__S__, __6__);
    return 3;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Tooltip::enter_area(class Fl_Widget * w, int X, int Y, int W, int H, const char * tip) */
int lua_call1_Fl_Tooltip__enter_area(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 6) goto error;
  {
     class Fl_Widget * w;
     int X;
     int Y;
     int W;
     int H;
     char * tip;
    
    w = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    X = ( int )(int)lua_tonumber(__S__, 2);
    Y = ( int )(int)lua_tonumber(__S__, 3);
    W = ( int )(int)lua_tonumber(__S__, 4);
    H = ( int )(int)lua_tonumber(__S__, 5);
    tip = ( char * )(char  *)lua_tostring(__S__, 6);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    Fl_Tooltip::enter_area(w, X, Y, W, H, tip);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Editor::kf_right(int c, class Fl_Text_Editor * e) */
int lua_call1_Fl_Text_Editor__kf_right(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int c;
     class Fl_Text_Editor * e;
    
    c = ( int )(int)lua_tonumber(__S__, 1);
    e = ( class Fl_Text_Editor * )lua_to_Fl_Text_Editor(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Text_Editor::kf_right(c, e));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Labeltype Fl_Menu_Item::labeltype()const  */
int lua_call1_Fl_Menu_Item__labeltype(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->labeltype());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_Item::labeltype(Fl_Labeltype a) */
int lua_call2_Fl_Menu_Item__labeltype(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     struct Fl_Menu_Item * __self__;
     Fl_Labeltype a;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    a = ( Fl_Labeltype )(Fl_Labeltype)(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->labeltype(a);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Menu_Item__labeltype(__S__);
}
/* int Fl_Text_Buffer::appendfile(const char * file, int buflen=128 * 1024) */
int lua_call1_Fl_Text_Buffer__appendfile(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Buffer * __self__;
     char * file;
     int buflen;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    file = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (nparam <= 2) {
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, __self__->appendfile(file));
      return 1;
    } else {
      buflen = ( int )(int)lua_tonumber(__S__, 3);
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, __self__->appendfile(file, buflen));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Chart::maxsize()const  */
int lua_call1_Fl_Chart__maxsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Chart * __self__;
    
    __self__ = ( class Fl_Chart * )lua_to_Fl_Chart(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->maxsize());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Chart::maxsize(int ) */
int lua_call2_Fl_Chart__maxsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Chart * __self__;
     int __2__;
    
    __self__ = ( class Fl_Chart * )lua_to_Fl_Chart(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->maxsize(__2__);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Chart__maxsize(__S__);
}
/* int Fl_Widget::damage_resize(int , int , int , int ) */
int lua_call1_Fl_Widget__damage_resize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Widget * __self__;
     int __2__;
     int __3__;
     int __4__;
     int __5__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    __5__ = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->damage_resize(__2__, __3__, __4__, __5__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Browser::value()const  */
int lua_call1_Fl_Browser__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Browser * __self__;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->value());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser::value(int v) */
int lua_call2_Fl_Browser__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Browser * __self__;
     int v;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    v = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->value(v);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Browser__value(__S__);
}
/* void Fl_Browser::insert(int , const char * , void * =0) */
int lua_call1_Fl_Browser__insert(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Browser * __self__;
     int __2__;
     char * __3__;
     void * __4__;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( char * )(char  *)lua_tostring(__S__, 3);
    
    /* Actual call */
    if (nparam <= 3) {
      if (__ERROR__) goto error;
      
      __self__->insert(__2__, __3__);
    } else {
      if (__ERROR__) goto error;
      
      __self__->insert(__2__, __3__, __4__);
    }
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Menu_Bar::Fl_Menu_Bar(int X, int Y, int W, int H, const char * l=0) */
int lua_call1_Fl_Menu_Bar__Fl_Menu_Bar(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     char * l;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Menu_Bar(__S__, new Fl_Menu_Bar(X, Y, W, H));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Menu_Bar(__S__, new Fl_Menu_Bar(X, Y, W, H, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Overlay_Window::Fl_Overlay_Window(int W, int H, const char * l=0) */
/* SKIPPED (pure virtual class) */
/*  Fl_Overlay_Window::Fl_Overlay_Window(int X, int Y, int W, int H, const char * l=0) */
/* SKIPPED (pure virtual class) */
/*  Fl_Hor_Value_Slider::Fl_Hor_Value_Slider(int X, int Y, int W, int H, const char * l=0) */
int lua_call1_Fl_Hor_Value_Slider__Fl_Hor_Value_Slider(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     char * l;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Hor_Value_Slider(__S__, new Fl_Hor_Value_Slider(X, Y, W, H));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Hor_Value_Slider(__S__, new Fl_Hor_Value_Slider(X, Y, W, H, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_File_Icon::load_fti(const char * fti) */
int lua_call1_Fl_File_Icon__load_fti(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_File_Icon * __self__;
     char * fti;
    
    __self__ = ( class Fl_File_Icon * )lua_to_Fl_File_Icon(__S__, 1, &__ERROR__);
    fti = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->load_fti(fti));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Timer::Fl_Timer(uchar t, int x, int y, int w, int h, const char * l) */
int lua_call1_Fl_Timer__Fl_Timer(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 6) goto error;
  {
     unsigned char t;
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    t = ( unsigned char )(char)lua_tonumber(__S__, 1);
    x = ( int )(int)lua_tonumber(__S__, 2);
    y = ( int )(int)lua_tonumber(__S__, 3);
    w = ( int )(int)lua_tonumber(__S__, 4);
    h = ( int )(int)lua_tonumber(__S__, 5);
    l = ( char * )(char  *)lua_tostring(__S__, 6);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_Timer(__S__, new Fl_Timer(t, x, y, w, h, l));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::screen_xywh(int & X, int & Y, int & W, int & H) */
int lua_call1_Fl__screen_xywh(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    Fl::screen_xywh(X, Y, W, H);
    lua_settop(__S__, 0);
    ;
    lua_pushnumber(__S__, X);
    lua_pushnumber(__S__, Y);
    lua_pushnumber(__S__, W);
    lua_pushnumber(__S__, H);
    return 4;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::screen_xywh(int & X, int & Y, int & W, int & H, int n) */
int lua_call2_Fl__screen_xywh(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 5) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     int n;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    n = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    Fl::screen_xywh(X, Y, W, H, n);
    lua_settop(__S__, 0);
    ;
    lua_pushnumber(__S__, X);
    lua_pushnumber(__S__, Y);
    lua_pushnumber(__S__, W);
    lua_pushnumber(__S__, H);
    return 4;
  }
  
error:
  return lua_call1_Fl__screen_xywh(__S__);
}
/* void Fl::screen_xywh(int & X, int & Y, int & W, int & H, int mx, int my) */
int lua_call3_Fl__screen_xywh(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 6) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     int mx;
     int my;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    mx = ( int )(int)lua_tonumber(__S__, 5);
    my = ( int )(int)lua_tonumber(__S__, 6);
    
    /* Actual call */
    Fl::screen_xywh(X, Y, W, H, mx, my);
    lua_settop(__S__, 0);
    ;
    lua_pushnumber(__S__, X);
    lua_pushnumber(__S__, Y);
    lua_pushnumber(__S__, W);
    lua_pushnumber(__S__, H);
    return 4;
  }
  
error:
  return lua_call2_Fl__screen_xywh(__S__);
}
/* ulong Fl_Clock_Output::value()const  */
int lua_call1_Fl_Clock_Output__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Clock_Output * __self__;
    
    __self__ = ( class Fl_Clock_Output * )lua_to_Fl_Clock_Output(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->value());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Clock_Output::value(ulong v) */
int lua_call2_Fl_Clock_Output__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Clock_Output * __self__;
     unsigned long v;
    
    __self__ = ( class Fl_Clock_Output * )lua_to_Fl_Clock_Output(__S__, 1, &__ERROR__);
    v = ( unsigned long )(long)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->value(v);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Clock_Output__value(__S__);
}
/* void Fl_Clock_Output::value(int , int , int ) */
int lua_call3_Fl_Clock_Output__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 4) goto error;
  {
     class Fl_Clock_Output * __self__;
     int __2__;
     int __3__;
     int __4__;
    
    __self__ = ( class Fl_Clock_Output * )lua_to_Fl_Clock_Output(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->value(__2__, __3__, __4__);
    ;
    return 0;
  }
  
error:
  return lua_call2_Fl_Clock_Output__value(__S__);
}
/* void Fl_Group::add_resizable(class Fl_Widget & o) */
int lua_call1_Fl_Group__add_resizable(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Group * __self__;
    
    __self__ = ( class Fl_Group * )lua_to_Fl_Group(__S__, 1, &__ERROR__);
     class Fl_Widget & o = ( class Fl_Widget & )(*lua_to_Fl_Widget(__S__, 2, &__ERROR__));
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->add_resizable(o);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Display::move_up() */
int lua_call1_Fl_Text_Display__move_up(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Display * __self__;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->move_up());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::dnd() */
int lua_call1_Fl__dnd(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::dnd());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Group::insert(class Fl_Widget & , int i) */
int lua_call1_Fl_Group__insert(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Group * __self__;
     class Fl_Widget & __2__ = ( class Fl_Widget & )(*lua_to_Fl_Widget(__S__, 2, &__ERROR__));
     int i;
    
    __self__ = ( class Fl_Group * )lua_to_Fl_Group(__S__, 1, &__ERROR__);
    i = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->insert(__2__, i);
    lua_settop(__S__, 0);
    ;
    lua_push_Fl_Widget(__S__, &(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Group::insert(class Fl_Widget & o, class Fl_Widget * before) */
int lua_call2_Fl_Group__insert(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Group * __self__;
     class Fl_Widget & o = ( class Fl_Widget & )(*lua_to_Fl_Widget(__S__, 2, &__ERROR__));
     class Fl_Widget * before;
    
    __self__ = ( class Fl_Group * )lua_to_Fl_Group(__S__, 1, &__ERROR__);
    before = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 3, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->insert(o, before);
    lua_settop(__S__, 0);
    ;
    lua_push_Fl_Widget(__S__, &(o));
    return 1;
  }
  
error:
  return lua_call1_Fl_Group__insert(__S__);
}
/* void fl_begin_polygon() */
int lua_call1_fl_begin_polygon(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    fl_begin_polygon();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Widget::inside(const class Fl_Widget * o)const  */
int lua_call1_Fl_Widget__inside(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Widget * __self__;
     class Fl_Widget * o;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    o = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->inside(o));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Group::children()const  */
int lua_call1_Fl_Group__children(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Group * __self__;
    
    __self__ = ( class Fl_Group * )lua_to_Fl_Group(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->children());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Group * Fl_Widget::parent()const  */
int lua_call1_Fl_Widget__parent(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Group(__S__, __self__->parent());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::parent(class Fl_Group * p) */
int lua_call2_Fl_Widget__parent(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Widget * __self__;
     class Fl_Group * p;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    p = ( class Fl_Group * )lua_to_Fl_Group(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->parent(p);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Widget__parent(__S__);
}
/* void Fl_Group::focus(class Fl_Widget * o) */
int lua_call1_Fl_Group__focus(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Group * __self__;
     class Fl_Widget * o;
    
    __self__ = ( class Fl_Group * )lua_to_Fl_Group(__S__, 1, &__ERROR__);
    o = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->focus(o);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser::make_visible(int n) */
int lua_call1_Fl_Browser__make_visible(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Browser * __self__;
     int n;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    n = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->make_visible(n);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* long Fl_Menu_Item::argument()const  */
int lua_call1_Fl_Menu_Item__argument(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->argument());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_Item::argument(long v) */
int lua_call2_Fl_Menu_Item__argument(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     struct Fl_Menu_Item * __self__;
     long v;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    v = ( long )(long)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->argument(v);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Menu_Item__argument(__S__);
}
/* void Fl_Help_View::resize(int , int , int , int ) */
int lua_call1_Fl_Help_View__resize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Help_View * __self__;
     int __2__;
     int __3__;
     int __4__;
     int __5__;
    
    __self__ = ( class Fl_Help_View * )lua_to_Fl_Help_View(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    __5__ = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->resize(__2__, __3__, __4__, __5__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Buffer::word_end(int pos) */
int lua_call1_Fl_Text_Buffer__word_end(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Buffer * __self__;
     int pos;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    pos = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->word_end(pos));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Editor::kf_enter(int c, class Fl_Text_Editor * e) */
int lua_call1_Fl_Text_Editor__kf_enter(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int c;
     class Fl_Text_Editor * e;
    
    c = ( int )(int)lua_tonumber(__S__, 1);
    e = ( class Fl_Text_Editor * )lua_to_Fl_Text_Editor(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Text_Editor::kf_enter(c, e));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::clear_output() */
int lua_call1_Fl_Widget__clear_output(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->clear_output();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const char * Fl_Input_::value()const  */
int lua_call1_Fl_Input___value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Input_ * __self__;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->value());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Input_::value(const char * ) */
int lua_call2_Fl_Input___value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Input_ * __self__;
     char * __2__;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    __2__ = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->value(__2__));
    return 1;
  }
  
error:
  return lua_call1_Fl_Input___value(__S__);
}
/* int Fl_Input_::value(const char * , int ) */
int lua_call3_Fl_Input___value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Input_ * __self__;
     char * __2__;
     int __3__;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    __2__ = ( char * )(char  *)lua_tostring(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->value(__2__, __3__));
    return 1;
  }
  
error:
  return lua_call2_Fl_Input___value(__S__);
}
/* Fl_Font Fl_Widget::labelfont()const  */
int lua_call1_Fl_Widget__labelfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->labelfont());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::labelfont(uchar a) */
int lua_call2_Fl_Widget__labelfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Widget * __self__;
     unsigned char a;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    a = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->labelfont(a);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Widget__labelfont(__S__);
}
/* int Fl_Help_Dialog::visible() */
int lua_call1_Fl_Help_Dialog__visible(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Help_Dialog * __self__;
    
    __self__ = ( class Fl_Help_Dialog * )lua_to_Fl_Help_Dialog(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->visible());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::reload_scheme() */
int lua_call1_Fl__reload_scheme(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::reload_scheme());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const char * Fl_File_Chooser::label() */
int lua_call1_Fl_File_Chooser__label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Chooser * __self__;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->label());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_File_Chooser::label(const char * l) */
int lua_call2_Fl_File_Chooser__label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_File_Chooser * __self__;
     char * l;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    l = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->label(l);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_File_Chooser__label(__S__);
}
/* int Fl_Window::y_root()const  */
int lua_call1_Fl_Window__y_root(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Window * __self__;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->y_root());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Color_Chooser::Fl_Color_Chooser(int , int , int , int , const char * =0) */
int lua_call1_Fl_Color_Chooser__Fl_Color_Chooser(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int __1__;
     int __2__;
     int __3__;
     int __4__;
     char * __5__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Color_Chooser(__S__, new Fl_Color_Chooser(__1__, __2__, __3__, __4__));
      return 1;
    } else {
      __5__ = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Color_Chooser(__S__, new Fl_Color_Chooser(__1__, __2__, __3__, __4__, __5__));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Menu_::item_pathname(char * name, int namelen, const struct Fl_Menu_Item * finditem=0)const  */
int lua_call1_Fl_Menu___item_pathname(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Menu_ * __self__;
     char * name;
     int namelen;
     struct Fl_Menu_Item * finditem;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    name = ( char * )(char  *)lua_tostring(__S__, 2);
    namelen = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (nparam <= 3) {
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, __self__->item_pathname(name, namelen));
      return 1;
    } else {
      finditem = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 4, &__ERROR__);
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, __self__->item_pathname(name, namelen, finditem));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Buffer::remove_secondary_selection() */
int lua_call1_Fl_Text_Buffer__remove_secondary_selection(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Buffer * __self__;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->remove_secondary_selection();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* uchar Fl_Browser_::has_scrollbar()const  */
int lua_call1_Fl_Browser___has_scrollbar(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Browser_ * __self__;
    
    __self__ = ( class Fl_Browser_ * )lua_to_Fl_Browser_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->has_scrollbar());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser_::has_scrollbar(uchar i) */
int lua_call2_Fl_Browser___has_scrollbar(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Browser_ * __self__;
     unsigned char i;
    
    __self__ = ( class Fl_Browser_ * )lua_to_Fl_Browser_(__S__, 1, &__ERROR__);
    i = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->has_scrollbar(i);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Browser___has_scrollbar(__S__);
}
/* void Fl_Pixmap::desaturate() */
int lua_call1_Fl_Pixmap__desaturate(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Pixmap * __self__;
    
    __self__ = ( class Fl_Pixmap * )lua_to_Fl_Pixmap(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->desaturate();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_Window::flush() */
int lua_call1_Fl_Menu_Window__flush(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Menu_Window * __self__;
    
    __self__ = ( class Fl_Menu_Window * )lua_to_Fl_Menu_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->flush();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Widget * Fl_Group::resizable()const  */
int lua_call1_Fl_Group__resizable(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Group * __self__;
    
    __self__ = ( class Fl_Group * )lua_to_Fl_Group(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Widget(__S__, __self__->resizable());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Group::resizable(class Fl_Widget * o) */
int lua_call2_Fl_Group__resizable(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Group * __self__;
     class Fl_Widget * o;
    
    __self__ = ( class Fl_Group * )lua_to_Fl_Group(__S__, 1, &__ERROR__);
    o = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->resizable(o);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Group__resizable(__S__);
}
/* void Fl_Group::resizable(class Fl_Widget & o) */
int lua_call3_Fl_Group__resizable(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Group * __self__;
    
    __self__ = ( class Fl_Group * )lua_to_Fl_Group(__S__, 1, &__ERROR__);
     class Fl_Widget & o = ( class Fl_Widget & )(*lua_to_Fl_Widget(__S__, 2, &__ERROR__));
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->resizable(o);
    ;
    return 0;
  }
  
error:
  return lua_call2_Fl_Group__resizable(__S__);
}
/* int Fl::event_length() */
int lua_call1_Fl__event_length(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::event_length());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::event_x_root() */
int lua_call1_Fl__event_x_root(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::event_x_root());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::handle(int , class Fl_Window * ) */
int lua_call1_Fl__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int __1__;
     class Fl_Window * __2__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    __2__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::handle(__1__, __2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* char Fl_Widget::label_shortcut(const char * t) */
int lua_call1_Fl_Widget__label_shortcut(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * t;
    
    t = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Widget::label_shortcut(t));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Boxtype Fl_Widget::box()const  */
int lua_call1_Fl_Widget__box(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->box());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::box(Fl_Boxtype a) */
int lua_call2_Fl_Widget__box(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Widget * __self__;
     Fl_Boxtype a;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    a = ( Fl_Boxtype )(Fl_Boxtype)(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->box(a);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Widget__box(__S__);
}
/* int Fl::compose(int & del) */
int lua_call1_Fl__compose(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     int del;
    
    del = ( int )(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::compose(del));
    lua_pushnumber(__S__, del);
    return 2;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Text_Buffer * Fl_Text_Display::buffer() */
int lua_call1_Fl_Text_Display__buffer(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Display * __self__;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Text_Buffer(__S__, __self__->buffer());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Display::buffer(class Fl_Text_Buffer & buf) */
int lua_call2_Fl_Text_Display__buffer(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Display * __self__;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
     class Fl_Text_Buffer & buf = ( class Fl_Text_Buffer & )(*lua_to_Fl_Text_Buffer(__S__, 2, &__ERROR__));
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->buffer(buf);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Text_Display__buffer(__S__);
}
/* void Fl_Text_Display::buffer(class Fl_Text_Buffer * buf) */
int lua_call3_Fl_Text_Display__buffer(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Display * __self__;
     class Fl_Text_Buffer * buf;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    buf = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->buffer(buf);
    ;
    return 0;
  }
  
error:
  return lua_call2_Fl_Text_Display__buffer(__S__);
}
/* int Fl::get_key(int ) */
int lua_call1_Fl__get_key(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     int __1__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::get_key(__1__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::deactivate() */
int lua_call1_Fl_Widget__deactivate(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->deactivate();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_Window::hide() */
int lua_call1_Fl_Menu_Window__hide(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Menu_Window * __self__;
    
    __self__ = ( class Fl_Menu_Window * )lua_to_Fl_Menu_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->hide();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Group::handle(int ) */
int lua_call1_Fl_Group__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Group * __self__;
     int __2__;
    
    __self__ = ( class Fl_Group * )lua_to_Fl_Group(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Buffer::replace_secondary_selection(const char * text) */
int lua_call1_Fl_Text_Buffer__replace_secondary_selection(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Buffer * __self__;
     char * text;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    text = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->replace_secondary_selection(text);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Help_View::leftline()const  */
int lua_call1_Fl_Help_View__leftline(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Help_View * __self__;
    
    __self__ = ( class Fl_Help_View * )lua_to_Fl_Help_View(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->leftline());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Help_View::leftline(int ) */
int lua_call2_Fl_Help_View__leftline(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Help_View * __self__;
     int __2__;
    
    __self__ = ( class Fl_Help_View * )lua_to_Fl_Help_View(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->leftline(__2__);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Help_View__leftline(__S__);
}
/* void Fl_Text_Selection::set_rectangular(int start, int end, int rectStart, int rectEnd) */
int lua_call1_Fl_Text_Selection__set_rectangular(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Text_Selection * __self__;
     int start;
     int end;
     int rectStart;
     int rectEnd;
    
    __self__ = ( class Fl_Text_Selection * )lua_to_Fl_Text_Selection(__S__, 1, &__ERROR__);
    start = ( int )(int)lua_tonumber(__S__, 2);
    end = ( int )(int)lua_tonumber(__S__, 3);
    rectStart = ( int )(int)lua_tonumber(__S__, 4);
    rectEnd = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->set_rectangular(start, end, rectStart, rectEnd);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::set_color(Fl_Color , unsigned int ) */
int lua_call1_Fl__set_color(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     Fl_Color __1__;
     unsigned int __2__;
    
    __1__ = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 1);
    __2__ = ( unsigned int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    Fl::set_color(__1__, __2__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::set_color(Fl_Color , uchar , uchar , uchar ) */
int lua_call2_Fl__set_color(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     Fl_Color __1__;
     unsigned char __2__;
     unsigned char __3__;
     unsigned char __4__;
    
    __1__ = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 1);
    __2__ = ( unsigned char )(char)lua_tonumber(__S__, 2);
    __3__ = ( unsigned char )(char)lua_tonumber(__S__, 3);
    __4__ = ( unsigned char )(char)lua_tonumber(__S__, 4);
    
    /* Actual call */
    Fl::set_color(__1__, __2__, __3__, __4__);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl__set_color(__S__);
}
/* int Fl_Text_Display::rewind_lines(int startPos, int nLines) */
int lua_call1_Fl_Text_Display__rewind_lines(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Text_Display * __self__;
     int startPos;
     int nLines;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    startPos = ( int )(int)lua_tonumber(__S__, 2);
    nLines = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->rewind_lines(startPos, nLines));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Buffer::insertfile(const char * file, int pos, int buflen=128 * 1024) */
int lua_call1_Fl_Text_Buffer__insertfile(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Text_Buffer * __self__;
     char * file;
     int pos;
     int buflen;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    file = ( char * )(char  *)lua_tostring(__S__, 2);
    pos = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (nparam <= 3) {
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, __self__->insertfile(file, pos));
      return 1;
    } else {
      buflen = ( int )(int)lua_tonumber(__S__, 4);
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, __self__->insertfile(file, pos, buflen));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Boxtype fl_define_FL_DIAMOND_BOX() */
int lua_call1_fl_define_FL_DIAMOND_BOX(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_define_FL_DIAMOND_BOX());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Adjuster::Fl_Adjuster(int X, int Y, int W, int H, const char * l=0) */
int lua_call1_Fl_Adjuster__Fl_Adjuster(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     char * l;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Adjuster(__S__, new Fl_Adjuster(X, Y, W, H));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Adjuster(__S__, new Fl_Adjuster(X, Y, W, H, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* double fl_transform_x(double x, double y) */
int lua_call1_fl_transform_x(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     double x;
     double y;
    
    x = ( double )(double)lua_tonumber(__S__, 1);
    y = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_transform_x(x, y));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Menu_Item::radio()const  */
int lua_call1_Fl_Menu_Item__radio(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->radio());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::set_output() */
int lua_call1_Fl_Widget__set_output(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->set_output();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Menu_Item::add(const char * a, const char * b, Fl_Callback * c, void * d=0, int e=0) */
/* SKIPPED (argument #4) */
/* int Fl_Menu_Item::add(const char * , int shortcut, Fl_Callback * , void * =0, int =0) */
/* SKIPPED (argument #4) */
/*  Fl_Wizard::Fl_Wizard(int , int , int , int , const char * =0) */
int lua_call1_Fl_Wizard__Fl_Wizard(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int __1__;
     int __2__;
     int __3__;
     int __4__;
     char * __5__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Wizard(__S__, new Fl_Wizard(__1__, __2__, __3__, __4__));
      return 1;
    } else {
      __5__ = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Wizard(__S__, new Fl_Wizard(__1__, __2__, __3__, __4__, __5__));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Double_Window::Fl_Double_Window(int W, int H, const char * l=0) */
int lua_call1_Fl_Double_Window__Fl_Double_Window(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int W;
     int H;
     char * l;
    
    W = ( int )(int)lua_tonumber(__S__, 1);
    H = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (nparam <= 2) {
      lua_settop(__S__, 0);
      lua_push_Fl_Double_Window(__S__, new Fl_Double_Window(W, H));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 3);
      lua_settop(__S__, 0);
      lua_push_Fl_Double_Window(__S__, new Fl_Double_Window(W, H, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Double_Window::Fl_Double_Window(int X, int Y, int W, int H, const char * l=0) */
int lua_call2_Fl_Double_Window__Fl_Double_Window(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     char * l;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Double_Window(__S__, new Fl_Double_Window(X, Y, W, H));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Double_Window(__S__, new Fl_Double_Window(X, Y, W, H, l));
      return 1;
    }
  }
  
error:
  return lua_call1_Fl_Double_Window__Fl_Double_Window(__S__);
}
/* int Fl_Tabs::handle(int ) */
int lua_call1_Fl_Tabs__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Tabs * __self__;
     int __2__;
    
    __self__ = ( class Fl_Tabs * )lua_to_Fl_Tabs(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Clock_Output::second()const  */
int lua_call1_Fl_Clock_Output__second(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Clock_Output * __self__;
    
    __self__ = ( class Fl_Clock_Output * )lua_to_Fl_Clock_Output(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->second());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::resize(int , int , int , int ) */
int lua_call1_Fl_Widget__resize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Widget * __self__;
     int __2__;
     int __3__;
     int __4__;
     int __5__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    __5__ = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->resize(__2__, __3__, __4__, __5__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Tooltip::disable() */
int lua_call1_Fl_Tooltip__disable(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    Fl_Tooltip::disable();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_::global() */
int lua_call1_Fl_Menu___global(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Menu_ * __self__;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->global();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Buffer::copy(class Fl_Text_Buffer * fromBuf, int fromStart, int fromEnd, int toPos) */
int lua_call1_Fl_Text_Buffer__copy(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Text_Buffer * __self__;
     class Fl_Text_Buffer * fromBuf;
     int fromStart;
     int fromEnd;
     int toPos;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    fromBuf = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 2, &__ERROR__);
    fromStart = ( int )(int)lua_tonumber(__S__, 3);
    fromEnd = ( int )(int)lua_tonumber(__S__, 4);
    toPos = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->copy(fromBuf, fromStart, fromEnd, toPos);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int fl_open_uri(const char * uri, char * msg=( char * ) 0, int msglen=0) */
int lua_call1_fl_open_uri(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * uri;
     char * msg;
     int msglen;
    
    uri = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    if (nparam <= 1) {
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, fl_open_uri(uri));
      return 1;
    } else {
      msg = ( char * )(char  *)lua_tostring(__S__, 2);
      if (nparam <= 2) {
        lua_settop(__S__, 0);
        lua_pushnumber(__S__, fl_open_uri(uri, msg));
        return 1;
      } else {
        msglen = ( int )(int)lua_tonumber(__S__, 3);
        lua_settop(__S__, 0);
        lua_pushnumber(__S__, fl_open_uri(uri, msg, msglen));
        return 1;
      }
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Callback_p Fl_Menu_Item::callback()const  */
/* SKIPPED (return type) */
/* void Fl_Menu_Item::callback(Fl_Callback * c) */
/* SKIPPED (argument #2) */
/* void Fl_Menu_Item::callback(Fl_Callback0 * c) */
/* SKIPPED (argument #2) */
/* void Fl_Menu_Item::callback(Fl_Callback * c, void * p) */
/* SKIPPED (argument #2) */
/* void Fl_Menu_Item::callback(Fl_Callback1 * c, long p=0) */
/* SKIPPED (argument #2) */
/*  Fl_Multiline_Output::Fl_Multiline_Output(int X, int Y, int W, int H, const char * l=0) */
int lua_call1_Fl_Multiline_Output__Fl_Multiline_Output(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     char * l;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Multiline_Output(__S__, new Fl_Multiline_Output(X, Y, W, H));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Multiline_Output(__S__, new Fl_Multiline_Output(X, Y, W, H, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::visual(int ) */
int lua_call1_Fl__visual(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     int __1__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::visual(__1__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Buffer::savefile(const char * file, int buflen=128 * 1024) */
int lua_call1_Fl_Text_Buffer__savefile(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Buffer * __self__;
     char * file;
     int buflen;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    file = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (nparam <= 2) {
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, __self__->savefile(file));
      return 1;
    } else {
      buflen = ( int )(int)lua_tonumber(__S__, 3);
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, __self__->savefile(file, buflen));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Editor::kf_page_up(int c, class Fl_Text_Editor * e) */
int lua_call1_Fl_Text_Editor__kf_page_up(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int c;
     class Fl_Text_Editor * e;
    
    c = ( int )(int)lua_tonumber(__S__, 1);
    e = ( class Fl_Text_Editor * )lua_to_Fl_Text_Editor(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Text_Editor::kf_page_up(c, e));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const struct Fl_Menu_Item * Fl_Menu_Item::find_shortcut(int * ip=0)const  */
int lua_call1_Fl_Menu_Item__find_shortcut(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
     int * ip;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (nparam <= 1) {
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_push_Fl_Menu_Item(__S__, __self__->find_shortcut());
      return 1;
    } else {
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_push_Fl_Menu_Item(__S__, __self__->find_shortcut(ip));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::box_dx(Fl_Boxtype ) */
int lua_call1_Fl__box_dx(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     Fl_Boxtype __1__;
    
    __1__ = ( Fl_Boxtype )(Fl_Boxtype)(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::box_dx(__1__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_RGB_Image::color_average(Fl_Color c, float i) */
int lua_call1_Fl_RGB_Image__color_average(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_RGB_Image * __self__;
     Fl_Color c;
     float i;
    
    __self__ = ( class Fl_RGB_Image * )lua_to_Fl_RGB_Image(__S__, 1, &__ERROR__);
    c = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 2);
    i = ( float )(float)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->color_average(c, i);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const struct Fl_Menu_Item * Fl_Menu_::test_shortcut() */
int lua_call1_Fl_Menu___test_shortcut(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Menu_ * __self__;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Menu_Item(__S__, __self__->test_shortcut());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Preferences::Name::Name(unsigned int n) */
int lua_call1_Fl_Preferences__Name__Name(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     unsigned int n;
    
    n = ( unsigned int )(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_Preferences__Name(__S__, new Fl_Preferences::Name(n));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Preferences::Name::Name(const char * format, ...) */
int lua_call2_Fl_Preferences__Name__Name(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * format;
    
    format = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_Preferences__Name(__S__, new Fl_Preferences::Name(format));
    return 1;
  }
  
error:
  return lua_call1_Fl_Preferences__Name__Name(__S__);
}
/* void Fl_Widget::measure_label(int & xx, int & yy) */
int lua_call1_Fl_Widget__measure_label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Widget * __self__;
     int xx;
     int yy;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    xx = ( int )(int)lua_tonumber(__S__, 2);
    yy = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->measure_label(xx, yy);
    lua_settop(__S__, 0);
    ;
    lua_pushnumber(__S__, xx);
    lua_pushnumber(__S__, yy);
    return 2;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_File_Chooser::visible() */
int lua_call1_Fl_File_Chooser__visible(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Chooser * __self__;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->visible());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Pack::draw() */
int lua_call1_Fl_Pack__draw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Pack * __self__;
    
    __self__ = ( class Fl_Pack * )lua_to_Fl_Pack(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->draw();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* char Fl_Timer::suspended()const  */
int lua_call1_Fl_Timer__suspended(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Timer * __self__;
    
    __self__ = ( class Fl_Timer * )lua_to_Fl_Timer(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->suspended());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Timer::suspended(char d) */
int lua_call2_Fl_Timer__suspended(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Timer * __self__;
     char d;
    
    __self__ = ( class Fl_Timer * )lua_to_Fl_Timer(__S__, 1, &__ERROR__);
    d = ( char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->suspended(d);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Timer__suspended(__S__);
}
/* void fl_draw_box(Fl_Boxtype , int x, int y, int w, int h, Fl_Color ) */
int lua_call1_fl_draw_box(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 6) goto error;
  {
     Fl_Boxtype __1__;
     int x;
     int y;
     int w;
     int h;
     Fl_Color __6__;
    
    __1__ = ( Fl_Boxtype )(Fl_Boxtype)(int)lua_tonumber(__S__, 1);
    x = ( int )(int)lua_tonumber(__S__, 2);
    y = ( int )(int)lua_tonumber(__S__, 3);
    w = ( int )(int)lua_tonumber(__S__, 4);
    h = ( int )(int)lua_tonumber(__S__, 5);
    __6__ = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 6);
    
    /* Actual call */
    fl_draw_box(__1__, x, y, w, h, __6__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::set_font(Fl_Font , Fl_Font ) */
int lua_call1_Fl__set_font(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     Fl_Font __1__;
     Fl_Font __2__;
    
    __1__ = ( Fl_Font )(Fl_Font)(int)lua_tonumber(__S__, 1);
    __2__ = ( Fl_Font )(Fl_Font)(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    Fl::set_font(__1__, __2__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::set_font(Fl_Font , const char * ) */
int lua_call2_Fl__set_font(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     Fl_Font __1__;
     char * __2__;
    
    __1__ = ( Fl_Font )(Fl_Font)(int)lua_tonumber(__S__, 1);
    __2__ = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    Fl::set_font(__1__, __2__);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl__set_font(__S__);
}
/*  Fl_Value_Input::Fl_Value_Input(int x, int y, int w, int h, const char * l=0) */
int lua_call1_Fl_Value_Input__Fl_Value_Input(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Value_Input(__S__, new Fl_Value_Input(x, y, w, h));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Value_Input(__S__, new Fl_Value_Input(x, y, w, h, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Display::cursor_style(int style) */
int lua_call1_Fl_Text_Display__cursor_style(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Display * __self__;
     int style;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    style = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->cursor_style(style);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Preferences::groups() */
int lua_call1_Fl_Preferences__groups(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Preferences * __self__;
    
    __self__ = ( class Fl_Preferences * )lua_to_Fl_Preferences(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->groups());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Tooltip::size() */
int lua_call1_Fl_Tooltip__size(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Tooltip::size());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Tooltip::size(int s) */
int lua_call2_Fl_Tooltip__size(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     int s;
    
    s = ( int )(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    Fl_Tooltip::size(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Tooltip__size(__S__);
}
/* int Fl::event_x() */
int lua_call1_Fl__event_x(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::event_x());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Editor::kf_ignore(int c, class Fl_Text_Editor * e) */
int lua_call1_Fl_Text_Editor__kf_ignore(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int c;
     class Fl_Text_Editor * e;
    
    c = ( int )(int)lua_tonumber(__S__, 1);
    e = ( class Fl_Text_Editor * )lua_to_Fl_Text_Editor(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Text_Editor::kf_ignore(c, e));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Widget::visible_focus() */
int lua_call1_Fl_Widget__visible_focus(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->visible_focus());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::visible_focus(int v) */
int lua_call2_Fl_Widget__visible_focus(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Widget * __self__;
     int v;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    v = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->visible_focus(v);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Widget__visible_focus(__S__);
}
/* int Fl::box_dy(Fl_Boxtype ) */
int lua_call1_Fl__box_dy(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     Fl_Boxtype __1__;
    
    __1__ = ( Fl_Boxtype )(Fl_Boxtype)(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::box_dy(__1__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const char * Fl_Preferences::entry(int ) */
int lua_call1_Fl_Preferences__entry(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Preferences * __self__;
     int __2__;
    
    __self__ = ( class Fl_Preferences * )lua_to_Fl_Preferences(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->entry(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Widget * Fl_Tabs::value() */
int lua_call1_Fl_Tabs__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Tabs * __self__;
    
    __self__ = ( class Fl_Tabs * )lua_to_Fl_Tabs(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Widget(__S__, __self__->value());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Tabs::value(class Fl_Widget * ) */
int lua_call2_Fl_Tabs__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Tabs * __self__;
     class Fl_Widget * __2__;
    
    __self__ = ( class Fl_Tabs * )lua_to_Fl_Tabs(__S__, 1, &__ERROR__);
    __2__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->value(__2__));
    return 1;
  }
  
error:
  return lua_call1_Fl_Tabs__value(__S__);
}
/* void Fl_Group::add(class Fl_Widget & ) */
int lua_call1_Fl_Group__add(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Group * __self__;
    
    __self__ = ( class Fl_Group * )lua_to_Fl_Group(__S__, 1, &__ERROR__);
     class Fl_Widget & __2__ = ( class Fl_Widget & )(*lua_to_Fl_Widget(__S__, 2, &__ERROR__));
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->add(__2__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Group::add(class Fl_Widget * o) */
int lua_call2_Fl_Group__add(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Group * __self__;
     class Fl_Widget * o;
    
    __self__ = ( class Fl_Group * )lua_to_Fl_Group(__S__, 1, &__ERROR__);
    o = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->add(o);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Group__add(__S__);
}
/* void Fl_Label::measure(int & , int & )const  */
int lua_call1_Fl_Label__measure(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     struct Fl_Label * __self__;
     int __2__;
     int __3__;
    
    __self__ = ( struct Fl_Label * )lua_to_Fl_Label(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->measure(__2__, __3__);
    lua_settop(__S__, 0);
    ;
    lua_pushnumber(__S__, __2__);
    lua_pushnumber(__S__, __3__);
    return 2;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Editor::insert_mode() */
int lua_call1_Fl_Text_Editor__insert_mode(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Editor * __self__;
    
    __self__ = ( class Fl_Text_Editor * )lua_to_Fl_Text_Editor(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->insert_mode());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Editor::insert_mode(int b) */
int lua_call2_Fl_Text_Editor__insert_mode(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Editor * __self__;
     int b;
    
    __self__ = ( class Fl_Text_Editor * )lua_to_Fl_Text_Editor(__S__, 1, &__ERROR__);
    b = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->insert_mode(b);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Text_Editor__insert_mode(__S__);
}
/* int Fl::event_state() */
int lua_call1_Fl__event_state(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::event_state());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::event_state(int i) */
int lua_call2_Fl__event_state(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     int i;
    
    i = ( int )(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::event_state(i));
    return 1;
  }
  
error:
  return lua_call1_Fl__event_state(__S__);
}
/* int Fl::draw_box_active() */
int lua_call1_Fl__draw_box_active(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::draw_box_active());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Display::wrapped_column(int row, int column) */
int lua_call1_Fl_Text_Display__wrapped_column(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Text_Display * __self__;
     int row;
     int column;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    row = ( int )(int)lua_tonumber(__S__, 2);
    column = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->wrapped_column(row, column));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser::swap(int a, int b) */
int lua_call1_Fl_Browser__swap(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Browser * __self__;
     int a;
     int b;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    a = ( int )(int)lua_tonumber(__S__, 2);
    b = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->swap(a, b);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* double fl_transform_dy(double x, double y) */
int lua_call1_fl_transform_dy(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     double x;
     double y;
    
    x = ( double )(double)lua_tonumber(__S__, 1);
    y = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_transform_dy(x, y));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_File_Icon::size() */
int lua_call1_Fl_File_Icon__size(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Icon * __self__;
    
    __self__ = ( class Fl_File_Icon * )lua_to_Fl_File_Icon(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->size());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* char * Fl_File_Chooser::directory() */
int lua_call1_Fl_File_Chooser__directory(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Chooser * __self__;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->directory());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_File_Chooser::directory(const char * d) */
int lua_call2_Fl_File_Chooser__directory(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_File_Chooser * __self__;
     char * d;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    d = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->directory(d);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_File_Chooser__directory(__S__);
}
/* double Fl_Spinner::mininum()const  */
int lua_call1_Fl_Spinner__mininum(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Spinner * __self__;
    
    __self__ = ( class Fl_Spinner * )lua_to_Fl_Spinner(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->mininum());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Font Fl_Value_Input::textfont()const  */
int lua_call1_Fl_Value_Input__textfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Value_Input * __self__;
    
    __self__ = ( class Fl_Value_Input * )lua_to_Fl_Value_Input(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textfont());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Value_Input::textfont(uchar s) */
int lua_call2_Fl_Value_Input__textfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Value_Input * __self__;
     unsigned char s;
    
    __self__ = ( class Fl_Value_Input * )lua_to_Fl_Value_Input(__S__, 1, &__ERROR__);
    s = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textfont(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Value_Input__textfont(__S__);
}
/* void Fl::background2(uchar , uchar , uchar ) */
int lua_call1_Fl__background2(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 3) goto error;
  {
     unsigned char __1__;
     unsigned char __2__;
     unsigned char __3__;
    
    __1__ = ( unsigned char )(char)lua_tonumber(__S__, 1);
    __2__ = ( unsigned char )(char)lua_tonumber(__S__, 2);
    __3__ = ( unsigned char )(char)lua_tonumber(__S__, 3);
    
    /* Actual call */
    Fl::background2(__1__, __2__, __3__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Window::clear_border() */
int lua_call1_Fl_Window__clear_border(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Window * __self__;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->clear_border();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_Item::activate() */
int lua_call1_Fl_Menu_Item__activate(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->activate();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* double Fl_Color_Chooser::g()const  */
int lua_call1_Fl_Color_Chooser__g(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Color_Chooser * __self__;
    
    __self__ = ( class Fl_Color_Chooser * )lua_to_Fl_Color_Chooser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->g());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Chart::replace(int , double , const char * =0, unsigned int =0) */
int lua_call1_Fl_Chart__replace(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Chart * __self__;
     int __2__;
     double __3__;
     char * __4__;
     unsigned int __5__;
    
    __self__ = ( class Fl_Chart * )lua_to_Fl_Chart(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( double )(double)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (nparam <= 3) {
      if (__ERROR__) goto error;
      
      __self__->replace(__2__, __3__);
    } else {
      __4__ = ( char * )(char  *)lua_tostring(__S__, 4);
      if (nparam <= 4) {
        if (__ERROR__) goto error;
        
        __self__->replace(__2__, __3__, __4__);
      } else {
        __5__ = ( unsigned int )(int)lua_tonumber(__S__, 5);
        if (__ERROR__) goto error;
        
        __self__->replace(__2__, __3__, __4__, __5__);
      }
    }
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const char * Fl_Window::icon()const  */
int lua_call1_Fl_Window__icon(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Window * __self__;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->icon());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Window::icon(const char * ic) */
int lua_call2_Fl_Window__icon(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Window * __self__;
     char * ic;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    ic = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->icon(ic);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Window__icon(__S__);
}
/* char Fl_Preferences::get(const char * entry, char * & value, const char * defaultValue) */
/* SKIPPED (argument #3) */
/* char Fl_Preferences::get(const char * entry, float & value, float defaultValue) */
int lua_call2_Fl_Preferences__get(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 4) goto error;
  {
     class Fl_Preferences * __self__;
     char * entry;
     float value;
     float defaultValue;
    
    __self__ = ( class Fl_Preferences * )lua_to_Fl_Preferences(__S__, 1, &__ERROR__);
    entry = ( char * )(char  *)lua_tostring(__S__, 2);
    value = ( float )(float)lua_tonumber(__S__, 3);
    defaultValue = ( float )(float)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->get(entry, value, defaultValue));
    lua_pushnumber(__S__, value);
    return 2;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* char Fl_Preferences::get(const char * entry, double & value, double defaultValue) */
int lua_call3_Fl_Preferences__get(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 4) goto error;
  {
     class Fl_Preferences * __self__;
     char * entry;
     double value;
     double defaultValue;
    
    __self__ = ( class Fl_Preferences * )lua_to_Fl_Preferences(__S__, 1, &__ERROR__);
    entry = ( char * )(char  *)lua_tostring(__S__, 2);
    value = ( double )(double)lua_tonumber(__S__, 3);
    defaultValue = ( double )(double)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->get(entry, value, defaultValue));
    lua_pushnumber(__S__, value);
    return 2;
  }
  
error:
  return lua_call2_Fl_Preferences__get(__S__);
}
/* char Fl_Preferences::get(const char * entry, int & value, int defaultValue) */
int lua_call4_Fl_Preferences__get(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 4) goto error;
  {
     class Fl_Preferences * __self__;
     char * entry;
     int value;
     int defaultValue;
    
    __self__ = ( class Fl_Preferences * )lua_to_Fl_Preferences(__S__, 1, &__ERROR__);
    entry = ( char * )(char  *)lua_tostring(__S__, 2);
    value = ( int )(int)lua_tonumber(__S__, 3);
    defaultValue = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->get(entry, value, defaultValue));
    lua_pushnumber(__S__, value);
    return 2;
  }
  
error:
  return lua_call3_Fl_Preferences__get(__S__);
}
/* char Fl_Preferences::get(const char * entry, void * & value, const void * defaultValue, int defaultSize) */
/* SKIPPED (argument #3) */
/* char Fl_Preferences::get(const char * entry, char * value, const char * defaultValue, int maxSize) */
int lua_call6_Fl_Preferences__get(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Preferences * __self__;
     char * entry;
     char * value;
     char * defaultValue;
     int maxSize;
    
    __self__ = ( class Fl_Preferences * )lua_to_Fl_Preferences(__S__, 1, &__ERROR__);
    entry = ( char * )(char  *)lua_tostring(__S__, 2);
    value = ( char * )(char  *)lua_tostring(__S__, 3);
    defaultValue = ( char * )(char  *)lua_tostring(__S__, 4);
    maxSize = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->get(entry, value, defaultValue, maxSize));
    return 1;
  }
  
error:
  return lua_call4_Fl_Preferences__get(__S__);
}
/* char Fl_Preferences::get(const char * entry, void * value, const void * defaultValue, int defaultSize, int maxSize) */
/* SKIPPED (argument #3) */
/* Fl_Align Fl_Text_Display::scrollbar_align() */
int lua_call1_Fl_Text_Display__scrollbar_align(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Display * __self__;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->scrollbar_align());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Display::scrollbar_align(Fl_Align a) */
int lua_call2_Fl_Text_Display__scrollbar_align(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Display * __self__;
     Fl_Align a;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    a = ( Fl_Align )(Fl_Align)(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->scrollbar_align(a);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Text_Display__scrollbar_align(__S__);
}
/*  Fl_Slider::Fl_Slider(int x, int y, int w, int h, const char * l=0) */
int lua_call1_Fl_Slider__Fl_Slider(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Slider(__S__, new Fl_Slider(x, y, w, h));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Slider(__S__, new Fl_Slider(x, y, w, h, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Slider::Fl_Slider(uchar t, int x, int y, int w, int h, const char * l) */
int lua_call2_Fl_Slider__Fl_Slider(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 6) goto error;
  {
     unsigned char t;
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    t = ( unsigned char )(char)lua_tonumber(__S__, 1);
    x = ( int )(int)lua_tonumber(__S__, 2);
    y = ( int )(int)lua_tonumber(__S__, 3);
    w = ( int )(int)lua_tonumber(__S__, 4);
    h = ( int )(int)lua_tonumber(__S__, 5);
    l = ( char * )(char  *)lua_tostring(__S__, 6);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_Slider(__S__, new Fl_Slider(t, x, y, w, h, l));
    return 1;
  }
  
error:
  return lua_call1_Fl_Slider__Fl_Slider(__S__);
}
/* int Fl_Menu_Item::size()const  */
int lua_call1_Fl_Menu_Item__size(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->size());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::has_timeout(Fl_Timeout_Handler , void * =0) */
/* SKIPPED (argument #1) */
/*  Fl_Multi_Browser::Fl_Multi_Browser(int X, int Y, int W, int H, const char * L=0) */
int lua_call1_Fl_Multi_Browser__Fl_Multi_Browser(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     char * L;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Multi_Browser(__S__, new Fl_Multi_Browser(X, Y, W, H));
      return 1;
    } else {
      L = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Multi_Browser(__S__, new Fl_Multi_Browser(X, Y, W, H, L));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* short Fl_Dial::angle2()const  */
int lua_call1_Fl_Dial__angle2(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Dial * __self__;
    
    __self__ = ( class Fl_Dial * )lua_to_Fl_Dial(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->angle2());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Dial::angle2(short a) */
int lua_call2_Fl_Dial__angle2(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Dial * __self__;
     short a;
    
    __self__ = ( class Fl_Dial * )lua_to_Fl_Dial(__S__, 1, &__ERROR__);
    a = ( short )(short)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->angle2(a);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Dial__angle2(__S__);
}
/* int Fl_Text_Buffer::findchars_forward(int startPos, const char * searchChars, int * foundPos) */
/* SKIPPED (argument #4) */
/* int Fl::box_dw(Fl_Boxtype ) */
int lua_call1_Fl__box_dw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     Fl_Boxtype __1__;
    
    __1__ = ( Fl_Boxtype )(Fl_Boxtype)(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::box_dw(__1__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* char * fl_filename_setext(char * to, const char * ext) */
int lua_call1_fl_filename_setext(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     char * to;
     char * ext;
    
    to = ( char * )(char  *)lua_tostring(__S__, 1);
    ext = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) fl_filename_setext(to, ext));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* char * fl_filename_setext(char * to, int tolen, const char * ext) */
int lua_call2_fl_filename_setext(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 3) goto error;
  {
     char * to;
     int tolen;
     char * ext;
    
    to = ( char * )(char  *)lua_tostring(__S__, 1);
    tolen = ( int )(int)lua_tonumber(__S__, 2);
    ext = ( char * )(char  *)lua_tostring(__S__, 3);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) fl_filename_setext(to, tolen, ext));
    return 1;
  }
  
error:
  return lua_call1_fl_filename_setext(__S__);
}
/* int Fl_Pack::spacing()const  */
int lua_call1_Fl_Pack__spacing(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Pack * __self__;
    
    __self__ = ( class Fl_Pack * )lua_to_Fl_Pack(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->spacing());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Pack::spacing(int i) */
int lua_call2_Fl_Pack__spacing(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Pack * __self__;
     int i;
    
    __self__ = ( class Fl_Pack * )lua_to_Fl_Pack(__S__, 1, &__ERROR__);
    i = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->spacing(i);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Pack__spacing(__S__);
}
/* int Fl_Text_Buffer::secondary_selected() */
int lua_call1_Fl_Text_Buffer__secondary_selected(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Buffer * __self__;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->secondary_selected());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::event_clicks() */
int lua_call1_Fl__event_clicks(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::event_clicks());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::event_clicks(int i) */
int lua_call2_Fl__event_clicks(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     int i;
    
    i = ( int )(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    Fl::event_clicks(i);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl__event_clicks(__S__);
}
/*  Fl_murgaLuaOffScreen::Fl_murgaLuaOffScreen(int , int ) */
int lua_call1_Fl_murgaLuaOffScreen__Fl_murgaLuaOffScreen(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int __1__;
     int __2__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_murgaLuaOffScreen(__S__, new Fl_murgaLuaOffScreen(__1__, __2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_File_Browser::load(const char * directory, Fl_File_Sort_F * sort=fl_numericsort) */
int lua_call1_Fl_File_Browser__load(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_File_Browser * __self__;
     char * directory;
     int ( * sort)(struct dirent * * , struct dirent * * );
    
    __self__ = ( class Fl_File_Browser * )lua_to_Fl_File_Browser(__S__, 1, &__ERROR__);
    directory = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (nparam <= 2) {
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, __self__->load(directory));
      return 1;
    } else {
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, __self__->load(directory, sort));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_register_images() */
int lua_call1_fl_register_images(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    fl_register_images();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const char * Fl_Help_View::value()const  */
int lua_call1_Fl_Help_View__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Help_View * __self__;
    
    __self__ = ( class Fl_Help_View * )lua_to_Fl_Help_View(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->value());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Help_View::value(const char * v) */
int lua_call2_Fl_Help_View__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Help_View * __self__;
     char * v;
    
    __self__ = ( class Fl_Help_View * )lua_to_Fl_Help_View(__S__, 1, &__ERROR__);
    v = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->value(v);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Help_View__value(__S__);
}
/* int Fl_Tile::handle(int ) */
int lua_call1_Fl_Tile__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Tile * __self__;
     int __2__;
    
    __self__ = ( class Fl_Tile * )lua_to_Fl_Tile(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Buffer::substitute_null_characters(char * string, int length) */
int lua_call1_Fl_Text_Buffer__substitute_null_characters(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Text_Buffer * __self__;
     char * string;
     int length;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    string = ( char * )(char  *)lua_tostring(__S__, 2);
    length = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->substitute_null_characters(string, length));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Editor::kf_move(int c, class Fl_Text_Editor * e) */
int lua_call1_Fl_Text_Editor__kf_move(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int c;
     class Fl_Text_Editor * e;
    
    c = ( int )(int)lua_tonumber(__S__, 1);
    e = ( class Fl_Text_Editor * )lua_to_Fl_Text_Editor(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Text_Editor::kf_move(c, e));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_Item::show() */
int lua_call1_Fl_Menu_Item__show(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->show();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Shared_Image::release() */
int lua_call1_Fl_Shared_Image__release(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Shared_Image * __self__;
    
    __self__ = ( class Fl_Shared_Image * )lua_to_Fl_Shared_Image(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->release();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::set_atclose(void ( * f)(class Fl_Window * , void * )) */
/* SKIPPED (argument #1) */
/* int Fl_Text_Display::line_start(int pos) */
int lua_call1_Fl_Text_Display__line_start(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Display * __self__;
     int pos;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    pos = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->line_start(pos));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Buffer::clear_rectangular(int start, int end, int rectStart, int rectEnd) */
int lua_call1_Fl_Text_Buffer__clear_rectangular(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Text_Buffer * __self__;
     int start;
     int end;
     int rectStart;
     int rectEnd;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    start = ( int )(int)lua_tonumber(__S__, 2);
    end = ( int )(int)lua_tonumber(__S__, 3);
    rectStart = ( int )(int)lua_tonumber(__S__, 4);
    rectEnd = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->clear_rectangular(start, end, rectStart, rectEnd);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Repeat_Button::handle(int ) */
int lua_call1_Fl_Repeat_Button__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Repeat_Button * __self__;
     int __2__;
    
    __self__ = ( class Fl_Repeat_Button * )lua_to_Fl_Repeat_Button(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Help_View::topline()const  */
int lua_call1_Fl_Help_View__topline(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Help_View * __self__;
    
    __self__ = ( class Fl_Help_View * )lua_to_Fl_Help_View(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->topline());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Help_View::topline(int ) */
int lua_call2_Fl_Help_View__topline(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Help_View * __self__;
     int __2__;
    
    __self__ = ( class Fl_Help_View * )lua_to_Fl_Help_View(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->topline(__2__);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Help_View__topline(__S__);
}
/* void Fl_Help_View::topline(const char * n) */
int lua_call3_Fl_Help_View__topline(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Help_View * __self__;
     char * n;
    
    __self__ = ( class Fl_Help_View * )lua_to_Fl_Help_View(__S__, 1, &__ERROR__);
    n = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->topline(n);
    ;
    return 0;
  }
  
error:
  return lua_call2_Fl_Help_View__topline(__S__);
}
/* int Fl_Menu_Item::shortcut()const  */
int lua_call1_Fl_Menu_Item__shortcut(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->shortcut());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_Item::shortcut(int s) */
int lua_call2_Fl_Menu_Item__shortcut(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     struct Fl_Menu_Item * __self__;
     int s;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    s = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->shortcut(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Menu_Item__shortcut(__S__);
}
/* void Fl::add_fd(int fd, void ( * cb)(int , void * ), void * =0) */
/* SKIPPED (argument #2) */
/* void Fl::add_fd(int fd, int when, void ( * cb)(int , void * ), void * =0) */
/* SKIPPED (argument #3) */
/* int Fl_Menu_Window::overlay() */
int lua_call1_Fl_Menu_Window__overlay(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Menu_Window * __self__;
    
    __self__ = ( class Fl_Menu_Window * )lua_to_Fl_Menu_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->overlay());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::show() */
int lua_call1_Fl_Widget__show(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->show();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Buffer::selection_position(int * start, int * end) */
/* SKIPPED (argument #2) */
/* int Fl_Text_Buffer::selection_position(int * start, int * end, int * isRect, int * rectStart, int * rectEnd) */
/* SKIPPED (argument #2) */
/*  Fl_Text_Editor::Fl_Text_Editor(int X, int Y, int W, int H, const char * l=0) */
int lua_call1_Fl_Text_Editor__Fl_Text_Editor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     char * l;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Text_Editor(__S__, new Fl_Text_Editor(X, Y, W, H));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Text_Editor(__S__, new Fl_Text_Editor(X, Y, W, H, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* float Fl_Tooltip::delay() */
int lua_call1_Fl_Tooltip__delay(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Tooltip::delay());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Tooltip::delay(float f) */
int lua_call2_Fl_Tooltip__delay(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     float f;
    
    f = ( float )(float)lua_tonumber(__S__, 1);
    
    /* Actual call */
    Fl_Tooltip::delay(f);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Tooltip__delay(__S__);
}
/* int Fl_Help_View::load(const char * f) */
int lua_call1_Fl_Help_View__load(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Help_View * __self__;
     char * f;
    
    __self__ = ( class Fl_Help_View * )lua_to_Fl_Help_View(__S__, 1, &__ERROR__);
    f = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->load(f));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Labeltype fl_define_FL_SHADOW_LABEL() */
int lua_call1_fl_define_FL_SHADOW_LABEL(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_define_FL_SHADOW_LABEL());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Tooltip::exit_(class Fl_Widget * w) */
int lua_call1_Fl_Tooltip__exit_(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     class Fl_Widget * w;
    
    w = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    Fl_Tooltip::exit_(w);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Shared_Image::remove_handler(Fl_Shared_Handler f) */
/* SKIPPED (argument #1) */
/* void Fl_Text_Editor::add_key_binding(int key, int state, Fl_Text_Editor::Key_Func f) */
/* SKIPPED (argument #4) */
/* void Fl_Text_Editor::add_key_binding(int key, int state, Fl_Text_Editor::Key_Func f, struct Fl_Text_Editor::Key_Binding * * list) */
/* SKIPPED (argument #4) */
/* const char * Fl_Window::label()const  */
int lua_call1_Fl_Window__label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Window * __self__;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->label());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Window::label(const char * ) */
int lua_call2_Fl_Window__label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Window * __self__;
     char * __2__;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    __2__ = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->label(__2__);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Window__label(__S__);
}
/* void Fl_Window::label(const char * label, const char * iconlabel) */
int lua_call3_Fl_Window__label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Window * __self__;
     char * label;
     char * iconlabel;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    label = ( char * )(char  *)lua_tostring(__S__, 2);
    iconlabel = ( char * )(char  *)lua_tostring(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->label(label, iconlabel);
    ;
    return 0;
  }
  
error:
  return lua_call2_Fl_Window__label(__S__);
}
/*  Fl_Text_Display::Fl_Text_Display(int X, int Y, int W, int H, const char * l=0) */
int lua_call1_Fl_Text_Display__Fl_Text_Display(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     char * l;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Text_Display(__S__, new Fl_Text_Display(X, Y, W, H));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Text_Display(__S__, new Fl_Text_Display(X, Y, W, H, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Group::forms_end() */
int lua_call1_Fl_Group__forms_end(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Group * __self__;
    
    __self__ = ( class Fl_Group * )lua_to_Fl_Group(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->forms_end();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const struct Fl_Menu_Item * Fl_Input_Choice::menu() */
int lua_call1_Fl_Input_Choice__menu(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Input_Choice * __self__;
    
    __self__ = ( class Fl_Input_Choice * )lua_to_Fl_Input_Choice(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Menu_Item(__S__, __self__->menu());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Input_Choice::menu(const struct Fl_Menu_Item * m) */
int lua_call2_Fl_Input_Choice__menu(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Input_Choice * __self__;
     struct Fl_Menu_Item * m;
    
    __self__ = ( class Fl_Input_Choice * )lua_to_Fl_Input_Choice(__S__, 1, &__ERROR__);
    m = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->menu(m);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Input_Choice__menu(__S__);
}
/* void Fl_Menu_Window::show() */
int lua_call1_Fl_Menu_Window__show(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Menu_Window * __self__;
    
    __self__ = ( class Fl_Menu_Window * )lua_to_Fl_Menu_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->show();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Widget * & Fl_Group::_ddfdesign_kludge() */
/* SKIPPED (return type) */
/* int Fl::event_button() */
int lua_call1_Fl__event_button(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::event_button());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Buffer::undo(int * cp=0) */
int lua_call1_Fl_Text_Buffer__undo(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Buffer * __self__;
     int * cp;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (nparam <= 1) {
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, __self__->undo());
      return 1;
    } else {
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, __self__->undo(cp));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Buffer::highlight() */
int lua_call1_Fl_Text_Buffer__highlight(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Buffer * __self__;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->highlight());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Buffer::highlight(int start, int end) */
int lua_call2_Fl_Text_Buffer__highlight(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Text_Buffer * __self__;
     int start;
     int end;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    start = ( int )(int)lua_tonumber(__S__, 2);
    end = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->highlight(start, end);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Text_Buffer__highlight(__S__);
}
/* void Fl_Browser::replace(int a, const char * b) */
int lua_call1_Fl_Browser__replace(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Browser * __self__;
     int a;
     char * b;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    a = ( int )(int)lua_tonumber(__S__, 2);
    b = ( char * )(char  *)lua_tostring(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->replace(a, b);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_murgaLuaTimer::doWait(double ) */
int lua_call1_Fl_murgaLuaTimer__doWait(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_murgaLuaTimer * __self__;
     double __2__;
    
    __self__ = ( class Fl_murgaLuaTimer * )lua_to_Fl_murgaLuaTimer(__S__, 1, &__ERROR__);
    __2__ = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->doWait(__2__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Tooltip::enable(int b=1) */
int lua_call1_Fl_Tooltip__enable(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  {
     int b;
    
    
    /* Actual call */
    if (nparam <= 0) {
      Fl_Tooltip::enable();
    } else {
      b = ( int )(int)lua_tonumber(__S__, 1);
      Fl_Tooltip::enable(b);
    }
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Window::free_position() */
int lua_call1_Fl_Window__free_position(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Window * __self__;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->free_position();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser::move(int to, int from) */
int lua_call1_Fl_Browser__move(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Browser * __self__;
     int to;
     int from;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    to = ( int )(int)lua_tonumber(__S__, 2);
    from = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->move(to, from);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color Fl_File_Input::errorcolor()const  */
int lua_call1_Fl_File_Input__errorcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Input * __self__;
    
    __self__ = ( class Fl_File_Input * )lua_to_Fl_File_Input(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->errorcolor());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_File_Input::errorcolor(Fl_Color c) */
int lua_call2_Fl_File_Input__errorcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_File_Input * __self__;
     Fl_Color c;
    
    __self__ = ( class Fl_File_Input * )lua_to_Fl_File_Input(__S__, 1, &__ERROR__);
    c = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->errorcolor(c);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_File_Input__errorcolor(__S__);
}
/* int fl_draw_symbol(const char * label, int x, int y, int w, int h, Fl_Color ) */
int lua_call1_fl_draw_symbol(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 6) goto error;
  {
     char * label;
     int x;
     int y;
     int w;
     int h;
     Fl_Color __6__;
    
    label = ( char * )(char  *)lua_tostring(__S__, 1);
    x = ( int )(int)lua_tonumber(__S__, 2);
    y = ( int )(int)lua_tonumber(__S__, 3);
    w = ( int )(int)lua_tonumber(__S__, 4);
    h = ( int )(int)lua_tonumber(__S__, 5);
    __6__ = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 6);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_draw_symbol(label, x, y, w, h, __6__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Double_Window::hide() */
int lua_call1_Fl_Double_Window__hide(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Double_Window * __self__;
    
    __self__ = ( class Fl_Double_Window * )lua_to_Fl_Double_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->hide();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_line_style(int style, int width=0, char * dashes=0) */
int lua_call1_fl_line_style(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     int style;
     int width;
     char * dashes;
    
    style = ( int )(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    if (nparam <= 1) {
      fl_line_style(style);
    } else {
      width = ( int )(int)lua_tonumber(__S__, 2);
      if (nparam <= 2) {
        fl_line_style(style, width);
      } else {
        dashes = ( char * )(char  *)lua_tostring(__S__, 3);
        fl_line_style(style, width, dashes);
      }
    }
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::compose_reset() */
int lua_call1_Fl__compose_reset(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    Fl::compose_reset();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Display::redisplay_range(int start, int end) */
int lua_call1_Fl_Text_Display__redisplay_range(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Text_Display * __self__;
     int start;
     int end;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    start = ( int )(int)lua_tonumber(__S__, 2);
    end = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->redisplay_range(start, end);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Image * Fl_Image::copy() */
int lua_call1_Fl_Image__copy(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Image * __self__;
    
    __self__ = ( class Fl_Image * )lua_to_Fl_Image(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Image(__S__, __self__->copy());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Image * Fl_Image::copy(int W, int H) */
int lua_call2_Fl_Image__copy(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Image * __self__;
     int W;
     int H;
    
    __self__ = ( class Fl_Image * )lua_to_Fl_Image(__S__, 1, &__ERROR__);
    W = ( int )(int)lua_tonumber(__S__, 2);
    H = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Image(__S__, __self__->copy(W, H));
    return 1;
  }
  
error:
  return lua_call1_Fl_Image__copy(__S__);
}
/* void fl_push_matrix() */
int lua_call1_fl_push_matrix(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    fl_push_matrix();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::visible_focus() */
int lua_call1_Fl__visible_focus(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::visible_focus());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::visible_focus(int v) */
int lua_call2_Fl__visible_focus(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     int v;
    
    v = ( int )(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    Fl::visible_focus(v);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl__visible_focus(__S__);
}
/*  Fl_Single_Window::Fl_Single_Window(int W, int H, const char * l=0) */
int lua_call1_Fl_Single_Window__Fl_Single_Window(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int W;
     int H;
     char * l;
    
    W = ( int )(int)lua_tonumber(__S__, 1);
    H = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (nparam <= 2) {
      lua_settop(__S__, 0);
      lua_push_Fl_Single_Window(__S__, new Fl_Single_Window(W, H));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 3);
      lua_settop(__S__, 0);
      lua_push_Fl_Single_Window(__S__, new Fl_Single_Window(W, H, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Single_Window::Fl_Single_Window(int X, int Y, int W, int H, const char * l=0) */
int lua_call2_Fl_Single_Window__Fl_Single_Window(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     char * l;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Single_Window(__S__, new Fl_Single_Window(X, Y, W, H));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Single_Window(__S__, new Fl_Single_Window(X, Y, W, H, l));
      return 1;
    }
  }
  
error:
  return lua_call1_Fl_Single_Window__Fl_Single_Window(__S__);
}
/* int fl_old_shortcut(const char * ) */
int lua_call1_fl_old_shortcut(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * __1__;
    
    __1__ = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_old_shortcut(__1__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int fl_not_clipped(int x, int y, int w, int h) */
int lua_call1_fl_not_clipped(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_not_clipped(x, y, w, h));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color Fl_Widget::color()const  */
int lua_call1_Fl_Widget__color(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->color());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::color(unsigned int a) */
int lua_call2_Fl_Widget__color(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Widget * __self__;
     unsigned int a;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    a = ( unsigned int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->color(a);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Widget__color(__S__);
}
/* void Fl_Widget::color(unsigned int a, unsigned int b) */
int lua_call3_Fl_Widget__color(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Widget * __self__;
     unsigned int a;
     unsigned int b;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    a = ( unsigned int )(int)lua_tonumber(__S__, 2);
    b = ( unsigned int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->color(a, b);
    ;
    return 0;
  }
  
error:
  return lua_call2_Fl_Widget__color(__S__);
}
/* uchar Fl_Spinner::type()const  */
int lua_call1_Fl_Spinner__type(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Spinner * __self__;
    
    __self__ = ( class Fl_Spinner * )lua_to_Fl_Spinner(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->type());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Spinner::type(uchar v) */
int lua_call2_Fl_Spinner__type(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Spinner * __self__;
     unsigned char v;
    
    __self__ = ( class Fl_Spinner * )lua_to_Fl_Spinner(__S__, 1, &__ERROR__);
    v = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->type(v);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Spinner__type(__S__);
}
/*  Fl_Group::Fl_Group(int , int , int , int , const char * =0) */
int lua_call1_Fl_Group__Fl_Group(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int __1__;
     int __2__;
     int __3__;
     int __4__;
     char * __5__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Group(__S__, new Fl_Group(__1__, __2__, __3__, __4__));
      return 1;
    } else {
      __5__ = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Group(__S__, new Fl_Group(__1__, __2__, __3__, __4__, __5__));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* char Fl_Browser::column_char()const  */
int lua_call1_Fl_Browser__column_char(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Browser * __self__;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->column_char());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser::column_char(char c) */
int lua_call2_Fl_Browser__column_char(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Browser * __self__;
     char c;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    c = ( char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->column_char(c);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Browser__column_char(__S__);
}
/* const char * Fl_Window::iconlabel()const  */
int lua_call1_Fl_Window__iconlabel(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Window * __self__;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->iconlabel());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Window::iconlabel(const char * ) */
int lua_call2_Fl_Window__iconlabel(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Window * __self__;
     char * __2__;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    __2__ = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->iconlabel(__2__);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Window__iconlabel(__S__);
}
/* int Fl::event_key() */
int lua_call1_Fl__event_key(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::event_key());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::event_key(int ) */
int lua_call2_Fl__event_key(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     int __1__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::event_key(__1__));
    return 1;
  }
  
error:
  return lua_call1_Fl__event_key(__S__);
}
/* void Fl_Input::draw() */
int lua_call1_Fl_Input__draw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Input * __self__;
    
    __self__ = ( class Fl_Input * )lua_to_Fl_Input(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->draw();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* char * Fl_Text_Buffer::text_range(int start, int end) */
int lua_call1_Fl_Text_Buffer__text_range(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Text_Buffer * __self__;
     int start;
     int end;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    start = ( int )(int)lua_tonumber(__S__, 2);
    end = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->text_range(start, end));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_Item::deactivate() */
int lua_call1_Fl_Menu_Item__deactivate(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->deactivate();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Image::d()const  */
int lua_call1_Fl_Image__d(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Image * __self__;
    
    __self__ = ( class Fl_Image * )lua_to_Fl_Image(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->d());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Buffer::loadfile(const char * file, int buflen=128 * 1024) */
int lua_call1_Fl_Text_Buffer__loadfile(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Buffer * __self__;
     char * file;
     int buflen;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    file = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (nparam <= 2) {
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, __self__->loadfile(file));
      return 1;
    } else {
      buflen = ( int )(int)lua_tonumber(__S__, 3);
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, __self__->loadfile(file, buflen));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Input_::input_type()const  */
int lua_call1_Fl_Input___input_type(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Input_ * __self__;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->input_type());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Input_::input_type(int t) */
int lua_call2_Fl_Input___input_type(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Input_ * __self__;
     int t;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    t = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->input_type(t);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Input___input_type(__S__);
}
/* int Fl_File_Chooser::preview()const  */
int lua_call1_Fl_File_Chooser__preview(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Chooser * __self__;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->preview());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_File_Chooser::preview(int e) */
int lua_call2_Fl_File_Chooser__preview(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_File_Chooser * __self__;
     int e;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    e = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->preview(e);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_File_Chooser__preview(__S__);
}
/* const int * Fl_Browser::column_widths()const  */
/* SKIPPED (return type) */
/* void Fl_Browser::column_widths(const int * l) */
/* SKIPPED (argument #2) */
/* int Fl_Check_Browser::nchecked()const  */
int lua_call1_Fl_Check_Browser__nchecked(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Check_Browser * __self__;
    
    __self__ = ( class Fl_Check_Browser * )lua_to_Fl_Check_Browser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->nchecked());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_draw_image_mono(Fl_Draw_Image_Cb , void * , int , int , int , int , int delta=1) */
/* SKIPPED (argument #1) */
/* void fl_draw_image_mono(const uchar * , int , int , int , int , int delta=1, int ld=0) */
int lua_call2_fl_draw_image_mono(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 5) goto error;
  {
     unsigned char * __1__;
     int __2__;
     int __3__;
     int __4__;
     int __5__;
     int delta;
     int ld;
    
    __1__ = ( unsigned char * )(char  *)lua_tostring(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    __5__ = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (nparam <= 5) {
      fl_draw_image_mono(__1__, __2__, __3__, __4__, __5__);
    } else {
      delta = ( int )(int)lua_tonumber(__S__, 6);
      if (nparam <= 6) {
        fl_draw_image_mono(__1__, __2__, __3__, __4__, __5__, delta);
      } else {
        ld = ( int )(int)lua_tonumber(__S__, 7);
        fl_draw_image_mono(__1__, __2__, __3__, __4__, __5__, delta, ld);
      }
    }
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Window::override()const  */
int lua_call1_Fl_Window__override(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Window * __self__;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->override());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Help_Dialog::load(const char * f) */
int lua_call1_Fl_Help_Dialog__load(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Help_Dialog * __self__;
     char * f;
    
    __self__ = ( class Fl_Help_Dialog * )lua_to_Fl_Help_Dialog(__S__, 1, &__ERROR__);
    f = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->load(f);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_translate(double x, double y) */
int lua_call1_fl_translate(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     double x;
     double y;
    
    x = ( double )(double)lua_tonumber(__S__, 1);
    y = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    fl_translate(x, y);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* uchar Fl_Menu_Item::labelsize()const  */
int lua_call1_Fl_Menu_Item__labelsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->labelsize());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_Item::labelsize(uchar a) */
int lua_call2_Fl_Menu_Item__labelsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     struct Fl_Menu_Item * __self__;
     unsigned char a;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    a = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->labelsize(a);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Menu_Item__labelsize(__S__);
}
/* class Fl_Window * Fl_Window::current() */
int lua_call1_Fl_Window__current(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_Window(__S__, Fl_Window::current());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::remove_timeout(Fl_Timeout_Handler , void * =0) */
/* SKIPPED (argument #1) */
/* int Fl_Text_Display::count_lines(int start, int end, bool start_pos_is_line_start) */
int lua_call1_Fl_Text_Display__count_lines(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 4) goto error;
  {
     class Fl_Text_Display * __self__;
     int start;
     int end;
     bool start_pos_is_line_start;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    start = ( int )(int)lua_tonumber(__S__, 2);
    end = ( int )(int)lua_tonumber(__S__, 3);
    start_pos_is_line_start = ( bool )(bool)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->count_lines(start, end, start_pos_is_line_start));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Widget::x()const  */
int lua_call1_Fl_Widget__x(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->x());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Buffer::secondary_selection_position(int * start, int * end) */
/* SKIPPED (argument #2) */
/* int Fl_Text_Buffer::secondary_selection_position(int * start, int * end, int * isRect, int * rectStart, int * rectEnd) */
/* SKIPPED (argument #2) */
/* class Fl_Text_Selection * Fl_Text_Buffer::primary_selection() */
int lua_call1_Fl_Text_Buffer__primary_selection(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Buffer * __self__;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Text_Selection(__S__, __self__->primary_selection());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Slider::scrollvalue(int windowtop, int windowsize, int first, int totalsize) */
int lua_call1_Fl_Slider__scrollvalue(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Slider * __self__;
     int windowtop;
     int windowsize;
     int first;
     int totalsize;
    
    __self__ = ( class Fl_Slider * )lua_to_Fl_Slider(__S__, 1, &__ERROR__);
    windowtop = ( int )(int)lua_tonumber(__S__, 2);
    windowsize = ( int )(int)lua_tonumber(__S__, 3);
    first = ( int )(int)lua_tonumber(__S__, 4);
    totalsize = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->scrollvalue(windowtop, windowsize, first, totalsize));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Display::handle(int e) */
int lua_call1_Fl_Text_Display__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Display * __self__;
     int e;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    e = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(e));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Select_Browser::Fl_Select_Browser(int X, int Y, int W, int H, const char * l=0) */
int lua_call1_Fl_Select_Browser__Fl_Select_Browser(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     char * l;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Select_Browser(__S__, new Fl_Select_Browser(X, Y, W, H));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Select_Browser(__S__, new Fl_Select_Browser(X, Y, W, H, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_File_Icon * Fl_File_Icon::next() */
int lua_call1_Fl_File_Icon__next(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Icon * __self__;
    
    __self__ = ( class Fl_File_Icon * )lua_to_Fl_File_Icon(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_File_Icon(__S__, __self__->next());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Text_Editor::Key_Func Fl_Text_Editor::bound_key_function(int key, int state) */
/* SKIPPED (return type) */
/* Fl_Text_Editor::Key_Func Fl_Text_Editor::bound_key_function(int key, int state, struct Fl_Text_Editor::Key_Binding * list) */
/* SKIPPED (return type) */
/* void Fl_Window::hide() */
int lua_call1_Fl_Window__hide(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Window * __self__;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->hide();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Menu_Item::activevisible()const  */
int lua_call1_Fl_Menu_Item__activevisible(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->activevisible());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Tiled_Image::Fl_Tiled_Image(class Fl_Image * i, int W=0, int H=0) */
int lua_call1_Fl_Tiled_Image__Fl_Tiled_Image(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     class Fl_Image * i;
     int W;
     int H;
    
    i = ( class Fl_Image * )lua_to_Fl_Image(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (nparam <= 1) {
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_push_Fl_Tiled_Image(__S__, new Fl_Tiled_Image(i));
      return 1;
    } else {
      W = ( int )(int)lua_tonumber(__S__, 2);
      if (nparam <= 2) {
        if (__ERROR__) goto error;
        
        lua_settop(__S__, 0);
        lua_push_Fl_Tiled_Image(__S__, new Fl_Tiled_Image(i, W));
        return 1;
      } else {
        H = ( int )(int)lua_tonumber(__S__, 3);
        if (__ERROR__) goto error;
        
        lua_settop(__S__, 0);
        lua_push_Fl_Tiled_Image(__S__, new Fl_Tiled_Image(i, W, H));
        return 1;
      }
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Spinner::range(double a, double b) */
int lua_call1_Fl_Spinner__range(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Spinner * __self__;
     double a;
     double b;
    
    __self__ = ( class Fl_Spinner * )lua_to_Fl_Spinner(__S__, 1, &__ERROR__);
    a = ( double )(double)lua_tonumber(__S__, 2);
    b = ( double )(double)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->range(a, b);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_pop_matrix() */
int lua_call1_fl_pop_matrix(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    fl_pop_matrix();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Help_Dialog::x() */
int lua_call1_Fl_Help_Dialog__x(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Help_Dialog * __self__;
    
    __self__ = ( class Fl_Help_Dialog * )lua_to_Fl_Help_Dialog(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->x());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Window::set_non_modal() */
int lua_call1_Fl_Window__set_non_modal(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Window * __self__;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->set_non_modal();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Group::resize(int , int , int , int ) */
int lua_call1_Fl_Group__resize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Group * __self__;
     int __2__;
     int __3__;
     int __4__;
     int __5__;
    
    __self__ = ( class Fl_Group * )lua_to_Fl_Group(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    __5__ = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->resize(__2__, __3__, __4__, __5__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Buffer::secondary_select(int start, int end) */
int lua_call1_Fl_Text_Buffer__secondary_select(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Text_Buffer * __self__;
     int start;
     int end;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    start = ( int )(int)lua_tonumber(__S__, 2);
    end = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->secondary_select(start, end);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Font Fl_Value_Slider::textfont()const  */
int lua_call1_Fl_Value_Slider__textfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Value_Slider * __self__;
    
    __self__ = ( class Fl_Value_Slider * )lua_to_Fl_Value_Slider(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textfont());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Value_Slider::textfont(uchar s) */
int lua_call2_Fl_Value_Slider__textfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Value_Slider * __self__;
     unsigned char s;
    
    __self__ = ( class Fl_Value_Slider * )lua_to_Fl_Value_Slider(__S__, 1, &__ERROR__);
    s = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textfont(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Value_Slider__textfont(__S__);
}
/* const char * fl_filename_ext(const char * ) */
int lua_call1_fl_filename_ext(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * __1__;
    
    __1__ = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) fl_filename_ext(__1__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* struct Fl_Menu_Item * Fl_Menu_Item::next(int i=1) */
int lua_call1_Fl_Menu_Item__next(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
     int i;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (nparam <= 1) {
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_push_Fl_Menu_Item(__S__, __self__->next());
      return 1;
    } else {
      i = ( int )(int)lua_tonumber(__S__, 2);
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_push_Fl_Menu_Item(__S__, __self__->next(i));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_Item::hide() */
int lua_call1_Fl_Menu_Item__hide(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->hide();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Repeat_Button::Fl_Repeat_Button(int X, int Y, int W, int H, const char * l=0) */
int lua_call1_Fl_Repeat_Button__Fl_Repeat_Button(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     char * l;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Repeat_Button(__S__, new Fl_Repeat_Button(X, Y, W, H));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Repeat_Button(__S__, new Fl_Repeat_Button(X, Y, W, H, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Browser::size()const  */
int lua_call1_Fl_Browser__size(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Browser * __self__;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->size());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser::size(int W, int H) */
int lua_call2_Fl_Browser__size(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Browser * __self__;
     int W;
     int H;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    W = ( int )(int)lua_tonumber(__S__, 2);
    H = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->size(W, H);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Browser__size(__S__);
}
/* int Fl_Group::find(const class Fl_Widget & o)const  */
int lua_call1_Fl_Group__find(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Group * __self__;
    
    __self__ = ( class Fl_Group * )lua_to_Fl_Group(__S__, 1, &__ERROR__);
     class Fl_Widget & o = ( class Fl_Widget & )(*lua_to_Fl_Widget(__S__, 2, &__ERROR__));
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->find(o));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Group::find(const class Fl_Widget * )const  */
int lua_call2_Fl_Group__find(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Group * __self__;
     class Fl_Widget * __2__;
    
    __self__ = ( class Fl_Group * )lua_to_Fl_Group(__S__, 1, &__ERROR__);
    __2__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->find(__2__));
    return 1;
  }
  
error:
  return lua_call1_Fl_Group__find(__S__);
}
/* const char * Fl_Preferences::group(int ) */
int lua_call1_Fl_Preferences__group(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Preferences * __self__;
     int __2__;
    
    __self__ = ( class Fl_Preferences * )lua_to_Fl_Preferences(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->group(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_File_Input::draw() */
int lua_call1_Fl_File_Input__draw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Input * __self__;
    
    __self__ = ( class Fl_File_Input * )lua_to_Fl_File_Input(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->draw();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color fl_show_colormap(Fl_Color oldcol) */
int lua_call1_fl_show_colormap(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     Fl_Color oldcol;
    
    oldcol = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_show_colormap(oldcol));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_RGB_Image::uncache() */
int lua_call1_Fl_RGB_Image__uncache(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_RGB_Image * __self__;
    
    __self__ = ( class Fl_RGB_Image * )lua_to_Fl_RGB_Image(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->uncache();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* uchar Fl_Menu_::textsize()const  */
int lua_call1_Fl_Menu___textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Menu_ * __self__;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textsize());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_::textsize(uchar c) */
int lua_call2_Fl_Menu___textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Menu_ * __self__;
     unsigned char c;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    c = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textsize(c);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Menu___textsize(__S__);
}
/* int Fl_Value_Slider::handle(int ) */
int lua_call1_Fl_Value_Slider__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Value_Slider * __self__;
     int __2__;
    
    __self__ = ( class Fl_Value_Slider * )lua_to_Fl_Value_Slider(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Display::highlight_data(class Fl_Text_Buffer * styleBuffer, const struct Fl_Text_Display::Style_Table_Entry * styleTable, int nStyles, char unfinishedStyle, Fl_Text_Display::Unfinished_Style_Cb unfinishedHighlightCB, void * cbArg) */
/* SKIPPED (argument #6) */
/* int Fl_Browser::visible(int n)const  */
int lua_call1_Fl_Browser__visible(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Browser * __self__;
     int n;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    n = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->visible(n));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* double Fl_Positioner::ymaximum()const  */
int lua_call1_Fl_Positioner__ymaximum(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Positioner * __self__;
    
    __self__ = ( class Fl_Positioner * )lua_to_Fl_Positioner(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->ymaximum());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Positioner::ymaximum(double a) */
int lua_call2_Fl_Positioner__ymaximum(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Positioner * __self__;
     double a;
    
    __self__ = ( class Fl_Positioner * )lua_to_Fl_Positioner(__S__, 1, &__ERROR__);
    a = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->ymaximum(a);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Positioner__ymaximum(__S__);
}
/*  Fl_Radio_Button::Fl_Radio_Button(int x, int y, int w, int h, const char * l=0) */
int lua_call1_Fl_Radio_Button__Fl_Radio_Button(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Radio_Button(__S__, new Fl_Radio_Button(x, y, w, h));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Radio_Button(__S__, new Fl_Radio_Button(x, y, w, h, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* double Fl_Positioner::yvalue()const  */
int lua_call1_Fl_Positioner__yvalue(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Positioner * __self__;
    
    __self__ = ( class Fl_Positioner * )lua_to_Fl_Positioner(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->yvalue());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Positioner::yvalue(double ) */
int lua_call2_Fl_Positioner__yvalue(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Positioner * __self__;
     double __2__;
    
    __self__ = ( class Fl_Positioner * )lua_to_Fl_Positioner(__S__, 1, &__ERROR__);
    __2__ = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->yvalue(__2__));
    return 1;
  }
  
error:
  return lua_call1_Fl_Positioner__yvalue(__S__);
}
/* int Fl_Input_::readonly()const  */
int lua_call1_Fl_Input___readonly(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Input_ * __self__;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->readonly());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Input_::readonly(int b) */
int lua_call2_Fl_Input___readonly(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Input_ * __self__;
     int b;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    b = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->readonly(b);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Input___readonly(__S__);
}
/* Fl_Color Fl_Tooltip::textcolor() */
int lua_call1_Fl_Tooltip__textcolor(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Tooltip::textcolor());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Tooltip::textcolor(unsigned int c) */
int lua_call2_Fl_Tooltip__textcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     unsigned int c;
    
    c = ( unsigned int )(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    Fl_Tooltip::textcolor(c);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Tooltip__textcolor(__S__);
}
/* int Fl_Browser::select(int , int =1) */
int lua_call1_Fl_Browser__select(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Browser * __self__;
     int __2__;
     int __3__;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (nparam <= 2) {
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, __self__->select(__2__));
      return 1;
    } else {
      __3__ = ( int )(int)lua_tonumber(__S__, 3);
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, __self__->select(__2__, __3__));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_copy_offscreen_with_alpha(int x, int y, int w, int h, HBITMAP pixmap, int srcx, int srcy) */
/* SKIPPED (argument #5) */
/* void fl_mult_matrix(double a, double b, double c, double d, double x, double y) */
int lua_call1_fl_mult_matrix(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 6) goto error;
  {
     double a;
     double b;
     double c;
     double d;
     double x;
     double y;
    
    a = ( double )(double)lua_tonumber(__S__, 1);
    b = ( double )(double)lua_tonumber(__S__, 2);
    c = ( double )(double)lua_tonumber(__S__, 3);
    d = ( double )(double)lua_tonumber(__S__, 4);
    x = ( double )(double)lua_tonumber(__S__, 5);
    y = ( double )(double)lua_tonumber(__S__, 6);
    
    /* Actual call */
    fl_mult_matrix(a, b, c, d, x, y);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Image::w()const  */
int lua_call1_Fl_Image__w(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Image * __self__;
    
    __self__ = ( class Fl_Image * )lua_to_Fl_Image(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->w());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser::bottomline(int l) */
int lua_call1_Fl_Browser__bottomline(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Browser * __self__;
     int l;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    l = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->bottomline(l);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color Fl_Browser_::textcolor()const  */
int lua_call1_Fl_Browser___textcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Browser_ * __self__;
    
    __self__ = ( class Fl_Browser_ * )lua_to_Fl_Browser_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textcolor());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser_::textcolor(unsigned int n) */
int lua_call2_Fl_Browser___textcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Browser_ * __self__;
     unsigned int n;
    
    __self__ = ( class Fl_Browser_ * )lua_to_Fl_Browser_(__S__, 1, &__ERROR__);
    n = ( unsigned int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textcolor(n);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Browser___textcolor(__S__);
}
/* void Fl_Text_Buffer::call_modify_callbacks() */
int lua_call1_Fl_Text_Buffer__call_modify_callbacks(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Buffer * __self__;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->call_modify_callbacks();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Buffer::unselect() */
int lua_call1_Fl_Text_Buffer__unselect(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Buffer * __self__;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->unselect();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Widget * Fl_Tooltip::current() */
int lua_call1_Fl_Tooltip__current(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_Widget(__S__, Fl_Tooltip::current());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Tooltip::current(class Fl_Widget * ) */
int lua_call2_Fl_Tooltip__current(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __1__;
    
    __1__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    Fl_Tooltip::current(__1__);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Tooltip__current(__S__);
}
/* int Fl_Check_Browser::nitems()const  */
int lua_call1_Fl_Check_Browser__nitems(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Check_Browser * __self__;
    
    __self__ = ( class Fl_Check_Browser * )lua_to_Fl_Check_Browser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->nitems());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Widget::active()const  */
int lua_call1_Fl_Widget__active(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->active());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::background(uchar , uchar , uchar ) */
int lua_call1_Fl__background(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 3) goto error;
  {
     unsigned char __1__;
     unsigned char __2__;
     unsigned char __3__;
    
    __1__ = ( unsigned char )(char)lua_tonumber(__S__, 1);
    __2__ = ( unsigned char )(char)lua_tonumber(__S__, 2);
    __3__ = ( unsigned char )(char)lua_tonumber(__S__, 3);
    
    /* Actual call */
    Fl::background(__1__, __2__, __3__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Check_Browser::check_none() */
int lua_call1_Fl_Check_Browser__check_none(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Check_Browser * __self__;
    
    __self__ = ( class Fl_Check_Browser * )lua_to_Fl_Check_Browser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->check_none();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Window::Fl_Window(int , int , const char * =0) */
int lua_call1_Fl_Window__Fl_Window(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int __1__;
     int __2__;
     char * __3__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (nparam <= 2) {
      lua_settop(__S__, 0);
      lua_push_Fl_Window(__S__, new Fl_Window(__1__, __2__));
      return 1;
    } else {
      __3__ = ( char * )(char  *)lua_tostring(__S__, 3);
      lua_settop(__S__, 0);
      lua_push_Fl_Window(__S__, new Fl_Window(__1__, __2__, __3__));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Window::Fl_Window(int , int , int , int , const char * =0) */
int lua_call2_Fl_Window__Fl_Window(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int __1__;
     int __2__;
     int __3__;
     int __4__;
     char * __5__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Window(__S__, new Fl_Window(__1__, __2__, __3__, __4__));
      return 1;
    } else {
      __5__ = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Window(__S__, new Fl_Window(__1__, __2__, __3__, __4__, __5__));
      return 1;
    }
  }
  
error:
  return lua_call1_Fl_Window__Fl_Window(__S__);
}
/* int Fl_Menu_::size()const  */
int lua_call1_Fl_Menu___size(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Menu_ * __self__;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->size());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_::size(int W, int H) */
int lua_call2_Fl_Menu___size(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Menu_ * __self__;
     int W;
     int H;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    W = ( int )(int)lua_tonumber(__S__, 2);
    H = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->size(W, H);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Menu___size(__S__);
}
/* void Fl_Text_Buffer::secondary_select_rectangular(int start, int end, int rectStart, int rectEnd) */
int lua_call1_Fl_Text_Buffer__secondary_select_rectangular(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Text_Buffer * __self__;
     int start;
     int end;
     int rectStart;
     int rectEnd;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    start = ( int )(int)lua_tonumber(__S__, 2);
    end = ( int )(int)lua_tonumber(__S__, 3);
    rectStart = ( int )(int)lua_tonumber(__S__, 4);
    rectEnd = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->secondary_select_rectangular(start, end, rectStart, rectEnd);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_xyline(int x, int y, int x1) */
int lua_call1_fl_xyline(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 3) goto error;
  {
     int x;
     int y;
     int x1;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    x1 = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    fl_xyline(x, y, x1);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_xyline(int x, int y, int x1, int y2) */
int lua_call2_fl_xyline(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int x1;
     int y2;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    x1 = ( int )(int)lua_tonumber(__S__, 3);
    y2 = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    fl_xyline(x, y, x1, y2);
    ;
    return 0;
  }
  
error:
  return lua_call1_fl_xyline(__S__);
}
/* void fl_xyline(int x, int y, int x1, int y2, int x3) */
int lua_call3_fl_xyline(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 5) goto error;
  {
     int x;
     int y;
     int x1;
     int y2;
     int x3;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    x1 = ( int )(int)lua_tonumber(__S__, 3);
    y2 = ( int )(int)lua_tonumber(__S__, 4);
    x3 = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    fl_xyline(x, y, x1, y2, x3);
    ;
    return 0;
  }
  
error:
  return lua_call2_fl_xyline(__S__);
}
/* int Fl_Text_Display::move_down() */
int lua_call1_Fl_Text_Display__move_down(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Display * __self__;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->move_down());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color Fl_Value_Input::textcolor()const  */
int lua_call1_Fl_Value_Input__textcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Value_Input * __self__;
    
    __self__ = ( class Fl_Value_Input * )lua_to_Fl_Value_Input(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textcolor());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Value_Input::textcolor(unsigned int n) */
int lua_call2_Fl_Value_Input__textcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Value_Input * __self__;
     unsigned int n;
    
    __self__ = ( class Fl_Value_Input * )lua_to_Fl_Value_Input(__S__, 1, &__ERROR__);
    n = ( unsigned int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textcolor(n);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Value_Input__textcolor(__S__);
}
/* char * fl_file_chooser(const char * message, const char * pat, const char * fname, int relative=0) */
int lua_call1_fl_file_chooser(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 3) goto error;
  {
     char * message;
     char * pat;
     char * fname;
     int relative;
    
    message = ( char * )(char  *)lua_tostring(__S__, 1);
    pat = ( char * )(char  *)lua_tostring(__S__, 2);
    fname = ( char * )(char  *)lua_tostring(__S__, 3);
    
    /* Actual call */
    if (nparam <= 3) {
      lua_settop(__S__, 0);
      lua_pushstring(__S__, (const char * ) fl_file_chooser(message, pat, fname));
      return 1;
    } else {
      relative = ( int )(int)lua_tonumber(__S__, 4);
      lua_settop(__S__, 0);
      lua_pushstring(__S__, (const char * ) fl_file_chooser(message, pat, fname, relative));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::set_abort(void ( * f)(const char * , ...)) */
/* SKIPPED (argument #1) */
/* HDC fl_makeDC(HBITMAP ) */
/* SKIPPED (return type) */
/*  Fl_Hor_Nice_Slider::Fl_Hor_Nice_Slider(int x, int y, int w, int h, const char * l=0) */
int lua_call1_Fl_Hor_Nice_Slider__Fl_Hor_Nice_Slider(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Hor_Nice_Slider(__S__, new Fl_Hor_Nice_Slider(x, y, w, h));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Hor_Nice_Slider(__S__, new Fl_Hor_Nice_Slider(x, y, w, h, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Editor::kf_backspace(int c, class Fl_Text_Editor * e) */
int lua_call1_Fl_Text_Editor__kf_backspace(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int c;
     class Fl_Text_Editor * e;
    
    c = ( int )(int)lua_tonumber(__S__, 1);
    e = ( class Fl_Text_Editor * )lua_to_Fl_Text_Editor(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Text_Editor::kf_backspace(c, e));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::remove_check(Fl_Timeout_Handler , void * =0) */
/* SKIPPED (argument #1) */
/* class Fl_Image * Fl_Pixmap::copy() */
int lua_call1_Fl_Pixmap__copy(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Pixmap * __self__;
    
    __self__ = ( class Fl_Pixmap * )lua_to_Fl_Pixmap(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Image(__S__, __self__->copy());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Image * Fl_Pixmap::copy(int W, int H) */
int lua_call2_Fl_Pixmap__copy(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Pixmap * __self__;
     int W;
     int H;
    
    __self__ = ( class Fl_Pixmap * )lua_to_Fl_Pixmap(__S__, 1, &__ERROR__);
    W = ( int )(int)lua_tonumber(__S__, 2);
    H = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Image(__S__, __self__->copy(W, H));
    return 1;
  }
  
error:
  return lua_call1_Fl_Pixmap__copy(__S__);
}
/* int Fl::run() */
int lua_call1_Fl__run(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::run());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* uchar Fl_Counter::textsize()const  */
int lua_call1_Fl_Counter__textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Counter * __self__;
    
    __self__ = ( class Fl_Counter * )lua_to_Fl_Counter(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textsize());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Counter::textsize(uchar s) */
int lua_call2_Fl_Counter__textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Counter * __self__;
     unsigned char s;
    
    __self__ = ( class Fl_Counter * )lua_to_Fl_Counter(__S__, 1, &__ERROR__);
    s = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textsize(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Counter__textsize(__S__);
}
/* int Fl_File_Chooser::shown() */
int lua_call1_Fl_File_Chooser__shown(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Chooser * __self__;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->shown());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Counter::handle(int ) */
int lua_call1_Fl_Counter__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Counter * __self__;
     int __2__;
    
    __self__ = ( class Fl_Counter * )lua_to_Fl_Counter(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Menu_::mode(int i)const  */
int lua_call1_Fl_Menu___mode(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Menu_ * __self__;
     int i;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    i = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->mode(i));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_::mode(int i, int fl) */
int lua_call2_Fl_Menu___mode(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Menu_ * __self__;
     int i;
     int fl;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    i = ( int )(int)lua_tonumber(__S__, 2);
    fl = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->mode(i, fl);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Menu___mode(__S__);
}
/* int Fl_Text_Buffer::findchar_backward(int startPos, char searchChar, int * foundPos) */
/* SKIPPED (argument #4) */
/* int Fl_Text_Display::wrapped_row(int row) */
int lua_call1_Fl_Text_Display__wrapped_row(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Display * __self__;
     int row;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    row = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->wrapped_row(row));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Input_Choice::add(const char * s) */
int lua_call1_Fl_Input_Choice__add(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Input_Choice * __self__;
     char * s;
    
    __self__ = ( class Fl_Input_Choice * )lua_to_Fl_Input_Choice(__S__, 1, &__ERROR__);
    s = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->add(s);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Clock::handle(int ) */
int lua_call1_Fl_Clock__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Clock * __self__;
     int __2__;
    
    __self__ = ( class Fl_Clock * )lua_to_Fl_Clock(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Input_Choice::clear() */
int lua_call1_Fl_Input_Choice__clear(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Input_Choice * __self__;
    
    __self__ = ( class Fl_Input_Choice * )lua_to_Fl_Input_Choice(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->clear();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::own_colormap() */
int lua_call1_Fl__own_colormap(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    Fl::own_colormap();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Button::setonly() */
int lua_call1_Fl_Button__setonly(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Button * __self__;
    
    __self__ = ( class Fl_Button * )lua_to_Fl_Button(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->setonly();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color Fl_Help_View::textcolor()const  */
int lua_call1_Fl_Help_View__textcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Help_View * __self__;
    
    __self__ = ( class Fl_Help_View * )lua_to_Fl_Help_View(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textcolor());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Help_View::textcolor(Fl_Color c) */
int lua_call2_Fl_Help_View__textcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Help_View * __self__;
     Fl_Color c;
    
    __self__ = ( class Fl_Help_View * )lua_to_Fl_Help_View(__S__, 1, &__ERROR__);
    c = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textcolor(c);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Help_View__textcolor(__S__);
}
/* class Fl_Widget * Fl_Tabs::which(int event_x, int event_y) */
int lua_call1_Fl_Tabs__which(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Tabs * __self__;
     int event_x;
     int event_y;
    
    __self__ = ( class Fl_Tabs * )lua_to_Fl_Tabs(__S__, 1, &__ERROR__);
    event_x = ( int )(int)lua_tonumber(__S__, 2);
    event_y = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Widget(__S__, __self__->which(event_x, event_y));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Callback_p Fl_Widget::callback()const  */
/* SKIPPED (return type) */
/* void Fl_Widget::callback(Fl_Callback * c) */
/* SKIPPED (argument #2) */
/* void Fl_Widget::callback(Fl_Callback0 * c) */
/* SKIPPED (argument #2) */
/* void Fl_Widget::callback(Fl_Callback * c, void * p) */
/* SKIPPED (argument #2) */
/* void Fl_Widget::callback(Fl_Callback1 * c, long p=0) */
/* SKIPPED (argument #2) */
/*  Fl_Line_Dial::Fl_Line_Dial(int x, int y, int w, int h, const char * l=0) */
int lua_call1_Fl_Line_Dial__Fl_Line_Dial(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Line_Dial(__S__, new Fl_Line_Dial(x, y, w, h));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Line_Dial(__S__, new Fl_Line_Dial(x, y, w, h, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Buffer::remove_modify_callback(Fl_Text_Modify_Cb bufModifiedCB, void * cbArg) */
/* SKIPPED (argument #2) */
/*  Fl_PNG_Image::Fl_PNG_Image(const char * filename) */
int lua_call1_Fl_PNG_Image__Fl_PNG_Image(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * filename;
    
    filename = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_PNG_Image(__S__, new Fl_PNG_Image(filename));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Wizard::next() */
int lua_call1_Fl_Wizard__next(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Wizard * __self__;
    
    __self__ = ( class Fl_Wizard * )lua_to_Fl_Wizard(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->next();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Value_Output::draw() */
int lua_call1_Fl_Value_Output__draw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Value_Output * __self__;
    
    __self__ = ( class Fl_Value_Output * )lua_to_Fl_Value_Output(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->draw();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::remove_fd(int ) */
int lua_call1_Fl__remove_fd(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     int __1__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    Fl::remove_fd(__1__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::remove_fd(int , int when) */
int lua_call2_Fl__remove_fd(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int __1__;
     int when;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    when = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    Fl::remove_fd(__1__, when);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl__remove_fd(__S__);
}
/* double Fl_Color_Chooser::b()const  */
int lua_call1_Fl_Color_Chooser__b(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Color_Chooser * __self__;
    
    __self__ = ( class Fl_Color_Chooser * )lua_to_Fl_Color_Chooser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->b());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::event_inside(const class Fl_Widget * ) */
int lua_call1_Fl__event_inside(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __1__;
    
    __1__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::event_inside(__1__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::event_inside(int , int , int , int ) */
int lua_call2_Fl__event_inside(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int __1__;
     int __2__;
     int __3__;
     int __4__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::event_inside(__1__, __2__, __3__, __4__));
    return 1;
  }
  
error:
  return lua_call1_Fl__event_inside(__S__);
}
/*  Fl_Menu_Button::Fl_Menu_Button(int , int , int , int , const char * =0) */
int lua_call1_Fl_Menu_Button__Fl_Menu_Button(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int __1__;
     int __2__;
     int __3__;
     int __4__;
     char * __5__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Menu_Button(__S__, new Fl_Menu_Button(__1__, __2__, __3__, __4__));
      return 1;
    } else {
      __5__ = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Menu_Button(__S__, new Fl_Menu_Button(__1__, __2__, __3__, __4__, __5__));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int fl_clip_box(int , int , int , int , int & x, int & y, int & w, int & h) */
int lua_call1_fl_clip_box(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 8) goto error;
  {
     int __1__;
     int __2__;
     int __3__;
     int __4__;
     int x;
     int y;
     int w;
     int h;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    x = ( int )(int)lua_tonumber(__S__, 5);
    y = ( int )(int)lua_tonumber(__S__, 6);
    w = ( int )(int)lua_tonumber(__S__, 7);
    h = ( int )(int)lua_tonumber(__S__, 8);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_clip_box(__1__, __2__, __3__, __4__, x, y, w, h));
    lua_pushnumber(__S__, x);
    lua_pushnumber(__S__, y);
    lua_pushnumber(__S__, w);
    lua_pushnumber(__S__, h);
    return 5;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::event_dy() */
int lua_call1_Fl__event_dy(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::event_dy());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color Fl_Value_Output::textcolor()const  */
int lua_call1_Fl_Value_Output__textcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Value_Output * __self__;
    
    __self__ = ( class Fl_Value_Output * )lua_to_Fl_Value_Output(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textcolor());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Value_Output::textcolor(unsigned int s) */
int lua_call2_Fl_Value_Output__textcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Value_Output * __self__;
     unsigned int s;
    
    __self__ = ( class Fl_Value_Output * )lua_to_Fl_Value_Output(__S__, 1, &__ERROR__);
    s = ( unsigned int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textcolor(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Value_Output__textcolor(__S__);
}
/* void Fl_Text_Display::scroll(int topLineNum, int horizOffset) */
int lua_call1_Fl_Text_Display__scroll(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Text_Display * __self__;
     int topLineNum;
     int horizOffset;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    topLineNum = ( int )(int)lua_tonumber(__S__, 2);
    horizOffset = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->scroll(topLineNum, horizOffset);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* char Fl_Preferences::groupExists(const char * group) */
int lua_call1_Fl_Preferences__groupExists(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Preferences * __self__;
     char * group;
    
    __self__ = ( class Fl_Preferences * )lua_to_Fl_Preferences(__S__, 1, &__ERROR__);
    group = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->groupExists(group));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Image * Fl_RGB_Image::copy() */
int lua_call1_Fl_RGB_Image__copy(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_RGB_Image * __self__;
    
    __self__ = ( class Fl_RGB_Image * )lua_to_Fl_RGB_Image(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Image(__S__, __self__->copy());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Image * Fl_RGB_Image::copy(int W, int H) */
int lua_call2_Fl_RGB_Image__copy(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_RGB_Image * __self__;
     int W;
     int H;
    
    __self__ = ( class Fl_RGB_Image * )lua_to_Fl_RGB_Image(__S__, 1, &__ERROR__);
    W = ( int )(int)lua_tonumber(__S__, 2);
    H = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Image(__S__, __self__->copy(W, H));
    return 1;
  }
  
error:
  return lua_call1_Fl_RGB_Image__copy(__S__);
}
/* void Fl::foreground(uchar , uchar , uchar ) */
int lua_call1_Fl__foreground(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 3) goto error;
  {
     unsigned char __1__;
     unsigned char __2__;
     unsigned char __3__;
    
    __1__ = ( unsigned char )(char)lua_tonumber(__S__, 1);
    __2__ = ( unsigned char )(char)lua_tonumber(__S__, 2);
    __3__ = ( unsigned char )(char)lua_tonumber(__S__, 3);
    
    /* Actual call */
    Fl::foreground(__1__, __2__, __3__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Display::scrollbar_width() */
int lua_call1_Fl_Text_Display__scrollbar_width(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Display * __self__;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->scrollbar_width());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Display::scrollbar_width(int W) */
int lua_call2_Fl_Text_Display__scrollbar_width(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Display * __self__;
     int W;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    W = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->scrollbar_width(W);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Text_Display__scrollbar_width(__S__);
}
/* int fl_measure_pixmap(const const char * * data, int & w, int & h) */
/* SKIPPED (argument #1) */
/* int fl_measure_pixmap(const char * * data, int & w, int & h) */
/* SKIPPED (argument #1) */
/* double Fl_Positioner::xmaximum()const  */
int lua_call1_Fl_Positioner__xmaximum(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Positioner * __self__;
    
    __self__ = ( class Fl_Positioner * )lua_to_Fl_Positioner(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->xmaximum());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Positioner::xmaximum(double a) */
int lua_call2_Fl_Positioner__xmaximum(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Positioner * __self__;
     double a;
    
    __self__ = ( class Fl_Positioner * )lua_to_Fl_Positioner(__S__, 1, &__ERROR__);
    a = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->xmaximum(a);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Positioner__xmaximum(__S__);
}
/* class Fl_Widget * Fl_Group::child(int n)const  */
int lua_call1_Fl_Group__child(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Group * __self__;
     int n;
    
    __self__ = ( class Fl_Group * )lua_to_Fl_Group(__S__, 1, &__ERROR__);
    n = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Widget(__S__, __self__->child(n));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Shared_Image::num_images() */
int lua_call1_Fl_Shared_Image__num_images(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Shared_Image::num_images());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_Window::set_overlay() */
int lua_call1_Fl_Menu_Window__set_overlay(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Menu_Window * __self__;
    
    __self__ = ( class Fl_Menu_Window * )lua_to_Fl_Menu_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->set_overlay();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* uchar Fl_Help_View::textsize()const  */
int lua_call1_Fl_Help_View__textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Help_View * __self__;
    
    __self__ = ( class Fl_Help_View * )lua_to_Fl_Help_View(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textsize());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Help_View::textsize(uchar s) */
int lua_call2_Fl_Help_View__textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Help_View * __self__;
     unsigned char s;
    
    __self__ = ( class Fl_Help_View * )lua_to_Fl_Help_View(__S__, 1, &__ERROR__);
    s = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textsize(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Help_View__textsize(__S__);
}
/* void Fl_Widget::hide() */
int lua_call1_Fl_Widget__hide(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->hide();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_File_Icon::labeltype(const struct Fl_Label * o, int x, int y, int w, int h, Fl_Align a) */
int lua_call1_Fl_File_Icon__labeltype(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 6) goto error;
  {
     struct Fl_Label * o;
     int x;
     int y;
     int w;
     int h;
     Fl_Align a;
    
    o = ( struct Fl_Label * )lua_to_Fl_Label(__S__, 1, &__ERROR__);
    x = ( int )(int)lua_tonumber(__S__, 2);
    y = ( int )(int)lua_tonumber(__S__, 3);
    w = ( int )(int)lua_tonumber(__S__, 4);
    h = ( int )(int)lua_tonumber(__S__, 5);
    a = ( Fl_Align )(Fl_Align)(int)lua_tonumber(__S__, 6);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    Fl_File_Icon::labeltype(o, x, y, w, h, a);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Buffer::outputfile(const char * file, int start, int end, int buflen=128 * 1024) */
int lua_call1_Fl_Text_Buffer__outputfile(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 4) goto error;
  {
     class Fl_Text_Buffer * __self__;
     char * file;
     int start;
     int end;
     int buflen;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    file = ( char * )(char  *)lua_tostring(__S__, 2);
    start = ( int )(int)lua_tonumber(__S__, 3);
    end = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, __self__->outputfile(file, start, end));
      return 1;
    } else {
      buflen = ( int )(int)lua_tonumber(__S__, 5);
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, __self__->outputfile(file, start, end, buflen));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_save_dc(HWND w, HDC dc) */
/* SKIPPED (argument #1) */
/* void Fl::add_handler(int ( * h)(int )) */
/* SKIPPED (argument #1) */
/* int Fl_Check_Browser::value()const  */
int lua_call1_Fl_Check_Browser__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Check_Browser * __self__;
    
    __self__ = ( class Fl_Check_Browser * )lua_to_Fl_Check_Browser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->value());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_File_Icon::load_image(const char * i) */
int lua_call1_Fl_File_Icon__load_image(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_File_Icon * __self__;
     char * i;
    
    __self__ = ( class Fl_File_Icon * )lua_to_Fl_File_Icon(__S__, 1, &__ERROR__);
    i = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->load_image(i));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Scroll::resize(int , int , int , int ) */
int lua_call1_Fl_Scroll__resize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Scroll * __self__;
     int __2__;
     int __3__;
     int __4__;
     int __5__;
    
    __self__ = ( class Fl_Scroll * )lua_to_Fl_Scroll(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    __5__ = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->resize(__2__, __3__, __4__, __5__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_File_Icon::type() */
int lua_call1_Fl_File_Icon__type(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Icon * __self__;
    
    __self__ = ( class Fl_File_Icon * )lua_to_Fl_File_Icon(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->type());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Positioner::value(double , double ) */
int lua_call1_Fl_Positioner__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Positioner * __self__;
     double __2__;
     double __3__;
    
    __self__ = ( class Fl_Positioner * )lua_to_Fl_Positioner(__S__, 1, &__ERROR__);
    __2__ = ( double )(double)lua_tonumber(__S__, 2);
    __3__ = ( double )(double)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->value(__2__, __3__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Text_Selection * Fl_Text_Buffer::secondary_selection() */
int lua_call1_Fl_Text_Buffer__secondary_selection(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Buffer * __self__;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Text_Selection(__S__, __self__->secondary_selection());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::do_callback() */
int lua_call1_Fl_Widget__do_callback(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->do_callback();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::do_callback(class Fl_Widget * o, void * arg=0) */
int lua_call2_Fl_Widget__do_callback(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Widget * __self__;
     class Fl_Widget * o;
     void * arg;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    o = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (nparam <= 2) {
      if (__ERROR__) goto error;
      
      __self__->do_callback(o);
    } else {
      if (__ERROR__) goto error;
      
      __self__->do_callback(o, arg);
    }
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Widget__do_callback(__S__);
}
/* void Fl_Widget::do_callback(class Fl_Widget * o, long arg) */
int lua_call3_Fl_Widget__do_callback(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Widget * __self__;
     class Fl_Widget * o;
     long arg;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    o = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 2, &__ERROR__);
    arg = ( long )(long)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->do_callback(o, arg);
    ;
    return 0;
  }
  
error:
  return lua_call2_Fl_Widget__do_callback(__S__);
}
/* class Fl_Widget * Fl::focus() */
int lua_call1_Fl__focus(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_Widget(__S__, Fl::focus());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::focus(class Fl_Widget * ) */
int lua_call2_Fl__focus(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __1__;
    
    __1__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    Fl::focus(__1__);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl__focus(__S__);
}
/* class Fl_Window * Fl::first_window() */
int lua_call1_Fl__first_window(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_Window(__S__, Fl::first_window());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::first_window(class Fl_Window * ) */
int lua_call2_Fl__first_window(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     class Fl_Window * __1__;
    
    __1__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    Fl::first_window(__1__);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl__first_window(__S__);
}
/* void Fl_Pixmap::color_average(Fl_Color c, float i) */
int lua_call1_Fl_Pixmap__color_average(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Pixmap * __self__;
     Fl_Color c;
     float i;
    
    __self__ = ( class Fl_Pixmap * )lua_to_Fl_Pixmap(__S__, 1, &__ERROR__);
    c = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 2);
    i = ( float )(float)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->color_average(c, i);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_Window::erase() */
int lua_call1_Fl_Menu_Window__erase(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Menu_Window * __self__;
    
    __self__ = ( class Fl_Menu_Window * )lua_to_Fl_Menu_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->erase();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Group * Fl_Group::current() */
int lua_call1_Fl_Group__current(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_Group(__S__, Fl_Group::current());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Group::current(class Fl_Group * g) */
int lua_call2_Fl_Group__current(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     class Fl_Group * g;
    
    g = ( class Fl_Group * )lua_to_Fl_Group(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    Fl_Group::current(g);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Group__current(__S__);
}
/* char Fl_Preferences::entryExists(const char * entry) */
int lua_call1_Fl_Preferences__entryExists(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Preferences * __self__;
     char * entry;
    
    __self__ = ( class Fl_Preferences * )lua_to_Fl_Preferences(__S__, 1, &__ERROR__);
    entry = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->entryExists(entry));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Display::in_selection(int x, int y) */
int lua_call1_Fl_Text_Display__in_selection(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Text_Display * __self__;
     int x;
     int y;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    x = ( int )(int)lua_tonumber(__S__, 2);
    y = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->in_selection(x, y));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Dial::angles(short a, short b) */
int lua_call1_Fl_Dial__angles(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Dial * __self__;
     short a;
     short b;
    
    __self__ = ( class Fl_Dial * )lua_to_Fl_Dial(__S__, 1, &__ERROR__);
    a = ( short )(short)lua_tonumber(__S__, 2);
    b = ( short )(short)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->angles(a, b);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Help_View::Fl_Help_View(int xx, int yy, int ww, int hh, const char * l=0) */
int lua_call1_Fl_Help_View__Fl_Help_View(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int xx;
     int yy;
     int ww;
     int hh;
     char * l;
    
    xx = ( int )(int)lua_tonumber(__S__, 1);
    yy = ( int )(int)lua_tonumber(__S__, 2);
    ww = ( int )(int)lua_tonumber(__S__, 3);
    hh = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Help_View(__S__, new Fl_Help_View(xx, yy, ww, hh));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Help_View(__S__, new Fl_Help_View(xx, yy, ww, hh, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Box::Fl_Box(int X, int Y, int W, int H, const char * l=0) */
int lua_call1_Fl_Box__Fl_Box(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     char * l;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Box(__S__, new Fl_Box(X, Y, W, H));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Box(__S__, new Fl_Box(X, Y, W, H, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Box::Fl_Box(Fl_Boxtype b, int X, int Y, int W, int H, const char * l) */
int lua_call2_Fl_Box__Fl_Box(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 6) goto error;
  {
     Fl_Boxtype b;
     int X;
     int Y;
     int W;
     int H;
     char * l;
    
    b = ( Fl_Boxtype )(Fl_Boxtype)(int)lua_tonumber(__S__, 1);
    X = ( int )(int)lua_tonumber(__S__, 2);
    Y = ( int )(int)lua_tonumber(__S__, 3);
    W = ( int )(int)lua_tonumber(__S__, 4);
    H = ( int )(int)lua_tonumber(__S__, 5);
    l = ( char * )(char  *)lua_tostring(__S__, 6);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_Box(__S__, new Fl_Box(b, X, Y, W, H, l));
    return 1;
  }
  
error:
  return lua_call1_Fl_Box__Fl_Box(__S__);
}
/* int Fl_Text_Buffer::findchar_forward(int startPos, char searchChar, int * foundPos) */
/* SKIPPED (argument #4) */
/* int Fl_Text_Buffer::selected() */
int lua_call1_Fl_Text_Buffer__selected(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Buffer * __self__;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->selected());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Window::modal()const  */
int lua_call1_Fl_Window__modal(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Window * __self__;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->modal());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const struct Fl_Menu_Item * Fl_Menu_::menu()const  */
/* void Fl_Menu_::menu(const struct Fl_Menu_Item * m) */
int lua_call2_Fl_Menu___menu(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Menu_ * __self__;
     struct Fl_Menu_Item * m;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    m = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->menu(m);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Menu___menu(__S__);
}
/* Fl_Boxtype fl_define_FL_PLASTIC_UP_BOX() */
int lua_call1_fl_define_FL_PLASTIC_UP_BOX(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_define_FL_PLASTIC_UP_BOX());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Display::word_start(int pos) */
int lua_call1_Fl_Text_Display__word_start(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Display * __self__;
     int pos;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    pos = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->word_start(pos));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_pop_clip() */
int lua_call1_fl_pop_clip(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    fl_pop_clip();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int fl_alphasort(struct dirent * * , struct dirent * * ) */
/* SKIPPED (argument #1) */
/* const struct Fl_Menu_Item * Fl_Menu_Item::test_shortcut()const  */
int lua_call1_Fl_Menu_Item__test_shortcut(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Menu_Item(__S__, __self__->test_shortcut());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int fl_filename_expand(char * to, const char * from) */
int lua_call1_fl_filename_expand(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     char * to;
     char * from;
    
    to = ( char * )(char  *)lua_tostring(__S__, 1);
    from = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_filename_expand(to, from));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int fl_filename_expand(char * to, int tolen, const char * from) */
int lua_call2_fl_filename_expand(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 3) goto error;
  {
     char * to;
     int tolen;
     char * from;
    
    to = ( char * )(char  *)lua_tostring(__S__, 1);
    tolen = ( int )(int)lua_tonumber(__S__, 2);
    from = ( char * )(char  *)lua_tostring(__S__, 3);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_filename_expand(to, tolen, from));
    return 1;
  }
  
error:
  return lua_call1_fl_filename_expand(__S__);
}
/* const char * fl_input(const char * label, const char * deflt=0, ...) */
int lua_call1_fl_input(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * label;
     char * deflt;
    
    label = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    if (nparam <= 1) {
      lua_settop(__S__, 0);
      lua_pushstring(__S__, (const char * ) fl_input(label));
      return 1;
    } else {
      deflt = ( char * )(char  *)lua_tostring(__S__, 2);
      lua_settop(__S__, 0);
      lua_pushstring(__S__, (const char * ) fl_input(label, deflt));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Window * fl_find(int xid) */
int lua_call1_fl_find(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  #ifdef macos
  luaL_error(__S__, "Unimplemented under MacOS FLTK");
  return 0;
  #else
  if (nparam < 1) goto error;
  {
     int xid;
    
    xid = ( int )(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_Window(__S__, fl_find((Window) xid));
    return 1;
  }
  #endif
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::check() */
int lua_call1_Fl__check(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::check());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Scroll::clear() */
int lua_call1_Fl_Scroll__clear(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Scroll * __self__;
    
    __self__ = ( class Fl_Scroll * )lua_to_Fl_Scroll(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->clear();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* char fl_can_do_alpha_blending() */
int lua_call1_fl_can_do_alpha_blending(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_can_do_alpha_blending());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Display::previous_word() */
int lua_call1_Fl_Text_Display__previous_word(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Display * __self__;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->previous_word();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Display::hide_cursor() */
int lua_call1_Fl_Text_Display__hide_cursor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Display * __self__;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->hide_cursor();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* char * Fl_Text_Buffer::line_text(int pos) */
int lua_call1_Fl_Text_Buffer__line_text(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Buffer * __self__;
     int pos;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    pos = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->line_text(pos));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Slider::draw() */
int lua_call1_Fl_Slider__draw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Slider * __self__;
    
    __self__ = ( class Fl_Slider * )lua_to_Fl_Slider(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->draw();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Buffer::line_end(int pos) */
int lua_call1_Fl_Text_Buffer__line_end(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Buffer * __self__;
     int pos;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    pos = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->line_end(pos));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Buffer::search_backward(int startPos, const char * searchString, int * foundPos, int matchCase=0) */
/* SKIPPED (argument #4) */
/* void fl_file_chooser_callback(void ( * cb)(const char * )) */
/* SKIPPED (argument #1) */
/* Fl_Labeltype fl_define_FL_EMBOSSED_LABEL() */
int lua_call1_fl_define_FL_EMBOSSED_LABEL(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_define_FL_EMBOSSED_LABEL());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Input_::static_value(const char * ) */
int lua_call1_Fl_Input___static_value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Input_ * __self__;
     char * __2__;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    __2__ = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->static_value(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Input_::static_value(const char * , int ) */
int lua_call2_Fl_Input___static_value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Input_ * __self__;
     char * __2__;
     int __3__;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    __2__ = ( char * )(char  *)lua_tostring(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->static_value(__2__, __3__));
    return 1;
  }
  
error:
  return lua_call1_Fl_Input___static_value(__S__);
}
/*  Fl_Button::Fl_Button(int , int , int , int , const char * =0) */
int lua_call1_Fl_Button__Fl_Button(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int __1__;
     int __2__;
     int __3__;
     int __4__;
     char * __5__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Button(__S__, new Fl_Button(__1__, __2__, __3__, __4__));
      return 1;
    } else {
      __5__ = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Button(__S__, new Fl_Button(__1__, __2__, __3__, __4__, __5__));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_message(const char * , ...) */
int lua_call1_fl_message(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * __1__;
    
    __1__ = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    fl_message(__1__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Window::make_current() */
int lua_call1_Fl_Window__make_current(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Window * __self__;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->make_current();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_alert(const char * , ...) */
int lua_call1_fl_alert(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * __1__;
    
    __1__ = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    fl_alert(__1__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Scroll::Fl_Scroll(int X, int Y, int W, int H, const char * l=0) */
int lua_call1_Fl_Scroll__Fl_Scroll(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     char * l;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Scroll(__S__, new Fl_Scroll(X, Y, W, H));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Scroll(__S__, new Fl_Scroll(X, Y, W, H, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Counter::lstep(double a) */
int lua_call1_Fl_Counter__lstep(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Counter * __self__;
     double a;
    
    __self__ = ( class Fl_Counter * )lua_to_Fl_Counter(__S__, 1, &__ERROR__);
    a = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->lstep(a);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_file_chooser_ok_label(const char * l) */
int lua_call1_fl_file_chooser_ok_label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * l;
    
    l = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    fl_file_chooser_ok_label(l);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Input_::cut() */
int lua_call1_Fl_Input___cut(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Input_ * __self__;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->cut());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Input_::cut(int n) */
int lua_call2_Fl_Input___cut(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Input_ * __self__;
     int n;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    n = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->cut(n));
    return 1;
  }
  
error:
  return lua_call1_Fl_Input___cut(__S__);
}
/* int Fl_Input_::cut(int a, int b) */
int lua_call3_Fl_Input___cut(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Input_ * __self__;
     int a;
     int b;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    a = ( int )(int)lua_tonumber(__S__, 2);
    b = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->cut(a, b));
    return 1;
  }
  
error:
  return lua_call2_Fl_Input___cut(__S__);
}
/* double Fl_Positioner::yminimum()const  */
int lua_call1_Fl_Positioner__yminimum(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Positioner * __self__;
    
    __self__ = ( class Fl_Positioner * )lua_to_Fl_Positioner(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->yminimum());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Positioner::yminimum(double a) */
int lua_call2_Fl_Positioner__yminimum(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Positioner * __self__;
     double a;
    
    __self__ = ( class Fl_Positioner * )lua_to_Fl_Positioner(__S__, 1, &__ERROR__);
    a = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->yminimum(a);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Positioner__yminimum(__S__);
}
/* void fl_line(int , int , int , int ) */
int lua_call1_fl_line(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int __1__;
     int __2__;
     int __3__;
     int __4__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    fl_line(__1__, __2__, __3__, __4__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_line(int , int , int , int , int , int ) */
int lua_call2_fl_line(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 6) goto error;
  {
     int __1__;
     int __2__;
     int __3__;
     int __4__;
     int __5__;
     int __6__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    __5__ = ( int )(int)lua_tonumber(__S__, 5);
    __6__ = ( int )(int)lua_tonumber(__S__, 6);
    
    /* Actual call */
    fl_line(__1__, __2__, __3__, __4__, __5__, __6__);
    ;
    return 0;
  }
  
error:
  return lua_call1_fl_line(__S__);
}
/* void fl_scale(double x) */
int lua_call1_fl_scale(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     double x;
    
    x = ( double )(double)lua_tonumber(__S__, 1);
    
    /* Actual call */
    fl_scale(x);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_scale(double x, double y) */
int lua_call2_fl_scale(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     double x;
     double y;
    
    x = ( double )(double)lua_tonumber(__S__, 1);
    y = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    fl_scale(x, y);
    ;
    return 0;
  }
  
error:
  return lua_call1_fl_scale(__S__);
}
/* uchar Fl_Widget::labelsize()const  */
int lua_call1_Fl_Widget__labelsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->labelsize());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::labelsize(uchar a) */
int lua_call2_Fl_Widget__labelsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Widget * __self__;
     unsigned char a;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    a = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->labelsize(a);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Widget__labelsize(__S__);
}
/* int Fl_Browser_::hposition()const  */
int lua_call1_Fl_Browser___hposition(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Browser_ * __self__;
    
    __self__ = ( class Fl_Browser_ * )lua_to_Fl_Browser_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->hposition());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser_::hposition(int ) */
int lua_call2_Fl_Browser___hposition(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Browser_ * __self__;
     int __2__;
    
    __self__ = ( class Fl_Browser_ * )lua_to_Fl_Browser_(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->hposition(__2__);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Browser___hposition(__S__);
}
/* int Fl_Widget::output()const  */
int lua_call1_Fl_Widget__output(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->output());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_begin_points() */
int lua_call1_fl_begin_points(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    fl_begin_points();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::set_visible() */
int lua_call1_Fl_Widget__set_visible(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->set_visible();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser::remove(int ) */
int lua_call1_Fl_Browser__remove(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Browser * __self__;
     int __2__;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->remove(__2__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_curve(double , double , double , double , double , double , double , double ) */
int lua_call1_fl_curve(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 8) goto error;
  {
     double __1__;
     double __2__;
     double __3__;
     double __4__;
     double __5__;
     double __6__;
     double __7__;
     double __8__;
    
    __1__ = ( double )(double)lua_tonumber(__S__, 1);
    __2__ = ( double )(double)lua_tonumber(__S__, 2);
    __3__ = ( double )(double)lua_tonumber(__S__, 3);
    __4__ = ( double )(double)lua_tonumber(__S__, 4);
    __5__ = ( double )(double)lua_tonumber(__S__, 5);
    __6__ = ( double )(double)lua_tonumber(__S__, 6);
    __7__ = ( double )(double)lua_tonumber(__S__, 7);
    __8__ = ( double )(double)lua_tonumber(__S__, 8);
    
    /* Actual call */
    fl_curve(__1__, __2__, __3__, __4__, __5__, __6__, __7__, __8__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_arc(double x, double y, double r, double start, double a) */
int lua_call1_fl_arc(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 5) goto error;
  {
     double x;
     double y;
     double r;
     double start;
     double a;
    
    x = ( double )(double)lua_tonumber(__S__, 1);
    y = ( double )(double)lua_tonumber(__S__, 2);
    r = ( double )(double)lua_tonumber(__S__, 3);
    start = ( double )(double)lua_tonumber(__S__, 4);
    a = ( double )(double)lua_tonumber(__S__, 5);
    
    /* Actual call */
    fl_arc(x, y, r, start, a);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_arc(int x, int y, int w, int h, double a1, double a2) */
int lua_call2_fl_arc(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 6) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     double a1;
     double a2;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    a1 = ( double )(double)lua_tonumber(__S__, 5);
    a2 = ( double )(double)lua_tonumber(__S__, 6);
    
    /* Actual call */
    fl_arc(x, y, w, h, a1, a2);
    ;
    return 0;
  }
  
error:
  return lua_call1_fl_arc(__S__);
}
/* void fl_end_loop() */
int lua_call1_fl_end_loop(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    fl_end_loop();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::add_timeout(double t, Fl_Timeout_Handler , void * =0) */
/* SKIPPED (argument #2) */
/* int Fl_Value_Input::handle(int ) */
int lua_call1_Fl_Value_Input__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Value_Input * __self__;
     int __2__;
    
    __self__ = ( class Fl_Value_Input * )lua_to_Fl_Value_Input(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_scroll(int X, int Y, int W, int H, int dx, int dy, void ( * draw_area)(void * , int , int , int , int ), void * data) */
/* SKIPPED (argument #7) */
/* void fl_release_dc(HWND w, HDC dc) */
/* SKIPPED (argument #1) */
/* void Fl_Image::inactive() */
int lua_call1_Fl_Image__inactive(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Image * __self__;
    
    __self__ = ( class Fl_Image * )lua_to_Fl_Image(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->inactive();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Font Fl::set_fonts(const char * =0) */
int lua_call1_Fl__set_fonts(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  {
     char * __1__;
    
    
    /* Actual call */
    if (nparam <= 0) {
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, Fl::set_fonts());
      return 1;
    } else {
      __1__ = ( char * )(char  *)lua_tostring(__S__, 1);
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, Fl::set_fonts(__1__));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color fl_lighter(Fl_Color c) */
int lua_call1_fl_lighter(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     Fl_Color c;
    
    c = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_lighter(c));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color fl_inactive(Fl_Color c) */
int lua_call1_fl_inactive(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     Fl_Color c;
    
    c = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_inactive(c));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::activate() */
int lua_call1_Fl_Widget__activate(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->activate();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_gap() */
int lua_call1_fl_gap(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    fl_gap();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_end_complex_polygon() */
int lua_call1_fl_end_complex_polygon(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    fl_end_complex_polygon();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_transformed_vertex(double x, double y) */
int lua_call1_fl_transformed_vertex(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     double x;
     double y;
    
    x = ( double )(double)lua_tonumber(__S__, 1);
    y = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    fl_transformed_vertex(x, y);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_File_Chooser::value(const char * filename) */
int lua_call1_Fl_File_Chooser__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_File_Chooser * __self__;
     char * filename;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    filename = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->value(filename);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const char * Fl_File_Chooser::value(int f=1) */
int lua_call2_Fl_File_Chooser__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Chooser * __self__;
     int f;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (nparam <= 1) {
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_pushstring(__S__, (const char * ) __self__->value());
      return 1;
    } else {
      f = ( int )(int)lua_tonumber(__S__, 2);
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_pushstring(__S__, (const char * ) __self__->value(f));
      return 1;
    }
  }
  
error:
  return lua_call1_Fl_File_Chooser__value(__S__);
}
/* const char * fl_latin1_to_local(const char * , int n=-1) */
int lua_call1_fl_latin1_to_local(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * __1__;
     int n;
    
    __1__ = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    if (nparam <= 1) {
      lua_settop(__S__, 0);
      lua_pushstring(__S__, (const char * ) fl_latin1_to_local(__1__));
      return 1;
    } else {
      n = ( int )(int)lua_tonumber(__S__, 2);
      lua_settop(__S__, 0);
      lua_pushstring(__S__, (const char * ) fl_latin1_to_local(__1__, n));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* char Fl_Button::value()const  */
int lua_call1_Fl_Button__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Button * __self__;
    
    __self__ = ( class Fl_Button * )lua_to_Fl_Button(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->value());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Button::value(int ) */
int lua_call2_Fl_Button__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Button * __self__;
     int __2__;
    
    __self__ = ( class Fl_Button * )lua_to_Fl_Button(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->value(__2__));
    return 1;
  }
  
error:
  return lua_call1_Fl_Button__value(__S__);
}
/* void fl_frame2(const char * s, int x, int y, int w, int h) */
int lua_call1_fl_frame2(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 5) goto error;
  {
     char * s;
     int x;
     int y;
     int w;
     int h;
    
    s = ( char * )(char  *)lua_tostring(__S__, 1);
    x = ( int )(int)lua_tonumber(__S__, 2);
    y = ( int )(int)lua_tonumber(__S__, 3);
    w = ( int )(int)lua_tonumber(__S__, 4);
    h = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    fl_frame2(s, x, y, w, h);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Editor::kf_down(int c, class Fl_Text_Editor * e) */
int lua_call1_Fl_Text_Editor__kf_down(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int c;
     class Fl_Text_Editor * e;
    
    c = ( int )(int)lua_tonumber(__S__, 1);
    e = ( class Fl_Text_Editor * )lua_to_Fl_Text_Editor(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Text_Editor::kf_down(c, e));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_draw_image(Fl_Draw_Image_Cb , void * , int , int , int , int , int delta=3) */
/* SKIPPED (argument #1) */
/* void fl_draw_image(const uchar * , int , int , int , int , int delta=3, int ldelta=0) */
int lua_call2_fl_draw_image(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 5) goto error;
  {
     unsigned char * __1__;
     int __2__;
     int __3__;
     int __4__;
     int __5__;
     int delta;
     int ldelta;
    
    __1__ = ( unsigned char * )(char  *)lua_tostring(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    __5__ = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (nparam <= 5) {
      fl_draw_image(__1__, __2__, __3__, __4__, __5__);
    } else {
      delta = ( int )(int)lua_tonumber(__S__, 6);
      if (nparam <= 6) {
        fl_draw_image(__1__, __2__, __3__, __4__, __5__, delta);
      } else {
        ldelta = ( int )(int)lua_tonumber(__S__, 7);
        fl_draw_image(__1__, __2__, __3__, __4__, __5__, delta, ldelta);
      }
    }
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_rectf(int x, int y, int w, int h) */
int lua_call1_fl_rectf(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    fl_rectf(x, y, w, h);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_rectf(int x, int y, int w, int h, Fl_Color c) */
int lua_call2_fl_rectf(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 5) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     Fl_Color c;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    c = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    fl_rectf(x, y, w, h, c);
    ;
    return 0;
  }
  
error:
  return lua_call1_fl_rectf(__S__);
}
/* void fl_rectf(int x, int y, int w, int h, uchar r, uchar g, uchar b) */
int lua_call3_fl_rectf(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 7) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     unsigned char r;
     unsigned char g;
     unsigned char b;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    r = ( unsigned char )(char)lua_tonumber(__S__, 5);
    g = ( unsigned char )(char)lua_tonumber(__S__, 6);
    b = ( unsigned char )(char)lua_tonumber(__S__, 7);
    
    /* Actual call */
    fl_rectf(x, y, w, h, r, g, b);
    ;
    return 0;
  }
  
error:
  return lua_call2_fl_rectf(__S__);
}
/*  Fl_Hor_Fill_Slider::Fl_Hor_Fill_Slider(int x, int y, int w, int h, const char * l=0) */
int lua_call1_Fl_Hor_Fill_Slider__Fl_Hor_Fill_Slider(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Hor_Fill_Slider(__S__, new Fl_Hor_Fill_Slider(x, y, w, h));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Hor_Fill_Slider(__S__, new Fl_Hor_Fill_Slider(x, y, w, h, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color fl_color_average(Fl_Color c1, Fl_Color c2, float weight) */
int lua_call1_fl_color_average(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 3) goto error;
  {
     Fl_Color c1;
     Fl_Color c2;
     float weight;
    
    c1 = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 1);
    c2 = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 2);
    weight = ( float )(float)lua_tonumber(__S__, 3);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_color_average(c1, c2, weight));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const char * fl_shortcut_label(int ) */
int lua_call1_fl_shortcut_label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     int __1__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) fl_shortcut_label(__1__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_overlay_clear() */
int lua_call1_fl_overlay_clear(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    fl_overlay_clear();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_cursor(Fl_Cursor , Fl_Color =FL_BLACK, Fl_Color =FL_WHITE) */
int lua_call1_fl_cursor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     Fl_Cursor __1__;
     Fl_Color __2__;
     Fl_Color __3__;
    
    __1__ = ( Fl_Cursor )(Fl_Cursor)(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    if (nparam <= 1) {
      fl_cursor(__1__);
    } else {
      __2__ = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 2);
      if (nparam <= 2) {
        fl_cursor(__1__, __2__);
      } else {
        __3__ = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 3);
        fl_cursor(__1__, __2__, __3__);
      }
    }
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_clip_region(Fl_Region ) */
/* SKIPPED (argument #1) */
/* int fl_xid(const class Fl_Window * w) */
int lua_call1_fl_xid(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     class Fl_Window * w;
    
    w = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, (int) fl_xid(w));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Boxtype fl_define_FL_GTK_UP_BOX() */
int lua_call1_fl_define_FL_GTK_UP_BOX(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_define_FL_GTK_UP_BOX());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Menu_Item::visible()const  */
int lua_call1_Fl_Menu_Item__visible(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->visible());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Image * Fl_Shared_Image::copy() */
int lua_call1_Fl_Shared_Image__copy(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Shared_Image * __self__;
    
    __self__ = ( class Fl_Shared_Image * )lua_to_Fl_Shared_Image(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Image(__S__, __self__->copy());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Image * Fl_Shared_Image::copy(int W, int H) */
int lua_call2_Fl_Shared_Image__copy(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Shared_Image * __self__;
     int W;
     int H;
    
    __self__ = ( class Fl_Shared_Image * )lua_to_Fl_Shared_Image(__S__, 1, &__ERROR__);
    W = ( int )(int)lua_tonumber(__S__, 2);
    H = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Image(__S__, __self__->copy(W, H));
    return 1;
  }
  
error:
  return lua_call1_Fl_Shared_Image__copy(__S__);
}
/* int fl_choice(const char * q, const char * b0, const char * b1, const char * b2, ...) */
int lua_call1_fl_choice(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     char * q;
     char * b0;
     char * b1;
     char * b2;
    
    q = ( char * )(char  *)lua_tostring(__S__, 1);
    b0 = ( char * )(char  *)lua_tostring(__S__, 2);
    b1 = ( char * )(char  *)lua_tostring(__S__, 3);
    b2 = ( char * )(char  *)lua_tostring(__S__, 4);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_choice(q, b0, b1, b2));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int fl_descent() */
int lua_call1_fl_descent(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_descent());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* float Fl_Progress::minimum()const  */
int lua_call1_Fl_Progress__minimum(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Progress * __self__;
    
    __self__ = ( class Fl_Progress * )lua_to_Fl_Progress(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->minimum());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Progress::minimum(float v) */
int lua_call2_Fl_Progress__minimum(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Progress * __self__;
     float v;
    
    __self__ = ( class Fl_Progress * )lua_to_Fl_Progress(__S__, 1, &__ERROR__);
    v = ( float )(float)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->minimum(v);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Progress__minimum(__S__);
}
/* int fl_size() */
int lua_call1_fl_size(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_size());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Help_Dialog::y() */
int lua_call1_Fl_Help_Dialog__y(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Help_Dialog * __self__;
    
    __self__ = ( class Fl_Help_Dialog * )lua_to_Fl_Help_Dialog(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->y());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_yxline(int x, int y, int y1) */
int lua_call1_fl_yxline(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 3) goto error;
  {
     int x;
     int y;
     int y1;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    y1 = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    fl_yxline(x, y, y1);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_yxline(int x, int y, int y1, int x2) */
int lua_call2_fl_yxline(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int y1;
     int x2;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    y1 = ( int )(int)lua_tonumber(__S__, 3);
    x2 = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    fl_yxline(x, y, y1, x2);
    ;
    return 0;
  }
  
error:
  return lua_call1_fl_yxline(__S__);
}
/* void fl_yxline(int x, int y, int y1, int x2, int y3) */
int lua_call3_fl_yxline(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 5) goto error;
  {
     int x;
     int y;
     int y1;
     int x2;
     int y3;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    y1 = ( int )(int)lua_tonumber(__S__, 3);
    x2 = ( int )(int)lua_tonumber(__S__, 4);
    y3 = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    fl_yxline(x, y, y1, x2, y3);
    ;
    return 0;
  }
  
error:
  return lua_call2_fl_yxline(__S__);
}
/* int Fl_Light_Button::handle(int ) */
int lua_call1_Fl_Light_Button__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Light_Button * __self__;
     int __2__;
    
    __self__ = ( class Fl_Light_Button * )lua_to_Fl_Light_Button(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Window * Fl::modal() */
int lua_call1_Fl__modal(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_Window(__S__, Fl::modal());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int fl_height() */
int lua_call1_fl_height(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_height());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int fl_height(int , int size) */
int lua_call2_fl_height(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int __1__;
     int size;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    size = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_height(__1__, size));
    return 1;
  }
  
error:
  return lua_call1_fl_height(__S__);
}
/* void Fl_Text_Editor::remove_all_key_bindings() */
int lua_call1_Fl_Text_Editor__remove_all_key_bindings(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Editor * __self__;
    
    __self__ = ( class Fl_Text_Editor * )lua_to_Fl_Text_Editor(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->remove_all_key_bindings();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Editor::remove_all_key_bindings(struct Fl_Text_Editor::Key_Binding * * list) */
/* SKIPPED (argument #2) */
/* void fl_rect(int x, int y, int w, int h) */
int lua_call1_fl_rect(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    fl_rect(x, y, w, h);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_rect(int x, int y, int w, int h, Fl_Color c) */
int lua_call2_fl_rect(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 5) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     Fl_Color c;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    c = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    fl_rect(x, y, w, h, c);
    ;
    return 0;
  }
  
error:
  return lua_call1_fl_rect(__S__);
}
/* int Fl_Menu_Bar::handle(int ) */
int lua_call1_Fl_Menu_Bar__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Menu_Bar * __self__;
     int __2__;
    
    __self__ = ( class Fl_Menu_Bar * )lua_to_Fl_Menu_Bar(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Bitmap::draw(int X, int Y) */
int lua_call1_Fl_Bitmap__draw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Bitmap * __self__;
     int X;
     int Y;
    
    __self__ = ( class Fl_Bitmap * )lua_to_Fl_Bitmap(__S__, 1, &__ERROR__);
    X = ( int )(int)lua_tonumber(__S__, 2);
    Y = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->draw(X, Y);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Bitmap::draw(int X, int Y, int W, int H, int cx=0, int cy=0) */
int lua_call2_Fl_Bitmap__draw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Bitmap * __self__;
     int X;
     int Y;
     int W;
     int H;
     int cx;
     int cy;
    
    __self__ = ( class Fl_Bitmap * )lua_to_Fl_Bitmap(__S__, 1, &__ERROR__);
    X = ( int )(int)lua_tonumber(__S__, 2);
    Y = ( int )(int)lua_tonumber(__S__, 3);
    W = ( int )(int)lua_tonumber(__S__, 4);
    H = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (nparam <= 5) {
      if (__ERROR__) goto error;
      
      __self__->draw(X, Y, W, H);
    } else {
      cx = ( int )(int)lua_tonumber(__S__, 6);
      if (nparam <= 6) {
        if (__ERROR__) goto error;
        
        __self__->draw(X, Y, W, H, cx);
      } else {
        cy = ( int )(int)lua_tonumber(__S__, 7);
        if (__ERROR__) goto error;
        
        __self__->draw(X, Y, W, H, cx, cy);
      }
    }
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Bitmap__draw(__S__);
}
/* void fl_copy_offscreen(int x, int y, int w, int h, HBITMAP pixmap, int srcx, int srcy) */
/* SKIPPED (argument #5) */
/* int fl_filename_isdir(const char * name) */
int lua_call1_fl_filename_isdir(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * name;
    
    name = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_filename_isdir(name));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* double fl_transform_y(double x, double y) */
int lua_call1_fl_transform_y(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     double x;
     double y;
    
    x = ( double )(double)lua_tonumber(__S__, 1);
    y = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_transform_y(x, y));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* double Fl_Valuator::round(double ) */
int lua_call1_Fl_Valuator__round(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Valuator * __self__;
     double __2__;
    
    __self__ = ( class Fl_Valuator * )lua_to_Fl_Valuator(__S__, 1, &__ERROR__);
    __2__ = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->round(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::screen_count() */
int lua_call1_Fl__screen_count(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::screen_count());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Image * Fl_Bitmap::copy() */
int lua_call1_Fl_Bitmap__copy(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Bitmap * __self__;
    
    __self__ = ( class Fl_Bitmap * )lua_to_Fl_Bitmap(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Image(__S__, __self__->copy());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Image * Fl_Bitmap::copy(int W, int H) */
int lua_call2_Fl_Bitmap__copy(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Bitmap * __self__;
     int W;
     int H;
    
    __self__ = ( class Fl_Bitmap * )lua_to_Fl_Bitmap(__S__, 1, &__ERROR__);
    W = ( int )(int)lua_tonumber(__S__, 2);
    H = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Image(__S__, __self__->copy(W, H));
    return 1;
  }
  
error:
  return lua_call1_Fl_Bitmap__copy(__S__);
}
/* void Fl_Text_Selection::update(int pos, int nDeleted, int nInserted) */
int lua_call1_Fl_Text_Selection__update(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 4) goto error;
  {
     class Fl_Text_Selection * __self__;
     int pos;
     int nDeleted;
     int nInserted;
    
    __self__ = ( class Fl_Text_Selection * )lua_to_Fl_Text_Selection(__S__, 1, &__ERROR__);
    pos = ( int )(int)lua_tonumber(__S__, 2);
    nDeleted = ( int )(int)lua_tonumber(__S__, 3);
    nInserted = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->update(pos, nDeleted, nInserted);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int fl_numericsort(struct dirent * * , struct dirent * * ) */
/* SKIPPED (argument #1) */
/* void fl_pie(int x, int y, int w, int h, double a1, double a2) */
int lua_call1_fl_pie(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 6) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     double a1;
     double a2;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    a1 = ( double )(double)lua_tonumber(__S__, 5);
    a2 = ( double )(double)lua_tonumber(__S__, 6);
    
    /* Actual call */
    fl_pie(x, y, w, h, a1, a2);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int fl_color_chooser(const char * name, double & r, double & g, double & b) */
int lua_call1_fl_color_chooser(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     char * name;
     double r;
     double g;
     double b;
    
    name = ( char * )(char  *)lua_tostring(__S__, 1);
    r = ( double )(double)lua_tonumber(__S__, 2);
    g = ( double )(double)lua_tonumber(__S__, 3);
    b = ( double )(double)lua_tonumber(__S__, 4);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_color_chooser(name, r, g, b));
    lua_pushnumber(__S__, r);
    lua_pushnumber(__S__, g);
    lua_pushnumber(__S__, b);
    return 4;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int fl_color_chooser(const char * name, uchar & r, uchar & g, uchar & b) */
int lua_call2_fl_color_chooser(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     char * name;
     unsigned char r;
     unsigned char g;
     unsigned char b;
    
    name = ( char * )(char  *)lua_tostring(__S__, 1);
    r = ( unsigned char )(char)lua_tonumber(__S__, 2);
    g = ( unsigned char )(char)lua_tonumber(__S__, 3);
    b = ( unsigned char )(char)lua_tonumber(__S__, 4);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_color_chooser(name, r, g, b));
    lua_pushnumber(__S__, r);
    lua_pushnumber(__S__, g);
    lua_pushnumber(__S__, b);
    return 4;
  }
  
error:
  return lua_call1_fl_color_chooser(__S__);
}
/* Fl_Boxtype fl_define_FL_OVAL_BOX() */
int lua_call1_fl_define_FL_OVAL_BOX(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_define_FL_OVAL_BOX());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::add_idle(void ( * cb)(void * ), void * =0) */
/* SKIPPED (argument #1) */
/* void fl_measure(const char * , int & x, int & y, int draw_symbols=1) */
int lua_call1_fl_measure(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 3) goto error;
  {
     char * __1__;
     int x;
     int y;
     int draw_symbols;
    
    __1__ = ( char * )(char  *)lua_tostring(__S__, 1);
    x = ( int )(int)lua_tonumber(__S__, 2);
    y = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (nparam <= 3) {
      fl_measure(__1__, x, y);
    } else {
      draw_symbols = ( int )(int)lua_tonumber(__S__, 4);
      fl_measure(__1__, x, y, draw_symbols);
    }
    lua_settop(__S__, 0);
    ;
    lua_pushnumber(__S__, x);
    lua_pushnumber(__S__, y);
    return 2;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const struct Fl_Menu_Item * Fl_Menu_::find_item(const char * name) */
int lua_call1_Fl_Menu___find_item(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Menu_ * __self__;
     char * name;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    name = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Menu_Item(__S__, __self__->find_item(name));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Input_::replace(int , int , const char * , int =0) */
int lua_call1_Fl_Input___replace(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 4) goto error;
  {
     class Fl_Input_ * __self__;
     int __2__;
     int __3__;
     char * __4__;
     int __5__;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( char * )(char  *)lua_tostring(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, __self__->replace(__2__, __3__, __4__));
      return 1;
    } else {
      __5__ = ( int )(int)lua_tonumber(__S__, 5);
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, __self__->replace(__2__, __3__, __4__, __5__));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_begin_line() */
int lua_call1_fl_begin_line(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    fl_begin_line();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_overlay_rect(int , int , int , int ) */
int lua_call1_fl_overlay_rect(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int __1__;
     int __2__;
     int __3__;
     int __4__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    fl_overlay_rect(__1__, __2__, __3__, __4__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_end_polygon() */
int lua_call1_fl_end_polygon(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    fl_end_polygon();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color fl_color_cube(int r, int g, int b) */
int lua_call1_fl_color_cube(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 3) goto error;
  {
     int r;
     int g;
     int b;
    
    r = ( int )(int)lua_tonumber(__S__, 1);
    g = ( int )(int)lua_tonumber(__S__, 2);
    b = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_color_cube(r, g, b));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Display::show_cursor(int b=1) */
int lua_call1_Fl_Text_Display__show_cursor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Display * __self__;
     int b;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (nparam <= 1) {
      if (__ERROR__) goto error;
      
      __self__->show_cursor();
    } else {
      b = ( int )(int)lua_tonumber(__S__, 2);
      if (__ERROR__) goto error;
      
      __self__->show_cursor(b);
    }
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_File_Icon::load(const char * f) */
int lua_call1_Fl_File_Icon__load(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_File_Icon * __self__;
     char * f;
    
    __self__ = ( class Fl_File_Icon * )lua_to_Fl_File_Icon(__S__, 1, &__ERROR__);
    f = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->load(f);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Simple_Counter::Fl_Simple_Counter(int x, int y, int w, int h, const char * l=0) */
int lua_call1_Fl_Simple_Counter__Fl_Simple_Counter(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Simple_Counter(__S__, new Fl_Simple_Counter(x, y, w, h));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Simple_Counter(__S__, new Fl_Simple_Counter(x, y, w, h, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_murgaLuaOffScreen::endOffScreenDrawing() */
int lua_call1_Fl_murgaLuaOffScreen__endOffScreenDrawing(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_murgaLuaOffScreen * __self__;
    
    __self__ = ( class Fl_murgaLuaOffScreen * )lua_to_Fl_murgaLuaOffScreen(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->endOffScreenDrawing();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const char * Fl_Browser::text(int )const  */
int lua_call1_Fl_Browser__text(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Browser * __self__;
     int __2__;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->text(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser::text(int , const char * ) */
int lua_call2_Fl_Browser__text(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Browser * __self__;
     int __2__;
     char * __3__;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( char * )(char  *)lua_tostring(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->text(__2__, __3__);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Browser__text(__S__);
}
/* void Fl_Double_Window::flush() */
int lua_call1_Fl_Double_Window__flush(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Double_Window * __self__;
    
    __self__ = ( class Fl_Double_Window * )lua_to_Fl_Double_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->flush();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int fl_add_symbol(const char * name, void ( * drawit)(Fl_Color ), int scalable) */
/* SKIPPED (argument #2) */
/* double Fl_Valuator::increment(double , int ) */
int lua_call1_Fl_Valuator__increment(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Valuator * __self__;
     double __2__;
     int __3__;
    
    __self__ = ( class Fl_Valuator * )lua_to_Fl_Valuator(__S__, 1, &__ERROR__);
    __2__ = ( double )(double)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->increment(__2__, __3__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::event_is_click() */
int lua_call1_Fl__event_is_click(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::event_is_click());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::event_is_click(int i) */
int lua_call2_Fl__event_is_click(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     int i;
    
    i = ( int )(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    Fl::event_is_click(i);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl__event_is_click(__S__);
}
/* const char * Fl_File_Chooser::filter() */
int lua_call1_Fl_File_Chooser__filter(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Chooser * __self__;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->filter());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_File_Chooser::filter(const char * p) */
int lua_call2_Fl_File_Chooser__filter(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_File_Chooser * __self__;
     char * p;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    p = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->filter(p);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_File_Chooser__filter(__S__);
}
/* void fl_push_clip(int x, int y, int w, int h) */
int lua_call1_fl_push_clip(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    fl_push_clip(x, y, w, h);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Shared_Image::refcount() */
int lua_call1_Fl_Shared_Image__refcount(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Shared_Image * __self__;
    
    __self__ = ( class Fl_Shared_Image * )lua_to_Fl_Shared_Image(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->refcount());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int fl_filename_absolute(char * to, const char * from) */
int lua_call1_fl_filename_absolute(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     char * to;
     char * from;
    
    to = ( char * )(char  *)lua_tostring(__S__, 1);
    from = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_filename_absolute(to, from));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int fl_filename_absolute(char * to, int tolen, const char * from) */
int lua_call2_fl_filename_absolute(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 3) goto error;
  {
     char * to;
     int tolen;
     char * from;
    
    to = ( char * )(char  *)lua_tostring(__S__, 1);
    tolen = ( int )(int)lua_tonumber(__S__, 2);
    from = ( char * )(char  *)lua_tostring(__S__, 3);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_filename_absolute(to, tolen, from));
    return 1;
  }
  
error:
  return lua_call1_fl_filename_absolute(__S__);
}
/* void Fl_Widget::clear_damage(uchar c=0) */
int lua_call1_Fl_Widget__clear_damage(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
     unsigned char c;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (nparam <= 1) {
      if (__ERROR__) goto error;
      
      __self__->clear_damage();
    } else {
      c = ( unsigned char )(char)lua_tonumber(__S__, 2);
      if (__ERROR__) goto error;
      
      __self__->clear_damage(c);
    }
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color fl_darker(Fl_Color c) */
int lua_call1_fl_darker(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     Fl_Color c;
    
    c = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_darker(c));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* unsigned int Fl::get_color(Fl_Color ) */
int lua_call1_Fl__get_color(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     Fl_Color __1__;
    
    __1__ = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::get_color(__1__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::get_color(Fl_Color , uchar & , uchar & , uchar & ) */
int lua_call2_Fl__get_color(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     Fl_Color __1__;
     unsigned char __2__;
     unsigned char __3__;
     unsigned char __4__;
    
    __1__ = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 1);
    __2__ = ( unsigned char )(char)lua_tonumber(__S__, 2);
    __3__ = ( unsigned char )(char)lua_tonumber(__S__, 3);
    __4__ = ( unsigned char )(char)lua_tonumber(__S__, 4);
    
    /* Actual call */
    Fl::get_color(__1__, __2__, __3__, __4__);
    lua_settop(__S__, 0);
    ;
    lua_pushnumber(__S__, __2__);
    lua_pushnumber(__S__, __3__);
    lua_pushnumber(__S__, __4__);
    return 3;
  }
  
error:
  return lua_call1_Fl__get_color(__S__);
}
/* void fl_vertex(double x, double y) */
int lua_call1_fl_vertex(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     double x;
     double y;
    
    x = ( double )(double)lua_tonumber(__S__, 1);
    y = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    fl_vertex(x, y);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const char * fl_local_to_latin1(const char * , int n=-1) */
int lua_call1_fl_local_to_latin1(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * __1__;
     int n;
    
    __1__ = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    if (nparam <= 1) {
      lua_settop(__S__, 0);
      lua_pushstring(__S__, (const char * ) fl_local_to_latin1(__1__));
      return 1;
    } else {
      n = ( int )(int)lua_tonumber(__S__, 2);
      lua_settop(__S__, 0);
      lua_pushstring(__S__, (const char * ) fl_local_to_latin1(__1__, n));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Buffer::remove_predelete_callback(Fl_Text_Predelete_Cb predelCB, void * cbArg) */
/* SKIPPED (argument #2) */
/* int Fl_Text_Selection::end() */
int lua_call1_Fl_Text_Selection__end(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Selection * __self__;
    
    __self__ = ( class Fl_Text_Selection * )lua_to_Fl_Text_Selection(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->end());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Buffer::count_lines(int startPos, int endPos) */
int lua_call1_Fl_Text_Buffer__count_lines(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Text_Buffer * __self__;
     int startPos;
     int endPos;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    startPos = ( int )(int)lua_tonumber(__S__, 2);
    endPos = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->count_lines(startPos, endPos));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_RGB_Image::label(class Fl_Widget * w) */
int lua_call1_Fl_RGB_Image__label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_RGB_Image * __self__;
     class Fl_Widget * w;
    
    __self__ = ( class Fl_RGB_Image * )lua_to_Fl_RGB_Image(__S__, 1, &__ERROR__);
    w = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->label(w);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_RGB_Image::label(struct Fl_Menu_Item * m) */
int lua_call2_Fl_RGB_Image__label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_RGB_Image * __self__;
     struct Fl_Menu_Item * m;
    
    __self__ = ( class Fl_RGB_Image * )lua_to_Fl_RGB_Image(__S__, 1, &__ERROR__);
    m = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->label(m);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_RGB_Image__label(__S__);
}
/* const char * fl_password(const char * label, const char * deflt=0, ...) */
int lua_call1_fl_password(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * label;
     char * deflt;
    
    label = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    if (nparam <= 1) {
      lua_settop(__S__, 0);
      lua_pushstring(__S__, (const char * ) fl_password(label));
      return 1;
    } else {
      deflt = ( char * )(char  *)lua_tostring(__S__, 2);
      lua_settop(__S__, 0);
      lua_pushstring(__S__, (const char * ) fl_password(label, deflt));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Font Fl_Value_Output::textfont()const  */
int lua_call1_Fl_Value_Output__textfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Value_Output * __self__;
    
    __self__ = ( class Fl_Value_Output * )lua_to_Fl_Value_Output(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textfont());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Value_Output::textfont(uchar s) */
int lua_call2_Fl_Value_Output__textfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Value_Output * __self__;
     unsigned char s;
    
    __self__ = ( class Fl_Value_Output * )lua_to_Fl_Value_Output(__S__, 1, &__ERROR__);
    s = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textfont(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Value_Output__textfont(__S__);
}
/* int Fl_File_Browser::filetype()const  */
int lua_call1_Fl_File_Browser__filetype(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Browser * __self__;
    
    __self__ = ( class Fl_File_Browser * )lua_to_Fl_File_Browser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->filetype());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_File_Browser::filetype(int t) */
int lua_call2_Fl_File_Browser__filetype(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_File_Browser * __self__;
     int t;
    
    __self__ = ( class Fl_File_Browser * )lua_to_Fl_File_Browser(__S__, 1, &__ERROR__);
    t = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->filetype(t);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_File_Browser__filetype(__S__);
}
/* int Fl_Menu_Item::active()const  */
int lua_call1_Fl_Menu_Item__active(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->active());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* double fl_width(uchar ) */
int lua_call1_fl_width(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     unsigned char __1__;
    
    __1__ = ( unsigned char )(char)lua_tonumber(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_width(__1__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* double fl_width(const char * ) */
int lua_call2_fl_width(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * __1__;
    
    __1__ = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_width(__1__));
    return 1;
  }
  
error:
  return lua_call1_fl_width(__S__);
}
/* double fl_width(const char * , int n) */
int lua_call3_fl_width(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     char * __1__;
     int n;
    
    __1__ = ( char * )(char  *)lua_tostring(__S__, 1);
    n = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_width(__1__, n));
    return 1;
  }
  
error:
  return lua_call2_fl_width(__S__);
}
/*  Fl_Value_Slider::Fl_Value_Slider(int x, int y, int w, int h, const char * l=0) */
int lua_call1_Fl_Value_Slider__Fl_Value_Slider(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Value_Slider(__S__, new Fl_Value_Slider(x, y, w, h));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Value_Slider(__S__, new Fl_Value_Slider(x, y, w, h, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Bitmap::label(class Fl_Widget * w) */
int lua_call1_Fl_Bitmap__label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Bitmap * __self__;
     class Fl_Widget * w;
    
    __self__ = ( class Fl_Bitmap * )lua_to_Fl_Bitmap(__S__, 1, &__ERROR__);
    w = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->label(w);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Bitmap::label(struct Fl_Menu_Item * m) */
int lua_call2_Fl_Bitmap__label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Bitmap * __self__;
     struct Fl_Menu_Item * m;
    
    __self__ = ( class Fl_Bitmap * )lua_to_Fl_Bitmap(__S__, 1, &__ERROR__);
    m = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->label(m);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Bitmap__label(__S__);
}
/* Fl_Color fl_contrast(Fl_Color fg, Fl_Color bg) */
int lua_call1_fl_contrast(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     Fl_Color fg;
     Fl_Color bg;
    
    fg = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 1);
    bg = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_contrast(fg, bg));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_begin_complex_polygon() */
int lua_call1_fl_begin_complex_polygon(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    fl_begin_complex_polygon();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Overlay_Window::show() */
int lua_call1_Fl_Overlay_Window__show(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Overlay_Window * __self__;
    
    __self__ = ( class Fl_Overlay_Window * )lua_to_Fl_Overlay_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->show();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Overlay_Window::show(int a, char * * b) */
/* SKIPPED (argument #3) */
/* int Fl_Text_Editor::kf_ctrl_move(int c, class Fl_Text_Editor * e) */
int lua_call1_Fl_Text_Editor__kf_ctrl_move(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int c;
     class Fl_Text_Editor * e;
    
    c = ( int )(int)lua_tonumber(__S__, 1);
    e = ( class Fl_Text_Editor * )lua_to_Fl_Text_Editor(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Text_Editor::kf_ctrl_move(c, e));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Single_Window::show() */
int lua_call1_Fl_Single_Window__show(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Single_Window * __self__;
    
    __self__ = ( class Fl_Single_Window * )lua_to_Fl_Single_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->show();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Single_Window::show(int a, char * * b) */
/* SKIPPED (argument #3) */
/* int Fl_Image::count()const  */
int lua_call1_Fl_Image__count(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Image * __self__;
    
    __self__ = ( class Fl_Image * )lua_to_Fl_Image(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->count());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Double_Window::show() */
int lua_call1_Fl_Double_Window__show(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Double_Window * __self__;
    
    __self__ = ( class Fl_Double_Window * )lua_to_Fl_Double_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->show();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Double_Window::show(int a, char * * b) */
/* SKIPPED (argument #3) */
/* const struct Fl_Menu_Item * Fl_Menu_Item::pulldown(int X, int Y, int W, int H, const struct Fl_Menu_Item * picked=0, const class Fl_Menu_ * =0, const struct Fl_Menu_Item * title=0, int menubar=0)const  */
int lua_call1_Fl_Menu_Item__pulldown(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     struct Fl_Menu_Item * __self__;
     int X;
     int Y;
     int W;
     int H;
     struct Fl_Menu_Item * picked;
     class Fl_Menu_ * __7__;
     struct Fl_Menu_Item * title;
     int menubar;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    X = ( int )(int)lua_tonumber(__S__, 2);
    Y = ( int )(int)lua_tonumber(__S__, 3);
    W = ( int )(int)lua_tonumber(__S__, 4);
    H = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (nparam <= 5) {
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_push_Fl_Menu_Item(__S__, __self__->pulldown(X, Y, W, H));
      return 1;
    } else {
      picked = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 6, &__ERROR__);
      if (nparam <= 6) {
        if (__ERROR__) goto error;
        
        lua_settop(__S__, 0);
        lua_push_Fl_Menu_Item(__S__, __self__->pulldown(X, Y, W, H, picked));
        return 1;
      } else {
        __7__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 7, &__ERROR__);
        if (nparam <= 7) {
          if (__ERROR__) goto error;
          
          lua_settop(__S__, 0);
          lua_push_Fl_Menu_Item(__S__, __self__->pulldown(X, Y, W, H, picked, __7__));
          return 1;
        } else {
          title = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 8, &__ERROR__);
          if (nparam <= 8) {
            if (__ERROR__) goto error;
            
            lua_settop(__S__, 0);
            lua_push_Fl_Menu_Item(__S__, __self__->pulldown(X, Y, W, H, picked, __7__, title));
            return 1;
          } else {
            menubar = ( int )(int)lua_tonumber(__S__, 9);
            if (__ERROR__) goto error;
            
            lua_settop(__S__, 0);
            lua_push_Fl_Menu_Item(__S__, __self__->pulldown(X, Y, W, H, picked, __7__, title, menubar));
            return 1;
          }
        }
      }
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* struct Fl_Menu_Item * Fl_Menu_Item::first() */
int lua_call1_Fl_Menu_Item__first(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Menu_Item(__S__, __self__->first());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color Fl_Counter::textcolor()const  */
int lua_call1_Fl_Counter__textcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Counter * __self__;
    
    __self__ = ( class Fl_Counter * )lua_to_Fl_Counter(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textcolor());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Counter::textcolor(unsigned int s) */
int lua_call2_Fl_Counter__textcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Counter * __self__;
     unsigned int s;
    
    __self__ = ( class Fl_Counter * )lua_to_Fl_Counter(__S__, 1, &__ERROR__);
    s = ( unsigned int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textcolor(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Counter__textcolor(__S__);
}
/* void Fl::release_widget_pointer(class Fl_Widget * & w) */
/* SKIPPED (argument #1) */
/* void Fl_murgaLuaOffScreen::startOffScreenDrawing() */
int lua_call1_Fl_murgaLuaOffScreen__startOffScreenDrawing(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_murgaLuaOffScreen * __self__;
    
    __self__ = ( class Fl_murgaLuaOffScreen * )lua_to_Fl_murgaLuaOffScreen(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->startOffScreenDrawing();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* char * fl_dir_chooser(const char * message, const char * fname, int relative=0) */
int lua_call1_fl_dir_chooser(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     char * message;
     char * fname;
     int relative;
    
    message = ( char * )(char  *)lua_tostring(__S__, 1);
    fname = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (nparam <= 2) {
      lua_settop(__S__, 0);
      lua_pushstring(__S__, (const char * ) fl_dir_chooser(message, fname));
      return 1;
    } else {
      relative = ( int )(int)lua_tonumber(__S__, 3);
      lua_settop(__S__, 0);
      lua_pushstring(__S__, (const char * ) fl_dir_chooser(message, fname, relative));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int fl_casenumericsort(struct dirent * * , struct dirent * * ) */
/* SKIPPED (argument #1) */
/* int Fl_Text_Buffer::character_width(char c, int indent, int tabDist, char nullSubsChar) */
int lua_call1_Fl_Text_Buffer__character_width(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     char c;
     int indent;
     int tabDist;
     char nullSubsChar;
    
    c = ( char )(char)lua_tonumber(__S__, 1);
    indent = ( int )(int)lua_tonumber(__S__, 2);
    tabDist = ( int )(int)lua_tonumber(__S__, 3);
    nullSubsChar = ( char )(char)lua_tonumber(__S__, 4);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Text_Buffer::character_width(c, indent, tabDist, nullSubsChar));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Editor::kf_paste(int c, class Fl_Text_Editor * e) */
int lua_call1_Fl_Text_Editor__kf_paste(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int c;
     class Fl_Text_Editor * e;
    
    c = ( int )(int)lua_tonumber(__S__, 1);
    e = ( class Fl_Text_Editor * )lua_to_Fl_Text_Editor(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Text_Editor::kf_paste(c, e));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Text_Buffer::Fl_Text_Buffer(int requestedSize=0) */
int lua_call1_Fl_Text_Buffer__Fl_Text_Buffer(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  {
     int requestedSize;
    
    
    /* Actual call */
    if (nparam <= 0) {
      lua_settop(__S__, 0);
      lua_push_Fl_Text_Buffer(__S__, new Fl_Text_Buffer());
      return 1;
    } else {
      requestedSize = ( int )(int)lua_tonumber(__S__, 1);
      lua_settop(__S__, 0);
      lua_push_Fl_Text_Buffer(__S__, new Fl_Text_Buffer(requestedSize));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color fl_gray_ramp(int i) */
int lua_call1_fl_gray_ramp(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     int i;
    
    i = ( int )(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_gray_ramp(i));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Boxtype fl_box(Fl_Boxtype b) */
int lua_call1_fl_box(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     Fl_Boxtype b;
    
    b = ( Fl_Boxtype )(Fl_Boxtype)(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_box(b));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_::shortcut(int i, int s) */
int lua_call1_Fl_Menu___shortcut(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Menu_ * __self__;
     int i;
     int s;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    i = ( int )(int)lua_tonumber(__S__, 2);
    s = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->shortcut(i, s);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Buffer::unhighlight() */
int lua_call1_Fl_Text_Buffer__unhighlight(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Buffer * __self__;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->unhighlight();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* char * Fl_Text_Buffer::selection_text() */
int lua_call1_Fl_Text_Buffer__selection_text(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Buffer * __self__;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->selection_text());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void * Fl_File_Chooser::user_data()const  */
/* SKIPPED (return type) */
/* void Fl_File_Chooser::user_data(void * d) */
/* SKIPPED (argument #2) */
/* Fl_Boxtype Fl_Menu_::down_box()const  */
int lua_call1_Fl_Menu___down_box(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Menu_ * __self__;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->down_box());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_::down_box(Fl_Boxtype b) */
int lua_call2_Fl_Menu___down_box(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Menu_ * __self__;
     Fl_Boxtype b;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    b = ( Fl_Boxtype )(Fl_Boxtype)(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->down_box(b);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Menu___down_box(__S__);
}
/* int Fl_Text_Buffer::length() */
int lua_call1_Fl_Text_Buffer__length(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Buffer * __self__;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->length());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Window::default_callback(class Fl_Window * , void * v) */
/* SKIPPED (argument #2) */
/* void Fl::set_boxtype(Fl_Boxtype , Fl_Boxtype from) */
int lua_call1_Fl__set_boxtype(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     Fl_Boxtype __1__;
     Fl_Boxtype from;
    
    __1__ = ( Fl_Boxtype )(Fl_Boxtype)(int)lua_tonumber(__S__, 1);
    from = ( Fl_Boxtype )(Fl_Boxtype)(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    Fl::set_boxtype(__1__, from);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::set_boxtype(Fl_Boxtype , Fl_Box_Draw_F * , uchar , uchar , uchar , uchar ) */
/* SKIPPED (argument #2) */
/* const struct Fl_Menu_Item * Fl_Menu_::picked(const struct Fl_Menu_Item * ) */
int lua_call1_Fl_Menu___picked(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Menu_ * __self__;
     struct Fl_Menu_Item * __2__;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    __2__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Menu_Item(__S__, __self__->picked(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Nice_Slider::Fl_Nice_Slider(int x, int y, int w, int h, const char * l=0) */
int lua_call1_Fl_Nice_Slider__Fl_Nice_Slider(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Nice_Slider(__S__, new Fl_Nice_Slider(x, y, w, h));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Nice_Slider(__S__, new Fl_Nice_Slider(x, y, w, h, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const char * fl_local_to_mac_roman(const char * , int n=-1) */
int lua_call1_fl_local_to_mac_roman(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * __1__;
     int n;
    
    __1__ = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    if (nparam <= 1) {
      lua_settop(__S__, 0);
      lua_pushstring(__S__, (const char * ) fl_local_to_mac_roman(__1__));
      return 1;
    } else {
      n = ( int )(int)lua_tonumber(__S__, 2);
      lua_settop(__S__, 0);
      lua_pushstring(__S__, (const char * ) fl_local_to_mac_roman(__1__, n));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Radio_Round_Button::Fl_Radio_Round_Button(int x, int y, int w, int h, const char * l=0) */
int lua_call1_Fl_Radio_Round_Button__Fl_Radio_Round_Button(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Radio_Round_Button(__S__, new Fl_Radio_Round_Button(x, y, w, h));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Radio_Round_Button(__S__, new Fl_Radio_Round_Button(x, y, w, h, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* uchar Fl_Widget::type()const  */
int lua_call1_Fl_Widget__type(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->type());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::type(uchar t) */
int lua_call2_Fl_Widget__type(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Widget * __self__;
     unsigned char t;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    t = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->type(t);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Widget__type(__S__);
}
/* void Fl_File_Icon::load_system_icons() */
int lua_call1_Fl_File_Icon__load_system_icons(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    Fl_File_Icon::load_system_icons();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_rotate(double d) */
int lua_call1_fl_rotate(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     double d;
    
    d = ( double )(double)lua_tonumber(__S__, 1);
    
    /* Actual call */
    fl_rotate(d);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Input::Fl_Input(int , int , int , int , const char * =0) */
int lua_call1_Fl_Input__Fl_Input(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int __1__;
     int __2__;
     int __3__;
     int __4__;
     char * __5__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Input(__S__, new Fl_Input(__1__, __2__, __3__, __4__));
      return 1;
    } else {
      __5__ = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Input(__S__, new Fl_Input(__1__, __2__, __3__, __4__, __5__));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_::remove(int ) */
int lua_call1_Fl_Menu___remove(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Menu_ * __self__;
     int __2__;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->remove(__2__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Timer::handle(int ) */
int lua_call1_Fl_Timer__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Timer * __self__;
     int __2__;
    
    __self__ = ( class Fl_Timer * )lua_to_Fl_Timer(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const char * Fl_Menu_::text()const  */
int lua_call1_Fl_Menu___text(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Menu_ * __self__;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->text());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const char * Fl_Menu_::text(int i)const  */
int lua_call2_Fl_Menu___text(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Menu_ * __self__;
     int i;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    i = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->text(i));
    return 1;
  }
  
error:
  return lua_call1_Fl_Menu___text(__S__);
}
/* char * Fl_Text_Buffer::text_in_rectangle(int start, int end, int rectStart, int rectEnd) */
int lua_call1_Fl_Text_Buffer__text_in_rectangle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Text_Buffer * __self__;
     int start;
     int end;
     int rectStart;
     int rectEnd;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    start = ( int )(int)lua_tonumber(__S__, 2);
    end = ( int )(int)lua_tonumber(__S__, 3);
    rectStart = ( int )(int)lua_tonumber(__S__, 4);
    rectEnd = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->text_in_rectangle(start, end, rectStart, rectEnd));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Group::init_sizes() */
int lua_call1_Fl_Group__init_sizes(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Group * __self__;
    
    __self__ = ( class Fl_Group * )lua_to_Fl_Group(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->init_sizes();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_Item::check() */
int lua_call1_Fl_Menu_Item__check(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->check();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Buffer::tab_distance() */
int lua_call1_Fl_Text_Buffer__tab_distance(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Buffer * __self__;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->tab_distance());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Buffer::tab_distance(int tabDist) */
int lua_call2_Fl_Text_Buffer__tab_distance(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Buffer * __self__;
     int tabDist;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    tabDist = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->tab_distance(tabDist);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Text_Buffer__tab_distance(__S__);
}
/*  Fl_murgaLuaTimer::Fl_murgaLuaTimer(int X, int Y, int W, int H, const char * l) */
int lua_call1_Fl_murgaLuaTimer__Fl_murgaLuaTimer(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 5) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     char * l;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    l = ( char * )(char  *)lua_tostring(__S__, 5);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_murgaLuaTimer(__S__, new Fl_murgaLuaTimer(X, Y, W, H, l));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::box_dh(Fl_Boxtype ) */
int lua_call1_Fl__box_dh(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     Fl_Boxtype __1__;
    
    __1__ = ( Fl_Boxtype )(Fl_Boxtype)(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::box_dh(__1__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Pixmap::uncache() */
int lua_call1_Fl_Pixmap__uncache(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Pixmap * __self__;
    
    __self__ = ( class Fl_Pixmap * )lua_to_Fl_Pixmap(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->uncache();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_::replace(int , const char * ) */
int lua_call1_Fl_Menu___replace(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Menu_ * __self__;
     int __2__;
     char * __3__;
    
    __self__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( char * )(char  *)lua_tostring(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->replace(__2__, __3__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* char Fl_Preferences::set(const char * entry, const char * value) */
int lua_call1_Fl_Preferences__set(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Preferences * __self__;
     char * entry;
     char * value;
    
    __self__ = ( class Fl_Preferences * )lua_to_Fl_Preferences(__S__, 1, &__ERROR__);
    entry = ( char * )(char  *)lua_tostring(__S__, 2);
    value = ( char * )(char  *)lua_tostring(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->set(entry, value));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* char Fl_Preferences::set(const char * entry, double value) */
int lua_call2_Fl_Preferences__set(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Preferences * __self__;
     char * entry;
     double value;
    
    __self__ = ( class Fl_Preferences * )lua_to_Fl_Preferences(__S__, 1, &__ERROR__);
    entry = ( char * )(char  *)lua_tostring(__S__, 2);
    value = ( double )(double)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->set(entry, value));
    return 1;
  }
  
error:
  return lua_call1_Fl_Preferences__set(__S__);
}
/* char Fl_Preferences::set(const char * entry, float value) */
int lua_call3_Fl_Preferences__set(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Preferences * __self__;
     char * entry;
     float value;
    
    __self__ = ( class Fl_Preferences * )lua_to_Fl_Preferences(__S__, 1, &__ERROR__);
    entry = ( char * )(char  *)lua_tostring(__S__, 2);
    value = ( float )(float)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->set(entry, value));
    return 1;
  }
  
error:
  return lua_call2_Fl_Preferences__set(__S__);
}
/* char Fl_Preferences::set(const char * entry, int value) */
int lua_call4_Fl_Preferences__set(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Preferences * __self__;
     char * entry;
     int value;
    
    __self__ = ( class Fl_Preferences * )lua_to_Fl_Preferences(__S__, 1, &__ERROR__);
    entry = ( char * )(char  *)lua_tostring(__S__, 2);
    value = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->set(entry, value));
    return 1;
  }
  
error:
  return lua_call3_Fl_Preferences__set(__S__);
}
/* char Fl_Preferences::set(const char * entry, float value, int precision) */
int lua_call5_Fl_Preferences__set(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 4) goto error;
  {
     class Fl_Preferences * __self__;
     char * entry;
     float value;
     int precision;
    
    __self__ = ( class Fl_Preferences * )lua_to_Fl_Preferences(__S__, 1, &__ERROR__);
    entry = ( char * )(char  *)lua_tostring(__S__, 2);
    value = ( float )(float)lua_tonumber(__S__, 3);
    precision = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->set(entry, value, precision));
    return 1;
  }
  
error:
  return lua_call4_Fl_Preferences__set(__S__);
}
/* char Fl_Preferences::set(const char * entry, const void * value, int size) */
/* SKIPPED (argument #3) */
/* char Fl_Preferences::set(const char * entry, double value, int precision) */
int lua_call7_Fl_Preferences__set(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 4) goto error;
  {
     class Fl_Preferences * __self__;
     char * entry;
     double value;
     int precision;
    
    __self__ = ( class Fl_Preferences * )lua_to_Fl_Preferences(__S__, 1, &__ERROR__);
    entry = ( char * )(char  *)lua_tostring(__S__, 2);
    value = ( double )(double)lua_tonumber(__S__, 3);
    precision = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->set(entry, value, precision));
    return 1;
  }
  
error:
  return lua_call5_Fl_Preferences__set(__S__);
}
/* Fl_Align Fl_Widget::align()const  */
int lua_call1_Fl_Widget__align(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->align());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::align(uchar a) */
int lua_call2_Fl_Widget__align(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Widget * __self__;
     unsigned char a;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    a = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->align(a);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Widget__align(__S__);
}
/* void Fl_Widget::clear_visible_focus() */
int lua_call1_Fl_Widget__clear_visible_focus(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->clear_visible_focus();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Menu_::Fl_Menu_(int , int , int , int , const char * =0) */
/* SKIPPED (pure virtual class) */
/* void Fl_Group::clear() */
int lua_call1_Fl_Group__clear(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Group * __self__;
    
    __self__ = ( class Fl_Group * )lua_to_Fl_Group(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->clear();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* float Fl_Progress::maximum()const  */
int lua_call1_Fl_Progress__maximum(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Progress * __self__;
    
    __self__ = ( class Fl_Progress * )lua_to_Fl_Progress(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->maximum());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Progress::maximum(float v) */
int lua_call2_Fl_Progress__maximum(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Progress * __self__;
     float v;
    
    __self__ = ( class Fl_Progress * )lua_to_Fl_Progress(__S__, 1, &__ERROR__);
    v = ( float )(float)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->maximum(v);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Progress__maximum(__S__);
}
/* void Fl::remove_idle(void ( * cb)(void * ), void * =0) */
/* SKIPPED (argument #1) */
/* int Fl_Help_Dialog::w() */
int lua_call1_Fl_Help_Dialog__w(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Help_Dialog * __self__;
    
    __self__ = ( class Fl_Help_Dialog * )lua_to_Fl_Help_Dialog(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->w());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* uchar Fl_File_Browser::textsize()const  */
int lua_call1_Fl_File_Browser__textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Browser * __self__;
    
    __self__ = ( class Fl_File_Browser * )lua_to_Fl_File_Browser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textsize());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_File_Browser::textsize(uchar s) */
int lua_call2_Fl_File_Browser__textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_File_Browser * __self__;
     unsigned char s;
    
    __self__ = ( class Fl_File_Browser * )lua_to_Fl_File_Browser(__S__, 1, &__ERROR__);
    s = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textsize(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_File_Browser__textsize(__S__);
}
/* double Fl_Color_Chooser::hue()const  */
int lua_call1_Fl_Color_Chooser__hue(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Color_Chooser * __self__;
    
    __self__ = ( class Fl_Color_Chooser * )lua_to_Fl_Color_Chooser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->hue());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Editor::kf_c_s_move(int c, class Fl_Text_Editor * e) */
int lua_call1_Fl_Text_Editor__kf_c_s_move(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int c;
     class Fl_Text_Editor * e;
    
    c = ( int )(int)lua_tonumber(__S__, 1);
    e = ( class Fl_Text_Editor * )lua_to_Fl_Text_Editor(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Text_Editor::kf_c_s_move(c, e));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* uchar Fl_File_Browser::iconsize()const  */
int lua_call1_Fl_File_Browser__iconsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Browser * __self__;
    
    __self__ = ( class Fl_File_Browser * )lua_to_Fl_File_Browser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->iconsize());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_File_Browser::iconsize(uchar s) */
int lua_call2_Fl_File_Browser__iconsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_File_Browser * __self__;
     unsigned char s;
    
    __self__ = ( class Fl_File_Browser * )lua_to_Fl_File_Browser(__S__, 1, &__ERROR__);
    s = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->iconsize(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_File_Browser__iconsize(__S__);
}
/* const char * Fl_File_Browser::filter()const  */
int lua_call1_Fl_File_Browser__filter(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Browser * __self__;
    
    __self__ = ( class Fl_File_Browser * )lua_to_Fl_File_Browser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->filter());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_File_Browser::filter(const char * pattern) */
int lua_call2_Fl_File_Browser__filter(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_File_Browser * __self__;
     char * pattern;
    
    __self__ = ( class Fl_File_Browser * )lua_to_Fl_File_Browser(__S__, 1, &__ERROR__);
    pattern = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->filter(pattern);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_File_Browser__filter(__S__);
}
/* void Fl_Image::draw(int X, int Y) */
int lua_call1_Fl_Image__draw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Image * __self__;
     int X;
     int Y;
    
    __self__ = ( class Fl_Image * )lua_to_Fl_Image(__S__, 1, &__ERROR__);
    X = ( int )(int)lua_tonumber(__S__, 2);
    Y = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->draw(X, Y);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Image::draw(int X, int Y, int W, int H, int cx=0, int cy=0) */
int lua_call2_Fl_Image__draw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Image * __self__;
     int X;
     int Y;
     int W;
     int H;
     int cx;
     int cy;
    
    __self__ = ( class Fl_Image * )lua_to_Fl_Image(__S__, 1, &__ERROR__);
    X = ( int )(int)lua_tonumber(__S__, 2);
    Y = ( int )(int)lua_tonumber(__S__, 3);
    W = ( int )(int)lua_tonumber(__S__, 4);
    H = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (nparam <= 5) {
      if (__ERROR__) goto error;
      
      __self__->draw(X, Y, W, H);
    } else {
      cx = ( int )(int)lua_tonumber(__S__, 6);
      if (nparam <= 6) {
        if (__ERROR__) goto error;
        
        __self__->draw(X, Y, W, H, cx);
      } else {
        cy = ( int )(int)lua_tonumber(__S__, 7);
        if (__ERROR__) goto error;
        
        __self__->draw(X, Y, W, H, cx, cy);
      }
    }
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Image__draw(__S__);
}
/* int Fl_Menu_Button::handle(int ) */
int lua_call1_Fl_Menu_Button__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Menu_Button * __self__;
     int __2__;
    
    __self__ = ( class Fl_Menu_Button * )lua_to_Fl_Menu_Button(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Image::color_average(Fl_Color c, float i) */
int lua_call1_Fl_Image__color_average(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Image * __self__;
     Fl_Color c;
     float i;
    
    __self__ = ( class Fl_Image * )lua_to_Fl_Image(__S__, 1, &__ERROR__);
    c = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 2);
    i = ( float )(float)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->color_average(c, i);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Tile::resize(int , int , int , int ) */
int lua_call1_Fl_Tile__resize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Tile * __self__;
     int __2__;
     int __3__;
     int __4__;
     int __5__;
    
    __self__ = ( class Fl_Tile * )lua_to_Fl_Tile(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    __5__ = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->resize(__2__, __3__, __4__, __5__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* uchar Fl_Input_::textsize()const  */
int lua_call1_Fl_Input___textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Input_ * __self__;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textsize());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Input_::textsize(uchar s) */
int lua_call2_Fl_Input___textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Input_ * __self__;
     unsigned char s;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    s = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textsize(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Input___textsize(__S__);
}
/* int Fl_Scrollbar::linesize()const  */
int lua_call1_Fl_Scrollbar__linesize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Scrollbar * __self__;
    
    __self__ = ( class Fl_Scrollbar * )lua_to_Fl_Scrollbar(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->linesize());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Scrollbar::linesize(int i) */
int lua_call2_Fl_Scrollbar__linesize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Scrollbar * __self__;
     int i;
    
    __self__ = ( class Fl_Scrollbar * )lua_to_Fl_Scrollbar(__S__, 1, &__ERROR__);
    i = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->linesize(i);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Scrollbar__linesize(__S__);
}
/* int Fl_Menu_Item::submenu()const  */
int lua_call1_Fl_Menu_Item__submenu(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->submenu());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Slider::handle(int ) */
int lua_call1_Fl_Slider__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Slider * __self__;
     int __2__;
    
    __self__ = ( class Fl_Slider * )lua_to_Fl_Slider(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Widget * Fl::selection_owner() */
int lua_call1_Fl__selection_owner(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_Widget(__S__, Fl::selection_owner());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::selection_owner(class Fl_Widget * ) */
int lua_call2_Fl__selection_owner(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __1__;
    
    __1__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    Fl::selection_owner(__1__);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl__selection_owner(__S__);
}
/* int Fl_Widget::test_shortcut() */
int lua_call1_Fl_Widget__test_shortcut(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->test_shortcut());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Widget::test_shortcut(const char * ) */
int lua_call2_Fl_Widget__test_shortcut(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * __1__;
    
    __1__ = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Widget::test_shortcut(__1__));
    return 1;
  }
  
error:
  return lua_call1_Fl_Widget__test_shortcut(__S__);
}
/* double Fl_Valuator::value()const  */
int lua_call1_Fl_Valuator__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Valuator * __self__;
    
    __self__ = ( class Fl_Valuator * )lua_to_Fl_Valuator(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->value());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Valuator::value(double ) */
int lua_call2_Fl_Valuator__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Valuator * __self__;
     double __2__;
    
    __self__ = ( class Fl_Valuator * )lua_to_Fl_Valuator(__S__, 1, &__ERROR__);
    __2__ = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->value(__2__));
    return 1;
  }
  
error:
  return lua_call1_Fl_Valuator__value(__S__);
}
/* void Fl_Slider::bounds(double a, double b) */
int lua_call1_Fl_Slider__bounds(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Slider * __self__;
     double a;
     double b;
    
    __self__ = ( class Fl_Slider * )lua_to_Fl_Slider(__S__, 1, &__ERROR__);
    a = ( double )(double)lua_tonumber(__S__, 2);
    b = ( double )(double)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->bounds(a, b);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Color_Chooser::hsv(double , double , double ) */
int lua_call1_Fl_Color_Chooser__hsv(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 4) goto error;
  {
     class Fl_Color_Chooser * __self__;
     double __2__;
     double __3__;
     double __4__;
    
    __self__ = ( class Fl_Color_Chooser * )lua_to_Fl_Color_Chooser(__S__, 1, &__ERROR__);
    __2__ = ( double )(double)lua_tonumber(__S__, 2);
    __3__ = ( double )(double)lua_tonumber(__S__, 3);
    __4__ = ( double )(double)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->hsv(__2__, __3__, __4__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Label::draw(int , int , int , int , Fl_Align )const  */
int lua_call1_Fl_Label__draw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 6) goto error;
  {
     struct Fl_Label * __self__;
     int __2__;
     int __3__;
     int __4__;
     int __5__;
     Fl_Align __6__;
    
    __self__ = ( struct Fl_Label * )lua_to_Fl_Label(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    __5__ = ( int )(int)lua_tonumber(__S__, 5);
    __6__ = ( Fl_Align )(Fl_Align)(int)lua_tonumber(__S__, 6);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->draw(__2__, __3__, __4__, __5__, __6__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color Fl_Text_Display::cursor_color()const  */
int lua_call1_Fl_Text_Display__cursor_color(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Display * __self__;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->cursor_color());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Display::cursor_color(Fl_Color n) */
int lua_call2_Fl_Text_Display__cursor_color(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Display * __self__;
     Fl_Color n;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    n = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->cursor_color(n);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Text_Display__cursor_color(__S__);
}
/* void Fl_Text_Buffer::select_rectangular(int start, int end, int rectStart, int rectEnd) */
int lua_call1_Fl_Text_Buffer__select_rectangular(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Text_Buffer * __self__;
     int start;
     int end;
     int rectStart;
     int rectEnd;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    start = ( int )(int)lua_tonumber(__S__, 2);
    end = ( int )(int)lua_tonumber(__S__, 3);
    rectStart = ( int )(int)lua_tonumber(__S__, 4);
    rectEnd = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->select_rectangular(start, end, rectStart, rectEnd);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_RGB_Image::desaturate() */
int lua_call1_Fl_RGB_Image__desaturate(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_RGB_Image * __self__;
    
    __self__ = ( class Fl_RGB_Image * )lua_to_Fl_RGB_Image(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->desaturate();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Browser_::select(void * , int =1, int docallbacks=0) */
/* SKIPPED (argument #2) */
/* int Fl_Text_Buffer::rewind_lines(int startPos, int nLines) */
int lua_call1_Fl_Text_Buffer__rewind_lines(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Text_Buffer * __self__;
     int startPos;
     int nLines;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    startPos = ( int )(int)lua_tonumber(__S__, 2);
    nLines = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->rewind_lines(startPos, nLines));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Check_Browser::checked(int item)const  */
int lua_call1_Fl_Check_Browser__checked(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Check_Browser * __self__;
     int item;
    
    __self__ = ( class Fl_Check_Browser * )lua_to_Fl_Check_Browser(__S__, 1, &__ERROR__);
    item = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->checked(item));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Check_Browser::checked(int item, int b) */
int lua_call2_Fl_Check_Browser__checked(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Check_Browser * __self__;
     int item;
     int b;
    
    __self__ = ( class Fl_Check_Browser * )lua_to_Fl_Check_Browser(__S__, 1, &__ERROR__);
    item = ( int )(int)lua_tonumber(__S__, 2);
    b = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->checked(item, b);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Check_Browser__checked(__S__);
}
/* void Fl_Widget::clear_visible() */
int lua_call1_Fl_Widget__clear_visible(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->clear_visible();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Image * Fl_Widget::image() */
int lua_call1_Fl_Widget__image(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Image(__S__, __self__->image());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::image(class Fl_Image * a) */
int lua_call2_Fl_Widget__image(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Widget * __self__;
     class Fl_Image * a;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    a = ( class Fl_Image * )lua_to_Fl_Image(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->image(a);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Widget__image(__S__);
}
/* void Fl_Widget::image(class Fl_Image & a) */
int lua_call3_Fl_Widget__image(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
     class Fl_Image & a = ( class Fl_Image & )(*lua_to_Fl_Image(__S__, 2, &__ERROR__));
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->image(a);
    ;
    return 0;
  }
  
error:
  return lua_call2_Fl_Widget__image(__S__);
}
/* void Fl_Menu_Item::draw(int x, int y, int w, int h, const class Fl_Menu_ * , int t=0)const  */
int lua_call1_Fl_Menu_Item__draw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 6) goto error;
  {
     struct Fl_Menu_Item * __self__;
     int x;
     int y;
     int w;
     int h;
     class Fl_Menu_ * __6__;
     int t;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    x = ( int )(int)lua_tonumber(__S__, 2);
    y = ( int )(int)lua_tonumber(__S__, 3);
    w = ( int )(int)lua_tonumber(__S__, 4);
    h = ( int )(int)lua_tonumber(__S__, 5);
    __6__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 6, &__ERROR__);
    
    /* Actual call */
    if (nparam <= 6) {
      if (__ERROR__) goto error;
      
      __self__->draw(x, y, w, h, __6__);
    } else {
      t = ( int )(int)lua_tonumber(__S__, 7);
      if (__ERROR__) goto error;
      
      __self__->draw(x, y, w, h, __6__, t);
    }
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Positioner::ybounds(double , double ) */
int lua_call1_Fl_Positioner__ybounds(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Positioner * __self__;
     double __2__;
     double __3__;
    
    __self__ = ( class Fl_Positioner * )lua_to_Fl_Positioner(__S__, 1, &__ERROR__);
    __2__ = ( double )(double)lua_tonumber(__S__, 2);
    __3__ = ( double )(double)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->ybounds(__2__, __3__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Boxtype fl_define_FL_ROUND_UP_BOX() */
int lua_call1_fl_define_FL_ROUND_UP_BOX(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_define_FL_ROUND_UP_BOX());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* float Fl_Slider::slider_size()const  */
int lua_call1_Fl_Slider__slider_size(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Slider * __self__;
    
    __self__ = ( class Fl_Slider * )lua_to_Fl_Slider(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->slider_size());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Slider::slider_size(double v) */
int lua_call2_Fl_Slider__slider_size(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Slider * __self__;
     double v;
    
    __self__ = ( class Fl_Slider * )lua_to_Fl_Slider(__S__, 1, &__ERROR__);
    v = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->slider_size(v);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Slider__slider_size(__S__);
}
/* int Fl::test_shortcut(int ) */
int lua_call1_Fl__test_shortcut(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     int __1__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::test_shortcut(__1__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Selection::rect_end() */
int lua_call1_Fl_Text_Selection__rect_end(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Selection * __self__;
    
    __self__ = ( class Fl_Text_Selection * )lua_to_Fl_Text_Selection(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->rect_end());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser_::display(void * ) */
/* SKIPPED (argument #2) */
/* int Fl_Widget::visible_r()const  */
int lua_call1_Fl_Widget__visible_r(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->visible_r());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Font Fl_Menu_Item::labelfont()const  */
int lua_call1_Fl_Menu_Item__labelfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->labelfont());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_Item::labelfont(uchar a) */
int lua_call2_Fl_Menu_Item__labelfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     struct Fl_Menu_Item * __self__;
     unsigned char a;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    a = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->labelfont(a);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Menu_Item__labelfont(__S__);
}
/* double Fl_Valuator::minimum()const  */
int lua_call1_Fl_Valuator__minimum(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Valuator * __self__;
    
    __self__ = ( class Fl_Valuator * )lua_to_Fl_Valuator(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->minimum());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Valuator::minimum(double a) */
int lua_call2_Fl_Valuator__minimum(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Valuator * __self__;
     double a;
    
    __self__ = ( class Fl_Valuator * )lua_to_Fl_Valuator(__S__, 1, &__ERROR__);
    a = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->minimum(a);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Valuator__minimum(__S__);
}
/* uchar Fl_Widget::damage()const  */
int lua_call1_Fl_Widget__damage(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->damage());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::damage(uchar c) */
int lua_call2_Fl_Widget__damage(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Widget * __self__;
     unsigned char c;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    c = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->damage(c);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Widget__damage(__S__);
}
/* void Fl_Widget::damage(uchar c, int , int , int , int ) */
int lua_call3_Fl_Widget__damage(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 6) goto error;
  {
     class Fl_Widget * __self__;
     unsigned char c;
     int __3__;
     int __4__;
     int __5__;
     int __6__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    c = ( unsigned char )(char)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    __5__ = ( int )(int)lua_tonumber(__S__, 5);
    __6__ = ( int )(int)lua_tonumber(__S__, 6);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->damage(c, __3__, __4__, __5__, __6__);
    ;
    return 0;
  }
  
error:
  return lua_call2_Fl_Widget__damage(__S__);
}
/* void Fl_Overlay_Window::hide() */
int lua_call1_Fl_Overlay_Window__hide(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Overlay_Window * __self__;
    
    __self__ = ( class Fl_Overlay_Window * )lua_to_Fl_Overlay_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->hide();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* short Fl_Dial::angle1()const  */
int lua_call1_Fl_Dial__angle1(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Dial * __self__;
    
    __self__ = ( class Fl_Dial * )lua_to_Fl_Dial(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->angle1());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Dial::angle1(short a) */
int lua_call2_Fl_Dial__angle1(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Dial * __self__;
     short a;
    
    __self__ = ( class Fl_Dial * )lua_to_Fl_Dial(__S__, 1, &__ERROR__);
    a = ( short )(short)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->angle1(a);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Dial__angle1(__S__);
}
/* int Fl::scrollbar_size() */
int lua_call1_Fl__scrollbar_size(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::scrollbar_size());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::scrollbar_size(int W) */
int lua_call2_Fl__scrollbar_size(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     int W;
    
    W = ( int )(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    Fl::scrollbar_size(W);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl__scrollbar_size(__S__);
}
/* const char * Fl_Spinner::format() */
int lua_call1_Fl_Spinner__format(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Spinner * __self__;
    
    __self__ = ( class Fl_Spinner * )lua_to_Fl_Spinner(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->format());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Spinner::format(const char * f) */
int lua_call2_Fl_Spinner__format(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Spinner * __self__;
     char * f;
    
    __self__ = ( class Fl_Spinner * )lua_to_Fl_Spinner(__S__, 1, &__ERROR__);
    f = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->format(f);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Spinner__format(__S__);
}
/* int Fl_Input_::insert(const char * t, int l=0) */
int lua_call1_Fl_Input___insert(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Input_ * __self__;
     char * t;
     int l;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    t = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (nparam <= 2) {
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, __self__->insert(t));
      return 1;
    } else {
      l = ( int )(int)lua_tonumber(__S__, 3);
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_pushnumber(__S__, __self__->insert(t, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Input_::mark()const  */
int lua_call1_Fl_Input___mark(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Input_ * __self__;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->mark());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Input_::mark(int m) */
int lua_call2_Fl_Input___mark(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Input_ * __self__;
     int m;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    m = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->mark(m));
    return 1;
  }
  
error:
  return lua_call1_Fl_Input___mark(__S__);
}
/* double Fl_Valuator::clamp(double ) */
int lua_call1_Fl_Valuator__clamp(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Valuator * __self__;
     double __2__;
    
    __self__ = ( class Fl_Valuator * )lua_to_Fl_Valuator(__S__, 1, &__ERROR__);
    __2__ = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->clamp(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_JPEG_Image::Fl_JPEG_Image(const char * filename) */
int lua_call1_Fl_JPEG_Image__Fl_JPEG_Image(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * filename;
    
    filename = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_JPEG_Image(__S__, new Fl_JPEG_Image(filename));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Font Fl_Browser_::textfont()const  */
int lua_call1_Fl_Browser___textfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Browser_ * __self__;
    
    __self__ = ( class Fl_Browser_ * )lua_to_Fl_Browser_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textfont());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser_::textfont(uchar s) */
int lua_call2_Fl_Browser___textfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Browser_ * __self__;
     unsigned char s;
    
    __self__ = ( class Fl_Browser_ * )lua_to_Fl_Browser_(__S__, 1, &__ERROR__);
    s = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textfont(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Browser___textfont(__S__);
}
/* double Fl_Valuator::step()const  */
int lua_call1_Fl_Valuator__step(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Valuator * __self__;
    
    __self__ = ( class Fl_Valuator * )lua_to_Fl_Valuator(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->step());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Valuator::step(int a) */
int lua_call2_Fl_Valuator__step(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Valuator * __self__;
     int a;
    
    __self__ = ( class Fl_Valuator * )lua_to_Fl_Valuator(__S__, 1, &__ERROR__);
    a = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->step(a);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Valuator__step(__S__);
}
/* void Fl_Valuator::step(double s) */
int lua_call3_Fl_Valuator__step(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Valuator * __self__;
     double s;
    
    __self__ = ( class Fl_Valuator * )lua_to_Fl_Valuator(__S__, 1, &__ERROR__);
    s = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->step(s);
    ;
    return 0;
  }
  
error:
  return lua_call2_Fl_Valuator__step(__S__);
}
/* void Fl_Valuator::step(double a, int b) */
int lua_call4_Fl_Valuator__step(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Valuator * __self__;
     double a;
     int b;
    
    __self__ = ( class Fl_Valuator * )lua_to_Fl_Valuator(__S__, 1, &__ERROR__);
    a = ( double )(double)lua_tonumber(__S__, 2);
    b = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->step(a, b);
    ;
    return 0;
  }
  
error:
  return lua_call3_Fl_Valuator__step(__S__);
}
/* uchar Fl_Pack::horizontal()const  */
int lua_call1_Fl_Pack__horizontal(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Pack * __self__;
    
    __self__ = ( class Fl_Pack * )lua_to_Fl_Pack(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->horizontal());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_RGB_Image * Fl_murgaLuaOffScreen::getOffScreenImage() */
int lua_call1_Fl_murgaLuaOffScreen__getOffScreenImage(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_murgaLuaOffScreen * __self__;
    
    __self__ = ( class Fl_murgaLuaOffScreen * )lua_to_Fl_murgaLuaOffScreen(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_RGB_Image(__S__, __self__->getOffScreenImage());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Editor::remove_key_binding(int key, int state) */
int lua_call1_Fl_Text_Editor__remove_key_binding(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Text_Editor * __self__;
     int key;
     int state;
    
    __self__ = ( class Fl_Text_Editor * )lua_to_Fl_Text_Editor(__S__, 1, &__ERROR__);
    key = ( int )(int)lua_tonumber(__S__, 2);
    state = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->remove_key_binding(key, state);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Editor::remove_key_binding(int key, int state, struct Fl_Text_Editor::Key_Binding * * list) */
/* SKIPPED (argument #4) */
/* int Fl::event_y() */
int lua_call1_Fl__event_y(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::event_y());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Selection::position(int * start, int * end) */
/* SKIPPED (argument #2) */
/* int Fl_Text_Selection::position(int * start, int * end, int * isRect, int * rectStart, int * rectEnd) */
/* SKIPPED (argument #2) */
/* void Fl::copy(const char * stuff, int len, int clipboard=0) */
int lua_call1_Fl__copy(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     char * stuff;
     int len;
     int clipboard;
    
    stuff = ( char * )(char  *)lua_tostring(__S__, 1);
    len = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (nparam <= 2) {
      Fl::copy(stuff, len);
    } else {
      clipboard = ( int )(int)lua_tonumber(__S__, 3);
      Fl::copy(stuff, len, clipboard);
    }
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Buffer::skip_displayed_characters(int lineStartPos, int nChars) */
int lua_call1_Fl_Text_Buffer__skip_displayed_characters(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Text_Buffer * __self__;
     int lineStartPos;
     int nChars;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    lineStartPos = ( int )(int)lua_tonumber(__S__, 2);
    nChars = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->skip_displayed_characters(lineStartPos, nChars));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::redraw_label() */
int lua_call1_Fl_Widget__redraw_label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->redraw_label();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Menu_Item::value()const  */
int lua_call1_Fl_Menu_Item__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->value());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Window::default_cursor(Fl_Cursor , Fl_Color =FL_BLACK, Fl_Color =FL_WHITE) */
int lua_call1_Fl_Window__default_cursor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Window * __self__;
     Fl_Cursor __2__;
     Fl_Color __3__;
     Fl_Color __4__;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    __2__ = ( Fl_Cursor )(Fl_Cursor)(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (nparam <= 2) {
      if (__ERROR__) goto error;
      
      __self__->default_cursor(__2__);
    } else {
      __3__ = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 3);
      if (nparam <= 3) {
        if (__ERROR__) goto error;
        
        __self__->default_cursor(__2__, __3__);
      } else {
        __4__ = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 4);
        if (__ERROR__) goto error;
        
        __self__->default_cursor(__2__, __3__, __4__);
      }
    }
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Menu_Item::measure(int * h, const class Fl_Menu_ * )const  */
/* SKIPPED (argument #2) */
/* const char * Fl_Menu_Item::label()const  */
int lua_call1_Fl_Menu_Item__label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->label());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_Item::label(const char * a) */
int lua_call2_Fl_Menu_Item__label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     struct Fl_Menu_Item * __self__;
     char * a;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    a = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->label(a);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Menu_Item__label(__S__);
}
/* void Fl_Menu_Item::label(Fl_Labeltype a, const char * b) */
int lua_call3_Fl_Menu_Item__label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     struct Fl_Menu_Item * __self__;
     Fl_Labeltype a;
     char * b;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    a = ( Fl_Labeltype )(Fl_Labeltype)(int)lua_tonumber(__S__, 2);
    b = ( char * )(char  *)lua_tostring(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->label(a, b);
    ;
    return 0;
  }
  
error:
  return lua_call2_Fl_Menu_Item__label(__S__);
}
/* int Fl_Window::x_root()const  */
int lua_call1_Fl_Window__x_root(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Window * __self__;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->x_root());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const struct Fl_Menu_Item * Fl_Menu_Item::popup(int X, int Y, const char * title=0, const struct Fl_Menu_Item * picked=0, const class Fl_Menu_ * =0)const  */
int lua_call1_Fl_Menu_Item__popup(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     struct Fl_Menu_Item * __self__;
     int X;
     int Y;
     char * title;
     struct Fl_Menu_Item * picked;
     class Fl_Menu_ * __6__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    X = ( int )(int)lua_tonumber(__S__, 2);
    Y = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (nparam <= 3) {
      if (__ERROR__) goto error;
      
      lua_settop(__S__, 0);
      lua_push_Fl_Menu_Item(__S__, __self__->popup(X, Y));
      return 1;
    } else {
      title = ( char * )(char  *)lua_tostring(__S__, 4);
      if (nparam <= 4) {
        if (__ERROR__) goto error;
        
        lua_settop(__S__, 0);
        lua_push_Fl_Menu_Item(__S__, __self__->popup(X, Y, title));
        return 1;
      } else {
        picked = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 5, &__ERROR__);
        if (nparam <= 5) {
          if (__ERROR__) goto error;
          
          lua_settop(__S__, 0);
          lua_push_Fl_Menu_Item(__S__, __self__->popup(X, Y, title, picked));
          return 1;
        } else {
          __6__ = ( class Fl_Menu_ * )lua_to_Fl_Menu_(__S__, 6, &__ERROR__);
          if (__ERROR__) goto error;
          
          lua_settop(__S__, 0);
          lua_push_Fl_Menu_Item(__S__, __self__->popup(X, Y, title, picked, __6__));
          return 1;
        }
      }
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Window::shown() */
int lua_call1_Fl_Window__shown(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Window * __self__;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->shown());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Help_Dialog::hide() */
int lua_call1_Fl_Help_Dialog__hide(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Help_Dialog * __self__;
    
    __self__ = ( class Fl_Help_Dialog * )lua_to_Fl_Help_Dialog(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->hide();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Button::clear() */
int lua_call1_Fl_Button__clear(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Button * __self__;
    
    __self__ = ( class Fl_Button * )lua_to_Fl_Button(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->clear());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Widget::changed()const  */
int lua_call1_Fl_Widget__changed(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->changed());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::size(int W, int H) */
int lua_call1_Fl_Widget__size(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Widget * __self__;
     int W;
     int H;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    W = ( int )(int)lua_tonumber(__S__, 2);
    H = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->size(W, H);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Editor::kf_end(int c, class Fl_Text_Editor * e) */
int lua_call1_Fl_Text_Editor__kf_end(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int c;
     class Fl_Text_Editor * e;
    
    c = ( int )(int)lua_tonumber(__S__, 1);
    e = ( class Fl_Text_Editor * )lua_to_Fl_Text_Editor(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Text_Editor::kf_end(c, e));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const char * Fl_Help_View::directory()const  */
int lua_call1_Fl_Help_View__directory(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Help_View * __self__;
    
    __self__ = ( class Fl_Help_View * )lua_to_Fl_Help_View(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->directory());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Input_::position()const  */
int lua_call1_Fl_Input___position(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Input_ * __self__;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->position());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Input_::position(int p) */
int lua_call2_Fl_Input___position(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Input_ * __self__;
     int p;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    p = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->position(p));
    return 1;
  }
  
error:
  return lua_call1_Fl_Input___position(__S__);
}
/* int Fl_Input_::position(int p, int m) */
int lua_call3_Fl_Input___position(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Input_ * __self__;
     int p;
     int m;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    p = ( int )(int)lua_tonumber(__S__, 2);
    m = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->position(p, m));
    return 1;
  }
  
error:
  return lua_call2_Fl_Input___position(__S__);
}
/* void Fl_Menu_Item::setonly() */
int lua_call1_Fl_Menu_Item__setonly(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->setonly();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Light_Button::Fl_Light_Button(int x, int y, int w, int h, const char * l=0) */
int lua_call1_Fl_Light_Button__Fl_Light_Button(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Light_Button(__S__, new Fl_Light_Button(x, y, w, h));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Light_Button(__S__, new Fl_Light_Button(x, y, w, h, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Fill_Slider::Fl_Fill_Slider(int x, int y, int w, int h, const char * l=0) */
int lua_call1_Fl_Fill_Slider__Fl_Fill_Slider(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Fill_Slider(__S__, new Fl_Fill_Slider(x, y, w, h));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Fill_Slider(__S__, new Fl_Fill_Slider(x, y, w, h, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Boxtype fl_define_FL_ROUNDED_BOX() */
int lua_call1_fl_define_FL_ROUNDED_BOX(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_define_FL_ROUNDED_BOX());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Image * Fl_Tiled_Image::image() */
int lua_call1_Fl_Tiled_Image__image(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Tiled_Image * __self__;
    
    __self__ = ( class Fl_Tiled_Image * )lua_to_Fl_Tiled_Image(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Image(__S__, __self__->image());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Menu_Item::checked()const  */
int lua_call1_Fl_Menu_Item__checked(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->checked());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::args(int , char * * ) */
/* SKIPPED (argument #2) */
/* int Fl::args(int , char * * , int & , int ( * )(int , char * * , int & )=0) */
/* SKIPPED (argument #2) */
/* void Fl_Text_Buffer::replace(int start, int end, const char * text) */
int lua_call1_Fl_Text_Buffer__replace(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 4) goto error;
  {
     class Fl_Text_Buffer * __self__;
     int start;
     int end;
     char * text;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    start = ( int )(int)lua_tonumber(__S__, 2);
    end = ( int )(int)lua_tonumber(__S__, 3);
    text = ( char * )(char  *)lua_tostring(__S__, 4);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->replace(start, end, text);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_murgaLuaTimer::draw() */
int lua_call1_Fl_murgaLuaTimer__draw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_murgaLuaTimer * __self__;
    
    __self__ = ( class Fl_murgaLuaTimer * )lua_to_Fl_murgaLuaTimer(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->draw();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::repeat_timeout(double t, Fl_Timeout_Handler , void * =0) */
/* SKIPPED (argument #2) */
/* int Fl_File_Input::handle(int ) */
int lua_call1_Fl_File_Input__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_File_Input * __self__;
     int __2__;
    
    __self__ = ( class Fl_File_Input * )lua_to_Fl_File_Input(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Display::move_left() */
int lua_call1_Fl_Text_Display__move_left(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Display * __self__;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->move_left());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Repeat_Button::deactivate() */
int lua_call1_Fl_Repeat_Button__deactivate(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Repeat_Button * __self__;
    
    __self__ = ( class Fl_Repeat_Button * )lua_to_Fl_Repeat_Button(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->deactivate();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Browser::load(const char * filename) */
int lua_call1_Fl_Browser__load(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Browser * __self__;
     char * filename;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    filename = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->load(filename));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_Item::clear() */
int lua_call1_Fl_Menu_Item__clear(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->clear();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Help_View::link(Fl_Help_Func * fn) */
/* SKIPPED (argument #2) */
/* void Fl::remove_handler(int ( * h)(int )) */
/* SKIPPED (argument #1) */
/* void Fl::display(const char * ) */
int lua_call1_Fl__display(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * __1__;
    
    __1__ = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    Fl::display(__1__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Positioner::Fl_Positioner(int x, int y, int w, int h, const char * l=0) */
int lua_call1_Fl_Positioner__Fl_Positioner(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Positioner(__S__, new Fl_Positioner(x, y, w, h));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Positioner(__S__, new Fl_Positioner(x, y, w, h, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Positioner::xstep(double a) */
int lua_call1_Fl_Positioner__xstep(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Positioner * __self__;
     double a;
    
    __self__ = ( class Fl_Positioner * )lua_to_Fl_Positioner(__S__, 1, &__ERROR__);
    a = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->xstep(a);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Button::set() */
int lua_call1_Fl_Button__set(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Button * __self__;
    
    __self__ = ( class Fl_Button * )lua_to_Fl_Button(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->set());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Positioner::handle(int ) */
int lua_call1_Fl_Positioner__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Positioner * __self__;
     int __2__;
    
    __self__ = ( class Fl_Positioner * )lua_to_Fl_Positioner(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* double Fl_Color_Chooser::r()const  */
int lua_call1_Fl_Color_Chooser__r(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Color_Chooser * __self__;
    
    __self__ = ( class Fl_Color_Chooser * )lua_to_Fl_Color_Chooser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->r());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Window::set_override() */
int lua_call1_Fl_Window__set_override(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Window * __self__;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->set_override();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Window::fullscreen_off(int , int , int , int ) */
int lua_call1_Fl_Window__fullscreen_off(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Window * __self__;
     int __2__;
     int __3__;
     int __4__;
     int __5__;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    __5__ = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->fullscreen_off(__2__, __3__, __4__, __5__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Input_::maximum_size()const  */
int lua_call1_Fl_Input___maximum_size(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Input_ * __self__;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->maximum_size());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Input_::maximum_size(int m) */
int lua_call2_Fl_Input___maximum_size(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Input_ * __self__;
     int m;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    m = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->maximum_size(m);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Input___maximum_size(__S__);
}
/* short * Fl_File_Icon::add(short d) */
/* SKIPPED (return type) */
/* int fl_filename_list(const char * d, struct dirent * * * l, Fl_File_Sort_F * s=fl_numericsort) */
/* SKIPPED (argument #2) */
/* int Fl_Text_Display::skip_lines(int startPos, int nLines, bool startPosIsLineStart) */
int lua_call1_Fl_Text_Display__skip_lines(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 4) goto error;
  {
     class Fl_Text_Display * __self__;
     int startPos;
     int nLines;
     bool startPosIsLineStart;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    startPos = ( int )(int)lua_tonumber(__S__, 2);
    nLines = ( int )(int)lua_tonumber(__S__, 3);
    startPosIsLineStart = ( bool )(bool)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->skip_lines(startPos, nLines, startPosIsLineStart));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* short * Fl_File_Icon::add_color(Fl_Color c) */
/* SKIPPED (return type) */
/* void Fl_Window::copy_label(const char * a) */
int lua_call1_Fl_Window__copy_label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Window * __self__;
     char * a;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    a = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->copy_label(a);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Widget::take_focus() */
int lua_call1_Fl_Widget__take_focus(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->take_focus());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Window::resize(int , int , int , int ) */
int lua_call1_Fl_Window__resize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Window * __self__;
     int __2__;
     int __3__;
     int __4__;
     int __5__;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    __5__ = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->resize(__2__, __3__, __4__, __5__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Window::iconize() */
int lua_call1_Fl_Window__iconize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Window * __self__;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->iconize();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::event_ctrl() */
int lua_call1_Fl__event_ctrl(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::event_ctrl());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Chart::size()const  */
int lua_call1_Fl_Chart__size(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Chart * __self__;
    
    __self__ = ( class Fl_Chart * )lua_to_Fl_Chart(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->size());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Chart::size(int W, int H) */
int lua_call2_Fl_Chart__size(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Chart * __self__;
     int W;
     int H;
    
    __self__ = ( class Fl_Chart * )lua_to_Fl_Chart(__S__, 1, &__ERROR__);
    W = ( int )(int)lua_tonumber(__S__, 2);
    H = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->size(W, H);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Chart__size(__S__);
}
/* const char * Fl_Window::xclass()const  */
int lua_call1_Fl_Window__xclass(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Window * __self__;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->xclass());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Window::xclass(const char * c) */
int lua_call2_Fl_Window__xclass(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Window * __self__;
     char * c;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    c = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->xclass(c);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Window__xclass(__S__);
}
/* char Fl_Text_Selection::rectangular() */
int lua_call1_Fl_Text_Selection__rectangular(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Selection * __self__;
    
    __self__ = ( class Fl_Text_Selection * )lua_to_Fl_Text_Selection(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->rectangular());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Browser::topline()const  */
int lua_call1_Fl_Browser__topline(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Browser * __self__;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->topline());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser::topline(int l) */
int lua_call2_Fl_Browser__topline(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Browser * __self__;
     int l;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    l = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->topline(l);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Browser__topline(__S__);
}
/* void Fl_Widget::copy_label(const char * a) */
int lua_call1_Fl_Widget__copy_label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Widget * __self__;
     char * a;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    a = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->copy_label(a);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Widget * Fl_Wizard::value() */
int lua_call1_Fl_Wizard__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Wizard * __self__;
    
    __self__ = ( class Fl_Wizard * )lua_to_Fl_Wizard(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Widget(__S__, __self__->value());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Wizard::value(class Fl_Widget * ) */
int lua_call2_Fl_Wizard__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Wizard * __self__;
     class Fl_Widget * __2__;
    
    __self__ = ( class Fl_Wizard * )lua_to_Fl_Wizard(__S__, 1, &__ERROR__);
    __2__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->value(__2__);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Wizard__value(__S__);
}
/*  Fl_Hor_Slider::Fl_Hor_Slider(int X, int Y, int W, int H, const char * l=0) */
int lua_call1_Fl_Hor_Slider__Fl_Hor_Slider(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     char * l;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Hor_Slider(__S__, new Fl_Hor_Slider(X, Y, W, H));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Hor_Slider(__S__, new Fl_Hor_Slider(X, Y, W, H, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Font Fl_Counter::textfont()const  */
int lua_call1_Fl_Counter__textfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Counter * __self__;
    
    __self__ = ( class Fl_Counter * )lua_to_Fl_Counter(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textfont());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Counter::textfont(uchar s) */
int lua_call2_Fl_Counter__textfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Counter * __self__;
     unsigned char s;
    
    __self__ = ( class Fl_Counter * )lua_to_Fl_Counter(__S__, 1, &__ERROR__);
    s = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textfont(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Counter__textfont(__S__);
}
/* const char * Fl_Widget::label()const  */
int lua_call1_Fl_Widget__label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->label());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::label(const char * a) */
int lua_call2_Fl_Widget__label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Widget * __self__;
     char * a;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    a = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->label(a);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Widget__label(__S__);
}
/* void Fl_Widget::label(Fl_Labeltype a, const char * b) */
int lua_call3_Fl_Widget__label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Widget * __self__;
     Fl_Labeltype a;
     char * b;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    a = ( Fl_Labeltype )(Fl_Labeltype)(int)lua_tonumber(__S__, 2);
    b = ( char * )(char  *)lua_tostring(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->label(a, b);
    ;
    return 0;
  }
  
error:
  return lua_call2_Fl_Widget__label(__S__);
}
/* int Fl_Input_::undo() */
int lua_call1_Fl_Input___undo(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Input_ * __self__;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->undo());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Tiled_Image::color_average(Fl_Color c, float i) */
int lua_call1_Fl_Tiled_Image__color_average(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Tiled_Image * __self__;
     Fl_Color c;
     float i;
    
    __self__ = ( class Fl_Tiled_Image * )lua_to_Fl_Tiled_Image(__S__, 1, &__ERROR__);
    c = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 2);
    i = ( float )(float)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->color_average(c, i);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const char * Fl_File_Chooser::ok_label() */
int lua_call1_Fl_File_Chooser__ok_label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Chooser * __self__;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->ok_label());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_File_Chooser::ok_label(const char * l) */
int lua_call2_Fl_File_Chooser__ok_label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_File_Chooser * __self__;
     char * l;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    l = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->ok_label(l);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_File_Chooser__ok_label(__S__);
}
/* int Fl_Color_Chooser::mode() */
int lua_call1_Fl_Color_Chooser__mode(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Color_Chooser * __self__;
    
    __self__ = ( class Fl_Color_Chooser * )lua_to_Fl_Color_Chooser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->mode());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::dnd_text_ops() */
int lua_call1_Fl__dnd_text_ops(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::dnd_text_ops());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::dnd_text_ops(int v) */
int lua_call2_Fl__dnd_text_ops(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     int v;
    
    v = ( int )(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    Fl::dnd_text_ops(v);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl__dnd_text_ops(__S__);
}
/* class Fl_Bitmap * Fl_FormsBitmap::bitmap()const  */
int lua_call1_Fl_FormsBitmap__bitmap(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_FormsBitmap * __self__;
    
    __self__ = ( class Fl_FormsBitmap * )lua_to_Fl_FormsBitmap(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Bitmap(__S__, __self__->bitmap());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_FormsBitmap::bitmap(class Fl_Bitmap * B) */
int lua_call2_Fl_FormsBitmap__bitmap(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_FormsBitmap * __self__;
     class Fl_Bitmap * B;
    
    __self__ = ( class Fl_FormsBitmap * )lua_to_Fl_FormsBitmap(__S__, 1, &__ERROR__);
    B = ( class Fl_Bitmap * )lua_to_Fl_Bitmap(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->bitmap(B);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_FormsBitmap__bitmap(__S__);
}
/* void Fl_Text_Buffer::secondary_unselect() */
int lua_call1_Fl_Text_Buffer__secondary_unselect(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Buffer * __self__;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->secondary_unselect();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Chart::add(double , const char * =0, unsigned int =0) */
int lua_call1_Fl_Chart__add(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Chart * __self__;
     double __2__;
     char * __3__;
     unsigned int __4__;
    
    __self__ = ( class Fl_Chart * )lua_to_Fl_Chart(__S__, 1, &__ERROR__);
    __2__ = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (nparam <= 2) {
      if (__ERROR__) goto error;
      
      __self__->add(__2__);
    } else {
      __3__ = ( char * )(char  *)lua_tostring(__S__, 3);
      if (nparam <= 3) {
        if (__ERROR__) goto error;
        
        __self__->add(__2__, __3__);
      } else {
        __4__ = ( unsigned int )(int)lua_tonumber(__S__, 4);
        if (__ERROR__) goto error;
        
        __self__->add(__2__, __3__, __4__);
      }
    }
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Buffer::count_displayed_characters(int lineStartPos, int targetPos) */
int lua_call1_Fl_Text_Buffer__count_displayed_characters(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Text_Buffer * __self__;
     int lineStartPos;
     int targetPos;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    lineStartPos = ( int )(int)lua_tonumber(__S__, 2);
    targetPos = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->count_displayed_characters(lineStartPos, targetPos));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Chart::insert(int , double , const char * =0, unsigned int =0) */
int lua_call1_Fl_Chart__insert(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Chart * __self__;
     int __2__;
     double __3__;
     char * __4__;
     unsigned int __5__;
    
    __self__ = ( class Fl_Chart * )lua_to_Fl_Chart(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( double )(double)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (nparam <= 3) {
      if (__ERROR__) goto error;
      
      __self__->insert(__2__, __3__);
    } else {
      __4__ = ( char * )(char  *)lua_tostring(__S__, 4);
      if (nparam <= 4) {
        if (__ERROR__) goto error;
        
        __self__->insert(__2__, __3__, __4__);
      } else {
        __5__ = ( unsigned int )(int)lua_tonumber(__S__, 5);
        if (__ERROR__) goto error;
        
        __self__->insert(__2__, __3__, __4__, __5__);
      }
    }
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* float Fl_Progress::value()const  */
int lua_call1_Fl_Progress__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Progress * __self__;
    
    __self__ = ( class Fl_Progress * )lua_to_Fl_Progress(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->value());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Progress::value(float v) */
int lua_call2_Fl_Progress__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Progress * __self__;
     float v;
    
    __self__ = ( class Fl_Progress * )lua_to_Fl_Progress(__S__, 1, &__ERROR__);
    v = ( float )(float)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->value(v);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Progress__value(__S__);
}
/* void Fl_Chart::clear() */
int lua_call1_Fl_Chart__clear(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Chart * __self__;
    
    __self__ = ( class Fl_Chart * )lua_to_Fl_Chart(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->clear();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_PNM_Image::Fl_PNM_Image(const char * filename) */
int lua_call1_Fl_PNM_Image__Fl_PNM_Image(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * filename;
    
    filename = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_PNM_Image(__S__, new Fl_PNM_Image(filename));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Multiline_Input::Fl_Multiline_Input(int X, int Y, int W, int H, const char * l=0) */
int lua_call1_Fl_Multiline_Input__Fl_Multiline_Input(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     char * l;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Multiline_Input(__S__, new Fl_Multiline_Input(X, Y, W, H));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Multiline_Input(__S__, new Fl_Multiline_Input(X, Y, W, H, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_File_Browser::Fl_File_Browser(int , int , int , int , const char * =0) */
int lua_call1_Fl_File_Browser__Fl_File_Browser(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int __1__;
     int __2__;
     int __3__;
     int __4__;
     char * __5__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_File_Browser(__S__, new Fl_File_Browser(__1__, __2__, __3__, __4__));
      return 1;
    } else {
      __5__ = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_File_Browser(__S__, new Fl_File_Browser(__1__, __2__, __3__, __4__, __5__));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color Fl_Chart::textcolor()const  */
int lua_call1_Fl_Chart__textcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Chart * __self__;
    
    __self__ = ( class Fl_Chart * )lua_to_Fl_Chart(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textcolor());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Chart::textcolor(unsigned int n) */
int lua_call2_Fl_Chart__textcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Chart * __self__;
     unsigned int n;
    
    __self__ = ( class Fl_Chart * )lua_to_Fl_Chart(__S__, 1, &__ERROR__);
    n = ( unsigned int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textcolor(n);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Chart__textcolor(__S__);
}
/* uchar Fl_Chart::autosize()const  */
int lua_call1_Fl_Chart__autosize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Chart * __self__;
    
    __self__ = ( class Fl_Chart * )lua_to_Fl_Chart(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->autosize());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Chart::autosize(uchar n) */
int lua_call2_Fl_Chart__autosize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Chart * __self__;
     unsigned char n;
    
    __self__ = ( class Fl_Chart * )lua_to_Fl_Chart(__S__, 1, &__ERROR__);
    n = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->autosize(n);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Chart__autosize(__S__);
}
/* uchar Fl_Value_Output::soft()const  */
int lua_call1_Fl_Value_Output__soft(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Value_Output * __self__;
    
    __self__ = ( class Fl_Value_Output * )lua_to_Fl_Value_Output(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->soft());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Value_Output::soft(uchar s) */
int lua_call2_Fl_Value_Output__soft(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Value_Output * __self__;
     unsigned char s;
    
    __self__ = ( class Fl_Value_Output * )lua_to_Fl_Value_Output(__S__, 1, &__ERROR__);
    s = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->soft(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Value_Output__soft(__S__);
}
/* Fl_Color Fl_Value_Slider::textcolor()const  */
int lua_call1_Fl_Value_Slider__textcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Value_Slider * __self__;
    
    __self__ = ( class Fl_Value_Slider * )lua_to_Fl_Value_Slider(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textcolor());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Value_Slider::textcolor(unsigned int s) */
int lua_call2_Fl_Value_Slider__textcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Value_Slider * __self__;
     unsigned int s;
    
    __self__ = ( class Fl_Value_Slider * )lua_to_Fl_Value_Slider(__S__, 1, &__ERROR__);
    s = ( unsigned int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textcolor(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Value_Slider__textcolor(__S__);
}
/* char * Fl_Text_Buffer::highlight_text() */
int lua_call1_Fl_Text_Buffer__highlight_text(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Buffer * __self__;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->highlight_text());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const char * Fl_Help_View::filename()const  */
int lua_call1_Fl_Help_View__filename(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Help_View * __self__;
    
    __self__ = ( class Fl_Help_View * )lua_to_Fl_Help_View(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->filename());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Window::hotspot(const class Fl_Widget & p, int offscreen=0) */
int lua_call1_Fl_Window__hotspot(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Window * __self__;
     int offscreen;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
     class Fl_Widget & p = ( class Fl_Widget & )(*lua_to_Fl_Widget(__S__, 2, &__ERROR__));
    
    /* Actual call */
    if (nparam <= 2) {
      if (__ERROR__) goto error;
      
      __self__->hotspot(p);
    } else {
      offscreen = ( int )(int)lua_tonumber(__S__, 3);
      if (__ERROR__) goto error;
      
      __self__->hotspot(p, offscreen);
    }
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Window::hotspot(const class Fl_Widget * , int offscreen=0) */
int lua_call2_Fl_Window__hotspot(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Window * __self__;
     class Fl_Widget * __2__;
     int offscreen;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    __2__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (nparam <= 2) {
      if (__ERROR__) goto error;
      
      __self__->hotspot(__2__);
    } else {
      offscreen = ( int )(int)lua_tonumber(__S__, 3);
      if (__ERROR__) goto error;
      
      __self__->hotspot(__2__, offscreen);
    }
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Window__hotspot(__S__);
}
/* void Fl_Window::hotspot(int x, int y, int offscreen=0) */
int lua_call3_Fl_Window__hotspot(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Window * __self__;
     int x;
     int y;
     int offscreen;
    
    __self__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    x = ( int )(int)lua_tonumber(__S__, 2);
    y = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (nparam <= 3) {
      if (__ERROR__) goto error;
      
      __self__->hotspot(x, y);
    } else {
      offscreen = ( int )(int)lua_tonumber(__S__, 4);
      if (__ERROR__) goto error;
      
      __self__->hotspot(x, y, offscreen);
    }
    ;
    return 0;
  }
  
error:
  return lua_call2_Fl_Window__hotspot(__S__);
}
/* void Fl_Text_Display::next_word() */
int lua_call1_Fl_Text_Display__next_word(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Display * __self__;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->next_word();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Float_Input::Fl_Float_Input(int X, int Y, int W, int H, const char * l=0) */
int lua_call1_Fl_Float_Input__Fl_Float_Input(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     char * l;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Float_Input(__S__, new Fl_Float_Input(X, Y, W, H));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Float_Input(__S__, new Fl_Float_Input(X, Y, W, H, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_beep(int type=FL_BEEP_DEFAULT) */
int lua_call1_fl_beep(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  {
     int type;
    
    
    /* Actual call */
    if (nparam <= 0) {
      fl_beep();
    } else {
      type = ( int )(int)lua_tonumber(__S__, 1);
      fl_beep(type);
    }
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Menu_Window::Fl_Menu_Window(int W, int H, const char * l=0) */
int lua_call1_Fl_Menu_Window__Fl_Menu_Window(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int W;
     int H;
     char * l;
    
    W = ( int )(int)lua_tonumber(__S__, 1);
    H = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (nparam <= 2) {
      lua_settop(__S__, 0);
      lua_push_Fl_Menu_Window(__S__, new Fl_Menu_Window(W, H));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 3);
      lua_settop(__S__, 0);
      lua_push_Fl_Menu_Window(__S__, new Fl_Menu_Window(W, H, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Menu_Window::Fl_Menu_Window(int X, int Y, int W, int H, const char * l=0) */
int lua_call2_Fl_Menu_Window__Fl_Menu_Window(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     char * l;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Menu_Window(__S__, new Fl_Menu_Window(X, Y, W, H));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Menu_Window(__S__, new Fl_Menu_Window(X, Y, W, H, l));
      return 1;
    }
  }
  
error:
  return lua_call1_Fl_Menu_Window__Fl_Menu_Window(__S__);
}
/* void Fl_Help_Dialog::resize(int xx, int yy, int ww, int hh) */
int lua_call1_Fl_Help_Dialog__resize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Help_Dialog * __self__;
     int xx;
     int yy;
     int ww;
     int hh;
    
    __self__ = ( class Fl_Help_Dialog * )lua_to_Fl_Help_Dialog(__S__, 1, &__ERROR__);
    xx = ( int )(int)lua_tonumber(__S__, 2);
    yy = ( int )(int)lua_tonumber(__S__, 3);
    ww = ( int )(int)lua_tonumber(__S__, 4);
    hh = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->resize(xx, yy, ww, hh);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Preferences::size(const char * entry) */
int lua_call1_Fl_Preferences__size(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Preferences * __self__;
     char * entry;
    
    __self__ = ( class Fl_Preferences * )lua_to_Fl_Preferences(__S__, 1, &__ERROR__);
    entry = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->size(entry));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser_::resize(int , int , int , int ) */
int lua_call1_Fl_Browser___resize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Browser_ * __self__;
     int __2__;
     int __3__;
     int __4__;
     int __5__;
    
    __self__ = ( class Fl_Browser_ * )lua_to_Fl_Browser_(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    __5__ = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->resize(__2__, __3__, __4__, __5__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::position(int X, int Y) */
int lua_call1_Fl_Widget__position(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Widget * __self__;
     int X;
     int Y;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    X = ( int )(int)lua_tonumber(__S__, 2);
    Y = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->position(X, Y);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Editor::kf_cut(int c, class Fl_Text_Editor * e) */
int lua_call1_Fl_Text_Editor__kf_cut(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int c;
     class Fl_Text_Editor * e;
    
    c = ( int )(int)lua_tonumber(__S__, 1);
    e = ( class Fl_Text_Editor * )lua_to_Fl_Text_Editor(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Text_Editor::kf_cut(c, e));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* char Fl_Preferences::deleteGroup(const char * group) */
int lua_call1_Fl_Preferences__deleteGroup(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Preferences * __self__;
     char * group;
    
    __self__ = ( class Fl_Preferences * )lua_to_Fl_Preferences(__S__, 1, &__ERROR__);
    group = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->deleteGroup(group));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Image::desaturate() */
int lua_call1_Fl_Image__desaturate(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Image * __self__;
    
    __self__ = ( class Fl_Image * )lua_to_Fl_Image(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->desaturate();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color Fl_Widget::labelcolor()const  */
int lua_call1_Fl_Widget__labelcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->labelcolor());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::labelcolor(unsigned int a) */
int lua_call2_Fl_Widget__labelcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Widget * __self__;
     unsigned int a;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    a = ( unsigned int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->labelcolor(a);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Widget__labelcolor(__S__);
}
/* void Fl_Double_Window::resize(int , int , int , int ) */
int lua_call1_Fl_Double_Window__resize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Double_Window * __self__;
     int __2__;
     int __3__;
     int __4__;
     int __5__;
    
    __self__ = ( class Fl_Double_Window * )lua_to_Fl_Double_Window(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    __5__ = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->resize(__2__, __3__, __4__, __5__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::event_shift() */
int lua_call1_Fl__event_shift(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::event_shift());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Image::Fl_Image(int W, int H, int D) */
int lua_call1_Fl_Image__Fl_Image(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 3) goto error;
  {
     int W;
     int H;
     int D;
    
    W = ( int )(int)lua_tonumber(__S__, 1);
    H = ( int )(int)lua_tonumber(__S__, 2);
    D = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_Image(__S__, new Fl_Image(W, H, D));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Editor::kf_select_all(int c, class Fl_Text_Editor * e) */
int lua_call1_Fl_Text_Editor__kf_select_all(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int c;
     class Fl_Text_Editor * e;
    
    c = ( int )(int)lua_tonumber(__S__, 1);
    e = ( class Fl_Text_Editor * )lua_to_Fl_Text_Editor(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Text_Editor::kf_select_all(c, e));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* const char * Fl_Help_Dialog::value()const  */
int lua_call1_Fl_Help_Dialog__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Help_Dialog * __self__;
    
    __self__ = ( class Fl_Help_Dialog * )lua_to_Fl_Help_Dialog(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->value());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Help_Dialog::value(const char * f) */
int lua_call2_Fl_Help_Dialog__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Help_Dialog * __self__;
     char * f;
    
    __self__ = ( class Fl_Help_Dialog * )lua_to_Fl_Help_Dialog(__S__, 1, &__ERROR__);
    f = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->value(f);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Help_Dialog__value(__S__);
}
/* int Fl_Scrollbar::value() */
int lua_call1_Fl_Scrollbar__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Scrollbar * __self__;
    
    __self__ = ( class Fl_Scrollbar * )lua_to_Fl_Scrollbar(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->value());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Scrollbar::value(int p, int s, int top, int total) */
int lua_call2_Fl_Scrollbar__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Scrollbar * __self__;
     int p;
     int s;
     int top;
     int total;
    
    __self__ = ( class Fl_Scrollbar * )lua_to_Fl_Scrollbar(__S__, 1, &__ERROR__);
    p = ( int )(int)lua_tonumber(__S__, 2);
    s = ( int )(int)lua_tonumber(__S__, 3);
    top = ( int )(int)lua_tonumber(__S__, 4);
    total = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->value(p, s, top, total));
    return 1;
  }
  
error:
  return lua_call1_Fl_Scrollbar__value(__S__);
}
/* char Fl_Preferences::getUserdataPath(char * path, int pathlen) */
int lua_call1_Fl_Preferences__getUserdataPath(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Preferences * __self__;
     char * path;
     int pathlen;
    
    __self__ = ( class Fl_Preferences * )lua_to_Fl_Preferences(__S__, 1, &__ERROR__);
    path = ( char * )(char  *)lua_tostring(__S__, 2);
    pathlen = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->getUserdataPath(path, pathlen));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* long Fl_Widget::argument()const  */
int lua_call1_Fl_Widget__argument(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->argument());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::argument(long v) */
int lua_call2_Fl_Widget__argument(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Widget * __self__;
     long v;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    v = ( long )(long)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->argument(v);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Widget__argument(__S__);
}
/* char * Fl_Text_Buffer::secondary_selection_text() */
int lua_call1_Fl_Text_Buffer__secondary_selection_text(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Buffer * __self__;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->secondary_selection_text());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_File_Chooser::hide() */
int lua_call1_Fl_File_Chooser__hide(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Chooser * __self__;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->hide();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color Fl_Input_::cursor_color()const  */
int lua_call1_Fl_Input___cursor_color(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Input_ * __self__;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->cursor_color());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Input_::cursor_color(unsigned int n) */
int lua_call2_Fl_Input___cursor_color(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Input_ * __self__;
     unsigned int n;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    n = ( unsigned int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->cursor_color(n);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Input___cursor_color(__S__);
}
/* int Fl_Input_::copy(int clipboard) */
int lua_call1_Fl_Input___copy(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Input_ * __self__;
     int clipboard;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    clipboard = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->copy(clipboard));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color Fl_File_Chooser::textcolor() */
int lua_call1_Fl_File_Chooser__textcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Chooser * __self__;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textcolor());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_File_Chooser::textcolor(Fl_Color c) */
int lua_call2_Fl_File_Chooser__textcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_File_Chooser * __self__;
     Fl_Color c;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    c = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textcolor(c);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_File_Chooser__textcolor(__S__);
}
/*  Fl_XPM_Image::Fl_XPM_Image(const char * filename) */
int lua_call1_Fl_XPM_Image__Fl_XPM_Image(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * filename;
    
    filename = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_XPM_Image(__S__, new Fl_XPM_Image(filename));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Scroll::handle(int ) */
int lua_call1_Fl_Scroll__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Scroll * __self__;
     int __2__;
    
    __self__ = ( class Fl_Scroll * )lua_to_Fl_Scroll(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Roller::Fl_Roller(int X, int Y, int W, int H, const char * L=0) */
int lua_call1_Fl_Roller__Fl_Roller(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     char * L;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Roller(__S__, new Fl_Roller(X, Y, W, H));
      return 1;
    } else {
      L = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Roller(__S__, new Fl_Roller(X, Y, W, H, L));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Browser_::handle(int ) */
int lua_call1_Fl_Browser___handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Browser_ * __self__;
     int __2__;
    
    __self__ = ( class Fl_Browser_ * )lua_to_Fl_Browser_(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Overlay_Window::resize(int , int , int , int ) */
int lua_call1_Fl_Overlay_Window__resize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Overlay_Window * __self__;
     int __2__;
     int __3__;
     int __4__;
     int __5__;
    
    __self__ = ( class Fl_Overlay_Window * )lua_to_Fl_Overlay_Window(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    __5__ = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->resize(__2__, __3__, __4__, __5__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser::hide() */
int lua_call1_Fl_Browser__hide(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Browser * __self__;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->hide();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser::hide(int n) */
int lua_call2_Fl_Browser__hide(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Browser * __self__;
     int n;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    n = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->hide(n);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Browser__hide(__S__);
}
/* void Fl_File_Chooser::show() */
int lua_call1_Fl_File_Chooser__show(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Chooser * __self__;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->show();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::default_atclose(class Fl_Window * , void * ) */
/* SKIPPED (argument #2) */
/*  Fl_Counter::Fl_Counter(int , int , int , int , const char * =0) */
int lua_call1_Fl_Counter__Fl_Counter(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int __1__;
     int __2__;
     int __3__;
     int __4__;
     char * __5__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Counter(__S__, new Fl_Counter(__1__, __2__, __3__, __4__));
      return 1;
    } else {
      __5__ = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Counter(__S__, new Fl_Counter(__1__, __2__, __3__, __4__, __5__));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* uchar Fl_File_Chooser::textfont() */
int lua_call1_Fl_File_Chooser__textfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Chooser * __self__;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textfont());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_File_Chooser::textfont(uchar f) */
int lua_call2_Fl_File_Chooser__textfont(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_File_Chooser * __self__;
     unsigned char f;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    f = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textfont(f);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_File_Chooser__textfont(__S__);
}
/* void Fl_Widget::clear_changed() */
int lua_call1_Fl_Widget__clear_changed(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->clear_changed();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* uchar Fl_File_Chooser::textsize() */
int lua_call1_Fl_File_Chooser__textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Chooser * __self__;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textsize());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_File_Chooser::textsize(uchar s) */
int lua_call2_Fl_File_Chooser__textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_File_Chooser * __self__;
     unsigned char s;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    s = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textsize(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_File_Chooser__textsize(__S__);
}
/* int Fl_Input::handle(int ) */
int lua_call1_Fl_Input__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Input * __self__;
     int __2__;
    
    __self__ = ( class Fl_Input * )lua_to_Fl_Input(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::flush() */
int lua_call1_Fl__flush(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    Fl::flush();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_File_Chooser::type() */
int lua_call1_Fl_File_Chooser__type(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Chooser * __self__;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->type());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_File_Chooser::type(int t) */
int lua_call2_Fl_File_Chooser__type(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_File_Chooser * __self__;
     int t;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    t = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->type(t);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_File_Chooser__type(__S__);
}
/* class Fl_Input * Fl_Input_Choice::input() */
int lua_call1_Fl_Input_Choice__input(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Input_Choice * __self__;
    
    __self__ = ( class Fl_Input_Choice * )lua_to_Fl_Input_Choice(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Input(__S__, __self__->input());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_File_Chooser::rescan_keep_filename() */
int lua_call1_Fl_File_Chooser__rescan_keep_filename(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_File_Chooser * __self__;
    
    __self__ = ( class Fl_File_Chooser * )lua_to_Fl_File_Chooser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->rescan_keep_filename();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Buffer::add_predelete_callback(Fl_Text_Predelete_Cb bufPredelCB, void * cbArg) */
/* SKIPPED (argument #2) */
/* void fl_draw(const char * , int x, int y) */
int lua_call1_fl_draw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 3) goto error;
  {
     char * __1__;
     int x;
     int y;
    
    __1__ = ( char * )(char  *)lua_tostring(__S__, 1);
    x = ( int )(int)lua_tonumber(__S__, 2);
    y = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    fl_draw(__1__, x, y);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_draw(const char * , int n, int x, int y) */
int lua_call2_fl_draw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     char * __1__;
     int n;
     int x;
     int y;
    
    __1__ = ( char * )(char  *)lua_tostring(__S__, 1);
    n = ( int )(int)lua_tonumber(__S__, 2);
    x = ( int )(int)lua_tonumber(__S__, 3);
    y = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    fl_draw(__1__, n, x, y);
    ;
    return 0;
  }
  
error:
  return lua_call1_fl_draw(__S__);
}
/* void fl_draw(const char * , int , int , int , int , Fl_Align , class Fl_Image * img=0, int draw_symbols=1) */
int lua_call3_fl_draw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 6) goto error;
  {
     char * __1__;
     int __2__;
     int __3__;
     int __4__;
     int __5__;
     Fl_Align __6__;
     class Fl_Image * img;
     int draw_symbols;
    
    __1__ = ( char * )(char  *)lua_tostring(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    __5__ = ( int )(int)lua_tonumber(__S__, 5);
    __6__ = ( Fl_Align )(Fl_Align)(int)lua_tonumber(__S__, 6);
    
    /* Actual call */
    if (nparam <= 6) {
      if (__ERROR__) goto error;
      
      fl_draw(__1__, __2__, __3__, __4__, __5__, __6__);
    } else {
      img = ( class Fl_Image * )lua_to_Fl_Image(__S__, 7, &__ERROR__);
      if (nparam <= 7) {
        if (__ERROR__) goto error;
        
        fl_draw(__1__, __2__, __3__, __4__, __5__, __6__, img);
      } else {
        draw_symbols = ( int )(int)lua_tonumber(__S__, 8);
        if (__ERROR__) goto error;
        
        fl_draw(__1__, __2__, __3__, __4__, __5__, __6__, img, draw_symbols);
      }
    }
    ;
    return 0;
  }
  
error:
  return lua_call2_fl_draw(__S__);
}
/* void fl_draw(const char * , int , int , int , int , Fl_Align , void ( * callthis)(const char * , int n, int x, int y), class Fl_Image * img=0, int draw_symbols=1) */
/* SKIPPED (argument #7) */
/* int Fl_Input_::copy_cuts() */
int lua_call1_Fl_Input___copy_cuts(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Input_ * __self__;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->copy_cuts());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Button::handle(int ) */
int lua_call1_Fl_Button__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Button * __self__;
     int __2__;
    
    __self__ = ( class Fl_Button * )lua_to_Fl_Button(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Input_Choice::clear_changed() */
int lua_call1_Fl_Input_Choice__clear_changed(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Input_Choice * __self__;
    
    __self__ = ( class Fl_Input_Choice * )lua_to_Fl_Input_Choice(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->clear_changed();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color Fl_Input_::textcolor()const  */
int lua_call1_Fl_Input___textcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Input_ * __self__;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textcolor());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Input_::textcolor(unsigned int n) */
int lua_call2_Fl_Input___textcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Input_ * __self__;
     unsigned int n;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    n = ( unsigned int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textcolor(n);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Input___textcolor(__S__);
}
/* char Fl_murgaLuaTimer::isActive() */
int lua_call1_Fl_murgaLuaTimer__isActive(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_murgaLuaTimer * __self__;
    
    __self__ = ( class Fl_murgaLuaTimer * )lua_to_Fl_murgaLuaTimer(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->isActive());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color Fl_Button::down_color()const  */
int lua_call1_Fl_Button__down_color(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Button * __self__;
    
    __self__ = ( class Fl_Button * )lua_to_Fl_Button(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->down_color());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Button::down_color(unsigned int c) */
int lua_call2_Fl_Button__down_color(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Button * __self__;
     unsigned int c;
    
    __self__ = ( class Fl_Button * )lua_to_Fl_Button(__S__, 1, &__ERROR__);
    c = ( unsigned int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->down_color(c);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Button__down_color(__S__);
}
/* class Fl_Window * Fl::grab() */
int lua_call1_Fl__grab(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_Window(__S__, Fl::grab());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::grab(class Fl_Window & win) */
int lua_call2_Fl__grab(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
    
     class Fl_Window & win = ( class Fl_Window & )(*lua_to_Fl_Window(__S__, 1, &__ERROR__));
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    Fl::grab(win);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl__grab(__S__);
}
/* void Fl::grab(class Fl_Window * ) */
int lua_call3_Fl__grab(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     class Fl_Window * __1__;
    
    __1__ = ( class Fl_Window * )lua_to_Fl_Window(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    Fl::grab(__1__);
    ;
    return 0;
  }
  
error:
  return lua_call2_Fl__grab(__S__);
}
/* int Fl::has_idle(void ( * cb)(void * ), void * =0) */
/* SKIPPED (argument #1) */
/* void Fl_Widget::set_changed() */
int lua_call1_Fl_Widget__set_changed(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->set_changed();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color Fl_Widget::color2()const  */
int lua_call1_Fl_Widget__color2(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->color2());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::color2(unsigned int a) */
int lua_call2_Fl_Widget__color2(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Widget * __self__;
     unsigned int a;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    a = ( unsigned int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->color2(a);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Widget__color2(__S__);
}
/* void Fl_Input_Choice::set_changed() */
int lua_call1_Fl_Input_Choice__set_changed(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Input_Choice * __self__;
    
    __self__ = ( class Fl_Input_Choice * )lua_to_Fl_Input_Choice(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->set_changed();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Multi_Label::label(class Fl_Widget * ) */
int lua_call1_Fl_Multi_Label__label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     struct Fl_Multi_Label * __self__;
     class Fl_Widget * __2__;
    
    __self__ = ( struct Fl_Multi_Label * )lua_to_Fl_Multi_Label(__S__, 1, &__ERROR__);
    __2__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->label(__2__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Multi_Label::label(struct Fl_Menu_Item * ) */
int lua_call2_Fl_Multi_Label__label(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     struct Fl_Multi_Label * __self__;
     struct Fl_Menu_Item * __2__;
    
    __self__ = ( struct Fl_Multi_Label * )lua_to_Fl_Multi_Label(__S__, 1, &__ERROR__);
    __2__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->label(__2__);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Multi_Label__label(__S__);
}
/* void Fl::watch_widget_pointer(class Fl_Widget * & w) */
/* SKIPPED (argument #1) */
/* int Fl_Input_::size()const  */
int lua_call1_Fl_Input___size(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Input_ * __self__;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->size());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Input_::size(int W, int H) */
int lua_call2_Fl_Input___size(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Input_ * __self__;
     int W;
     int H;
    
    __self__ = ( class Fl_Input_ * )lua_to_Fl_Input_(__S__, 1, &__ERROR__);
    W = ( int )(int)lua_tonumber(__S__, 2);
    H = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->size(W, H);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Input___size(__S__);
}
/* void Fl_Check_Browser::clear() */
int lua_call1_Fl_Check_Browser__clear(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Check_Browser * __self__;
    
    __self__ = ( class Fl_Check_Browser * )lua_to_Fl_Check_Browser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->clear();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Check_Browser::remove(int item) */
int lua_call1_Fl_Check_Browser__remove(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Check_Browser * __self__;
     int item;
    
    __self__ = ( class Fl_Check_Browser * )lua_to_Fl_Check_Browser(__S__, 1, &__ERROR__);
    item = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->remove(item));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_File_Icon * Fl_File_Icon::first() */
int lua_call1_Fl_File_Icon__first(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_File_Icon(__S__, Fl_File_Icon::first());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Box_Draw_F * Fl::get_boxtype(Fl_Boxtype ) */
/* SKIPPED (return type) */
/* void Fl_File_Icon::draw(int x, int y, int w, int h, Fl_Color ic, int active=1) */
int lua_call1_Fl_File_Icon__draw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 6) goto error;
  {
     class Fl_File_Icon * __self__;
     int x;
     int y;
     int w;
     int h;
     Fl_Color ic;
     int active;
    
    __self__ = ( class Fl_File_Icon * )lua_to_Fl_File_Icon(__S__, 1, &__ERROR__);
    x = ( int )(int)lua_tonumber(__S__, 2);
    y = ( int )(int)lua_tonumber(__S__, 3);
    w = ( int )(int)lua_tonumber(__S__, 4);
    h = ( int )(int)lua_tonumber(__S__, 5);
    ic = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 6);
    
    /* Actual call */
    if (nparam <= 6) {
      if (__ERROR__) goto error;
      
      __self__->draw(x, y, w, h, ic);
    } else {
      active = ( int )(int)lua_tonumber(__S__, 7);
      if (__ERROR__) goto error;
      
      __self__->draw(x, y, w, h, ic, active);
    }
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_File_Icon::Fl_File_Icon(const char * p, int t, int nd=0, short * d=0) */
int lua_call1_Fl_File_Icon__Fl_File_Icon(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     char * p;
     int t;
     int nd;
     short * d;
    
    p = ( char * )(char  *)lua_tostring(__S__, 1);
    t = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (nparam <= 2) {
      lua_settop(__S__, 0);
      lua_push_Fl_File_Icon(__S__, new Fl_File_Icon(p, t));
      return 1;
    } else {
      nd = ( int )(int)lua_tonumber(__S__, 3);
      if (nparam <= 3) {
        lua_settop(__S__, 0);
        lua_push_Fl_File_Icon(__S__, new Fl_File_Icon(p, t, nd));
        return 1;
      } else {
        lua_settop(__S__, 0);
        lua_push_Fl_File_Icon(__S__, new Fl_File_Icon(p, t, nd, d));
        return 1;
      }
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* double Fl_Color_Chooser::value()const  */
int lua_call1_Fl_Color_Chooser__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Color_Chooser * __self__;
    
    __self__ = ( class Fl_Color_Chooser * )lua_to_Fl_Color_Chooser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->value());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::get_font_sizes(Fl_Font , int * & sizep) */
/* SKIPPED (argument #2) */
/* void Fl_Help_Dialog::topline(int n) */
int lua_call1_Fl_Help_Dialog__topline(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Help_Dialog * __self__;
     int n;
    
    __self__ = ( class Fl_Help_Dialog * )lua_to_Fl_Help_Dialog(__S__, 1, &__ERROR__);
    n = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->topline(n);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Help_Dialog::topline(const char * n) */
int lua_call2_Fl_Help_Dialog__topline(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Help_Dialog * __self__;
     char * n;
    
    __self__ = ( class Fl_Help_Dialog * )lua_to_Fl_Help_Dialog(__S__, 1, &__ERROR__);
    n = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->topline(n);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Help_Dialog__topline(__S__);
}
/* int Fl_Text_Editor::kf_shift_move(int c, class Fl_Text_Editor * e) */
int lua_call1_Fl_Text_Editor__kf_shift_move(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int c;
     class Fl_Text_Editor * e;
    
    c = ( int )(int)lua_tonumber(__S__, 1);
    e = ( class Fl_Text_Editor * )lua_to_Fl_Text_Editor(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Text_Editor::kf_shift_move(c, e));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Shared_Image::draw(int X, int Y) */
int lua_call1_Fl_Shared_Image__draw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Shared_Image * __self__;
     int X;
     int Y;
    
    __self__ = ( class Fl_Shared_Image * )lua_to_Fl_Shared_Image(__S__, 1, &__ERROR__);
    X = ( int )(int)lua_tonumber(__S__, 2);
    Y = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->draw(X, Y);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Shared_Image::draw(int X, int Y, int W, int H, int cx, int cy) */
int lua_call2_Fl_Shared_Image__draw(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 7) goto error;
  {
     class Fl_Shared_Image * __self__;
     int X;
     int Y;
     int W;
     int H;
     int cx;
     int cy;
    
    __self__ = ( class Fl_Shared_Image * )lua_to_Fl_Shared_Image(__S__, 1, &__ERROR__);
    X = ( int )(int)lua_tonumber(__S__, 2);
    Y = ( int )(int)lua_tonumber(__S__, 3);
    W = ( int )(int)lua_tonumber(__S__, 4);
    H = ( int )(int)lua_tonumber(__S__, 5);
    cx = ( int )(int)lua_tonumber(__S__, 6);
    cy = ( int )(int)lua_tonumber(__S__, 7);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->draw(X, Y, W, H, cx, cy);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Shared_Image__draw(__S__);
}
/* double Fl_Spinner::value()const  */
int lua_call1_Fl_Spinner__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Spinner * __self__;
    
    __self__ = ( class Fl_Spinner * )lua_to_Fl_Spinner(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->value());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Spinner::value(double v) */
int lua_call2_Fl_Spinner__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Spinner * __self__;
     double v;
    
    __self__ = ( class Fl_Spinner * )lua_to_Fl_Spinner(__S__, 1, &__ERROR__);
    v = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->value(v);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Spinner__value(__S__);
}
/* Fl_Color Fl_Spinner::textcolor()const  */
int lua_call1_Fl_Spinner__textcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Spinner * __self__;
    
    __self__ = ( class Fl_Spinner * )lua_to_Fl_Spinner(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textcolor());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Spinner::textcolor(Fl_Color c) */
int lua_call2_Fl_Spinner__textcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Spinner * __self__;
     Fl_Color c;
    
    __self__ = ( class Fl_Spinner * )lua_to_Fl_Spinner(__S__, 1, &__ERROR__);
    c = ( Fl_Color )(Fl_Color)(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textcolor(c);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Spinner__textcolor(__S__);
}
/* double Fl_Spinner::maxinum()const  */
int lua_call1_Fl_Spinner__maxinum(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Spinner * __self__;
    
    __self__ = ( class Fl_Spinner * )lua_to_Fl_Spinner(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->maxinum());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* double Fl_Spinner::maximum()const  */
int lua_call1_Fl_Spinner__maximum(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Spinner * __self__;
    
    __self__ = ( class Fl_Spinner * )lua_to_Fl_Spinner(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->maximum());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Spinner::maximum(double m) */
int lua_call2_Fl_Spinner__maximum(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Spinner * __self__;
     double m;
    
    __self__ = ( class Fl_Spinner * )lua_to_Fl_Spinner(__S__, 1, &__ERROR__);
    m = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->maximum(m);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Spinner__maximum(__S__);
}
/* void Fl_Text_Editor::add_default_key_bindings(struct Fl_Text_Editor::Key_Binding * * list) */
/* SKIPPED (argument #2) */
/*  Fl_Tile::Fl_Tile(int X, int Y, int W, int H, const char * l=0) */
int lua_call1_Fl_Tile__Fl_Tile(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     char * l;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Tile(__S__, new Fl_Tile(X, Y, W, H));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Tile(__S__, new Fl_Tile(X, Y, W, H, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Browser::Fl_Browser(int , int , int , int , const char * =0) */
int lua_call1_Fl_Browser__Fl_Browser(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int __1__;
     int __2__;
     int __3__;
     int __4__;
     char * __5__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Browser(__S__, new Fl_Browser(__1__, __2__, __3__, __4__));
      return 1;
    } else {
      __5__ = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Browser(__S__, new Fl_Browser(__1__, __2__, __3__, __4__, __5__));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl::set_idle(void ( * cb)()) */
/* SKIPPED (argument #1) */
/* int Fl_Browser::selected(int )const  */
int lua_call1_Fl_Browser__selected(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Browser * __self__;
     int __2__;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->selected(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Buffer::insert(int pos, const char * text) */
int lua_call1_Fl_Text_Buffer__insert(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Text_Buffer * __self__;
     int pos;
     char * text;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    pos = ( int )(int)lua_tonumber(__S__, 2);
    text = ( char * )(char  *)lua_tostring(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->insert(pos, text);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* char Fl_Text_Selection::selected() */
int lua_call1_Fl_Text_Selection__selected(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Selection * __self__;
    
    __self__ = ( class Fl_Text_Selection * )lua_to_Fl_Text_Selection(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->selected());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Selection::selected(char b) */
int lua_call2_Fl_Text_Selection__selected(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Selection * __self__;
     char b;
    
    __self__ = ( class Fl_Text_Selection * )lua_to_Fl_Text_Selection(__S__, 1, &__ERROR__);
    b = ( char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->selected(b);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Text_Selection__selected(__S__);
}
/* uchar Fl_Value_Output::textsize()const  */
int lua_call1_Fl_Value_Output__textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Value_Output * __self__;
    
    __self__ = ( class Fl_Value_Output * )lua_to_Fl_Value_Output(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textsize());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Value_Output::textsize(uchar s) */
int lua_call2_Fl_Value_Output__textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Value_Output * __self__;
     unsigned char s;
    
    __self__ = ( class Fl_Value_Output * )lua_to_Fl_Value_Output(__S__, 1, &__ERROR__);
    s = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textsize(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Value_Output__textsize(__S__);
}
/* void Fl_Browser::middleline(int l) */
int lua_call1_Fl_Browser__middleline(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Browser * __self__;
     int l;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    l = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->middleline(l);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Selection::rect_start() */
int lua_call1_Fl_Text_Selection__rect_start(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Selection * __self__;
    
    __self__ = ( class Fl_Text_Selection * )lua_to_Fl_Text_Selection(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->rect_start());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_File_Input::Fl_File_Input(int , int , int , int , const char * t=0) */
int lua_call1_Fl_File_Input__Fl_File_Input(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int __1__;
     int __2__;
     int __3__;
     int __4__;
     char * t;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_File_Input(__S__, new Fl_File_Input(__1__, __2__, __3__, __4__));
      return 1;
    } else {
      t = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_File_Input(__S__, new Fl_File_Input(__1__, __2__, __3__, __4__, t));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Int_Input::Fl_Int_Input(int X, int Y, int W, int H, const char * l=0) */
int lua_call1_Fl_Int_Input__Fl_Int_Input(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     char * l;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Int_Input(__S__, new Fl_Int_Input(X, Y, W, H));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Int_Input(__S__, new Fl_Int_Input(X, Y, W, H, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Browser::displayed(int n)const  */
int lua_call1_Fl_Browser__displayed(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Browser * __self__;
     int n;
    
    __self__ = ( class Fl_Browser * )lua_to_Fl_Browser(__S__, 1, &__ERROR__);
    n = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->displayed(n));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Display::word_end(int pos) */
int lua_call1_Fl_Text_Display__word_end(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Display * __self__;
     int pos;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    pos = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->word_end(pos));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Widget::active_r()const  */
int lua_call1_Fl_Widget__active_r(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->active_r());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::event_button1() */
int lua_call1_Fl__event_button1(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::event_button1());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* uchar Fl_Spinner::textsize()const  */
int lua_call1_Fl_Spinner__textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Spinner * __self__;
    
    __self__ = ( class Fl_Spinner * )lua_to_Fl_Spinner(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->textsize());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Spinner::textsize(uchar s) */
int lua_call2_Fl_Spinner__textsize(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Spinner * __self__;
     unsigned char s;
    
    __self__ = ( class Fl_Spinner * )lua_to_Fl_Spinner(__S__, 1, &__ERROR__);
    s = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->textsize(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Spinner__textsize(__S__);
}
/* int Fl_Button::shortcut()const  */
int lua_call1_Fl_Button__shortcut(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Button * __self__;
    
    __self__ = ( class Fl_Button * )lua_to_Fl_Button(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->shortcut());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Button::shortcut(int s) */
int lua_call2_Fl_Button__shortcut(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Button * __self__;
     int s;
    
    __self__ = ( class Fl_Button * )lua_to_Fl_Button(__S__, 1, &__ERROR__);
    s = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->shortcut(s);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Button__shortcut(__S__);
}
/* void Fl_Button::shortcut(const char * s) */
int lua_call3_Fl_Button__shortcut(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Button * __self__;
     char * s;
    
    __self__ = ( class Fl_Button * )lua_to_Fl_Button(__S__, 1, &__ERROR__);
    s = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->shortcut(s);
    ;
    return 0;
  }
  
error:
  return lua_call2_Fl_Button__shortcut(__S__);
}
/* int Fl_Color_Chooser::rgb(double , double , double ) */
int lua_call1_Fl_Color_Chooser__rgb(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 4) goto error;
  {
     class Fl_Color_Chooser * __self__;
     double __2__;
     double __3__;
     double __4__;
    
    __self__ = ( class Fl_Color_Chooser * )lua_to_Fl_Color_Chooser(__S__, 1, &__ERROR__);
    __2__ = ( double )(double)lua_tonumber(__S__, 2);
    __3__ = ( double )(double)lua_tonumber(__S__, 3);
    __4__ = ( double )(double)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->rgb(__2__, __3__, __4__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Display::move_right() */
int lua_call1_Fl_Text_Display__move_right(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Display * __self__;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->move_right());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Return_Button::handle(int ) */
int lua_call1_Fl_Return_Button__handle(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Return_Button * __self__;
     int __2__;
    
    __self__ = ( class Fl_Return_Button * )lua_to_Fl_Return_Button(__S__, 1, &__ERROR__);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->handle(__2__));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_Color Fl_Menu_Item::labelcolor()const  */
int lua_call1_Fl_Menu_Item__labelcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     struct Fl_Menu_Item * __self__;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->labelcolor());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Menu_Item::labelcolor(unsigned int a) */
int lua_call2_Fl_Menu_Item__labelcolor(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     struct Fl_Menu_Item * __self__;
     unsigned int a;
    
    __self__ = ( struct Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
    a = ( unsigned int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->labelcolor(a);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Menu_Item__labelcolor(__S__);
}
/*  Fl_Bitmap::Fl_Bitmap(const char * bits, int W, int H) */
int lua_call1_Fl_Bitmap__Fl_Bitmap(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 3) goto error;
  {
     char * bits;
     int W;
     int H;
    
    bits = ( char * )(char  *)lua_tostring(__S__, 1);
    W = ( int )(int)lua_tonumber(__S__, 2);
    H = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_Bitmap(__S__, new Fl_Bitmap(bits, W, H));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Bitmap::Fl_Bitmap(const uchar * bits, int W, int H) */
int lua_call2_Fl_Bitmap__Fl_Bitmap(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 3) goto error;
  {
     unsigned char * bits;
     int W;
     int H;
    
    bits = ( unsigned char * )(char  *)lua_tostring(__S__, 1);
    W = ( int )(int)lua_tonumber(__S__, 2);
    H = ( int )(int)lua_tonumber(__S__, 3);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_Bitmap(__S__, new Fl_Bitmap(bits, W, H));
    return 1;
  }
  
error:
  return lua_call1_Fl_Bitmap__Fl_Bitmap(__S__);
}
/* Fl_Color Fl_Tooltip::color() */
int lua_call1_Fl_Tooltip__color(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Tooltip::color());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Tooltip::color(unsigned int c) */
int lua_call2_Fl_Tooltip__color(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     unsigned int c;
    
    c = ( unsigned int )(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    Fl_Tooltip::color(c);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Tooltip__color(__S__);
}
/* int Fl::get_awake_handler_(Fl_Awake_Handler & , void * & ) */
/* SKIPPED (argument #1) */
/* int Fl_Text_Selection::start() */
int lua_call1_Fl_Text_Selection__start(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Selection * __self__;
    
    __self__ = ( class Fl_Text_Selection * )lua_to_Fl_Text_Selection(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->start());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl::w() */
int lua_call1_Fl__w(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl::w());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Display::position_style(int lineStartPos, int lineLen, int lineIndex, int dispIndex) */
int lua_call1_Fl_Text_Display__position_style(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 5) goto error;
  {
     class Fl_Text_Display * __self__;
     int lineStartPos;
     int lineLen;
     int lineIndex;
     int dispIndex;
    
    __self__ = ( class Fl_Text_Display * )lua_to_Fl_Text_Display(__S__, 1, &__ERROR__);
    lineStartPos = ( int )(int)lua_tonumber(__S__, 2);
    lineLen = ( int )(int)lua_tonumber(__S__, 3);
    lineIndex = ( int )(int)lua_tonumber(__S__, 4);
    dispIndex = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->position_style(lineStartPos, lineLen, lineIndex, dispIndex));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Shared_Image * Fl_Shared_Image::get(const char * n, int W=0, int H=0) */
int lua_call1_Fl_Shared_Image__get(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     char * n;
     int W;
     int H;
    
    n = ( char * )(char  *)lua_tostring(__S__, 1);
    
    /* Actual call */
    if (nparam <= 1) {
      lua_settop(__S__, 0);
      lua_push_Fl_Shared_Image(__S__, Fl_Shared_Image::get(n));
      return 1;
    } else {
      W = ( int )(int)lua_tonumber(__S__, 2);
      if (nparam <= 2) {
        lua_settop(__S__, 0);
        lua_push_Fl_Shared_Image(__S__, Fl_Shared_Image::get(n, W));
        return 1;
      } else {
        H = ( int )(int)lua_tonumber(__S__, 3);
        lua_settop(__S__, 0);
        lua_push_Fl_Shared_Image(__S__, Fl_Shared_Image::get(n, W, H));
        return 1;
      }
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Editor::kf_default(int c, class Fl_Text_Editor * e) */
int lua_call1_Fl_Text_Editor__kf_default(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int c;
     class Fl_Text_Editor * e;
    
    c = ( int )(int)lua_tonumber(__S__, 1);
    e = ( class Fl_Text_Editor * )lua_to_Fl_Text_Editor(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Text_Editor::kf_default(c, e));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_polygon(int , int , int , int , int , int ) */
int lua_call1_fl_polygon(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 6) goto error;
  {
     int __1__;
     int __2__;
     int __3__;
     int __4__;
     int __5__;
     int __6__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    __5__ = ( int )(int)lua_tonumber(__S__, 5);
    __6__ = ( int )(int)lua_tonumber(__S__, 6);
    
    /* Actual call */
    fl_polygon(__1__, __2__, __3__, __4__, __5__, __6__);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_polygon(int , int , int , int , int , int , int , int ) */
int lua_call2_fl_polygon(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 8) goto error;
  {
     int __1__;
     int __2__;
     int __3__;
     int __4__;
     int __5__;
     int __6__;
     int __7__;
     int __8__;
    
    __1__ = ( int )(int)lua_tonumber(__S__, 1);
    __2__ = ( int )(int)lua_tonumber(__S__, 2);
    __3__ = ( int )(int)lua_tonumber(__S__, 3);
    __4__ = ( int )(int)lua_tonumber(__S__, 4);
    __5__ = ( int )(int)lua_tonumber(__S__, 5);
    __6__ = ( int )(int)lua_tonumber(__S__, 6);
    __7__ = ( int )(int)lua_tonumber(__S__, 7);
    __8__ = ( int )(int)lua_tonumber(__S__, 8);
    
    /* Actual call */
    fl_polygon(__1__, __2__, __3__, __4__, __5__, __6__, __7__, __8__);
    ;
    return 0;
  }
  
error:
  return lua_call1_fl_polygon(__S__);
}
/* const char * Fl_Widget::tooltip()const  */
int lua_call1_Fl_Widget__tooltip(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) __self__->tooltip());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::tooltip(const char * t) */
int lua_call2_Fl_Widget__tooltip(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Widget * __self__;
     char * t;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    t = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->tooltip(t);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Widget__tooltip(__S__);
}
/* const char * Fl::event_text() */
int lua_call1_Fl__event_text(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushstring(__S__, (const char * ) Fl::event_text());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Browser_::scrollbar_left() */
int lua_call1_Fl_Browser___scrollbar_left(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Browser_ * __self__;
    
    __self__ = ( class Fl_Browser_ * )lua_to_Fl_Browser_(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->scrollbar_left();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* double Fl_Timer::value()const  */
int lua_call1_Fl_Timer__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Timer * __self__;
    
    __self__ = ( class Fl_Timer * )lua_to_Fl_Timer(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->value());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Timer::value(double ) */
int lua_call2_Fl_Timer__value(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Timer * __self__;
     double __2__;
    
    __self__ = ( class Fl_Timer * )lua_to_Fl_Timer(__S__, 1, &__ERROR__);
    __2__ = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->value(__2__);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Timer__value(__S__);
}
/* void Fl_Text_Buffer::overlay_rectangular(int startPos, int rectStart, int rectEnd, const char * text, int * charsInserted, int * charsDeleted) */
/* SKIPPED (argument #6) */
/*  Fl_Check_Button::Fl_Check_Button(int x, int y, int w, int h, const char * l=0) */
int lua_call1_Fl_Check_Button__Fl_Check_Button(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int x;
     int y;
     int w;
     int h;
     char * l;
    
    x = ( int )(int)lua_tonumber(__S__, 1);
    y = ( int )(int)lua_tonumber(__S__, 2);
    w = ( int )(int)lua_tonumber(__S__, 3);
    h = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Check_Button(__S__, new Fl_Check_Button(x, y, w, h));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Check_Button(__S__, new Fl_Check_Button(x, y, w, h, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Text_Editor::kf_insert(int c, class Fl_Text_Editor * e) */
int lua_call1_Fl_Text_Editor__kf_insert(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 2) goto error;
  {
     int c;
     class Fl_Text_Editor * e;
    
    c = ( int )(int)lua_tonumber(__S__, 1);
    e = ( class Fl_Text_Editor * )lua_to_Fl_Text_Editor(__S__, 2, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, Fl_Text_Editor::kf_insert(c, e));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_open_callback(void ( * )(const char * )) */
/* SKIPPED (argument #1) */
/* void Fl_Text_Buffer::append(const char * t) */
int lua_call1_Fl_Text_Buffer__append(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Buffer * __self__;
     char * t;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    t = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->append(t);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Help_Dialog::Fl_Help_Dialog() */
int lua_call1_Fl_Help_Dialog__Fl_Help_Dialog(lua_State * __S__)
{
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); }
  {
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_push_Fl_Help_Dialog(__S__, new Fl_Help_Dialog());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Clock_Output::hour()const  */
int lua_call1_Fl_Clock_Output__hour(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Clock_Output * __self__;
    
    __self__ = ( class Fl_Clock_Output * )lua_to_Fl_Clock_Output(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->hour());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Toggle_Button::Fl_Toggle_Button(int X, int Y, int W, int H, const char * l=0) */
int lua_call1_Fl_Toggle_Button__Fl_Toggle_Button(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     char * l;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Toggle_Button(__S__, new Fl_Toggle_Button(X, Y, W, H));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Toggle_Button(__S__, new Fl_Toggle_Button(X, Y, W, H, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Clock_Output::minute()const  */
int lua_call1_Fl_Clock_Output__minute(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Clock_Output * __self__;
    
    __self__ = ( class Fl_Clock_Output * )lua_to_Fl_Clock_Output(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->minute());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* int Fl_Widget::h()const  */
int lua_call1_Fl_Widget__h(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->h());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* class Fl_Menu_Button * Fl_Input_Choice::menubutton() */
int lua_call1_Fl_Input_Choice__menubutton(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Input_Choice * __self__;
    
    __self__ = ( class Fl_Input_Choice * )lua_to_Fl_Input_Choice(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_push_Fl_Menu_Button(__S__, __self__->menubutton());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* double Fl_Color_Chooser::saturation()const  */
int lua_call1_Fl_Color_Chooser__saturation(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Color_Chooser * __self__;
    
    __self__ = ( class Fl_Color_Chooser * )lua_to_Fl_Color_Chooser(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->saturation());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* Fl_When Fl_Widget::when()const  */
int lua_call1_Fl_Widget__when(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Widget * __self__;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->when());
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Widget::when(uchar i) */
int lua_call2_Fl_Widget__when(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Widget * __self__;
     unsigned char i;
    
    __self__ = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
    i = ( unsigned char )(char)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->when(i);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Widget__when(__S__);
}
/* Fl_Boxtype fl_frame(Fl_Boxtype b) */
int lua_call1_fl_frame(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 1) goto error;
  {
     Fl_Boxtype b;
    
    b = ( Fl_Boxtype )(Fl_Boxtype)(int)lua_tonumber(__S__, 1);
    
    /* Actual call */
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, fl_frame(b));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void fl_frame(const char * s, int x, int y, int w, int h) */
int lua_call2_fl_frame(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 5) goto error;
  {
     char * s;
     int x;
     int y;
     int w;
     int h;
    
    s = ( char * )(char  *)lua_tostring(__S__, 1);
    x = ( int )(int)lua_tonumber(__S__, 2);
    y = ( int )(int)lua_tonumber(__S__, 3);
    w = ( int )(int)lua_tonumber(__S__, 4);
    h = ( int )(int)lua_tonumber(__S__, 5);
    
    /* Actual call */
    fl_frame(s, x, y, w, h);
    ;
    return 0;
  }
  
error:
  return lua_call1_fl_frame(__S__);
}
/*  Fl_Return_Button::Fl_Return_Button(int X, int Y, int W, int H, const char * l=0) */
int lua_call1_Fl_Return_Button__Fl_Return_Button(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  if (lua_istable(__S__, 1)) { lua_remove(__S__, 1); nparam--; }
  if (nparam < 4) goto error;
  {
     int X;
     int Y;
     int W;
     int H;
     char * l;
    
    X = ( int )(int)lua_tonumber(__S__, 1);
    Y = ( int )(int)lua_tonumber(__S__, 2);
    W = ( int )(int)lua_tonumber(__S__, 3);
    H = ( int )(int)lua_tonumber(__S__, 4);
    
    /* Actual call */
    if (nparam <= 4) {
      lua_settop(__S__, 0);
      lua_push_Fl_Return_Button(__S__, new Fl_Return_Button(X, Y, W, H));
      return 1;
    } else {
      l = ( char * )(char  *)lua_tostring(__S__, 5);
      lua_settop(__S__, 0);
      lua_push_Fl_Return_Button(__S__, new Fl_Return_Button(X, Y, W, H, l));
      return 1;
    }
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void * Fl_Widget::user_data()const  */
/* SKIPPED (return type) */
/* void Fl_Widget::user_data(void * v) */
/* SKIPPED (argument #2) */
/* void Fl_Text_Buffer::remove_selection() */
int lua_call1_Fl_Text_Buffer__remove_selection(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 1) goto error;
  {
     class Fl_Text_Buffer * __self__;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->remove_selection();
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/*  Fl_Pixmap::Fl_Pixmap(const char * * D) */
/* SKIPPED (argument #1) */
/*  Fl_Pixmap::Fl_Pixmap(const const char * * D) */
/* SKIPPED (argument #1) */
/*  Fl_Pixmap::Fl_Pixmap(const const uchar * * D) */
/* SKIPPED (argument #1) */
/*  Fl_Pixmap::Fl_Pixmap(const uchar * * D) */
/* SKIPPED (argument #1) */
/* void Fl_Counter::step(double a) */
int lua_call1_Fl_Counter__step(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Counter * __self__;
     double a;
    
    __self__ = ( class Fl_Counter * )lua_to_Fl_Counter(__S__, 1, &__ERROR__);
    a = ( double )(double)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->step(a);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Counter::step(double a, double b) */
int lua_call2_Fl_Counter__step(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 3) goto error;
  {
     class Fl_Counter * __self__;
     double a;
     double b;
    
    __self__ = ( class Fl_Counter * )lua_to_Fl_Counter(__S__, 1, &__ERROR__);
    a = ( double )(double)lua_tonumber(__S__, 2);
    b = ( double )(double)lua_tonumber(__S__, 3);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->step(a, b);
    ;
    return 0;
  }
  
error:
  return lua_call1_Fl_Counter__step(__S__);
}
/* char Fl_Text_Buffer::character(int pos) */
int lua_call1_Fl_Text_Buffer__character(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Buffer * __self__;
     int pos;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    pos = ( int )(int)lua_tonumber(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    lua_settop(__S__, 0);
    lua_pushnumber(__S__, __self__->character(pos));
    return 1;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}
/* void Fl_Text_Buffer::unsubstitute_null_characters(char * string) */
int lua_call1_Fl_Text_Buffer__unsubstitute_null_characters(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
  if (nparam < 2) goto error;
  {
     class Fl_Text_Buffer * __self__;
     char * string;
    
    __self__ = ( class Fl_Text_Buffer * )lua_to_Fl_Text_Buffer(__S__, 1, &__ERROR__);
    string = ( char * )(char  *)lua_tostring(__S__, 2);
    
    /* Actual call */
    if (__ERROR__) goto error;
    
    __self__->unsubstitute_null_characters(string);
    ;
    return 0;
  }
  
error:
  luaL_error(__S__, badargs_error);
  return 0;
}

/* Init lua state (template 3) */


typedef struct funcdecl_t {
  const char * name;
  int (* func) (lua_State * S);
} funcdecl_t;

typedef struct enumdecl_t {
  const char * name;
  int value;
} enumdecl_t;

typedef struct numberdef_t {
  const char * name;
  float value;
} numberdef_t;

typedef struct stringdef_t {
  const char * name;
  const char * value;
} stringdef_t;


static void lua_fltk_init_type(lua_State * __S__, 
				 int isnamespace,
				 const char * name, 
				 lua_type_t * type,
				 const char * parent_types[],
				 funcdecl_t * functable, 
				 funcdecl_t * gettable, 
				 funcdecl_t * settable, 
				 enumdecl_t * enumtable)
{
  char nametag[128];
  char namecompattag[128];
  char nametypeinfo[128];
  char namegets[128];
  char namesets[128];
  int i;

  strcpy(nametag, name);
  strcat(nametag, "__TAG");
  
  strcpy(namecompattag, name);
  strcat(namecompattag, "__compattag");
  
  strcpy(nametypeinfo, name);
  strcat(nametypeinfo, "__typeinfo");
  
  strcpy(namegets, name);
  strcat(namegets, "__gets");
  
  strcpy(namesets, name);
  strcat(namesets, "__sets");
  
/*   type->tag = lua_newtag(__S__); */
/*   lua_pushnumber(__S__, type->tag); */
/*   lua_setglobal(__S__, nametag); */
  type->name = name;
	
	
  lua_settop(__S__, 0);
  luaL_newmetatable(__S__, name);
  lua_setglobal(__S__, name);
	
	
  lua_settop(__S__, 0);
  lua_newtable(__S__);
  lua_setglobal(__S__, namecompattag);
	
	
  lua_settop(__S__, 0);
  lua_newtable(__S__);
  lua_setglobal(__S__, nametypeinfo);
	
	
  lua_settop(__S__, 0);
  lua_newtable(__S__);
  lua_setglobal(__S__, namegets);


  lua_settop(__S__, 0);
  lua_newtable(__S__);
  lua_setglobal(__S__, namesets);


  lua_settop(__S__, 0);
  luaL_getmetatable(__S__, name);
  for (i=0; enumtable[i].name; i++) {
    lua_pushstring(__S__, enumtable[i].name);
    lua_pushnumber(__S__, enumtable[i].value);
    lua_settable(__S__, 1);
  }	

	
  lua_settop(__S__, 0);
  lua_getglobal(__S__, nametypeinfo);
	
  lua_pushstring(__S__, "compattag");
  lua_getglobal(__S__, namecompattag);
  lua_settable(__S__, 1);
	
  lua_pushstring(__S__, "vtable");
  luaL_getmetatable(__S__, name);
  lua_settable(__S__, 1);
	
  lua_pushstring(__S__, "name");
  lua_pushstring(__S__, type->name);
  lua_settable(__S__, 1);

  for (i=0; parent_types[i]; i++) {
    lua_pushnumber(__S__, i+1);
    lua_getglobal(__S__, parent_types[i]);
    lua_settable(__S__, 1);
    lua_settop(__S__, 1);
  }
  lua_pushstring(__S__, "n");
  lua_pushnumber(__S__, i);
  lua_settable(__S__, 1);
  lua_pop(__S__, 1);
	

  if (!isnamespace) {
    char str1[256];
    char str2[256];

    lua_settop(__S__, 0);
    luaL_getmetatable(__S__, name);
    lua_pushlightuserdata(__S__, type);
    lua_pushnumber(__S__, 1.0f);
    lua_settable(__S__, -3);
    lua_pop(__S__, 1);

    lua_getglobal(__S__, nametypeinfo);
    lua_pushlightuserdata(__S__, type);
    _lua_setfield(__S__, -2, "id");
    lua_pop(__S__, 1);

    lua_getglobal(__S__, "bind_lua_buildparents");
    lua_getglobal(__S__, nametypeinfo);
    lua_call(__S__, 1, 0);
/*     sprintf(str1, "bind_lua_buildparents(%s) \n", nametypeinfo); */
/*     sprintf(str2, "%s parents initializer", name); */
/*     lua_fltk_dostring(__S__,  */
/* 			str1, str2); */
  }
	
  lua_settop(__S__, 0);
  luaL_getmetatable(__S__, name);
  lua_pushstring(__S__, "bind_lua_typeinfo");
  lua_getglobal(__S__, nametypeinfo);
  lua_settable(__S__, 1);

  for (i=0; functable[i].name; i++) {
    lua_pushstring(__S__, functable[i].name);
    lua_pushcclosure(__S__, functable[i].func, 0);
    lua_settable(__S__, 1);
  }

  lua_settop(__S__, 0);
  lua_getglobal(__S__, namegets);
  for (i=0; gettable[i].name; i++) {
    lua_pushstring(__S__, gettable[i].name);
    lua_pushcclosure(__S__, gettable[i].func, 0);
    lua_settable(__S__, 1);
  }

  lua_settop(__S__, 0);
  lua_getglobal(__S__, namesets);
  for (i=0; settable[i].name; i++) {
    lua_pushstring(__S__, settable[i].name);
    lua_pushcclosure(__S__, settable[i].func, 0);
    lua_settable(__S__, 1);
  }

  if (!isnamespace) {
    lua_settop(__S__, 0);
    lua_getglobal(__S__, "lua_bindtypes");
    lua_pushstring(__S__, type->name);
    lua_getglobal(__S__, nametypeinfo);
    lua_settable(__S__, 1);
  }
	
  if (gettable[0].name == 0L) {
    luaL_getmetatable(__S__, name);
    luaL_getmetatable(__S__, name);
    lua_pushcclosure(__S__, lua_gettable_tagmethod_f, 1);
    _lua_setfield(__S__, -2, "__index");
  } else {
    if (functable[0].name == 0L) {
      luaL_getmetatable(__S__, name);
      lua_getglobal(__S__, namegets);
      lua_pushcclosure(__S__, lua_gettable_tagmethod_v, 1);
      _lua_setfield(__S__, -2, "__index");
    } else {
      luaL_getmetatable(__S__, name);
      luaL_getmetatable(__S__, name);
      lua_getglobal(__S__, namegets);
      lua_pushcclosure(__S__, lua_gettable_tagmethod_fv, 2);
      _lua_setfield(__S__, -2, "__index");
    }
  }

  luaL_getmetatable(__S__, name);
  lua_getglobal(__S__, namesets);
  lua_pushcclosure(__S__, lua_settable_tagmethod, 1);
  _lua_setfield(__S__, -2, "__newindex");

}


int init_lua_fltk_State(lua_State * __S__)
{
  lua_settop(__S__, 0);
	
  /* Create lua_bindtypes table if necessary */
  lua_getglobal(__S__, "lua_bindtypes");
  if (lua_type(__S__, 1) != LUA_TTABLE) { lua_pop(__S__, 1); lua_newtable(__S__); lua_setglobal(__S__, "lua_bindtypes"); }
  lua_settop(__S__, 0);

  luaL_dostring(__S__,
"function bind_lua_buildparents(ti) \n"
"  bind_lua_buildcompattag(ti, ti) \n"
"  local i, v, parent, j \n"
"  for j=1,ti.n,1 do \n"
"    parent = ti[j] \n"
"--    print(parent.name, 'is parent of', ti.name, 'with tag', ti.name) \n"
"    if type(parent)=='table' then \n"
"      local parentvtable = parent.vtable \n"
"      for i, v in pairs(parentvtable) do \n"
"        ti.vtable[i] = v \n"
"      end \n"
"    end \n"
"  end \n"
"end \n"
"  \n"
"function bind_lua_buildcompattag(ti, parent) \n"
"  if not parent or not parent.n then return end \n"
"  local i \n"
"  ti.compattag[ti.vtable] = ti \n"
"  for i=1,parent.n,1 do \n"
"    if parent[i] and parent[i].compattag then \n"
"      parent[i].compattag[ti.vtable] = ti \n"
"      ti.vtable[parent[i].id] = 1 \n"
"      bind_lua_buildcompattag(ti, parent[i]) \n"
"    end \n"
"  end \n"
"end \n"
" \n"
"function bind_lua_addtovtable(vtable, index, value) \n"
"  vtable[index] = value \n"
"  local ti = vtable.bind_lua_typeinfo \n"
"  if not ti or not ti.compattag then \n"
"    return \n"
"  end \n"
"  local tt = ti.compattag \n"
"  local i, v \n"
"  for i, v in pairs(tt) do \n"
"    local vt2 = v.vtable \n"
"    if not vt2[index] then \n"
"      bind_lua_addtovtable(vt2, index, value) \n"
"    end \n"
"  end \n"
"end \n"
);


/* End of template 3
 */
  
  /* Binding for class Fl */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "scheme", lua_call2_Fl__scheme },
    { "version", lua_call1_Fl__version },
    { "get_mouse", lua_call1_Fl__get_mouse },
    { "ready", lua_call1_Fl__ready },
    { "x", lua_call1_Fl__x },
    { "paste", lua_call2_Fl__paste },
    { "redraw", lua_call1_Fl__redraw },
    { "event_button3", lua_call1_Fl__event_button3 },
    { "get_font_name", lua_call1_Fl__get_font_name },
    { "event_dx", lua_call1_Fl__event_dx },
    { "event_button2", lua_call1_Fl__event_button2 },
    { "release", lua_call1_Fl__release },
    { "event_buttons", lua_call1_Fl__event_buttons },
    { "get_font", lua_call1_Fl__get_font },
    { "event_original_key", lua_call1_Fl__event_original_key },
    { "event", lua_call1_Fl__event },
    { "readqueue", lua_call1_Fl__readqueue },
    { "delete_widget", lua_call1_Fl__delete_widget },
    { "get_system_colors", lua_call1_Fl__get_system_colors },
    { "h", lua_call1_Fl__h },
    { "pushed", lua_call2_Fl__pushed },
    { "damage", lua_call2_Fl__damage },
    { "next_window", lua_call1_Fl__next_window },
    { "event_alt", lua_call1_Fl__event_alt },
    { "wait", lua_call2_Fl__wait },
    { "belowmouse", lua_call2_Fl__belowmouse },
    { "event_y_root", lua_call1_Fl__event_y_root },
    { "clear_widget_pointer", lua_call1_Fl__clear_widget_pointer },
    { "y", lua_call1_Fl__y },
    { "selection", lua_call1_Fl__selection },
    { "do_widget_deletion", lua_call1_Fl__do_widget_deletion },
    { "screen_xywh", lua_call3_Fl__screen_xywh },
    { "dnd", lua_call1_Fl__dnd },
    { "reload_scheme", lua_call1_Fl__reload_scheme },
    { "event_length", lua_call1_Fl__event_length },
    { "event_x_root", lua_call1_Fl__event_x_root },
    { "handle", lua_call1_Fl__handle },
    { "compose", lua_call1_Fl__compose },
    { "get_key", lua_call1_Fl__get_key },
    { "set_color", lua_call2_Fl__set_color },
    { "visual", lua_call1_Fl__visual },
    { "box_dx", lua_call1_Fl__box_dx },
    { "set_font", lua_call2_Fl__set_font },
    { "event_x", lua_call1_Fl__event_x },
    { "box_dy", lua_call1_Fl__box_dy },
    { "event_state", lua_call2_Fl__event_state },
    { "draw_box_active", lua_call1_Fl__draw_box_active },
    { "background2", lua_call1_Fl__background2 },
    { "box_dw", lua_call1_Fl__box_dw },
    { "event_clicks", lua_call2_Fl__event_clicks },
    { "event_button", lua_call1_Fl__event_button },
    { "compose_reset", lua_call1_Fl__compose_reset },
    { "visible_focus", lua_call2_Fl__visible_focus },
    { "event_key", lua_call2_Fl__event_key },
    { "background", lua_call1_Fl__background },
    { "run", lua_call1_Fl__run },
    { "own_colormap", lua_call1_Fl__own_colormap },
    { "remove_fd", lua_call2_Fl__remove_fd },
    { "event_inside", lua_call2_Fl__event_inside },
    { "event_dy", lua_call1_Fl__event_dy },
    { "foreground", lua_call1_Fl__foreground },
    { "focus", lua_call2_Fl__focus },
    { "first_window", lua_call2_Fl__first_window },
    { "check", lua_call1_Fl__check },
    { "set_fonts", lua_call1_Fl__set_fonts },
    { "modal", lua_call1_Fl__modal },
    { "screen_count", lua_call1_Fl__screen_count },
    { "event_is_click", lua_call2_Fl__event_is_click },
    { "get_color", lua_call2_Fl__get_color },
    { "set_boxtype", lua_call1_Fl__set_boxtype },
    { "box_dh", lua_call1_Fl__box_dh },
    { "selection_owner", lua_call2_Fl__selection_owner },
    { "test_shortcut", lua_call1_Fl__test_shortcut },
    { "scrollbar_size", lua_call2_Fl__scrollbar_size },
    { "event_y", lua_call1_Fl__event_y },
    { "copy", lua_call1_Fl__copy },
    { "display", lua_call1_Fl__display },
    { "event_ctrl", lua_call1_Fl__event_ctrl },
    { "dnd_text_ops", lua_call2_Fl__dnd_text_ops },
    { "event_shift", lua_call1_Fl__event_shift },
    { "flush", lua_call1_Fl__flush },
    { "grab", lua_call3_Fl__grab },
    { "event_button1", lua_call1_Fl__event_button1 },
    { "w", lua_call1_Fl__w },
    { "event_text", lua_call1_Fl__event_text },
    { "delete", lua_delete_Fl },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl", &type__Fl, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Help_Dialog */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "h", lua_call1_Fl_Help_Dialog__h },
    { "show", lua_call1_Fl_Help_Dialog__show },
    { "textsize", lua_call2_Fl_Help_Dialog__textsize },
    { "position", lua_call1_Fl_Help_Dialog__position },
    { "visible", lua_call1_Fl_Help_Dialog__visible },
    { "load", lua_call1_Fl_Help_Dialog__load },
    { "x", lua_call1_Fl_Help_Dialog__x },
    { "y", lua_call1_Fl_Help_Dialog__y },
    { "w", lua_call1_Fl_Help_Dialog__w },
    { "hide", lua_call1_Fl_Help_Dialog__hide },
    { "resize", lua_call1_Fl_Help_Dialog__resize },
    { "value", lua_call2_Fl_Help_Dialog__value },
    { "topline", lua_call2_Fl_Help_Dialog__topline },
    { "Fl_Help_Dialog", lua_call1_Fl_Help_Dialog__Fl_Help_Dialog },
    { "delete", lua_delete_Fl_Help_Dialog },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Help_Dialog", &type__Fl_Help_Dialog, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for struct Fl_Text_Display__Style_Table_Entry */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Style_Table_Entry", lua_new_Fl_Text_Display__Style_Table_Entry },
    { "delete", lua_delete_Fl_Text_Display__Style_Table_Entry },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Text_Display__Style_Table_Entry", &type__Fl_Text_Display__Style_Table_Entry, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_End */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_End", lua_call1_Fl_End__Fl_End },
    { "delete", lua_delete_Fl_End },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_End", &type__Fl_End, parents, funcs, gets, sets, enums);
  }
  
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Menu", lua_new_Fl_Menu },
    { "delete", lua_delete_Fl_Menu },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Menu", &type__Fl_Menu, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Widget */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "serial", lua_call1_Fl_Widget__serial },
    { "labeltype", lua_call2_Fl_Widget__labeltype },
    { "set_visible_focus", lua_call1_Fl_Widget__set_visible_focus },
    { "takesevents", lua_call1_Fl_Widget__takesevents },
    { "w", lua_call1_Fl_Widget__w },
    { "draw", lua_call1_Fl_Widget__draw },
    { "y", lua_call1_Fl_Widget__y },
    { "deimage", lua_call3_Fl_Widget__deimage },
    { "draw_label", lua_call1_Fl_Widget__draw_label },
    { "contains", lua_call1_Fl_Widget__contains },
    { "redraw", lua_call1_Fl_Widget__redraw },
    { "handle", lua_call1_Fl_Widget__handle },
    { "selection_color", lua_call2_Fl_Widget__selection_color },
    { "visible", lua_call1_Fl_Widget__visible },
    { "window", lua_call1_Fl_Widget__window },
    { "damage_resize", lua_call1_Fl_Widget__damage_resize },
    { "inside", lua_call1_Fl_Widget__inside },
    { "parent", lua_call2_Fl_Widget__parent },
    { "clear_output", lua_call1_Fl_Widget__clear_output },
    { "labelfont", lua_call2_Fl_Widget__labelfont },
    { "label_shortcut", lua_call1_Fl_Widget__label_shortcut },
    { "box", lua_call2_Fl_Widget__box },
    { "deactivate", lua_call1_Fl_Widget__deactivate },
    { "set_output", lua_call1_Fl_Widget__set_output },
    { "resize", lua_call1_Fl_Widget__resize },
    { "measure_label", lua_call1_Fl_Widget__measure_label },
    { "visible_focus", lua_call2_Fl_Widget__visible_focus },
    { "show", lua_call1_Fl_Widget__show },
    { "color", lua_call3_Fl_Widget__color },
    { "x", lua_call1_Fl_Widget__x },
    { "active", lua_call1_Fl_Widget__active },
    { "hide", lua_call1_Fl_Widget__hide },
    { "do_callback", lua_call3_Fl_Widget__do_callback },
    { "labelsize", lua_call2_Fl_Widget__labelsize },
    { "output", lua_call1_Fl_Widget__output },
    { "set_visible", lua_call1_Fl_Widget__set_visible },
    { "activate", lua_call1_Fl_Widget__activate },
    { "clear_damage", lua_call1_Fl_Widget__clear_damage },
    { "type", lua_call2_Fl_Widget__type },
    { "align", lua_call2_Fl_Widget__align },
    { "clear_visible_focus", lua_call1_Fl_Widget__clear_visible_focus },
    { "test_shortcut", lua_call2_Fl_Widget__test_shortcut },
    { "clear_visible", lua_call1_Fl_Widget__clear_visible },
    { "image", lua_call3_Fl_Widget__image },
    { "visible_r", lua_call1_Fl_Widget__visible_r },
    { "damage", lua_call3_Fl_Widget__damage },
    { "redraw_label", lua_call1_Fl_Widget__redraw_label },
    { "changed", lua_call1_Fl_Widget__changed },
    { "size", lua_call1_Fl_Widget__size },
    { "take_focus", lua_call1_Fl_Widget__take_focus },
    { "copy_label", lua_call1_Fl_Widget__copy_label },
    { "label", lua_call3_Fl_Widget__label },
    { "position", lua_call1_Fl_Widget__position },
    { "labelcolor", lua_call2_Fl_Widget__labelcolor },
    { "argument", lua_call2_Fl_Widget__argument },
    { "clear_changed", lua_call1_Fl_Widget__clear_changed },
    { "set_changed", lua_call1_Fl_Widget__set_changed },
    { "color2", lua_call2_Fl_Widget__color2 },
    { "active_r", lua_call1_Fl_Widget__active_r },
    { "tooltip", lua_call2_Fl_Widget__tooltip },
    { "h", lua_call1_Fl_Widget__h },
    { "when", lua_call2_Fl_Widget__when },
    { "delete", lua_delete_Fl_Widget },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Widget", &type__Fl_Widget, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for struct FL_CHART_ENTRY */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "FL_CHART_ENTRY", lua_new_FL_CHART_ENTRY },
    { "delete", lua_delete_FL_CHART_ENTRY },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { 0 };
  
  lua_fltk_init_type(__S__, 0, "FL_CHART_ENTRY", &type__FL_CHART_ENTRY, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for struct FL_BLINE */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { 0 };
  
  lua_fltk_init_type(__S__, 0, "FL_BLINE", &type__FL_BLINE, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for struct Fl_Menu_Item */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "serial", lua_call1_Fl_Menu_Item__serial },
    { "checkbox", lua_call1_Fl_Menu_Item__checkbox },
    { "set", lua_call1_Fl_Menu_Item__set },
    { "image", lua_call2_Fl_Menu_Item__image },
    { "do_callback", lua_call3_Fl_Menu_Item__do_callback },
    { "uncheck", lua_call1_Fl_Menu_Item__uncheck },
    { "labeltype", lua_call2_Fl_Menu_Item__labeltype },
    { "argument", lua_call2_Fl_Menu_Item__argument },
    { "radio", lua_call1_Fl_Menu_Item__radio },
    { "find_shortcut", lua_call1_Fl_Menu_Item__find_shortcut },
    { "activate", lua_call1_Fl_Menu_Item__activate },
    { "size", lua_call1_Fl_Menu_Item__size },
    { "show", lua_call1_Fl_Menu_Item__show },
    { "shortcut", lua_call2_Fl_Menu_Item__shortcut },
    { "deactivate", lua_call1_Fl_Menu_Item__deactivate },
    { "labelsize", lua_call2_Fl_Menu_Item__labelsize },
    { "activevisible", lua_call1_Fl_Menu_Item__activevisible },
    { "next", lua_call1_Fl_Menu_Item__next },
    { "hide", lua_call1_Fl_Menu_Item__hide },
    { "test_shortcut", lua_call1_Fl_Menu_Item__test_shortcut },
    { "visible", lua_call1_Fl_Menu_Item__visible },
    { "active", lua_call1_Fl_Menu_Item__active },
    { "pulldown", lua_call1_Fl_Menu_Item__pulldown },
    { "first", lua_call1_Fl_Menu_Item__first },
    { "check", lua_call1_Fl_Menu_Item__check },
    { "submenu", lua_call1_Fl_Menu_Item__submenu },
    { "draw", lua_call1_Fl_Menu_Item__draw },
    { "labelfont", lua_call2_Fl_Menu_Item__labelfont },
    { "value", lua_call1_Fl_Menu_Item__value },
    { "label", lua_call3_Fl_Menu_Item__label },
    { "popup", lua_call1_Fl_Menu_Item__popup },
    { "setonly", lua_call1_Fl_Menu_Item__setonly },
    { "checked", lua_call1_Fl_Menu_Item__checked },
    { "clear", lua_call1_Fl_Menu_Item__clear },
    { "labelcolor", lua_call2_Fl_Menu_Item__labelcolor },
    { "Fl_Menu_Item", lua_new_Fl_Menu_Item },
    { "delete", lua_delete_Fl_Menu_Item },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Menu_Item", &type__Fl_Menu_Item, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_murgaLuaOffScreen */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_murgaLuaOffScreen", lua_call1_Fl_murgaLuaOffScreen__Fl_murgaLuaOffScreen },
    { "endOffScreenDrawing", lua_call1_Fl_murgaLuaOffScreen__endOffScreenDrawing },
    { "startOffScreenDrawing", lua_call1_Fl_murgaLuaOffScreen__startOffScreenDrawing },
    { "getOffScreenImage", lua_call1_Fl_murgaLuaOffScreen__getOffScreenImage },
    { "delete", lua_delete_Fl_murgaLuaOffScreen },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_murgaLuaOffScreen", &type__Fl_murgaLuaOffScreen, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for struct Fl_Label */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "measure", lua_call1_Fl_Label__measure },
    { "draw", lua_call1_Fl_Label__draw },
    { "Fl_Label", lua_new_Fl_Label },
    { "delete", lua_delete_Fl_Label },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Label", &type__Fl_Label, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Preferences__Name */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Name", lua_call2_Fl_Preferences__Name__Name },
    { "delete", lua_delete_Fl_Preferences__Name },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Preferences__Name", &type__Fl_Preferences__Name, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for struct Fl_Check_Browser__cb_item */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "cb_item", lua_new_Fl_Check_Browser__cb_item },
    { "delete", lua_delete_Fl_Check_Browser__cb_item },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Check_Browser__cb_item", &type__Fl_Check_Browser__cb_item, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_File_Icon */
  {
  static enumdecl_t enums[] = {
    { "ANY", Fl_File_Icon::ANY },
    { "PLAIN", Fl_File_Icon::PLAIN },
    { "DIRECTORY", Fl_File_Icon::DIRECTORY },
    { "FIFO", Fl_File_Icon::FIFO },
    { "CLOSEDLINE", Fl_File_Icon::CLOSEDLINE },
    { "VERTEX", Fl_File_Icon::VERTEX },
    { "DEVICE", Fl_File_Icon::DEVICE },
    { "LINE", Fl_File_Icon::LINE },
    { "END", Fl_File_Icon::END },
    { "LINK", Fl_File_Icon::LINK },
    { "POLYGON", Fl_File_Icon::POLYGON },
    { "COLOR", Fl_File_Icon::COLOR },
    { "OUTLINEPOLYGON", Fl_File_Icon::OUTLINEPOLYGON },
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "label", lua_call1_Fl_File_Icon__label },
    { "pattern", lua_call1_Fl_File_Icon__pattern },
    { "clear", lua_call1_Fl_File_Icon__clear },
    { "find", lua_call1_Fl_File_Icon__find },
    { "load_fti", lua_call1_Fl_File_Icon__load_fti },
    { "size", lua_call1_Fl_File_Icon__size },
    { "next", lua_call1_Fl_File_Icon__next },
    { "labeltype", lua_call1_Fl_File_Icon__labeltype },
    { "load_image", lua_call1_Fl_File_Icon__load_image },
    { "type", lua_call1_Fl_File_Icon__type },
    { "load", lua_call1_Fl_File_Icon__load },
    { "load_system_icons", lua_call1_Fl_File_Icon__load_system_icons },
    { "first", lua_call1_Fl_File_Icon__first },
    { "draw", lua_call1_Fl_File_Icon__draw },
    { "Fl_File_Icon", lua_call1_Fl_File_Icon__Fl_File_Icon },
    { "delete", lua_delete_Fl_File_Icon },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_File_Icon", &type__Fl_File_Icon, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for struct Fl_Preferences__Entry */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Entry", lua_new_Fl_Preferences__Entry },
    { "delete", lua_delete_Fl_Preferences__Entry },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Preferences__Entry", &type__Fl_Preferences__Entry, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_File_Chooser */
  {
  static enumdecl_t enums[] = {
    { "CREATE", Fl_File_Chooser::CREATE },
    { "DIRECTORY", Fl_File_Chooser::DIRECTORY },
    { "SINGLE", Fl_File_Chooser::SINGLE },
    { "MULTI", Fl_File_Chooser::MULTI },
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "color", lua_call2_Fl_File_Chooser__color },
    { "filter_value", lua_call2_Fl_File_Chooser__filter_value },
    { "Fl_File_Chooser", lua_call1_Fl_File_Chooser__Fl_File_Chooser },
    { "count", lua_call1_Fl_File_Chooser__count },
    { "rescan", lua_call1_Fl_File_Chooser__rescan },
    { "iconsize", lua_call2_Fl_File_Chooser__iconsize },
    { "label", lua_call2_Fl_File_Chooser__label },
    { "visible", lua_call1_Fl_File_Chooser__visible },
    { "directory", lua_call2_Fl_File_Chooser__directory },
    { "preview", lua_call2_Fl_File_Chooser__preview },
    { "shown", lua_call1_Fl_File_Chooser__shown },
    { "value", lua_call2_Fl_File_Chooser__value },
    { "filter", lua_call2_Fl_File_Chooser__filter },
    { "ok_label", lua_call2_Fl_File_Chooser__ok_label },
    { "hide", lua_call1_Fl_File_Chooser__hide },
    { "textcolor", lua_call2_Fl_File_Chooser__textcolor },
    { "show", lua_call1_Fl_File_Chooser__show },
    { "textfont", lua_call2_Fl_File_Chooser__textfont },
    { "textsize", lua_call2_Fl_File_Chooser__textsize },
    { "type", lua_call2_Fl_File_Chooser__type },
    { "rescan_keep_filename", lua_call1_Fl_File_Chooser__rescan_keep_filename },
    { "delete", lua_delete_Fl_File_Chooser },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_File_Chooser", &type__Fl_File_Chooser, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Preferences */
  {
  static enumdecl_t enums[] = {
    { "SYSTEM", Fl_Preferences::SYSTEM },
    { "USER", Fl_Preferences::USER },
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "deleteEntry", lua_call1_Fl_Preferences__deleteEntry },
    { "Fl_Preferences", lua_call4_Fl_Preferences__Fl_Preferences },
    { "entries", lua_call1_Fl_Preferences__entries },
    { "flush", lua_call1_Fl_Preferences__flush },
    { "Name", lua_call2_Fl_Preferences__Name__Name },
    { "groups", lua_call1_Fl_Preferences__groups },
    { "entry", lua_call1_Fl_Preferences__entry },
    { "get", lua_call6_Fl_Preferences__get },
    { "group", lua_call1_Fl_Preferences__group },
    { "groupExists", lua_call1_Fl_Preferences__groupExists },
    { "entryExists", lua_call1_Fl_Preferences__entryExists },
    { "set", lua_call7_Fl_Preferences__set },
    { "size", lua_call1_Fl_Preferences__size },
    { "deleteGroup", lua_call1_Fl_Preferences__deleteGroup },
    { "getUserdataPath", lua_call1_Fl_Preferences__getUserdataPath },
    { "delete", lua_delete_Fl_Preferences },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Preferences", &type__Fl_Preferences, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Image */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "data", lua_call1_Fl_Image__data },
    { "getTiles", lua_call1_Fl_RGB_Image__getTiles },
    { "h", lua_call1_Fl_Image__h },
    { "label", lua_call2_Fl_Image__label },
    { "uncache", lua_call1_Fl_Image__uncache },
    { "ld", lua_call1_Fl_Image__ld },
    { "copy", lua_call2_Fl_Image__copy },
    { "d", lua_call1_Fl_Image__d },
    { "w", lua_call1_Fl_Image__w },
    { "inactive", lua_call1_Fl_Image__inactive },
    { "count", lua_call1_Fl_Image__count },
    { "draw", lua_call2_Fl_Image__draw },
    { "color_average", lua_call1_Fl_Image__color_average },
    { "desaturate", lua_call1_Fl_Image__desaturate },
    { "Fl_Image", lua_call1_Fl_Image__Fl_Image },
    { "delete", lua_delete_Fl_Image },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Image", &type__Fl_Image, parents, funcs, gets, sets, enums);
  }
  
  /* Global namespace of the module */
  {
  static enumdecl_t enums[] = {
    { "FL_MAGENTA", FL_MAGENTA },
    { "FL_OFLAT_BOX", _FL_OFLAT_BOX },
    { "FL_DIAMOND_UP_BOX", _FL_DIAMOND_UP_BOX },
    { "FL_DARK_GREEN", FL_DARK_GREEN },
    { "FL_ALIGN_TEXT_OVER_IMAGE", FL_ALIGN_TEXT_OVER_IMAGE },
    { "FL_ALIGN_RIGHT_BOTTOM", FL_ALIGN_RIGHT_BOTTOM },
    { "FL_CURSOR_NE", FL_CURSOR_NE },
    { "FL_FLAT_BOX", FL_FLAT_BOX },
    { "FL_NO_LABEL", FL_NO_LABEL },
    { "FL_PUSH", FL_PUSH },
    { "FL_ALIGN_BOTTOM_LEFT", FL_ALIGN_BOTTOM_LEFT },
    { "FL_KEYUP", FL_KEYUP },
    { "FL_MOVE", FL_MOVE },
    { "FL_ACTIVATE", FL_ACTIVATE },
    { "FL_GTK_ROUND_UP_BOX", _FL_GTK_ROUND_UP_BOX },
    { "FL_LIGHT1", FL_LIGHT1 },
    { "FL_MOUSEWHEEL", FL_MOUSEWHEEL },
    { "FL_GRAY0", FL_GRAY0 },
    { "FL_GTK_THIN_DOWN_BOX", _FL_GTK_THIN_DOWN_BOX },
    { "FL_ALIGN_LEFT_TOP", FL_ALIGN_LEFT_TOP },
    { "FL_ALPHA", FL_ALPHA },
    { "FL_DAMAGE_USER1", FL_DAMAGE_USER1 },
    { "FL_DRAG", FL_DRAG },
    { "FL_EXCEPT", FL_EXCEPT },
    { "FL_THIN_UP_FRAME", FL_THIN_UP_FRAME },
    { "FL_TIMES_BOLD", FL_TIMES_BOLD },
    { "FL_SINGLE", FL_SINGLE },
    { "FL_ALIGN_TOP", FL_ALIGN_TOP },
    { "FL_PUP_SUBMENU", FL_PUP_SUBMENU },
    { "FL_STENCIL", FL_STENCIL },
    { "FL_CURSOR_WAIT", FL_CURSOR_WAIT },
    { "FL_COURIER_BOLD", FL_COURIER_BOLD },
    { "FL_MENU_BOX", FL_MENU_BOX },
    { "FL_DARK_YELLOW", FL_DARK_YELLOW },
    { "FL_CURSOR_INSERT", FL_CURSOR_INSERT },
    { "FL_DASHDOTDOT", FL_DASHDOTDOT },
    { "FL_MENU_RADIO", FL_MENU_RADIO },
    { "FL_DARK_BLUE", FL_DARK_BLUE },
    { "FL_JOIN_BEVEL", FL_JOIN_BEVEL },
    { "FL_MULTI_LABEL", _FL_MULTI_LABEL },
    { "FL_BLUE", FL_BLUE },
    { "FL_HIDE", FL_HIDE },
    { "FL_MENU_INACTIVE", FL_MENU_INACTIVE },
    { "FL_CURSOR_SW", FL_CURSOR_SW },
    { "FL_SHOW", FL_SHOW },
    { "FL_JOIN_ROUND", FL_JOIN_ROUND },
    { "FL_ROUND_UP_BOX", _FL_ROUND_UP_BOX },
    { "FL_BACKGROUND_COLOR", FL_BACKGROUND_COLOR },
    { "FL_DARK_MAGENTA", FL_DARK_MAGENTA },
    { "FL_BEEP_NOTIFICATION", FL_BEEP_NOTIFICATION },
    { "FL_PUP_GRAY", FL_PUP_GRAY },
    { "FL_MULTISAMPLE", FL_MULTISAMPLE },
    { "FL_CURSOR_MOVE", FL_CURSOR_MOVE },
    { "FL_CURSOR_SE", FL_CURSOR_SE },
    { "FL_DAMAGE_ALL", FL_DAMAGE_ALL },
    { "FL_FREE_BOXTYPE", FL_FREE_BOXTYPE },
    { "FL_OSHADOW_BOX", _FL_OSHADOW_BOX },
    { "FL_PUP_BOX", FL_PUP_BOX },
    { "FL_CLOSE", FL_CLOSE },
    { "FL_ROUNDED_BOX", _FL_ROUNDED_BOX },
    { "FL_PUP_CHECK", FL_PUP_CHECK },
    { "FL_DASH", FL_DASH },
    { "FL_MENU_DIVIDER", FL_MENU_DIVIDER },
    { "FL_WHEN_RELEASE", FL_WHEN_RELEASE },
    { "FL_RELEASE", FL_RELEASE },
    { "FL_DEPTH", FL_DEPTH },
    { "FL_CURSOR_N", FL_CURSOR_N },
    { "FL_CURSOR_NESW", FL_CURSOR_NESW },
    { "FL_SCREEN", FL_SCREEN },
    { "FL_NO_BOX", FL_NO_BOX },
    { "FL_DARK3", FL_DARK3 },
    { "FL_RGB8", FL_RGB8 },
    { "FL_LEAVE", FL_LEAVE },
    { "FL_INDEX", FL_INDEX },
    { "FL_CURSOR_NW", FL_CURSOR_NW },
    { "FL_ENGRAVED_LABEL", _FL_ENGRAVED_LABEL },
    { "FL_GTK_DOWN_BOX", _FL_GTK_DOWN_BOX },
    { "FL_ALIGN_CENTER", FL_ALIGN_CENTER },
    { "FL_DEACTIVATE", FL_DEACTIVATE },
    { "FL_MENU_INVISIBLE", FL_MENU_INVISIBLE },
    { "FL_WRITE", FL_WRITE },
    { "FL_CURSOR_HELP", FL_CURSOR_HELP },
    { "FL_WHEN_ENTER_KEY", FL_WHEN_ENTER_KEY },
    { "FL_ALIGN_INSIDE", FL_ALIGN_INSIDE },
    { "FL_ICON_LABEL", _FL_ICON_LABEL },
    { "FL_SYMBOL", FL_SYMBOL },
    { "FL_BACKGROUND2_COLOR", FL_BACKGROUND2_COLOR },
    { "FL_READ", FL_READ },
    { "FL_THIN_DOWN_BOX", FL_THIN_DOWN_BOX },
    { "FL_ALIGN_BOTTOM", FL_ALIGN_BOTTOM },
    { "FL_WHEN_CHANGED", FL_WHEN_CHANGED },
    { "FL_STEREO", FL_STEREO },
    { "FL_NO_EVENT", FL_NO_EVENT },
    { "FL_LIGHT3", FL_LIGHT3 },
    { "FL_PASTE", FL_PASTE },
    { "FL_DARK_CYAN", FL_DARK_CYAN },
    { "FL_EMBOSSED_LABEL", _FL_EMBOSSED_LABEL },
    { "FL_COURIER_BOLD_ITALIC", FL_COURIER_BOLD_ITALIC },
    { "FL_SHADOW_LABEL", _FL_SHADOW_LABEL },
    { "FL_COURIER_ITALIC", FL_COURIER_ITALIC },
    { "FL_PUP_INVISIBLE", FL_PUP_INVISIBLE },
    { "FL_CURSOR_S", FL_CURSOR_S },
    { "FL_CAP_FLAT", FL_CAP_FLAT },
    { "FL_ZAPF_DINGBATS", FL_ZAPF_DINGBATS },
    { "FL_ROUNDED_FRAME", _FL_ROUNDED_FRAME },
    { "FL_MENU_VALUE", FL_MENU_VALUE },
    { "FL_ALIGN_NOWRAP", FL_ALIGN_NOWRAP },
    { "FL_CAP_SQUARE", FL_CAP_SQUARE },
    { "FL_HELVETICA_ITALIC", FL_HELVETICA_ITALIC },
    { "FL_EMBOSSED_BOX", FL_EMBOSSED_BOX },
    { "FL_DND_DRAG", FL_DND_DRAG },
    { "FL_GTK_UP_FRAME", _FL_GTK_UP_FRAME },
    { "FL_SOLID", FL_SOLID },
    { "FL_CURSOR_CROSS", FL_CURSOR_CROSS },
    { "FL_PLASTIC_DOWN_BOX", _FL_PLASTIC_DOWN_BOX },
    { "FL_GTK_THIN_DOWN_FRAME", _FL_GTK_THIN_DOWN_FRAME },
    { "FL_GTK_UP_BOX", _FL_GTK_UP_BOX },
    { "FL_HELVETICA_BOLD", FL_HELVETICA_BOLD },
    { "FL_OVAL_FRAME", _FL_OVAL_FRAME },
    { "FL_PLASTIC_ROUND_DOWN_BOX", _FL_PLASTIC_ROUND_DOWN_BOX },
    { "FL_BEEP_ERROR", FL_BEEP_ERROR },
    { "FL_UP_BOX", FL_UP_BOX },
    { "FL_WHEN_RELEASE_ALWAYS", FL_WHEN_RELEASE_ALWAYS },
    { "FL_SHADOW_FRAME", _FL_SHADOW_FRAME },
    { "FL_BEEP_QUESTION", FL_BEEP_QUESTION },
    { "FL_PLASTIC_UP_FRAME", _FL_PLASTIC_UP_FRAME },
    { "FL_ROUND_DOWN_BOX", _FL_ROUND_DOWN_BOX },
    { "FL_PLASTIC_THIN_DOWN_BOX", _FL_PLASTIC_THIN_DOWN_BOX },
    { "FL_THIN_DOWN_FRAME", FL_THIN_DOWN_FRAME },
    { "FL_CURSOR_E", FL_CURSOR_E },
    { "FL_ALIGN_RIGHT_TOP", FL_ALIGN_RIGHT_TOP },
    { "FL_CYAN", FL_CYAN },
    { "FL_WHITE", FL_WHITE },
    { "FL_UP_FRAME", FL_UP_FRAME },
    { "FL_ITALIC", FL_ITALIC },
    { "FL_ENTER", FL_ENTER },
    { "FL_SHORTCUT", FL_SHORTCUT },
    { "FL_MENU_CHECK", FL_MENU_CHECK },
    { "FL_CURSOR_ARROW", FL_CURSOR_ARROW },
    { "FL_CURSOR_DEFAULT", FL_CURSOR_DEFAULT },
    { "FL_NORMAL_LABEL", FL_NORMAL_LABEL },
    { "FL_JOIN_MITER", FL_JOIN_MITER },
    { "FL_DASHDOT", FL_DASHDOT },
    { "FL_DOT", FL_DOT },
    { "FL_BEEP_PASSWORD", FL_BEEP_PASSWORD },
    { "FL_BEEP_MESSAGE", FL_BEEP_MESSAGE },
    { "FL_BEEP_DEFAULT", FL_BEEP_DEFAULT },
    { "FL_ALIGN_IMAGE_OVER_TEXT", FL_ALIGN_IMAGE_OVER_TEXT },
    { "FL_CURSOR_NS", FL_CURSOR_NS },
    { "FL_CURSOR_WE", FL_CURSOR_WE },
    { "FL_DARK_RED", FL_DARK_RED },
    { "FL_DND_ENTER", FL_DND_ENTER },
    { "FL_RGB", FL_RGB },
    { "FL_DOUBLE", FL_DOUBLE },
    { "FL_PLASTIC_UP_BOX", _FL_PLASTIC_UP_BOX },
    { "FL_BOLD", FL_BOLD },
    { "FL_TIMES", FL_TIMES },
    { "FL_SUBMENU", FL_SUBMENU },
    { "FL_WHEN_ENTER_KEY_ALWAYS", FL_WHEN_ENTER_KEY_ALWAYS },
    { "FL_CURSOR_W", FL_CURSOR_W },
    { "FL_FOREGROUND_COLOR", FL_FOREGROUND_COLOR },
    { "FL_PUP_RADIO", FL_PUP_RADIO },
    { "FL_MENU_TOGGLE", FL_MENU_TOGGLE },
    { "FL_PLASTIC_THIN_UP_BOX", _FL_PLASTIC_THIN_UP_BOX },
    { "FL_DAMAGE_CHILD", FL_DAMAGE_CHILD },
    { "FL_ACCUM", FL_ACCUM },
    { "FL_DOWN_BOX", FL_DOWN_BOX },
    { "FL_ALIGN_TOP_LEFT", FL_ALIGN_TOP_LEFT },
    { "FL_ENGRAVED_BOX", FL_ENGRAVED_BOX },
    { "FL_DIAMOND_DOWN_BOX", _FL_DIAMOND_DOWN_BOX },
    { "FL_FOCUS", FL_FOCUS },
    { "FL_EMBOSSED_FRAME", FL_EMBOSSED_FRAME },
    { "FL_RED", FL_RED },
    { "FL_WHEN_NEVER", FL_WHEN_NEVER },
    { "FL_IMAGE_LABEL", _FL_IMAGE_LABEL },
    { "FL_LIGHT2", FL_LIGHT2 },
    { "FL_INACTIVE_COLOR", FL_INACTIVE_COLOR },
    { "FL_PLASTIC_DOWN_FRAME", _FL_PLASTIC_DOWN_FRAME },
    { "FL_DARK2", FL_DARK2 },
    { "FL_SUBMENU_POINTER", FL_SUBMENU_POINTER },
    { "FL_DND_LEAVE", FL_DND_LEAVE },
    { "FL_TIMES_BOLD_ITALIC", FL_TIMES_BOLD_ITALIC },
    { "FL_WHEN_ENTER_KEY_CHANGED", FL_WHEN_ENTER_KEY_CHANGED },
    { "FL_DAMAGE_USER2", FL_DAMAGE_USER2 },
    { "FL_UNFOCUS", FL_UNFOCUS },
    { "FL_ALIGN_RIGHT", FL_ALIGN_RIGHT },
    { "FL_DARK1", FL_DARK1 },
    { "FL_FREE_FONT", FL_FREE_FONT },
    { "FL_HELVETICA_BOLD_ITALIC", FL_HELVETICA_BOLD_ITALIC },
    { "FL_CURSOR_HAND", FL_CURSOR_HAND },
    { "FL_GTK_THIN_UP_FRAME", _FL_GTK_THIN_UP_FRAME },
    { "FL_BLACK", FL_BLACK },
    { "FL_GREEN", FL_GREEN },
    { "FL_FREE_LABELTYPE", FL_FREE_LABELTYPE },
    { "FL_DAMAGE_EXPOSE", FL_DAMAGE_EXPOSE },
    { "FL_ALIGN_BOTTOM_RIGHT", FL_ALIGN_BOTTOM_RIGHT },
    { "FL_TIMES_ITALIC", FL_TIMES_ITALIC },
    { "FL_DND_RELEASE", FL_DND_RELEASE },
    { "FL_CURSOR_NONE", FL_CURSOR_NONE },
    { "FL_SELECTIONCLEAR", FL_SELECTIONCLEAR },
    { "FL_BORDER_FRAME", FL_BORDER_FRAME },
    { "FL_YELLOW", FL_YELLOW },
    { "FL_SHADOW_BOX", _FL_SHADOW_BOX },
    { "FL_DAMAGE_SCROLL", FL_DAMAGE_SCROLL },
    { "FL_ALIGN_WRAP", FL_ALIGN_WRAP },
    { "FL_GTK_ROUND_DOWN_BOX", _FL_GTK_ROUND_DOWN_BOX },
    { "FL_HELVETICA", FL_HELVETICA },
    { "FL_GTK_THIN_UP_BOX", _FL_GTK_THIN_UP_BOX },
    { "FL_WHEN_NOT_CHANGED", FL_WHEN_NOT_CHANGED },
    { "FL_RFLAT_BOX", _FL_RFLAT_BOX },
    { "FL_MENU_HORIZONTAL", FL_MENU_HORIZONTAL },
    { "FL_ENGRAVED_FRAME", FL_ENGRAVED_FRAME },
    { "FL_PUP_NONE", FL_PUP_NONE },
    { "FL_COURIER", FL_COURIER },
    { "FL_RSHADOW_BOX", _FL_RSHADOW_BOX },
    { "FL_DAMAGE_OVERLAY", FL_DAMAGE_OVERLAY },
    { "FL_CURSOR_NWSE", FL_CURSOR_NWSE },
    { "FL_SCREEN_BOLD", FL_SCREEN_BOLD },
    { "FL_CAP_ROUND", FL_CAP_ROUND },
    { "FL_FAKE_SINGLE", FL_FAKE_SINGLE },
    { "FL_GTK_DOWN_FRAME", _FL_GTK_DOWN_FRAME },
    { "FL_ALIGN_LEFT", FL_ALIGN_LEFT },
    { "FL_SELECTION_COLOR", FL_SELECTION_COLOR },
    { "FL_KEYDOWN", FL_KEYDOWN },
    { "FL_DOWN_FRAME", FL_DOWN_FRAME },
    { "FL_ALIGN_CLIP", FL_ALIGN_CLIP },
    { "FL_ALIGN_TOP_RIGHT", FL_ALIGN_TOP_RIGHT },
    { "FL_OVAL_BOX", _FL_OVAL_BOX },
    { "FL_BORDER_BOX", FL_BORDER_BOX },
    { "FL_PUP_GREY", FL_PUP_GREY },
    { "FL_PLASTIC_ROUND_UP_BOX", _FL_PLASTIC_ROUND_UP_BOX },
    { "FL_ALIGN_LEFT_BOTTOM", FL_ALIGN_LEFT_BOTTOM },
    { "FL_THIN_UP_BOX", FL_THIN_UP_BOX },
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Round_Button", lua_call1_Fl_Round_Button__Fl_Round_Button },
    { "fl_text_drag_me", lua_call1_fl_text_drag_me },
    { "Fl_Progress", lua_call1_Fl_Progress__Fl_Progress },
    { "Fl_Check_Browser", lua_call1_Fl_Check_Browser__Fl_Check_Browser },
    { "fl_push_no_clip", lua_call1_fl_push_no_clip },
    { "fl_define_FL_RSHADOW_BOX", lua_call1_fl_define_FL_RSHADOW_BOX },
    { "Fl_Dial", lua_call1_Fl_Dial__Fl_Dial },
    { "fl_begin_loop", lua_call1_fl_begin_loop },
    { "fl_mac_roman_to_local", lua_call1_fl_mac_roman_to_local },
    { "Fl_Clock", lua_call2_Fl_Clock__Fl_Clock },
    { "fl_filename_relative", lua_call2_fl_filename_relative },
    { "Fl_Tabs", lua_call1_Fl_Tabs__Fl_Tabs },
    { "Fl_Spinner", lua_call1_Fl_Spinner__Fl_Spinner },
    { "Fl_Output", lua_call1_Fl_Output__Fl_Output },
    { "Fl_Input_Choice", lua_call1_Fl_Input_Choice__Fl_Input_Choice },
    { "fl_down", lua_call1_fl_down },
    { "Fl_Hold_Browser", lua_call1_Fl_Hold_Browser__Fl_Hold_Browser },
    { "Fl_Clock_Output", lua_call1_Fl_Clock_Output__Fl_Clock_Output },
    { "Fl_End", lua_call1_Fl_End__Fl_End },
    { "fl_message_font", lua_call1_fl_message_font },
    { "fl_rgb_color", lua_call2_fl_rgb_color },
    { "Fl_Choice", lua_call1_Fl_Choice__Fl_Choice },
    { "fl_color", lua_call4_fl_color },
    { "fl_end_line", lua_call1_fl_end_line },
    { "Fl_GIF_Image", lua_call1_Fl_GIF_Image__Fl_GIF_Image },
    { "Fl_Value_Output", lua_call1_Fl_Value_Output__Fl_Value_Output },
    { "fl_define_FL_RFLAT_BOX", lua_call1_fl_define_FL_RFLAT_BOX },
    { "Fl_FormsBitmap", lua_call1_Fl_FormsBitmap__Fl_FormsBitmap },
    { "Fl_Secret_Input", lua_call1_Fl_Secret_Input__Fl_Secret_Input },
    { "fl_read_image", lua_call1_fl_read_image },
    { "fl_transform_dx", lua_call1_fl_transform_dx },
    { "fl_font", lua_call2_fl_font },
    { "Fl_RGB_Image", lua_call1_Fl_RGB_Image__Fl_RGB_Image },
    { "Fl_Chart", lua_call1_Fl_Chart__Fl_Chart },
    { "fl_filename_name", lua_call1_fl_filename_name },
    { "fl_point", lua_call1_fl_point },
    { "fl_circle", lua_call1_fl_circle },
    { "Fl_Round_Clock", lua_call1_Fl_Round_Clock__Fl_Round_Clock },
    { "Fl_Radio_Light_Button", lua_call1_Fl_Radio_Light_Button__Fl_Radio_Light_Button },
    { "fl_message_icon", lua_call1_fl_message_icon },
    { "fl_define_FL_ENGRAVED_LABEL", lua_call1_fl_define_FL_ENGRAVED_LABEL },
    { "Fl_Preferences", lua_call4_Fl_Preferences__Fl_Preferences },
    { "fl_end_points", lua_call1_fl_end_points },
    { "Fl_Scrollbar", lua_call1_Fl_Scrollbar__Fl_Scrollbar },
    { "Fl_File_Chooser", lua_call1_Fl_File_Chooser__Fl_File_Chooser },
    { "Fl_Pack", lua_call1_Fl_Pack__Fl_Pack },
    { "Fl_XBM_Image", lua_call1_Fl_XBM_Image__Fl_XBM_Image },
    { "Fl_BMP_Image", lua_call1_Fl_BMP_Image__Fl_BMP_Image },
    { "Fl_Fill_Dial", lua_call1_Fl_Fill_Dial__Fl_Fill_Dial },
    { "fl_loop", lua_call2_fl_loop },
    { "fl_filename_match", lua_call1_fl_filename_match },
    { "fl_define_FL_SHADOW_BOX", lua_call1_fl_define_FL_SHADOW_BOX },
    { "Fl_FormsPixmap", lua_call1_Fl_FormsPixmap__Fl_FormsPixmap },
    { "Fl_Menu_Bar", lua_call1_Fl_Menu_Bar__Fl_Menu_Bar },
    { "Fl_Hor_Value_Slider", lua_call1_Fl_Hor_Value_Slider__Fl_Hor_Value_Slider },
    { "Fl_Timer", lua_call1_Fl_Timer__Fl_Timer },
    { "fl_begin_polygon", lua_call1_fl_begin_polygon },
    { "Fl_Color_Chooser", lua_call1_Fl_Color_Chooser__Fl_Color_Chooser },
    { "fl_define_FL_DIAMOND_BOX", lua_call1_fl_define_FL_DIAMOND_BOX },
    { "Fl_Adjuster", lua_call1_Fl_Adjuster__Fl_Adjuster },
    { "fl_transform_x", lua_call1_fl_transform_x },
    { "Fl_Wizard", lua_call1_Fl_Wizard__Fl_Wizard },
    { "Fl_Double_Window", lua_call2_Fl_Double_Window__Fl_Double_Window },
    { "fl_open_uri", lua_call1_fl_open_uri },
    { "Fl_Multiline_Output", lua_call1_Fl_Multiline_Output__Fl_Multiline_Output },
    { "fl_draw_box", lua_call1_fl_draw_box },
    { "Fl_Value_Input", lua_call1_Fl_Value_Input__Fl_Value_Input },
    { "fl_transform_dy", lua_call1_fl_transform_dy },
    { "Fl_Slider", lua_call2_Fl_Slider__Fl_Slider },
    { "Fl_Multi_Browser", lua_call1_Fl_Multi_Browser__Fl_Multi_Browser },
    { "fl_filename_setext", lua_call2_fl_filename_setext },
    { "Fl_murgaLuaOffScreen", lua_call1_Fl_murgaLuaOffScreen__Fl_murgaLuaOffScreen },
    { "fl_register_images", lua_call1_fl_register_images },
    { "Fl_Text_Editor", lua_call1_Fl_Text_Editor__Fl_Text_Editor },
    { "fl_define_FL_SHADOW_LABEL", lua_call1_fl_define_FL_SHADOW_LABEL },
    { "Fl_Text_Display", lua_call1_Fl_Text_Display__Fl_Text_Display },
    { "fl_draw_symbol", lua_call1_fl_draw_symbol },
    { "fl_line_style", lua_call1_fl_line_style },
    { "fl_push_matrix", lua_call1_fl_push_matrix },
    { "Fl_Single_Window", lua_call2_Fl_Single_Window__Fl_Single_Window },
    { "fl_old_shortcut", lua_call1_fl_old_shortcut },
    { "fl_not_clipped", lua_call1_fl_not_clipped },
    { "Fl_Group", lua_call1_Fl_Group__Fl_Group },
    { "fl_draw_image_mono", lua_call2_fl_draw_image_mono },
    { "fl_translate", lua_call1_fl_translate },
    { "Fl_Select_Browser", lua_call1_Fl_Select_Browser__Fl_Select_Browser },
    { "Fl_Tiled_Image", lua_call1_Fl_Tiled_Image__Fl_Tiled_Image },
    { "fl_pop_matrix", lua_call1_fl_pop_matrix },
    { "fl_filename_ext", lua_call1_fl_filename_ext },
    { "Fl_Repeat_Button", lua_call1_Fl_Repeat_Button__Fl_Repeat_Button },
    { "fl_show_colormap", lua_call1_fl_show_colormap },
    { "Fl_Radio_Button", lua_call1_Fl_Radio_Button__Fl_Radio_Button },
    { "fl_mult_matrix", lua_call1_fl_mult_matrix },
    { "Fl_Window", lua_call2_Fl_Window__Fl_Window },
    { "fl_xyline", lua_call3_fl_xyline },
    { "fl_file_chooser", lua_call1_fl_file_chooser },
    { "Fl_Hor_Nice_Slider", lua_call1_Fl_Hor_Nice_Slider__Fl_Hor_Nice_Slider },
    { "Fl_Line_Dial", lua_call1_Fl_Line_Dial__Fl_Line_Dial },
    { "Fl_PNG_Image", lua_call1_Fl_PNG_Image__Fl_PNG_Image },
    { "Fl_Menu_Button", lua_call1_Fl_Menu_Button__Fl_Menu_Button },
    { "fl_clip_box", lua_call1_fl_clip_box },
    { "Fl_Help_View", lua_call1_Fl_Help_View__Fl_Help_View },
    { "Fl_Box", lua_call2_Fl_Box__Fl_Box },
    { "fl_define_FL_PLASTIC_UP_BOX", lua_call1_fl_define_FL_PLASTIC_UP_BOX },
    { "fl_pop_clip", lua_call1_fl_pop_clip },
    { "fl_filename_expand", lua_call2_fl_filename_expand },
    { "fl_input", lua_call1_fl_input },
    { "fl_find", lua_call1_fl_find },
    { "fl_can_do_alpha_blending", lua_call1_fl_can_do_alpha_blending },
    { "fl_define_FL_EMBOSSED_LABEL", lua_call1_fl_define_FL_EMBOSSED_LABEL },
    { "Fl_Button", lua_call1_Fl_Button__Fl_Button },
    { "fl_message", lua_call1_fl_message },
    { "fl_alert", lua_call1_fl_alert },
    { "Fl_Scroll", lua_call1_Fl_Scroll__Fl_Scroll },
    { "fl_file_chooser_ok_label", lua_call1_fl_file_chooser_ok_label },
    { "fl_line", lua_call2_fl_line },
    { "fl_scale", lua_call2_fl_scale },
    { "fl_begin_points", lua_call1_fl_begin_points },
    { "fl_curve", lua_call1_fl_curve },
    { "fl_arc", lua_call2_fl_arc },
    { "fl_end_loop", lua_call1_fl_end_loop },
    { "fl_lighter", lua_call1_fl_lighter },
    { "fl_inactive", lua_call1_fl_inactive },
    { "fl_gap", lua_call1_fl_gap },
    { "fl_end_complex_polygon", lua_call1_fl_end_complex_polygon },
    { "fl_transformed_vertex", lua_call1_fl_transformed_vertex },
    { "fl_latin1_to_local", lua_call1_fl_latin1_to_local },
    { "fl_frame2", lua_call1_fl_frame2 },
    { "fl_draw_image", lua_call2_fl_draw_image },
    { "fl_rectf", lua_call3_fl_rectf },
    { "Fl_Hor_Fill_Slider", lua_call1_Fl_Hor_Fill_Slider__Fl_Hor_Fill_Slider },
    { "fl_color_average", lua_call1_fl_color_average },
    { "fl_shortcut_label", lua_call1_fl_shortcut_label },
    { "fl_overlay_clear", lua_call1_fl_overlay_clear },
    { "fl_cursor", lua_call1_fl_cursor },
    { "fl_xid", lua_call1_fl_xid },
    { "fl_define_FL_GTK_UP_BOX", lua_call1_fl_define_FL_GTK_UP_BOX },
    { "fl_choice", lua_call1_fl_choice },
    { "fl_descent", lua_call1_fl_descent },
    { "fl_size", lua_call1_fl_size },
    { "fl_yxline", lua_call3_fl_yxline },
    { "fl_height", lua_call2_fl_height },
    { "fl_rect", lua_call2_fl_rect },
    { "fl_filename_isdir", lua_call1_fl_filename_isdir },
    { "fl_transform_y", lua_call1_fl_transform_y },
    { "fl_pie", lua_call1_fl_pie },
    { "fl_color_chooser", lua_call2_fl_color_chooser },
    { "fl_define_FL_OVAL_BOX", lua_call1_fl_define_FL_OVAL_BOX },
    { "fl_measure", lua_call1_fl_measure },
    { "fl_begin_line", lua_call1_fl_begin_line },
    { "fl_overlay_rect", lua_call1_fl_overlay_rect },
    { "fl_end_polygon", lua_call1_fl_end_polygon },
    { "fl_color_cube", lua_call1_fl_color_cube },
    { "Fl_Simple_Counter", lua_call1_Fl_Simple_Counter__Fl_Simple_Counter },
    { "fl_push_clip", lua_call1_fl_push_clip },
    { "fl_filename_absolute", lua_call2_fl_filename_absolute },
    { "fl_darker", lua_call1_fl_darker },
    { "fl_vertex", lua_call1_fl_vertex },
    { "fl_local_to_latin1", lua_call1_fl_local_to_latin1 },
    { "fl_password", lua_call1_fl_password },
    { "fl_width", lua_call3_fl_width },
    { "Fl_Value_Slider", lua_call1_Fl_Value_Slider__Fl_Value_Slider },
    { "fl_contrast", lua_call1_fl_contrast },
    { "fl_begin_complex_polygon", lua_call1_fl_begin_complex_polygon },
    { "fl_dir_chooser", lua_call1_fl_dir_chooser },
    { "fl_gray_ramp", lua_call1_fl_gray_ramp },
    { "fl_box", lua_call1_fl_box },
    { "Fl_Nice_Slider", lua_call1_Fl_Nice_Slider__Fl_Nice_Slider },
    { "fl_local_to_mac_roman", lua_call1_fl_local_to_mac_roman },
    { "Fl_Radio_Round_Button", lua_call1_Fl_Radio_Round_Button__Fl_Radio_Round_Button },
    { "fl_rotate", lua_call1_fl_rotate },
    { "Fl_Input", lua_call1_Fl_Input__Fl_Input },
    { "Fl_murgaLuaTimer", lua_call1_Fl_murgaLuaTimer__Fl_murgaLuaTimer },
    { "fl_define_FL_ROUND_UP_BOX", lua_call1_fl_define_FL_ROUND_UP_BOX },
    { "Fl_JPEG_Image", lua_call1_Fl_JPEG_Image__Fl_JPEG_Image },
    { "Fl_Light_Button", lua_call1_Fl_Light_Button__Fl_Light_Button },
    { "Fl_Fill_Slider", lua_call1_Fl_Fill_Slider__Fl_Fill_Slider },
    { "fl_define_FL_ROUNDED_BOX", lua_call1_fl_define_FL_ROUNDED_BOX },
    { "Fl_Positioner", lua_call1_Fl_Positioner__Fl_Positioner },
    { "Fl_Hor_Slider", lua_call1_Fl_Hor_Slider__Fl_Hor_Slider },
    { "Fl_PNM_Image", lua_call1_Fl_PNM_Image__Fl_PNM_Image },
    { "Fl_Multiline_Input", lua_call1_Fl_Multiline_Input__Fl_Multiline_Input },
    { "Fl_File_Browser", lua_call1_Fl_File_Browser__Fl_File_Browser },
    { "Fl_Float_Input", lua_call1_Fl_Float_Input__Fl_Float_Input },
    { "fl_beep", lua_call1_fl_beep },
    { "Fl_Menu_Window", lua_call2_Fl_Menu_Window__Fl_Menu_Window },
    { "Fl_Image", lua_call1_Fl_Image__Fl_Image },
    { "Fl_XPM_Image", lua_call1_Fl_XPM_Image__Fl_XPM_Image },
    { "Fl_Roller", lua_call1_Fl_Roller__Fl_Roller },
    { "Fl_Counter", lua_call1_Fl_Counter__Fl_Counter },
    { "Fl_Text_Buffer", lua_call1_Fl_Text_Buffer__Fl_Text_Buffer },
    { "Fl_Pixmap", lua_call1_Fl_Pixmap__Fl_Pixmap },
    { "fl_draw", lua_call3_fl_draw },
    { "Fl_File_Icon", lua_call1_Fl_File_Icon__Fl_File_Icon },
    { "Fl_Tile", lua_call1_Fl_Tile__Fl_Tile },
    { "Fl_Browser", lua_call1_Fl_Browser__Fl_Browser },
    { "Fl_File_Input", lua_call1_Fl_File_Input__Fl_File_Input },
    { "Fl_Int_Input", lua_call1_Fl_Int_Input__Fl_Int_Input },
    { "Fl_Bitmap", lua_call2_Fl_Bitmap__Fl_Bitmap },
    { "fl_polygon", lua_call2_fl_polygon },
    { "Fl_Check_Button", lua_call1_Fl_Check_Button__Fl_Check_Button },
    { "Fl_Help_Dialog", lua_call1_Fl_Help_Dialog__Fl_Help_Dialog },
    { "Fl_Toggle_Button", lua_call1_Fl_Toggle_Button__Fl_Toggle_Button },
    { "fl_frame", lua_call2_fl_frame },
    { "Fl_Return_Button", lua_call1_Fl_Return_Button__Fl_Return_Button },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { 0 };
  
  lua_fltk_init_type(__S__, 1, "fltk", &type__main_namespace, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for struct Fl_Help_Block */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Help_Block", lua_new_Fl_Help_Block },
    { "delete", lua_delete_Fl_Help_Block },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Help_Block", &type__Fl_Help_Block, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Text_Buffer */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "text", lua_call2_Fl_Text_Buffer__text },
    { "null_substitution_character", lua_call1_Fl_Text_Buffer__null_substitution_character },
    { "highlight_rectangular", lua_call1_Fl_Text_Buffer__highlight_rectangular },
    { "remove", lua_call1_Fl_Text_Buffer__remove },
    { "remove_rectangular", lua_call1_Fl_Text_Buffer__remove_rectangular },
    { "replace_rectangular", lua_call1_Fl_Text_Buffer__replace_rectangular },
    { "word_start", lua_call1_Fl_Text_Buffer__word_start },
    { "highlight_selection", lua_call1_Fl_Text_Buffer__highlight_selection },
    { "skip_lines", lua_call1_Fl_Text_Buffer__skip_lines },
    { "expand_character", lua_call2_Fl_Text_Buffer__expand_character },
    { "line_start", lua_call1_Fl_Text_Buffer__line_start },
    { "canUndo", lua_call1_Fl_Text_Buffer__canUndo },
    { "select", lua_call1_Fl_Text_Buffer__select },
    { "call_predelete_callbacks", lua_call1_Fl_Text_Buffer__call_predelete_callbacks },
    { "replace_selection", lua_call1_Fl_Text_Buffer__replace_selection },
    { "appendfile", lua_call1_Fl_Text_Buffer__appendfile },
    { "word_end", lua_call1_Fl_Text_Buffer__word_end },
    { "remove_secondary_selection", lua_call1_Fl_Text_Buffer__remove_secondary_selection },
    { "replace_secondary_selection", lua_call1_Fl_Text_Buffer__replace_secondary_selection },
    { "insertfile", lua_call1_Fl_Text_Buffer__insertfile },
    { "copy", lua_call1_Fl_Text_Buffer__copy },
    { "savefile", lua_call1_Fl_Text_Buffer__savefile },
    { "secondary_selected", lua_call1_Fl_Text_Buffer__secondary_selected },
    { "substitute_null_characters", lua_call1_Fl_Text_Buffer__substitute_null_characters },
    { "clear_rectangular", lua_call1_Fl_Text_Buffer__clear_rectangular },
    { "undo", lua_call1_Fl_Text_Buffer__undo },
    { "highlight", lua_call2_Fl_Text_Buffer__highlight },
    { "text_range", lua_call1_Fl_Text_Buffer__text_range },
    { "loadfile", lua_call1_Fl_Text_Buffer__loadfile },
    { "primary_selection", lua_call1_Fl_Text_Buffer__primary_selection },
    { "secondary_select", lua_call1_Fl_Text_Buffer__secondary_select },
    { "call_modify_callbacks", lua_call1_Fl_Text_Buffer__call_modify_callbacks },
    { "unselect", lua_call1_Fl_Text_Buffer__unselect },
    { "secondary_select_rectangular", lua_call1_Fl_Text_Buffer__secondary_select_rectangular },
    { "outputfile", lua_call1_Fl_Text_Buffer__outputfile },
    { "secondary_selection", lua_call1_Fl_Text_Buffer__secondary_selection },
    { "selected", lua_call1_Fl_Text_Buffer__selected },
    { "line_text", lua_call1_Fl_Text_Buffer__line_text },
    { "line_end", lua_call1_Fl_Text_Buffer__line_end },
    { "count_lines", lua_call1_Fl_Text_Buffer__count_lines },
    { "character_width", lua_call1_Fl_Text_Buffer__character_width },
    { "Fl_Text_Buffer", lua_call1_Fl_Text_Buffer__Fl_Text_Buffer },
    { "unhighlight", lua_call1_Fl_Text_Buffer__unhighlight },
    { "selection_text", lua_call1_Fl_Text_Buffer__selection_text },
    { "length", lua_call1_Fl_Text_Buffer__length },
    { "text_in_rectangle", lua_call1_Fl_Text_Buffer__text_in_rectangle },
    { "tab_distance", lua_call2_Fl_Text_Buffer__tab_distance },
    { "select_rectangular", lua_call1_Fl_Text_Buffer__select_rectangular },
    { "rewind_lines", lua_call1_Fl_Text_Buffer__rewind_lines },
    { "skip_displayed_characters", lua_call1_Fl_Text_Buffer__skip_displayed_characters },
    { "replace", lua_call1_Fl_Text_Buffer__replace },
    { "secondary_unselect", lua_call1_Fl_Text_Buffer__secondary_unselect },
    { "count_displayed_characters", lua_call1_Fl_Text_Buffer__count_displayed_characters },
    { "highlight_text", lua_call1_Fl_Text_Buffer__highlight_text },
    { "secondary_selection_text", lua_call1_Fl_Text_Buffer__secondary_selection_text },
    { "insert", lua_call1_Fl_Text_Buffer__insert },
    { "append", lua_call1_Fl_Text_Buffer__append },
    { "remove_selection", lua_call1_Fl_Text_Buffer__remove_selection },
    { "character", lua_call1_Fl_Text_Buffer__character },
    { "unsubstitute_null_characters", lua_call1_Fl_Text_Buffer__unsubstitute_null_characters },
    { "delete", lua_delete_Fl_Text_Buffer },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Text_Buffer", &type__Fl_Text_Buffer, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Tooltip */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "enter_", lua_call1_Fl_Tooltip__enter_ },
    { "font", lua_call2_Fl_Tooltip__font },
    { "hoverdelay", lua_call2_Fl_Tooltip__hoverdelay },
    { "enabled", lua_call1_Fl_Tooltip__enabled },
    { "enter_area", lua_call1_Fl_Tooltip__enter_area },
    { "disable", lua_call1_Fl_Tooltip__disable },
    { "size", lua_call2_Fl_Tooltip__size },
    { "delay", lua_call2_Fl_Tooltip__delay },
    { "exit_", lua_call1_Fl_Tooltip__exit_ },
    { "enable", lua_call1_Fl_Tooltip__enable },
    { "textcolor", lua_call2_Fl_Tooltip__textcolor },
    { "current", lua_call2_Fl_Tooltip__current },
    { "color", lua_call2_Fl_Tooltip__color },
    { "Fl_Tooltip", lua_new_Fl_Tooltip },
    { "delete", lua_delete_Fl_Tooltip },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Tooltip", &type__Fl_Tooltip, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Text_Selection */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "includes", lua_call1_Fl_Text_Selection__includes },
    { "set", lua_call1_Fl_Text_Selection__set },
    { "set_rectangular", lua_call1_Fl_Text_Selection__set_rectangular },
    { "update", lua_call1_Fl_Text_Selection__update },
    { "end", lua_call1_Fl_Text_Selection__end },
    { "Fl_Text_Buffer", lua_call1_Fl_Text_Buffer__Fl_Text_Buffer },
    { "rect_end", lua_call1_Fl_Text_Selection__rect_end },
    { "rectangular", lua_call1_Fl_Text_Selection__rectangular },
    { "selected", lua_call2_Fl_Text_Selection__selected },
    { "rect_start", lua_call1_Fl_Text_Selection__rect_start },
    { "start", lua_call1_Fl_Text_Selection__start },
    { "Fl_Text_Selection", lua_new_Fl_Text_Selection },
    { "delete", lua_delete_Fl_Text_Selection },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Text_Selection", &type__Fl_Text_Selection, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for struct Fl_Text_Editor__Key_Binding */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Key_Binding", lua_new_Fl_Text_Editor__Key_Binding },
    { "delete", lua_delete_Fl_Text_Editor__Key_Binding },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Text_Editor__Key_Binding", &type__Fl_Text_Editor__Key_Binding, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for struct Fl_Multi_Label */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "label", lua_call2_Fl_Multi_Label__label },
    { "Fl_Multi_Label", lua_new_Fl_Multi_Label },
    { "delete", lua_delete_Fl_Multi_Label },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Multi_Label", &type__Fl_Multi_Label, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for struct Fl_Help_Target */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Help_Target", lua_new_Fl_Help_Target },
    { "delete", lua_delete_Fl_Help_Target },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Help_Target", &type__Fl_Help_Target, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for struct Fl_Help_Link */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Help_Link", lua_new_Fl_Help_Link },
    { "delete", lua_delete_Fl_Help_Link },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Help_Link", &type__Fl_Help_Link, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Box */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "handle", lua_call1_Fl_Box__handle },
    { "Fl_Box", lua_call2_Fl_Box__Fl_Box },
    { "delete", lua_delete_Fl_Box },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Widget__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Box", &type__Fl_Box, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Shared_Image */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "name", lua_call1_Fl_Shared_Image__name },
    { "uncache", lua_call1_Fl_Shared_Image__uncache },
    { "find", lua_call1_Fl_Shared_Image__find },
    { "color_average", lua_call1_Fl_Shared_Image__color_average },
    { "desaturate", lua_call1_Fl_Shared_Image__desaturate },
    { "reload", lua_call1_Fl_Shared_Image__reload },
    { "release", lua_call1_Fl_Shared_Image__release },
    { "num_images", lua_call1_Fl_Shared_Image__num_images },
    { "copy", lua_call2_Fl_Shared_Image__copy },
    { "refcount", lua_call1_Fl_Shared_Image__refcount },
    { "draw", lua_call2_Fl_Shared_Image__draw },
    { "get", lua_call1_Fl_Shared_Image__get },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Image__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Shared_Image", &type__Fl_Shared_Image, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Progress */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Progress", lua_call1_Fl_Progress__Fl_Progress },
    { "minimum", lua_call2_Fl_Progress__minimum },
    { "maximum", lua_call2_Fl_Progress__maximum },
    { "value", lua_call2_Fl_Progress__value },
    { "delete", lua_delete_Fl_Progress },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Widget__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Progress", &type__Fl_Progress, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Group */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "remove", lua_call2_Fl_Group__remove },
    { "begin", lua_call1_Fl_Group__begin },
    { "end", lua_call1_Fl_Group__end },
    { "add_resizable", lua_call1_Fl_Group__add_resizable },
    { "insert", lua_call2_Fl_Group__insert },
    { "children", lua_call1_Fl_Group__children },
    { "focus", lua_call1_Fl_Group__focus },
    { "resizable", lua_call3_Fl_Group__resizable },
    { "handle", lua_call1_Fl_Group__handle },
    { "add", lua_call2_Fl_Group__add },
    { "forms_end", lua_call1_Fl_Group__forms_end },
    { "Fl_Group", lua_call1_Fl_Group__Fl_Group },
    { "resize", lua_call1_Fl_Group__resize },
    { "find", lua_call2_Fl_Group__find },
    { "child", lua_call1_Fl_Group__child },
    { "current", lua_call2_Fl_Group__current },
    { "init_sizes", lua_call1_Fl_Group__init_sizes },
    { "clear", lua_call1_Fl_Group__clear },
    { "delete", lua_delete_Fl_Group },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Widget__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Group", &type__Fl_Group, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Timer */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "direction", lua_call2_Fl_Timer__direction },
    { "Fl_Timer", lua_call1_Fl_Timer__Fl_Timer },
    { "suspended", lua_call2_Fl_Timer__suspended },
    { "handle", lua_call1_Fl_Timer__handle },
    { "value", lua_call2_Fl_Timer__value },
    { "delete", lua_delete_Fl_Timer },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Widget__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Timer", &type__Fl_Timer, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Chart */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "textsize", lua_call2_Fl_Chart__textsize },
    { "textfont", lua_call2_Fl_Chart__textfont },
    { "bounds", lua_call1_Fl_Chart__bounds },
    { "Fl_Chart", lua_call1_Fl_Chart__Fl_Chart },
    { "maxsize", lua_call2_Fl_Chart__maxsize },
    { "replace", lua_call1_Fl_Chart__replace },
    { "size", lua_call2_Fl_Chart__size },
    { "add", lua_call1_Fl_Chart__add },
    { "insert", lua_call1_Fl_Chart__insert },
    { "clear", lua_call1_Fl_Chart__clear },
    { "textcolor", lua_call2_Fl_Chart__textcolor },
    { "autosize", lua_call2_Fl_Chart__autosize },
    { "delete", lua_delete_Fl_Chart },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Widget__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Chart", &type__Fl_Chart, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_murgaLuaTimer */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "doWait", lua_call1_Fl_murgaLuaTimer__doWait },
    { "Fl_murgaLuaTimer", lua_call1_Fl_murgaLuaTimer__Fl_murgaLuaTimer },
    { "draw", lua_call1_Fl_murgaLuaTimer__draw },
    { "isActive", lua_call1_Fl_murgaLuaTimer__isActive },
    { "delete", lua_delete_Fl_murgaLuaTimer },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Widget__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_murgaLuaTimer", &type__Fl_murgaLuaTimer, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Menu_ */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "mvalue", lua_call1_Fl_Menu___mvalue },
    { "clear", lua_call1_Fl_Menu___clear },
    { "copy", lua_call1_Fl_Menu___copy },
    { "add_overriden", lua_call1_Fl_Menu___add },
    { "add_overriden", lua_call1_Fl_Menu___add },
    { "textfont", lua_call2_Fl_Menu___textfont },
    { "down_color", lua_call2_Fl_Menu___down_color },
    { "textcolor", lua_call2_Fl_Menu___textcolor },
    { "value", lua_call3_Fl_Menu___value },
    { "item_pathname", lua_call1_Fl_Menu___item_pathname },
    { "global", lua_call1_Fl_Menu___global },
    { "test_shortcut", lua_call1_Fl_Menu___test_shortcut },
    { "textsize", lua_call2_Fl_Menu___textsize },
    { "size", lua_call2_Fl_Menu___size },
    { "mode", lua_call2_Fl_Menu___mode },
    { "menu", lua_call2_Fl_Menu___menu },
    { "find_item", lua_call1_Fl_Menu___find_item },
    { "shortcut", lua_call1_Fl_Menu___shortcut },
    { "down_box", lua_call2_Fl_Menu___down_box },
    { "picked", lua_call1_Fl_Menu___picked },
    { "remove", lua_call1_Fl_Menu___remove },
    { "text", lua_call2_Fl_Menu___text },
    { "replace", lua_call1_Fl_Menu___replace },
    { "delete", lua_delete_Fl_Menu_ },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Widget__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Menu_", &type__Fl_Menu_, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Button */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "down_box", lua_call2_Fl_Button__down_box },
    { "setonly", lua_call1_Fl_Button__setonly },
    { "Fl_Button", lua_call1_Fl_Button__Fl_Button },
    { "value", lua_call2_Fl_Button__value },
    { "clear", lua_call1_Fl_Button__clear },
    { "set", lua_call1_Fl_Button__set },
    { "handle", lua_call1_Fl_Button__handle },
    { "down_color", lua_call2_Fl_Button__down_color },
    { "shortcut", lua_call3_Fl_Button__shortcut },
    { "delete", lua_delete_Fl_Button },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Widget__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Button", &type__Fl_Button, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Valuator */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "format", lua_call1_Fl_Valuator__format },
    { "maximum", lua_call2_Fl_Valuator__maximum },
    { "bounds", lua_call1_Fl_Valuator__bounds },
    { "range", lua_call1_Fl_Valuator__range },
    { "precision", lua_call1_Fl_Valuator__precision },
    { "round", lua_call1_Fl_Valuator__round },
    { "increment", lua_call1_Fl_Valuator__increment },
    { "value", lua_call2_Fl_Valuator__value },
    { "minimum", lua_call2_Fl_Valuator__minimum },
    { "clamp", lua_call1_Fl_Valuator__clamp },
    { "step", lua_call4_Fl_Valuator__step },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Widget__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Valuator", &type__Fl_Valuator, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Positioner */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "xvalue", lua_call2_Fl_Positioner__xvalue },
    { "xbounds", lua_call1_Fl_Positioner__xbounds },
    { "xminimum", lua_call2_Fl_Positioner__xminimum },
    { "ystep", lua_call1_Fl_Positioner__ystep },
    { "ymaximum", lua_call2_Fl_Positioner__ymaximum },
    { "yvalue", lua_call2_Fl_Positioner__yvalue },
    { "xmaximum", lua_call2_Fl_Positioner__xmaximum },
    { "value", lua_call1_Fl_Positioner__value },
    { "yminimum", lua_call2_Fl_Positioner__yminimum },
    { "ybounds", lua_call1_Fl_Positioner__ybounds },
    { "Fl_Positioner", lua_call1_Fl_Positioner__Fl_Positioner },
    { "xstep", lua_call1_Fl_Positioner__xstep },
    { "handle", lua_call1_Fl_Positioner__handle },
    { "delete", lua_delete_Fl_Positioner },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Widget__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Positioner", &type__Fl_Positioner, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Input_ */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "textfont", lua_call2_Fl_Input___textfont },
    { "wrap", lua_call2_Fl_Input___wrap },
    { "resize", lua_call1_Fl_Input___resize },
    { "index", lua_call1_Fl_Input___index },
    { "value", lua_call3_Fl_Input___value },
    { "input_type", lua_call2_Fl_Input___input_type },
    { "readonly", lua_call2_Fl_Input___readonly },
    { "static_value", lua_call2_Fl_Input___static_value },
    { "cut", lua_call3_Fl_Input___cut },
    { "replace", lua_call1_Fl_Input___replace },
    { "textsize", lua_call2_Fl_Input___textsize },
    { "insert", lua_call1_Fl_Input___insert },
    { "mark", lua_call2_Fl_Input___mark },
    { "position", lua_call3_Fl_Input___position },
    { "maximum_size", lua_call2_Fl_Input___maximum_size },
    { "undo", lua_call1_Fl_Input___undo },
    { "cursor_color", lua_call2_Fl_Input___cursor_color },
    { "copy", lua_call1_Fl_Input___copy },
    { "copy_cuts", lua_call1_Fl_Input___copy_cuts },
    { "textcolor", lua_call2_Fl_Input___textcolor },
    { "size", lua_call2_Fl_Input___size },
    { "delete", lua_delete_Fl_Input_ },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Widget__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Input_", &type__Fl_Input_, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_FormsBitmap */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "set", lua_call1_Fl_FormsBitmap__set },
    { "Fl_FormsBitmap", lua_call1_Fl_FormsBitmap__Fl_FormsBitmap },
    { "bitmap", lua_call2_Fl_FormsBitmap__bitmap },
    { "delete", lua_delete_Fl_FormsBitmap },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Widget__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_FormsBitmap", &type__Fl_FormsBitmap, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Clock_Output */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Clock_Output", lua_call1_Fl_Clock_Output__Fl_Clock_Output },
    { "value", lua_call3_Fl_Clock_Output__value },
    { "second", lua_call1_Fl_Clock_Output__second },
    { "hour", lua_call1_Fl_Clock_Output__hour },
    { "minute", lua_call1_Fl_Clock_Output__minute },
    { "delete", lua_delete_Fl_Clock_Output },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Widget__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Clock_Output", &type__Fl_Clock_Output, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_FormsPixmap */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Pixmap", lua_call2_Fl_FormsPixmap__Pixmap },
    { "Fl_FormsPixmap", lua_call1_Fl_FormsPixmap__Fl_FormsPixmap },
    { "delete", lua_delete_Fl_FormsPixmap },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Widget__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_FormsPixmap", &type__Fl_FormsPixmap, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Tiled_Image */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "copy", lua_call2_Fl_Tiled_Image__copy },
    { "draw", lua_call2_Fl_Tiled_Image__draw },
    { "desaturate", lua_call1_Fl_Tiled_Image__desaturate },
    { "Fl_Tiled_Image", lua_call1_Fl_Tiled_Image__Fl_Tiled_Image },
    { "image", lua_call1_Fl_Tiled_Image__image },
    { "color_average", lua_call1_Fl_Tiled_Image__color_average },
    { "delete", lua_delete_Fl_Tiled_Image },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Image__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Tiled_Image", &type__Fl_Tiled_Image, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_RGB_Image */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_RGB_Image", lua_call1_Fl_RGB_Image__Fl_RGB_Image },
    { "saveAsPng", lua_call1_Fl_RGB_Image__saveAsPng },
    { "draw", lua_call2_Fl_RGB_Image__draw },
    { "color_average", lua_call1_Fl_RGB_Image__color_average },
    { "uncache", lua_call1_Fl_RGB_Image__uncache },
    { "copy", lua_call2_Fl_RGB_Image__copy },
    { "label", lua_call2_Fl_RGB_Image__label },
    { "desaturate", lua_call1_Fl_RGB_Image__desaturate },
    { "delete", lua_delete_Fl_RGB_Image },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Image__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_RGB_Image", &type__Fl_RGB_Image, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Pixmap */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "draw", lua_call2_Fl_Pixmap__draw },
    { "label", lua_call2_Fl_Pixmap__label },
    { "desaturate", lua_call1_Fl_Pixmap__desaturate },
    { "copy", lua_call2_Fl_Pixmap__copy },
    { "color_average", lua_call1_Fl_Pixmap__color_average },
    { "uncache", lua_call1_Fl_Pixmap__uncache },
    { "delete", lua_delete_Fl_Pixmap },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Image__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Pixmap", &type__Fl_Pixmap, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Bitmap */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "uncache", lua_call1_Fl_Bitmap__uncache },
    { "draw", lua_call2_Fl_Bitmap__draw },
    { "copy", lua_call2_Fl_Bitmap__copy },
    { "label", lua_call2_Fl_Bitmap__label },
    { "Fl_Bitmap", lua_call2_Fl_Bitmap__Fl_Bitmap },
    { "delete", lua_delete_Fl_Bitmap },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Image__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Bitmap", &type__Fl_Bitmap, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Toggle_Button */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Toggle_Button", lua_call1_Fl_Toggle_Button__Fl_Toggle_Button },
    { "delete", lua_delete_Fl_Toggle_Button },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Button__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Toggle_Button", &type__Fl_Toggle_Button, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Value_Output */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Value_Output", lua_call1_Fl_Value_Output__Fl_Value_Output },
    { "handle", lua_call1_Fl_Value_Output__handle },
    { "draw", lua_call1_Fl_Value_Output__draw },
    { "textcolor", lua_call2_Fl_Value_Output__textcolor },
    { "textfont", lua_call2_Fl_Value_Output__textfont },
    { "soft", lua_call2_Fl_Value_Output__soft },
    { "textsize", lua_call2_Fl_Value_Output__textsize },
    { "delete", lua_delete_Fl_Value_Output },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Valuator__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Value_Output", &type__Fl_Value_Output, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Return_Button */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "handle", lua_call1_Fl_Return_Button__handle },
    { "Fl_Return_Button", lua_call1_Fl_Return_Button__Fl_Return_Button },
    { "delete", lua_delete_Fl_Return_Button },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Button__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Return_Button", &type__Fl_Return_Button, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Counter */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "textsize", lua_call2_Fl_Counter__textsize },
    { "handle", lua_call1_Fl_Counter__handle },
    { "lstep", lua_call1_Fl_Counter__lstep },
    { "textcolor", lua_call2_Fl_Counter__textcolor },
    { "textfont", lua_call2_Fl_Counter__textfont },
    { "Fl_Counter", lua_call1_Fl_Counter__Fl_Counter },
    { "step", lua_call2_Fl_Counter__step },
    { "delete", lua_delete_Fl_Counter },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Valuator__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Counter", &type__Fl_Counter, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_PNG_Image */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_PNG_Image", lua_call1_Fl_PNG_Image__Fl_PNG_Image },
    { "delete", lua_delete_Fl_PNG_Image },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_RGB_Image__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_PNG_Image", &type__Fl_PNG_Image, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Radio_Button */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Radio_Button", lua_call1_Fl_Radio_Button__Fl_Radio_Button },
    { "delete", lua_delete_Fl_Radio_Button },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Button__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Radio_Button", &type__Fl_Radio_Button, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Scroll */
  {
  static enumdecl_t enums[] = {
    { "BOTH", Fl_Scroll::BOTH },
    { "VERTICAL_ALWAYS", Fl_Scroll::VERTICAL_ALWAYS },
    { "BOTH_ALWAYS", Fl_Scroll::BOTH_ALWAYS },
    { "HORIZONTAL_ALWAYS", Fl_Scroll::HORIZONTAL_ALWAYS },
    { "ALWAYS_ON", Fl_Scroll::ALWAYS_ON },
    { "VERTICAL", Fl_Scroll::VERTICAL },
    { "HORIZONTAL", Fl_Scroll::HORIZONTAL },
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "xposition", lua_call1_Fl_Scroll__xposition },
    { "yposition", lua_call1_Fl_Scroll__yposition },
    { "position", lua_call1_Fl_Scroll__position },
    { "resize", lua_call1_Fl_Scroll__resize },
    { "clear", lua_call1_Fl_Scroll__clear },
    { "Fl_Scroll", lua_call1_Fl_Scroll__Fl_Scroll },
    { "handle", lua_call1_Fl_Scroll__handle },
    { "delete", lua_delete_Fl_Scroll },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Group__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Scroll", &type__Fl_Scroll, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Window */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "size_range", lua_call1_Fl_Window__size_range },
    { "show", lua_call1_Fl_Window__show },
    { "border", lua_call2_Fl_Window__border },
    { "fullscreen", lua_call1_Fl_Window__fullscreen },
    { "handle", lua_call1_Fl_Window__handle },
    { "set_modal", lua_call1_Fl_Window__set_modal },
    { "non_modal", lua_call1_Fl_Window__non_modal },
    { "cursor", lua_call1_Fl_Window__cursor },
    { "y_root", lua_call1_Fl_Window__y_root },
    { "clear_border", lua_call1_Fl_Window__clear_border },
    { "icon", lua_call2_Fl_Window__icon },
    { "label", lua_call3_Fl_Window__label },
    { "free_position", lua_call1_Fl_Window__free_position },
    { "iconlabel", lua_call2_Fl_Window__iconlabel },
    { "override", lua_call1_Fl_Window__override },
    { "current", lua_call1_Fl_Window__current },
    { "hide", lua_call1_Fl_Window__hide },
    { "set_non_modal", lua_call1_Fl_Window__set_non_modal },
    { "Fl_Window", lua_call2_Fl_Window__Fl_Window },
    { "modal", lua_call1_Fl_Window__modal },
    { "make_current", lua_call1_Fl_Window__make_current },
    { "default_cursor", lua_call1_Fl_Window__default_cursor },
    { "x_root", lua_call1_Fl_Window__x_root },
    { "shown", lua_call1_Fl_Window__shown },
    { "set_override", lua_call1_Fl_Window__set_override },
    { "fullscreen_off", lua_call1_Fl_Window__fullscreen_off },
    { "copy_label", lua_call1_Fl_Window__copy_label },
    { "resize", lua_call1_Fl_Window__resize },
    { "iconize", lua_call1_Fl_Window__iconize },
    { "xclass", lua_call2_Fl_Window__xclass },
    { "hotspot", lua_call3_Fl_Window__hotspot },
    { "delete", lua_delete_Fl_Window },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Group__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Window", &type__Fl_Window, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Color_Chooser */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "rgb2hsv", lua_call1_Fl_Color_Chooser__rgb2hsv },
    { "hsv2rgb", lua_call1_Fl_Color_Chooser__hsv2rgb },
    { "Fl_Color_Chooser", lua_call1_Fl_Color_Chooser__Fl_Color_Chooser },
    { "g", lua_call1_Fl_Color_Chooser__g },
    { "b", lua_call1_Fl_Color_Chooser__b },
    { "hue", lua_call1_Fl_Color_Chooser__hue },
    { "hsv", lua_call1_Fl_Color_Chooser__hsv },
    { "r", lua_call1_Fl_Color_Chooser__r },
    { "mode", lua_call1_Fl_Color_Chooser__mode },
    { "value", lua_call1_Fl_Color_Chooser__value },
    { "rgb", lua_call1_Fl_Color_Chooser__rgb },
    { "saturation", lua_call1_Fl_Color_Chooser__saturation },
    { "delete", lua_delete_Fl_Color_Chooser },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Group__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Color_Chooser", &type__Fl_Color_Chooser, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Input */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "draw", lua_call1_Fl_Input__draw },
    { "Fl_Input", lua_call1_Fl_Input__Fl_Input },
    { "handle", lua_call1_Fl_Input__handle },
    { "delete", lua_delete_Fl_Input },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Input___typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Input", &type__Fl_Input, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Menu_Bar */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Menu_Bar", lua_call1_Fl_Menu_Bar__Fl_Menu_Bar },
    { "handle", lua_call1_Fl_Menu_Bar__handle },
    { "delete", lua_delete_Fl_Menu_Bar },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Menu___typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Menu_Bar", &type__Fl_Menu_Bar, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_PNM_Image */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_PNM_Image", lua_call1_Fl_PNM_Image__Fl_PNM_Image },
    { "delete", lua_delete_Fl_PNM_Image },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_RGB_Image__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_PNM_Image", &type__Fl_PNM_Image, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Adjuster */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "soft", lua_call2_Fl_Adjuster__soft },
    { "Fl_Adjuster", lua_call1_Fl_Adjuster__Fl_Adjuster },
    { "delete", lua_delete_Fl_Adjuster },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Valuator__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Adjuster", &type__Fl_Adjuster, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Dial */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Dial", lua_call1_Fl_Dial__Fl_Dial },
    { "handle", lua_call1_Fl_Dial__handle },
    { "angle2", lua_call2_Fl_Dial__angle2 },
    { "angles", lua_call1_Fl_Dial__angles },
    { "angle1", lua_call2_Fl_Dial__angle1 },
    { "delete", lua_delete_Fl_Dial },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Valuator__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Dial", &type__Fl_Dial, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_BMP_Image */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_BMP_Image", lua_call1_Fl_BMP_Image__Fl_BMP_Image },
    { "delete", lua_delete_Fl_BMP_Image },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_RGB_Image__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_BMP_Image", &type__Fl_BMP_Image, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Menu_Button */
  {
  static enumdecl_t enums[] = {
    { "POPUP23", Fl_Menu_Button::POPUP23 },
    { "POPUP12", Fl_Menu_Button::POPUP12 },
    { "POPUP2", Fl_Menu_Button::POPUP2 },
    { "POPUP3", Fl_Menu_Button::POPUP3 },
    { "POPUP123", Fl_Menu_Button::POPUP123 },
    { "POPUP1", Fl_Menu_Button::POPUP1 },
    { "POPUP13", Fl_Menu_Button::POPUP13 },
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "popup", lua_call1_Fl_Menu_Button__popup },
    { "Fl_Menu_Button", lua_call1_Fl_Menu_Button__Fl_Menu_Button },
    { "handle", lua_call1_Fl_Menu_Button__handle },
    { "delete", lua_delete_Fl_Menu_Button },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Menu___typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Menu_Button", &type__Fl_Menu_Button, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_GIF_Image */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_GIF_Image", lua_call1_Fl_GIF_Image__Fl_GIF_Image },
    { "delete", lua_delete_Fl_GIF_Image },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Pixmap__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_GIF_Image", &type__Fl_GIF_Image, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_XPM_Image */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_XPM_Image", lua_call1_Fl_XPM_Image__Fl_XPM_Image },
    { "delete", lua_delete_Fl_XPM_Image },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Pixmap__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_XPM_Image", &type__Fl_XPM_Image, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Input_Choice */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "textfont", lua_call2_Fl_Input_Choice__textfont },
    { "resize", lua_call1_Fl_Input_Choice__resize },
    { "textcolor", lua_call2_Fl_Input_Choice__textcolor },
    { "Fl_Input_Choice", lua_call1_Fl_Input_Choice__Fl_Input_Choice },
    { "down_box", lua_call2_Fl_Input_Choice__down_box },
    { "changed", lua_call1_Fl_Input_Choice__changed },
    { "textsize", lua_call2_Fl_Input_Choice__textsize },
    { "value", lua_call3_Fl_Input_Choice__value },
    { "menu", lua_call2_Fl_Input_Choice__menu },
    { "add", lua_call1_Fl_Input_Choice__add },
    { "clear", lua_call1_Fl_Input_Choice__clear },
    { "input", lua_call1_Fl_Input_Choice__input },
    { "clear_changed", lua_call1_Fl_Input_Choice__clear_changed },
    { "set_changed", lua_call1_Fl_Input_Choice__set_changed },
    { "menubutton", lua_call1_Fl_Input_Choice__menubutton },
    { "delete", lua_delete_Fl_Input_Choice },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Group__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Input_Choice", &type__Fl_Input_Choice, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Help_View */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "size", lua_call2_Fl_Help_View__size },
    { "title", lua_call1_Fl_Help_View__title },
    { "select_all", lua_call1_Fl_Help_View__select_all },
    { "find", lua_call1_Fl_Help_View__find },
    { "clear_selection", lua_call1_Fl_Help_View__clear_selection },
    { "textfont", lua_call2_Fl_Help_View__textfont },
    { "resize", lua_call1_Fl_Help_View__resize },
    { "leftline", lua_call2_Fl_Help_View__leftline },
    { "value", lua_call2_Fl_Help_View__value },
    { "topline", lua_call3_Fl_Help_View__topline },
    { "load", lua_call1_Fl_Help_View__load },
    { "textcolor", lua_call2_Fl_Help_View__textcolor },
    { "textsize", lua_call2_Fl_Help_View__textsize },
    { "Fl_Help_View", lua_call1_Fl_Help_View__Fl_Help_View },
    { "directory", lua_call1_Fl_Help_View__directory },
    { "filename", lua_call1_Fl_Help_View__filename },
    { "delete", lua_delete_Fl_Help_View },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Group__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Help_View", &type__Fl_Help_View, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Wizard */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "prev", lua_call1_Fl_Wizard__prev },
    { "Fl_Wizard", lua_call1_Fl_Wizard__Fl_Wizard },
    { "next", lua_call1_Fl_Wizard__next },
    { "value", lua_call2_Fl_Wizard__value },
    { "delete", lua_delete_Fl_Wizard },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Group__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Wizard", &type__Fl_Wizard, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Slider */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "slider", lua_call2_Fl_Slider__slider },
    { "Fl_Slider", lua_call2_Fl_Slider__Fl_Slider },
    { "scrollvalue", lua_call1_Fl_Slider__scrollvalue },
    { "draw", lua_call1_Fl_Slider__draw },
    { "handle", lua_call1_Fl_Slider__handle },
    { "bounds", lua_call1_Fl_Slider__bounds },
    { "slider_size", lua_call2_Fl_Slider__slider_size },
    { "delete", lua_delete_Fl_Slider },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Valuator__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Slider", &type__Fl_Slider, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Choice */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Choice", lua_call1_Fl_Choice__Fl_Choice },
    { "value", lua_call3_Fl_Choice__value },
    { "handle", lua_call1_Fl_Choice__handle },
    { "delete", lua_delete_Fl_Choice },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Menu___typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Choice", &type__Fl_Choice, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_XBM_Image */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_XBM_Image", lua_call1_Fl_XBM_Image__Fl_XBM_Image },
    { "delete", lua_delete_Fl_XBM_Image },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Bitmap__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_XBM_Image", &type__Fl_XBM_Image, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Clock */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Clock", lua_call2_Fl_Clock__Fl_Clock },
    { "handle", lua_call1_Fl_Clock__handle },
    { "delete", lua_delete_Fl_Clock },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Clock_Output__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Clock", &type__Fl_Clock, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Spinner */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "step", lua_call2_Fl_Spinner__step },
    { "Fl_Spinner", lua_call1_Fl_Spinner__Fl_Spinner },
    { "minimum", lua_call2_Fl_Spinner__minimum },
    { "handle", lua_call1_Fl_Spinner__handle },
    { "resize", lua_call1_Fl_Spinner__resize },
    { "textfont", lua_call2_Fl_Spinner__textfont },
    { "mininum", lua_call1_Fl_Spinner__mininum },
    { "type", lua_call2_Fl_Spinner__type },
    { "range", lua_call1_Fl_Spinner__range },
    { "format", lua_call2_Fl_Spinner__format },
    { "value", lua_call2_Fl_Spinner__value },
    { "textcolor", lua_call2_Fl_Spinner__textcolor },
    { "maxinum", lua_call1_Fl_Spinner__maxinum },
    { "maximum", lua_call2_Fl_Spinner__maximum },
    { "textsize", lua_call2_Fl_Spinner__textsize },
    { "delete", lua_delete_Fl_Spinner },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Group__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Spinner", &type__Fl_Spinner, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_JPEG_Image */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_JPEG_Image", lua_call1_Fl_JPEG_Image__Fl_JPEG_Image },
    { "delete", lua_delete_Fl_JPEG_Image },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_RGB_Image__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_JPEG_Image", &type__Fl_JPEG_Image, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Browser_ */
  {
  static enumdecl_t enums[] = {
    { "VERTICAL_ALWAYS", Fl_Browser_::VERTICAL_ALWAYS },
    { "ALWAYS_ON", Fl_Browser_::ALWAYS_ON },
    { "HORIZONTAL_ALWAYS", Fl_Browser_::HORIZONTAL_ALWAYS },
    { "HORIZONTAL", Fl_Browser_::HORIZONTAL },
    { "BOTH", Fl_Browser_::BOTH },
    { "BOTH_ALWAYS", Fl_Browser_::BOTH_ALWAYS },
    { "VERTICAL", Fl_Browser_::VERTICAL },
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "scrollbar_width", lua_call2_Fl_Browser___scrollbar_width },
    { "scrollbar_right", lua_call1_Fl_Browser___scrollbar_right },
    { "textsize", lua_call2_Fl_Browser___textsize },
    { "deselect", lua_call1_Fl_Browser___deselect },
    { "position", lua_call2_Fl_Browser___position },
    { "has_scrollbar", lua_call2_Fl_Browser___has_scrollbar },
    { "textcolor", lua_call2_Fl_Browser___textcolor },
    { "hposition", lua_call2_Fl_Browser___hposition },
    { "textfont", lua_call2_Fl_Browser___textfont },
    { "resize", lua_call1_Fl_Browser___resize },
    { "handle", lua_call1_Fl_Browser___handle },
    { "scrollbar_left", lua_call1_Fl_Browser___scrollbar_left },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Group__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Browser_", &type__Fl_Browser_, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Tile */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "position", lua_call1_Fl_Tile__position },
    { "handle", lua_call1_Fl_Tile__handle },
    { "resize", lua_call1_Fl_Tile__resize },
    { "Fl_Tile", lua_call1_Fl_Tile__Fl_Tile },
    { "delete", lua_delete_Fl_Tile },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Group__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Tile", &type__Fl_Tile, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Text_Display */
  {
  static enumdecl_t enums[] = {
    { "NORMAL_CURSOR", Fl_Text_Display::NORMAL_CURSOR },
    { "CHARACTER_POS", Fl_Text_Display::CHARACTER_POS },
    { "DRAG_LINE", Fl_Text_Display::DRAG_LINE },
    { "ATTR_NONE", Fl_Text_Display::ATTR_NONE },
    { "CURSOR_POS", Fl_Text_Display::CURSOR_POS },
    { "DIM_CURSOR", Fl_Text_Display::DIM_CURSOR },
    { "BLOCK_CURSOR", Fl_Text_Display::BLOCK_CURSOR },
    { "DRAG_CHAR", Fl_Text_Display::DRAG_CHAR },
    { "HEAVY_CURSOR", Fl_Text_Display::HEAVY_CURSOR },
    { "ATTR_UNDERLINE", Fl_Text_Display::ATTR_UNDERLINE },
    { "DRAG_WORD", Fl_Text_Display::DRAG_WORD },
    { "ATTR_HIDDEN", Fl_Text_Display::ATTR_HIDDEN },
    { "CARET_CURSOR", Fl_Text_Display::CARET_CURSOR },
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "line_end", lua_call1_Fl_Text_Display__line_end },
    { "resize", lua_call1_Fl_Text_Display__resize },
    { "insert_position", lua_call2_Fl_Text_Display__insert_position },
    { "insert", lua_call1_Fl_Text_Display__insert },
    { "textcolor", lua_call2_Fl_Text_Display__textcolor },
    { "overstrike", lua_call1_Fl_Text_Display__overstrike },
    { "show_insert_position", lua_call1_Fl_Text_Display__show_insert_position },
    { "textsize", lua_call2_Fl_Text_Display__textsize },
    { "textfont", lua_call2_Fl_Text_Display__textfont },
    { "wrap_mode", lua_call1_Fl_Text_Display__wrap_mode },
    { "move_up", lua_call1_Fl_Text_Display__move_up },
    { "buffer", lua_call3_Fl_Text_Display__buffer },
    { "rewind_lines", lua_call1_Fl_Text_Display__rewind_lines },
    { "cursor_style", lua_call1_Fl_Text_Display__cursor_style },
    { "wrapped_column", lua_call1_Fl_Text_Display__wrapped_column },
    { "scrollbar_align", lua_call2_Fl_Text_Display__scrollbar_align },
    { "line_start", lua_call1_Fl_Text_Display__line_start },
    { "Fl_Text_Display", lua_call1_Fl_Text_Display__Fl_Text_Display },
    { "redisplay_range", lua_call1_Fl_Text_Display__redisplay_range },
    { "count_lines", lua_call1_Fl_Text_Display__count_lines },
    { "handle", lua_call1_Fl_Text_Display__handle },
    { "move_down", lua_call1_Fl_Text_Display__move_down },
    { "wrapped_row", lua_call1_Fl_Text_Display__wrapped_row },
    { "scroll", lua_call1_Fl_Text_Display__scroll },
    { "scrollbar_width", lua_call2_Fl_Text_Display__scrollbar_width },
    { "in_selection", lua_call1_Fl_Text_Display__in_selection },
    { "word_start", lua_call1_Fl_Text_Display__word_start },
    { "previous_word", lua_call1_Fl_Text_Display__previous_word },
    { "hide_cursor", lua_call1_Fl_Text_Display__hide_cursor },
    { "show_cursor", lua_call1_Fl_Text_Display__show_cursor },
    { "cursor_color", lua_call2_Fl_Text_Display__cursor_color },
    { "move_left", lua_call1_Fl_Text_Display__move_left },
    { "skip_lines", lua_call1_Fl_Text_Display__skip_lines },
    { "next_word", lua_call1_Fl_Text_Display__next_word },
    { "word_end", lua_call1_Fl_Text_Display__word_end },
    { "move_right", lua_call1_Fl_Text_Display__move_right },
    { "position_style", lua_call1_Fl_Text_Display__position_style },
    { "delete", lua_delete_Fl_Text_Display },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Group__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Text_Display", &type__Fl_Text_Display, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Pack */
  {
  static enumdecl_t enums[] = {
    { "VERTICAL", Fl_Pack::VERTICAL },
    { "HORIZONTAL", Fl_Pack::HORIZONTAL },
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Pack", lua_call1_Fl_Pack__Fl_Pack },
    { "draw", lua_call1_Fl_Pack__draw },
    { "spacing", lua_call2_Fl_Pack__spacing },
    { "horizontal", lua_call1_Fl_Pack__horizontal },
    { "delete", lua_delete_Fl_Pack },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Group__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Pack", &type__Fl_Pack, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Repeat_Button */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "handle", lua_call1_Fl_Repeat_Button__handle },
    { "Fl_Repeat_Button", lua_call1_Fl_Repeat_Button__Fl_Repeat_Button },
    { "deactivate", lua_call1_Fl_Repeat_Button__deactivate },
    { "delete", lua_delete_Fl_Repeat_Button },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Button__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Repeat_Button", &type__Fl_Repeat_Button, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Light_Button */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "handle", lua_call1_Fl_Light_Button__handle },
    { "Fl_Light_Button", lua_call1_Fl_Light_Button__Fl_Light_Button },
    { "delete", lua_delete_Fl_Light_Button },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Button__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Light_Button", &type__Fl_Light_Button, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Roller */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "handle", lua_call1_Fl_Roller__handle },
    { "Fl_Roller", lua_call1_Fl_Roller__Fl_Roller },
    { "delete", lua_delete_Fl_Roller },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Valuator__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Roller", &type__Fl_Roller, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Tabs */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Tabs", lua_call1_Fl_Tabs__Fl_Tabs },
    { "push", lua_call2_Fl_Tabs__push },
    { "handle", lua_call1_Fl_Tabs__handle },
    { "value", lua_call2_Fl_Tabs__value },
    { "which", lua_call1_Fl_Tabs__which },
    { "delete", lua_delete_Fl_Tabs },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Group__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Tabs", &type__Fl_Tabs, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Value_Input */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "draw", lua_call1_Fl_Value_Input__draw },
    { "resize", lua_call1_Fl_Value_Input__resize },
    { "textsize", lua_call2_Fl_Value_Input__textsize },
    { "soft", lua_call2_Fl_Value_Input__soft },
    { "cursor_color", lua_call2_Fl_Value_Input__cursor_color },
    { "Fl_Value_Input", lua_call1_Fl_Value_Input__Fl_Value_Input },
    { "textfont", lua_call2_Fl_Value_Input__textfont },
    { "textcolor", lua_call2_Fl_Value_Input__textcolor },
    { "handle", lua_call1_Fl_Value_Input__handle },
    { "delete", lua_delete_Fl_Value_Input },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Valuator__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Value_Input", &type__Fl_Value_Input, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Nice_Slider */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Nice_Slider", lua_call1_Fl_Nice_Slider__Fl_Nice_Slider },
    { "delete", lua_delete_Fl_Nice_Slider },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Slider__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Nice_Slider", &type__Fl_Nice_Slider, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Fill_Dial */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Fill_Dial", lua_call1_Fl_Fill_Dial__Fl_Fill_Dial },
    { "delete", lua_delete_Fl_Fill_Dial },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Dial__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Fill_Dial", &type__Fl_Fill_Dial, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Browser */
  {
  static enumdecl_t enums[] = {
    { "MIDDLE", Fl_Browser::MIDDLE },
    { "TOP", Fl_Browser::TOP },
    { "BOTTOM", Fl_Browser::BOTTOM },
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "format_char", lua_call2_Fl_Browser__format_char },
    { "lineposition", lua_call1_Fl_Browser__lineposition },
    { "display", lua_call1_Fl_Browser__display },
    { "clear", lua_call1_Fl_Browser__clear },
    { "add", lua_call1_Fl_Browser__add },
    { "show", lua_call2_Fl_Browser__show },
    { "data", lua_call2_Fl_Browser__data },
    { "value", lua_call2_Fl_Browser__value },
    { "insert", lua_call1_Fl_Browser__insert },
    { "make_visible", lua_call1_Fl_Browser__make_visible },
    { "swap", lua_call1_Fl_Browser__swap },
    { "replace", lua_call1_Fl_Browser__replace },
    { "move", lua_call1_Fl_Browser__move },
    { "column_widths", lua_call1_Fl_Browser__column_widths },
    { "column_char", lua_call2_Fl_Browser__column_char },
    { "size", lua_call2_Fl_Browser__size },
    { "visible", lua_call1_Fl_Browser__visible },
    { "select", lua_call1_Fl_Browser__select },
    { "bottomline", lua_call1_Fl_Browser__bottomline },
    { "remove", lua_call1_Fl_Browser__remove },
    { "text", lua_call2_Fl_Browser__text },
    { "load", lua_call1_Fl_Browser__load },
    { "topline", lua_call2_Fl_Browser__topline },
    { "hide", lua_call2_Fl_Browser__hide },
    { "Fl_Browser", lua_call1_Fl_Browser__Fl_Browser },
    { "selected", lua_call1_Fl_Browser__selected },
    { "middleline", lua_call1_Fl_Browser__middleline },
    { "displayed", lua_call1_Fl_Browser__displayed },
    { "delete", lua_delete_Fl_Browser },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Browser___typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Browser", &type__Fl_Browser, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Radio_Light_Button */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Radio_Light_Button", lua_call1_Fl_Radio_Light_Button__Fl_Radio_Light_Button },
    { "delete", lua_delete_Fl_Radio_Light_Button },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Light_Button__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Radio_Light_Button", &type__Fl_Radio_Light_Button, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Single_Window */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "flush", lua_call1_Fl_Single_Window__flush },
    { "Fl_Single_Window", lua_call2_Fl_Single_Window__Fl_Single_Window },
    { "show", lua_call1_Fl_Single_Window__show },
    { "delete", lua_delete_Fl_Single_Window },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Window__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Single_Window", &type__Fl_Single_Window, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Multiline_Input */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Multiline_Input", lua_call1_Fl_Multiline_Input__Fl_Multiline_Input },
    { "delete", lua_delete_Fl_Multiline_Input },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Input__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Multiline_Input", &type__Fl_Multiline_Input, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Output */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Output", lua_call1_Fl_Output__Fl_Output },
    { "delete", lua_delete_Fl_Output },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Input__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Output", &type__Fl_Output, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Round_Button */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Round_Button", lua_call1_Fl_Round_Button__Fl_Round_Button },
    { "delete", lua_delete_Fl_Round_Button },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Light_Button__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Round_Button", &type__Fl_Round_Button, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Scrollbar */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "handle", lua_call1_Fl_Scrollbar__handle },
    { "Fl_Scrollbar", lua_call1_Fl_Scrollbar__Fl_Scrollbar },
    { "linesize", lua_call2_Fl_Scrollbar__linesize },
    { "value", lua_call2_Fl_Scrollbar__value },
    { "delete", lua_delete_Fl_Scrollbar },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Slider__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Scrollbar", &type__Fl_Scrollbar, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Secret_Input */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Secret_Input", lua_call1_Fl_Secret_Input__Fl_Secret_Input },
    { "delete", lua_delete_Fl_Secret_Input },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Input__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Secret_Input", &type__Fl_Secret_Input, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Value_Slider */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "textsize", lua_call2_Fl_Value_Slider__textsize },
    { "draw", lua_call1_Fl_Value_Slider__draw },
    { "textfont", lua_call2_Fl_Value_Slider__textfont },
    { "handle", lua_call1_Fl_Value_Slider__handle },
    { "Fl_Value_Slider", lua_call1_Fl_Value_Slider__Fl_Value_Slider },
    { "textcolor", lua_call2_Fl_Value_Slider__textcolor },
    { "delete", lua_delete_Fl_Value_Slider },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Slider__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Value_Slider", &type__Fl_Value_Slider, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Hor_Slider */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Hor_Slider", lua_call1_Fl_Hor_Slider__Fl_Hor_Slider },
    { "delete", lua_delete_Fl_Hor_Slider },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Slider__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Hor_Slider", &type__Fl_Hor_Slider, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Check_Button */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Check_Button", lua_call1_Fl_Check_Button__Fl_Check_Button },
    { "delete", lua_delete_Fl_Check_Button },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Light_Button__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Check_Button", &type__Fl_Check_Button, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Fill_Slider */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Fill_Slider", lua_call1_Fl_Fill_Slider__Fl_Fill_Slider },
    { "delete", lua_delete_Fl_Fill_Slider },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Slider__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Fill_Slider", &type__Fl_Fill_Slider, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Int_Input */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Int_Input", lua_call1_Fl_Int_Input__Fl_Int_Input },
    { "delete", lua_delete_Fl_Int_Input },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Input__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Int_Input", &type__Fl_Int_Input, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_File_Input */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "value", lua_call3_Fl_File_Input__value },
    { "down_box", lua_call2_Fl_File_Input__down_box },
    { "errorcolor", lua_call2_Fl_File_Input__errorcolor },
    { "draw", lua_call1_Fl_File_Input__draw },
    { "handle", lua_call1_Fl_File_Input__handle },
    { "Fl_File_Input", lua_call1_Fl_File_Input__Fl_File_Input },
    { "delete", lua_delete_Fl_File_Input },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Input__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_File_Input", &type__Fl_File_Input, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Check_Browser */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Check_Browser", lua_call1_Fl_Check_Browser__Fl_Check_Browser },
    { "check_all", lua_call1_Fl_Check_Browser__check_all },
    { "text", lua_call1_Fl_Check_Browser__text },
    { "set_checked", lua_call1_Fl_Check_Browser__set_checked },
    { "add", lua_call4_Fl_Check_Browser__add },
    { "nchecked", lua_call1_Fl_Check_Browser__nchecked },
    { "nitems", lua_call1_Fl_Check_Browser__nitems },
    { "check_none", lua_call1_Fl_Check_Browser__check_none },
    { "value", lua_call1_Fl_Check_Browser__value },
    { "checked", lua_call2_Fl_Check_Browser__checked },
    { "clear", lua_call1_Fl_Check_Browser__clear },
    { "remove", lua_call1_Fl_Check_Browser__remove },
    { "delete", lua_delete_Fl_Check_Browser },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Browser___typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Check_Browser", &type__Fl_Check_Browser, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Simple_Counter */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Simple_Counter", lua_call1_Fl_Simple_Counter__Fl_Simple_Counter },
    { "delete", lua_delete_Fl_Simple_Counter },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Counter__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Simple_Counter", &type__Fl_Simple_Counter, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Line_Dial */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Line_Dial", lua_call1_Fl_Line_Dial__Fl_Line_Dial },
    { "delete", lua_delete_Fl_Line_Dial },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Dial__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Line_Dial", &type__Fl_Line_Dial, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Double_Window */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Double_Window", lua_call2_Fl_Double_Window__Fl_Double_Window },
    { "hide", lua_call1_Fl_Double_Window__hide },
    { "flush", lua_call1_Fl_Double_Window__flush },
    { "show", lua_call1_Fl_Double_Window__show },
    { "resize", lua_call1_Fl_Double_Window__resize },
    { "delete", lua_delete_Fl_Double_Window },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Window__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Double_Window", &type__Fl_Double_Window, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Round_Clock */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Round_Clock", lua_call1_Fl_Round_Clock__Fl_Round_Clock },
    { "delete", lua_delete_Fl_Round_Clock },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Clock__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Round_Clock", &type__Fl_Round_Clock, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Float_Input */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Float_Input", lua_call1_Fl_Float_Input__Fl_Float_Input },
    { "delete", lua_delete_Fl_Float_Input },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Input__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Float_Input", &type__Fl_Float_Input, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Text_Editor */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "kf_page_down", lua_call1_Fl_Text_Editor__kf_page_down },
    { "kf_home", lua_call1_Fl_Text_Editor__kf_home },
    { "kf_delete", lua_call1_Fl_Text_Editor__kf_delete },
    { "handle", lua_call1_Fl_Text_Editor__handle },
    { "kf_undo", lua_call1_Fl_Text_Editor__kf_undo },
    { "kf_left", lua_call1_Fl_Text_Editor__kf_left },
    { "kf_copy", lua_call1_Fl_Text_Editor__kf_copy },
    { "kf_up", lua_call1_Fl_Text_Editor__kf_up },
    { "kf_right", lua_call1_Fl_Text_Editor__kf_right },
    { "kf_enter", lua_call1_Fl_Text_Editor__kf_enter },
    { "kf_page_up", lua_call1_Fl_Text_Editor__kf_page_up },
    { "kf_ignore", lua_call1_Fl_Text_Editor__kf_ignore },
    { "insert_mode", lua_call2_Fl_Text_Editor__insert_mode },
    { "kf_move", lua_call1_Fl_Text_Editor__kf_move },
    { "Fl_Text_Editor", lua_call1_Fl_Text_Editor__Fl_Text_Editor },
    { "kf_backspace", lua_call1_Fl_Text_Editor__kf_backspace },
    { "kf_down", lua_call1_Fl_Text_Editor__kf_down },
    { "remove_all_key_bindings", lua_call1_Fl_Text_Editor__remove_all_key_bindings },
    { "kf_ctrl_move", lua_call1_Fl_Text_Editor__kf_ctrl_move },
    { "kf_paste", lua_call1_Fl_Text_Editor__kf_paste },
    { "kf_c_s_move", lua_call1_Fl_Text_Editor__kf_c_s_move },
    { "remove_key_binding", lua_call1_Fl_Text_Editor__remove_key_binding },
    { "kf_end", lua_call1_Fl_Text_Editor__kf_end },
    { "kf_cut", lua_call1_Fl_Text_Editor__kf_cut },
    { "kf_select_all", lua_call1_Fl_Text_Editor__kf_select_all },
    { "kf_shift_move", lua_call1_Fl_Text_Editor__kf_shift_move },
    { "kf_default", lua_call1_Fl_Text_Editor__kf_default },
    { "kf_insert", lua_call1_Fl_Text_Editor__kf_insert },
    { "delete", lua_delete_Fl_Text_Editor },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Text_Display__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Text_Editor", &type__Fl_Text_Editor, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Hor_Fill_Slider */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Hor_Fill_Slider", lua_call1_Fl_Hor_Fill_Slider__Fl_Hor_Fill_Slider },
    { "delete", lua_delete_Fl_Hor_Fill_Slider },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Slider__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Hor_Fill_Slider", &type__Fl_Hor_Fill_Slider, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Hor_Nice_Slider */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Hor_Nice_Slider", lua_call1_Fl_Hor_Nice_Slider__Fl_Hor_Nice_Slider },
    { "delete", lua_delete_Fl_Hor_Nice_Slider },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Slider__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Hor_Nice_Slider", &type__Fl_Hor_Nice_Slider, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Multi_Browser */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Multi_Browser", lua_call1_Fl_Multi_Browser__Fl_Multi_Browser },
    { "delete", lua_delete_Fl_Multi_Browser },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Browser__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Multi_Browser", &type__Fl_Multi_Browser, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_File_Browser */
  {
  static enumdecl_t enums[] = {
    { "FILES", Fl_File_Browser::FILES },
    { "DIRECTORIES", Fl_File_Browser::DIRECTORIES },
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "load", lua_call1_Fl_File_Browser__load },
    { "filetype", lua_call2_Fl_File_Browser__filetype },
    { "textsize", lua_call2_Fl_File_Browser__textsize },
    { "iconsize", lua_call2_Fl_File_Browser__iconsize },
    { "filter", lua_call2_Fl_File_Browser__filter },
    { "Fl_File_Browser", lua_call1_Fl_File_Browser__Fl_File_Browser },
    { "delete", lua_delete_Fl_File_Browser },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Browser__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_File_Browser", &type__Fl_File_Browser, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Overlay_Window */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "flush", lua_call1_Fl_Overlay_Window__flush },
    { "redraw_overlay", lua_call1_Fl_Overlay_Window__redraw_overlay },
    { "can_do_overlay", lua_call1_Fl_Overlay_Window__can_do_overlay },
    { "show", lua_call1_Fl_Overlay_Window__show },
    { "hide", lua_call1_Fl_Overlay_Window__hide },
    { "resize", lua_call1_Fl_Overlay_Window__resize },
    { "delete", lua_delete_Fl_Overlay_Window },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Double_Window__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Overlay_Window", &type__Fl_Overlay_Window, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Radio_Round_Button */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Radio_Round_Button", lua_call1_Fl_Radio_Round_Button__Fl_Radio_Round_Button },
    { "delete", lua_delete_Fl_Radio_Round_Button },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Round_Button__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Radio_Round_Button", &type__Fl_Radio_Round_Button, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Menu_Window */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "clear_overlay", lua_call1_Fl_Menu_Window__clear_overlay },
    { "flush", lua_call1_Fl_Menu_Window__flush },
    { "hide", lua_call1_Fl_Menu_Window__hide },
    { "overlay", lua_call1_Fl_Menu_Window__overlay },
    { "show", lua_call1_Fl_Menu_Window__show },
    { "set_overlay", lua_call1_Fl_Menu_Window__set_overlay },
    { "erase", lua_call1_Fl_Menu_Window__erase },
    { "Fl_Menu_Window", lua_call2_Fl_Menu_Window__Fl_Menu_Window },
    { "delete", lua_delete_Fl_Menu_Window },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Single_Window__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Menu_Window", &type__Fl_Menu_Window, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Select_Browser */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Select_Browser", lua_call1_Fl_Select_Browser__Fl_Select_Browser },
    { "delete", lua_delete_Fl_Select_Browser },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Browser__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Select_Browser", &type__Fl_Select_Browser, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Hold_Browser */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Hold_Browser", lua_call1_Fl_Hold_Browser__Fl_Hold_Browser },
    { "delete", lua_delete_Fl_Hold_Browser },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Browser__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Hold_Browser", &type__Fl_Hold_Browser, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Multiline_Output */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Multiline_Output", lua_call1_Fl_Multiline_Output__Fl_Multiline_Output },
    { "delete", lua_delete_Fl_Multiline_Output },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Output__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Multiline_Output", &type__Fl_Multiline_Output, parents, funcs, gets, sets, enums);
  }
  
  /* Binding for class Fl_Hor_Value_Slider */
  {
  static enumdecl_t enums[] = {
    { 0 }
  };
  static funcdecl_t funcs[] = {
    { "Fl_Hor_Value_Slider", lua_call1_Fl_Hor_Value_Slider__Fl_Hor_Value_Slider },
    { "delete", lua_delete_Fl_Hor_Value_Slider },
    { 0 }
  };
  static funcdecl_t gets[] = {
    { 0 }
  };
  static funcdecl_t sets[] = {
    { 0 }
  };
  const char * parents[] = { "Fl_Value_Slider__typeinfo", 0 };
  
  lua_fltk_init_type(__S__, 0, "Fl_Hor_Value_Slider", &type__Fl_Hor_Value_Slider, parents, funcs, gets, sets, enums);
  }
  
  
  static numberdef_t numberdef[] = {
    { "FL_CTRL", FL_CTRL },
    { "FL_F_Last", FL_F_Last },
    { "FL_Print", FL_Print },
    { "FL_LINE_DIAL", FL_LINE_DIAL },
    { "FL_MULTILINE_OUTPUT", FL_MULTILINE_OUTPUT },
    { "FL_LINE_CHART", FL_LINE_CHART },
    { "FL_HIDDEN_INPUT", FL_HIDDEN_INPUT },
    { "FL_Caps_Lock", FL_Caps_Lock },
    { "FL_CHART_LABEL_MAX", FL_CHART_LABEL_MAX },
    { "FL_PATCH_VERSION", FL_PATCH_VERSION },
    { "FL_CHART_MAX", FL_CHART_MAX },
    { "FL_NUM_RED", FL_NUM_RED },
    { "FL_NORMAL_COUNTER", FL_NORMAL_COUNTER },
    { "FL_HORIZONTAL", FL_HORIZONTAL },
    { "FL_FILLED_CHART", FL_FILLED_CHART },
    { "FL_KP", FL_KP },
    { "FL_HIDDEN_BUTTON", FL_HIDDEN_BUTTON },
    { "FL_ROUND_CLOCK", FL_ROUND_CLOCK },
    { "FL_Delete", FL_Delete },
    { "FL_TOGGLE_BUTTON", FL_TOGGLE_BUTTON },
    { "FL_NUM_LOCK", FL_NUM_LOCK },
    { "FL_Down", FL_Down },
    { "FL_NORMAL_BROWSER", FL_NORMAL_BROWSER },
    { "FL_MINOR_VERSION", FL_MINOR_VERSION },
    { "FL_Meta_L", FL_Meta_L },
    { "FL_BAR_CHART", FL_BAR_CHART },
    { "FL_MULTI_BROWSER", FL_MULTI_BROWSER },
    { "FL_Home", FL_Home },
    { "FL_Button", FL_Button },
    { "FL_HOR_FILL_SLIDER", FL_HOR_FILL_SLIDER },
    { "FL_CAPS_LOCK", FL_CAPS_LOCK },
    { "FL_F", FL_F },
    { "FL_HOR_SLIDER", FL_HOR_SLIDER },
    { "FL_KP_Last", FL_KP_Last },
    { "FL_SIMPLE_COUNTER", FL_SIMPLE_COUNTER },
    { "FL_BUTTON2", FL_BUTTON2 },
    { "FL_FILL_DIAL", FL_FILL_DIAL },
    { "FL_NUM_FREE_COLOR", FL_NUM_FREE_COLOR },
    { "FL_MAJOR_VERSION", FL_MAJOR_VERSION },
    { "FL_SQUARE_CLOCK", FL_SQUARE_CLOCK },
    { "FL_Right", FL_Right },
    { "FL_Alt_R", FL_Alt_R },
    { "FL_NORMAL_OUTPUT", FL_NORMAL_OUTPUT },
    { "FL_Meta_R", FL_Meta_R },
    { "FL_PIE_CHART", FL_PIE_CHART },
    { "FL_VERT_FILL_SLIDER", FL_VERT_FILL_SLIDER },
    { "FL_Help", FL_Help },
    { "FL_ALT", FL_ALT },
    { "FL_HORBAR_CHART", FL_HORBAR_CHART },
    { "FL_VERTICAL", FL_VERTICAL },
    { "FL_HIDDEN_TIMER", FL_HIDDEN_TIMER },
    { "FL_VALUE_TIMER", FL_VALUE_TIMER },
    { "FL_TEXT_MAX_EXP_CHAR_LEN", FL_TEXT_MAX_EXP_CHAR_LEN },
    { "FL_Escape", FL_Escape },
    { "FL_NORMAL_BUTTON", FL_NORMAL_BUTTON },
    { "FL_NORMAL_INPUT", FL_NORMAL_INPUT },
    { "FL_NORMAL_TIMER", FL_NORMAL_TIMER },
    { "FL_Pause", FL_Pause },
    { "FL_META", FL_META },
    { "FL_SECRET_INPUT", FL_SECRET_INPUT },
    { "FL_SCROLL_LOCK", FL_SCROLL_LOCK },
    { "FL_Left", FL_Left },
    { "FL_HOLD_BROWSER", FL_HOLD_BROWSER },
    { "FL_BUTTON3", FL_BUTTON3 },
    { "FL_INT_INPUT", FL_INT_INPUT },
    { "FL_MULTILINE_INPUT_WRAP", FL_MULTILINE_INPUT_WRAP },
    { "FL_Alt_L", FL_Alt_L },
    { "FL_Tab", FL_Tab },
    { "FL_FILL_CHART", FL_FILL_CHART },
    { "FL_IMAGE_WITH_ALPHA", FL_IMAGE_WITH_ALPHA },
    { "FL_BUTTONS", FL_BUTTONS },
    { "FL_Control_L", FL_Control_L },
    { "FL_DOUBLE_WINDOW", FL_DOUBLE_WINDOW },
    { "FL_NUM_GREEN", FL_NUM_GREEN },
    { "FL_VERT_SLIDER", FL_VERT_SLIDER },
    { "FL_Control_R", FL_Control_R },
    { "FL_Enter", FL_Enter },
    { "FL_Scroll_Lock", FL_Scroll_Lock },
    { "FL_Shift_R", FL_Shift_R },
    { "FL_BackSpace", FL_BackSpace },
    { "FL_MULTILINE_OUTPUT_WRAP", FL_MULTILINE_OUTPUT_WRAP },
    { "FL_End", FL_End },
    { "FL_COMMAND", FL_COMMAND },
    { "FL_WINDOW", FL_WINDOW },
    { "FL_SPIKE_CHART", FL_SPIKE_CHART },
    { "FL_Insert", FL_Insert },
    { "FL_Page_Down", FL_Page_Down },
    { "FL_Shift_L", FL_Shift_L },
    { "FL_NUM_GRAY", FL_NUM_GRAY },
    { "FL_ANALOG_CLOCK", FL_ANALOG_CLOCK },
    { "FL_INPUT_READONLY", FL_INPUT_READONLY },
    { "FL_MIDDLE_MOUSE", FL_MIDDLE_MOUSE },
    { "FL_VERT_NICE_SLIDER", FL_VERT_NICE_SLIDER },
    { "FL_INPUT_WRAP", FL_INPUT_WRAP },
    { "FL_DIGITAL_CLOCK", FL_DIGITAL_CLOCK },
    { "FL_NORMAL_DIAL", FL_NORMAL_DIAL },
    { "FL_Up", FL_Up },
    { "FL_KP_Enter", FL_KP_Enter },
    { "FL_SELECT_BROWSER", FL_SELECT_BROWSER },
    { "FL_SHIFT", FL_SHIFT },
    { "FL_MULTILINE_INPUT", FL_MULTILINE_INPUT },
    { "FL_INPUT_TYPE", FL_INPUT_TYPE },
    { "FL_FLOAT_INPUT", FL_FLOAT_INPUT },
    { "FL_Num_Lock", FL_Num_Lock },
    { "FL_Page_Up", FL_Page_Up },
    { "FL_LEFT_MOUSE", FL_LEFT_MOUSE },
    { "FL_PATH_MAX", FL_PATH_MAX },
    { "FL_NUM_BLUE", FL_NUM_BLUE },
    { "FL_RESERVED_TYPE", FL_RESERVED_TYPE },
    { "FL_SPECIALPIE_CHART", FL_SPECIALPIE_CHART },
    { "FL_HOR_NICE_SLIDER", FL_HOR_NICE_SLIDER },
    { "FL_RIGHT_MOUSE", FL_RIGHT_MOUSE },
    { "FL_BUTTON1", FL_BUTTON1 },
    { "FL_Menu", FL_Menu },
    { "FL_RADIO_BUTTON", FL_RADIO_BUTTON },
    { 0 }
  };
  static stringdef_t stringdef[] = {
    { 0 }
  };
/* End of init lua state (template 4) */


  {
    int i;

    lua_settop(__S__, 0);

    lua_getglobal(__S__, "fltk");

    for (i=0; numberdef[i].name; i++) {
      lua_pushstring(__S__, numberdef[i].name);
      lua_pushnumber(__S__, numberdef[i].value);
      lua_settable(__S__, 1);
    }

    for (i=0; stringdef[i].name; i++) {
      lua_pushstring(__S__, stringdef[i].name);
      lua_pushstring(__S__, stringdef[i].value);
      lua_settable(__S__, 1);
    }

    lua_settop(__S__, 0);
  }

 
  luaL_dostring(__S__, 
	       "bind_lua_buildcompattag=nil bind_lua_buildparents=nil");

  return 0;
}
	
/* End of template 4
 */