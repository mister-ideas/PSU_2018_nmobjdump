/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** init_data
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nm.h"

void init_data(nm64_t *nm64)
{
    nm64->sh = (Elf64_Shdr *)(nm64->data + nm64->elf->e_shoff);
    nm64->sh_str_tab = (char *)(nm64->data
    + nm64->sh[nm64->elf->e_shstrndx].sh_offset);
    for (int i = 0; i < nm64->elf->e_shnum; i++) {
        if (!strcmp(&nm64->sh_str_tab[nm64->sh[i].sh_name], ".strtab"))
            nm64->str_tab_sh = (Elf64_Shdr *)&nm64->sh[i];
        if (!strcmp(&nm64->sh_str_tab[nm64->sh[i].sh_name], ".symtab"))
            nm64->sym_tab_sh = (Elf64_Shdr *)&nm64->sh[i];
    }
    if (nm64->sym_tab_sh == SHN_UNDEF) {
        dprintf(2, "nm: %s: no symbols\n", nm64->filename);
        exit(84);
    }
    if (nm64->str_tab_sh == SHN_UNDEF) {
        dprintf(2, "nm: '%s': no strings table\n", nm64->filename);
        exit(84);
    }
}