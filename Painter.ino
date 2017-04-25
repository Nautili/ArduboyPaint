#include "Arduboy.h"
#include "Brush.h"
#include "Palette.h"
#include "PalettePainter.h"
#include "PaintCursor.h"

Arduboy arduboy;

PaintCursor paintCursor(HEIGHT);
Palette palette;
PalettePainter palettePainter(palette);

void handleInputs() {
  //open menu
  if(arduboy.pressed(A_BUTTON)) {
    //TODO: update menu state
    //animate menu cursor

    if(arduboy.pressed(UP_BUTTON)) {
      paintCursor.increaseWidth();
    }
    else if(arduboy.pressed(DOWN_BUTTON)) {
      paintCursor.decreaseWidth();
    }
    else if(arduboy.pressed(RIGHT_BUTTON)) {
      palette.selectNext();
    }
    else if(arduboy.pressed(LEFT_BUTTON)) {
      palette.selectPrev();
    }
  }
  else {
    if(arduboy.pressed(B_BUTTON)) {
      palette.getCurrentBrush()->paint(paintCursor);
    }
    if(arduboy.pressed(UP_BUTTON)) {

    }
    if(arduboy.pressed(DOWN_BUTTON)) {

    }
    if(arduboy.pressed(RIGHT_BUTTON)) {
      
    }
    if(arduboy.pressed(LEFT_BUTTON)) {
      
    }
  }
}

void updateDisplay() {
  //TODO: Think this through
  palettePainter.paint();
}

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(15);
  arduboy.display();
}

void loop() {
  handleInputs();
  updateDisplay();
}
