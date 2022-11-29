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

    typedef struct animation {
        char *name;
        bool loop;
        int nbr_sprites;
        sfTexture **sprites_sfTexture;
        float frame_rate;

        bool (*add_sprite)(struct animation*, char *path);
        void (*destroy)(struct animation*);
        void (*set_loop)(struct animation*, bool loop);
        bool (*set_frame_rate)(struct animation*, float frame_rate);
    } animation;

    bool animation_add_sprite(animation *self, char *path);
    void animation_destroy(animation *self);
    void animation_set_loop(animation *self, bool loop);
    bool animation_set_frame_rate(animation *self, float frame_rate);
#endif //t_class_sprite_animation
