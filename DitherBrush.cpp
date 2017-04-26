#include "DitherBrush.h"
#include "Arduboy.h"

constexpr unsigned char DitherBrush::ditherOrder[4][4];

DitherBrush::DitherBrush(Arduboy& arduboy, unsigned char ditherLevel) : Brush(arduboy) {
  this->ditherLevel = ditherLevel;
}

void DitherBrush::paint(PaintCursor pc) {
  int centerX = pc.x + pc.width / 2;
  int centerY = pc.y + pc.width / 2;
  for(int row = pc.y; row < pc.y + pc.width; ++row) {
    for(int col = pc.x; col < pc.x + pc.width; ++col) {
      int distX = centerX - col;
      int distY = centerY - row;
      if(distX * distX + distY * distY <= pc.width * pc.width / 4) {
        int color = ditherOrder[row % 4][col % 4] < ditherLevel ? 1 : 0;
        arduboy.drawPixel(col, row, color);
      }
    }
  }
}

void DitherBrush::paintIcon(unsigned char x, unsigned char y) {
  
}

