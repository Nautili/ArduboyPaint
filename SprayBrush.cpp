#include "SprayBrush.h"
#include "Arduboy.h"
#include <Arduino.h>

constexpr unsigned char SprayBrush::icon[8][8];

SprayBrush::SprayBrush(Arduboy& arduboy) : Brush(arduboy) {

}

unsigned char SprayBrush::gaussianRandom(int maxValue) {
  return (random(maxValue * 5) + random(maxValue * 5)) / 10;
}

void SprayBrush::paint(Cursor pc) {
  int x = gaussianRandom(pc.width) + pc.x;
  int y = gaussianRandom(pc.width) + pc.y;
  arduboy.drawPixel(x, y, WHITE);
}

void SprayBrush::paintIcon(unsigned char x, unsigned char y) {
  for(int row = 0; row < 8; ++row) {
    for(int col = 0; col < 8; ++col) {
      arduboy.drawPixel(x + col, y + row, icon[row][col]);
    }
  }
}
