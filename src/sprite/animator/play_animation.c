/*
** EPITECH PROJECT, 2022
** play_animation.c
** File description:
** desc
*/

#include <Class/t_sprite_animation.h>
#include <Class/t_sprite_animator.h>

bool animator_play_animation(animator *self, char *animation_name)
{
    t_hashmap_node *animation_node;
    sfIntRect *temp_rect;

    if ((animation_node = thashmap_get(self->map_animation
        , animation_name)) == NULL)
        return false;
    if (self->played_animation == animation_node)
        return false;
    temp_rect = ((animation *)animation_node->value)
        ->list_frame_rect->head->value;
    sfSprite_setOrigin(self->host->sf_sprite
        , (sfVector2f){(float)temp_rect->width / 2
        , (float)temp_rect->height / 2});
    self->animation_frame = 0;
    self->played_animation = animation_node;
    return true;
}
