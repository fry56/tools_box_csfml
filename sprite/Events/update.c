/*
** EPITECH PROJECT, 2022
** update.c
** File description:
** desc
*/

#include <Class/t_class_sprite.h>

void update_sprite_animator(sprite *sprite)
{
    animator *animator = sprite->animator;
    if (animator->update_frame(animator)) {
        sfSprite_setTexture(sprite->sf_sprite
            , animator->played_animation->sprites_sfTexture[animator->animation_frame]
            , sfTrue);
    }
}

void update_sprite(sprite **list_sprites)
{
    for (int i = 0; list_sprites[i] != NULL; ++i) {
        update_sprite_animator(list_sprites[i]);
    }
}
