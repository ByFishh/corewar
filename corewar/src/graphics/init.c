/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** init
*/

#include "corewar.h"

static sfRenderWindow *init_window(int width, int heigth, char *name)
{
    sfVideoMode mode = {width, heigth, 32};

    return sfRenderWindow_create(mode, name, sfClose, NULL);
}

static int get_pos(int x, int y)
{
    if (x == 0)
        x = 1;
    if (y == 0)
        y = 1;
    return x * y;
}

static sfColor get_color_id(int id)
{
    sfColor tmp;
    sfColor color[9] = {sfWhite, sfGreen, sfBlue
        , sfYellow, sfMagenta, sfColor_fromRGB(0, 119, 13)
        , sfColor_fromRGB(0, 19, 127), sfColor_fromRGB(181, 150, 0)
        , sfColor_fromRGB(81, 0, 119)};

    if (id == -1)
        tmp = sfWhite;
    else
        tmp = color[id];
    return tmp;
}

void set_color(data_t *data)
{
    int x = 0;
    int y = 0;
    sfColor color;

    for (int i = 0; i != SIZE_X * SIZE_Y; i++, x++) {
        if (x == SIZE_X) {
            x = 0;
            y += 1;
        }
        color = get_color_id(data->area[i]);
        sfRectangleShape_setFillColor(data->bonus->arena_tab[y][x], color);
    }
}

void init(data_t *data)
{
    sfVector2f size = {SIZE_SQUARE, SIZE_SQUARE};
    sfVector2f pos = {0, 0};

    data->bonus = malloc(sizeof(bonus_t));
    data->bonus->w = init_window(1920, 1080, "COREWAR");

    for (int i = 0; i != MEM_SIZE; i++)
        data->area[i] = -1;
    for (int i = 0; i != SIZE_Y; i++) {
        for (int j = 0; j != SIZE_X; j++) {
            pos.x = j * SIZE_SQUARE + j * SIZE_INTER + SIZE_SQUARE;
            pos.y = i * SIZE_SQUARE + i * SIZE_INTER + SIZE_SQUARE;
            data->bonus->arena_tab[i][j] = sfRectangleShape_create();
            sfRectangleShape_setSize(data->bonus->arena_tab[i][j], size);
            sfRectangleShape_setFillColor(data->bonus->arena_tab[i][j]
            , sfWhite);
            sfRectangleShape_setPosition(data->bonus->arena_tab[i][j], pos);
        }
    }
    set_color(data);
}