/*
** EPITECH PROJECT, 2022
** t_class_sprite_animator.h
** File description:
** desc
*/
#ifndef t_class_sprite_animator
    #define t_class_sprite_animator

    #include <stdbool.h>
    #include "t_class_sprite_animation.h"
    #include "../tools_box/t_map.h"

    typedef struct animator {
        int animation_frame;
        t_map_node *played_animation;
        t_map *map_animation;
        t_map_node *default_animation;

        bool (*play_animation)(struct animator*, char *animation_name);
        bool (*add_animation)(struct animator*, animation *new_animation);
        bool (*remove_animation)(struct animator*, char *animation_name);
        bool (*set_default)(struct animator*, char *animation_name);
        t_map_node *(*have_animation)(struct animator*, char *animation_name);
        int (*update_frame)(struct animator*);

    } animator;

    int animator_update_frame(animator *self);
    bool animator_play_animation(animator *self, char *animation_name);
    bool animator_add_animation(animator *self, animation *new_animation);
    bool animator_remove_animation(animator *self, char *animation_name);
    t_map_node *animator_have_animation(animator *self, char *animation_name);
    bool animator_set_default(animator *self, char *animation_name);
    animator *animator_new_animator();
#endif //t_class_sprite_animator
