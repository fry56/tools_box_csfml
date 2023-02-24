/*
** EPITECH PROJECT, 2022
** use_event.c
** File description:
** desc
*/

#include <Class/t_sprite.h>

void sprite_use_event(sprite *self, window *window_datas)
{
    if (self->list_event_update_functions->length == 0)
        return;
    list_foreach(self->list_event_update_functions, node) {
        if (((event *)node->value)->type == window_datas->event.type)
            ((event *)node->value)->event_function(self, window_datas);
    }
}
