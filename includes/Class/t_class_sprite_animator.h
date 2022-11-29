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
    #include "tools_box/t_ctype.h"
    #include "t_class_sprite.h"

    int animator_update_frame(animator *self, sfClock *clock);
    bool animator_play_animation(animator *self, char *animation_name);
    bool animator_add_animation(animator *self, animation *new_animation);
    bool animator_remove_animation(animator *self, char *animation_name);
    int animator_have_animation(animator *self, char *animation_name);
    void animator_new_animator(sprite *self);
    bool animator_set_default(animator *self, char *animation_name);
#endif //t_class_sprite_animator
