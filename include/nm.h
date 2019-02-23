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
    Elf64_Sym *sorted_sym_tab;
    char *sh_str_tab;
    char *str_tab;
    char *filename;
    int sym_nb;
    int fd;
    int multi;
} nm64_t;

//nm.c
int launch_nm(char *filename, int multi);

//open_file.c
int open_file(nm64_t *nm64);

//file_mapping.c
int file_mapping(nm64_t *nm64);

//symbols.c
char *convert_str(char *str);
void compare_sym(nm64_t *nm64, int i, int j);
void sort_sym_tab(nm64_t *nm64);
void display_symbols(nm64_t *nm64);

//types.c
char get_sym_type_special(Elf64_Sym sym);
char get_sym_type(nm64_t *nm64, Elf64_Sym sym);

//check_file.c
void check_elf(nm64_t *nm64);
void check_architecture(nm64_t *nm64);
void check_file(nm64_t *nm64);

//init_data.c
void init_data(nm64_t *nm64);

#endif /* !NM_H_ */
