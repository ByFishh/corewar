/*
** EPITECH PROJECT, 2021
** get coding bytes
** File description:
** file 1
*/

#include "corewar.h"

static int get_size_param(unsigned char tmp, int index)
{
    if (tmp == 1)
        return (1);
    if (tmp == 2 && index == 0)
        return (4);
    if (tmp == 2 && index == 1)
        return (2);
    if (tmp == 3)
        return (2);
}

static void fill_store(coding_bytes_t *store, unsigned char tmp, int nb)
{
    if (nb == 1) {
        store->nb_param += 1;
        store->param_types[0] = tmp;
        store->nb_bytes_param[0] = get_size_param(tmp, store->index);
    } if (nb == 2) {
        store->nb_param += 1;
        store->param_types[1] = tmp;
        store->nb_bytes_param[1] = get_size_param(tmp, store->index);
    } if (nb == 3) {
        store->nb_param += 1;
        store->param_types[2] = tmp;
        store->nb_bytes_param[2] = get_size_param(tmp, store->index);
    } if (nb == 4) {
        store->nb_param += 1;
        store->param_types[3] = tmp;
        store->nb_bytes_param[3] = get_size_param(tmp, store->index);
    }
}

void uncrypt_bytes(unsigned char hex, coding_bytes_t *store)
{
    int nb_bytes_param = 0;
    unsigned char tmp = 0;

    tmp = hex >> 6;
    if (tmp > 0)
        fill_store(store, tmp, 1);
    tmp = hex << 2;
    tmp >>= 6;
    if (tmp > 0)
        fill_store(store, tmp, 2);
    tmp = hex << 4;
    tmp >>= 6;
    if (tmp > 0)
        fill_store(store, tmp, 3);
    tmp = hex << 6;
    tmp >>= 6;
    if (tmp > 0)
        fill_store(store, tmp, 4);
}