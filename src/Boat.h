#ifndef BOAT_H
#define BOAT_H

#include <stdlib.h>

/* Class Boat extends Vehicle */
typedef struct Boat Boat;
typedef struct BoatVtable BoatVtable;

/* Methods */
void Boat_construct(void *boat, int capacity, int topSpeed);
Boat *Boat_new(int capacity, int topSpeed);
void Boat_delete(Boat *boat);
char *Boat_toString(void *boat);
int Boat_getCapacity(void *boat);
int Boat_getTopSpeed(void *boat);

/* Vtable */
struct BoatVtable {
  size_t offset;
  /* Object Methods */
  unsigned long (*hashCode)(void *boat);
  char *(*toString)(void *boat);
  /* Vehicle Methods */
  int (*getCapacity)(void *boat);
  int (*getTopSpeed)(void *boat);
  void (*move)(void *boat);
};

/* Data */
struct Boat {
  /* Vehicle Fields */
  BoatVtable *vtable;
  int capacity;
  int topSpeed;
};

#endif
