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

    /*Paint 8x8 icon at location (x, y)*/
    virtual void paintIcon(unsigned char x, unsigned char y);
  protected:
    Arduboy& arduboy;
    static constexpr unsigned char defaultIcon[8][8] = {{1, 1, 1, 1, 1, 1, 1, 1},
                                                        {1, 1, 0, 0, 0, 0, 0, 1},
                                                        {1, 0, 1, 0, 0, 0, 0, 1},
                                                        {1, 0, 0, 1, 0, 0, 0, 1},
                                                        {1, 0, 0, 0, 1, 0, 0, 1},
                                                        {1, 0, 0, 0, 0, 1, 0, 1},
                                                        {1, 0, 0, 0, 0, 0, 1, 1},
                                                        {1, 1, 1, 1, 1, 1, 1, 1}};
};

#endif
