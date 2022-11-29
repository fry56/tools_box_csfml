/*
** EPITECH PROJECT, 2022
** play_animation.c
** File description:
** desc
*/

#include <Class/t_class_sprite_animation.h>
#include <Class/t_class_sprite_animator.h>
#include <tools_box/t_string.h>

bool animator_play_animation(animator *self, char *animation_name)
{
    int animation_index;

    if ((animation_index = self->have_animation(self, animation_name)) == -1)
        return false;
    self->animation_frame = 0;
    self->played_animation = self->list_animation[animation_index];
    return true;
}
