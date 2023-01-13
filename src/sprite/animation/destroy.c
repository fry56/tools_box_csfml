/*
** EPITECH PROJECT, 2022
** destroy.c
** File description:
** desc
*/

#include <t_class_sprite_animation.h>
#include <stdlib.h>
#include <t_list.h>

void animation_destroy(animation *self)
{
    list_foreach(self->sprites_sf_texture_list, node) {
        sfTexture_destroy(node->value);
    }
    tlist_pop(self->sprites_sf_texture_list);
    self->sprites_sf_texture_list = NULL;
}
