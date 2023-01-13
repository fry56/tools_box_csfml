/*
** EPITECH PROJECT, 2022
** t_class_scene.h
** File description:
** desc
*/
#ifndef t_class_scene
    #define t_class_scene

    #include "t_window.h"

    bool scene_remove_clock_update_function(scene *self
        , void (*clock_update_function)
        (scene *scene_datas, sfClock *clock));
    bool scene_add_clock_update_function(scene *self
        , void (*clock_update_function)
        (scene *scene_datas, sfClock *clock));
    bool scene_remove_event_update_function(scene *self
        , void (*event_update_function)
        (scene *scene_datas, struct window *));
    bool scene_add_event_update_function(scene *self
        , void (*event_update_function)
        (scene *scene_datas, struct window *));
#endif //t_class_scene
