/*
** EPITECH PROJECT, 2020
** my_put_hex
** File description:
** file 1
*/

void my_putchar(char c);

void convert_hexa(unsigned int nb, int c)
{
    if (nb > 9 && nb < 16) {
        nb -= 10;
        if (c == 0)
            my_putchar(nb + 97);
        if (c == 1)
            my_putchar(nb + 65);
    } else if (nb < 10) {
        my_putchar(nb + 48);
    }
    if (nb > 15){
        convert_hexa(nb / 16, c);
        convert_hexa(nb % 16, c);
    }
    return;
}