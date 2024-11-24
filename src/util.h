#ifndef UTIL_H
#define UTIL_H

#include <stddef.h>
#include <stdint.h>

#define READ_CHUNK 1024

uint8_t *read_file(const char *path, size_t *len);

#endif // UTIL_H