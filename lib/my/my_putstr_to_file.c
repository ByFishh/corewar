/*
** EPITECH PROJECT, 2021
** my_putstr_to_file
** File description:
** file 1
*/
#include <unistd.h>

int my_strlen(char const *str);

void my_putstr_to_file(char *str, int fd)
{
    write(fd, str, my_strlen(str));
}