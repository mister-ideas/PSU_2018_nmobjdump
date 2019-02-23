/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** check_file
*/

#include <stdlib.h>
#include <stdio.h>
#include "nm.h"

void check_elf(nm64_t *nm64)
{
    if ((nm64->elf->e_type != ET_REL
    && nm64->elf->e_type != ET_EXEC
    && nm64->elf->e_type != ET_DYN)
    || (nm64->elf->e_ident[EI_MAG0] != ELFMAG0
    || nm64->elf->e_ident[EI_MAG1] != ELFMAG1
    || nm64->elf->e_ident[EI_MAG2] != ELFMAG2
    || nm64->elf->e_ident[EI_MAG3] != ELFMAG3)) {
        dprintf(2, "nm: %s: File format not recognized\n", nm64->filename);
        exit(84);
    }
}

void check_architecture(nm64_t *nm64)
{
    if (nm64->elf->e_ident[EI_CLASS] == ELFCLASS32) {
        dprintf(2, "nm: '%s': Unsupported architecture\n", nm64->filename);
        exit(84);
    }
}

void check_file(nm64_t *nm64)
{
    nm64->elf = (Elf64_Ehdr *)nm64->data;
    if (!nm64->elf) {
        dprintf(2, "nm: %s: no ELF header\n", nm64->filename);
        exit(84);
    }
    check_architecture(nm64);
    check_elf(nm64);
}