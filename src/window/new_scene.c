/*
** EPITECH PROJECT, 2022
** new_scene.c
** File description:
** desc
*/

#include <Class/t_class_window.h>
#include <stdlib.h>
#include <Class/t_class_scene.h>
#include <Class/t_class_sprite.h>

void init_new_scene(scene *new_scene, void (*load)(struct scene *), void (*unload)(struct scene *))
{
    new_scene->list_clock_update_functions = tlist_new();
    new_scene->list_event_update_functions = tlist_new();
    new_scene->add_clock_update_function
        = scene_add_clock_update_function;
    new_scene->remove_clock_update_function
        = scene_remove_clock_update_function;
    new_scene->add_event_update_function
        = scene_add_event_update_function;
    new_scene->remove_event_update_function
        = scene_remove_event_update_function;
    new_scene->add_event_update_function(new_scene, event_update_sprite);
    new_scene->add_clock_update_function(new_scene, clock_update_sprite);
    new_scene->load = load;
    new_scene->unload = unload;
}

scene *window_new_scene(window *self, char *name
    , void (*load)(struct scene *)
    , void (*unload)(struct scene *))
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
    init_new_scene(new_scene, load, unload);
    return new_scene;
}
