#ifndef PAINT_CURSOR_H
#define PAINT_CURSOR_H

class PaintCursor {
  public:
    unsigned char x;
    unsigned char y;
    unsigned char width;

    PaintCursor(unsigned char width);
    void paint();
    void increaseWidth();
    void decreaseWidth();
    
  private:
    unsigned char maxWidth;
};

#endif
