/*
** EPITECH PROJECT, 2022
** update_frame.c
** File description:
** desc
*/

#include <Class/t_class_sprite_animator.h>
#include <stdlib.h>

int animator_update_frame(animator *self)
{
    if (self->map_animation->length == 0 || self->played_animation == NULL)
        return false;
    if (self->animation_frame >= ((animation *)self->played_animation->value)->nbr_sprites) {
        self->animation_frame = 0;
        if (!((animation *)self->played_animation->value)->loop
            && self->played_animation != self->default_animation) {
            self->played_animation = self->default_animation;
        }
        return true;
    }
    self->animation_frame++;
    return true;
}
