/*
** EPITECH PROJECT, 2021
** B-CPE-201-NCY-2-1-corewar-antoine.gasser
** File description:
** ldi
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

static int param(champ_t *champion, data_t *data, coding_bytes_t store)
{
    int tmp1 = 0;
    int tmp2 = 0;

    champion->next_instr = mod(champion->next_instr, 1);
    tmp1 = rec_param(champion, data, store, 0);
    tmp2 = rec_param(champion, data, store, 1);
    return (tmp1 + tmp2);
}

void ldi_mnemonic(champ_t *champion, data_t *data)
{
    int tmp = 0;
    int init = champion->next_instr;
    coding_bytes_t store = {0};

    store.index = 1;
    champion->next_instr = mod(champion->next_instr, 1);
    uncrypt_bytes(data->arena[champion->next_instr], &store);
    if (store.nb_param != 3 || store.param_types[0] == 0
        || (store.param_types[1] != 1 && store.param_types[1] != 2)
        || store.param_types[2] != 1)
        return (error_mnemonic(champion, 25));
    tmp = param(champion, data, store);
    if (verif_reg(champion, data) == 1)
        return (error_mnemonic(champion, 25));
    champion->reg[data->arena[champion->next_instr] - 1]
    = data->arena[(init + tmp % IDX_MOD) % MEM_SIZE];
    calcul_carry(champion
    , champion->reg[data->arena[champion->next_instr] - 1]);
    champion->next_instr = mod(champion->next_instr, 1);
    champion->cycle += 25;
}