/*
** EPITECH PROJECT, 2022
** callback.c
** File description:
** desc
*/

#include <Class/t_sprite.h>
#include <Class/t_animator_callback.h>

void animator_callback(animator *self, char *animation_name)
{
    list_foreach(self->list_callback, node) {
        if (((callback *)node->value)->animation_name == animation_name)
            ((callback *)node->value)->callback(self->host);
    }
}
