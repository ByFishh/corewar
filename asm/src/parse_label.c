/*
** EPITECH PROJECT, 2021
** parse_label.c
** File description:
** asm
*/

#include "asm.h"

static int invalid_name_label(data_t *data, int check_lb)
{
    if (check_lb == 0) {
        data->error_type = ERROR_INVALID_LABEL_NAME;
        return (0);
    }
    return (1);
}

static int check_lb_valide(int check_lb, char *line)
{
    for (int j = 0; LABEL_CHARS[j] != '\0'; j++) {
        if (*line == LABEL_CHARS[j])
            check_lb = 1;
    }
    return (check_lb);
}

static int label_exist(data_t *data, char *line)
{
    node_label_t *tmp = data->lb_first;

    for (int i = 0; i < data->nb_node_lb - 1; i++, tmp = tmp->next) {
        if (my_strncmp(tmp->label, line, my_strlen(line)) == 0) {
            data->error_type = ERROR_MULTI_LABEL;
            return (0);
        }
    }
    return (1);
}

int label_gestion(data_t *data, char *line)
{
    int check_lb = 0;
    node_label_t *tmp = NULL;

    tmp = add_node_label(data);
    tmp->hex_position = data->hex_total;
    tmp->label = my_memset_char(my_strlen(line) + 1);
    for (int i = 0; line[i] != LABEL_CHAR; i++) {
        check_lb = check_lb_valide(check_lb, line);
        if (!invalid_name_label(data, check_lb))
            return (0);
        check_lb = 0;
    }
    for (int i = 0; *line != LABEL_CHAR; ++line)
        tmp->label[i++] = *line;
    for (; *line == LABEL_CHAR || *line == ' ' || *line == '\t'; ++line);
    if (!label_exist(data, tmp->label))
        return (0);
    return (1);
}

int verif_label(char *line)
{
    int i = 0;

    for (; line[i] != '\0' && line[i] != LABEL_CHAR && line[i] != ' '
    && line[i] != '\t'; i++);
    if (line[i] == LABEL_CHAR)
        return (1);
    return (0);
}