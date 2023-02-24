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

    bool scene_is_key_bind(scene *self, sfKeyCode key);
    bool scene_add_key_bind(scene *self, sfKeyCode key);
    key_bind *scene_get_key(scene *self, sfKeyCode key);
    tsize_t scene_get_key_press_timestamp(scene *self, sfKeyCode key);
    bool scene_is_key_press(scene *self, sfKeyCode key);
    void scene_update_key(scene *self, window *window_datas);
#endif //t_class_scene
