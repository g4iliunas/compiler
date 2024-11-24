#ifndef ELF_H
#define ELF_H

#include <stddef.h>
#include <stdint.h>

#define READ_CHUNK 1024

struct __attribute__((packed)) e_ident {
    uint8_t magic[4];
    uint8_t arch;
    uint8_t data;
    uint8_t elf_version;
    uint8_t abi;
    uint8_t abi_version;
    uint8_t pad[7];
};

struct __attribute__((packed)) elf_header_common0 {
    struct e_ident ident;
    uint16_t type;
    uint16_t machine;
    uint32_t elf_version;
};

struct __attribute__((packed)) elf_header_common1 {
    uint32_t flags;
    uint16_t ehsize;
    uint16_t phentsize;
    uint16_t phnum;
    uint16_t shentsize;
    uint16_t shnum;
    uint16_t shstrndx;
};

struct __attribute__((packed)) elf_header32 {
    struct elf_header_common0 common0;
    uint32_t entry_addr;
    uint32_t phoff;
    uint32_t shoff;
    struct elf_header_common1 common1;
};

struct __attribute__((packed)) elf_header64 {
    struct elf_header_common0 common0;
    uint64_t entry_addr;
    uint64_t phoff;
    uint64_t shoff;
    struct elf_header_common1 common1;
};

uint8_t *read_elf(const char *path, size_t *len);

#endif // ELF_H