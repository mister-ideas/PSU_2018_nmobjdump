/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** objdump
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include "objdump.h"

int launch_objdump(char *filename, int multi)
{
    objdump64_t *objdump64 = malloc(sizeof(objdump64_t));
    int size = 0;

    if (!objdump64)
        exit(84);
    objdump64->filename = filename;
    objdump64->multi = multi;
    if (open_file(objdump64) == 0)
        return (0);
    size = file_mapping(objdump64);
    check_file(objdump64);
    init_data(objdump64);
    display(objdump64);
    if (close(objdump64->fd) == -1) {
        dprintf(2, "objdump: '%s': Can't close file\n", objdump64->filename);
        exit(84);
    }
    munmap(objdump64->data, size);
    free(objdump64);
    return (1);
}

int main(int ac, char **av)
{
    int error = 0;

    if (ac == 1)
        launch_objdump("a.out", 0);
    else if (ac == 2)
        launch_objdump(av[1], 0);
    else {
        for (int i = 1; av[i]; i++)
            if (launch_objdump(av[i], 1) == 0)
                error = 1;
        if (error)
            return (84);
    }
    return (0);
}