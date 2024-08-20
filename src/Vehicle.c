#include "Object.h"
#include "Vehicle.h"

#define my(field) (((VehicleData *)(this->_private_)))->field

void Vehicle_construct(void *_this_, int capacity, int topSpeed) {
  Vehicle *this = _this_;
  Object_construct(this); // call superconstructor
  my(capacity) = capacity;
  my(topSpeed) = topSpeed;
}

int Vehicle_getCapacity(void *_this_) {
  Vehicle *this = _this_;
  return my(capacity);
}

int Vehicle_getTopSpeed(void *_this_) {
  Vehicle *this = _this_;
  return my(topSpeed);
}
