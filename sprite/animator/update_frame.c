/*
** EPITECH PROJECT, 2022
** update_frame.c
** File description:
** desc
*/

#include <Class/t_class_sprite_animator.h>
#include <stdlib.h>

int animator_update_frame(animator *self, sfClock *clock)
{
    sfTime clock_stamp = sfClock_getElapsedTime(clock);

    if (self->nbr_animation == 0 || self->played_animation == NULL)
        return false;
    if (self->last_clock_update
        + (int)(self->played_animation->frame_rate * 100000)
        > clock_stamp.microseconds)
        return false;
    self->last_clock_update = clock_stamp.microseconds;
    if (self->animation_frame == self->played_animation->nbr_sprites - 1) {
        self->animation_frame = 0;
        if (!self->played_animation->loop && self->played_animation != self->default_animation) {
            self->played_animation = self->default_animation;
        }
        return true;
    }
    self->animation_frame++;
    return true;
}
