/*
** EPITECH PROJECT, 2022
** destroy.c
** File description:
** desc
*/

#include <Class/t_class_sprite_animation.h>
#include <stdlib.h>

void animation_destroy(animation *self)
{
    for (int i = 0; i < self->nbr_sprites; ++i) {
        sfTexture_destroy(self->sprites_sfTexture[i]);
    }
    free(self->sprites_sfTexture);
}
