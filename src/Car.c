#include <stdio.h>
#include <stdlib.h>
#include "Car.h"
#include "Object.h"
#include "Vehicle.h"

typedef struct CarPrivateData {
  int numberOfWheels;
} CarPrivateData;

#define my(field) (((CarPrivateData *)(this->_private)))->field

char *Car_toString(void *car) {
  Car *this = car;
  char* string = malloc(64);
  sprintf(string, "Car[capacity=%d, topSpeed=%d, numberOfWheels=%d]",
      this->capacity, this->topSpeed, my(numberOfWheels));
  return string;
}

int Car_getCapacity(void *car) {
  Car *this = car;
  return this->capacity;
}

int Car_getTopSpeed(void *car) {
  Car *this = car;
  return this->topSpeed;
}

void Car_move(void *car) {
  puts("I am a Car! I drive along the road.");
}

int Car_getNumberOfWheels(void *car) {
  Car *this = car;
  return my(numberOfWheels);
}

void *Car_clone(void *car) {
  Car *this = car;
  return Car_new(this->capacity, this->topSpeed, my(numberOfWheels));
}

static CarVtable carVtable = {
  .offset = 0,
  .hashCode = Object_hashCode,
  .toString = Car_toString,
  .getCapacity = Car_getCapacity,
  .getTopSpeed = Car_getTopSpeed,
  .move = Car_move,
  .getNumberOfWheels = Car_getNumberOfWheels,
  .cloneableOffset = /* 24 */ sizeof(struct {
    CarVtable *vtable;
    int intFields[3];
    // all fields before CloneableVtable
  }),
  .clone = Car_clone
};

void Car_construct(void *car, int capacity, int topSpeed, int numberOfWheels) {
  Vehicle_construct(car, capacity, topSpeed); // call superconstructor
  Car *this = car;
  my(numberOfWheels) = numberOfWheels;
  this->vtableCloneable = (CloneableVtable *)&carVtable.cloneableOffset;
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

#undef my
