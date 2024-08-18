#ifndef CAR_H
#define CAR_H

#include <stdlib.h>
#include "Cloneable.h"

/* Class Car extends Vehicle */
typedef struct Car Car;
typedef struct CarVtable CarVtable;

/* Methods */
void Car_construct(void *this, int capacity, int topSpeed, int numberOfWheels);
void Car_destruct(void *this);
char *Car_toString(void *this);
void Car_move(void *this);
int Car_getNumberOfWheels(void *this);
void *Car_clone(void *this);

/* Vtable */
struct CarVtable {
  const size_t offset;
  void (*construct)(void *this, int capacity, int topSpeed, int numberOfWheels);
  void (*destruct)(void *this);
  /* Object Methods */
  unsigned long (*hashCode)(void *this);
  char *(*toString)(void *this);
  /* Vehicle Methods */
  int (*getCapacity)(void *this);
  int (*getTopSpeed)(void *this);
  void (*move)(void *this);
  /* Car Methods */
  int (*getNumberOfWheels)(void *this);
  /* Cloneable Vtable */
  const size_t offsetCloneable;
  void *(*clone)(void *this);
  /* Any number of additional interfaces could go here... */
};

extern const CarVtable Car_vtable;

/* Data */
struct Car {
  const CarVtable *vtable;
  /* Vehicle Fields */
  int capacity;
  int topSpeed;
  /* Car Fields */
  int numberOfWheels;
  /* Cloneable Vtable Pointer */
  CloneableVtable *vtableCloneable;
};

#endif
