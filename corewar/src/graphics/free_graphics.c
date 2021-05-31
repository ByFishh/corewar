/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** free_graphics
*/

#include "corewar.h"

void free_graph(data_t *data)
{
    for (int i = 0; i != SIZE_Y; i++)
        for (int j = 0; j != SIZE_X; j++)
            sfRectangleShape_destroy(data->bonus->arena_tab[i][j]);
    sfRenderWindow_destroy(data->bonus->w);
    free(data->bonus);
}