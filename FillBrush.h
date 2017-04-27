#ifndef FILL_BRUSH_H
#define FILL_BRUSH_H

#include "Brush.h"

class FillBrush : public Brush {
  public:
    FillBrush(Arduboy& arduboy, unsigned char color);
    void paint(Cursor);
    void paintIcon(unsigned char x, unsigned char y);
  private:
    unsigned char color;
    static constexpr unsigned char icon[8][8] = {{0, 0, 1, 1, 1, 1, 0, 0},
                                                 {0, 1, 2, 2, 2, 2, 1, 0},
                                                 {0, 1, 1, 1, 1, 1, 1, 0},
                                                 {0, 1, 0, 0, 0, 0, 1, 0},
                                                 {0, 1, 1, 0, 0, 1, 1, 0},
                                                 {0, 1, 0, 1, 1, 0, 1, 0},
                                                 {0, 1, 0, 0, 0, 0, 1, 0},
                                                 {0, 0, 1, 1, 1, 1, 0, 0}};
};

#endif
