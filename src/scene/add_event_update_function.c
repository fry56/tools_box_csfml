/*
** EPITECH PROJECT, 2022
** add_event_update_function.c
** File description:
** desc
*/


#include <Class/t_class_sprite.h>
#include <stdio.h>
#include <Class/t_class_window.h>

bool scene_add_event_update_function(scene *self
    , void (*event_update_function)(scene *scene_datas, sfClock *clock))
{
    if (tlist_add(self->list_event_update_functions
            , event_update_function) == NULL)
        return false;
    return true;
}
