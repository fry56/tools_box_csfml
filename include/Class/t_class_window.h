/*
** EPITECH PROJECT, 2022
** t_class_window.h
** File description:
** desc
*/
#ifndef t_class_window
    #define t_class_window

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <t_map.h>
    #include <t_list.h>

    typedef struct scene {
        bool is_active;
        struct window *host;
        t_list *list_sprites;
        void (*load)(struct scene *);
        void (*unload)(struct scene *);
    } scene;

    typedef struct window {
        sfVideoMode mode;
        sfRenderWindow *window;
        sfEvent event;
        t_map *scenes_map;
        t_map_node *actual_scene;
        sfClock *global_clock;

        scene *(*new_scene)(struct window *, char *name
                , void (*load)(struct scene *)
                , void (*unload)(struct scene *));
        bool (*change_scene)(struct window *, char *scene_name);
    } window;

    scene *window_new_scene(window *self, char *name
        , void (*load)(struct scene *)
        , void (*unload)(struct scene *));
    bool window_change_scene(window *self, char *scene_name);
    window *new_window(char *name, sfVideoMode mode);
#endif //t_class_window
