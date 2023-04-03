/*
** EPITECH PROJECT, 2023
** sound_manager_remove_sound.c
** File description:
** desc
*/

#include <Class/t_sound.h>
#include <t_string.h>
#include <Class/t_sound_manager.h>

bool sound_manager_remove_sound(sound_mananger *self, char *name)
{
    t_hashmap_node *sound_node;

    if ((sound_node = thashmap_get(self->map_sound, name)) == NULL)
        return false;
    if (self->played_sound == sound_node)
        sfSound_stop(self->sf_sound);
    thashmap_remove(self->map_sound, name);
    return true;
}
