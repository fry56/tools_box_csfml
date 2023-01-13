/*
** EPITECH PROJECT, 2022
** t_class_sprite_animation.h
** File description:
** desc
*/
#ifndef t_class_sprite_animation
    #define t_class_sprite_animation

    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include <t_class_sprite.h>

    bool animation_add_sprite(animation *self, char *path);
    void animation_destroy(animation *self);
    void animation_set_loop(animation *self, bool loop);
    bool animation_set_frame_rate(animation *self, float frame_rate);
    animation *new_animation(char *name, bool loop, float frame_rate);
#endif //t_class_sprite_animation
