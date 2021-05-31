/*
** EPITECH PROJECT, 2021
** B-CPE-201-NCY-2-1-corewar-antoine.gasser
** File description:
** create_file
*/

#include "asm.h"

char *stock_argv(char *av)
{
    char *tmp = my_memset_char(my_strlen(av) + 5);

    if (tmp == NULL) {
        my_printf(MALLOC_FAIL);
        return (NULL);
    }
    for (int i = my_strlen(av) - 1, j = 0; i >= 0 && av[i] != '/'; i--, j++)
        tmp[j] = av[i];
    tmp = my_revstr(tmp);
    return (tmp);
}

static char *get_filename(char *file)
{
    char *tmp = my_memset_char(my_strlen(file) + 5);
    int dot_cor = 0;

    if (tmp == NULL) {
        my_printf(MALLOC_FAIL);
        return (NULL);
    }
    for (int i = my_strlen(file) - 1, j = 0; i >= 0 && file[i] != '/';
        i--, j++)
        tmp[j] = file[i];
    tmp = my_revstr(tmp);
    for (dot_cor = my_strlen(tmp); dot_cor >= 0 && tmp[dot_cor] != '.';
    dot_cor--);
    tmp[dot_cor] = '\0';
    tmp = my_strcat(tmp, ".cor");
    return (tmp);
}

void write_assembly(data_t *data)
{
    node_t *tmp = data->first;

    data->header.magic = __builtin_bswap32(COREWAR_EXEC_MAGIC);
    data->header.prog_size = __builtin_bswap32(data->hex_total);
    write(data->fd, &data->header, sizeof(header_t));
    for (int i = 0; i < data->nb_node; i++, tmp = tmp->next)
        write(data->fd, tmp->args,
        (sizeof(unsigned char) * tmp->size));
}

int create_file(char *file, data_t *data)
{
    char *tmp = get_filename(file);

    if (tmp == NULL) {
        my_printf(MALLOC_FAIL);
        return (84);
    }
    if (data->error_type == 0 && data->line == 0) {
        free(tmp);
        return (84);
    }
    data->fd = open(tmp, O_WRONLY | O_CREAT, 00666);
    if (data->fd == -1) {
        data->error_type = NOT_OPEN;
        my_printf(CANT_OPEN);
        return (84);
    }
    write_assembly(data);
    close(data->fd);
    free(tmp);
    return (0);
}