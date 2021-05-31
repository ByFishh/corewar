/*
** EPITECH PROJECT, 2021
** instr tab
** File description:
** file 1
*/

#include "corewar.h"

void init_ptr(data_t *data)
{
    data->ptr[0] = NULL;
    data->ptr[1] = live_mnemonic;
    data->ptr[2] = ld_mnemonic;
    data->ptr[3] = st_mnemonic;
    data->ptr[4] = add_mnemonic;
    data->ptr[5] = sub_mnemonic;
    data->ptr[6] = and_mnemonic;
    data->ptr[7] = or_mnemonic;
    data->ptr[8] = xor_mnemonic;
    data->ptr[9] = zjmp_mnemonic;
    data->ptr[10] = ldi_mnemonic;
    data->ptr[11] = sti_mnemonic;
    data->ptr[12] = fork_mnemonic;
    data->ptr[13] = lld_mnemonic;
    data->ptr[14] = lldi_mnemonic;
    data->ptr[15] = lfork_mnemonic;
    data->ptr[16] = aff_mnemonic;
}