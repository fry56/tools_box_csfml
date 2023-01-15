/*
** EPITECH PROJECT, 2022
** new_sprite.c
** File description:
** desc
*/

#include "Class/t_sprite.h"
#include <stdlib.h>
#include "Class/t_sprite_animator.h"
#include "t_list.h"
#include "t_map.h"

void init_sprite(sprite *sprite)
{
    sprite->sf_texture = NULL;
    sprite->animator = NULL;
    sprite->set_pos = sprite_set_pos;
    sprite->set_origin_center = sprite_set_origin_center;
    sprite->set_texture = sprite_set_texture;
    sprite->new_animator = animator_new_animator;
    sprite->destroy = sprite_destroy;
    sprite->use_event = sprite_use_event;
    sprite->remove_event = sprite_remove_event;
    sprite->remove_events_by_type = sprite_remove_events_by_type;
    sprite->add_event = sprite_add_event;
    sprite->is_mouse_over = sprite_is_mouse_over;
    sprite->is_mouse_click = sprite_is_mouse_click;
    sprite->sf_sprite = sfSprite_create();
    sprite->events_list = tlist_new();
    sprite->list_flags = tlist_new();
    sprite->have_flag = sprite_have_flag;
    sprite->add_flag = sprite_add_flag;
    sprite->remove_flag = sprite_remove_flag;
}

t_list_node *z_index_list_add(t_list *list_sprites, sprite *new_sprite
    , int z_index)
{
    list_foreach(list_sprites, node) {
        if (((sprite *)node->value)->z_index > z_index)
            return tlist_add_before(list_sprites, node, new_sprite);
    }
    return tlist_add(list_sprites, new_sprite);
}

sprite *new_sprite(scene *scene_datas, char *texture_path, int z_index)
{
    sprite *new_sprite = malloc(sizeof(sprite));
    t_list_node *new_sprite_node;

    if (new_sprite == NULL)
        return NULL;
    if ((new_sprite_node = z_index_list_add(scene_datas->list_sprites
        , new_sprite, z_index))
        == NULL) {
        free(new_sprite);
        return NULL;
    }
    new_sprite->host = scene_datas;
    new_sprite->sprite_node = new_sprite_node;
    new_sprite->z_index = z_index;
    init_sprite(new_sprite);
    sprite_set_texture(new_sprite, texture_path);
    new_sprite->set_origin_center(new_sprite);
    return new_sprite;
}
