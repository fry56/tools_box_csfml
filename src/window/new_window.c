/*
** EPITECH PROJECT, 2022
** inti.c
** File description:
** desc
*/

#include <Class/t_window.h>
#include <stdlib.h>

void init_window(window *self)
{
    sfRenderWindow_setFramerateLimit(self->window, 60);
    self->actual_scene = NULL;
    self->last_tick = 0;
    self->deltatime = 0;
    self->new_scene = window_new_scene;
    self->change_scene = window_change_scene;
    self->clock_update = window_clock_update;
    self->event_update = window_event_update;
    self->destroy = window_destroy;
}

window *new_window(char *name, sfVideoMode mode)
{
    window *new_window = malloc(sizeof(window));

    if (new_window == NULL)
        return NULL;
    new_window->mode = mode;
    new_window->window = sfRenderWindow_create(mode, name
        , sfClose, NULL);
    if (!new_window->window) {
        free(new_window);
        return NULL;
    }
    new_window->scenes_map = thashmap_new(1024);
    if (new_window->scenes_map == NULL) {
        sfRenderWindow_destroy(new_window->window);
        free(new_window);
        return NULL;
    }
    init_window(new_window);
    return new_window;
}
