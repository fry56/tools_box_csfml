/*
** EPITECH PROJECT, 2022
** set_font_color.c
** File description:
** desc
*/

#include <Class/t_class_text.h>

void text_set_font_color(text *self, uint32_t integer_color)
{
    self->sf_color = sfColor_fromInteger(integer_color);
    sfText_setColor(self->sf_text, self->sf_color);
}
