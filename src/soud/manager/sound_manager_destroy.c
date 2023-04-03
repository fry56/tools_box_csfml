/*
** EPITECH PROJECT, 2023
** sound_manager_destroy.c
** File description:
** desc
*/

#include <Class/t_sound.h>
#include <t_mem.h>
#include <t_string.h>
#include <Class/t_sound_manager.h>

void sound_manager_destroy(sound_mananger *self)
{
    tlist_remove(self->host->list_sound_manager,
        tlist_find(self->host->list_sound_manager, self));
    thashmap_clear(self->map_sound);
    sfSound_destroy(self->sf_sound);
    free(self);
}
