#include <stdio.h>
#include <stdlib.h>
#include "Object.h"

static ObjectVtable objectVtable = {
  .offset = 0,
  .hashCode = Object_hashCode,
  .toString = Object_toString,
};

void Object_construct(void *_this_) {
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

unsigned long Object_hashCode(void *_this_) {
  Object *this = _this_;
  return (unsigned long)this;
}

char *Object_toString(void *_this_) {
  Object *this = _this_;
  char *string = malloc(7 + sizeof(void *));
  sprintf(string, "Object@%p", this);
  return string;
}
