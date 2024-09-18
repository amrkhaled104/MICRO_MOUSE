#include "walls.h"

bool wallFront() {
  return (digitalRead(FRONT_SENSOR_PIN) == LOW); // إذا كان هناك جدار أمامي
}

bool wallRight() {
  return (digitalRead(RIGHT_SENSOR_PIN) == LOW); // إذا كان هناك جدار يمين
}

bool wallLeft() {
  return (digitalRead(LEFT_SENSOR_PIN) == LOW); // إذا كان هناك جدار يسار
}
