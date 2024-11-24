#include "elf.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t len;
    uint8_t *elf_bytes = read_file("main.o", &len);
    if (!elf_bytes) {
        fprintf(stderr, "Failed to read the ELF file\n");
        return 1;
    }

    hexdump(elf_bytes, len);
    elfdump(elf_bytes);

    free(elf_bytes);
    return 0;
}