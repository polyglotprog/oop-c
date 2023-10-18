#ifndef CLONEABLE_H
#define CLONEABLE_H

#include <stdlib.h>

typedef struct Cloneable Cloneable;
typedef struct CloneableVtable CloneableVtable;

struct CloneableVtable {
  const size_t offset;
  void *(*clone)(void *this);
};

struct Cloneable {
  const CloneableVtable *vtable;
};

#endif
