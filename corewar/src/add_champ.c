/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** add_champ
*/

#include "corewar.h"

static int add_val(champ_t *tmp, char *name, int n)
{
    int fd = 0;

    if (tmp->adress > MEM_SIZE)
        tmp->adress = tmp->adress % MEM_SIZE;
    tmp->cycle = 0;
    tmp->max_instr = 0;
    tmp->live = 0;
    fd = my_open(name);
    if (fd < 0) {
        my_printf(OPEN_FAIL);
        return (84);
    }
    tmp->id = n;
    tmp->header = get_header(fd, tmp);
    tmp->bin = get_bin(fd, tmp);
    tmp->next_instr = 0;
    close(fd);
    return 0;
}

static int add_filepath(champ_t *tmp, char *filepath)
{
    tmp->filepath = malloc(sizeof(char) * (my_strlen(filepath) + 1));

    if (tmp->filepath == NULL) {
        my_printf("malloc fail");
        return (84);
    }
    tmp->filepath = my_strcpy(tmp->filepath, filepath);
    tmp->filepath[my_strlen(filepath)] = '\0';

    return (0);
}

int add_champ(data_t *data, char *name, int a, int n)
{
    int fd = 0;
    champ_t *tmp = malloc(sizeof(champ_t));

    if (tmp == NULL)
        return (84);
    tmp->next = data->first_champ;
    data->first_champ = tmp;
    tmp->adress = a;
    if (add_val(tmp, name, n) == 84)
        return 84;
    if (add_filepath(tmp, name) == 84) {
        my_printf("Copy filepath fail\n");
        return (84);
    }
    if (tmp->bin == NULL) {
        my_printf(READ_FAIL);
        return (84);
    }
    data->nb_champ += 1;
    return (0);
}