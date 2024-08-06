#ifndef FAT_POINTER_H
#define FAT_POINTER_H

typedef struct FatPointer FatPointer;

struct FatPointer {
  void *instance;
  void *impl;
};

#endif
