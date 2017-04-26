#include <Arduino.h>
#include "PaintCursor.h"

PaintCursor::PaintCursor(unsigned char maxWidth) {
  this->maxWidth = maxWidth;
  x = 0;
  y = 0;
  width = 8;
}

void paint() {
  //TODO: implement this
}

void PaintCursor::increaseWidth() {
  width = min(width * 2, maxWidth);
}

void PaintCursor::decreaseWidth() {
  width = max(width / 2, 1);
}

