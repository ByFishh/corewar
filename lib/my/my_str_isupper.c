/*
** EPITECH PROJECT, 2020
** my_str_isupper
** File description:
** task15
*/

int my_str_isupper(char const *str)
{
    for (int count = 0; str[count] != '\0'; count++) {
        if (str[count] > 'Z' || str[count] < 'A')
            return (0);
    }
    return (1);
}