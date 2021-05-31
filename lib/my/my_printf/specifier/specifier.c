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

int verif_specifer(char *str, my_struct *store, int *count)
{
    int temp = 0;

    temp = (str[0] == 'd' || str[0] == 'i') ? 1 : temp;
    temp = (str[0] == 'u') ? 2 : temp;
    temp = (str[0] == 'o') ? 3 : temp;
    temp = (str[0] == 'x') ? 4 : temp;
    temp = (str[0] == 'X') ? 5 : temp;
    temp = (str[0] == 'c') ? 14 : temp;
    temp = (str[0] == 's') ? 15 : temp;
    temp = (str[0] == 'S') ? 16 : temp;
    temp = (str[0] == 'p') ? 17 : temp;
    temp = (str[0] == 'n') ? 18 : temp;
    temp = (str[0] == 'b') ? 19 : temp;
    temp = (str[0] == '%') ? 20 : temp;
    if (temp > 0) {
        *count += 1;
        store->specifier = temp;
        return (1);
    }
    return (0);
}