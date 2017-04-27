#ifndef CURSOR_PAINTER_H
#define CURSOR_PAINTER_H

class Arduboy;
class Cursor;
/*
 * Handles displaying the cursor
 */
class CursorPainter {
  public:
    CursorPainter(Arduboy& arduboy, Cursor& cursor);
    void set(bool isOn);
    void paint();
  private:
    Arduboy& arduboy;
    Cursor& cursor;
    bool cursorOn;
};

#endif
