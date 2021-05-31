/*
** EPITECH PROJECT, 2021
** B-CPE-201-NCY-2-1-corewar-antoine.gasser
** File description:
** lld
*/

#include "corewar.h"

static int rec_param(champ_t *champion, data_t *data, coding_bytes_t store)
{
    int tmp = 0;

    champion->next_instr = mod(champion->next_instr, 1);
    for (int nb = 0; nb < store.nb_bytes_param[0]; nb += 1) {
        tmp <<= 8;
        tmp |= data->arena[mod(champion->next_instr, nb)];
    }
    champion->next_instr = mod(champion->next_instr, store.nb_bytes_param[0]);
    return (tmp);
}

void lld_mnemonic(champ_t *champ, data_t *data)
{
    int tm = 0;
    int init = champ->next_instr;
    coding_bytes_t store = {0};

    champ->next_instr = mod(champ->next_instr, 1);
    uncrypt_bytes(data->arena[champ->next_instr], &store);
    if (store.nb_param != 2 || (store.param_types[0] != 2
        && store.param_types[0] != 3) || store.param_types[1] != 1)
        return (error_mnemonic(champ, 10));
    tm = rec_param(champ, data, store);
    if (verif_reg(champ, data) == 1)
        return (error_mnemonic(champ, 10));
    if (store.param_types[0] == 2)
        champ->reg[data->arena[champ->next_instr] - 1] = data->arena[tm];
    else
        champ->reg[data->arena[champ->next_instr] - 1]
        = data->arena[(init + tm) % MEM_SIZE];
    calcul_carry(champ, champ->reg[data->arena[champ->next_instr] - 1]);
    champ->next_instr = mod(champ->next_instr, 1);
    champ->cycle += 10;
}