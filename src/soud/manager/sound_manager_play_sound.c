/*
** EPITECH PROJECT, 2023
** sound_manager_play_sound.c
** File description:
** desc
*/

#include <Class/t_sound.h>
#include <t_string.h>
#include <Class/t_sound_manager.h>

bool sound_manager_play_sound(sound_mananger *self, char *name)
{
    t_hashmap_node *sound_node;

    if ((sound_node = thashmap_get(self->map_sound, name)) == NULL)
        return false;
    sfSound_stop(self->sf_sound);
    self->played_sound = sound_node;
    sfSound_setBuffer(self->sf_sound,
        ((sound *)sound_node->value)->sf_sound_buffer);
    sfSound_setMinDistance(self->sf_sound,
        ((sound *)sound_node->value)->min_dist > 0 ?
        ((sound *)sound_node->value)->min_dist : self->min_dist);
    sfSound_setVolume(self->sf_sound,
        ((sound *)sound_node->value)->volume > 0 ?
        ((sound *)sound_node->value)->volume : self->volume);
    sfSound_setLoop(self->sf_sound, ((sound *)sound_node->value)->loop);
    sfSound_play(self->sf_sound);
    return true;
}
