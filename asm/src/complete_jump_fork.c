/*
** EPITECH PROJECT, 2021
** complete_jump_fork.c
** File description:
** asm
*/

#include "asm.h"

static void check_instr(node_complete_t *tmp_complete, node_t *tmp, int jump,
int pos)
{
    char *hexa = my_memset_char(20);
    char **val_hex = my_memset_dchar(4, 3);

    if (my_strncmp("zjmp", tmp_complete->instr, 4) == 0
    || my_strncmp("fork", tmp_complete->instr, 4) == 0
    || my_strncmp("lfork", tmp_complete->instr, 5) == 0
    || my_strncmp("ldi", tmp_complete->instr, 3) == 0
    || my_strncmp("sti", tmp_complete->instr, 3) == 0
    || my_strncmp("lldi", tmp_complete->instr, 4) == 0) {
        jump = int_to_bin_to_twos_complement(-jump, 0);
        int_to_hex(jump, hexa);
        tmp->args = stock_args(tmp, hexa, val_hex, (int [3]){pos - 2, pos, 2});
    }
    free_inst(hexa, val_hex);
}

static void check_instr_lg(node_complete_t *tmp_complete, node_t *tmp,
long jump, int pos)
{
    long nb = 0;
    unsigned long u_nb = 0;
    char *hexa = my_memset_char(20);
    char **val_hex = my_memset_dchar(4, 3);

    if (my_strncmp("live", tmp_complete->instr, 4) == 0
    || my_strncmp("ld", tmp_complete->instr, 2) == 0
    || my_strncmp("and", tmp_complete->instr, 3) == 0
    || my_strncmp("or", tmp_complete->instr, 2) == 0
    || my_strncmp("xor", tmp_complete->instr, 3) == 0
    || my_strncmp("lld", tmp_complete->instr, 3) == 0) {
        nb = int_to_bin_to_twos_complement(-jump, 1);
        if (nb < 0) {
            u_nb = FFFFFFFF + nb;
            int_to_hex_long(u_nb, hexa);
        } else
            int_to_hex(nb, hexa);
        tmp->args = stock_args(tmp, hexa, val_hex, (int [3]){pos - 4, pos, 4});
    }
    free_inst(hexa, val_hex);
}

static void field_args(data_t *data, node_complete_t *tmp_complete,
node_label_t *tmp_lb)
{
    node_t *tmp = data->first;
    int jump = 0;
    long lg_jump = 0;

    for (int i = 0; i < tmp_complete->position_node; i++, tmp = tmp->next);
    jump = tmp_lb->hex_position - tmp_complete->position_progr;
    lg_jump = tmp_lb->hex_position - tmp_complete->position_progr;
    for (int i = 0; i < 10; i++) {
        if (tmp_complete->arg_nb[i] != 0) {
            check_instr(tmp_complete, tmp, jump, i);
            check_instr_lg(tmp_complete, tmp, lg_jump, i);
        }
    }
}

static int verif_label_list(data_t *data, int i, node_label_t *tmp_lb,
node_complete_t *tmp_complete)
{
    for (i = 0; i < data->nb_node_lb; i++, tmp_lb = tmp_lb->next) {
        if (my_strncmp(tmp_complete->label, tmp_lb->label,
        my_strlen(tmp_complete->label)) == 0) {
            field_args(data, tmp_complete, tmp_lb);
            break;
        }
    }
    return (i);
}

int complete_jump_fork(data_t *data)
{
    int i = 0;
    node_label_t *tmp_lb = data->lb_first;
    node_complete_t *tmp_complete = data->complete_first;

    for (int j = 0; j < data->nb_node_complete; j++,
    tmp_complete = tmp_complete->next) {
        i = verif_label_list(data, i, tmp_lb, tmp_complete);
        if (i == data->nb_node_lb) {
            data->line = tmp_complete->line_pos;
            data->error_type = ERROR_UNDEFINED_LABEL;
            return (0);
        }
        tmp_lb = data->lb_first;
    }
    return (1);
}