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

static int explore_maze(maze_t *maze, graph_t *graph)
{
    graph_t *tmp = graph;
    fifo_t *queue = create_queue();
    int is_first = 1;

    while ((tmp != NULL && !(tmp->pos.y == maze->size.y - 1 &&
        tmp->pos.x == maze->size.x - 1)) || is_first) {
        maze->map[tmp->pos.y][tmp->pos.x] = 'x';
        find_children(maze, tmp);
        for (int i = 0; tmp->children[i] != NULL; i++)
            add_to_queue(tmp->children[i], queue);
        tmp = remove_from_queue(queue);
        is_first = 0;
    }
    if (tmp == NULL)
        return 0;
    for (; tmp; tmp = tmp->father)
        maze->map[tmp->pos.y][tmp->pos.x] = 'o';
    free_queue(queue);
    return (1);
}

static void clean_maze(maze_t *maze)
{
    for (int i = 0; i < maze->size.y; i++) {
        for (int j = 0; j < maze->size.x; j++) {
            if (maze->map[i][j] == 'x')
                maze->map[i][j] = '*';
        }
    }
}

static void free_all(maze_t *maze, graph_t *graph)
{
    for (int i = 0; i < maze->size.y; i++)
        free(maze->map[i]);
    free(maze->map);
    free(maze);
    free_graph(graph);
}

int init_exploring(char **maze_map)
{
    graph_t *graph = create_root();
    maze_t *maze = malloc(sizeof(maze_t));
    int i = 0;
    int j = 0;

    maze->map = maze_map;
    for (; maze_map[i] != NULL; i++)
        for (; maze_map[i][j] != '\0'; j++);
    maze->size = V(j, i);
    if (!explore_maze(maze, graph))
        return 1;
    clean_maze(maze);
    for (i = 0; maze->map[i + 1] != NULL; i++)
        printf("%s\n", maze->map[i]);
    printf("%s", maze->map[i]);
    free_all(maze, graph);
    return 0;
}
