/*
** EPITECH PROJECT, 2021
** gestion_list.c
** File description:
** asm
*/

#include "asm.h"

node_t *add_node(data_t *data)
{
    node_t *tmp = malloc(sizeof(node_t));

    if (tmp == NULL)
        return NULL;
    tmp->next = NULL;
    if (data->nb_node == 0) {
        data->first = tmp;
        data->last = tmp;
    } else {
        data->last->next = tmp;
        data->last = tmp;
    }
    data->nb_node += 1;
    return (tmp);
}

node_label_t *add_node_label(data_t *data)
{
    node_label_t *tmp = malloc(sizeof(node_label_t));

    if (tmp == NULL)
        return NULL;
    tmp->next = NULL;
    if (data->nb_node_lb == 0) {
        data->lb_first = tmp;
        data->lb_last = tmp;
    } else {
        data->lb_last->next = tmp;
        data->lb_last = tmp;
    }
    data->nb_node_lb += 1;
    return (tmp);
}

node_complete_t *add_node_complete(data_t *data)
{
    node_complete_t *tmp = malloc(sizeof(node_complete_t));

    if (tmp == NULL)
        return NULL;
    tmp->next = NULL;
    if (data->nb_node_complete == 0) {
        data->complete_first = tmp;
        data->complete_last = tmp;
    } else {
        data->complete_last->next = tmp;
        data->complete_last = tmp;
    }
    data->nb_node_complete += 1;
    return (tmp);
}