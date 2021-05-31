/*
** EPITECH PROJECT, 2020
** my_nbrlen
** File description:
** my_nbrlen
*/

int my_nbrlen(int nb, int base)
{
    int i = 0;

    if (nb < 0) {
        i += 1;
        nb = nb * - 1;
    }
    for (; nb > 0; i += 1)
        nb = nb / base;
    return (i);
}