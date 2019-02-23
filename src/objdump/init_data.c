/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** init_data
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "objdump.h"

void init_data(objdump64_t *objdump64)
{
    objdump64->sh = (Elf64_Shdr *)(objdump64->data + objdump64->elf->e_shoff);
    objdump64->sh_str_tab = (char *)(objdump64->data
    + objdump64->sh[objdump64->elf->e_shstrndx].sh_offset);
    for (int i = 0; i < objdump64->elf->e_shnum; i++) {
        if (!strcmp(&objdump64->sh_str_tab[objdump64->sh[i].sh_name], ".strtab"))
            objdump64->str_tab_sh = (Elf64_Shdr *)&objdump64->sh[i];
    }
    if (objdump64->str_tab_sh != SHN_UNDEF) {
        objdump64->str_tab = (char *)(objdump64->data
        + objdump64->str_tab_sh->sh_offset);
    }
}