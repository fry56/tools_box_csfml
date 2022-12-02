/*
** EPITECH PROJECT, 2022
** update.c
** File description:
** desc
*/

#include <Class/t_class_sprite.h>
#include <stdio.h>
#include <t_list.h>
#include <Class/t_class_window.h>

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

void event_update_sprite(t_list *list_sprites, window *window_datas)
{
    int i = 0;
    list_foreach(list_sprites, node) {
        printf("[%d]NBR : %lu \n", i, ((sprite *)node->value)->events_list->length);
        i++;
        if (((sprite *)node->value)->events_list->length > 0)
            sprite_use_event(((sprite *)node->value), window_datas);
    }
}
