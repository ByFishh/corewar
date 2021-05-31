/*
** EPITECH PROJECT, 2021
** main
** File description:
** file 1
*/

#include "asm.h"

int help(void)
{
    int fd = open("asm/src/help.txt", O_RDONLY);
    char buff[148] = { 0 };

    if (fd == -1)
        return (84);
    if (read(fd, buff, 147) == -1) {
        close(fd);
        return (84);
    }
    my_printf("%s\n", buff);
    close(fd);
    return (0);
}

int main(const int argc, char **argv)
{
    data_t data = {0};
    int ret_value = 0;

    if (argc == 1)
        return (error_utils());
    if (!my_strncmp("-h", argv[1], 1))
        return (help());
    for (int i = 1; i < argc; i++) {
        if (i > 1) {
            display_error(&data);
            free_memory(&data);
        }
        if (multi_champ(&data, argv, i) == 84)
            ret_value = 84;
    }
    if (data.error_type != 0)
        ret_value = 84;
    display_error(&data);
    free_memory(&data);
    return (ret_value);
}