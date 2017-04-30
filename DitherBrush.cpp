#include "DitherBrush.h"
#include "Arduboy.h"
#include "CircleIterator.h"

constexpr unsigned char DitherBrush::ditherOrder[4][4];

DitherBrush::DitherBrush(Arduboy& arduboy, unsigned char ditherLevel) : Brush(arduboy) {
  this->ditherLevel = ditherLevel;
}

void DitherBrush::paint(Cursor pc) {
  CircleIterator iter(pc.width);
  while(iter.next()) {
    int color = ditherOrder[(pc.y + iter.y) % 4][(pc.x + iter.x) % 4] < ditherLevel;
    arduboy.drawPixel(pc.x + iter.x, pc.y + iter.y, color);
  }
}

void DitherBrush::paintIcon(unsigned char x, unsigned char y) {
  for(int row = 0; row < 8; ++row) {
    for(int col = 0; col < 8; ++col) {
      int color = ditherOrder[row % 4][col % 4] < ditherLevel;
      arduboy.drawPixel(x + col, y + row, color);
    }
  }
}

