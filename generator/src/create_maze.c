/*
** EPITECH PROJECT, 2022
** my_dante
** File description:
** create_maze
*/

#include <stdio.h>
#include <stdlib.h>
#include "generator.h"
#include "my.h"

static void create_tunnel(maze_t maze, run_t *run)
{
    int crave = 1;
    int enter = 0;

    for (int i = run->pos_start.x; crave; i += 2) {
        if (i >= maze.pos.x - 1)
            break;
        run->pos_end = V(i + 2, 2);
        maze.map[run->pos_start.y][i + 1] = '*';
        crave = my_randint(2);
        enter = 1;
    }
    if (!enter)
        run->pos_end.x = run->pos_start.x + 1;
    do {
        crave = my_randint(run->pos_end.x - run->pos_start.x);
    } while ((crave + run->pos_start.x) % 2 == 1);
    maze.map[run->pos_start.y - 1][crave + run->pos_start.x] = '*';
}

static void odd_maze(maze_t maze)
{
    if (maze.pos.x % 2 == 0 &&
    maze.map[maze.pos.y - 2][maze.pos.x - 1] != '*') {
        maze.map[maze.pos.y - 1][maze.pos.x - 2] = '*';
    }
}

void create_maze(maze_t maze)
{
    run_t *run = malloc(sizeof(run_t));

    if (!run)
        return;
    run->pos_start = V(0, 2);
    while (run->pos_start.y < maze.pos.y) {
        while (run->pos_start.x < maze.pos.x) {
            create_tunnel(maze, run);
            run->pos_start.x = run->pos_end.x + 2;
        }
        run->pos_start = V(0, run->pos_start.y + 2);
    }
    odd_maze(maze);
    free(run);
}
