/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** my_put_octal
*/

void my_putchar(char c);

void my_put_octal(unsigned int nb)
{
    if (nb < 8) {
        my_putchar(nb + 48);
    } else if (nb > 7) {
        my_put_octal(nb / 8);
        my_put_octal(nb % 8);
    }
    return;
}