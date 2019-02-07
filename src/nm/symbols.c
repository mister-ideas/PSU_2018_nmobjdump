/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** symbols
*/

#include <elf.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nm.h"

void symbols(nm64_t *nm64)
{
    char *str;
    int sym_nb;

    nm64->elf = (Elf64_Ehdr *)nm64->data;
    nm64->sh = (Elf64_Shdr *)(nm64->data + nm64->elf->e_shoff);
    str = (char *)(nm64->data + nm64->sh[nm64->elf->e_shstrndx].sh_offset);
    for (int i = 0; i < nm64->elf->e_shnum; i++) {
        if (!strcmp(&str[nm64->sh[i].sh_name], ".strtab"))
            nm64->str_tab_sh = (Elf64_Shdr *)&nm64->sh[i];
        if (!strcmp(&str[nm64->sh[i].sh_name], ".symtab"))
            nm64->sym_tab_sh = (Elf64_Shdr *)&nm64->sh[i];
    }
    if (nm64->sym_tab_sh == SHN_UNDEF) {
        dprintf(2, "nm: %s: no symbols\n", nm64->filename);
        exit(84);
    }
    sym_nb = nm64->sym_tab_sh->sh_size / nm64->sym_tab_sh->sh_entsize;
    nm64->sym_tab = (Elf64_Sym *)(nm64->data + nm64->sym_tab_sh->sh_offset);
    nm64->str_tab = (char *)(nm64->data + nm64->str_tab_sh->sh_offset);
    for (int i = 0; i < sym_nb; i++) {
        if (nm64->sym_tab[i].st_name != SHN_UNDEF)
            printf("%s\n", nm64->str_tab + nm64->sym_tab[i].st_name);
    }
}
