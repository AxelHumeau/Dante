/*
** EPITECH PROJECT, 2022
** Dante
** File description:
** create_node
*/

#include "my.h"
#include "solver.h"
#include <stdlib.h>

graph_t *create_graph_node(vector_t pos, graph_t *father)
{
    graph_t *graph = malloc(sizeof(graph_t));

    graph->children = malloc(sizeof(graph_t *) * 4);
    for (int i = 0; i < 4; i++)
        graph->children[i] = NULL;
    graph->pos = pos;
    graph->father = father;
    return graph;
}

graph_t *create_root(void)
{
    graph_t *root = malloc(sizeof(graph_t));

    root->children = malloc(sizeof(graph_t *) * 4);
    for (int i = 0; i < 4; i++)
        root->children[i] = NULL;
    root->pos = V(0, 0);
    root->father = NULL;
    return root;
}

void add_child(graph_t *graph, vector_t pos)
{
    static int index = 0;

    if (pos.x == -1 && pos.y == -1) {
        graph->children[index] = NULL;
        index = 0;
        return;
    }
    graph->children[index] = create_graph_node(pos, graph);
    index++;
}

void free_graph(graph_t *graph)
{
    if (graph == NULL)
        return;
    else {
        for (int i = 0; i < 4; i++)
            free_graph(graph->children[i]);
        free(graph->children);
        free(graph);
    }
}
