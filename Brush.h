#ifndef BRUSH_H
#define BRUSH_H

#include "Cursor.h"
class Arduboy;

/*
 * Abstract brush class. 
 * Derived classes define how each brush will paint
 */
class Brush {
  public:
    Brush(Arduboy& arduboy);
    virtual ~Brush();
    virtual void paint(Cursor) = 0;
    virtual void paintIcon(unsigned char x, unsigned char y) = 0;
  protected:
    Arduboy& arduboy;
};

#endif
