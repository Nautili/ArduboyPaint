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
static const float CURSOR_MOVEMENT_DELAY = 0.1;
static const float CURSOR_RESIZE_DELAY = 0.1;
static const float CURSOR_FLASH_RATE = 1;
static const int MAX_CURSOR_CYCLES = 5;
static const int PALETTE_WIDTH = palettePainter.getPaletteWidth();
static const float PALETTE_MOVEMENT_DELAY = 0.1;

int cursorCycles = 0;
int cursorFramesHeld = 0;
int paletteFramesHeld = 0;

void handleInputs() {
  //reset cursor animation when any button is pressed
  if(arduboy.buttonsState() > 0) {
    cursorPainter.set(OFF);
    cursorCycles = 0;
  }
  
  if(arduboy.pressed(A_BUTTON)) {
    //handle palette selection
    if(paletteFramesHeld == 0) {
      if(arduboy.pressed(UP_BUTTON)) {
        palette.selectPrev();
      }
      if(arduboy.pressed(DOWN_BUTTON)) {
        palette.selectNext();
      }
    }

    if(arduboy.pressed(UP_BUTTON) || arduboy.pressed(DOWN_BUTTON)) {
      paletteFramesHeld = (paletteFramesHeld + 1) % (int)(PALETTE_MOVEMENT_DELAY * FRAME_RATE);
    }
    else {
      paletteFramesHeld = 0;
    }

    //handle cursor resizing
    if(cursorFramesHeld > CURSOR_RESIZE_DELAY * FRAME_RATE || cursorFramesHeld == 0) {
      if(arduboy.pressed(RIGHT_BUTTON)) {
        cursor.increaseWidth();
      }
      if(arduboy.pressed(LEFT_BUTTON)) {
        cursor.decreaseWidth();
      }
    }

    if((arduboy.buttonsState() & (UP_BUTTON | DOWN_BUTTON | RIGHT_BUTTON | LEFT_BUTTON)) > 0) {
      ++cursorFramesHeld;
    }
    else {
      cursorFramesHeld = 0;
    }
  }
  else {
    //handle paint
    if(arduboy.pressed(B_BUTTON)) {
      palette.getCurrentBrush()->paint(cursor);
    }

    //handle cursor movement
    if(cursorFramesHeld >= CURSOR_MOVEMENT_DELAY * FRAME_RATE || cursorFramesHeld == 0) {
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

    //check if button is still held down
    if((arduboy.buttonsState() & (UP_BUTTON | DOWN_BUTTON | RIGHT_BUTTON | LEFT_BUTTON)) > 0) {
      ++cursorFramesHeld;
    }
    else {
      cursorFramesHeld = 0;
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
