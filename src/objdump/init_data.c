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
    objdump64->sh_str_tab = (objdump64->data
    + objdump64->sh[objdump64->elf->e_shstrndx].sh_offset);
}