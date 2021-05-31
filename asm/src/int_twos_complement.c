/*
** EPITECH PROJECT, 2021
** int_twos_complement.c
** File description:
** asm
*/

#include "asm.h"

char *int_to_onescomplement(unsigned int u_nb)
{
    int bin[16] = {0};
    char *onescomplement = my_memset_char(17);

    for (int i = 15; i >= 0; i--) {
        bin[i] = u_nb & 0x1;
        u_nb = u_nb >> 1;
    }
    for (int i = 0; i < 16; i++) {
        if (bin[i] == 0) {
            onescomplement[i] = '1';
        } else if (bin[i] == 1)
            onescomplement[i] = '0';
    }
    onescomplement[16] = '\0';
    return (onescomplement);
}

char *bin_to_twoscomplement(char *onescomplement)
{
    char *twoscomplement = my_memset_char(17);
    int carry = 1;

    for (int i = 15; i >= 0; i--) {
        if (onescomplement[i] == '1' && carry == 1) {
            twoscomplement[i] = '0';
        } else if (onescomplement[i] == '0' && carry == 1) {
            twoscomplement[i] = '1';
            carry = 0;
        } else
            twoscomplement[i] = onescomplement[i];
    }
    twoscomplement[16] = '\0';
    return (twoscomplement);
}

long twoscomplement_to_int(long bin_val)
{
    long hex_val = 0;
    int remainder = 0;
    int coeff = 1;

    while (bin_val != 0) {
        remainder = bin_val % 10;
        hex_val = hex_val + remainder * coeff;
        coeff = coeff * 2;
        bin_val = bin_val / 10;
    }
    return (hex_val);
}

long long my_getnbr_u_long(char const *str)
{
    long long res = 0;
    long nb = 1;
    long count = 0;

    while (str[count] == '-' || str[count] == '+') {
        if (str[count] == '-')
            nb = nb * -1;
        count++;
    }
    while (str[count] >= '0' && str[count] <= '9') {
        res = (res * 10) + (str[count] - 48);
        count++;
    }
    return (res * nb);
}

long int_to_bin_to_twos_complement(long nb, int lg)
{
    char *onescomplement = NULL;
    char *twoscomplement = NULL;
    unsigned long hex_val = 0;

    if (lg == 0) {
        onescomplement = int_to_onescomplement(nb);
        twoscomplement = bin_to_twoscomplement(onescomplement);
        hex_val = twoscomplement_to_int(my_getnbr_long(twoscomplement));
    } else {
        onescomplement = lg_to_onescomplement(nb);
        twoscomplement = bin_to_twoscomplement_lg(onescomplement);
        hex_val = twoscomplement_to_lg(twoscomplement);
    }
    free(onescomplement);
    free(twoscomplement);
    return (hex_val);
}