/*
** EPITECH PROJECT, 2022
** destroy.c
** File description:
** desc
*/

#include <Class/t_text.h>
#include <Class/t_scene.h>

void text_destroy(text *self)
{
    if (self->destroy != NULL)
        self->destroy(self);
    tlist_remove(self->host->list_texts, self->text_node);
    sfText_destroy(self->sf_text);
    sfFont_destroy(self->sf_font);
    tlist_pop(self->list_flags);
}
