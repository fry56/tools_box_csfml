/*
** EPITECH PROJECT, 2022
** add_flag.c
** File description:
** desc
*/


#include <Class/t_class_sprite.h>

bool sprite_add_flag(sprite *self, char *flag)
{
    if (self->have_flag(self, flag))
        return false;
    tlist_add(self->list_flag, flag);
    return true;
}
