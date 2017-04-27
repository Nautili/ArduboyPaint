#ifndef GLITCH_BRUSH_H
#define GLITCH_BRUSH_H

#include "Brush.h"

class GlitchBrush : public Brush {
  public:
    GlitchBrush(Arduboy& arduboy);
    void paint(Cursor);
    void paintIcon(unsigned char x, unsigned char y);
  private:
    static constexpr unsigned char icon[8][8] = {{1, 0, 1, 0, 1, 0, 1, 0},
                                                 {1, 0, 1, 0, 1, 0, 1, 0},
                                                 {0, 1, 0, 1, 0, 1, 0, 1},
                                                 {0, 1, 0, 1, 0, 1, 0, 1},
                                                 {1, 0, 1, 0, 1, 0, 1, 0},
                                                 {1, 0, 1, 0, 1, 0, 1, 0},
                                                 {0, 1, 0, 1, 0, 1, 0, 1},
                                                 {0, 1, 0, 1, 0, 1, 0, 1}};
};

#endif
