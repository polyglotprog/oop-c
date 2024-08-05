#include <stdio.h>
#include <stdlib.h>
#include "Boat.h"
#include "Object.h"
#include "Vehicle.h"

char *Boat_toString(void *boat) {
  Boat *this = boat;
  char* string = malloc(64);
  sprintf(string, "Boat[capacity=%d, topSpeed=%d]",
      this->capacity, this->topSpeed);
  return string;
}

int Boat_getCapacity(void *boat) {
  Boat *this = boat;
  return this->capacity;
}

int Boat_getTopSpeed(void *boat) {
  Boat *this = boat;
  return this->topSpeed;
}

void Boat_move(void *boat) {
  puts("I am a Boat! I sail in the water.");
}

static BoatVtable boatVtable = {
  .offset = 0,
  .hashCode = Object_hashCode,
  .toString = Boat_toString,
  .getCapacity = Boat_getCapacity,
  .getTopSpeed = Boat_getTopSpeed,
  .move = Boat_move
};

void Boat_construct(void *boat, int capacity, int topSpeed) {
  Vehicle_construct(boat, capacity, topSpeed);
}

Boat *Boat_new(int capacity, int topSpeed) {
  puts("Creating Boat.");

  Boat *this = malloc(sizeof(Boat));
  this->vtable = &boatVtable;
  Boat_construct(this, capacity, topSpeed);

  return this;
}

void Boat_delete(Boat *boat) {
  puts("Deleting Boat.");
  free(boat);
}
