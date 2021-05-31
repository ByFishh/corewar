/*
** EPITECH PROJECT, 2021
** utils.c
** File description:
** asm
*/

#include "asm.h"

unsigned char *stock_args(node_t *tmp, char *hexa, char **val_hex, int *size)
{
    int size_one = size[1];

    for (int nb = 0; nb < size[2]; nb++)
        val_hex[nb][0] = '0';
    for (int nb = 1, lnb = 0, size_one = my_strlen(hexa) - 1;
    size_one >= 0; size_one--) {
        if (nb == -1) {
            nb = 1;
            lnb += 1;
        }
        val_hex[lnb][nb--] = hexa[size_one];
    }
    for (int nb = size_one, lnb = 0; nb > size[0]; nb--, lnb++) {
        tmp->args[nb] = hex_to_int(val_hex[lnb]);
    }
    return (tmp->args);
}

int starter_count(char *parse)
{
    if (my_strncmp(parse, "fork", 4) == 0
        || my_strncmp(parse, "lfork", 5) == 0
        || my_strncmp(parse, "zjmp", 4) == 0
        || my_strncmp(parse, "live", 4) == 0)
        return (0);
    return (1);
}

void refresh_var_complete(char ***val_hex, char **hexa)
{
    free_inst(*hexa, *val_hex);
    *val_hex = my_memset_dchar(4, 3);
    *hexa = my_memset_char(20);
}