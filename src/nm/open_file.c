/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** open_file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "nm.h"

int open_file(nm64_t *nm64)
{
    nm64->fd = open(nm64->filename, O_RDONLY);
    if (nm64->fd == -1) {
        dprintf(2, "nm: '%s': No such file\n", nm64->filename);
        if (nm64->multi)
            return (0);
        exit(84);
    }
    if (nm64->multi)
        printf("\n%s:\n", nm64->filename);
    return (1);
}
