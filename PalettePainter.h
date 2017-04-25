#ifndef PALETTE_PAINTER_H
#define PALETTE_PAINTER_H

/*
 * A PalettePainter paints the palette and icons for each brush
 */
class PalettePainter {
  public:
    PalettePainter(Palette& palette);
    void paint();
  private:
    const Palette& palette;
    //TODO: some notion of state (animation, etc)
};

#endif
