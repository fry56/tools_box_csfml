/*
** EPITECH PROJECT, 2022
** add_sprite.c
** File description:
** desc
*/

#include <Class/t_class_sprite_animation.h>
#include <tools_box/t_mem.h>

bool animation_add_sprite(animation *self, char *path)
{
    sfTexture *new_sprite;

    self->sprites_sfTexture = trealloc(self->sprites_sfTexture
        , (self->nbr_sprites) * sizeof(sfTexture *)
        , (self->nbr_sprites + 1) * sizeof(sfTexture *));
    if (self->sprites_sfTexture == NULL)
        return false;
    if ((new_sprite = sfTexture_createFromFile(path, NULL)) == NULL)
        return false;
    self->sprites_sfTexture[self->nbr_sprites] = new_sprite;
    self->nbr_sprites++;
    return true;
}
