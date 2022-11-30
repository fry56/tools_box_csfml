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
            ((animation *)animator->played_animation->value)
            ->sprites_sf_texture_list
            , animator->animation_frame)->value;
        sfSprite_setTexture(sprite->sf_sprite
            , animation_frame
            , sfTrue);
    }
}

void clock_update_sprite(t_list *list_sprites, sfClock *clock)
{
    list_foreach(list_sprites, node) {
        update_sprite_animator(((sprite *)node->value), clock);
    }
}

void event_update_sprite(t_list *list_sprites, sfEvent *event_datas)
{
    list_foreach(list_sprites, node) {
        if (((sprite *)node->value)->events_list->length == 0)
            continue;
        sprite_use_event(((sprite *)node->value), event_datas);
    }
}