#ifndef PRIVATE_H
#define PRIVATE_H

/*
 * Helper macro to make "private" data
 */
typedef unsigned char byte;
#define private(data) byte _private_[(sizeof(data))]

#endif
