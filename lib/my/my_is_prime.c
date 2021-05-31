/*
** EPITECH PROJECT, 2020
** my_is_prime
** File description:
** task06
*/

int my_is_prime(int nb)
{
    int temp = 0;
    int count = 2;

    if (nb == 0 || nb == 1 || nb < 0)
        return (0);
    while (count < nb) {
        temp = nb / count;
        temp = temp * count;
        count++;
        if (temp == nb)
            return (0);
    }
    return (1);
}