/*
** EPITECH PROJECT, 2022
** new_sprite.c
** File description:
** desc
*/

#include <Class/t_class_sprite.h>
#include <stdlib.h>
#include <Class/t_class_sprite_animator.h>

void init_sprite(sprite *sprite)
{
    sprite->set_pos = sprite_set_pos;
    sprite->set_texture = sprite_set_texture;
    sprite->new_animator = animator_new_animator;
    sprite->sf_sprite = sfSprite_create();
}

sprite *new_sprite(void)
{
    sprite *new_sprite = malloc(sizeof(sprite));
    init_sprite(new_sprite);
    return new_sprite;
}
