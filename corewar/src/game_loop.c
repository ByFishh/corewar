/*
** EPITECH PROJECT, 2021
** game_loop
** File description:
** file 1
*/

#include "corewar.h"

static void verif_instr_nb(data_t *data, champ_t *process, char instr)
{
    if (instr <= 0 || instr > 16) {
        process->cycle += 1;
        process->next_instr += 1;
        return;
    }
    data->ptr[data->arena[process->next_instr]](process, data);
}

static void instr_cycle_do(data_t *data, champ_t *process)
{
    if (process->cycle == data->curt_cycle) {
        if (process->next_instr < process->max_instr
            && process->next_instr < MEM_SIZE)
            verif_instr_nb(data, process,
            data->arena[process->next_instr]);
    }
}

static void instr_cycle(data_t *data)
{
    champ_t *process = data->first_champ;

    while (process != NULL) {
        instr_cycle_do(data, process);
        process = process->next;
    }
}

static void cycle_handler(data_t *data)
{
    if (data->nb_cycle == data->curt_cycle) {
        data->nb_cycle_die -= CYCLE_DELTA;
        if (data->nb_cycle_die < data->curt_cycle)
            data->nb_cycle_die = (data->curt_cycle + 1);
        data->nb_cycle += data->curt_cycle;
    }
}

void game_loop(data_t *data)
{
    if (data->g)
        display(data);
    init_ptr(data);
    while (data->stop == 0) {
        if (data->g == 1 && sfRenderWindow_isOpen(data->bonus->w))
            graph_event(data);
        if (data->nb_cycle_die == data->curt_cycle) {
            verif_life(data);
            data->nb_cycle_die += data->curt_cycle;
        }
        cycle_handler(data);
        instr_cycle(data);
        data->curt_cycle += 1;
    }
}