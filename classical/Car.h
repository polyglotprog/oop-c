#ifndef CAR_H
#define CAR_H

#include <stdlib.h>
#include "Cloneable.h"

/* Class Car extends Vehicle */
typedef struct Car Car;
typedef struct CarVtable CarVtable;

/* Methods */
void Car_init(void *car, int capacity, int topSpeed, int numberOfWheels);
Car *Car_create(int capacity, int topSpeed, int numberOfWheels);
void Car_destroy(Car *car);
char *Car_toString(void *car);
int Car_getCapacity(void *car);
int Car_getTopSpeed(void *car);
int Car_getNumberOfWheels(void *car);
void *Car_clone(void *car);

/* Vtable */
struct CarVtable {
  size_t offset;
  /* Object Methods */
  unsigned long (*hashCode)(void *car);
  char *(*toString)(void *car);
  /* Vehicle Methods */
  int (*getCapacity)(void *car);
  int (*getTopSpeed)(void *car);
  void (*move)(void *car);
  int (*getNumberOfWheels)(void *car);
  /* Cloneable Implementation */
  size_t cloneableOffset;
  void *(*clone)(void *car);
};

/* Data */
struct Car {
  /* Vehicle Fields */
  CarVtable *vtable;
  int capacity;
  int topSpeed;
  /* Car Fields */
  int numberOfWheels;
  /* Cloneable Pointer */
  CloneableVtable *vtableCloneable;
};

#endif
