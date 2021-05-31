/*
** EPITECH PROJECT, 2021
** main
** File description:
** file 1
*/

#include "corewar.h"

static int help(void)
{
    int fd = open("corewar/src/help.txt", O_RDONLY);
    char buff[590] = { 0 };

    if (fd == -1)
        return (84);
    if (read(fd, buff, 589) == -1) {
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

    if (argc == 2 && my_strcmp("-h", argv[1]) == 0)
        return (help());
    if (argc == 1) {
        my_printf(USAGE USAGE2);
        return (84);
    }
    if (parsing_args(&data, argc, argv) == 84)
        return (84);
    if (data.g == 1)
        init(&data);
    if (init_arena(&data) == 84)
        return (84);
    init_champ(&data);
    game_loop(&data);
    if (data.g == 1)
        free_graph(&data);
    destroy_corewar(&data);
    return (0);
}