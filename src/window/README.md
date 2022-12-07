
# Class Window

## Window struct
```c
typedef struct window {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    t_map *scenes_map;
    t_map_node *actual_scene;
    sfClock *global_clock;
} window;
```

## Create your first window

```c
#include <Class/t_class_window.h>

int window_update(window *self)
{
    sfWindow_setFramerateLimit((sfWindow *) self->window, 60);
    while (sfRenderWindow_isOpen(self->window)) {
        while (sfRenderWindow_pollEvent(self->window, &self->event)) {
            self->event_update(self);
        }
        self->clock_update(self);
        sfRenderWindow_clear(self->window, sfBlack);
        list_foreach(((scene *)self->actual_scene->value)->list_sprites, node)
            sfRenderWindow_drawSprite(self->window
                , ((sprite *)node->value)->sf_sprite, NULL);
        list_foreach(((scene *)self->actual_scene->value)->list_texts, node)
            sfRenderWindow_drawText(self->window
                , ((text *)node->value)->sf_text, NULL);
        sfRenderWindow_display(self->window);
    }
    self->destroy(self);
    return 0;
}

int main(void)
{
    window *new_window_datas = new_window("My Hunter", ((sfVideoMode){800, 600, 32}));
    new_window_datas->global_clock = sfClock_create(); -- Create the global_clock
    window_update(new_window_datas);
    return 0;
}

```
## Functions Lists
### <ins>new_window</ins>
The function new_window allow you tou create a new window object.

This function take 2 arguments :
- A string for the name of your window.
- A struct [sfVideoMode](https://26.customprotocol.com/csfml/structsfVideoMode.htm) who containe unsigned int (Width, Height, [bitsPerPixel](https://26.customprotocol.com/csfml/structsfVideoMode.htm#af2127ab37c7e99a92b8fcd7312aaf325)).

This function return a pointer of your new created window object.

Exemple :
```c
window *my_window = new_window("My window", ((sfVideoMode){800, 600, 32}));
```

### <ins>destroy</ins>
The function destroy allow you to destroy a window object properly.

Its a function of class object window.

This function destroy recursively linked objects :

- scene
    - sprite
        - [sfSprite](https://26.customprotocol.com/csfml/Graphics_2Types_8h.htm#a83f6e917c9d260f8b92cf5119c8bb036)
        - events
        - animator
        - default texture
        - flags list
    - text
        - [sfText](https://26.customprotocol.com/csfml/Graphics_2Types_8h.htm#acf1decff09b5b3a9d453909d07571117)
        - [sfFont](https://26.customprotocol.com/csfml/Graphics_2Types_8h.htm#ae23f460393aed22f5689c3dfd17a5c03)
        - flags list
- global_clock ([sfClock](https://26.customprotocol.com/csfml/Clock_8h.htm))
- [sfWindow](https://26.customprotocol.com/csfml/RenderWindow_8h.htm)

Exemple :
```c
window *my_window = new_window("My window", ((sfVideoMode){800, 600, 32}));

my_window->destroy(my_window);
```