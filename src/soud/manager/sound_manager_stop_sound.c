/*
** EPITECH PROJECT, 2023
** sound_manager_stop_sound.c
** File description:
** desc
*/

#include <Class/t_sound.h>
#include <t_string.h>
#include <Class/t_sound_manager.h>

void sound_manager_stop_sound(sound_mananger *self)
{
    sfSound_stop(self->sf_sound);
}
