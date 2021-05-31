/*
** EPITECH PROJECT, 2021
** B-CPE-201-NCY-2-1-corewar-antoine.gasser
** File description:
** live
*/

#include "corewar.h"

void live_mnemonic(champ_t *champion, data_t *data)
{
    unsigned int live = 0;

    champion->next_instr = mod(champion->next_instr, 1);
    for (int nb = 0; nb < 4; nb += 1) {
        live = live << 8;
        live = live | data->arena[champion->next_instr];
        champion->next_instr = mod(champion->next_instr, 1);
    }
    champion->live = 1;
    my_printf("The player %d (%s) is alive.\n"
    , champion->id, champion->header->prog_name);
    champion->cycle += 10;
}