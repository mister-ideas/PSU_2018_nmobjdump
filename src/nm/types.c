/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** types
*/

#include <string.h>
#include "nm.h"

int check_sym_section(nm64_t *nm64, Elf64_Sym sym, const char *section)
{
    if (!strcmp(&nm64->sh_str_tab[nm64->sh[sym.st_shndx].sh_name], section))
        return (1);
    return (0);
}

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
    if (check_sym_section(nm64, sym, ".bss"))
        return (ELF64_ST_BIND(sym.st_info) == STB_LOCAL ? 'b' : 'B');
    if (check_sym_section(nm64, sym, ".text")
    || ELF64_ST_TYPE(sym.st_info) == STT_FUNC)
        return (ELF64_ST_BIND(sym.st_info) == STB_LOCAL ? 't' : 'T');
    if (check_sym_section(nm64, sym, ".rodata"))
        return (ELF64_ST_BIND(sym.st_info) == STB_LOCAL ? 'r' : 'R');
    if (check_sym_section(nm64, sym, ".data")
    || ELF64_ST_TYPE(sym.st_info) == STT_NOTYPE
    || ELF64_ST_TYPE(sym.st_info) == STT_OBJECT)
        return (ELF64_ST_BIND(sym.st_info) == STB_LOCAL ? 'd' : 'D');
    return (' ');
}
