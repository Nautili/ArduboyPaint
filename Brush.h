#ifndef BRUSH_H
#define BRUSH_H

class PaintCursor;

/*
 * Abstract brush class. 
 * Derived classes define how each brush will paint
 */
class Brush {
  public:
    Brush();
    ~Brush();
    virtual void paint(PaintCursor) = 0;
};

#endif
