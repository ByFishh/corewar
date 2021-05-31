/*
** EPITECH PROJECT, 2021
** binary_calc.c
** File description:
** asm
*/

#include "asm.h"

int binary_to_dec(int binary)
{
    int dec = 0;
    int base = 1;
    int rem = 0;

    while (binary > 0) {
        rem = binary % 10;
        dec = dec + rem * base;
        binary = binary / 10;
        base = base * 2;
    }
    return (dec);
}

int coding_byte(node_t *tmp, char *args, int nb_args)
{
    int binary = 0;

    tmp->size = 2;
    for (int i = 0; i < nb_args; i++) {
        if (args[i] == 'r') {
            tmp->size += 1;
            binary = (binary * 100) + 1;
        }
        if (args[i] == 'd') {
            tmp->size += 4;
            binary = (binary * 100) + 10;
        }
        if (args[i] == 'i') {
            tmp->size += 2;
            binary = (binary * 100) + 11;
        }
    }
    binary = binary * 100;
    return (binary);
}

int coding_byte_index(node_t *tmp, char *args, int nb_args)
{
    int binary = 0;

    tmp->size = 2;
    for (int i = 0; i < nb_args; i++) {
        if (args[i] == 'r') {
            tmp->size += 1;
            binary = (binary * 100) + 1;
        }
        if (args[i] == 'd') {
            tmp->size += 2;
            binary = (binary * 100) + 10;
        }
        if (args[i] == 'i') {
            tmp->size += 2;
            binary = (binary * 100) + 11;
        }
    }
    binary = binary * 100;
    return (binary);
}