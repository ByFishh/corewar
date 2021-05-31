/*
** EPITECH PROJECT, 2021
** B-CPE-201-NCY-2-1-corewar-antoine.gasser
** File description:
** my_str_to_word_array
*/

#include "asm.h"

char *my_malloc(int size, char c)
{
    char *tmp = malloc(sizeof(char) * (size));

    for (int i = 0; i != size; i++)
        tmp[i] = c;
    return tmp;
}

int count_word(char separator, char *str)
{
    int word = 0;
    int i = 0;
    int inword = 0;

    while (str[i] != '\0') {
        if (str[i] == separator)
            inword = 0;
        else if (inword == 0) {
            inword = 1;
            word++;
        }
        i++;
    }
    return word;
}

char *get_word(char separator, char *str, char **endptr)
{
    int i = 0;
    int len = 0;
    char *word;

    while (str[i] == separator)
        i++;
    while (str[i + len] != separator && (i + len) < my_strlen(str))
        len++;
    word = my_malloc(len + 1, '\0');
    for (int j = 0; j != len; j++)
        word[j] = str[i + j];
    (*endptr) = (*endptr + i + len);
    return word;
}

char **my_str_to_word_array(char *str, char separator)
{
    int word = count_word(separator, str);
    char **array = malloc(sizeof(char *) * (word + 1));

    for (int i = 0; i != word; i++)
        array[i] = get_word(separator, str, &str);
    array[word] = NULL;
    return array;
}