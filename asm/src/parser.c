/*
** EPITECH PROJECT, 2021
** parser.c
** File description:
** asm
*/

#include "asm.h"

static void copy_line_parse(char **parse, char *line)
{
    for (int i = 0, j = 0; i < 5 && *line != '\0' && *line != '\n'; ++line,
    j++) {
        if (*line == COMMENT_CHAR)
            break;
        if (*line == SEPARATOR_CHAR || *line == ' ' || *line == '\t') {
            for (; *line == SEPARATOR_CHAR || *line == ' ' || *line == '\t';
            ++line);
            i += 1;
            j = 0;
        }
        if (*line == COMMENT_CHAR)
            break;
        if (i > 4 || *line == '\n' || *line == '\0')
            break;
        if (parse[i] == NULL)
            parse[i] = my_memset_char(my_strlen(line) + 1);
        parse[i][j] = *line;
    }
}

static char **parse_instr(char *line)
{
    char **parse = malloc(sizeof(char *) * 5);

    for (int i = 0; i < 5; i++)
        parse[i] = NULL;
    for (; *line == '\t' || *line == ' '; ++line);
    copy_line_parse(parse, line);
    return (parse);
}

static int loop_call_lexer(data_t *data, char **parse)
{
    for (int i = 0; i < 5; i++) {
        if (parse[i] != NULL && !lexer_asm(data, parse)) {
            return (0);
        } else if (parse[i] != NULL)
            return (1);
    }
    return (1);
}

static int check_loop_call_lexer(char **parse, data_t *data)
{
    int ret_val = 0;

    if (!loop_call_lexer(data, parse)) {
        ret_val = 0;
    } else
        ret_val = 1;
    for (int i = 0; i < 5; i++)
        free(parse[i]);
    free(parse);
    return (ret_val);
}

int lexer_parser_asm(data_t *data, char *line)
{
    char **parse = NULL;
    node_label_t *tmp = NULL;

    data->have_label = 0;
    for (; *line == '\t' || *line == ' '; ++line);
    if (verif_label(line)) {
        if (!label_gestion(data, line))
            return (0);
        tmp = add_node_label(data);
        tmp->hex_position = data->hex_total;
        tmp->label = my_memset_char(my_strlen(line) + 1);
        for (int i = 0; *line != LABEL_CHAR; ++line)
            tmp->label[i++] = *line;
        for (; *line == LABEL_CHAR || *line == ' ' || *line == '\t'; ++line);
    }
    parse = parse_instr(line);
    if (!check_loop_call_lexer(parse, data))
        return (0);
    return (1);
}