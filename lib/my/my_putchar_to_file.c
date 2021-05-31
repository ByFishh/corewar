/*
** EPITECH PROJECT, 2021
** my_putchar_to_file
** File description:
** file 1
*/
#include <unistd.h>

void my_putchar_to_file(char c, int fd)
{
    write(fd, &c, 1);
}