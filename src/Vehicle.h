#ifndef VEHICLE_H
#define VEHICLE_H
#include <stdlib.h>

/* Abstract Class Vehicle extends Object */
typedef struct Vehicle Vehicle;
typedef struct VehicleVtable VehicleVtable;

/* Methods */
void Vehicle_construct(void *vehicle, int capacity, int topSpeed);
// No `new` or `delete` methods because this is an *abstract* class.
// Technically, you *could* create an instance if you wanted to.
int Vehicle_getCapacity(void *vehicle);
int Vehicle_getTopSpeed(void *vehicle);

/* Vtable */
struct VehicleVtable {
  size_t offset;
  /* Object Methods */
  unsigned long (*hashCode)(void *object);
  char *(*toString)(void *object);
  /* Vehicle Methods */
  int (*getCapacity)(void *vehicle);
  int (*getTopSpeed)(void *vehicle);
  void (*move)(void *vehicle); // abstract
};

/* Data */
struct Vehicle {
  VehicleVtable *vtable;
  int capacity;
  int topSpeed;
};

#endif
