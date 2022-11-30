/*
** EPITECH PROJECT, 2022
** use_event.c
** File description:
** desc
*/

#include <Class/t_class_sprite.h>

void sprite_use_event(sprite *self, sfEvent *event_data)
{
    if (self->events_list->length == 0)
        return;
    list_foreach(self->events_list, node) {
        if (((event *)node->value)->type == event_data->type)
            ((event *)node->value)->event_function(self, event_data);
    }
}
