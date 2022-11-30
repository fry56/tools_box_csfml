/*
** EPITECH PROJECT, 2022
** have_animation.c
** File description:
** desc
*/

#include <Class/t_class_sprite_animator.h>
#include <Class/t_class_sprite_animation.h>
#include <tools_box/t_string.h>

t_map_node *animator_have_animation(animator *self, char *animation_name)
{
    t_map_node *animation = tmap_get(self->map_animation, animation_name);
    return animation;
}
