/*
** EPITECH PROJECT, 2022
** destroy.c
** File description:
** desc
*/

#include <t_class_window.h>
#include <t_class_sprite.h>
#include <t_class_text.h>

void clear_sprite(scene *temp)
{
    sprite *temp_sprite;

    list_foreach(temp->list_sprites, node) {
        temp_sprite = node->value;
        temp_sprite->destroy(temp_sprite);
    }
}

void clear_text(scene *temp)
{
    text *temp_text;

    list_foreach(temp->list_texts, node) {
        temp_text = node->value;
        temp_text->destroy(temp_text);
    }
}

void window_destroy(window *self)
{
    map_foreach(self->scenes_map, node) {
        clear_sprite(node->value);
        clear_text(node->value);
    }
    sfClock_destroy(self->global_clock);
    sfRenderWindow_destroy(self->window);
}
