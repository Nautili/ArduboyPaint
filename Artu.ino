#include "Arduboy.h"
#include "Brush.h"
#include "DitherBrush.h"
//#include "GlitchBrush.h"
#include "FillBrush.h"
#include "SprayBrush.h"
#include "Palette.h"
#include "PalettePainter.h"
#include "Cursor.h"
#include "CursorPainter.h"

#define ON true
#define OFF false

Arduboy arduboy;

Cursor cursor;
CursorPainter cursorPainter(arduboy, cursor);
Palette palette;
PalettePainter palettePainter(arduboy, palette);

static const unsigned char FRAME_RATE = 60;
static const float CURSOR_MOVEMENT_DELAY = 0.1;
static const float CURSOR_RESIZE_DELAY = 0.1;
static const float CURSOR_FLASH_RATE = 1;
static const unsigned char MAX_CURSOR_CYCLES = 5;
static const unsigned char PALETTE_WIDTH = palettePainter.getPaletteWidth();
static const float PALETTE_MOVEMENT_DELAY = 0.1;

unsigned char cursorCycles = 0;
unsigned char cursorFramesHeld = 0;
unsigned char paletteFramesHeld = 0;

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
        ++cursor.width;
        if((cursor.x + cursor.width > WIDTH - PALETTE_WIDTH) || (cursor.y + cursor.width > HEIGHT)) {
          --cursor.width;
        }
      }
      if(arduboy.pressed(LEFT_BUTTON)) {
        cursor.width = max(cursor.width - 1, 1);
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
  //palette.addBrush(new GlitchBrush(arduboy));
  palette.addBrush(new SprayBrush(arduboy));
  palette.addBrush(new FillBrush(arduboy, WHITE));
  palette.addBrush(new FillBrush(arduboy, BLACK));
  
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

  handleInputs();
  updateOverlay();
  arduboy.display();
}
