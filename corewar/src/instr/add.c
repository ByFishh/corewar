/*
** EPITECH PROJECT, 2021
** B-CPE-201-NCY-2-1-corewar-antoine.gasser
** File description:
** add
*/

#include "corewar.h"

void add_mnemonic(champ_t *champion, data_t *data)
{
    coding_bytes_t store = {0};
    unsigned char p1;
    unsigned char p2;
    unsigned char p3;

    champion->next_instr = mod(champion->next_instr, 1);
    uncrypt_bytes(data->arena[champion->next_instr], &store);
    if (store.nb_param != 3 || store.param_types[0] != 1
        || store.param_types[1] != 1 || store.param_types[2] != 1)
        return (error_mnemonic(champion, 10));
    champion->next_instr = mod(champion->next_instr, 4);
    p1 = data->arena[mod(champion->next_instr, -3)];
    p2 = data->arena[mod(champion->next_instr, -2)];
    p3 = data->arena[mod(champion->next_instr, -1)];
    if (!(p1 >= 1 && p1 <= 16 && p2 >= 1 && p2 <= 16 && p3 >= 1 && p3 <= 16))
        return (error_mnemonic(champion, 10));
    champion->reg[p1 - 1] = champion->reg[p2 - 1] + champion->reg[p3 - 1];
    calcul_carry(champion, champion->reg[p1 - 1]);
    champion->cycle += 10;
}