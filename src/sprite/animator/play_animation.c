/*
** EPITECH PROJECT, 2022
** play_animation.c
** File description:
** desc
*/

#include <t_class_sprite_animation.h>
#include <t_class_sprite_animator.h>
#include <t_string.h>

bool animator_play_animation(animator *self, char *animation_name)
{
    t_map_node *animation;

    if ((animation = tmap_get(self->map_animation, animation_name)) == NULL)
        return false;
    self->animation_frame = 0;
    self->played_animation = animation;
    return true;
}
