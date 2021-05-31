/*
** EPITECH PROJECT, 2021
** sub_lexer.c
** File description:
** asm
*/

#include "asm.h"

static int verif_param(char *parse, int i)
{
    if (i >= 1) {
        if (!verif_reg(parse))
            return (0);
    }
    return (1);
}

static int sub_error(char **parse)
{
    int i = 1;

    for (; parse[i] != NULL && i < 5; i += 1) {
        if (i > 3)
            return (0);
        if (!(verif_param(parse[i], i)))
            return (0);
    }
    if (i != 4)
        return (0);
    return (i);
}

static void sub_instr_basic(node_t *tmp, char **parse)
{
    char *hexa = my_memset_char(20);
    char **val_hex = my_memset_dchar(4, 3);

    int_to_hex(my_getnbr_long(parse[1] + 1), hexa);
    tmp->args = stock_args(tmp, hexa, val_hex, (int [3]){1, 2, 1});
    free_inst(hexa, val_hex);
    val_hex = my_memset_dchar(4, 3);
    hexa = my_memset_char(20);
    int_to_hex(my_getnbr_long(parse[2] + 1), hexa);
    tmp->args = stock_args(tmp, hexa, val_hex, (int [3]){2, 3, 1});
    free_inst(hexa, val_hex);
    val_hex = my_memset_dchar(4, 3);
    hexa = my_memset_char(20);
    int_to_hex(my_getnbr_long(parse[3] + 1), hexa);
    tmp->args = stock_args(tmp, hexa, val_hex, (int [3]){3, 4, 1});
    free_inst(hexa, val_hex);
}

int sub_instr(data_t *data, char **parse)
{
    node_t *tmp = NULL;

    if (!sub_error(parse))
        return (0);
    tmp = add_node(data);
    tmp->args = malloc(sizeof(unsigned char) * 6);
    tmp->args[0] = 0x5;
    tmp->args[1] = 0x54;
    data->hex_total += 5;
    tmp->size = 5;
    sub_instr_basic(tmp, parse);
    return (1);
}