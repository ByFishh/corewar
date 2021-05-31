/*
** EPITECH PROJECT, 2021
** B-CPE-201-NCY-2-1-corewar-antoine.gasser
** File description:
** fork
*/

#include "corewar.h"

int get_new_id(data_t *data)
{
    int tmp = 0;
    champ_t *champ = data->first_champ;

    while (champ != NULL) {
        if (champ->id > tmp)
            tmp = champ->id;
        champ = champ->next;
    }
    return tmp + 1;
}

void fill_new_mob(data_t *data)
{
    champ_t *tmp = data->first_champ;

    for (int i = 0; i != tmp->header->prog_size; i++) {
        data->area[(i + tmp->adress) % MEM_SIZE] = tmp->id + 4;
        data->arena[(i + tmp->adress) % MEM_SIZE] = tmp->bin[i];
    }
}

void fork_mnemonic(champ_t *champion, data_t *data)
{
    unsigned short add = 0;

    champion->next_instr = mod(champion->next_instr, 1);
    add = data->arena[champion->next_instr];
    add <<= 8;
    add |= data->arena[mod(champion->next_instr, 1)];
    add = (champion->next_instr + add % IDX_MOD) % MEM_SIZE;
    add_champ(data, champion->filepath, add, champion->id);
    fill_new_mob(data);
    champion->next_instr = mod(champion->next_instr, 2);
    champion->cycle += 800;
}