/*
** EPITECH PROJECT, 2022
** t_class_animator_callback.h
** File description:
** desc
*/
#ifndef t_class_animator_callback
    #define t_class_animator_callback

    #include <t_class_sprite.h>

    typedef struct callback {
        char *animation_name;
        void (*callback)(sprite *sprite_pointer);
    } callback;

#endif //t_class_animator_callback
