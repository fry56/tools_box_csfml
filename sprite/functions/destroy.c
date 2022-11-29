/*
** EPITECH PROJECT, 2022
** destroy.c
** File description:
** desc
*/
#include <Class/t_class_sprite.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

void sprite_destroy(sprite *self)
{
    sfSprite_destroy(self->sf_sprite);
    sfTexture_destroy(self->sf_texture);
    free(self);
}