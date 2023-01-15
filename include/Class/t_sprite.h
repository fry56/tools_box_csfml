/*
** EPITECH PROJECT, 2022
** t_class_sprint.h
** File description:
** desc
*/
#ifndef t_class_sprint
    #define t_class_sprint

    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #include "t_map.h"
    #include "t_list.h"
    #include "t_ctype.h"
    #include "t_window.h"
    #include "t_hashmap.h"

    typedef struct animation {
        char *name;
        bool loop;
        t_list *list_frame_rect;
        float frame_rate;

        void (*set_loop)(struct animation *, bool loop);
        bool (*set_frame_rate)(struct animation *, float frame_rate);
        bool (*auto_gen_frame)(struct animation *, int nbr_sprites
                , int nbr_sprite_per_line, sfIntRect rect_start);
        bool (*add_frame)(struct animation *, sfIntRect rect);
        bool (*remove_frame)(struct animation *, size_t index);
    } animation;

    typedef struct animator {
        struct sprite *host;
        int animation_frame;
        t_hashmap_node *played_animation;
        t_hashmap *map_animation;
        t_hashmap_node *default_animation;
        t_list *callback_list;
        int64_t last_clock_update;

        bool (*play_animation)(struct animator *, char *animation_name);
        bool (*add_animation)(struct animator *, animation *new_animation);
        bool (*remove_animation)(struct animator *, char *animation_name);
        t_hashmap_node *(*have_animation)(struct animator *
            , char *animation_name);
        int (*update_frame)(struct animator *, sfClock *clock);
        bool (*set_default)(struct animator *, char *animation_name);
        void (*callback)(struct animator *, char *animation_name);
        bool (*remove_callback)(struct animator *, tsize_t index);
        void (*remove_callback_by_name)(struct animator *
            , char *animation_name);
        bool (*add_callback)(struct animator *, char *animation_name
            , void (*call_back)());
    } animator;

    typedef struct sprite {
        scene *host;
        t_list_node *sprite_node;
        sfSprite *sf_sprite;

        sfTexture *sf_texture;
        sfVector2f pos;

        t_list *list_flags;
        void *object_datas;

        animator *animator;
        t_list *events_list;

        bool (*have_flag)(struct sprite *, char *flag);
        bool (*remove_flag)(struct sprite *, char *flag);
        bool (*add_flag)(struct sprite *, char *flag);
        bool (*is_mouse_click)(struct sprite *, sfEvent *event_datas);
        bool (*is_mouse_over)(struct sprite *, sfEvent *event_datas);
        void (*new_animator)(struct sprite *);
        void (*set_pos)(struct sprite *, float x, float y);
        void (*set_origin_center)(struct sprite *);
        bool (*set_texture)(struct sprite *, char *path);
        void (*destroy)(struct sprite *);
        void (*use_event)(struct sprite *, window *window_datas);
        bool (*remove_event)(struct sprite *, tsize_t index);
        void (*remove_events_by_type)(struct sprite *, sfEvent *event_data);
        bool (*add_event)(struct sprite *, sfEventType type
                , void (*event_function)(struct sprite *
                , window *window_datas));
    } sprite;

    typedef struct event {
        sfEventType type;
        void (*event_function)(sprite *self, window *window_datas);
    } event;

    void sprite_set_pos(sprite *self, float x, float y);
    bool sprite_set_texture(sprite *self, char *path);
    void sprite_set_origin_center(sprite *self);
    void sprite_destroy(sprite *self);
    sprite *new_sprite(scene *scene_datas);
    void sprite_use_event(sprite *self, window *window_datas);
    bool sprite_remove_event(sprite *self, tsize_t index);
    void sprite_remove_events_by_type(sprite *self, sfEvent *event_data);
    bool sprite_add_event(sprite *self, sfEventType type
        , void (*event_function)(sprite *sprite_pointer
        , window *window_datas));
    bool sprite_is_mouse_over(sprite *self, sfEvent *event_datas);
    bool sprite_is_mouse_click(sprite *self, sfEvent *event_datas);
    bool sprite_remove_flag(sprite *self, char *flag);
    bool sprite_add_flag(sprite *self, char *flag);
    bool sprite_have_flag(sprite *self, char *flag);

    void clock_update_sprite(scene *scene_datas, sfClock *clock);
    void event_update_sprite(scene *scene_datas, window *window_datas);
#endif //t_class_sprint
