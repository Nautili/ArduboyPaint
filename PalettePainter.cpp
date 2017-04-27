#include "PalettePainter.h"
#include "Palette.h"
#include "Arduboy.h"
#include "Brush.h"

PalettePainter::PalettePainter(Arduboy& arduboy, Palette& palette) : arduboy(arduboy), palette(palette) {
  
}

void PalettePainter::paint() {
  arduboy.fillRect(WIDTH-12, 0, 12, HEIGHT, BLACK);
  
  int curBrushIndex = palette.getCurrentBrushIndex();
  for(int i = max(0, curBrushIndex - 3); i < min(curBrushIndex + 4, palette.getNumBrushes()); ++i) {
    int brushHeight = 27 - (curBrushIndex - i) * 9;
    palette.getBrush(i)->paintIcon(WIDTH - 11, brushHeight);
  }

  arduboy.drawRect(WIDTH-2, 27, 2, 8, WHITE);
}

int PalettePainter::getPaletteWidth() {
  return paletteWidth;
}

