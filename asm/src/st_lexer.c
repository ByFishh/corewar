/*
** EPITECH PROJECT, 2021
** st_lexer.c
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
    if (i == 2) {
        if (!verif_reg_ind(parse, i, args))
            return (0);
    }
    return (1);
}

static int st_error(char **parse, char **args)
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

int st_instr(data_t *data, char **parse)
{
    char *args = my_memset_char(4);
    int binary = 0;
    node_t *tmp = NULL;

    if (!st_error(parse, &args))
        return (0);
    tmp = add_node(data);
    binary = coding_byte(tmp, args, 2);
    binary = binary * 100;
    tmp->args = malloc(sizeof(unsigned char) * (tmp->size + 1));
    data->hex_total += tmp->size;
    tmp->args[0] = 0x03;
    tmp->args[1] = binary_to_dec(binary);
    complete_args(tmp, parse, args, 2);
    free(args);
    return (1);
}