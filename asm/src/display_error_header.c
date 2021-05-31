/*
** EPITECH PROJECT, 2021
** display_error_header.c
** File description:
** asm
*/

#include "asm.h"

void display_error_header(data_t *data)
{
    if (data->error_type == ERROR_TOOLONG_COMMENT)
        my_putstr(BOLDCYAN "The comment is too long.\n" RESET);
    if (data->error_type == ERROR_TOOLONG_NAME)
        my_putstr(BOLDCYAN "The name is too long.\n" RESET);
    if (data->error_type == ERROR_NO_NAME_FST_LINE)
        my_putstr(BOLDCYAN "The comment must be just after the name.\n" RESET);
    if (data->error_type == ERROR_MULTI_NAME)
        my_putstr(BOLDCYAN "The name can only be defined once.\n" RESET);
    if (data->error_type == ERROR_MULTI_COMMENT)
        my_putstr(BOLDCYAN "The comment can only be defined once.\n" RESET);
    if (data->error_type == ERROR_NO_COMMENT_AFT_NAME)
        my_putstr(BOLDCYAN "No comment specified.\n" RESET);
    if (data->error_type == ERROR_SYNTAX)
        my_putstr(BOLDCYAN "Syntax error.\n" RESET);
}