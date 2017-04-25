#ifndef PALETTE_H
#define PALETTE_H

class Brush;

/*
 * Data structure and methods for a set of brushes
 */
class Palette {
  public:
    Palette();
    void selectNext();
    void selectPrev();
    Brush* getBrush(int index);
    Brush* getCurrentBrush();
  private:
    Brush* brushes[];
    int brushIndex;
};

#endif
