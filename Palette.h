#ifndef PALETTE_H
#define PALETTE_H

class Brush;
const unsigned char MAX_BRUSHES = 30;

/*
 * Data structure and methods for a set of brushes
 */
class Palette {
  public:
    Palette();
    void addBrush(Brush* brush);
    void selectNext();
    void selectPrev();
    Brush* getBrush(int index);
    Brush* getCurrentBrush();
  private:
    Brush* brushes[MAX_BRUSHES];
    int numBrushes;
    int brushIndex;
};

#endif
