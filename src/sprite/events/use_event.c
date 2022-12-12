/*
** EPITECH PROJECT, 2022
** use_event.c
** File description:
** desc
*/

#include <Class/t_class_sprite.h>

void sprite_use_event(sprite *self, window *window_datas)
{
    if (self->events_list->length == 0)
        return;
    list_foreach(self->events_list, node) {
        if (((event *)node->value)->type == window_datas->event.type)
            ((event *)node->value)->event_function(self, window_datas);
    }
}
