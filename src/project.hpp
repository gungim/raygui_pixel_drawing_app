class Project {
  private:
    char name[128];
    char locale[256];
    char imgLocale[256];
    int width;
    int height;

  public:
    Project();
    ~Project();
    Project(int width, int height, char* name, char* imgLocale, char* locale);
    char* getName();
    void setWidth(int w);
    void setHeight(int h);
};
