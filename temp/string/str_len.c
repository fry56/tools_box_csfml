/*
** EPITECH PROJECT, 2022
** str_len.c
** File description:
** desc
*/

int tstr_len(char const *buffer)
{
    int count = 0;

    while (buffer[count] != '\0')
        count++;
    return count;
}
