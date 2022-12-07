
# Class Scene

## Scene struct
```c
typedef struct scene {
    bool is_active;
    struct window *host;
    t_list *list_sprites;
    t_list *list_texts;
    t_list *list_clock_update_functions;
    t_list *list_event_update_functions;
    t_map *map_datas;
} scene;
```

## Create your first Scene
This class depend of class window
```c
#include <Class/t_class_window.h>
#include <Class/t_class_scene.h>

int main(void)
{
    window *new_window_datas = new_window("My Hunter", ((sfVideoMode){800, 600, 32})); -- Explain in window documentation
    new_window_datas->global_clock = sfClock_create(); -- Create the global_clock -- Explain in window documentation
    
    scene *scene_intro = new_window_datas->new_scene(new_window_datas, "Intro", scene_init_intro, NULL);
    scene_intro->load(scene_intro);
    new_window_datas->new_scene(new_window_datas, "Menu", scene_init_menu, NULL);
    new_window_datas->new_scene(new_window_datas, "Game", scene_init_game, NULL);
    
    window_update(new_window_datas); -- Explain in window documentation
    return 0;
}
```
## Functions Lists
### <ins>new_scene</ins>
The function new_scene allow you tou create a new scene object in a window object.
Your new scene object will be stored in a map in her window parent with all other scene.
You can see the actual scene of the window parent and all scene in the map.

#### Exemple :
```c
int main(void)
{
    window *my_window = new_window("My Hunter", ((sfVideoMode){800, 600, 32}));
    new_window_datas->global_clock = sfClock_create(); -- Create the global_clock
    scene *my_scene = my_window->new_scene(my_window, "My new scene", my_new_scene_load, my_new_scene_unload);
    my_window->change_scene(change_scene, "My new scene"); -- Optional because its the first scene and its automatically set to actual scene
    my_scene->load(my_scene);
    window_update(new_window_datas);
    return 0;
}
```

This function take 4 arguments :
- The parent window object.
- The name of your new scene.
- A function called when the scene will be loaded (by the object function unload) (can be NULL).
- A function called when the scene will be unloaded (by the object function unload) (can be NULL).

This function return a pointer of your new created scene object.

#### Prototype :
```c
scene *new_scene(window *self, char *name, void (*load)(struct scene *), void (*unload)(struct scene *));
```

#### Prototype of the argument function (load / unload):
```c
void (*load)(struct scene *);
```

#### Exemple :
```c
scene *my_scene = my_window->new_scene(my_window, "My new scene", my_new_scene_load, my_new_scene_unload);
my_scene->load(scene_intro);
```

### <ins>window->change_scene</ins>
The function change_scene allow you to change the sceen of window object.
When you change the sceen all object and event of the last charged scene is freeze,
but not unload and if you rechange the old sceen every sprite text and datas 
are at the same place with the same value,
if you want to unload the sceen datas (delete sprite, text ...) use object->unload.

It's a function of class object window.

This function take 2 arguments :
- The parent window object.
- The name of the scene you want to load.

This function return a bool :
- Flase : scene not existe or wrong name.
- True : scene success fully load.

#### Prototype :
```c
bool (*change_scene)(struct window *, char *scene_name);
```

#### Exemple :
```c
window *new_window = new_window("My Hunter", ((sfVideoMode){800, 600, 32}));
scene *scene_intro = new_window->new_scene(new_window, "Intro", scene_init_intro, NULL);

new_window->new_scene(new_window, "Menu", scene_init_menu, NULL);

new_window->change_scene(new_window, "Menu");

new_window->global_clock = sfClock_create();
window_update(new_window);
```

### <ins>scene->load</ins>
The function load allow you to execute the load function specified during creation of the scene.

It's a function of class object scene.

This function take 1 arguments :
- The parent scene object.

#### Prototype :
```c
void (*load)(struct scene *);
```

#### Exemple :
```c
// Exemple when you have directly the pointer of the sceen
scene *my_scene = my_window->new_scene(my_window, "My new scene", my_new_scene_load, my_new_scene_unload);
my_scene->load(my_scene);

//Exemple if you need to find the pointer of the sceen
scene *new_scene = tmap_get(self->scenes_map, scene_name)->value;
my_scene->load(new_scene);

//Exemple if you want to load the actual sceen
scene *actual_scene = my_window->actual_scene->value;
actual_scene->load(actual_scene);
```

### <ins>scene->unload</ins>
The function unload allow you to execute the unload function specified during creation of the scene
and destroy every entity like :
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

It's a function of class object scene.

#### This function take 1 arguments :
- The parent scene object.

#### Prototype :
```c
void (*unload)(struct scene *);
```

#### Exemple :
```c
// Exemple when you have directly the pointer of the sceen
scene *my_scene = my_window->new_scene(my_window, "My new scene", my_new_scene_load, my_new_scene_unload);
my_scene->unload(my_scene);

//Exemple if you need to find the pointer of the sceen
scene *new_scene = tmap_get(self->scenes_map, scene_name)->value;
my_scene->unload(new_scene);

//Exemple if you want to load the actual sceen
scene *actual_scene = my_window->actual_scene->value;
actual_scene->unload(actual_scene);
```

### <ins>scene->scene_add_clock_update_function</ins>
The function scene_add_clock_update_function allow you to add function
who will be call at every update of the global clock.

It's a function of class object scene.

#### This function take 1 arguments :
- The parent scene object.
- A function with a specific prototype (exemple below).

#### Prototype :
```c
bool scene_add_clock_update_function(scene *self, void (*clock_update_function)(scene *scene_datas, sfClock *clock));
```

#### Prototype of the argument function :
```c
void (*clock_update_function)(scene *scene_datas, sfClock *clock)
```

#### Exemple :
```c
// Exemple when you have directly the pointer of the sceen

void printf_clock_update(scene *scene_datas, sfClock *clock)
{
    char *scene_name = scene_datas->name;
    long long int clock_time = sfClock_getElapsedTime(clock).microseconds; // csfml function
    printf("[%s] Update : %ul", scene_name, clock_time);
}

int init_scene(scene *my_scene)
{
    my_scene->add_clock_update_function(my_scene, printf_clock_update);
}
```

### <ins>scene->scene_remove_clock_update_function</ins>
The function scene_remove_clock_update_function allow you to remove function previously added.

It's a function of class object scene.

#### This function take 1 arguments :
- The parent scene object.
- The prototype of the function you want to remove.

#### Prototype :
```c
bool scene_remove_clock_update_function(scene *self, void (*clock_update_function)(scene *scene_datas, sfClock *clock));
```

#### Prototype of the argument function :
```c
void (*clock_update_function)(scene *scene_datas, sfClock *clock)
```

#### Exemple :
```c
// Exemple when you have directly the pointer of the sceen

void printf_clock_update(scene *scene_datas, sfClock *clock)
{
    char *scene_name = scene_datas->name;
    long long int clock_time = sfClock_getElapsedTime(clock).microseconds; // csfml function
    printf("[%s] Update : %ul", scene_name, clock_time);
}

int unload_scene(scene *my_scene)
{
    my_scene->scene_remove_clock_update_function(my_scene, printf_clock_update)
}
```

### <ins>scene->scene_add_event_update_function</ins>
The function scene_add_event_update_function allow you to add function
who will be call everytime the event is trigger.

It's a function of class object scene.

#### This function take 1 arguments :
- The parent scene object.
- A function with a specific prototype (exemple below).

#### Prototype :
```c
bool scene_add_event_update_function(scene *self, void (*event_update_function)(scene *scene_datas, struct window *));
```

#### Prototype of the argument function :
```c
void (*event_update_function)(scene *scene_datas, struct window *);
```

#### Exemple :
```c
// Exemple when you have directly the pointer of the sceen

void printf_event_update(scene *scene_datas, sfClock *clock)
{
    if (window.event != sfEvtMouseButtonPressed)
        return;
    printf("Mouse click \n");
}

int init_scene(scene *my_scene)
{
    my_scene->add_clock_event_function(my_scene, printf_event_update);
}
```

### <ins>scene->scene_remove_clock_update_function</ins>
The function scene_remove_clock_update_function allow you to remove function previously added.

It's a function of class object scene.

#### This function take 1 arguments :
- The parent scene object.
- The prototype of the function you want to remove.

#### Prototype :
```c
bool scene_remove_clock_update_function(scene *self, void (*clock_update_function)(scene *scene_datas, sfClock *clock));
```

#### Prototype of the argument function :
```c
void (*clock_update_function)(scene *scene_datas, sfClock *clock)
```

#### Exemple :
```c
// Exemple when you have directly the pointer of the sceen

void printf_clock_update(scene *scene_datas, sfClock *clock)
{
    char *scene_name = scene_datas->name;
    long long int clock_time = sfClock_getElapsedTime(clock).microseconds; // csfml function
    printf("[%s] Update : %ul", scene_name, clock_time);
}

int unload_scene(scene *my_scene)
{
    my_scene->scene_remove_clock_update_function(my_scene, printf_clock_update)
}
```