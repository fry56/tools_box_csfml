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
    #include <t_map.h>
    #include <t_ctype.h>

    typedef struct animation {
        char *name;
        bool loop;
        int nbr_sprites;
        sfTexture **sprites_sfTexture;
        float frame_rate;

        bool (*add_sprite)(struct animation *, char *path);
        void (*destroy)(struct animation *);
        void (*set_loop)(struct animation *, bool loop);
        bool (*set_frame_rate)(struct animation *, float frame_rate);
    } animation;

    typedef struct animator {
        int nbr_animation;
        int animation_frame;
        t_map_node *played_animation;
        t_map *map_animation;
        t_map_node *default_animation;
        int64_t last_clock_update;

        bool (*play_animation)(struct animator *, char *animation_name);
        bool (*add_animation)(struct animator *, animation *new_animation);
        bool (*remove_animation)(struct animator *, char *animation_name);
        t_map_node *(*have_animation)(struct animator *, char *animation_name);
        int (*update_frame)(struct animator *, sfClock *clock);
        bool (*set_default)(struct animator *, char *animation_name);
    } animator;

    typedef struct sprite {
        sfSprite *sf_sprite;
        sfTexture *sf_texture;
        sfVector2f pos;

        animator *animator;

        void (*new_animator)(struct sprite *);
        void (*set_pos)(struct sprite *, float x, float y);
        bool (*set_texture)(struct sprite *, char *path);
        void (*destroy)(struct sprite *);
    } sprite;

    void sprite_set_pos(sprite *self, float x, float y);
    bool sprite_set_texture(sprite *self, char *path);
    void sprite_destroy(sprite *self);
    sprite *new_sprite(void);
    void update_sprite(sprite **list_sprites, sfClock *clock);
#endif //t_class_sprint
