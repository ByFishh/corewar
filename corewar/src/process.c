/*
** EPITECH PROJECT, 2021
** process.c
** File description:
** file 1
*/

#include "corewar.h"

static void init_reg(data_t *data)
{
    champ_t *process = data->first_champ;

    while (process != NULL) {
        process->reg[0] = process->id;
        for (int i = 1; i < REG_NUMBER; i++)
            process->reg[i] = 0;
        process = process->next;
    }
}

void init_champ(data_t *data)
{
    champ_t *process = data->first_champ;

    init_reg(data);
    while (process != NULL) {
        process->carry = 0;
        process = process->next;
    }
}