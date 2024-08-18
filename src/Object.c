#include <stdio.h>
#include <stdlib.h>
#include "Object.h"

const ObjectVtable Object_vtable = {
  .offset = 0,
  .construct = Object_construct,
  .destruct = Object_destruct,
  .hashCode = Object_hashCode,
  .toString = Object_toString,
};

void Object_construct(void *_this_) {
}

void Object_destruct(void *_this_) {
  puts("Deleting Object.");
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
