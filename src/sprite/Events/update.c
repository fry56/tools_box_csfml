/*
** EPITECH PROJECT, 2022
** update.c
** File description:
** desc
*/

#include <Class/t_class_sprite.h>
#include <stdio.h>
#include <t_list.h>

void update_sprite_animator(sprite *sprite, sfClock *clock)
{
    animator *animator = sprite->animator;
    sfTexture *animation_frame;

    if (sprite->animator == NULL)
        return;
    if (animator->update_frame(animator, clock)) {
        animation_frame = tlist_get(
                ((animation *)animator->played_animation)
                ->sprites_sf_texture_list
                , animator->animation_frame)->value;
        sfSprite_setTexture(sprite->sf_sprite
            , animation_frame
            , sfTrue);
    }
}

void update_sprite(sprite **list_sprites, sfClock *clock)
{
    for (int i = 0; list_sprites[i] != NULL; ++i) {
        update_sprite_animator(list_sprites[i], clock);
    }
}
