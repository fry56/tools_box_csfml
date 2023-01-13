/*
** EPITECH PROJECT, 2022
** update_frame.c
** File description:
** desc
*/

#include "Class/t_sprite.h"
#include <stdlib.h>

int animator_update_frame(animator *self, sfClock *clock)
{
    animation *anim;

    if (self->map_animation->node_elements == 0 || self->played_animation == NULL)
        return false;
    anim = self->played_animation->value;
    if (self->last_clock_update
        + (int)(anim->frame_rate * 10000)
        >= sfClock_getElapsedTime(clock).microseconds)
        return false;
    self->last_clock_update = sfClock_getElapsedTime(clock).microseconds;
    if (self->animation_frame >= (*(anim->nbr_sprites) - 1)) {
        self->animation_frame = 0;
        self->callback(self, anim->name);
        if (!anim->loop && self->played_animation != self->default_animation)
            self->played_animation = self->default_animation;
        return true;
    }
    self->animation_frame++;
    return true;
}
