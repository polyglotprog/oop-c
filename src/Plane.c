#include <stdio.h>
#include <stdlib.h>
#include "Plane.h"
#include "Object.h"
#include "Vehicle.h"

char *Plane_toString(void *plane) {
  Plane *this = plane;
  char* string = malloc(64);
  sprintf(string, "Plane[capacity=%d, topSpeed=%d]",
      this->capacity, this->topSpeed);
  return string;
}

int Plane_getCapacity(void *plane) {
  Plane *this = plane;
  return this->capacity;
}

int Plane_getTopSpeed(void *plane) {
  Plane *this = plane;
  return this->topSpeed;
}

void Plane_move(void *plane) {
  puts("I am a Plane! I fly in the air.");
}

static PlaneVtable planeVtable = {
  .offset = 0,
  .hashCode = Object_hashCode,
  .toString = Plane_toString,
  .getCapacity = Plane_getCapacity,
  .getTopSpeed = Plane_getTopSpeed,
  .move = Plane_move
};

void Plane_construct(void *plane, int capacity, int topSpeed) {
  Vehicle_construct(plane, capacity, topSpeed); // call superconstructor
  Plane *this = plane;
  this->capacity = capacity;
  this->topSpeed = topSpeed;
}

Plane *Plane_new(int capacity, int topSpeed) {
  puts("Creating Plane.");
  Plane *this = malloc(sizeof(Plane));
  this->vtable = &planeVtable;
  Plane_construct(this, capacity, topSpeed);
  return this;
}

void Plane_delete(Plane *plane) {
  puts("Deleting Plane.");
  free(plane);
}
