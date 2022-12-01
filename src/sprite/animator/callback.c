/*
** EPITECH PROJECT, 2022
** callback.c
** File description:
** desc
*/

#include <Class/t_class_sprite.h>
#include <Class/t_class_animator_callback.h>

void animator_callback(animator *self, char *animation_name)
{
    list_foreach(self->callback_list, node) {
        if (((callback *)node->value)->animation_name == animation_name)
            ((callback *)node->value)->callback(self->host);
    }
}
