/*
** EPITECH PROJECT, 2022
** inti.c
** File description:
** desc
*/

#include <Class/t_window.h>
#include <stdlib.h>
#include <t_assert.h>
#include <t_mem.h>

static void init_window(window *self)
{
    sfRenderWindow_setFramerateLimit(self->window, 60);
    self->map_scenes = thashmap_new(1024);
    self->map_global_datas = thashmap_new(1024);
    self->actual_scene = NULL;
    self->last_tick = 0;
    self->deltatime = 0;
}

window *new_window(char *name, sfVideoMode mode)
{
    window *new_window = tcalloc(1, sizeof(window));

    tassert(new_window == NULL && "New window == NULL");
    new_window->mode = mode;
    tassert((new_window->window = sfRenderWindow_create(mode, name,
        sfClose, NULL)) == NULL && "SFML window == NULL");
    init_window(new_window);
    return new_window;
}
