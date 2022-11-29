/*
** EPITECH PROJECT, 2022
** set_pos.c
** File description:
** desc
*/

#include <Class/t_class_sprite.h>
#include <SFML/Graphics.h>

void sprite_set_pos(sprite *self, float x, float y)
{
    self->pos.x = x;
    self->pos.y = y;
    sfSprite_setPosition(self->sf_sprite, self->pos);
}