/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** check_file
*/

#include <stdlib.h>
#include <stdio.h>
#include "nm.h"

void check_magic(nm64_t *nm64)
{
    if (nm64->elf->e_ident[EI_MAG0] != ELFMAG0
    || nm64->elf->e_ident[EI_MAG1] != ELFMAG1
    || nm64->elf->e_ident[EI_MAG2] != ELFMAG2
    || nm64->elf->e_ident[EI_MAG3] != ELFMAG3) {
        dprintf(2, "nm: '%s': ELF header is incorrect\n", nm64->filename);
        exit(84);
    }
}

void check_is_supported(nm64_t *nm64)
{
    if (nm64->elf->e_ident[EI_CLASS] == ELFCLASS32) {
        dprintf(2, "nm: '%s': Unsupported architecture\n", nm64->filename);
        exit(84);
    }
}

void check_file(nm64_t *nm64)
{
    check_magic(nm64);
    check_is_supported(nm64);
}