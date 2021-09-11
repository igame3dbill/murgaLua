#include <FL/Fl.H>
#include <FL/fl_message.H>
#include <FL/fl_draw.H>
#include <FL/x.H>
#include <FL/Fl_RGB_Image.H>

#include "Fl_murgaLuaOffScreen.h"

Fl_RGB_Image *Fl_murgaLuaOffScreen::getOffScreenImage()
{
  return new Fl_RGB_Image(fl_read_image(0, 0, 0, width, height), width, height);
}

void Fl_murgaLuaOffScreen::endOffScreenDrawing()
{
	fl_end_offscreen();
}

void Fl_murgaLuaOffScreen::startOffScreenDrawing()
{
	#  ifdef WIN32
	_sgc=fl_gc;
	_sw=fl_window;
	fl_gc=fl_makeDC(screenBuffer);
	_savedc = SaveDC(fl_gc);
	fl_window=(HWND)screenBuffer;
	fl_push_no_clip();
	#  elif defined(__APPLE__)
	fl_begin_offscreen(screenBuffer);
	#  else
	_sw=fl_window; fl_window=screenBuffer; fl_push_no_clip();
	#  endif
}

Fl_murgaLuaOffScreen::~Fl_murgaLuaOffScreen()
{
	fl_delete_offscreen(screenBuffer);
}

Fl_murgaLuaOffScreen::Fl_murgaLuaOffScreen(int x, int y)
{
	screenBuffer = fl_create_offscreen(x,y);
	width = x;
	height = y;
}
