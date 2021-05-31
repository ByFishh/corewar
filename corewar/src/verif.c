/*
** EPITECH PROJECT, 2021
** verif
** File description:
** file 1
*/

#include "corewar.h"

int verif_reg(champ_t *champion, data_t *data)
{
    if (data->arena[champion->next_instr] < 1
        || data->arena[champion->next_instr] > 16)
        return (1);
    return (0);
}