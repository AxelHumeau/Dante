/*
** EPITECH PROJECT, 2022
** Dante
** File description:
** main
*/

#include "my.h"
#include "solver.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
    char **maze;
    char *buff;

    if (argc != 2)
        return 84;
    buff = read_file(argv[1]);
    if (!buff)
        return 84;
    maze = my_str_separator(buff, "\n");
    free(buff);
    if (init_exploring(maze))
        my_printf("no solution found");
    return 0;
}
