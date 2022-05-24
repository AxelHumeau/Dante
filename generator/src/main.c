/*
** EPITECH PROJECT, 2022
** generator
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include "generator.h"
#include "my.h"
#include <time.h>

static void print_map(char **map)
{
    int i = 0;

    for (i = 0; map[i + 1] != NULL; i++) {
        printf("%s\n", map[i]);
    }
    printf("%s", map[i]);
}

static void my_free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        free(tab[i]);
    }
    free(tab);
}

static void imperfect(maze_t maze)
{
    int rand = my_randint(maze.pos.x / 2);
    int x = 0;
    int y = 0;

    for (int i = 0; i < rand; ) {
        x = my_randint(maze.pos.x - 1);
        y = my_randint(maze.pos.y - 1);
        if (maze.map[y][x] != '*') {
            maze.map[y][x] = '*';
            i++;
        }
    }
    print_map(maze.map);
}

int main(int ac, char *const *av)
{
    maze_t maze;

    srand(time(NULL));
    if (ac < 3 || ac > 4)
        return 84;
    maze = start_maze(av[1], av[2]);
    if (!maze.map)
        return 84;
    create_maze(maze);
    if (ac == 4) {
        if (!my_strcmp(av[3], "perfect")) {
            print_map(maze.map);
            return 0;
        }
    }
    imperfect(maze);
    my_free_tab(maze.map);
    return 0;
}
