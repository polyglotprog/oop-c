#ifndef NEW_H
#define NEW_H

#include <assert.h>
#include <stdlib.h>

/*
 * Instantiate class on the heap
 */
#define new(class, ...) \
    ({ \
      printf("Creating " #class ".\n"); \
      class *_instance_ = calloc(1, sizeof(class)); \
      _instance_->vtable = &class##_vtable; \
      class##_construct(_instance_, ## __VA_ARGS__); \
      (_instance_); \
    })

/*
 * Delete instance from the heap
 */
void delete(void *instance);

#endif
