/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** my_strcmp
*/

int my_strcmp(char const *str1, char const *str2)
{
    for (int nb = 0; str2[nb]; nb += 1) {
        if (str1[nb] != str2[nb])
            return (1);
    }
    return (0);
}