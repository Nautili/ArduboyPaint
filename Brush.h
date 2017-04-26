#ifndef BRUSH_H
#define BRUSH_H

class Arduboy;
class PaintCursor;

/*
 * Abstract brush class. 
 * Derived classes define how each brush will paint
 */
class Brush {
  public:
    Brush(Arduboy& arduboy);
    virtual ~Brush();
    virtual void paint(PaintCursor) = 0;
  protected:
    Arduboy& arduboy;
};

#endif
