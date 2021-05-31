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
        if (!verif_reg(parse))
            return (0);
        (*args)[i - 1] = 'r';
    }
    return (1);
}

static int aff_error(char **parse, int i, char **args)
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

int aff_instr(data_t *data, char **parse)
{
    int i = 1;
    char *args = my_memset_char(4);
    int binary = 0;
    node_t *tmp = NULL;

    if (!(i = aff_error(parse, i, &args)))
        return (0);
    tmp = add_node(data);
    binary = coding_byte(tmp, args, 1);
    binary = binary * 10000;
    tmp->args = malloc(sizeof(unsigned char) * (tmp->size + 1));
    data->hex_total += tmp->size;
    tmp->args[0] = 0x10;
    tmp->args[1] = binary_to_dec(binary);
    complete_args(tmp, parse, args, 1);
    free(args);
    return (1);
}