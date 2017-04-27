#include "Arduboy.h"
#include "Brush.h"
#include "DitherBrush.h"
#include "Palette.h"
#include "PalettePainter.h"
#include "Cursor.h"
#include "CursorPainter.h"

#define ON true
#define OFF false

Arduboy arduboy;

Cursor cursor(HEIGHT);
CursorPainter cursorPainter(arduboy, cursor);
Palette palette;
PalettePainter palettePainter(arduboy, palette);

static const int FRAME_RATE = 60;
static const int CURSOR_MOVEMENT_DELAY = 20;
static const float CURSOR_FLASH_RATE = 1;
static const int MAX_CURSOR_CYCLES = 7;
static const int PALETTE_WIDTH = palettePainter.getPaletteWidth();

int cursorCycles = 0;

void handleInputs() {
  if(arduboy.buttonsState() > 0) {
    cursorPainter.set(OFF);
    cursorCycles = 0;
  }
  
  if(arduboy.pressed(A_BUTTON)) {
    if(arduboy.pressed(UP_BUTTON)) {
      palette.selectPrev();
    }
    else if(arduboy.pressed(DOWN_BUTTON)) {
      palette.selectNext();
    }
    else if(arduboy.pressed(RIGHT_BUTTON)) {
      cursor.increaseWidth();
    }
    else if(arduboy.pressed(LEFT_BUTTON)) {
      cursor.decreaseWidth();
    }
  }
  else {
    if(arduboy.pressed(B_BUTTON)) {
      palette.getCurrentBrush()->paint(cursor);
    }
    if(arduboy.pressed(UP_BUTTON)) {
      cursor.y = max(cursor.y - 1, 0);
    }
    if(arduboy.pressed(DOWN_BUTTON)) {
      cursor.y = min(cursor.y + 1, HEIGHT - cursor.width);
    }
    if(arduboy.pressed(LEFT_BUTTON)) {
      cursor.x = max(cursor.x - 1, 0);
    }
    if(arduboy.pressed(RIGHT_BUTTON)) {
      cursor.x = min(cursor.x + 1, WIDTH - (cursor.width + PALETTE_WIDTH));
    }
  }

  if(arduboy.buttonsState() > 0) {
    cursorPainter.set(ON);
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
  if(arduboy.everyXFrames(FRAME_RATE / CURSOR_FLASH_RATE) && cursorCycles < MAX_CURSOR_CYCLES) {
    cursorPainter.paint();
    ++cursorCycles;
  }
  palettePainter.paint();
}

void setup() {
  initializeBrushes();
  arduboy.begin();
  arduboy.setFrameRate(FRAME_RATE);
  arduboy.clear();
  arduboy.display();
}

void loop() {
  if(!arduboy.nextFrame()) {
    return;
  }

  updateOverlay();
  handleInputs();
  arduboy.display();
}
