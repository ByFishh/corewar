/*
** EPITECH PROJECT, 2021
** file 1
** File description:
** file 1
*/

#include "corewar.h"

static int nb_type(data_t *data)
{
    champ_t *process = data->first_champ;
    int last = process->id;
    int nb = 1;

    while (process != NULL) {
        if (last != process->id)
            nb += 1;
        process = process->next;
    }
    return (nb);
}

void verif_life(data_t *data)
{
    champ_t *process = data->first_champ;

    while (process != NULL) {
        if (process->live == 0 && data->nb_champ > 1) {
            process = remove_spe_champ(data, process);
            continue;
        }
        process->live = 0;
        process = process->next;
    }
    if (data->nb_champ == 0 || nb_type(data) < 2) {
        if (data->nb_champ == 0)
            my_printf("Nobody win !!! RIP\n");
        if (data->nb_champ == 1)
            my_printf("The player %d (%s) has won.\n"
            , data->first_champ->id, data->first_champ->header->prog_name);
        data->stop = 1;
    }
}