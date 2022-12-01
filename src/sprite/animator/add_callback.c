/*
** EPITECH PROJECT, 2022
** add_callback.c
** File description:
** desc
*/

#include <Class/t_class_sprite.h>
#include <Class/t_class_animator_callback.h>
#include <stdlib.h>

bool animator_add_callback(animator *self, char *animation_name
    , void (*callback_func)(sprite *sprite_pointer))
{
    callback *new_callback;

    if (!self->have_animation(self, animation_name))
        return false;
    new_callback = malloc(sizeof(callback));
    if (new_callback == NULL)
        return false;
    new_callback->animation_name = animation_name;
    new_callback->callback = callback_func;
    if (tlist_add(self->callback_list, new_callback) == NULL) {
        free(new_callback);
        return false;
    }
    return true;
}
