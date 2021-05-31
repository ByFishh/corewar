/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** file 1
*/

#include <stdarg.h>
#include <stdio.h>
#include "../include/struct.h"
#include "../include/prototype.h"

int verif_flags(char *str, my_struct *store, int *count)
{
    int temp = 0;

    temp = (str[0] == '-') ? 1 : temp;
    temp = (str[0] == '+') ? 2 : temp;
    temp = (str[0] == ' ') ? 3 : temp;
    temp = (str[0] == '#') ? 4 : temp;
    temp = (str[0] == '0') ? 5 : temp;
    if (temp > 0) {
        *count += 1;
        store->flags = temp;
        return (1);
    }
    return (0);
}