/*
** EPITECH PROJECT, 2022
** destroy.c
** File description:
** desc
*/

#include <Class/t_window.h>
#include <Class/t_sprite.h>
#include <Class/t_text.h>

void window_destroy(window *self)
{
    for (u32 i = 0; i < self->map_scenes->size; ++i) {
        if (self->map_scenes->map[i] == NULL)
            continue;
        scene_destroy(self->map_scenes->map[i]->value);
        list_foreach(self->map_scenes->map[i]->childs_node, node)
            scene_destroy(node->value);
    }
    thashmap_free(self->map_scenes);
    sfClock_destroy(self->global_clock);
    sfRenderWindow_destroy(self->window);
}
