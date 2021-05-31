/*
** EPITECH PROJECT, 2021
** display_error.c
** File description:
** asm
*/

#include "asm.h"

static void display_error_start(data_t *data, int line)
{
    my_putstr(BOLDWHITE "asm, ");
    my_putstr(data->av);
    my_putstr(", line ");
    my_put_nbr(line);
    my_putstr(": " RESET);
}

static void modif_nb_line(data_t *data)
{
    if (data->error_type == ERROR_NO_NAME_FST_LINE
        || data->error_type == ERROR_NO_COMMENT_AFT_NAME
        || data->error_type == ERROR_MULTI_COMMENT)
        data->line = data->comment_line;
    if (data->error_type == ERROR_MULTI_NAME
        || data->error_type == ERROR_NO_NAME
        || data->error_type == ERROR_INVALID_LABEL_NAME)
        data->line = data->name_line;
}

static void display_warning_or_empty(data_t *data)
{
    if (data->error_type == 0 && data->line == 0) {
        my_putstr(BOLDWHITE "asm, ");
        my_putstr(data->av);
        my_putstr(": " RESET);
        data->error_type = ERROR_EMPTY_FILE;
        my_putstr(BOLDCYAN "The file is empty.\n" RESET);
        return;
    }
    modif_nb_line(data);
    my_putstr(BOLDWHITE "asm, ");
    my_putstr(data->av);
    my_putstr(", line ");
    my_put_nbr(data->comment_line);
    my_putstr(": ");
    my_putstr(BOLDRED "Warning: ");
    my_putstr(BOLDCYAN "No comment specified\n" RESET);
}

static void display_error_parser(data_t *data)
{
    display_error_start(data, data->line);
    if (data->error_type == ERROR_ARGUMENTS)
        my_putstr(BOLDCYAN
        "The argument given to the instruction is invalid.\n" RESET);
    if (data->error_type == ERROR_INVALID_LABEL_NAME)
        my_putstr(BOLDCYAN "Invalid label name.\n" RESET);
    if (data->error_type == ERROR_NO_INSTRUCTION)
        my_putstr(BOLDCYAN "Invalid instruction.\n" RESET);
    if (data->error_type == ERROR_NO_NAME)
        my_putstr(BOLDCYAN "No name specified.\n" RESET);
    if (data->error_type == ERROR_UNDEFINED_LABEL)
        my_putstr(BOLDCYAN "Undefined label.\n" RESET);
    if (data->error_type == ERROR_MULTI_LABEL)
        my_putstr(BOLDCYAN "Multiple definition of the same label.\n" RESET);
    display_error_header(data);
}

void display_error(data_t *data)
{
    if (data->error_type == NOT_OPEN)
        return;
    if (data->name_line > data->comment_line)
        data->error_type = ERROR_NO_NAME_FST_LINE;
    if ((data->comment == 0 || data->warning_type != 0)
        && data->error_type < 207)
        display_warning_or_empty(data);
    if (data->error_type == 0 || data->error_type == ERROR_EMPTY_FILE)
        return;
    if (data->header.prog_name[0] == '\0') {
        display_error_start(data, data->name_line);
        my_putstr(BOLDCYAN "No name specified.\n" RESET);
        return;
    }
    if (data->header.comment[0] == '\0') {
        display_error_start(data, data->comment_line);
        my_putstr(BOLDCYAN "No comment specified.\n" RESET);
        return;
    }
    display_error_parser(data);
}