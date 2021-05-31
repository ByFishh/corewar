/*
** EPITECH PROJECT, 2021
** B-CPE-201-NCY-2-1-corewar-antoine.gasser
** File description:
** utils
*/

#include "corewar.h"

int id_available(data_t *data, int id)
{
    champ_t *champ = data->first_champ;

    while (champ != NULL) {
        if (champ->id == id)
            return (0);
        champ = champ->next;
    }
    return (1);
}

void fill_tmp(champ_t *tmp, int *tot_size)
{
    while (tmp != NULL) {
        (*tot_size) += tmp->header->prog_size;
        tmp = tmp->next;
    }
}

int my_open(char *path)
{
    int fd = open(path, O_RDONLY);

    return (fd);
}

void error_mnemonic(champ_t *champion, int nb_cycle)
{
    champion->next_instr += 1;
    champion->cycle += nb_cycle;
}

int mod(int next, int nb)
{
    return (next + nb) % MEM_SIZE;
}