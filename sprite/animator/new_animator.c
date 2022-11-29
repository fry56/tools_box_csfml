/*
** EPITECH PROJECT, 2022
** new_animator.c
** File description:
** desc
*/

#include <Class/t_class_sprite_animator.h>
#include <Class/t_class_sprite_animation.h>
#include <Class/t_class_sprite.h>
#include <stdlib.h>

bool init_animator(animator *animator)
{
    animator->nbr_animation = 0;
    animator->animation_frame = 0;
    animator->list_animation = NULL;
    animator->played_animation = NULL;
    animator->default_animation = NULL;
    animator->last_clock_update = 0;

    animator->play_animation = animator_play_animation;
    animator->add_animation = animator_add_animation;
    animator->have_animation = animator_have_animation;
    animator->remove_animation = animator_remove_animation;
    animator->update_frame = animator_update_frame;
    animator->set_default = animator_set_default;
    return true;
}

void animator_new_animator(struct sprite *self)
{
    animator *new_animator = malloc(sizeof(animator));
    if (new_animator == NULL)
        return;
    init_animator(new_animator);
    self->animator = new_animator;
}
