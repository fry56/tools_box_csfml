/*
** EPITECH PROJECT, 2022
** remove_animation.c
** File description:
** desc
*/

#include <Class/t_class_sprite_animator.h>
#include <Class/t_class_sprite_animation.h>
#include <t_string.h>
#include <t_mem.h>

bool animator_remove_animation(animator *self, char *animation_name)
{
    t_map_node *animation;

    if ((animation = tmap_get(self->map_animation, animation_name)) == NULL)
        return false;
    if (self->played_animation == animation
        || self->default_animation == animation)
        return false;
    return tmap_remove(self->map_animation, animation_name);
}
