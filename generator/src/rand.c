/*
** EPITECH PROJECT, 2022
** my_dante
** File description:
** rand
*/

#include <stdio.h>
#include <stdlib.h>

int my_randint(int limit)
{
    int randint = rand();

    return randint % limit;
}
