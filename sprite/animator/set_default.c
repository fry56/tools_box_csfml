/*
** EPITECH PROJECT, 2022
** set_default.c
** File description:
** desc
*/

#include <Class/t_class_sprite_animator.h>
#include <Class/t_class_sprite_animation.h>
#include <tools_box/t_string.h>
#include <tools_box/t_mem.h>

bool animator_set_default(animator *self, char *animation_name)
{
    int animation_index;

    if ((animation_index = self->have_animation(self, animation_name)) == -1)
        return false;
    if (self->played_animation == self->list_animation[animation_index]
        || self->default_animation == self->list_animation[animation_index])
        return false;
    free(self->list_animation[animation_index]);
    self->list_animation[animation_index] = NULL;
    self->list_animation = trealloc(self->list_animation
            , self->nbr_animation * sizeof(animation*)
            , (self->nbr_animation - 1) * sizeof(animation*));
    if (self->list_animation == NULL)
        return false;
    self->nbr_animation--;
    return true;
}
