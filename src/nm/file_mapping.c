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
#include "nm.h"

int file_mapping(nm64_t *nm64)
{
    struct stat s;

    if (fstat(nm64->fd, &s) == -1) {
        dprintf(2, "nm: '%s': Can't retrieve file stats\n", nm64->filename);
        exit(84);
    }
    if (S_ISDIR(s.st_mode)) {
        dprintf(2, "nm: Warning: '%s' is not an ordinary file\n",
        nm64->filename);
        exit(84);
    }
    nm64->data = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, nm64->fd, 0);
    if (nm64->data == MAP_FAILED) {
        dprintf(2, "nm: '%s': File mapping failed\n", nm64->filename);
        exit(84);
    }
    return (s.st_size);
}
