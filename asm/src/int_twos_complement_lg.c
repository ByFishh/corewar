/*
** EPITECH PROJECT, 2021
** int_twos_complement.c
** File description:
** asm
*/

#include "asm.h"

char *lg_to_onescomplement(long u_nb)
{
    int bin[32] = {0};
    char *onescomplement = my_memset_char(33);

    for (int i = 31; i >= 0; i--) {
        bin[i] = u_nb & 0x1;
        u_nb = u_nb >> 1;
    }
    for (int i = 0; i < 32; i++) {
        if (bin[i] == 0) {
            onescomplement[i] = '1';
        } else if (bin[i] == 1)
            onescomplement[i] = '0';
    }
    onescomplement[32] = '\0';
    return (onescomplement);
}

char *bin_to_twoscomplement_lg(char *onescomplement)
{
    char *twoscomplement = my_memset_char(33);
    int carry = 1;

    for (int i = 31; i >= 0; i--) {
        if (onescomplement[i] == '1' && carry == 1) {
            twoscomplement[i] = '0';
        } else if (onescomplement[i] == '0' && carry == 1) {
            twoscomplement[i] = '1';
            carry = 0;
        } else
            twoscomplement[i] = onescomplement[i];
    }
    twoscomplement[32] = '\0';
    return (twoscomplement);
}

int carry_bin_val(int i, char *bin_val)
{
    int j = 0;

    for (j = 0; j <= i; j++) {
        if (bin_val[i] == '1')
            break;
    }
    if (j == i && bin_val[i] == '0')
        return (0);
    return (1);
}

long twoscomplement_to_lg(char *bin_val)
{
    long hex_val = 0;
    int remainder = 0;
    int coeff = 1;
    int nb = 0;
    int i = my_strlen(bin_val) - 1;

    while (i >= 0) {
        if (!carry_bin_val(i, bin_val))
            break;
        nb = bin_val[i] - '0';
        remainder = nb % 10;
        hex_val = hex_val + remainder * coeff;
        coeff = coeff * 2;
        i--;
    }
    return (hex_val);
}