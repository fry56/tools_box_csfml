/*
** EPITECH PROJECT, 2022
** calloc.c
** File description:
** desc
*/

#include <tools_box/t_ctype.h>
#include <tools_box/t_mem.h>

void *tcalloc(tsize_t tmem, tsize_t size)
{
    void *pointer = malloc(size * tmem);

    if (pointer)
        tmemset(pointer, 0, size * tmem);
    return pointer;
}
