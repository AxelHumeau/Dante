/*
** EPITECH PROJECT, 2022
** dante
** File description:
** init_maze
*/

#include <stdio.h>
#include <stdlib.h>
#include "generator.h"

static char complet_wall(int i, int j)
{
    if (i == 0)
        return '*';
    else if (i % 2 || j % 2)
        return 'X';
    return '*';
}

static char **empty_maze(vector_t pos)
{
    char **map = NULL;

    if (pos.x < 0 || pos.y < 0)
        return NULL;
    map = malloc(sizeof(char *) * (pos.y + 1));
    if (!map)
        return NULL;
    for (int i = 0; i < pos.y; i++) {
        map[i] = malloc(sizeof(char) * (pos.x + 1));
        if (!map[i])
            return NULL;
        for (int j = 0; j < pos.x; j++)
            map[i][j] = complet_wall(i, j);
        map[i][pos.x] = '\0';
    }
    map[pos.y] = NULL;
    if (pos.x % 2 == 0 || pos.y % 2 == 0)
        map[pos.y - 1][pos.x - 1] = '*';
    return map;
}

maze_t start_maze(const char *str_x, const char * str_y)
{
    maze_t maze;

    if (!my_str_isnum(str_x) || !my_str_isnum(str_y))
        maze.pos = V(-1, -1);
    else
        maze.pos = V(atoi(str_x), atoi(str_y));
    maze.map = empty_maze(maze.pos);
    return maze;
}
