/*
** EPITECH PROJECT, 2022
** new_animation.c
** File description:
** desc
*/

#include "Class/t_sprite_animation.h"
#include <stdlib.h>
#include <t_list.h>

void init_animation(animation *animation)
{
    animation->sprites_sf_texture_list = tlist_new();
    animation->nbr_sprites = &(animation->sprites_sf_texture_list->length);
    animation->add_sprite = animation_add_sprite;
    animation->set_loop = animation_set_loop;
    animation->set_frame_rate = animation_set_frame_rate;
    animation->destroy = animation_destroy;
}

animation *new_animation(char *name, bool loop, float frame_rate)
{
    animation *new_animation = malloc(sizeof(animation));
    if (new_animation == NULL)
        return NULL;
    new_animation->name = name;
    new_animation->loop = loop;
    new_animation->frame_rate = frame_rate;
    init_animation(new_animation);
    return new_animation;
}
