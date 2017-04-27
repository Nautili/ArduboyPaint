#ifndef INVERTER_BRUSH_H
#define INVERTER_BRUSH_H

#include "Brush.h"

class InverterBrush : public Brush {
  public:
    InverterBrush(Arduboy& arduboy);
    void paint(Cursor);
    void paintIcon(unsigned char x, unsigned char y);
  private:
};

#endif
