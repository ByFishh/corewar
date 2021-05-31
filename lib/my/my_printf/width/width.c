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

int verif_width(char *str, my_struct *store, int *subcount)
{
    int width = 0;
    int count = 0;

    if (str[0] >= '0' && str[0] <= '9') {
        for (count = 0; str[count] <= '9' && str[count] >= '0'; count += 1);
        width = my_getnbr(str);
    }
    store->width = width;
    *subcount += count;
    if (count == 0)
        return (0);
    return (count);
}