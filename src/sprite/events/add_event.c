/*
** EPITECH PROJECT, 2022
** add_event.c
** File description:
** desc
*/

#include <Class/t_class_sprite.h>
#include <stdlib.h>
#include <Class/t_class_window.h>

bool sprite_add_event(sprite *self, sfEventType type
    , void (*event_function)(sprite *sprite_pointer
    , window *window_datas))
{
    event *new_event = malloc(sizeof(event));

    new_event->type = type;
    new_event->event_function = event_function;
    if (tlist_add(self->events_list, new_event) == NULL) {
        free(new_event);
        return false;
    }
    return true;
}
