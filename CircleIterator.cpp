#include "CircleIterator.h"

CircleIterator::CircleIterator(int width) {
  this->width = width;
  x = 1; //ignore outermost points for a smoother brush
  y = 1;
  inCircle = false;
  quadrantsReturned = 0;
}

/*
 * Iterates to the next point inside a quadrant.
 * It's up to the user to decide how to use the quadrant
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

  int radius = width / 2;
  if(inCircle) {
    ++x;
  }  
  if(x > radius) {
    x = 1;
    ++y;
    inCircle = false;
  }
  if(y > radius) {
    return false;
  }

  if(!inCircle) {
    int distX = radius;
    int distY = radius - y;
    while(distX * distX + distY * distY >= radius * radius && x < radius) {
      ++x;
      --distX;
    }

    inCircle = true;
  }

  quadrantsReturned = 1;
  return true;
}

