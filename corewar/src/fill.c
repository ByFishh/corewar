/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** fill
*/

#include "corewar.h"

static void fill_id_cmp(data_t *data, champ_t *champ, int *i)
{
    if (champ->id == -1) {
        while (id_available(data, (*i)) == 0)
            (*i)--;
        champ->id = (*i);
    } else
        (*i)++;
}

void fill_id(data_t *data)
{
    champ_t *champ = data->first_champ;

    for (int i = data->nb_champ; champ != NULL; i--) {
        while (id_available(data, i) == 0)
            i--;
        fill_id_cmp(data, champ, &i);
        champ = champ->next;
    }
}

void fill_cycle(data_t *data)
{
    data->curt_cycle = 0;
    if (data->nb_cycle == 0)
        data->nb_cycle = NBR_LIVE;
    data->nb_cycle_die = CYCLE_TO_DIE;
}