#ifndef BOAT_H
#define BOAT_H

#include <stdlib.h>

/* Class Boat extends Vehicle */
typedef struct Boat Boat;
typedef struct BoatVtable BoatVtable;

/* Methods */
void Boat_construct(void *this, int capacity, int topSpeed);
void Boat_destruct(void *this);
char *Boat_toString(void *this);
void Boat_move(void *this);

/* Vtable */
struct BoatVtable {
  const size_t offset;
  void (*construct)(void *this, int capacity, int topSpeed);
  void (*destruct)(void *this);
  /* Object Methods */
  unsigned long (*hashCode)(void *this);
  char *(*toString)(void *this);
  /* Vehicle Methods */
  int (*getCapacity)(void *this);
  int (*getTopSpeed)(void *this);
  void (*move)(void *this);
};

extern const BoatVtable Boat_vtable;

/* Data */
struct Boat {
  const BoatVtable *vtable;
  /* Vehicle Fields */
  int capacity;
  int topSpeed;
};

#endif
