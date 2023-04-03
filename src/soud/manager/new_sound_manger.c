/*
** EPITECH PROJECT, 2023
** new_sound_manger.c
** File description:
** desc
*/

#include <t_mem.h>
#include <t_assert.h>
#include <t_string.h>
#include <Class/t_sound_manager.h>
#include <SFML/Audio.h>
#include <Class/t_scene.h>

sound_mananger *new_sound_manager(scene *scene_datas, sfVector2f pos,
    float min_dist, float volume)
{
    sound_mananger *temp = tcalloc(2, sizeof(sound_mananger));

    tassert(temp == NULL);
    temp->map_sound = thashmap_new(32);
    tassert((temp->sf_sound = sfSound_create()) == NULL);
    sfSound_setVolume(temp->sf_sound, volume);
    sfSound_setMinDistance(temp->sf_sound, min_dist);
    sfSound_setPosition(temp->sf_sound, (sfVector3f){pos.x, pos.y, 0});
    temp->min_dist = min_dist;
    temp->volume = volume;
    tlist_add(scene_datas->list_sound_manager, temp);
    return temp;
}
