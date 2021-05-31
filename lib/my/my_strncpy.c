/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** task02
*/
#include <stdio.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int nb;
    int count;

    for (nb = 0; src[nb] != '\0'; nb++);
    for (count = 0; count <= (n - 1); count++)
        dest[count] = src[count];
    if (n > nb)
        dest[count + 1] = '\0';
    return (dest);
}