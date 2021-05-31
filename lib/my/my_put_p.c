/*
** EPITECH PROJECT, 2020
** my_put_p
** File description:
** file 1
*/

#include <stdlib.h>

void my_putchar(char c);

int my_putstr(char const *str);

void print_p(long long nb)
{
    if (nb > 9 && nb < 16) {
        nb -= 10;
        my_putchar(nb + 97);
    } else if (nb < 10) {
        my_putchar(nb + 48);
    }
    if (nb > 15){
        print_p(nb / 16);
        print_p(nb % 16);
    }
    return;
}

void convert_p(unsigned long p)
{
    if (p == 0) {
        my_putstr("(nil)");
        return;
    } else {
        my_putstr("0x");
        print_p(p);
    }
}