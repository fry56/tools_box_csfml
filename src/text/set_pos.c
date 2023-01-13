/*
** EPITECH PROJECT, 2022
** set_pos.c
** File description:
** desc
*/

#include <t_class_text.h>

void text_set_pos(text *self, int x, int y)
{
    sfText_setPosition(self->sf_text, (sfVector2f){x, y});
}
