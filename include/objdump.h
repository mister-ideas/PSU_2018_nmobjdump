/*
** EPITECH PROJECT, 2019
** PSU_2018_objdumpobjdump
** File description:
** objdump
*/

#ifndef OBJDUMP_H_
#define OBJDUMP_H_

#include <elf.h>

typedef struct objdump64 {
    void *data;
    Elf64_Ehdr *elf;
    Elf64_Shdr *sh;
    char *sh_str_tab;
    char *filename;
    int fd;
    int multi;
} objdump64_t;

//objdump.c
int launch_objdump(char *filename, int multi);

//open_file.c
int open_file(objdump64_t *objdump64);

//file_mapping.c
int file_mapping(objdump64_t *objdump64);

//check_file.c
void check_elf(objdump64_t *objdump64);
void check_architecture(objdump64_t *objdump64);
void check_file(objdump64_t *objdump64);

//init_data.c
void init_data(objdump64_t *objdump64);

//display.c
const char *get_flags(objdump64_t *objdump64);
void display_header(objdump64_t *objdump64);
void display_sections(objdump64_t *objdump64);
void display(objdump64_t *objdump64);

#endif /* !OBJDUMP_H_ */
