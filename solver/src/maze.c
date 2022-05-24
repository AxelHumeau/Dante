/*
** EPITECH PROJECT, 2022
** Dante
** File description:
** maze
*/

#include "my.h"
#include "solver.h"
#include <stdlib.h>

maze_t *create_maze(char **maze_map)
{
    maze_t *maze = malloc(sizeof(maze_t));
    int i = 0;
    int j = 0;

    maze->map = maze_map;
    for (; maze_map[i] != NULL; i++)
        for (; maze_map[i][j] != '\0'; j++);
    maze->size = V(j, i);
    return maze;
}

static void replace_chars(maze_t *maze, int i, int j)
{
    if (maze->map[i][j] == 'x')
        maze->map[i][j] = '*';
}

void clean_maze(maze_t *maze)
{
    for (int i = 0; i < maze->size.y; i++) {
        for (int j = 0; j < maze->size.x; j++)
            replace_chars(maze, i, j);
    }
}

void free_all(maze_t *maze, graph_t *graph)
{
    for (int i = 0; i < maze->size.y; i++)
        free(maze->map[i]);
    free(maze->map);
    free(maze);
    free_graph(graph);
}
