#include "PalettePainter.h"
#include "Palette.h"
#include "Arduboy.h"
#include "Brush.h"

PalettePainter::PalettePainter(Arduboy& arduboy, Palette& palette) : arduboy(arduboy), palette(palette) {
  
}

void PalettePainter::paint() {
  arduboy.fillRect(WIDTH-12, 0, 12, HEIGHT, BLACK);
  
  int curBrushIndex = palette.getCurrentBrushIndex();
  for(int i = 0; i < palette.getNumBrushes(); ++i) {
    int brushHeight = 26 - (curBrushIndex - i) * 9;
    palette.getBrush(i)->paintIcon(WIDTH - 11, brushHeight);
  }

  arduboy.drawRect(WIDTH-2, 26, 2, 8, WHITE);
}

int PalettePainter::getPaletteWidth() {
  return paletteWidth;
}

