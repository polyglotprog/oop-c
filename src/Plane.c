#include <stdio.h>
#include <stdlib.h>
#include "Plane.h"
#include "Object.h"
#include "Vehicle.h"

const PlaneVtable Plane_vtable = {
  .offset = 0,
  .construct = Plane_construct,
  .destruct = Plane_destruct,
  .hashCode = Object_hashCode,        // inherit from Object
  .toString = Plane_toString,
  .getCapacity = Vehicle_getCapacity, // inherit from Vehicle
  .getTopSpeed = Vehicle_getTopSpeed, // inherit from Vehicle
  .move = Plane_move,                 // implementation
};

void Plane_construct(void *_this_, int capacity, int topSpeed) {
  Plane *this = _this_;
  Vehicle_construct(this, capacity, topSpeed); // call superconstructor
}

void Plane_destruct(void *_this_) {
  puts("Deleting Plane.");
}

char *Plane_toString(void *_this_) {
  Plane *this = _this_;
  char *string = malloc(64);
  sprintf(string, "Plane[capacity=%d, topSpeed=%d]",
      this->capacity, this->topSpeed);
  return string;
}

void Plane_move(void *_this_) {
  puts("I am a Plane! I fly in the air.");
}
