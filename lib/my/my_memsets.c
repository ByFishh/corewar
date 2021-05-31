/*
** EPITECH PROJECT, 2021
** my_memset_char.c
** File description:
** antman
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char *my_memset_char(int size)
{
    char *str = malloc(sizeof(char) * size);

    if (str == NULL)
        return NULL;
    for (int i = 0; i < size; i++)
        str[i] = '\0';
    return (str);
}

char **my_memset_dchar(int size1, int size2)
{
    char **str = malloc(sizeof(char *) * size1);

    if (str == NULL)
        return NULL;
    for (int i = 0; i < size1; i++) {
        str[i] = my_memset_char(size2);
        if (str[i] == NULL)
            return NULL;
    }
    return (str);
}

int *my_memset_int(int size)
{
    int *str = malloc(sizeof(int) * size);

    if (str == NULL)
        return NULL;
    for (int i = 0; i < size; i++)
        str[i] = 0;
    return (str);
}