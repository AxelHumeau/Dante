/*
** EPITECH PROJECT, 2022
** Dante
** File description:
** solver
*/

#pragma once

#define V(x, y) create_vector(x, y)
#define REACH_END graph->pos.y == maze->size.y - 1 && \
graph->pos.x == maze->size.x - 1

typedef struct vector_struct {
    int x;
    int y;
} vector_t;

typedef struct graph_struct {
    vector_t pos;
    struct graph_struct *father;
    struct graph_struct **children;
} graph_t;

typedef struct maze {
    char **map;
    vector_t size;
} maze_t;

typedef struct linked_list_struct {
    graph_t *data;
    struct linked_list_struct *next;
} linked_list_t;

typedef struct fifo_struct {
    linked_list_t *tail;
    linked_list_t *head;
    int size;
} fifo_t;

vector_t create_vector(int x, int y);
graph_t *create_root(void);
graph_t *create_graph_node(vector_t pos, graph_t *father);
void add_child(graph_t *graph, vector_t pos);
int init_exploring(char **maze_map);
void free_graph(graph_t *graph);
fifo_t *create_queue(void);
void add_to_queue(graph_t *graph, fifo_t *fifo);
graph_t *remove_from_queue(fifo_t *fifo);
void free_queue(fifo_t *fifo);
void clean_maze(maze_t *maze);
void free_all(maze_t *maze, graph_t *graph);
maze_t *create_maze(char **maze_map);
