#include "CircleIterator.h"

CircleIterator::CircleIterator(float width) {
  this->width = width - 1;
  x = 0;
  y = 0;
  inCircle = false;
  quadrantsReturned = 0;
}

/*
 * Iterates to the next point inside a quadrant, then iterates to the mirrors
 * in each of the other quadrant. This is definitely not the fastest, but it
 * should be good enough.
 */
bool CircleIterator::next() {
  if(quadrantsReturned > 0) {
      x = width - x;

      if(quadrantsReturned % 2 == 0) {
        y = width - y;
      }
      quadrantsReturned = (quadrantsReturned + 1) % 5;
      
      if(quadrantsReturned > 0) {
        return true;
      }
  }

  float radius = width / 2;
  if(inCircle) {
    ++x;
  }  
  if(x > radius) {
    x = 0;
    ++y;
    inCircle = false;
  }
  if(y > radius) {
    return false;
  }

  if(!inCircle) {
    float distX = radius - 0.5;
    float distY = radius - y - 0.5;
    while(distX * distX + distY * distY > radius * radius && x < radius) {
      ++x;
      distX -= 1;
    }

    inCircle = true;
  }

  quadrantsReturned = 1;
  return true;
}

