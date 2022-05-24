/*
** EPITECH PROJECT, 2022
** Dante
** File description:
** solve
*/

#include "solver.h"
#include "my.h"
#include <stdlib.h>
#include <stdio.h>

static void find_children(maze_t *maze, graph_t *graph)
{
    if (graph->pos.x > 0 && maze->map[graph->pos.y][graph->pos.x - 1] == '*')
        add_child(graph, V(graph->pos.x - 1, graph->pos.y));
    if (maze->map[graph->pos.y + 1] != NULL &&
        maze->map[graph->pos.y + 1][graph->pos.x] == '*')
        add_child(graph, V(graph->pos.x, graph->pos.y + 1));
    if (maze->map[graph->pos.y][graph->pos.x + 1] != '\0' &&
        maze->map[graph->pos.y][graph->pos.x + 1] == '*')
        add_child(graph, V(graph->pos.x + 1, graph->pos.y));
    if (graph->pos.y > 0 && maze->map[graph->pos.y - 1][graph->pos.x] == '*')
        add_child(graph, V(graph->pos.x, graph->pos.y - 1));
    add_child(graph, V(-1, -1));
}

static graph_t *explore_maze(maze_t *maze, graph_t *graph)
{
    graph_t *tmp;

    maze->map[graph->pos.y][graph->pos.x] = 'x';
    if (REACH_END)
        return graph;
    find_children(maze, graph);
    while (graph->children[0] != NULL && graph->children[1] == NULL) {
        graph = graph->children[0];
        find_children(maze, graph);
        maze->map[graph->pos.y][graph->pos.x] = 'x';
        if (REACH_END)
            return graph;
    }
    for (int i = 0; graph->children[i] != NULL; i++) {
        tmp = explore_maze(maze, graph->children[i]);
        if (tmp)
            return tmp;
    }
    return NULL;
}

int init_exploring(char **maze_map)
{
    graph_t *graph = create_root();
    maze_t *maze = create_maze(maze_map);
    int i = 0;

    graph = explore_maze(maze, graph);
    if (graph == NULL)
        return 1;
    for (; graph; graph = graph->father)
        maze->map[graph->pos.y][graph->pos.x] = 'o';
    clean_maze(maze);
    for (; maze->map[i + 1] != NULL; i++)
        printf("%s\n", maze->map[i]);
    printf("%s", maze->map[i]);
    free_all(maze, graph);
    return 0;
}
