/*
** EPITECH PROJECT, 2022
** Dante
** File description:
** fifo
*/

#include "my.h"
#include "solver.h"
#include <stdlib.h>

fifo_t *create_queue(void)
{
    fifo_t *fifo = malloc(sizeof(fifo_t));

    fifo->head = NULL;
    fifo->tail = NULL;
    fifo->size = 0;
    return fifo;
}

void add_to_queue(graph_t *graph, fifo_t *fifo)
{
    linked_list_t *node = malloc(sizeof(linked_list_t));

    node->data = graph;
    node->next = NULL;
    if (fifo->head == NULL) {
        fifo->head = node;
        fifo->tail = node;
    } else {
        fifo->tail->next = node;
        fifo->tail = fifo->tail->next;
    }
    fifo->size++;
}

graph_t *remove_from_queue(fifo_t *fifo)
{
    graph_t *to_return;
    linked_list_t *tmp;

    if (fifo->head == NULL)
        return NULL;
    tmp = fifo->head;
    fifo->head = fifo->head->next;
    to_return = tmp->data;
    free(tmp);
    return to_return;
}

void free_queue(fifo_t *fifo)
{
    linked_list_t *to_free;

    for (linked_list_t * tmp = fifo->head; tmp;) {
        to_free = tmp;
        tmp = tmp->next;
        free(to_free);
    }
    free(fifo);
}
