#include "Animal.h"
#include "Bird.h"
// #include "FatPointer.h"
#include "dispatch.h"

int main() {
  Bird *bird = Bird_new();
  AnimalPointer animal = { bird, &birdAnimalImpl };
  animal.impl->speak(animal.instance); // dispatch using fat pointer
  dispatch(animal, speak);             // same as previous line
  return 0;
}
