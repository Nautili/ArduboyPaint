#include "Brush.h"
#include <Arduino.h>
#include "Palette.h"

Palette::Palette(){
  numBrushes = 0;
  brushIndex = 0;
}

void Palette::addBrush(Brush* brush) {
  brushes[numBrushes] = brush;
  ++numBrushes;
}

void Palette::selectNext() {
  brushIndex = min(brushIndex + 1, numBrushes - 1);
}

void Palette::selectPrev() {
  brushIndex = max(brushIndex - 1, 0);
}

Brush* Palette::getBrush(int index) {
  return brushes[index];
}

Brush* Palette::getCurrentBrush() {
  return getBrush(brushIndex);
}

