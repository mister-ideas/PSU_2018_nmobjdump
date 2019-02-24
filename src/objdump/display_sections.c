/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** display_sections
*/

#include <stdio.h>
#include "objdump.h"

void display_section(objdump64_t *objdump64)
{
    (void)objdump64;
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
