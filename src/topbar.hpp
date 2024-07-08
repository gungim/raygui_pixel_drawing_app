#include "context.hpp"
#include "new_win.hpp"

class TopBar {
  private:
	float width;
	float height;

    NewWin newWin;
    bool showNewWindow;

  public:
    TopBar();
    ~TopBar();
    void Draw(Context* context);
    void LoadFile();
};
