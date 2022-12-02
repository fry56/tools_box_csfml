/*
** EPITECH PROJECT, 2022
** new_sprite.c
** File description:
** desc
*/

#include <Class/t_class_sprite.h>
#include <stdlib.h>
#include <Class/t_class_sprite_animator.h>
#include <t_list.h>

void init_sprite(sprite *sprite)
{
    sprite->animator = NULL;
    sprite->set_pos = sprite_set_pos;
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
}

sprite *new_sprite(scene *scene_datas)
{
    sprite *new_sprite = malloc(sizeof(sprite));
    t_list_node *new_sprite_node;

    if (new_sprite == NULL)
        return NULL;
    if ((new_sprite_node = tlist_add(scene_datas->list_sprites, new_sprite))
        == NULL) {
        free(new_sprite);
        return NULL;
    }
    new_sprite->host = scene_datas;
    new_sprite->sprite_node = new_sprite_node;
    init_sprite(new_sprite);
    return new_sprite;
}
