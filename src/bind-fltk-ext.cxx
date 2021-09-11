#include "fltk.cxx"

#define init_lua_fltk_State _init_lua_fltk_State
#include "bind-fltk.cxx"
#undef init_lua_fltk_State



static lua_State * S;

void lua_fltk_widget_callback(Fl_Widget * w, void * udata)
{
  lua_settop(S, 0);
  lua_getref(S, (int) udata);
  lua_pushnumber(S, 2);
  lua_gettable(S, 1);
  lua_pushnumber(S, 1);
  lua_gettable(S, 1);
  lua_call(S, 1, 0);
}

int lua_fltk__Fl_Widget__callback(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
	
  Fl_Widget * self;
  self = ( class Fl_Widget * )lua_to_Fl_Widget(__S__, 1, &__ERROR__);
  
  if (__ERROR__)
    return 0;

  if (lua_isnil(__S__, 2))
    ;//self->callback(0); // ??
  else {
    lua_settop(__S__, 2);
    lua_newtable(__S__);

    lua_pushnumber(__S__, 1);
    lua_pushvalue(__S__, 1);
    lua_settable(__S__, 3);

    lua_pushnumber(__S__, 2);
    lua_pushvalue(__S__, 2);
    lua_settable(__S__, 3);

    int ref = lua_ref(__S__, 3);
    S = __S__;
    self->callback(lua_fltk_widget_callback, (void *) ref);
  }

  return 0;
}

void lua_fltk_menuitem_callback(Fl_Menu_Item * w, void * udata)
{
  lua_settop(S, 0);
  lua_getref(S, (int) udata);
  lua_pushnumber(S, 2);
  lua_gettable(S, 1);
  lua_pushnumber(S, 1);
  lua_gettable(S, 1);
  lua_call(S, 1, 0);
}

int lua_fltk__Fl_Menu_Item__callback(lua_State * __S__)
{
  int nparam = lua_gettop(__S__);
  int __ERROR__ = 0;
	
  Fl_Menu_Item * self;
  self = ( class Fl_Menu_Item * )lua_to_Fl_Menu_Item(__S__, 1, &__ERROR__);
  
  if (__ERROR__)
    return 0;

  if (lua_isnil(__S__, 2))
    ;//self->callback(0); // ??
  else {
    lua_settop(__S__, 2);
    lua_newtable(__S__);

    lua_pushnumber(__S__, 1);
    lua_pushvalue(__S__, 1);
    lua_settable(__S__, 3);

    lua_pushnumber(__S__, 2);
    lua_pushvalue(__S__, 2);
    lua_settable(__S__, 3);

    int ref = lua_ref(__S__, 3);
    S = __S__;
    self->callback((Fl_Callback *) lua_fltk_widget_callback, (void *) ref);
  }

  return 0;
}


int init_lua_fltk_State(lua_State * _S)
{
  S = _S;

  int BS = !_init_lua_fltk_State(S);

  lua_pushcclosure(S, lua_fltk__Fl_Widget__callback, 0);
  lua_setglobal(S, "fl_callback_widget");
  luaL_dostring(S, 
"bind_lua_addtovtable(Fl_Widget, 'callback', fl_callback_widget) \n"
"fl_callback_widget = nil \n");

  lua_pushcclosure(S, lua_fltk__Fl_Menu_Item__callback, 0);
  lua_setglobal(S, "fl_callback_menu");
  luaL_dostring(S, 
"bind_lua_addtovtable(Fl_Menu_Item, 'callback', fl_callback_menu) \n"
"fl_callback_menu = nil \n");

  return BS? 0 : -1;
}

