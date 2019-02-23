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
#include "objdump.h"

int open_file(objdump64_t *objdump64)
{
    objdump64->fd = open(objdump64->filename, O_RDONLY);
    if (objdump64->fd == -1) {
        dprintf(2, "nm: '%s': No such file\n", objdump64->filename);
        if (objdump64->multi)
            return (0);
        exit(84);
    }
    return (1);
}
