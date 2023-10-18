#ifndef PLANE_H
#define PLANE_H

#include <stdlib.h>

/* Class Plane extends Vehicle */
typedef struct Plane Plane;
typedef struct PlaneVtable PlaneVtable;

/* Methods */
void Plane_init(void *plane, int capacity, int topSpeed);
Plane *Plane_create(int capacity, int topSpeed);
void Plane_destroy(Plane *plane);
char *Plane_toString(void *plane);
int Plane_getCapacity(void *plane);
int Plane_getTopSpeed(void *plane);

/* Vtable */
struct PlaneVtable {
  size_t offset;
  /* Object Methods */
  unsigned long (*hashCode)(void *plane);
  char *(*toString)(void *plane);
  /* Vehicle Methods */
  int (*getCapacity)(void *plane);
  int (*getTopSpeed)(void *plane);
  void (*move)(void *plane);
};

/* Data */
struct Plane {
  /* Vehicle Fields */
  PlaneVtable *vtable;
  int capacity;
  int topSpeed;
};

#endif
