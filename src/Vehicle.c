#include "Object.h"
#include "Vehicle.h"

void Vehicle_construct(void *_this_, int capacity, int topSpeed) {
  Vehicle *this = _this_;
  Object_construct(this); // call superconstructor
  this->capacity = capacity;
  this->topSpeed = topSpeed;
}

int Vehicle_getCapacity(void *_this_) {
  Vehicle *this = _this_;
  return this->capacity;
}

int Vehicle_getTopSpeed(void *_this_) {
  Vehicle *this = _this_;
  return this->topSpeed;
}
