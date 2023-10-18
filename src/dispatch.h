#ifndef DISPATCH_H
#define DISPATCH_H

/*
 * Dynamicall dispatch a method on an instance. This works on both *instance*
 * and *interface* pointers because every vtable begins with an offset field.
 */
#define dispatch(instance, method, ...) \
  instance->vtable->method((void *)instance - instance->vtable->offset, \
      ## __VA_ARGS__)

/*
 * Convert an *instance* pointer to an *interface* pointer
 */
#define toInterface(interface, instance) \
  (interface *)(&instance->vtable##interface)

/*
 * Convert an *interface* pointer to an *instance* pointer
 */
#define toInstance(interface) \
  ((void *)interface - interface->vtable->offset)

#endif
