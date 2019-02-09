/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** nm
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include "nm.h"

int launch_nm(char *filename, int multi)
{
    nm64_t *nm64 = malloc(sizeof(nm64_t));
    int size = 0;

    if (!nm64)
        exit(84);
    nm64->filename = filename;
    nm64->multi = multi;
    if (open_file(nm64) == 0)
        return (0);
    size = file_mapping(nm64);
    symbols(nm64);
    if (close(nm64->fd) == -1) {
        dprintf(2, "nm: '%s': Can't close file\n", nm64->filename);
        exit(84);
    }
    munmap(nm64->data, size);
    free(nm64);
    return (1);
}

int main(int ac, char **av)
{
    int error = 0;

    if (ac == 1)
        launch_nm("a.out", 0);
    else if (ac == 2)
        launch_nm(av[1], 0);
    else {
        for (int i = 1; av[i]; i++)
            if (launch_nm(av[i], 1) == 0)
                error = 1;
        if (error)
            return (84);
    }
    return (0);
}
