/*
** EPITECH PROJECT, 2022
** str_cmp.c
** File description:
** desc
*/

#include <tools_box/t_string.h>

static int str_cmpn(char const *str, int n)
{
    int count = 0;
    int value = 0;

    while (str[count] != '\0' && count <= n) {
        value += str[count];
        count++;
    }

    return value;
}

int tstr_cmp(char const *s1, char const *s2)
{
    int value_a = str_cmpn(s1, tstr_len(s1));
    int value_b = str_cmpn(s2, tstr_len(s2));

    return value_a - value_b;
}

int tstr_ncmp(char const *s1, char const *s2, int n)
{
    int value_a = str_cmpn(s1, n);
    int value_b = str_cmpn(s2, n);

    return value_a - value_b;
}
