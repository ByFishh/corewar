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

int verif_precision(char *str, my_struct *store, int *subcount)
{
    int precision = 0;
    int count = 0;

    if (str[0] == '.') {
        str += 1;
        for (count = 0; str[count] <= '9' && str[count] >= '0'; count += 1);
        precision = my_getnbr(str);
    }
    store->precision = precision;
    *subcount += count;
    if (count == 0)
        return (0);
    *subcount += 1;
    return (count + 1);
}