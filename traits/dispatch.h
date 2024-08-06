#ifndef DISPATCH_H
#define DISPATCH_H

#define dispatch(fatPointer, method, ...) \
  fatPointer.impl->method(fatPointer.instance, ## __VA_ARGS__)

#endif
