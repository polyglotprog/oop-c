#include <stdlib.h>
#include "new.h"
#include "Object.h"

void delete(void *object) {
  Object *this = object;
  if (this && this->vtable && this->vtable->destruct) {
    this->vtable->destruct(this);
    free(this);
  }
}
