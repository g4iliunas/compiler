#include "elf.h"
#include <stdio.h>
#include <stdlib.h>

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

    if (((struct e_ident *)elf_bytes)->arch == 1) {
        fprintf(stdout, "ELF file is 32bit\n");
        struct elf_header32 *h32 = (struct elf_header32 *)elf_bytes;

        fprintf(stdout, "Entry offset: 0x%x\n", h32->entry_addr);
        fprintf(stdout, "Program header table offset: 0x%x\n", h32->phoff);
        fprintf(stdout, "Section header table offset: 0x%x\n", h32->shoff);
    }
    else if (((struct e_ident *)elf_bytes)->arch == 2) {
        fprintf(stdout, "ELF file is 64bit\n");
        struct elf_header64 *h64 = (struct elf_header64 *)elf_bytes;
    }

    free(elf_bytes);
    return 0;
}