#include "PalettePainter.h"
#include "Palette.h"
#include "Arduboy.h"

PalettePainter::PalettePainter(Arduboy& arduboy, Palette& palette) : arduboy(arduboy), palette(palette) {
  
}

void PalettePainter::paint() {
  //TODO: implement this
}

int PalettePainter::getPaletteWidth() {
  return paletteWidth;
}

