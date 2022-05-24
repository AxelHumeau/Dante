/*
** EPITECH PROJECT, 2022
** Dante
** File description:
** read_file
*/

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

char *read_file(char const *pathname)
{
    char *buff;
    int fd;
    int size;
    struct stat sb;

    fd = open(pathname, O_RDONLY);
    if (fd == -1 || stat(pathname, &sb) != 0)
        return NULL;
    buff = malloc(sizeof(char) * (sb.st_size + 1));
    size = read(fd, buff, sb.st_size);
    buff[size] = '\0';
    close(fd);
    return (buff);
}
