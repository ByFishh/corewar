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

int verif_length(char *str, my_struct *store, int *count)
{
    int temp = 0;

    temp = (str[0] == 'h' && str[1] == 'h') ? 1 : temp;
    temp = (str[0] == 'h' && str[1] != 'h') ? 2 : temp;
    temp = (str[0] == 'l' && str[1] == 'l') ? 3 : temp;
    temp = (str[0] == 'l' && str[1] != 'l') ? 4 : temp;
    temp = (str[0] == 'j') ? 5 : temp;
    temp = (str[0] == 'z') ? 6 : temp;
    temp = (str[0] == 't') ? 7 : temp;
    temp = (str[0] == 'L') ? 8 : temp;
    if (temp == 1 || temp == 3) {
        store->length = temp;
        *count += 2;
        return (2);
    } else if (temp > 0) {
        store->length = temp;
        *count += 1;
        return (1);
    }
    return (0);
}