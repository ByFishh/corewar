/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** task03
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int len;
    int count;

    for (len; dest[len] != '\0'; len++);
    for (count = 0; nb > count && src[count] != '\0'; count++)
        dest[len + count] = src[count];
    dest[len + count] = '\0';
    return (dest);
}