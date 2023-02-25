/*
** EPITECH PROJECT, 2022
** t_class_sprint.h
** File description:
** desc
*/
#ifndef t_class_sprint
    #define t_class_sprint

    #include <SFML/Graphics.h>
    #include "t_map.h"
    #include "t_list.h"
    #include "t_ctype.h"
    #include "t_hashmap.h"
    #include <Class/t_window.h>
    #include <Class/t_scene.h>

    #include <Class/t_sprite_animator.h>

    typedef struct sprite {
        scene *host;
        t_list_node *sprite_node;
        sfSprite *sf_sprite;

        sfTexture *sf_texture;
        sfVector2f pos;
        int z_index;

        t_list *list_flags;
        void *sprite_datas;

        animator *animator;
        t_list *list_clock_update_functions;
        t_list *list_event_update_functions;
    } sprite;

    void sprite_set_pos(sprite *self, float x, float y);
    bool sprite_set_texture(sprite *self, char *path);
    void sprite_set_origin_center(sprite *self);
    void sprite_destroy(sprite *self);
    sprite *new_sprite(scene *scene_datas, char *texture_path, int z_index);
    void sprite_use_event(sprite *self, window *window_datas);
    bool sprite_is_mouse_over(sprite *self, sfEvent *event_datas);
    bool sprite_is_mouse_click(sprite *self, sfEvent *event_datas);
    bool sprite_remove_flag(sprite *self, char *flag);
    bool sprite_add_flag(sprite *self, char *flag);
    bool sprite_have_flag(sprite *self, char *flag);

    void clock_update_sprite(scene *scene_datas, sfClock *clock);
    void event_update_sprite(scene *scene_datas, window *window_datas);
    void call_update_sprite_clock(sprite *sprite_datas, sfClock *clock);
    void call_update_sprite_event(sprite *sprite_datas, window *window_datas);

    bool sprite_remove_event_update_function(sprite *self
            , void (*event_update_function)
            (sprite *sprite_datas, struct window *));
    bool sprite_add_event_update_function(sprite *self
            , void (*event_update_function)
            (sprite *sprite_datas, struct window *));

    bool sprite_add_clock_update_function(sprite *self
        , void (*clock_update_function)(sprite *sprite_datas, sfClock *clock));
    bool sprite_remove_clock_update_function(sprite *self
        , void (*clock_update_function)(sprite *sprite_datas, sfClock *clock));
#endif //t_class_sprint
