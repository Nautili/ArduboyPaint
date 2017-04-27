#include "Cursor.h"
#include <Arduino.h>

Cursor::Cursor(unsigned char x, unsigned char y) {
  this->x = x;
  this->y = y;
  width = 8;
}

Cursor::Cursor() : Cursor(0, 0) {

}

