/*
** EPITECH PROJECT, 2022
** add_flag.c
** File description:
** desc
*/

#include "Class/t_sprite.h"
#include <t_string.h>

bool sprite_add_flag(sprite *self, char *flag)
{
    if (sprite_have_flag(self, flag))
        return false;
    tlist_add(self->list_flags, tstr_cpy(NULL, flag));
    return true;
}
