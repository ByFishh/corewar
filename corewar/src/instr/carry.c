/*
** EPITECH PROJECT, 2021
** carry
** File description:
** file 1
*/

#include "corewar.h"

void calcul_carry(champ_t *champion, int last_res)
{
    if (last_res == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
}