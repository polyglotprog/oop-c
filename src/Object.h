#ifndef OBJECT_H
#define OBJECT_H

#include <stdlib.h>

/* Class Object */
typedef struct Object Object;
typedef struct ObjectVtable ObjectVtable;

/* Methods */
void Object_construct(void *this);
Object *Object_new();
void Object_delete(Object *object);
unsigned long Object_hashCode(void *this);
char *Object_toString(void *this);

/* Vtable */
struct ObjectVtable {
  const size_t offset; // this is necessary to make dispatch uniform
  unsigned long (*hashCode)(void *this);
  char *(*toString)(void *this);
};

/* Data */
struct Object {
  const ObjectVtable *vtable;
};

#endif
