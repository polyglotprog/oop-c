#include <stdio.h>
#include <stdlib.h>
#include "Boat.h"
#include "Object.h"
#include "Vehicle.h"

static BoatVtable boatVtable = {
  .offset = 0,
  .hashCode = Object_hashCode,        // inherit from Object
  .toString = Boat_toString,
  .getCapacity = Vehicle_getCapacity, // inherit from Vehicle
  .getTopSpeed = Vehicle_getTopSpeed, // inherit from Vehicle
  .move = Boat_move,                  // implementation
};

Boat *Boat_new(int capacity, int topSpeed) {
  puts("Creating Boat.");

  Boat *this = malloc(sizeof(Boat));
  this->vtable = &boatVtable;
  Boat_construct(this, capacity, topSpeed);

  return this;
}

void Boat_construct(void *_this_, int capacity, int topSpeed) {
  Boat *this = _this_;
  Vehicle_construct(this, capacity, topSpeed); // call superconstructor
}

void Boat_delete(Boat *boat) {
  puts("Deleting Boat.");
  free(boat);
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
