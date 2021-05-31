/*
** EPITECH PROJECT, 2021
** lexer.c
** File description:
** asm
*/

#include "asm.h"

int lexer_call_func(data_t *data, char **parse, int j)
{
    if (data->comment == 1 && data->name == 0) {
        data->error_type = ERROR_NO_NAME_FST_LINE;
        return (0);
    }
    if (data->comment == 0 && data->name == 0) {
        data->error_type = ERROR_NO_NAME;
        return (0);
    }
    return (LEXER_FUNCS[j].type_instruction(data, parse));
}

int function_pointer_loop(data_t *data, char **parse, int i)
{
    for (int j = 0; parse[i] != NULL && LEXER_FUNCS[j].mnemo != NULL; j++) {
        if (my_strncmp(parse[i], LEXER_FUNCS[j].mnemo,
        my_strlen(parse[i])) == 0) {
            return (lexer_call_func(data, parse, j));
        }
    }
    return (-1);
}

int lexer_asm(data_t *data, char **parse)
{
    int ret_val = 0;

    for (int i = 0; i < 5; i++) {
        ret_val = function_pointer_loop(data, parse, i);
        if (data->error_type == 0 && ret_val == 0)
            data->error_type = ERROR_ARGUMENTS;
        if (ret_val != -1)
            return (ret_val);
        data->error_type = ERROR_NO_INSTRUCTION;
        return (0);
    }
    return (0);
}
