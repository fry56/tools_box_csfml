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

    typedef struct animator {
        int nbr_animation;
        int animation_frame;
        animation *played_animation;
        animation **list_animation;
        animation *default_animation;

        bool (*play_animation)(struct animator*, char *animation_name);
        bool (*add_animation)(struct animator*, animation *new_animation);
        bool (*remove_animation)(struct animator*, char *animation_name);
        int (*have_animation)(struct animator*, char *animation_name);
        int (*update_frame)(struct animator*);

    } animator;
    int animator_update_frame(animator *self);
    bool animator_play_animation(animator *self, char *animation_name);
    bool animator_add_animation(animator *self, animation *new_animation);
    bool animator_remove_animation(animator *self, char *animation_name);
    int animator_have_animation(animator *self, char *animation_name);
    animator *animator_new_animator();
#endif //t_class_sprite_animator
