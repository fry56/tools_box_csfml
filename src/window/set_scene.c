/*
** EPITECH PROJECT, 2022
** set_scene.c
** File description:
** desc
*/

#include <Class/t_class_scene.h>
#include <Class/t_class_window.h>
#include <stdlib.h>

bool window_set_scene(window *self, char *scene_name)
{
    t_map_node *scene = tmap_get(self->scenes_map, scene_name);

    if (scene == NULL)
        return false;
    self->actual_scene = scene;
    return true;
}
