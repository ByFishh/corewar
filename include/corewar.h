/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** .h
*/

#ifndef COREWAR
#define COREWAR

#include "my.h"
#include "op.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>

#define USAGE "Usage: ./corewar [-g] [-dump cycle_nb] ["
#define USAGE2 "[-a load_addr] [-n prog_nb] prog.cor] ...\n"
#define INVALID_OPTION "Invalid option.\n"
#define N "Enter a number between 1 and 4.\n"
#define MAX_CHAMP "The number of champion load is above the limit.\n"
#define OPEN_FAIL "Error in function open: No such file or directory.\n"
#define READ_FAIL "Error in function read: Read fail.\n"

#define SIZE_X 78
#define SIZE_Y 78
#define SIZE_SQUARE 10
#define SIZE_INTER 1

typedef struct champ_s
{
    int id;
    int max_instr;
    int type;
    int adress;
    int next_instr;
    int carry;
    int reg[REG_NUMBER];
    unsigned char *bin;
    int cycle;
    int live;
    header_t *header;
    struct champ_s *next;
    char *filepath;
}champ_t;

typedef struct bonus_s
{
    sfRectangleShape *arena_tab[SIZE_Y][SIZE_X];
    sfRenderWindow *w;
    sfEvent e;
} bonus_t;

typedef struct param_rac_s
{
    int tmp;
    int init;
}param_rac_t;


typedef struct parse_s
{
    int a;
    int a_val;
    int n;
    int n_val;
    int pdump;
    int parsen;
    int parsea;
} parse_t;

typedef struct data_s
{
    bonus_t *bonus;
    int area[MEM_SIZE];
    unsigned char *arena;
    int curt_cycle;
    int nb_cycle;
    int nb_cycle_die;
    champ_t *first_champ;
    champ_t *last_champ;
    int nb_champ;
    int stop;
    int g;
    void (*ptr[17])(champ_t *champion, struct data_s *data);
}data_t;

typedef struct coding_bytes_s
{
    int index;
    int nb_param;
    int nb_bytes_param[4];
    int param_types[4];
}coding_bytes_t;

int parsing_args(data_t *data, int arg, char **args);
void set_color(data_t *data);
int init_arena(data_t *data);
void init_champ(data_t *data);
champ_t *remove_spe_champ(data_t *data, champ_t *p);
void destroy_corewar(data_t *data);
void game_loop(data_t *data);
void uncrypt_bytes(unsigned char hex, coding_bytes_t *store);
void init_ptr(data_t *data);
void live_mnemonic(champ_t *champion, data_t *data);
void ld_mnemonic(champ_t *champion, data_t *data);
void st_mnemonic(champ_t *champion, data_t *data);
void add_mnemonic(champ_t *champion, data_t *data);
void sub_mnemonic(champ_t *champion, data_t *data);
void and_mnemonic(champ_t *champion, data_t *data);
void or_mnemonic(champ_t *champion, data_t *data);
void xor_mnemonic(champ_t *champion, data_t *data);
void zjmp_mnemonic(champ_t *champion, data_t *data);
void ldi_mnemonic(champ_t *champion, data_t *data);
void sti_mnemonic(champ_t *champion, data_t *data);
void fork_mnemonic(champ_t *champion, data_t *data);
void lld_mnemonic(champ_t *champion, data_t *data);
void lldi_mnemonic(champ_t *champion, data_t *data);
void lfork_mnemonic(champ_t *champion, data_t *data);
void aff_mnemonic(champ_t *champion, data_t *data);
void error_mnemonic(champ_t *champion, int nb_cycle);
void calcul_carry(champ_t *champion, int last_res);
int verif_reg(champ_t *champion, data_t *data);
void fill_new_mob(data_t *data);
int get_new_id(data_t *data);
void verif_life(data_t *data);
void fill_tmp(champ_t *tmp, int *tot_size);

char *get_bin(int fd, champ_t *tmp);
header_t *get_header(int fd, champ_t *tmp);
void fill_id(data_t *data);
void fill_cycle(data_t *data);
int my_open(char *path);
int id_available(data_t *data, int id);
int add_champ(data_t *data, char *name, int a, int n);

int mod(int next, int nb);

char *hex_to_onescomplement(unsigned short u_nb);
char *bin_to_twoscomplement(char *onescomplement);

void display(data_t *data);
void init(data_t *data);
void graph_event(data_t *data);
void free_graph(data_t *data);

#endif