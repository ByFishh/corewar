/*
** EPITECH PROJECT, 2021
** ld_lexer.c
** File description:
** asm
*/

#include "asm.h"

static int verif_param(char *parse, int i, char **args)
{
    if (i == 1) {
        if (!verif_dir_nb_foor(parse, 65535))
            return (0);
        (*args)[i - 1] = 'd';
    }
    return (1);
}

static int fork_error(char **parse, int i, char **args)
{
    for (; parse[i] != NULL && i < 5; i += 1) {
        if (i > 1)
            return (0);
        if (!(verif_param(parse[i], i, args)))
            return (0);
    }
    if (i != 2)
        return (0);
    return (i);
}

static void fork_add_node(data_t *data, node_t *tmp, char **parse, char *args)
{
    char *hexa = my_memset_char(20);
    char **val_hex = my_memset_dchar(4, 3);
    int nb = 0;

    tmp = add_node(data);
    tmp->args = malloc(sizeof(unsigned char) * 4);
    data->hex_total += 3;
    tmp->size = 3;
    tmp->args[0] = 0xc;
    nb = int_to_bin_to_twos_complement(-my_getnbr(parse[1] + 1), 0);
    int_to_hex(nb, hexa);
    tmp->args = stock_args(tmp, hexa, val_hex, (int [3]){0, 2, 2});
    free(args);
    free(data->have_label);
    free_inst(hexa, val_hex);
}

int fork_instr(data_t *data, char **parse)
{
    int i = 1;
    char *args = my_memset_char(4);
    node_t *tmp = NULL;

    if (!(i = fork_error(parse, i, &args)))
        return (0);
    data->have_label = my_memset_char(my_strlen(parse[1]));
    if (parse[1][1] == LABEL_CHAR) {
        if (!verif_dir_label(data, parse[1], "fork", 2))
            return (0);
    }
    fork_add_node(data, tmp, parse, args);
    return (1);
}