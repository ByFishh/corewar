/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** my_swap
*/

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}