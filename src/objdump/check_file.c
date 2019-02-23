/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** check_file
*/

#include <stdlib.h>
#include <stdio.h>
#include "objdump.h"

void check_elf(objdump64_t *objdump64)
{
    if ((objdump64->elf->e_type != ET_REL
    && objdump64->elf->e_type != ET_EXEC
    && objdump64->elf->e_type != ET_DYN)
    || (objdump64->elf->e_ident[EI_MAG0] != ELFMAG0
    || objdump64->elf->e_ident[EI_MAG1] != ELFMAG1
    || objdump64->elf->e_ident[EI_MAG2] != ELFMAG2
    || objdump64->elf->e_ident[EI_MAG3] != ELFMAG3)) {
        dprintf(2, "objdump: %s: File format not recognized\n", objdump64->filename);
        exit(84);
    }
}

void check_architecture(objdump64_t *objdump64)
{
    if (objdump64->elf->e_ident[EI_CLASS] == ELFCLASS32) {
        dprintf(2, "objdump: '%s': Unsupported architecture\n", objdump64->filename);
        exit(84);
    }
}

void check_file(objdump64_t *objdump64)
{
    objdump64->elf = (Elf64_Ehdr *)objdump64->data;
    if (!objdump64->elf) {
        dprintf(2, "objdump: %s: no ELF header\n", objdump64->filename);
        exit(84);
    }
    check_architecture(objdump64);
    check_elf(objdump64);
}