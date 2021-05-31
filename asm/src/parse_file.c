/*
** EPITECH PROJECT, 2021
** B-CPE-201-NCY-2-1-corewar-antoine.gasser
** File description:
** write_header
*/

#include "asm.h"

int fill_file_condition(data_t *data, char *buff)
{
    data->line += 1;
    if (my_strcmp(buff, NAME_CMD_STRING) == 0) {
        if (!syntax_error(data, buff, my_strlen(NAME_CMD_STRING)))
            return (0);
        create_name_comment(data->header.prog_name, buff);
        data->name_line = data->line;
        data->name += 1;
    } else if (my_strcmp(buff, COMMENT_CMD_STRING) == 0) {
        if (!syntax_error(data, buff, my_strlen(COMMENT_CMD_STRING)))
            return (0);
        create_name_comment(data->header.comment, buff);
        data->comment_line = data->line;
        data->comment += 1;
    } else {
        if (buff[0] == COMMENT_CHAR)
            return (1);
        if (!lexer_parser_asm(data, buff))
            return (0);
    }
    return (1);
}

int fill_file(data_t *data)
{
    char *buff = NULL;
    size_t len = 0;
    ssize_t read = 0;
    FILE *fp = fopen(data->path, "r");

    while ((read = getline(&buff, &len, fp)) != -1 && data->error_type == 0) {
        if (!fill_file_condition(data, buff))
            break;
    }
    free(buff);
    if (fclose(fp) == -1) {
        my_printf(CANT_CLOSE);
        return (84);
    }
    if (!(complete_jump_fork(data)))
        return (84);
    if (data->name_line > data->comment_line)
        return (84);
    return (0);
}