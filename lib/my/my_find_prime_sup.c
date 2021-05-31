/*
** EPITECH PROJECT, 2020
** my_find_prime_sup
** File description:
** task07
*/

int my_find_prime_sup(int nb)
{
    int temp = 0;
    int count = 2;
    int is_not_prime = 0;

    if (nb == 0 || nb == 1 || nb < 0)
        return (2);
    while (count < nb) {
        temp = nb / count;
        temp = temp * count;
        count++;
        if (temp == nb) {
            is_not_prime = 1;
            break;
        }
    }
    if (is_not_prime == 1)
        nb = my_find_prime_sup(nb + 1);
    return (nb);
}