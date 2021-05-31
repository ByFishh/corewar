/*
** EPITECH PROJECT, 2021
** destroy_champ
** File description:
** file 1
*/

#include "corewar.h"

static void free_champ(champ_t *p)
{
    free(p->bin);
    free(p->header);
    free(p->filepath);
    free(p);
}

champ_t *remove_spe_champ(data_t *data, champ_t *p)
{
    champ_t *tmp = data->first_champ;
    champ_t *next = NULL;

    if (tmp == p) {
        data->first_champ = tmp->next;
        data->nb_champ -= 1;
        next = p->next;
        free_champ(p);
        return (next);
    }
    for (int nb = 0; nb < data->nb_champ; nb += 1) {
        if (tmp->next == p) {
            tmp->next = tmp->next->next;
            data->nb_champ -= 1;
            next = p->next;
            free_champ(p);
        }
        tmp = tmp->next;
    }
    return (next);
}

static void remove_first_champ(champ_t *champ, data_t *data)
{
    data->first_champ = champ->next;
    free_champ(champ);
    data->nb_champ -= 1;
}

void destroy_corewar(data_t *data)
{
    while (data->nb_champ != 0)
        remove_first_champ(data->first_champ, data);
    free(data->arena);
}