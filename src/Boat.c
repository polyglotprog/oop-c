#include <stdio.h>
#include <stdlib.h>
#include "Boat.h"
#include "Object.h"
#include "Vehicle.h"

const BoatVtable Boat_vtable = {
  .offset = 0,
  .construct = Boat_construct,
  .destruct = Boat_destruct,
  .hashCode = Object_hashCode,        // inherit from Object
  .toString = Boat_toString,
  .getCapacity = Vehicle_getCapacity, // inherit from Vehicle
  .getTopSpeed = Vehicle_getTopSpeed, // inherit from Vehicle
  .move = Boat_move,                  // implementation
};

void Boat_construct(void *_this_, int capacity, int topSpeed) {
  Boat *this = _this_;
  Vehicle_construct(this, capacity, topSpeed); // call superconstructor
}

void Boat_destruct(void *_this_) {
  puts("Deleting Boat.");
}

char *Boat_toString(void *_this_) {
  Boat *this = _this_;
  char *string = malloc(64);
  sprintf(string, "Boat[capacity=%d, topSpeed=%d]",
      this->capacity, this->topSpeed);
  return string;
}

void Boat_move(void *_this_) {
  puts("I am a Boat! I sail in the water.");
}
