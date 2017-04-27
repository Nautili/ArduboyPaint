#ifndef SPRAY_BRUSH_H
#define SPRAY_BRUSH_H

#include "Brush.h"

class SprayBrush : public Brush {
  public:
    SprayBrush(Arduboy& arduboy);
    void paint(Cursor);
    void paintIcon(unsigned char x, unsigned char y);
  private:
    unsigned char gaussianRandom(int maxValue);
    static constexpr unsigned char icon[8][8] = {{0, 0, 0, 1, 0, 0, 0, 0},
                                                 {0, 0, 1, 0, 1, 0, 0, 0},
                                                 {0, 1, 0, 1, 0, 1, 0, 0},
                                                 {0, 1, 1, 0, 1, 0, 1, 1},
                                                 {0, 1, 0, 1, 0, 0, 1, 1},
                                                 {0, 1, 1, 0, 1, 1, 0, 0},
                                                 {0, 0, 1, 0, 1, 0, 0, 0},
                                                 {0, 0, 0, 1, 0, 0, 0, 0}};
};

#endif
