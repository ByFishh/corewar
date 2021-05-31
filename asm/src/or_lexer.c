/*
** EPITECH PROJECT, 2021
** or_lexer.c
** File description:
** asm
*/

#include "asm.h"

static int verif_param(char *parse, int i, char **args, int **arg_pos)
{
    if (i == 1 || i == 2) {
        if (!verif_dir_reg_ind(parse, i, args, FFFFFFFF))
            return (0);
    }
    if (i == 3) {
        if (!verif_reg(parse))
            return (0);
        (*args)[i - 1] = 'r';
    }
    if (i < 3)
        count_pos_arg_noind(args, arg_pos, i);
    return (1);
}

static int or_error(char **parse, char **args, int **arg_pos)
{
    int i = 1;

    for (; parse[i] != NULL && i < 5; i += 1) {
        if (i > 3)
            return (0);
        if (!(verif_param(parse[i], i, args, arg_pos)))
            return (0);
    }
    if (i != 4)
        return (0);
    return (i);
}

static void or_add_node(data_t *data, char **parse, char *args)
{
    int binary = 0;
    node_t *tmp = NULL;

    tmp = add_node(data);
    binary = coding_byte(tmp, args, 3);
    tmp->args = malloc(sizeof(unsigned char) * (tmp->size + 1));
    data->hex_total += tmp->size;
    tmp->args[0] = 0x7;
    tmp->args[1] = binary_to_dec(binary);
    complete_args(tmp, parse, args, 3);
}

int or_instr(data_t *data, char **parse)
{
    char *args = my_memset_char(4);
    int *arg_pos = my_memset_int(3);

    if (!or_error(parse, &args, &arg_pos))
        return (0);
    if (parse[1][1] == LABEL_CHAR) {
        if (!verif_dir_label(data, parse[1], "or", arg_pos[1]))
            return (0);
    }
    if (parse[2][1] == LABEL_CHAR) {
        if (!verif_dir_label(data, parse[2], "or", arg_pos[2]))
            return (0);
    }
    or_add_node(data, parse, args);
    free(args);
    free(arg_pos);
    return (1);
}