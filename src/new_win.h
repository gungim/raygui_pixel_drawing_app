class NewWin {
private:
  char name[128];
  int width;
  int height;

  bool nameEditMode;
  bool widthEditMode;
  bool heightEditMode;
  bool open;

public:
  NewWin();
  ~NewWin();
  void draw(float offsetX, float offsetY);
  void enable();
	bool isOpen();
};
