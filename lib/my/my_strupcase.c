/*
** EPITECH PROJECT, 2020
** my_strupcase
** File description:
** task08
*/

char *my_strupcase(char *str)
{
    for (int count = 0; str[count] != '\0'; count++) {
        if (str[count] <= 'z' && str[count] >= 'a')
            str[count] = str[count] - 32;
    }
    return (str);
}