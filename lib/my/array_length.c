/*
** EPITECH PROJECT, 2022
** Sokoban
** File description:
** array_lenght
*/

int array_length(void **array)
{
    int len = 0;

    for (; array[len]; len++);
    return len;
}
