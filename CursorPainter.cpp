#include "CursorPainter.h"
#include "Cursor.h"
#include "Arduboy.h"

CursorPainter::CursorPainter(Arduboy& arduboy, Cursor& cursor) : arduboy(arduboy), cursor(cursor) {
  cursorOn = false;
}

void CursorPainter::set(bool isOn) {
  if(cursorOn != isOn) {
    paint();
  }
}

void CursorPainter::paint() {
  cursorOn = !cursorOn;
  for(int col = cursor.x; col < cursor.x + cursor.width; ++col) {
    arduboy.drawPixel(col, cursor.y, 1 - arduboy.getPixel(col, cursor.y));
    if(cursor.width > 1) {
      arduboy.drawPixel(col, cursor.y + cursor.width - 1, 1 - arduboy.getPixel(col, cursor.y + cursor.width - 1));
    }
  }

  for(int row = cursor.y + 1; row < cursor.y + cursor.width - 1; ++row) {
    arduboy.drawPixel(cursor.x, row, 1 - arduboy.getPixel(cursor.x, row));
    arduboy.drawPixel(cursor.x + cursor.width - 1, row, 1 - arduboy.getPixel(cursor.x + cursor.width - 1, row));
  }
}
