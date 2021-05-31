/*
** EPITECH PROJECT, 2021
** complete_args_noindex.c
** File description:
** asm
*/

#include "asm.h"

static int complete_dir_label(node_t *tmp, char **parse, int j,
int count)
{
    char *hexa = my_memset_char(20);
    char **val_hex = my_memset_dchar(4, 3);
    long nb = 0;
    unsigned long u_nb = 0;

    nb = int_to_bin_to_twos_complement(-my_getnbr_long(parse[j + 1] + 1), 1);
    if (nb < 0) {
        u_nb = FFFFFFFF + nb;
        int_to_hex_long(u_nb, hexa);
    } else
        int_to_hex_long(nb, hexa);
    tmp->args = stock_args(tmp, hexa, val_hex, (int [3]){count, count + 4, 4});
    count += 4;
    free_inst(hexa, val_hex);
    return (count);
}

static int complete_ind_label_noindex(node_t *tmp, char **parse, int j,
int count)
{
    char *hexa = my_memset_char(20);
    char **val_hex = my_memset_dchar(4, 3);
    int nb = 0;

    nb = int_to_bin_to_twos_complement(-my_getnbr(parse[j + 1]), 0);
    int_to_hex(nb, hexa);
    tmp->args = stock_args(tmp, hexa, val_hex, (int [3]){count, count + 2, 2});
    count += 2;
    free_inst(hexa, val_hex);
    return (count);
}

void complete_args(node_t *tmp, char **parse, char *args, int nb_args)
{
    char *hexa = my_memset_char(20);
    char **val_hex = my_memset_dchar(4, 3);

    for (int j = 0, count = starter_count(parse[0]); j < nb_args; j++) {
        if (args[j] == 'r') {
            int_to_hex(my_getnbr_long(parse[j + 1] + 1), hexa);
            tmp->args = stock_args(tmp, hexa, val_hex,
            (int [3]){count, count + 1, 1});
            count += 1;
        } else if (args[j] == 'd') {
            count = complete_dir_label(tmp, parse, j, count);
        } else
            count = complete_ind_label_noindex(tmp, parse, j, count);
        refresh_var_complete(&val_hex, &hexa);
    }
    free_inst(hexa, val_hex);
}