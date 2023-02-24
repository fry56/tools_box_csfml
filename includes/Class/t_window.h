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
    #include <t_list.h>
    #include <t_hashmap.h>
    #include <Utils/t_key.h>

    typedef struct scene {
        bool is_active;
        struct window *host;
        t_list *list_sprites;
        t_list *list_texts;
        t_list *list_clock_update_functions;
        t_list *list_event_update_functions;
        t_list *list_keys;
        t_hashmap *map_datas;

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

        bool (*is_key_bind)(struct scene *, sfKeyCode key);
        bool (*add_key_bind)(struct scene *, sfKeyCode key);
        key_bind *(*get_key)(struct scene *, sfKeyCode key);
        tsize_t (*get_key_press_timestamp)(struct scene *, sfKeyCode key);
        bool (*is_key_press)(struct scene *, sfKeyCode key);
        bool (*key_press)(struct scene *, sfKeyCode key);

        void (*load)(struct scene *);
        void (*unload)(struct scene *);
    } scene;

    typedef struct window {
        sfVideoMode mode;
        sfRenderWindow *window;
        sfEvent event;

        t_hashmap *scenes_map;
        t_hashmap_node *actual_scene;
        sfClock *global_clock;
        long long last_tick;
        float deltatime;

        scene *(*new_scene)(struct window *, char *name
                , void (*load)(struct scene *)
                , void (*unload)(struct scene *));
        bool (*change_scene)(struct window *, char *scene_name);
        void (*clock_update)(struct window *);
        void (*event_update)(struct window *);
        void (*destroy)(struct window *);
    } window;

    scene *window_new_scene(window *self, char *name
        , void (*load)(struct scene *)
        , void (*unload)(struct scene *));
    bool window_change_scene(window *self, char *scene_name);
    window *new_window(char *name, sfVideoMode mode);
    void window_clock_update(window *window_datas);
    void window_event_update(window *window_datas);
    void window_destroy(window *self);
#endif //t_class_window
