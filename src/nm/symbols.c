/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** symbols
*/

#include <stdio.h>
#include "nm.h"

void display_symbols(nm64_t *nm64)
{
    int sym_nb;

    sym_nb = nm64->sym_tab_sh->sh_size / nm64->sym_tab_sh->sh_entsize;
    nm64->sym_tab = (Elf64_Sym *)(nm64->data + nm64->sym_tab_sh->sh_offset);
    nm64->str_tab = (char *)(nm64->data + nm64->str_tab_sh->sh_offset);
    for (int i = 0; i < sym_nb; i++) {
        if (nm64->sym_tab[i].st_name != SHN_UNDEF
        && ELF64_ST_TYPE(nm64->sym_tab[i].st_info) != STT_FILE)
            printf("%016x - %s\n", (unsigned)nm64->sym_tab[i].st_value,
            nm64->str_tab + nm64->sym_tab[i].st_name);
    }
}
