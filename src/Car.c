#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "Car.h"
#include "Object.h"
#include "Vehicle.h"

static CarVtable carVtable = {
  .offset = 0,
  .hashCode = Object_hashCode,        // inherit from Object
  .toString = Car_toString,
  .getCapacity = Vehicle_getCapacity, // inherit from Vehicle
  .getTopSpeed = Vehicle_getTopSpeed, // inherit from Vehicle
  .move = Car_move,                   // implementation
  .getNumberOfWheels = Car_getNumberOfWheels,
  /* Cloneable Interface Slot */
  .offsetCloneable = offsetof(CarVtable, offsetCloneable),
  .clone = Car_clone,                 // implementation
};

void Car_construct(void *_this_,
    int capacity, int topSpeed, int numberOfWheels) {
  Car *this = _this_;
  Vehicle_construct(this, capacity, topSpeed); // call superconstructor
  this->numberOfWheels = numberOfWheels;
  this->vtableCloneable = (CloneableVtable *)&carVtable.offsetCloneable;
}

Car *Car_new(int capacity, int topSpeed, int numberOfWheels) {
  puts("Creating Car.");

  Car *this = malloc(sizeof(Car));
  this->vtable = &carVtable;
  Car_construct(this, capacity, topSpeed, numberOfWheels);

  return this;
}

void Car_delete(Car *car) {
  puts("Deleting Car.");
  free(car);
}

char *Car_toString(void *_this_) {
  Car *this = _this_;
  char *string = malloc(64);
  sprintf(string, "Car[capacity=%d, topSpeed=%d, numberOfWheels=%d]",
      this->capacity, this->topSpeed, this->numberOfWheels);
  return string;
}

void Car_move(void *_this_) {
  puts("I am a Car! I drive along the road.");
}

int Car_getNumberOfWheels(void *_this_) {
  Car *this = _this_;
  return this->numberOfWheels;
}

void *Car_clone(void *_this_) {
  Car *this = _this_;
  return Car_new(this->capacity, this->topSpeed, this->numberOfWheels);
}
