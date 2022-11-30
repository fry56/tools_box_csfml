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

sprite *new_sprite()
{
    sprite *new_sprite = malloc(sizeof(sprite));
    init_sprite(new_sprite);
    return new_sprite;
}

/*void CReatefirstsprite()
{
    sprite *bird = new_sprite();
    bird->new_animator();

    animation anim_1;
    anim_1.name = "Idel";
    anim_1.add_sprite(&anim_1, "../bird_1.png");
    anim_1.add_sprite(&anim_1, "../bird_2.png");
    anim_1.loop = true;

    bird->animator->add_animation(bird->animator, &anim_1);
    bird->animator->play_animation(bird->animator, "Idel");


}*/