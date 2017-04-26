#include "Arduboy.h"
#include "Brush.h"
#include "DitherBrush.h"
#include "Palette.h"
#include "PalettePainter.h"
#include "PaintCursor.h"

Arduboy arduboy;

PaintCursor paintCursor(HEIGHT);
Palette palette;
PalettePainter palettePainter(arduboy, palette);

void handleInputs() {
  //TODO: handle input delays
  if(arduboy.pressed(A_BUTTON)) {
    //TODO: update menu state
    //animate menu cursor

    if(arduboy.pressed(UP_BUTTON)) {
      palette.selectPrev();
    }
    else if(arduboy.pressed(DOWN_BUTTON)) {
      palette.selectNext();
    }
    else if(arduboy.pressed(RIGHT_BUTTON)) {
      paintCursor.increaseWidth();
    }
    else if(arduboy.pressed(LEFT_BUTTON)) {
      paintCursor.decreaseWidth();
    }
  }
  else {
    if(arduboy.pressed(B_BUTTON)) {
      palette.getCurrentBrush()->paint(paintCursor);
    }
    if(arduboy.pressed(UP_BUTTON)) {
      paintCursor.y = max(paintCursor.y - 1, 0);
    }
    if(arduboy.pressed(DOWN_BUTTON)) {
      paintCursor.y = min(paintCursor.y + 1, HEIGHT - paintCursor.width);
    }
    if(arduboy.pressed(LEFT_BUTTON)) {
      paintCursor.x = max(paintCursor.x - 1, 0);
    }
    if(arduboy.pressed(RIGHT_BUTTON)) {
      paintCursor.x = min(paintCursor.x + 1, WIDTH - paintCursor.width);
    }
  }
}

/*
 * Register brushes here
 */
void initializeBrushes() {
  for(int i = 0; i <= 16; ++i) {
    palette.addBrush(new DitherBrush(arduboy, i));
  }
}

void updateOverlay() {
  //TODO: Think this through
  palettePainter.paint();
  //paintCursor.paint();
}

void setup() {
  initializeBrushes();
  arduboy.begin();
  arduboy.setFrameRate(60);
  arduboy.clear();
  arduboy.display();
}

void loop() {
  if(!arduboy.nextFrame()) {
    return;
  }
  
  handleInputs();
  //updateOverlay();
  arduboy.display();
}
