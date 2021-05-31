/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** event
*/

#include "corewar.h"

static void event(data_t *data)
{
    if (data->bonus->e.type == sfEvtClosed)
        sfRenderWindow_close(data->bonus->w);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(data->bonus->w);
}

void graph_event(data_t *data)
{
    if (data->curt_cycle % 200 == 0) {
        display(data);
        sfRenderWindow_display(data->bonus->w);
    }
    while (sfRenderWindow_pollEvent(data->bonus->w, &data->bonus->e))
        event(data);
}