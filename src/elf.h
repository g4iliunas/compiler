#ifndef ELF_H
#define ELF_H

#include <stddef.h>
#include <stdint.h>

#define ELF_ABI_SYSTEMV 0x00
#define ELF_ABI_HPUX 0x01
#define ELF_ABI_NETBSD 0x02
#define ELF_ABI_LINUX 0x03
#define ELF_ABI_GNUHURD 0x04
#define ELF_ABI_SOLARIS 0x06
#define ELF_ABI_AIX 0x07
#define ELF_ABI_IRIX 0x08
#define ELF_ABI_FREEBSD 0x09
#define ELF_ABI_TRU64 0x0A
#define ELF_ABI_NOVELLMODESTO 0x0B
#define ELF_ABI_OPENBSD 0x0C
#define ELF_ABI_OPENVMS 0x0D
#define ELF_ABI_NONSTOPKERNEL 0x0E
#define ELF_ABI_AROS 0x0F
#define ELF_ABI_FENIXOS 0x10
#define ELF_ABI_NUXICLOUD 0x11
#define ELF_ABI_OPENVOS 0x12

#define ELF_TYPE_UNKNOWN 0x00
#define ELF_TYPE_REL 0x01
#define ELF_TYPE_EXEC 0x02
#define ELF_TYPE_SHARED 0x03
#define ELF_TYPE_CORE 0x04
#define ELF_TYPE_LOOS 0xFE00
#define ELF_TYPE_HIOS 0xFEFF
#define ELF_TYPE_LOPROC 0xFF00
#define ELF_TYPE_HIPROC 0xFFFF

#define ELF_MACHINE_NONE 0x00
#define ELF_MACHINE_ATT_WE32100 0x01
#define ELF_MACHINE_SPARC 0x02
#define ELF_MACHINE_X86 0x03
#define ELF_MACHINE_M68K 0x04
#define ELF_MACHINE_M88K 0x05
#define ELF_MACHINE_INTEL_MCU 0x06
#define ELF_MACHINE_INTEL_80860 0x07
#define ELF_MACHINE_MIPS 0x08
#define ELF_MACHINE_IBM_370 0x09
#define ELF_MACHINE_MIPS_RS3000_LE 0x0A
#define ELF_MACHINE_RESERVED_0B 0x0B
#define ELF_MACHINE_RESERVED_0C 0x0C
#define ELF_MACHINE_RESERVED_0D 0x0D
#define ELF_MACHINE_RESERVED_0E 0x0E
#define ELF_MACHINE_PA_RISC 0x0F
#define ELF_MACHINE_INTEL_80960 0x13
#define ELF_MACHINE_POWERPC 0x14
#define ELF_MACHINE_POWERPC_64 0x15
#define ELF_MACHINE_S390 0x16
#define ELF_MACHINE_IBM_SPU 0x17
#define ELF_MACHINE_RESERVED_18 0x18
#define ELF_MACHINE_RESERVED_19 0x19
#define ELF_MACHINE_RESERVED_1A 0x1A
#define ELF_MACHINE_RESERVED_1B 0x1B
#define ELF_MACHINE_RESERVED_1C 0x1C
#define ELF_MACHINE_RESERVED_1D 0x1D
#define ELF_MACHINE_RESERVED_1E 0x1E
#define ELF_MACHINE_RESERVED_1F 0x1F
#define ELF_MACHINE_V800 0x24
#define ELF_MACHINE_FR20 0x25
#define ELF_MACHINE_RH32 0x26
#define ELF_MACHINE_RCE 0x27
#define ELF_MACHINE_ARM 0x28
#define ELF_MACHINE_ALPHA 0x29
#define ELF_MACHINE_SUPERH 0x2A
#define ELF_MACHINE_SPARC_V9 0x2B
#define ELF_MACHINE_TRICORE 0x2C
#define ELF_MACHINE_ARGON_RISC 0x2D
#define ELF_MACHINE_H8_300 0x2E
#define ELF_MACHINE_H8_300H 0x2F
#define ELF_MACHINE_H8S 0x30
#define ELF_MACHINE_H8_500 0x31
#define ELF_MACHINE_IA_64 0x32
#define ELF_MACHINE_MIPS_X 0x33
#define ELF_MACHINE_COLDFIRE 0x34
#define ELF_MACHINE_M68HC12 0x35
#define ELF_MACHINE_FUJITSU_MMA 0x36
#define ELF_MACHINE_PCP 0x37
#define ELF_MACHINE_NCPU 0x38
#define ELF_MACHINE_NDR1 0x39
#define ELF_MACHINE_STARCORE 0x3A
#define ELF_MACHINE_ME16 0x3B
#define ELF_MACHINE_ST100 0x3C
#define ELF_MACHINE_TINYJ 0x3D
#define ELF_MACHINE_X86_64 0x3E
#define ELF_MACHINE_DSP 0x3F
#define ELF_MACHINE_PDP10 0x40
#define ELF_MACHINE_PDP11 0x41
#define ELF_MACHINE_FX66 0x42
#define ELF_MACHINE_ST9_PLUS 0x43
#define ELF_MACHINE_ST7 0x44
#define ELF_MACHINE_MC68HC16 0x45
#define ELF_MACHINE_MC68HC11 0x46
#define ELF_MACHINE_MC68HC08 0x47
#define ELF_MACHINE_MC68HC05 0x48
#define ELF_MACHINE_SVX 0x49
#define ELF_MACHINE_ST19 0x4A
#define ELF_MACHINE_VAX 0x4B
#define ELF_MACHINE_AXIS_32 0x4C
#define ELF_MACHINE_INFINEON 0x4D
#define ELF_MACHINE_ELEMENT14 0x4E
#define ELF_MACHINE_LSI_16_DSP 0x4F
#define ELF_MACHINE_TMS320C6000 0x8C
#define ELF_MACHINE_ELBRUS_E2K 0xAF
#define ELF_MACHINE_ARM_64 0xB7
#define ELF_MACHINE_Z80 0xDC
#define ELF_MACHINE_RISCV 0xF3
#define ELF_MACHINE_BPF 0xF7
#define ELF_MACHINE_WDC_65C816 0x101
#define ELF_MACHINE_LOONGARCH 0x102

#define ELF_PTYPE_NULL 0x00000000
#define ELF_PTYPE_LOAD 0x00000001
#define ELF_PTYPE_DYNAMIC 0x00000002
#define ELF_PTYPE_INTERP 0x00000003
#define ELF_PTYPE_NOTE 0x00000004
#define ELF_PTYPE_SHLIB 0x00000005
#define ELF_PTYPE_PHDR 0x00000006
#define ELF_PTYPE_TLS 0x00000007
#define ELF_PTYPE_LOOS 0x60000000
#define ELF_PTYPE_HIOS 0x6FFFFFFF
#define ELF_PTYPE_LOPROC 0x70000000

#define ELF_SEGMENT_EXEC 0x1
#define ELF_SEGMENT_WRITE 0x2
#define ELF_SEGMENT_READ 0x4

#define ELF_SHTYPE_NULL 0x0
#define ELF_SHTYPE_PROGBITS 0x1
#define ELF_SHTYPE_SYMTAB 0x2
#define ELF_SHTYPE_STRTAB 0x3
#define ELF_SHTYPE_RELA 0x4
#define ELF_SHTYPE_HASH 0x5
#define ELF_SHTYPE_DYNAMIC 0x6
#define ELF_SHTYPE_NOTE 0x7
#define ELF_SHTYPE_NOBITS 0x8
#define ELF_SHTYPE_REL 0x9
#define ELF_SHTYPE_SHLIB 0xA
#define ELF_SHTYPE_DYNSYM 0xB
#define ELF_SHTYPE_INIT_ARRAY 0xE
#define ELF_SHTYPE_FINI_ARRAY 0xF
#define ELF_SHTYPE_PREINIT_ARRAY 0x10
#define ELF_SHTYPE_GROUP 0x11
#define ELF_SHTYPE_SYMTAB_SHNDX 0x12
#define ELF_SHTYPE_NUM 0x13
#define ELF_SHTYPE_LOOS 0x60000000

#define ELF_SHFLAG_WRITE 0x1
#define ELF_SHFLAG_ALLOC 0x2
#define ELF_SHFLAG_EXECINSTR 0x4
#define ELF_SHFLAG_MERGE 0x10
#define ELF_SHFLAG_STRINGS 0x20
#define ELF_SHFLAG_INFO_LINK 0x40
#define ELF_SHFLAG_LINK_ORDER 0x80
#define ELF_SHFLAG_OS_NONCONFORMING 0x100
#define ELF_SHFLAG_GROUP 0x200
#define ELF_SHFLAG_TLS 0x400
#define ELF_SHFLAG_MASKOS 0x0FF00000
#define ELF_SHFLAG_MASKPROC 0xF0000000
#define ELF_SHFLAG_ORDERED 0x4000000
#define ELF_SHFLAG_EXCLUDE 0x8000000

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

struct __attribute__((packed)) elf_program_header32 {
    uint32_t type;
    uint32_t offset;
    uint32_t vaddr;
    uint32_t paddr;
    uint32_t filesz;
    uint32_t memsz;
    uint32_t flags;
    uint32_t align;
};

struct __attribute__((packed)) elf_program_header64 {
    uint32_t type;
    uint32_t flags;
    uint64_t offset;
    uint64_t vaddr;
    uint64_t paddr;
    uint64_t filesz;
    uint64_t memsz;
    uint64_t align;
};

struct __attribute__((packed)) elf_section_header32 {
    uint32_t name;
    uint32_t type;
    uint32_t flags;
    uint32_t addr;
    uint32_t offset;
    uint32_t size;
    uint32_t link;
    uint32_t info;
    uint32_t addralign;
    uint32_t entsize;
};

struct __attribute__((packed)) elf_section_header64 {
    uint32_t name;
    uint32_t type;
    uint64_t flags;
    uint64_t addr;
    uint64_t offset;
    uint64_t size;
    uint32_t link;
    uint32_t info;
    uint64_t addralign;
    uint64_t entsize;
};

#endif // ELF_H