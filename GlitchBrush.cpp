#include "GlitchBrush.h"
#include "Arduboy.h"
#include "CircleIterator.h"

constexpr unsigned char GlitchBrush::icon[8][8];

GlitchBrush::GlitchBrush(Arduboy& arduboy) : Brush(arduboy) {

}

void GlitchBrush::paint(Cursor pc) {
  CircleIterator iter(pc.width);
  while(iter.next()) {
    arduboy.drawPixel(pc.x + iter.x, pc.y + iter.y, 1 - arduboy.getPixel(pc.x + iter.x, pc.y + iter.y));
  }
}

void GlitchBrush::paintIcon(unsigned char x, unsigned char y) {
  for(int row = 0; row < 8; ++row) {
    for(int col = 0; col < 8; ++col) {
      arduboy.drawPixel(x + col, y + row, icon[row][col]);
    }
  }
}
