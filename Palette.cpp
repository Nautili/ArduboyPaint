#include "Brush.h"
#include <Arduino.h>
#include "Palette.h"

Palette::Palette(){

}

void Palette::selectNext() {
  //TODO: Fill this in once constructor is finished
  //need to know how many brushes ahead of time?
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

