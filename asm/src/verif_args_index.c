/*
** EPITECH PROJECT, 2021
** verif_args_type.c
** File description:
** asm
*/

#include "asm.h"

int verif_dir_ind(char *parse, int i, char **args, long limit)
{
    if (verif_dir_nb_foor(parse, limit)) {
        (*args)[i - 1] = 'd';
        return (1);
    }
    if (verif_ind_nb(parse)) {
        (*args)[i - 1] = 'i';
        return (1);
    }
    return (0);
}

int verif_reg_ind(char *parse, int i, char **args)
{
    if (verif_reg(parse)) {
        (*args)[i - 1] = 'r';
        return (1);
    }
    if (verif_ind_nb(parse)) {
        (*args)[i - 1] = 'i';
        return (1);
    }
    return (0);
}

int verif_dir_reg_ind(char *parse, int i, char **args, long limit)
{
    if (verif_reg(parse)) {
        (*args)[i - 1] = 'r';
        return (1);
    }
    if (verif_dir_nb_foor(parse, limit)) {
        (*args)[i - 1] = 'd';
        return (1);
    }
    if (verif_ind_nb(parse)) {
        (*args)[i - 1] = 'i';
        return (1);
    }
    return (0);
}

int verif_ind_nb(char *parse)
{
    if (my_strlen(parse) < 1)
        return (0);
    for (int i = 0; parse[i] != '\0'; i++) {
        if (i == 0 && parse[i] == '-')
            continue;
        if (!(parse[i] >= '0' && parse[i] <= '9'))
            return (0);
    }
    return (1);
}