/*
** EPITECH PROJECT, 2023
** t_sound_mananger.h
** File description:
** desc
*/
#ifndef t_sound_mananger
    #define t_sound_mananger

    #include <t_hashmap.h>
    #include "t_sound.h"
    #include <Class/t_scene.h>

    typedef struct sound_mananger {
        scene *host;
        t_hashmap *map_sound;
        t_hashmap_node *played_sound;
        sfSound *sf_sound;
        float min_dist;
        float volume;
    } sound_mananger;

    sound_mananger *new_sound_manager(scene *scene_datas, sfVector2f pos,
        float min_dist, float volume);
    bool sound_manager_add_sound(sound_mananger *self, sound *sound_datas);
    bool sound_manager_play_sound(sound_mananger *self, char *name);
    void sound_manager_destroy(sound_mananger *self);
    void sound_manager_stop_sound(sound_mananger *self);
#endif //t_sound_mananger
