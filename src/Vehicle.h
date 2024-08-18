#ifndef VEHICLE_H
#define VEHICLE_H

#include <stdlib.h>

/* Abstract Class Vehicle extends Object */
typedef struct Vehicle Vehicle;
typedef struct VehicleVtable VehicleVtable;

/* Methods */
void Vehicle_construct(void *this, int capacity, int topSpeed);
// No `destruct` method because this is an *abstract* class.
// Technically, you *could* create an instance if you wanted to.
int Vehicle_getCapacity(void *this);
int Vehicle_getTopSpeed(void *this);

/* Vtable */
struct VehicleVtable {
  const size_t offset;
  void (*construct)(void *this, int capacity, int topSpeed);
  void (*destruct)(void *this);
  /* Object Methods */
  unsigned long (*hashCode)(void *this);
  char *(*toString)(void *this);
  /* Vehicle Methods */
  int (*getCapacity)(void *this);
  int (*getTopSpeed)(void *this);
  void (*move)(void *this); // abstract
};

/* No constant vtable since this class is abstract */

/* Data */
struct Vehicle {
  const VehicleVtable *vtable;
  int capacity;
  int topSpeed;
};

#endif
