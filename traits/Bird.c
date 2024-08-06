#include <stdio.h>
#include "Bird.h"

void Bird_speak(void *bird) {
  Bird *this = bird;
  puts("Chirp!");
}

Animal birdAnimalImpl = {
  .speak = Bird_speak
};

Bird *Bird_new() {
  Bird *this = malloc(sizeof(Bird));
  return this;
}
