#ifndef ANIMAL_H
#define ANIMAL_H

#include <stdlib.h>

typedef struct Animal Animal;
typedef struct AnimalPointer AnimalPointer;

struct Animal {
  void (*speak)(void *animal);
};

// Fat pointer including instance and Animal implementation
struct AnimalPointer {
  void *instance;
  Animal *impl;
};

#endif
