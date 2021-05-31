/*
** EPITECH PROJECT, 2021
** B-CPE-201-NCY-2-1-corewar-antoine.gasser
** File description:
** st
*/

#include "corewar.h"

static int rec_param(champ_t *champion, data_t *data, coding_bytes_t store)
{
    int tmp = 0;

    champion->next_instr = mod(champion->next_instr, 1);
    for (int nb = 0; nb < store.nb_bytes_param[1]; nb += 1) {
        tmp <<= 8;
        tmp |= data->arena[mod(champion->next_instr, nb)];
    }
    return (tmp);
}

static void param_st(champ_t *champion, data_t *data
, coding_bytes_t store, param_rac_t p)
{
    if (store.param_types[0] == 1)
        champion->reg[p.tmp - 1]
        = champion->reg[data->arena[champion->next_instr] - 1];
    else
        data->arena[(p.init + p.tmp % IDX_MOD) % MEM_SIZE]
        = champion->reg[data->arena[champion->next_instr] - 1];
}

void st_mnemonic(champ_t *champion, data_t *data)
{
    int tmp = 0;
    int init = champion->next_instr;
    coding_bytes_t store = {0};

    champion->next_instr = mod(champion->next_instr, 1);
    uncrypt_bytes(data->arena[champion->next_instr], &store);
    champion->next_instr = mod(champion->next_instr, 1);
    if (store.nb_param != 2 || (store.param_types[1] != 1
        && store.param_types[1] != 3) || store.param_types[0] != 1)
        return (error_mnemonic(champion, 5));
    if (verif_reg(champion, data) == 1)
        return (error_mnemonic(champion, 5));
    tmp = rec_param(champion, data, store);
    if (store.param_types[1] = 1 && (tmp < 1 || tmp > 16))
        return (error_mnemonic(champion, 5));
    param_st(champion, data, store, (param_rac_t){tmp, init});
    champion->next_instr
    = mod(champion->next_instr, store.nb_bytes_param[1] + 1);
    champion->cycle += 5;
}