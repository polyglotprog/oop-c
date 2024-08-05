#ifndef OBJECT_H
#define OBJECT_H

#include <stdlib.h>

/* Class Object */
typedef struct Object Object;
typedef struct ObjectVtable ObjectVtable;

/* Methods */
void Object_construct(void *object);
Object *Object_new();
void Object_delete(Object *object);
unsigned long Object_hashCode(void *object);
char *Object_toString(void *object);

/* Vtable */
struct ObjectVtable {
  size_t offset; // this is necessary to make dispatch uniform
  unsigned long (*hashCode)(void *object);
  char *(*toString)(void *object);
};

/* Data */
struct Object {
  ObjectVtable *vtable;
};

#endif
