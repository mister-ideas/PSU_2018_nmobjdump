/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** symbols
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "nm.h"

char *convert_str(char *str)
{
    int j = 0;

    char *new_str = malloc(sizeof(char) * (strlen(str) + 1));
    if (!new_str)
        exit(84);
    for (int i = 0; str[i]; i++) {
        if (str[i] == '_' || str[i] == '.')
            continue;
        else {
            new_str[j] = tolower(str[i]);
            j++;
        }
    }
    new_str[j] = '\0';
    return (new_str);
}

void compare_sym(nm64_t *nm64, int i, int j)
{
    Elf64_Sym temp;
    char *str1 = convert_str(nm64->str_tab + nm64->sorted_sym_tab[i].st_name);
    char *str2 = convert_str(nm64->str_tab + nm64->sorted_sym_tab[j].st_name);

    if (strcmp(str1, str2) > 0) {
        temp = nm64->sorted_sym_tab[i];
        nm64->sorted_sym_tab[i] = nm64->sorted_sym_tab[j];
        nm64->sorted_sym_tab[j] = temp;
    }
    free(str1);
    free(str2);
}

void sort_sym_tab(nm64_t *nm64)
{
    nm64->sorted_sym_tab = malloc(sizeof(Elf64_Sym) * nm64->sym_nb);
    if (!nm64->sorted_sym_tab)
        exit(84);
    for (int i = 0; i < nm64->sym_nb; i++)
        nm64->sorted_sym_tab[i] = nm64->sym_tab[i];
    for (int i = 0; i < nm64->sym_nb - 1; i++) {
        for (int j = i + 1; j < nm64->sym_nb; j++)
            compare_sym(nm64, i, j);
    }
}

void display_symbols(nm64_t *nm64)
{
    nm64->sym_nb = nm64->sym_tab_sh->sh_size / nm64->sym_tab_sh->sh_entsize;
    nm64->sym_tab = (Elf64_Sym *)(nm64->data + nm64->sym_tab_sh->sh_offset);
    nm64->str_tab = (char *)(nm64->data + nm64->str_tab_sh->sh_offset);
    sort_sym_tab(nm64);
    for (int i = 0; i < nm64->sym_nb; i++) {
        if (nm64->sorted_sym_tab[i].st_name != SHN_UNDEF
        && ELF64_ST_TYPE(nm64->sorted_sym_tab[i].st_info) != STT_FILE) {
            if (!nm64->sorted_sym_tab[i].st_value && nm64->elf->e_type == ET_EXEC)
                printf("                ");
            else
                printf("%016x", (unsigned)nm64->sorted_sym_tab[i].st_value);
            printf(" - %s\n", nm64->str_tab + nm64->sorted_sym_tab[i].st_name);
        }
    }
}
