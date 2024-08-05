#include <stdio.h>
#include <stdlib.h>
#include "Object.h"

unsigned long Object_hashCode(void *object) {
  return (unsigned long)object;
}

char *Object_toString(void *object) {
  char *string = malloc(7 + sizeof(void *));
  sprintf(string, "Object@%p", object);
  return string;
}

static ObjectVtable objectVtable = {
  .offset = 0,
  .hashCode = Object_hashCode,
  .toString = Object_toString
};

void Object_construct(void *object) {
}

Object *Object_new() {
  puts("Creating new Object.");
  Object *this = malloc(sizeof(Object));
  this->vtable = &objectVtable;
  return this;
}

void Object_delete(Object *object) {
  puts("Deleting Object.");
  free(object);
}
