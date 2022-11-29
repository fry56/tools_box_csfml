/*
** EPITECH PROJECT, 2022
** tstring.h
** File description:
** desc
*/
#ifndef TOOLS_BOX_TSTRING_H
    #define TOOLS_BOX_TSTRING_H
    #include "t_ctype.h"
    char *tstr_case_lower(char *str);
    char *tstr_case_upper(char *str);
    int tstr_cmp(char const *s1, char const *s2);
    int tstr_ncmp(char const *s1, char const *s2, int n);
    char *tstr_cpy(char *dest, char const *src);
    char *tstr_ncpy(char *dest, char const *src, int n);
    int tstr_is_alpha(char const *str);
    int tstr_is_lower(char const *str);
    int tstr_is_num(char const *str);
    int tstr_is_printable(char const *str);
    int tstr_is_upper(char const *str);
    int tstr_len(char const *buffer);
    char *tstr_rev(char *str);
    char *tstr_str(char *str, char const *to_find);
    char **tstr_to_word_array(char const *str);
    int str_get_nbr(char const *str);
    bool tstr_contain_only(char *str, char *char_list);
#endif //TOOLS_BOX_TSTRING_H
