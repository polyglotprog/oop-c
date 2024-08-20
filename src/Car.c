#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "new.h"
#include "Car.h"
#include "Object.h"
#include "Vehicle.h"

const CarVtable Car_vtable = {
  .offset = 0,
  .construct = Car_construct,
  .destruct = Car_destruct,
  .hashCode = Object_hashCode,        // inherit from Object
  .toString = Car_toString,
  .getCapacity = Vehicle_getCapacity, // inherit from Vehicle
  .getTopSpeed = Vehicle_getTopSpeed, // inherit from Vehicle
  .move = Car_move,                   // implementation
  .getNumberOfWheels = Car_getNumberOfWheels,
  /* Cloneable Interface Slot */
  .offsetCloneable = offsetof(Car, vtableCloneable),
  .clone = Car_clone,                 // implementation
};

#define my(field) (((CarData *)(this->_private_)))->field

void Car_construct(void *_this_,
    int capacity, int topSpeed, int numberOfWheels) {
  Car *this = _this_;
  Vehicle_construct(this, capacity, topSpeed); // call superconstructor
  my(numberOfWheels) = numberOfWheels;
  this->vtableCloneable = (CloneableVtable *)&Car_vtable.offsetCloneable;
}

void Car_destruct(void *_this_) {
  puts("Deleting Car.");
}

char *Car_toString(void *_this_) {
  Car *this = _this_;
  char *string = malloc(64);
  sprintf(string, "Car[capacity=%d, topSpeed=%d, numberOfWheels=%d]",
      Vehicle_getCapacity(this), Vehicle_getTopSpeed(this), my(numberOfWheels));
  return string;
}

void Car_move(void *_this_) {
  puts("I am a Car! I drive along the road.");
}

int Car_getNumberOfWheels(void *_this_) {
  Car *this = _this_;
  return my(numberOfWheels);
}

void *Car_clone(void *_this_) {
  Car *this = _this_;
  return new(Car,
      Vehicle_getCapacity(this), Vehicle_getTopSpeed(this), my(numberOfWheels));
}

#undef my
