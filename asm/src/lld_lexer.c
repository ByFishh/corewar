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
        if (!verif_dir_ind(parse, i, args, 65535))
            return (0);
    }
    if (i == 2) {
        if (!verif_reg(parse))
            return (0);
        (*args)[i - 1] = 'r';
    }
    return (1);
}

static int lld_error(char **parse, char **args)
{
    int i = 1;

    for (; parse[i] != NULL && i < 5; i += 1) {
        if (i > 2)
            return (0);
        if (!(verif_param(parse[i], i, args)))
            return (0);
    }
    if (i != 3)
        return (0);
    return (i);
}

static void lld_add_node(data_t *data, char **parse, char *args)
{
    int binary = 0;
    node_t *tmp = NULL;

    tmp = add_node(data);
    binary = coding_byte(tmp, args, 2);
    binary = binary * 100;
    tmp->args = malloc(sizeof(unsigned char) * (tmp->size + 1));
    data->hex_total += tmp->size;
    tmp->args[0] = 0x0d;
    tmp->args[1] = binary_to_dec(binary);
    complete_args(tmp, parse, args, 2);
}

int lld_instr(data_t *data, char **parse)
{
    char *args = my_memset_char(4);

    if (!lld_error(parse, &args))
        return (0);
    if (parse[1][1] == LABEL_CHAR) {
        if (!verif_dir_label(data, parse[1], "lld", 5))
            return (0);
    }
    lld_add_node(data, parse, args);
    free(args);
    return (1);
}