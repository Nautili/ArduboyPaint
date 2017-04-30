#ifndef CIRCLE_ITERATOR_H
#define CIRCLE_ITERATOR_H

/*
 * Iterator to find points in a circle
 */

class CircleIterator {
  public:
    int x;
    int y;
    CircleIterator(float width);
    bool next();
    
  private:
    float width;
    bool inCircle;
    unsigned char quadrantsReturned;
};

#endif
