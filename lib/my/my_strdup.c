/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** file 1
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(const char *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(src) + 6));
    int a = 0;
    int b = 0;

    while (src[b] != '\0') {
        str[a] = src[b];
        a++;
        b++;
    }
    str[a] = '\0';
    return (str);
}