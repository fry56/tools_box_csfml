/*
** EPITECH PROJECT, 2022
** new_animation.c
** File description:
** desc
*/

#include <Class/t_class_sprite_animation.h>
#include <stdlib.h>

void init_animation(animation *animation)
{
    animation->sprites_sfTexture = NULL;
    animation->nbr_sprites = 0;
    animation->add_sprite = animation_add_sprite;
}

animation *new_animation(char *name, bool loop, float frame_rate)
{
    animation *new_animation = malloc(sizeof(animation*));
    if (new_animation == NULL)
        return NULL;
    new_animation->name = name;
    new_animation->loop = loop;
    new_animation->frame_rate = frame_rate;
    init_animation(new_animation);
    return new_animation;
}
