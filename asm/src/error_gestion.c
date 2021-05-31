/*
** EPITECH PROJECT, 2021
** error_gestion.c
** File description:
** asm
*/

#include "asm.h"

static int verif_length_header(data_t *data, int i, int length, char *ref)
{
    if (i + 1 > length && my_strcmp(ref, NAME_CMD_STRING) == 0) {
        data->error_type = ERROR_TOOLONG_NAME;
        data->name += 1;
        data->header.prog_name[0] = 'e';
        data->name_line = data->line;
        data->comment += 1;
        data->header.comment[0] = 'e';
        data->comment_line = data->line;
        return (0);
    }
    if (i + 1 > length && my_strcmp(ref, COMMENT_CMD_STRING) == 0) {
        data->error_type = ERROR_TOOLONG_COMMENT;
        data->comment += 1;
        data->header.comment[0] = 'e';
        data->comment_line = data->line;
        return (0);
    }
    return (1);
}

static int verif_character_after_header(data_t *data, char buff, int count)
{
    if (count >= 2 && (buff != '\n' && buff != ' '
    && buff != '\t' && buff != '\0')) {
        data->error_type = ERROR_SYNTAX;
        data->name += 1;
        data->header.prog_name[0] = 'e';
        data->name_line = data->line;
        data->comment += 1;
        data->header.comment[0] = 'e';
        data->comment_line = data->line;
        return (0);
    }
    return (1);
}

static int verif_syntax_header(data_t *data, char *buff, char *ref, int length)
{
    int count = 0;

    if (buff[my_strlen(ref)] == '"') {
        data->error_type = ERROR_SYNTAX;
        return (0);
    }
    for (int i = 0; buff[i] != '\0'; i++) {
        if (!verif_length_header(data, i, length, ref))
            return (0);
        if (!verif_character_after_header(data, buff[i], count))
            return (0);
        if (buff[i] == '"')
            count += 1;
    }
    if (count != 2) {
        data->error_type = ERROR_SYNTAX;
        return (0);
    }
    return (1);
}

int syntax_error(data_t *data, char *buff, int start)
{
    if (data->name > 1) {
        data->error_type = ERROR_MULTI_NAME;
        return (0);
    }
    if (data->comment > 1) {
        data->error_type = ERROR_MULTI_COMMENT;
        return (0);
    }
    if (start == my_strlen(NAME_CMD_STRING)) {
        if (!verif_syntax_header(data, buff, NAME_CMD_STRING,
            PROG_NAME_LENGTH))
            return (0);
    } else {
        if (!verif_syntax_header(data, buff, COMMENT_CMD_STRING,
            COMMENT_LENGTH))
            return (0);
    }
    return (1);
}

int error_utils(void)
{
    my_putstr("Usage: ./asm file_name[.s] ....\n");

    return (84);
}