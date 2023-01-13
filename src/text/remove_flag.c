/*
** EPITECH PROJECT, 2022
** remove_flag.c
** File description:
** desc
*/

#include <t_class_text.h>
#include <t_string.h>

bool text_remove_flag(text *self, char *flag)
{
    list_foreach(self->list_flags, node) {
        if (tstr_cmp(node->value, flag) == 0) {
            tlist_remove(self->list_flags, node);
            return true;
        }
    }
    return false;
}
