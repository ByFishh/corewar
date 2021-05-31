/*
** EPITECH PROJECT, 2021
** B-CPE-201-NCY-2-1-corewar-antoine.gasser
** File description:
** free_memory
*/

#include "asm.h"

void free_node(data_t *data)
{
    node_t *tmp = NULL;
    node_t *list = data->first;

    while (list != NULL) {
        tmp = list;
        list = list->next;
        free(tmp->args);
        free(tmp);
    }
}

void free_node_label(data_t *data)
{
    node_label_t *tmp = NULL;
    node_label_t *list = data->lb_first;

    while (list != NULL) {
        tmp = list;
        list = list->next;
        free(tmp->label);
        free(tmp);
    }
}

void free_node_complete(data_t *data)
{
    node_complete_t *tmp = NULL;
    node_complete_t *list = data->complete_first;

    while (list != NULL) {
        tmp = list;
        list = list->next;
        free(tmp->arg_nb);
        free(tmp->label);
        free(tmp->instr);
        free(tmp);
    }
}

void free_memory(data_t *data)
{
    if (data->path != NULL)
        free(data->path);
    if (data->nb_node > 0)
        free_node(data);
    if (data->nb_node_lb > 0)
        free_node_label(data);
    if (data->nb_node_complete > 0)
        free_node_complete(data);
    if (data->av != NULL)
        free(data->av);
    restart_var(data);
    for (int i = 0; i < PROG_NAME_LENGTH; i++)
        data->header.prog_name[i] = '\0';
    for (int i = 0; i < COMMENT_LENGTH; i++)
        data->header.comment[i] = '\0';
}

void free_inst(char *hexa, char **val_hex)
{
    free(hexa);
    for (int i = 0; i < 4; i++)
        free(val_hex[i]);
    free(val_hex);
}