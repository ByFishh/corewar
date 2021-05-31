/*
** EPITECH PROJECT, 2021
** B-CPE-201-NCY-2-1-corewar-antoine.gasser
** File description:
** aff
*/

#include "corewar.h"

void aff_mnemonic(champ_t *champion, data_t *data)
{
    coding_bytes_t store = {0};

    champion->next_instr = mod(champion->next_instr, 1);
    uncrypt_bytes(data->arena[champion->next_instr], &store);
    champion->next_instr = mod(champion->next_instr, 1);
    if (store.nb_param != 1 || store.param_types[0] != 1)
        return (error_mnemonic(champion, 2));
    if (data->arena[champion->next_instr] < 1
        || data->arena[champion->next_instr] > 16)
        return (error_mnemonic(champion, 2));
    my_printf("%c"
    , (champion->reg[data->arena[champion->next_instr] - 1] % 256));
    champion->next_instr = mod(champion->next_instr, 1);
    champion->cycle += 2;
}