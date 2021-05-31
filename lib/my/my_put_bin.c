/*
** EPITECH PROJECT, 2020
** my_put_bin
** File description:
** my_put_bin
*/

void my_putchar(char c);

int my_put_bin(int nb)
{
    if (nb < 2) {
        my_putchar(nb + 48);
    } else if (nb > 1){
        my_put_bin(nb / 2);
        my_put_bin(nb % 2);
    }
    return (0);
}