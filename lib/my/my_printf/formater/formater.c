/*
** EPITECH PROJECT, 2020
** formater
** File description:
** file 1
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/struct.h"
#include "../include/prototype.h"

void formater_int(int varg, my_struct *store)
{
    int tmp = 0;

    if (store->precision >= store->width)
        store->width = 0;
    if (store->precision < store->width)
        store->width -= store->precision;
    if (store->width > 0 && store->width > my_nbrlen(varg, 10)) {
        tmp = (store->width - my_nbrlen(varg, 10));
        for (int nb = 0; nb != tmp; nb += 1)
            my_putchar(' ');
    }
    if (store->precision > 0 && store->precision > my_nbrlen(varg, 10)) {
        tmp = (store->precision - my_nbrlen(varg, 10));
        for (int nb = 0; nb != tmp; nb += 1)
            my_putchar('0');
    }
    my_put_nbr(varg);
}