/*
** EPITECH PROJECT, 2022
** new_animation.c
** File description:
** desc
*/

#include <Class/t_sprite_animation.h>
#include <stdlib.h>

void init_animation(animation *animation)
{
    animation->auto_gen_frame = animation_auto_gen_frame;
    animation->add_frame = animation_add_frame;
    animation->remove_frame = animation_remove_frame;
    animation->set_loop = animation_set_loop;
    animation->set_frame_rate = animation_set_frame_rate;
}

animation *new_animation(char *name, bool loop, float frame_rate)
{
    animation *new_animation = malloc(sizeof(animation));
    if (new_animation == NULL)
        return NULL;
    new_animation->name = name;
    new_animation->loop = loop;
    new_animation->frame_rate = frame_rate;
    new_animation->list_frame_rect = tlist_new();
    init_animation(new_animation);
    return new_animation;
}
