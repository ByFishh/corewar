/*
** EPITECH PROJECT, 2021
** ldi_parser.c
** File description:
** asm
*/

#include "asm.h"

static int verif_param(char *parse, int i, char **args, int **arg_pos)
{
    if (i == 1) {
        if (!verif_dir_reg_ind(parse, i, args, 65535))
            return (0);
    }
    if (i == 2) {
        if (!verif_dir_reg(parse, i, args, 65535))
            return (0);
    }
    if (i == 3) {
        if (!verif_reg(parse))
            return (0);
        (*args)[i - 1] = 'r';
    }
    if (i < 3)
        count_pos_arg(args, arg_pos, i);
    return (1);
}

static int lldi_error(char **parse, char **args, int **arg_pos)
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

static void lldi_add_node(data_t *data, char **parse, char *args)
{
    int binary = 0;
    node_t *tmp = NULL;

    tmp = add_node(data);
    binary = coding_byte_index(tmp, args, 3);
    tmp->args = malloc(sizeof(unsigned char) * (tmp->size + 1));
    data->hex_total += tmp->size;
    tmp->args[0] = 0x0e;
    tmp->args[1] = binary_to_dec(binary);
    complete_args_index(tmp, parse, args, 3);
    free(args);
    free(data->have_label);
}

int lldi_instr(data_t *data, char **parse)
{
    char *args = my_memset_char(4);
    int *arg_pos = my_memset_int(3);

    if (!lldi_error(parse, &args, &arg_pos))
        return (0);
    data->have_label = my_memset_char(my_strlen(parse[1]));
    if (parse[1][1] == LABEL_CHAR) {
        if (!verif_dir_label(data, parse[1], "lldi", arg_pos[0]))
            return (0);
    }
    if (parse[2][1] == LABEL_CHAR) {
        if (!verif_dir_label(data, parse[2], "lldi", arg_pos[1]))
            return (0);
    }
    lldi_add_node(data, parse, args);
    free(arg_pos);
    return (1);
}