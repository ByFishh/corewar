/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** get
*/

#include "corewar.h"

char *get_bin(int fd, champ_t *tmp)
{
    unsigned char *buff = malloc(sizeof(char) * (tmp->header->prog_size + 1));

    if (read(fd, buff, tmp->header->prog_size) == -1)
        return (NULL);
    buff[tmp->header->prog_size] = '\0';
    return (buff);
}

header_t *get_header(int fd, champ_t *tmp)
{
    header_t *header = malloc(sizeof(header_t));

    if (read(fd, header, sizeof(header_t)) == -1)
        return (NULL);
    header->magic = __builtin_bswap32(header->magic);
    header->prog_size = __builtin_bswap32(header->prog_size);
    if (header->magic != COREWAR_EXEC_MAGIC) {
        my_printf("Error: Wrong magic number\n");
        return NULL;
    }
    return (header);
}