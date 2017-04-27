#include "Cursor.h"
#include <Arduino.h>

Cursor::Cursor(unsigned char x, unsigned char y, unsigned char maxWidth) {
  this->maxWidth = maxWidth;
  this->x = x;
  this->y = y;
  width = 8;
}

Cursor::Cursor(unsigned char maxWidth) : Cursor(0, 0, maxWidth) {

}

void Cursor::increaseWidth() {
  width = min(width + 1, maxWidth);
}

void Cursor::decreaseWidth() {
  width = max(width - 1, 1);
}

