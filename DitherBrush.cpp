#include "DitherBrush.h"
#include "Arduboy.h"

constexpr unsigned char DitherBrush::ditherOrder[4][4];

DitherBrush::DitherBrush(Arduboy& arduboy, unsigned char ditherLevel) : Brush(arduboy) {
  this->ditherLevel = ditherLevel;
}

void DitherBrush::paint(Cursor pc) {
  float centerX = pc.x + pc.width / 2;
  float centerY = pc.y + pc.width / 2;
  for(int row = pc.y; row < pc.y + pc.width; ++row) {
    for(int col = pc.x; col < pc.x + pc.width; ++col) {
      float distX = centerX - col;
      float distY = centerY - row;
      if(distX * distX + distY * distY <= pc.width * pc.width / 4) {
        int color = ditherOrder[row % 4][col % 4] < ditherLevel;
        arduboy.drawPixel(col, row, color);
      }
    }
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

