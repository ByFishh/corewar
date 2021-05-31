/*
** EPITECH PROJECT, 2021
** live_lexer.c
** File description:
** asm
*/

#include "asm.h"

static int live_error(char **parse)
{
    int i = 1;

    for (; parse[i] != NULL && i < 5; i += 1) {
        if (i > 1)
            return (0);
        if (!(verif_dir_nb_foor(parse[i], FFFFFFFF)))
            return (0);
    }
    if (i != 2)
        return (0);
    return (i);
}

static void live_add_node(data_t *data, char **parse)
{
    char *hexa = my_memset_char(20);
    char **val_hex = my_memset_dchar(4, 3);
    long nb = 0;
    unsigned long u_nb = 0;
    node_t *tmp = NULL;

    tmp = add_node(data);
    tmp->args = malloc(sizeof(unsigned char) * 6);
    data->hex_total += 5;
    tmp->size = 5;
    tmp->args[0] = 0x1;
    nb = int_to_bin_to_twos_complement(-my_getnbr_long(parse[1] + 1), 1);
    if (nb < 0) {
        u_nb = FFFFFFFF + nb;
        int_to_hex_long(u_nb, hexa);
    } else
        int_to_hex(nb, hexa);
    tmp->args = stock_args(tmp, hexa, val_hex, (int [3]){0, 4, 4});
    free(data->have_label);
    free_inst(hexa, val_hex);
}

int live_instr(data_t *data, char **parse)
{
    char *args = my_memset_char(4);

    if (!(live_error(parse)))
        return (0);
    data->have_label = my_memset_char(my_strlen(parse[1]));
    if (parse[1][1] == LABEL_CHAR) {
        if (!verif_dir_label(data, parse[1], "live", 4))
            return (0);
    }
    live_add_node(data, parse);
    free(args);
    return (1);
}