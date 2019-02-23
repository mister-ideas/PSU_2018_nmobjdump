/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** types
*/

#include <string.h>
#include "nm.h"

char get_sym_type_special(Elf64_Sym sym)
{
    if (ELF64_ST_BIND(sym.st_info) == STB_WEAK) {
        return (!sym.st_value ?
        ELF64_ST_TYPE(sym.st_info) == STT_OBJECT ? 'v' : 'w' :
        ELF64_ST_TYPE(sym.st_info) == STT_OBJECT ? 'V' : 'W');
    }
    if (ELF64_ST_BIND(sym.st_info) == STB_GNU_UNIQUE)
        return('u');
    if (sym.st_shndx == SHN_COMMON)
        return('C');
    if (sym.st_shndx == SHN_ABS)
        return('A');
    if (sym.st_shndx == SHN_UNDEF)
        return('U');
    return (' ');
}

char get_sym_type(nm64_t *nm64, Elf64_Sym sym)
{
    char type = get_sym_type_special(sym);

    if (type != ' ')
        return (type);
    if (nm64->sh[sym.st_shndx].sh_type == SHT_NOBITS
    && nm64->sh[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        return (ELF64_ST_BIND(sym.st_info) == STB_LOCAL ? 'b' : 'B');
    if (nm64->sh[sym.st_shndx].sh_type == SHT_INIT_ARRAY
    || nm64->sh[sym.st_shndx].sh_type == SHT_FINI_ARRAY
    || (nm64->sh[sym.st_shndx].sh_type == SHT_PROGBITS
    && nm64->sh[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR)))
        return (ELF64_ST_BIND(sym.st_info) == STB_LOCAL ? 't' : 'T');
    if (nm64->sh[sym.st_shndx].sh_type == SHT_PROGBITS
    && (nm64->sh[sym.st_shndx].sh_flags == (SHF_MERGE | SHF_ALLOC)
    || nm64->sh[sym.st_shndx].sh_flags == SHF_ALLOC))
        return (ELF64_ST_BIND(sym.st_info) == STB_LOCAL ? 'r' : 'R');
    if (nm64->sh[sym.st_shndx].sh_type == SHT_DYNAMIC
    || (nm64->sh[sym.st_shndx].sh_type == SHT_PROGBITS
    && nm64->sh[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE)))
        return (ELF64_ST_BIND(sym.st_info) == STB_LOCAL ? 'd' : 'D');
    return (' ');
}
