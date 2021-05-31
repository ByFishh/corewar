/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** file 1
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/struct.h"
#include "include/prototype.h"

void print_res(va_list list, my_struct *store)
{
    if (store->specifier == 1)
        formater_int(va_arg(list, int), store);
    if (store->specifier >= 2 && store->specifier <= 5)
        convert(store, va_arg(list, unsigned int));
    if (store->specifier == 14)
        my_putchar(va_arg(list, int));
    if (store->specifier == 15)
        my_putstr(va_arg(list, char *));
    if (store->specifier == 16)
        my_putstr_nprint(va_arg(list, char *));
    if (store->specifier == 17)
        convert_p(va_arg(list, unsigned long));
    if (store->specifier == 19)
        convert(store, va_arg(list, unsigned int));
    if (store->specifier == 20)
        my_putchar('%');
}

int verif_format(char *str, my_struct *store, va_list list)
{
    int count = 1;
    str += verif_flags(str, store, &count);
    str += verif_width(str, store, &count);
    str += verif_precision(str, store, &count);
    str += verif_length(str, store, &count);
    verif_specifer(str, store, &count);
    if (store->specifier == 0) {
        my_putchar('%');
        return (1);
    }
    print_res(list, store);
    if (count == 1)
        count = 0;
    return (count);
}

void initialise_struct(my_struct *store)
{
    store->flags = 0;
    store->length = 0;
    store->precision = 0;
    store->specifier = 0;
    store->width = 0;
}

int my_printf(char *str, ...)
{
    my_struct *store = malloc(sizeof(my_struct));
    va_list list;

    va_start(list, str);
    initialise_struct(store);
    for (int count = 0; str[count] != '\0'; count += 1) {
        if (str[count] == '%') {
            count += verif_format(str + count + 1, store, list);
            count -= 1;
        }
        else
            my_putchar(str[count]);
    }
    free(store);
    va_end(list);
}