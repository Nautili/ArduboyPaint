#include "Cursor.h"
#include <Arduino.h>

Cursor::Cursor(char x, char y) {
  this->x = x;
  this->y = y;
  width = 8;
}

Cursor::Cursor() : Cursor(0, 0) {

}

