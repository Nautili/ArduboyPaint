#include "FillBrush.h"
#include "Arduboy.h"

constexpr unsigned char FillBrush::icon[8][8];

FillBrush::FillBrush(Arduboy& arduboy, unsigned char color) : Brush(arduboy) {
  this->color = color;
}

void FillBrush::paint(Cursor pc) {
  arduboy.fillScreen(color);
}

void FillBrush::paintIcon(unsigned char x, unsigned char y) {
  for(int row = 0; row < 8; ++row) {
    for(int col = 0; col < 8; ++col) {
      int pixelColor = icon[row][col];
      if(pixelColor == 2) {
          pixelColor = color;
      }
      arduboy.drawPixel(x + col, y + row, pixelColor);
    }
  }
}
