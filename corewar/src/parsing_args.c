/*
** EPITECH PROJECT, 2021
** B-CPE-201-NCY-2-1-corewar-antoine.gasser
** File description:
** parsing_args
*/

#include "corewar.h"

static int parsing_dump(data_t *data, char **args, int *i)
{
    if (data->nb_champ >= 4) {
        my_printf(MAX_CHAMP);
        return (84);
    }
    if (my_strcmp(args[*i], "-g\0") == 0) {
        data->g = 1;
        return 42;
    }
    if (my_strcmp(args[*i], "-dump\0") == 0) {
        if (args[*i + 1] == NULL || !my_str_isnum(args[*i + 1])) {
            my_printf(USAGE USAGE2);
            return (84);
        }
        data->nb_cycle = my_getnbr(args[*i + 1]);
        (*i)++;
        return 42;
    }
}

static int parse_n(char **args, int *i, int *n, int *n_val)
{
    if (args[*i + 1] == NULL || !my_str_isnum(args[*i + 1])) {
        my_printf(USAGE USAGE2);
        return (84);
    }
    *n = 1;
    *n_val = my_getnbr(args[*i + 1]);
    if (*n_val < 0) {
        my_printf(INVALID_OPTION);
        return (84);
    }
    if (*n_val > 4) {
        my_printf(N);
        return (84);
    }
    (*i)++;
    return 0;
}

static int parse_a(char **args, int *i, int *a, int *a_val)
{
    if (args[*i + 1] == NULL || !my_str_isnum(args[*i + 1])) {
        my_printf(USAGE USAGE2);
        return (84);
    }
    *a = 1;
    *a_val = my_getnbr(args[*i + 1]);
    if (*a_val < 0) {
        my_printf(INVALID_OPTION);
        return (84);
    }
    (*i)++;
}

static int parsing_args_bis(char **args, parse_t *parse, int *i, data_t *data)
{
    if (!my_strcmp(args[*i], "-n\0")) {
        parse->parsen = parse_n(args, i, &parse->n, &parse->n_val);
        if (parse->parsen == 84)
            return (84);
    } else if (!my_strcmp(args[*i], "-a\0")) {
        parse->parsea = parse_a(args, i, &parse->a, &parse->a_val);
        if (parse->parsea == 84)
            return (84);
    } else {
        if (add_champ(data, args[*i], parse->a_val, parse->n_val) == 84)
            return (84);
        parse->a = -1;
        parse->n = 0;
        parse->a_val = -1;
        parse->n_val = -1;
    }
    return (0);
}

int parsing_args(data_t *data, int arg, char **args)
{
    parse_t parse = { -1, -1, 0, -1, 0, 0, 0};

    for (int i = 1; i != arg; i++) {
        parse.pdump = parsing_dump(data, args, &i);
        if (parse.pdump == 42)
            continue;
        else if (parse.pdump == 84)
            return 84;
        if (parsing_args_bis(args, &parse, &i, data) == 84)
            return 84;
    }
    if (parse.a == 1 || parse.n == 1 || data->nb_champ <= 1) {
        my_printf(USAGE USAGE2);
        return (84);
    }
    fill_id(data);
    fill_cycle(data);
    return (0);
}