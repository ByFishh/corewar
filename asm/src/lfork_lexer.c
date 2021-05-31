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
        if (!(verif_dir_nb_foor(parse, 65535)))
            return (0);
        (*args)[i - 1] = 'd';
    }
    return (1);
}

static int lfork_error(char **parse, char **args)
{
    int i = 1;

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

static void lfork_add_node(data_t *data, node_t *tmp, char **parse, char *args)
{
    tmp = add_node(data);
    tmp->args = malloc(sizeof(unsigned char) * 4);
    data->hex_total += 3;
    tmp->size = 3;
    tmp->args[0] = 0xf;
    complete_args_index(tmp, parse, args, 1);
}

int lfork_instr(data_t *data, char **parse)
{
    char *args = my_memset_char(4);
    node_t *tmp = NULL;

    if (!(lfork_error(parse, &args)))
        return (0);
    data->have_label = my_memset_char(my_strlen(parse[1]));
    if (parse[1][1] == LABEL_CHAR) {
        if (!verif_dir_label(data, parse[1], "lfork", 2))
            return (0);
    }
    lfork_add_node(data, tmp, parse, args);
    free(args);
    return (1);
}