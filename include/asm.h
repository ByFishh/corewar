/*
** EPITECH PROJECT, 2021
** asm
** File description:
** .h
*/

#ifndef ASM
#define ASM

#include "my.h"
#include "op.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define FFFFFFFF 4294967296

#define WARNING_NO_COMMENT 100

#define ERROR_NO_NAME 200
#define ERROR_MULTI_NAME 201
#define ERROR_MULTI_COMMENT 202
#define ERROR_COMMENT_BF_NAME 203
#define ERROR_NO_COMMENT_AFT_NAME 204
#define ERROR_NO_NAME_FST_LINE 205
#define ERROR_NO_COMMENT_SPECIFIED 206
#define ERROR_SYNTAX 207
#define ERROR_ARGUMENTS 209
#define ERROR_UNDEFINED_LABEL 210
#define ERROR_NO_INSTRUCTION 211
#define ERROR_INVALID_LABEL_NAME 212
#define ERROR_EMPTY_FILE 213
#define ERROR_TOOLONG_COMMENT 214
#define ERROR_TOOLONG_NAME 215
#define ERROR_MULTI_LABEL 216
#define NOT_OPEN 300

#define CANT_OPEN "Error: Impossible to open file.\n"
#define CANT_CLOSE "Error: Impossible to close file.\n"
#define CANT_READ "Error: Impossible to read file.\n"
#define MALLOC_FAIL "Error: Malloc failed.\n"

#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLDBLACK "\033[1m\033[30m"
#define BOLDRED "\033[1m\033[31m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDYELLOW "\033[1m\033[33m"
#define BOLDBLUE "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN "\033[1m\033[36m"
#define BOLDWHITE "\033[1m\033[37m"

typedef struct node_t node_t;
struct node_t
{
    int arg_pos;
    int size;
    unsigned char *args;
    node_t *next;
};

typedef struct node_label_t node_label_t;
struct node_label_t
{
    char *label;
    int hex_position;
    node_label_t *next;
};

typedef struct node_complete_t node_complete_t;
struct node_complete_t
{
    int position_node;
    int position_progr;
    int line_pos;
    int *arg_nb;
    char *label;
    char *instr;
    node_complete_t *next;
};

typedef struct data_s {
    char *av;
    int line;
    int fd;
    char *path;
    header_t header;
    int nb_node;
    int hex_total;
    node_t *first;
    node_t *last;
    int nb_node_lb;
    node_label_t *lb_first;
    node_label_t *lb_last;
    int nb_node_complete;
    node_complete_t *complete_first;
    node_complete_t *complete_last;
    char *have_label;
    int error_type;
    int warning_type;
    int name;
    int comment;
    int comment_line;
    int name_line;
} data_t;

int create_file(char *file, data_t *data);
int fill_file(data_t *data);
void free_memory(data_t *data);
int open_file(data_t *data, char const *file);
int lexer_parser_asm(data_t *data, char *line);
char *my_malloc(int size, char c);
char **my_str_to_word_array(char *str, char separator);
node_t *add_node(data_t *data);
node_label_t *add_node_label(data_t *data);
node_complete_t *add_node_complete(data_t *data);
char *get_label(char *line);
int is_label(char *line);
void fill_label(data_t *data, char *line);
int get_size(char **array);
void fill_args(char **array, node_t *tmp, int start);
int lexer_asm(data_t *data, char **parse);
int verif_label(char *line);
void int_to_hex(long dec_nb, char *args);
long hex_to_int(char *hex_nb);
unsigned char *stock_args(node_t *tmp, char *hexa, char **val_hex, int *size);
int verif_reg(char *parse);
int verif_dir_nb_foor(char *parse, long limit);
int verif_ind_nb(char *parse);
int st_instr(data_t *data, char **parse);
void free_inst(char *hexa, char **val_hex);
int verif_dir_reg_ind(char *parse, int i, char **args, long limit);
int binary_to_dec(int binary);
int coding_byte(node_t *tmp, char *args, int nb_args);
int coding_byte_index(node_t *tmp, char *args, int nb_args);
void complete_args(node_t *tmp, char **parse, char *args, int nb_args);
void complete_args_index(node_t *tmp, char **parse, char *args, int nb_args);
int verif_dir_reg(char *parse, int i, char **args, long limit);
int verif_dir_ind(char *parse, int i, char **args, long limit);
int verif_reg_ind(char *parse, int i, char **args);
long int_to_bin_to_twos_complement(long nb, int lg);
int complete_jump_fork(data_t *data);
int verif_dir_label(data_t *data, char *parse, char *instr, int pos_arg);
void count_pos_arg(char **args, int **arg_pos, int i);
long twoscomplement_to_lg(char *bin_val);
char *bin_to_twoscomplement_lg(char *onescomplement);
char *lg_to_onescomplement(long u_nb);
void int_to_hex_long(unsigned long dec_nb, char *args);
void count_pos_arg_noind(char **args, int **arg_pos, int i);
void create_name_comment(char *str, char *buff);
int error_utils(void);
char *stock_argv(char *av);
void display_error(data_t *data);
int syntax_error(data_t *data, char *buff, int start);
int label_gestion(data_t *data, char *line);
void restart_var(data_t *data);
int starter_count(char *parse);
void refresh_var_complete(char ***val_hex, char **hexa);
int multi_champ(data_t *data, char **argv, int i);
void display_error_header(data_t *data);

int live_instr(data_t *data, char **parse);
int ld_instr(data_t *data, char **parse);
int st_instr(data_t *data, char **parse);
int add_instr(data_t *data, char **parse);
int sub_instr(data_t *data, char **parse);
int and_instr(data_t *data, char **parse);
int or_instr(data_t *data, char **parse);
int xor_instr(data_t *data, char **parse);
int zjmp_instr(data_t *data, char **parse);
int ldi_instr(data_t *data, char **parse);
int sti_instr(data_t *data, char **parse);
int fork_instr(data_t *data, char **parse);
int lld_instr(data_t *data, char **parse);
int lldi_instr(data_t *data, char **parse);
int lfork_instr(data_t *data, char **parse);
int aff_instr(data_t *data, char **parse);

struct lexer {
    char *mnemo;
    int (*type_instruction)(data_t *data, char **parse);
};

static const struct lexer LEXER_FUNCS[] = {
    {"live", &live_instr},
    {"ld", &ld_instr},
    {"st", &st_instr},
    {"add", &add_instr},
    {"sub", &sub_instr},
    {"and", &and_instr},
    {"or", &or_instr},
    {"xor", &xor_instr},
    {"zjmp", &zjmp_instr},
    {"ldi", &ldi_instr},
    {"sti", &sti_instr},
    {"fork", &fork_instr},
    {"lld", &lld_instr},
    {"lldi", &lldi_instr},
    {"lfork", &lfork_instr},
    {"aff", &aff_instr},
    {NULL, NULL}
};

#endif