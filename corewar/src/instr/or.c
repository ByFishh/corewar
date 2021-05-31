/*
** EPITECH PROJECT, 2021
** B-CPE-201-NCY-2-1-corewar-antoine.gasser
** File description:
** or
*/

#include "corewar.h"

static int rec_param(champ_t *champion, data_t *data
, coding_bytes_t store, int i)
{
    int tmp = 0;

    for (int nb = 0; nb < store.nb_bytes_param[i]; nb += 1) {
        tmp <<= 8;
        tmp |= data->arena[mod(champion->next_instr, nb)];
    }
    champion->next_instr = mod(champion->next_instr, store.nb_bytes_param[i]);
    return (tmp);
}

void or_mnemonic(champ_t *champion, data_t *data)
{
    int p1 = 0;
    int p2 = 0;
    coding_bytes_t store = {0};

    champion->next_instr = mod(champion->next_instr, 1);
    uncrypt_bytes(data->arena[champion->next_instr], &store);
    if (store.nb_param != 3 || store.param_types[0] == 0
        || store.param_types[1] == 0 || store.param_types[2] != 1)
        return (error_mnemonic(champion, 6));
    champion->next_instr = mod(champion->next_instr, 1);
    p1 = rec_param(champion, data, store, 0);
    p2 = rec_param(champion, data, store, 1);
    if (verif_reg(champion, data) == 1)
        return (error_mnemonic(champion, 6));
    champion->reg[data->arena[champion->next_instr] - 1] = p1 | p2;
    calcul_carry(champion
    , champion->reg[data->arena[champion->next_instr] - 1]);
    champion->next_instr = mod(champion->next_instr, 1);
    champion->cycle += 6;
}