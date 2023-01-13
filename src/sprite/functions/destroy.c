/*
** EPITECH PROJECT, 2022
** destroy.c
** File description:
** desc
*/
#include <t_class_sprite.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

void sprite_destroy(sprite *self)
{
    tsize_t i = 0;

    sfSprite_destroy(self->sf_sprite);
    if (self->sf_texture != NULL)
        sfTexture_destroy(self->sf_texture);
    tlist_remove(self->host->list_sprites, self->sprite_node);
    if (self->animator != NULL) {
        list_foreach(self->animator->callback_list, node) {
            self->animator->remove_callback(self->animator, i);
            i++;
        }
        map_foreach(self->animator->map_animation, node) {
            tmap_remove(self->animator->map_animation, node->key);
        }
        free(self->animator->map_animation);
        free(self->animator);
    }
    tlist_pop(self->list_flags);
    free(self);
}
