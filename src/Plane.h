#ifndef PLANE_H
#define PLANE_H

#include <stdlib.h>

/* Class Plane extends Vehicle */
typedef struct Plane Plane;
typedef struct PlaneVtable PlaneVtable;

/* Methods */
void Plane_construct(void *this, int capacity, int topSpeed);
Plane *Plane_new(int capacity, int topSpeed);
void Plane_delete(Plane *plane);
char *Plane_toString(void *this);
void Plane_move(void *this);

/* Vtable */
struct PlaneVtable {
  const size_t offset;
  /* Object Methods */
  unsigned long (*hashCode)(void *this);
  char *(*toString)(void *this);
  /* Vehicle Methods */
  int (*getCapacity)(void *this);
  int (*getTopSpeed)(void *this);
  void (*move)(void *this);
};

/* Data */
struct Plane {
  const PlaneVtable *vtable;
  /* Vehicle Fields */
  int capacity;
  int topSpeed;
};

#endif
