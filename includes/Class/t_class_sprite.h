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
    #include <Class/t_class_sprite_animator.h>

    typedef struct sprite {
        sfSprite *sf_sprite;
        sfTexture *sf_texture;
        sfVector2f pos;
        animator *animator;

        animator *(*new_animator)();
        void (*set_pos)(struct sprite*, float x, float y);
        bool (*set_texture)(struct sprite*, char *path);
        void (*destroy)(struct sprite*);
    } sprite;

    void sprite_set_pos(sprite *self, float x, float y);
    bool sprite_set_texture(sprite *self, char *path);
    void sprite_destroy(sprite *self);
    sprite *new_sprite();
#endif //t_class_sprint
