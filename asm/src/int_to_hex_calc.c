/*
** EPITECH PROJECT, 2021
** int_to_hex_calc.c
** File description:
** asm
*/

#include "asm.h"

void int_to_hex(long dec_nb, char *args)
{
    long nb_decimal = dec_nb;
    int i = 1;
    long reminder = 0;
    char *dec_nb_str = my_getstr(dec_nb);
    char *nb_hexa = my_memset_char(my_strlen(dec_nb_str) + 1);

    while (nb_decimal != 0) {
        reminder = nb_decimal % 16;
        nb_decimal = nb_decimal / 16;
        if (reminder >= 10) {
            nb_hexa[i] = 'a' + (reminder % 10);
        } else
            nb_hexa[i] = reminder + '0';
        i++;
    }
    for (int j = i - 1, z = 0; j > 0; j--, z++)
        args[z] = nb_hexa[j];
    free(nb_hexa);
    free(dec_nb_str);
}

void int_to_hex_long(unsigned long dec_nb, char *args)
{
    unsigned long nb_decimal = dec_nb;
    int i = 1;
    int reminder = 0;
    char *nb_hexa = my_memset_char(20);

    while (nb_decimal != 0) {
        reminder = nb_decimal % 16;
        nb_decimal = nb_decimal / 16;
        if (reminder >= 10) {
            nb_hexa[i] = 'a' + (reminder % 10);
        } else
            nb_hexa[i] = reminder + '0';
        i++;
    }
    for (int j = i - 1, z = 0; j > 0; j--, z++)
        args[z] = nb_hexa[j];
    free(nb_hexa);
}

long hex_to_int(char *hex_nb)
{
    long nb_decimal = 0;
    int base = 1;

    for (int i = my_strlen(hex_nb) - 1; i >= 0; i--) {
        if (hex_nb[i] >= '0' && hex_nb[i] <= '9') {
            nb_decimal += (hex_nb[i] - 48) * base;
            base = base * 16;
        }
        else if (hex_nb[i] >= 'a' && hex_nb[i] <= 'f') {
            nb_decimal += (hex_nb[i] - 87) * base;
            base = base * 16;
        }
    }
    return (nb_decimal);
}