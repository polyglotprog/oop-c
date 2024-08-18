#ifndef OBJECT_H
#define OBJECT_H

#include <stdlib.h>

/* Class Object */
typedef struct Object Object;
typedef struct ObjectVtable ObjectVtable;

/* Methods */
void Object_construct(void *this);
void Object_destruct(void *this);
unsigned long Object_hashCode(void *this);
char *Object_toString(void *this);

/* Vtable */
struct ObjectVtable {
  const size_t offset; // this is necessary to make dispatch uniform
  void (*construct)(void *this);
  void (*destruct)(void *this);
  unsigned long (*hashCode)(void *this);
  char *(*toString)(void *this);
};

extern const ObjectVtable Object_vtable;

/* Data */
struct Object {
  const ObjectVtable *vtable;
};

#endif
