/*
** EPITECH PROJECT, 2022
** remove_event_update_function.c
** File description:
** desc
*/

#include <Class/t_class_sprite.h>
#include <Class/t_class_window.h>

bool scene_remove_event_update_function(scene *self
    , void (*event_update_function)(scene *scene_datas, sfClock *clock))
{
    list_foreach(self->list_event_update_functions,node) {
        if (node->value == event_update_function) {
            tlist_remove(self->list_event_update_functions, node);
            return true;
        }
    }
    return false;
}
