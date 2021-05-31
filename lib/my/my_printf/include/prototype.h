/*
** EPITECH PROJECT, 2020
** prototype
** File description:
** .h
*/

#ifndef PROTOTYPE
#define PROTOTYPE

typedef struct my_struct my_struct;

int verif_flags(char *str, my_struct *store, int *count);
int verif_width(char *str, my_struct *store, int *subcount);
int verif_precision(char *str, my_struct *store, int *subcount);
int verif_length(char *str, my_struct *store, int *count);
int verif_specifer(char *str, my_struct *store, int *count);
void convert_p(unsigned long p);
void convert(my_struct *store, unsigned int nb);
void convert_hexa(unsigned int nb, int c);
int my_getnbr(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
void my_put_octal(unsigned int nb);
int my_putstr_nprint(char const *str);
int my_put_bin(int nb);
int my_strlen(char const *str);
int my_nbrlen(int nb, int base);
void formater_int(int varg, my_struct *store);
long my_getnbr_long(char const *str);

#endif /* !PROTOTYPE */