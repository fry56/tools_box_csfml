/*
** EPITECH PROJECT, 2022
** add_clock_update_function.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <stdio.h>
#include <Class/t_window.h>

void scene_add_clock_update_function(scene *self
    , void (*clock_update_function)(scene *scene_datas, sfClock *clock))
{
    tlist_add(self->list_clock_update_functions, clock_update_function);
}
