#include "Arduboy.h"
#include "Brush.h"
#include "PaintCursor.h"
#include "DitherBrush.h"

constexpr unsigned char DitherBrush::ditherOrder[4][4];

DitherBrush::DitherBrush(Arduboy& arduboy, unsigned char ditherLevel) : Brush(arduboy) {
  this->ditherLevel = ditherLevel;
}

void DitherBrush::paint(PaintCursor pc) {
  for(int row = pc.y; row < pc.y + pc.width; ++row) {
    for(int col = pc.x; col < pc.x + pc.width; ++col) {
      int color = ditherOrder[row % 4][col % 4] > ditherLevel ? 1 : 0;
      arduboy.drawPixel(col, row, color);
    }
  }
}

