#include "Object.h"
#include "Vehicle.h"

void Vehicle_construct(void *vehicle, int capacity, int topSpeed) {
  Object_construct(vehicle); // call superconstructor
  Vehicle *this = vehicle;
  this->capacity = capacity;
  this->topSpeed = topSpeed;
}

int Vehicle_getCapacity(void *vehicle) {
  Vehicle *this = vehicle;
  return this->capacity;
}

int Vehicle_getTopSpeed(void *vehicle) {
  Vehicle *this = vehicle;
  return this->topSpeed;
}
