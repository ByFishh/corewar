/*
** EPITECH PROJECT, 2021
** header_parser.c
** File description:
** asm
*/

#include "asm.h"

char *modif_case_one(char *buff)
{
    if (*buff >= -88 && *buff <= -86)
        *buff = 'e';
    if (*buff >= -96 && *buff <= -94)
        *buff = 'a';
    if (*buff >= -71 && *buff <= -69)
        *buff = 'u';
    if (*buff == -82)
        *buff = 'i';
    if (*buff == -76)
        *buff = 'o';
    if (*buff == -89)
        *buff = 'c';
    return (buff);
}

char *case_check(char *buff)
{
    if (*buff == -61) {
        ++buff;
        buff = modif_case_one(buff);
        return (buff);
    }
    if (*buff == -59) {
        ++buff;
        if (*buff == -73)
            *buff = 'y';
        return (buff);
    }
    return (buff);
}

void create_name_comment(char *str, char *buff)
{
    while (*buff != '"' && *buff != '\n' && *buff != '\0')
        ++buff;
    ++buff;
    for (int i = 0; *buff != '"' && *buff != '\n' && *buff != '\0'; ++buff)
        str[i++] = *buff;
}