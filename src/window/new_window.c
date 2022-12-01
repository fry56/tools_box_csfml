/*
** EPITECH PROJECT, 2022
** inti.c
** File description:
** desc
*/

#include <Class/t_class_window.h>
#include <stdlib.h>

void init_window(window *self)
{
    self->actual_scene = NULL;
    self->new_scene = window_new_scene;
    self->load_scene = window_load_scene;
}

window *new_window(char *name, sfVideoMode mode)
{
    window *new_window = malloc(sizeof(window));

    if (new_window == NULL)
        return NULL;
    new_window->mode = mode;
    new_window->window = sfRenderWindow_create(mode, name
        , sfResize | sfClose, NULL);
    if (!new_window->window) {
        free(new_window);
        return NULL;
    }
    new_window->scenes_map = tmap_new();
    if (new_window->scenes_map == NULL) {
        sfRenderWindow_destroy(new_window->window);
        free(new_window);
        return NULL;
    }
    init_window(new_window);
    return new_window;
}
