#ifndef ENCAPSULATION_H
#define ENCAPSULATION_H

#include <stdlib.h>

typedef uint8_t byte;

#define private(fields) byte[sizeof(fields)] data;

#endif
