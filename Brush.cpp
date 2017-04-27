#include "Brush.h"
#include "Arduboy.h"

constexpr unsigned char Brush::defaultIcon[8][8];

Brush::Brush(Arduboy& arduboy) : arduboy(arduboy) {
  
}

Brush::~Brush() {
  
}

/*
 * Default icon paint method
 */
void Brush::paintIcon(unsigned char x, unsigned char y) {
  for(int row = 0; row < 8; ++row) {
    for(int col = 0; col < 8; ++col) {
      arduboy.drawPixel(x + col, y + row, defaultIcon[row][col]);
    }
  }
}

