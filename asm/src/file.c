/*
** EPITECH PROJECT, 2021
** B-CPE-201-NCY-2-1-corewar-antoine.gasser
** File description:
** file
*/

#include "asm.h"

int open_file(data_t *data, char const *file)
{
    FILE *fp = fopen(file, "r");

    data->path = malloc(sizeof(char) * my_strlen(file) + 1);
    data->path[my_strlen(file)] = '\0';
    data->path = my_strcpy(data->path, file);
    if (fp == NULL) {
        data->error_type = NOT_OPEN;
        my_putstr_to_file(CANT_OPEN, 2);
        return (84);
    }
    if (fclose(fp) == -1) {
        my_putstr_to_file(CANT_CLOSE, 2);
        return (84);
    }
    return (0);
}