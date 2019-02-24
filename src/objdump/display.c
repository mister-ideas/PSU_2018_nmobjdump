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

void display_sections(objdump64_t *objdump64)
{
    for (int i = 0; i < objdump64->elf->e_shnum; i++) {
        if (!objdump64->sh_str_tab[objdump64->sh[i].sh_name]
        || objdump64->sh[i].sh_type == SHT_SYMTAB
        || objdump64->sh[i].sh_type == SHT_NOBITS
        || objdump64->sh[i].sh_type == SHT_STRTAB
        || objdump64->data
        + objdump64->sh[i].sh_offset == objdump64->sh_str_tab)
            continue;
        printf("Contents of section %s:\n",
        &(objdump64->sh_str_tab)[objdump64->sh[i].sh_name]);
    }
    return;
}

void display(objdump64_t *objdump64)
{
    display_header(objdump64);
    display_sections(objdump64);
}
