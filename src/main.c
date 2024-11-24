#include "elf.h"
#include <stdio.h>

void hexdump(uint8_t *buf, size_t len)
{
    fprintf(stdout, "=== HEXDUMP ===\n");
    fprintf(stdout, "Size: %lu\n", len);
    for (size_t i = 0; i < len; i++) {
        fprintf(stdout, "%02x ", buf[i]);
    }
    fprintf(stdout, "\n======\n");
}

int main(void)
{
    size_t len;
    uint8_t *elf_bytes = read_elf("main.o", &len);
    if (!elf_bytes) {
        fprintf(stderr, "Failed to read the ELF file\n");
        return 1;
    }

    hexdump(elf_bytes, len);
    return 0;
}