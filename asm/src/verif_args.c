/*
** EPITECH PROJECT, 2021
** verif_args.c
** File description:
** asm
*/

#include "asm.h"

int verif_dir_nb_foor(char *parse, long limit)
{
    if (my_strlen(parse) < 2)
        return (0);
    if (parse[0] != DIRECT_CHAR)
        return (0);
    if (my_getnbr_long(parse + 1) > limit)
        return (0);
    if (parse[1] == LABEL_CHAR)
        return (1);
    for (int i = 1; parse[i] != '\0'; i++) {
        if (i == 1 && parse[i] == '-')
            continue;
        if (!(parse[i] >= '0' && parse[i] <= '9'))
            return (0);
    }
    return (1);
}

int verif_reg(char *parse)
{
    if (my_strlen(parse) < 2 || my_strlen(parse) > 4)
        return (0);
    if (parse[0] != 'r')
        return (0);
    if (my_getnbr(parse + 1) > REG_NUMBER || my_getnbr(parse + 1) == 0)
        return (0);
    for (int i = 1; parse[i] != '\0'; i++) {
        if (!(parse[i] >= '0' && parse[i] <= '9'))
            return (0);
    }
    return (1);
}

int verif_dir_reg(char *parse, int i, char **args, long limit)
{
    if (verif_reg(parse)) {
        (*args)[i - 1] = 'r';
        return (1);
    }
    if (verif_dir_nb_foor(parse, limit)) {
        (*args)[i - 1] = 'd';
        return (1);
    }
    return (0);
}

static void verif_dir_label_provide_args(node_complete_t *tmp_complete,
data_t *data, int pos_arg)
{
    for (int i = 0; i < 10; i++)
        tmp_complete->arg_nb[i] = 0;
    tmp_complete->arg_nb[pos_arg] = 1;
    tmp_complete->position_node = data->nb_node;
    tmp_complete->position_progr = data->hex_total;
}

int verif_dir_label(data_t *data, char *parse, char *instr, int pos_arg)
{
    node_complete_t *tmp_complete = NULL;

    free(data->have_label);
    data->have_label = my_memset_char(my_strlen(parse) + 1);
    data->have_label = my_strcpy(data->have_label, parse + 2);
    for (int i = 0; data->have_label[i] != '\0'; i++) {
        if (data->have_label[i] == LABEL_CHAR)
            return (0);
    }
    tmp_complete = add_node_complete(data);
    tmp_complete->arg_nb = malloc(sizeof(int) * 10);
    verif_dir_label_provide_args(tmp_complete, data, pos_arg);
    tmp_complete->label = my_memset_char(my_strlen(data->have_label) + 1);
    tmp_complete->label = my_strcpy(tmp_complete->label, data->have_label);
    tmp_complete->instr = my_memset_char(my_strlen(instr) + 1);
    tmp_complete->instr = my_strcpy(tmp_complete->instr, instr);
    tmp_complete->line_pos = data->line;
    return (1);
}