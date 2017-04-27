#ifndef DITHER_BRUSH_H
#define DITHER_BRUSH_H

#include "Brush.h"

/*
 * Draws a dithered circle using a 4x4 ordered dither
 */
class DitherBrush : public Brush {
  public:
    DitherBrush(Arduboy& arduboy, unsigned char ditherLevel);
    void paint(Cursor);
    void paintIcon(unsigned char x, unsigned char y);
  private:
    unsigned char ditherLevel;
    static constexpr unsigned char ditherOrder[4][4] = {{ 0,  8,  2, 10},
                                                        {12,  4, 14,  6},
                                                        { 3, 11,  1,  9},
                                                        {15,  7, 13,  5}};
};

#endif

