#include <FL/x.H>
#include <FL/Fl_RGB_Image.H>

class Fl_murgaLuaOffScreen
{
#  ifdef WIN32
  HDC _sgc;
  int _savedc;
#    endif
  Window _sw;
  
  int width;
  int height;
  Fl_Offscreen screenBuffer;
public:
  Fl_murgaLuaOffScreen(int, int);
  ~Fl_murgaLuaOffScreen();
  Fl_RGB_Image *getOffScreenImage();
  void endOffScreenDrawing();
  void startOffScreenDrawing();
};
