#include "Cursor.h"
#include <Arduino.h>

Cursor::Cursor(unsigned char maxWidth) {
  this->maxWidth = maxWidth;
  x = 0;
  y = 0;
  width = 8;
}

void Cursor::paint() {
  //TODO: implement this
}

void Cursor::increaseWidth() {
  width = min(width * 2, maxWidth);
}

void Cursor::decreaseWidth() {
  width = max(width / 2, 1);
}

