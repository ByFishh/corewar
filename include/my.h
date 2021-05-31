/*
** EPITECH PROJECT, 2020
** my
** File description:
** .h
*/

#ifndef MY_LIB
#define MY_LIB

int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_isneg(int n);
int my_is_prime(int nb);
void my_putchar(char c);
void my_putchar_error(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_putstr_error(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
char *my_strcapitalize(char *str);
void my_sort_int_array(int *tab, int size);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
int my_compute_power_rec(int nb, int p);
void print_p(long long nb);
int my_put_bin(int nb);
void convert_hexa(unsigned int nb, int c);
void my_put_octal(unsigned int nb);
int my_nbrlen(int nb, int base);
char *my_strcpy_after_n(char *dest, char *src, int n);
int my_printf(char *str, ...);
void my_putchar_to_file(char c, int fd);
void my_putstr_to_file(char *str, int fd);
int my_putnbr_to_file(int nb, int fd);
char *my_strdup(const char *src);
char *my_memset_char(int size);
char **my_memset_dchar(int size1, int size2);
int *my_memset_int(int size);
long my_getnbr_long(char const *str);
char *my_getstr(long nb);

#endif /* !MY_LIB */
