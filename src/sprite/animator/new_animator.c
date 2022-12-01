/*
** EPITECH PROJECT, 2022
** new_animator.c
** File description:
** desc
*/

#include <Class/t_class_sprite_animator.h>
#include <stdlib.h>
#include <t_map.h>

void init_animator(animator *animator)
{
    animator->animation_frame = 0;
    animator->map_animation = tmap_new();
    animator->played_animation = NULL;
    animator->default_animation = NULL;
    animator->last_clock_update = 1000;

    animator->play_animation = animator_play_animation;
    animator->add_animation = animator_add_animation;
    animator->have_animation = animator_have_animation;
    animator->remove_animation = animator_remove_animation;
    animator->update_frame = animator_update_frame;
    animator->set_default = animator_set_default;
}

void animator_new_animator(sprite *self)
{
    animator *new_animator = malloc(sizeof(animator));
    if (new_animator == NULL)
        return;
    init_animator(new_animator);
    self->animator = new_animator;
}
