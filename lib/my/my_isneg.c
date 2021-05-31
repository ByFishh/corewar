/*
** EPITECH PROJECT, 2020
** my_isneg.c
** File description:
** my_isneg.c
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
        my_putchar('\n');
        return (0);
    } else {
        my_putchar('N');
        my_putchar('\n');
        return (0);
    }
}