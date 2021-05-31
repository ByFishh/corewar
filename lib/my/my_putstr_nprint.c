/*
** EPITECH PROJECT, 2020
** my_putstr_nprint
** File description:
** my_putstr_nprint
*/

void my_putchar(char c);

void my_put_octal(unsigned int nb);

int my_get_octal(unsigned int nb)
{
    int res = 0;

    if (nb < 8) {
        res += (nb + 48);
    } else if (nb > 7) {
        my_put_octal(nb / 8);
        my_put_octal(nb % 8);
    }
}

static void my_putstr_nprint_except(char const *str, int i)
{
    if (str[i] >= 100)
        my_putchar((str[i] % 1000) + '0');
}

int my_putstr_nprint(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            my_putstr_nprint_except(str, i);
            my_put_octal(str[i]);
        }
        my_putchar(str[i]);
        i++;
    }
    return (0);
}