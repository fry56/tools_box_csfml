/*
** EPITECH PROJECT, 2022
** destroy.c
** File description:
** desc
*/

#include <t_class_text.h>
#include <t_class_scene.h>

void text_destroy(text *self)
{
    tlist_remove(self->host->list_texts, self->text_node);
    sfText_destroy(self->sf_text);
    sfFont_destroy(self->sf_font);
    tlist_pop(self->list_flags);
}
