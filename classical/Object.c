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

Object *Object_create() {
  puts("Creating Object.");
  Object *this = malloc(sizeof(Object));
  this->vtable = &objectVtable;
  return this;
}

void Object_destroy(Object *object) {
  puts("Destroying Object.");
  free(object);
}
