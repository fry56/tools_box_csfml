/*
** EPITECH PROJECT, 2022
** new_scene.c
** File description:
** desc
*/

#include <Class/t_class_window.h>
#include <stdlib.h>

scene *window_new_scene(window *self, char *name)
{
    scene *new_scene = malloc(sizeof(scene));
    t_map_node *new_scene_node;

    if (new_scene == NULL)
        return NULL;
    new_scene->list_sprites = tlist_new();
    if (new_scene->list_sprites == NULL) {
        free(new_scene);
        return NULL;
    }
    if ((new_scene_node = tmap_add(self->scenes_map, name, new_scene)) == NULL) {
        free(new_scene->list_sprites);
        free(new_scene);
        return NULL;
    }
    new_scene->host = self;
    if (self->actual_scene == NULL)
        self->actual_scene = new_scene_node;
    return new_scene;
}
