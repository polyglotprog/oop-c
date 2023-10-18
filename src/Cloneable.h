#ifndef CLONEABLE_H
#define CLONEABLE_H

#include <stdlib.h>

typedef struct Cloneable Cloneable;
typedef struct CloneableVtable CloneableVtable;

struct CloneableVtable {
  size_t offset;
  void *(*clone)(void *cloneable);
};

struct Cloneable {
  CloneableVtable *vtable;
};

#endif
