/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** task07
*/

#include "my.h"

int my_strncmp(char const *str1, char const *str2, int n)
{
    if (my_strlen(str1) != my_strlen(str2))
        return (1);
    for (int nb = 0; nb < n; nb += 1) {
        if (str1[nb] != str2[nb])
            return (1);
    }
    return (0);
}