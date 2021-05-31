/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** display
*/

#include "corewar.h"

void display(data_t *data)
{
    for (int i = 0; i != SIZE_Y; i++)
        for (int j = 0; j != SIZE_X; j++)
            sfRenderWindow_drawRectangleShape(data->bonus->w
            , data->bonus->arena_tab[i][j], NULL);
    set_color(data);
}