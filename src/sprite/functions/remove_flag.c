/*
** EPITECH PROJECT, 2022
** remove_flag.c
** File description:
** desc
*/

#include <Class/t_class_sprite.h>
#include <t_string.h>

bool sprite_remove_flag(sprite *self, char *flag)
{
    list_foreach(self->list_flag, node) {
        if (tstr_cmp(node->value, flag) == 0) {
            tlist_remove(self->list_flag, node);
            return true;
        }
    }
    return false;
}
