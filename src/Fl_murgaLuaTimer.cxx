#include <FL/Fl.H>
#include <FL/Fl_Widget.H>

#include "Fl_murgaLuaTimer.h"

void Fl_murgaLuaTimer::stepcb(void* v)
{
    ((Fl_murgaLuaTimer*)v)->set_changed();
    ((Fl_murgaLuaTimer*)v)->do_callback();
}

void Fl_murgaLuaTimer::doWait(double d)
{
  Fl::remove_timeout(stepcb, this);
  active = d > 0.0;
  
  if (active)
    Fl::add_timeout(d, stepcb, this);
}

char Fl_murgaLuaTimer::isActive()
{
  return active;
}

void Fl_murgaLuaTimer::draw() {;}

Fl_murgaLuaTimer::~Fl_murgaLuaTimer()
{
  Fl::remove_timeout(stepcb, this);
}

Fl_murgaLuaTimer::Fl_murgaLuaTimer(int X, int Y, int W, int H, const char *l)
: Fl_Widget(X,Y,W,H,l)
{
  active=0;
}
