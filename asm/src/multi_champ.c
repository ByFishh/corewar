/*
** EPITECH PROJECT, 2021
** multi_champ.c
** File description:
** asm
*/

#include "asm.h"

int multi_champ(data_t *data, char **argv, int i)
{
    data->av = stock_argv(argv[i]);
    if (data->av == NULL)
        return (84);
    if (open_file(data, argv[i]) == 84)
        return (84);
    if (fill_file(data) == 84)
        return (84);
    if (data->error_type == 0 && create_file(argv[i], data) == 84)
        return (84);
    return (0);
}