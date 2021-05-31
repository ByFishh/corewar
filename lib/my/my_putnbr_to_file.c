/*
** EPITECH PROJECT, 2021
** my_putnbr_to_file
** File description:
** file 1
*/

void my_putchar_to_file(char c, int fd);

int my_putnbr_to_file(int nb, int fd)
{
    if (nb < 0) {
        my_putchar_to_file('-', fd);
        nb = nb * - 1;
    }
    if (nb < 10) {
        my_putchar_to_file((nb + 48), fd);
    } else if (nb > 9){
        my_putnbr_to_file(nb / 10, fd);
        my_putnbr_to_file(nb % 10, fd);
    }
    return (0);
}