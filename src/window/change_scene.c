/*
** EPITECH PROJECT, 2022
** set_scene.c
** File description:
** desc
*/

#include <t_class_window.h>
#include <stdlib.h>

bool window_change_scene(window *self, char *scene_name)
{
    t_map_node *new_scene = tmap_get(self->scenes_map, scene_name);

    if (new_scene == NULL)
        return false;
    self->actual_scene = new_scene;
    return true;
}
