/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** file_mapping
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>
#include "objdump.h"

int file_mapping(objdump64_t *objdump64)
{
    struct stat s;

    if (fstat(objdump64->fd, &s) == -1) {
        dprintf(2, "objdump: '%s': Can't retrieve file stats\n", objdump64->filename);
        exit(84);
    }
    if (S_ISDIR(s.st_mode)) {
        dprintf(2, "objdump: Warning: '%s' is not an ordinary file\n", objdump64->filename);
        exit(84);
    }
    objdump64->data = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, objdump64->fd, 0);
    if (objdump64->data == MAP_FAILED) {
        dprintf(2, "objdump: '%s': File mapping failed\n", objdump64->filename);
        exit(84);
    }
    return (s.st_size);
}
