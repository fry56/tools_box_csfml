/*
** EPITECH PROJECT, 2022
** is_mouse_over.c
** File description:
** desc
*/

#include <Class/t_class_sprite.h>

bool sprite_is_mouse_click(sprite *self, sfEvent *event_datas)
{
    sfFloatRect sprite_bounds;

    if (event_datas->type != sfEvtMouseButtonPressed
        && event_datas->type != sfEvtMouseButtonReleased)
        return false;
    sprite_bounds = sfSprite_getGlobalBounds(self->sf_sprite);
    if (self->pos.x > (float)event_datas->mouseButton.x
        || (self->pos.x + sprite_bounds.width)
        < (float)event_datas->mouseButton.x)
        return false;
    if (self->pos.y > (float)event_datas->mouseButton.y
        || (self->pos.y + sprite_bounds.height)
        < (float)event_datas->mouseButton.y)
        return false;
    return true;
}
