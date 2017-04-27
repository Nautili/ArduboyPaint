#ifndef CURSOR_H
#define CURSOR_H

/*
 * Contains position and width for the cursor.
 * Note: This is separate from the Brush class which only
 *       describes how a brush will paint.
 */

class Cursor {
  public:
    unsigned char x;
    unsigned char y;
    unsigned char width;

    Cursor(unsigned char width);
    void paint();
    void increaseWidth();
    void decreaseWidth();
    
  private:
    unsigned char maxWidth;
};

#endif
