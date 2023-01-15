/*
** EPITECH PROJECT, 2022
** update.c
** File description:
** desc
*/

#include "Class/t_sprite.h"
#include <stdio.h>
#include "t_list.h"
#include "Class/t_window.h"

void update_sprite_animator(sprite *sprite, sfClock *clock)
{
    animator *animator = sprite->animator;
    animation *animation;
    t_list_node *temp_rect;

    if (sprite->animator == NULL)
        return;
    if (animator->update_frame(animator, clock)) {
        animation = animator->played_animation->value;
        if ((temp_rect = tlist_get(animation->list_frame_rect
            , animator->animation_frame)) == NULL)
            return;
        sfSprite_setTextureRect(sprite->sf_sprite
            , *(sfIntRect *)temp_rect->value);
    }
}

void clock_update_sprite(scene *scene_datas, sfClock *clock)
{
    list_foreach(scene_datas->list_sprites, node) {
        update_sprite_animator(((sprite *)node->value), clock);
    }
}

void event_update_sprite(scene *scene_datas, window *window_datas)
{
    list_foreach(scene_datas->list_sprites, node) {
        if (((sprite *)node->value)->events_list->length > 0)
            sprite_use_event(((sprite *)node->value), window_datas);
    }
}
