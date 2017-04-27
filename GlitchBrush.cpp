#include "GlitchBrush.h"
#include "Arduboy.h"

constexpr unsigned char GlitchBrush::icon[8][8];

GlitchBrush::GlitchBrush(Arduboy& arduboy) : Brush(arduboy) {

}

void GlitchBrush::paint(Cursor pc) {
  float centerX = pc.x + pc.width / 2;
  float centerY = pc.y + pc.width / 2;
  for(int row = pc.y; row < pc.y + pc.width; ++row) {
    for(int col = pc.x; col < pc.x + pc.width; ++col) {
      float distX = centerX - col;
      float distY = centerY - row;
      if(distX * distX + distY * distY <= pc.width * pc.width / 4) {
        arduboy.drawPixel(col, row, 1 - arduboy.getPixel(col, row));
      }
    }
  }
}

void GlitchBrush::paintIcon(unsigned char x, unsigned char y) {
  for(int row = 0; row < 8; ++row) {
    for(int col = 0; col < 8; ++col) {
      arduboy.drawPixel(x + col, y + row, icon[row][col]);
    }
  }
}
