/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    int res = 0;
    int nb = 1;
    int count = 0;

    while (str[count] == '-' || str[count] == '+') {
        if (str[count] == '-')
            nb = nb * -1;
        count++;
    }
    while (str[count] >= '0' && str[count] <= '9') {
        res = (res * 10) + (str[count] - 48);
        count++;
    }
    return (res * nb);
}

long my_getnbr_long(char const *str)
{
    long res = 0;
    long nb = 1;
    long count = 0;

    while (str[count] == '-' || str[count] == '+') {
        if (str[count] == '-')
            nb = nb * -1;
        count++;
    }
    while (str[count] >= '0' && str[count] <= '9') {
        res = (res * 10) + (str[count] - 48);
        count++;
    }
    return (res * nb);
}