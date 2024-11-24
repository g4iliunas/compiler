#ifndef ELF_H
#define ELF_H

#include <stddef.h>
#include <stdint.h>

#define READ_CHUNK 1024

uint8_t *read_elf(const char *path, size_t *len);

#endif // ELF_H