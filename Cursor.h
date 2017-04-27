#ifndef CURSOR_H
#define CURSOR_H

/*
 * Contains position and width for the cursor.
 * Note: This is separate from the Brush class which only
 *       describes how a brush will paint.
 */

class Cursor {
  public:
    char x;
    char y;
    char width;

    Cursor(char x, char y);
    Cursor();
};

#endif
