/*
** EPITECH PROJECT, 2021
** B-CPE-201-NCY-2-1-corewar-antoine.gasser
** File description:
** arena
*/

#include "corewar.h"

static int fill_champ_no_adress(data_t *data, champ_t *champ, int i)
{
    int size = MEM_SIZE / data->nb_champ;

    champ->adress = i * size;
    for (int j = 0; j != champ->header->prog_size; j++) {
        if (data->area[j + i * size] != -1) {
            my_printf("OVERLAP\n");
            return (84);
        }
        data->area[j + i * size] = champ->id;
        data->arena[j + i * size] = champ->bin[j];
    }
    return (0);
}

static int fill_champ_adress(champ_t *champ, data_t *data)
{
    for (int j = 0; j != champ->header->prog_size; j++) {
        if (data->area[j + champ->adress] != -1) {
            my_printf("OVERLAP1\n");
            return (84);
        }
        data->area[j + champ->adress] = champ->id;
        data->arena[j + champ->adress] = champ->bin[j];
    }
    return (0);
}

static int fill_arena(data_t *data)
{
    champ_t *champ = data->first_champ;
    int size = MEM_SIZE / data->nb_champ;
    int error = 0;

    for (int i = 0; i != MEM_SIZE; i++)
        data->area[i] = -1;
    for (int i = 0; i < data->nb_champ; i++) {
        if (champ->adress == -1) {
            error = fill_champ_no_adress(data, champ, i);
        } else {
            error = fill_champ_adress(champ, data);
        }
        if (error == 84)
            return 84;
        champ->next_instr = champ->adress;
        champ->max_instr = champ->adress + champ->header->prog_size;
        champ = champ->next;
    }
}

int init_arena(data_t *data)
{
    int tot_size = 0;
    champ_t *tmp = data->first_champ;
    data->arena = malloc(sizeof(1) * MEM_SIZE);

    if (data->arena == NULL)
        return (84);
    fill_tmp(tmp, &tot_size);
    if (tot_size > MEM_SIZE) {
        my_printf("OVERLAP\n");
        return (84);
    }
    for (int i = 0; i < MEM_SIZE; i++) {
        data->arena[i] = 0x00;
        data->area[i] = 0;
    }
    if (fill_arena(data) == 84) {
        return (84);
    }
    return (0);
}