/*
** EPITECH PROJECT, 2022
** have_animation.c
** File description:
** desc
*/

#include <Class/t_class_sprite_animator.h>
#include <Class/t_class_sprite_animation.h>
#include <tools_box/t_string.h>

int animator_have_animation(animator *self, char *animation_name)
{
    for (int i = 0; i < self->nbr_animation; ++i) {
        if (tstr_cmp(self->list_animation[i]->name, animation_name) != 0)
            continue;
        return i;
    }
    return -1;
}
