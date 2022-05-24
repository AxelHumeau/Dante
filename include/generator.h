/*
** EPITECH PROJECT, 2022
** generator
** File description:
** generator
*/

#pragma once

#define V(x, y) create_vector(x, y)

typedef struct vector_struct {
    int x;
    int y;
} vector_t;

typedef struct {
    char **map;
    vector_t pos;
} maze_t;

typedef struct run_s {
    vector_t pos_start;
    vector_t pos_end;
} run_t;

int my_str_isnum(char const *str);
vector_t create_vector(int x, int y);
maze_t start_maze(const char *str_x, const char * str_y);
int my_randint(int limit);
void create_maze(maze_t maze);
