/*
** EPITECH PROJECT, 2022
** add_animation.c
** File description:
** desc
*/

#include <Class/t_class_sprite_animator.h>
#include <Class/t_class_sprite_animation.h>
#include <tools_box/t_string.h>
#include <tools_box/t_mem.h>
#include <stdio.h>

bool animator_add_animation(animator *self, animation *new_animation)
{
    if (self->have_animation(self, new_animation->name) != -1)
        return false;
    self->list_animation = trealloc(self->list_animation
            , self->nbr_animation * sizeof(animation*)
            , (self->nbr_animation + 1) * sizeof(animation*));
    if (self->list_animation == NULL)
        return false;
    self->list_animation[self->nbr_animation] = new_animation;
    self->nbr_animation++;
    return true;
}
