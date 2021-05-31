/*
** EPITECH PROJECT, 2020
** my_compute_square_root
** File description:
** task05
*/

int my_compute_square_root(int nb)
{
    int temp = 0;
    int count = 0;
    int square = 0;

    while (square != nb) {
        temp++;
        count++;
        square = temp * temp;
        if (count > nb)
            return (0);
    }
    return (count);
}