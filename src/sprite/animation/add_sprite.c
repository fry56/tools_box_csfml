/*
** EPITECH PROJECT, 2022
** add_sprite.c
** File description:
** desc
*/

#include "Class/t_sprite_animation.h"
#include <t_mem.h>
#include <t_list.h>

bool animation_add_sprite(animation *self, char *path)
{
    sfTexture *new_sprite;

    if ((new_sprite = sfTexture_createFromFile(path, NULL)) == NULL)
        return false;
    if (tlist_add(self->sprites_sf_texture_list, new_sprite) == NULL)
        return false;
    return true;
}
