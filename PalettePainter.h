#ifndef PALETTE_PAINTER_H
#define PALETTE_PAINTER_H

class Arduboy;
class Palette;

/*
 * A PalettePainter paints the palette and icons for each brush
 */
class PalettePainter {
  public:
    PalettePainter(Arduboy& arduboy, Palette& palette);
    void paint();
    int getPaletteWidth();
  private:
    Arduboy& arduboy;
    Palette& palette;
    static const int paletteWidth = 12;
};

#endif
