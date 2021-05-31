/*
** EPITECH PROJECT, 2021
** B-CPE-201-NCY-2-1-corewar-antoine.gasser
** File description:
** zjmp
*/

#include "corewar.h"

void zjmp_mnemonic(champ_t *champion, data_t *data)
{
    unsigned short add = 0;

    champion->next_instr = mod(champion->next_instr, 1);
    add = data->arena[champion->next_instr];
    add <<= 8;
    add |= data->arena[mod(champion->next_instr, 1)];
    if (champion->carry == 1)
        champion->next_instr = add % MEM_SIZE;
    champion->next_instr += 2;
    champion->cycle += 20;
}