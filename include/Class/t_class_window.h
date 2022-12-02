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
        t_list *list_clock_update_functions;
        t_list *list_event_update_functions;
        t_map *map_datas;

        bool (*add_clock_update_function)(struct scene *
            , void (*clock_update_function)
            (struct scene *scene_datas, sfClock *clock));
        bool (*remove_clock_update_function)(struct scene *
            , void (*clock_update_function)
            (struct scene *scene_datas, sfClock *clock));

        bool (*add_event_update_function)(struct scene *
            , void (*event_update_function)
            (struct scene *scene_datas, struct window *window_datas));
        bool (*remove_event_update_function)(struct scene *
            , void (*event_update_function)
            (struct scene *scene_datas, struct window *window_datas));

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
        void (*clock_update)(struct window *);
        void (*event_update)(struct window *);
    } window;

    scene *window_new_scene(window *self, char *name
        , void (*load)(struct scene *)
        , void (*unload)(struct scene *));
    bool window_change_scene(window *self, char *scene_name);
    window *new_window(char *name, sfVideoMode mode);
    void window_clock_update(window *window_datas);
    void window_event_update(window *window_datas);
#endif //t_class_window
