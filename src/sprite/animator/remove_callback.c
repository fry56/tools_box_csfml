/*
** EPITECH PROJECT, 2022
** remove_event.c
** File description:
** desc
*/

#include <t_class_sprite.h>
#include <t_class_animator_callback.h>
#include <stdlib.h>
#include <t_string.h>

bool animator_remove_callback(animator *self, tsize_t index)
{
    tsize_t i = 0;

    if (self->callback_list->length < index)
        return false;
    list_foreach(self->callback_list, node) {
        if (i == index) {
            free(node->value);
            tlist_remove(self->callback_list, node);
            break;
        }
        i++;
    }
    return true;
}

void animator_remove_callback_by_name(animator *self, char *animation_name)
{
    list_foreach(self->callback_list, node) {
        if (tstr_cmp(((callback *)node->value)->animation_name
            , animation_name) == 0) {
            tlist_remove(self->callback_list, node);
        }
    }
}
