/*
** EPITECH PROJECT, 2020
** my_strcapitalize
** File description:
** task10
*/

char *my_strcapitalize(char *str)
{
    int lock = 0;

    for (int count = 0; str[count] != '\0'; count++) {
        if (str[count] <= 'Z' && str[count] >= 'A')
            str[count] = str[count] + 32;
        if (str[count] <= 'z' && str[count] >= 'a' && lock == 0) {
            str[count] = str[count] - 32;
            lock = 1;
        }
        if (str[count] <= 47 || (str[count] >= 58 && str[count] <= 64)
            || (str[count] >= 91 && str[count] <= 96)
            || str[count] >= 123)
            lock = 0;
        if (str[count] >= '0' && str[count] <= '9')
            lock = 1;
    }
    return (str);
}