/*
** EPITECH PROJECT, 2020
** my_putstr_error
** File description:
** my_putstr_error
*/

void my_putchar_error(char c);

int my_putstr_error(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar_error(str[i]);
        i++;
    }
    return (0);
}