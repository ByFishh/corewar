/*
** EPITECH PROJECT, 2021
** count_pos_args.c
** File description:
** asm
*/

#include "asm.h"

void count_pos_arg(char **args, int **arg_pos, int i)
{
    (*arg_pos)[0] = 3;
    if ((*args)[i - 1] == 'r')
        (*arg_pos)[i] = (*arg_pos)[i - 1] + 1;
    if ((*args)[i - 1] == 'd')
        (*arg_pos)[i] = (*arg_pos)[i - 1] + 2;
    if ((*args)[i - 1] == 'i')
        (*arg_pos)[i] = (*arg_pos)[i - 1] + 2;
}

void count_pos_arg_noind(char **args, int **arg_pos, int i)
{
    (*arg_pos)[0] = 1;
    if ((*args)[i - 1] == 'r')
        (*arg_pos)[i] = (*arg_pos)[i - 1] + 1;
    if ((*args)[i - 1] == 'd')
        (*arg_pos)[i] = (*arg_pos)[i - 1] + 4;
    if ((*args)[i - 1] == 'i')
        (*arg_pos)[i] = (*arg_pos)[i - 1] + 2;
}