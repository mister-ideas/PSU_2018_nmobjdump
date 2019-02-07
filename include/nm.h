/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** nm
*/

#ifndef NM_H_
#define NM_H_

#include <elf.h>

typedef struct nm64 {
    void *data;
    Elf64_Ehdr *elf;
    Elf64_Shdr *sh;
    Elf64_Shdr *sym_tab_sh;
    Elf64_Shdr *str_tab_sh;
    Elf64_Sym *sym_tab;
    char *str_tab;
    char *filename;
    int fd;
    int multi;
} nm64_t;

//nm.c
int launch_nm(char *filename, int multi);

//open_file.c
int open_file(nm64_t *nm64);

//file_mapping.c
void file_mapping(nm64_t *nm64);

//symbols.c
void symbols(nm64_t *nm64);

#endif /* !NM_H_ */
