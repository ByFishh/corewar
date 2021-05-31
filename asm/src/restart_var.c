/*
** EPITECH PROJECT, 2021
** restart_var.c
** File description:
** asm
*/

#include "asm.h"

void restart_var(data_t *data)
{
    data->name = 0;
    data->name_line = 0;
    data->comment = 0;
    data->comment_line = 0;
    data->line = 0;
    data->fd = 0;
    data->nb_node = 0;
    data->hex_total = 0;
    data->nb_node_lb = 0;
    data->nb_node_complete = 0;
    data->error_type = 0;
    data->warning_type = 0;
    data->header.magic = 0;
    data->header.prog_size = 0;
}