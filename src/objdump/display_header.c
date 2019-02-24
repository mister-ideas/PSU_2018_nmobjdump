/*
** EPITECH PROJECT, 2019
** PSU_2018_objdump
** File description:
** display
*/

#include <stdio.h>
#include "objdump.h"

const char *get_flags(objdump64_t *objdump64)
{
    switch (objdump64->elf->e_type)
    {
        case ET_REL:
            return ("0x00000011:\nHAS_RELOC, HAS_SYMS\n");
            break;
        case ET_EXEC:
            return ("0x00000112:\nEXEC_P, HAS_SYMS, D_PAGED\n");
            break;
        case ET_DYN:
            return ("0x00000150:\nHAS_SYMS, DYNAMIC, D_PAGED\n");
        default:
            break;
    }
    return ("");
}

void display_header(objdump64_t *objdump64)
{
    printf("\n%s:     file format elf64-x86-64\n", objdump64->filename);
    printf("architecture: i386:x86-64, flags %s", get_flags(objdump64));
    printf("start address 0x%016lx\n\n", objdump64->elf->e_entry);
    return;
}
