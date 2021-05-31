/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** task01
*/
#include <stdio.h>

char *my_strcpy(char *dest, char const *src)
{
    int nb;

    for (nb = 0; src[nb] != '\0'; nb++);
    for (int count = 0; count <= nb; count++)
        dest[count] = src[count];
    return (dest);
}