/*
** EPITECH PROJECT, 2020
** my_strcpy_after_n
** File description:
** file 1
*/

#include <stdlib.h>
#include <stdio.h>

char *my_strcpy_after_n(char *dest, char *src, int n)
{
    int count;
    int subcount = 0;

    for (count = 0; src[count] != '\0'; count += 1)
        if (count >= n) {
            dest[subcount] = src[count];
            subcount += 1;
        }
    dest[subcount] = '\0';
    return (dest);
}
