/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** task03
*/

#include "my.h"

char *my_revstr(char *str)
{
    int length = my_strlen(str) - 1;
    char stock;

    for (int i = 0; i < length; i++, length--) {
        stock = str[i];
        str[i] = str[length];
        str[length] = stock;
    }
    return (str);
}