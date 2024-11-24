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

void elfdump(uint8_t *elf_bytes)
{
    if (((struct e_ident *)elf_bytes)->arch == 1) {
        fprintf(stdout, "ELF file is 32bit\n");
        struct elf_header32 *h32 = (struct elf_header32 *)elf_bytes;

        fprintf(stdout, "Entry offset: 0x%x\n", h32->entry_addr);
        fprintf(stdout, "Program header table offset: 0x%x\n", h32->phoff);
        fprintf(stdout, "Section header table offset: 0x%x\n", h32->shoff);
        fprintf(stdout, "Program table entries: %d\n", h32->common1.phnum);
        fprintf(stdout, "Section table entries: %d\n", h32->common1.shnum);

        struct elf_section_header32 *shstrtab =
            (struct elf_section_header32 *)(elf_bytes + h32->shoff +
                                            h32->common1.shentsize *
                                                h32->common1.shstrndx);

        for (int i = 0; i < h32->common1.shnum; i++) {
            struct elf_section_header32 *sh32 =
                (struct elf_section_header32 *)(elf_bytes + h32->shoff +
                                                h32->common1.shentsize * i);

            if (sh32->type != 0) {
                const char *section_name =
                    (char *)(elf_bytes + shstrtab->offset + sh32->name);
                void *section_data = sh32 + sh32->offset;

                fprintf(stdout,
                        "Section name: %s, section data is located at %p\n",
                        section_name, section_data);
            }
        }
    }
    else if (((struct e_ident *)elf_bytes)->arch == 2) {
        fprintf(stdout, "=== ELFDUMP ===\n");
        fprintf(stdout, "ELF file is 64bit\n");
        struct elf_header64 *h64 = (struct elf_header64 *)elf_bytes;

        fprintf(stdout, "Entry offset: 0x%lx\n", h64->entry_addr);
        fprintf(stdout, "Program header table offset: 0x%lx\n", h64->phoff);
        fprintf(stdout, "Section header table offset: 0x%lx\n", h64->shoff);

        fprintf(stdout, "Program table entries: %d\n", h64->common1.phnum);
        fprintf(stdout, "Section table entries: %d\n", h64->common1.shnum);

        struct elf_section_header64 *shstrtab =
            (struct elf_section_header64 *)(elf_bytes + h64->shoff +
                                            h64->common1.shentsize *
                                                h64->common1.shstrndx);

        for (int i = 0; i < h64->common1.shnum; i++) {
            struct elf_section_header64 *sh64 =
                (struct elf_section_header64 *)(elf_bytes + h64->shoff +
                                                h64->common1.shentsize * i);

            if (sh64->type != 0) {
                const char *section_name =
                    (char *)(elf_bytes + shstrtab->offset + sh64->name);
                void *section_data = sh64 + sh64->offset;

                fprintf(stdout,
                        "Section name: %s, section data is located at %p\n",
                        section_name, section_data);
            }
        }
    }
    fprintf(stdout, "======\n");
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
    elfdump(elf_bytes);

    free(elf_bytes);
    return 0;
}