/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** file 1
*/

#include <stdlib.h>
#include "../include/struct.h"
#include "../include/prototype.h"

void convert(my_struct *store, unsigned int nb)
{
    if (store->specifier == 2)
        my_put_nbr(nb);
    if (store->specifier == 3) {
        if (store->flags == 4 && nb != 0)
            my_putchar('0');
        my_put_octal(nb);
    }
    if (store->specifier == 4) {
        if (store->flags == 4 && nb != 0)
            my_putstr("0x");
        convert_hexa(nb, 0);
    }
    if (store->specifier == 5) {
        if (store->flags == 4 && nb != 0)
            my_putstr("0X");
        convert_hexa(nb, 1);
    }
    if (store->specifier == 19)
        my_put_bin(nb);
}