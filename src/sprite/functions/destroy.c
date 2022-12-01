/*
** EPITECH PROJECT, 2022
** destroy.c
** File description:
** desc
*/
#include <Class/t_class_sprite.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

void sprite_destroy(sprite *self)
{
    sfSprite_destroy(self->sf_sprite);
    sfTexture_destroy(self->sf_texture);
    tlist_remove(self->host, self->sprite_node);
    if (self->animator != NULL) {
        map_foreach(self->animator->map_animation, node) {
            ((animation *)node->value)->destroy((animation *)node->value);
            tmap_remove(self->animator->map_animation, node->key);
        }
        free(self->animator->map_animation);
        free(self->animator);
    }
    free(self);
}
