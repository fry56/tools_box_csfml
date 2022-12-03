/*
** EPITECH PROJECT, 2022
** set_string.c
** File description:
** desc
*/

#include <Class/t_class_text.h>

void text_set_content(text *self, char *content)
{
    sfText_setString(self->sf_text, content);
}
