/*
** EPITECH PROJECT, 2022
** set_texture.c
** File description:
** desc
*/

#include <stdlib.h>
#include <stdbool.h>
#include "Class/t_sprite.h"
#include <t_assert.h>

bool sprite_set_texture(sprite *self, char *path)
{
    if (self->sf_texture != NULL)
        sfTexture_destroy(self->sf_texture);
    tassert((self->sf_texture = sfTexture_createFromFile(path, NULL)) == NULL);
    sfSprite_setTexture(self->sf_sprite, self->sf_texture, sfTrue);
    sprite_set_origin_center(self);
    return true;
}
