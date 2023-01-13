/*
** EPITECH PROJECT, 2022
** remove_event.c
** File description:
** desc
*/

#include "Class/t_sprite.h"

bool sprite_remove_event(sprite *self, tsize_t index)
{
    tsize_t i = 0;

    if (self->events_list->length < index)
        return false;
    list_foreach(self->events_list, node) {
        if (i == index) {
            tlist_remove(self->events_list, node);
            break;
        }
        i++;
    }
    return true;
}

void sprite_remove_events_by_type(sprite *self, sfEvent *event_data)
{
    list_foreach(self->events_list, node) {
        if (((event *)node->value)->type == event_data->type) {
            tlist_remove(self->events_list, node);
        }
    }
}
