/*
** EPITECH PROJECT, 2022
** t_class_window.h
** File description:
** desc
*/
#ifndef t_class_window
    #define t_class_window

    #include <SFML/Graphics.h>
    #include <t_map.h>
    #include <Class/t_class_scene.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>

    typedef struct window {
        sfVideoMode mode;
        sfRenderWindow *window;
        sfEvent event;
        t_map *scenes_map;
        t_map_node *actual_scene;
        sfClock *global_clock;

        scene *(*new_scene)(struct window *, char *name);
        bool (*set_scene)(struct window *, char *scene_name);
    } window;

    scene *window_new_scene(window *self, char *name);
    bool window_set_scene(window *self, char *scene_name);
    window *new_window(char *name, sfVideoMode mode);
#endif //t_class_window
