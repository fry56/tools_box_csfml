/*
** EPITECH PROJECT, 2022
** add_flag.c
** File description:
** desc
*/

#include <t_class_text.h>

bool text_add_flag(text *self, char *flag)
{
    if (self->have_flag(self, flag))
        return false;
    tlist_add(self->list_flags, flag);
    return true;
}
