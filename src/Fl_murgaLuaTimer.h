class Fl_murgaLuaTimer : public Fl_Widget
{
  char active;
  static void stepcb(void *);
public:
  virtual void draw();
  Fl_murgaLuaTimer(int X, int Y, int W, int H, const char *l);
  ~Fl_murgaLuaTimer();
  void doWait(double);
  char isActive();
};
