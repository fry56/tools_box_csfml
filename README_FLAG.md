
# Flags of [Sprite](https://github.com/fry56/tools_box_csfml/tree/main/src/sprite) / [Text](https://github.com/fry56/tools_box_csfml/tree/main/src/text)

## Struct of Sprite / Text
```c
//Sprite struct
typedef struct sprite {
    scene *host;
    t_list_node *sprite_node;
    sfSprite *sf_sprite;
    
    sfTexture *sf_texture;
    sfVector2f pos;
    
    t_list *list_flags;
    t_map *map_datas;
    
    animator *animator;
    t_list *events_list;
} sprite;

//Text struct
typedef struct text {
    scene *host;
    t_list_node *text_node;
    
    t_list *list_flags;
    sfText *sf_text;
    sfFont *sf_font;
    sfColor sf_color;
} text;
```

## Concept of flag

As you could have seen every sprites and texts are stored in a global [t_list](https://github.com/fry56/tools_box_csfml/blob/main/README_T_LIST.md) in her [scene](https://github.com/fry56/tools_box_csfml/tree/main/src/scene) parent object,
this method allow you to access at every sprite wath ever you are because
every update function give you in argument the scene.

The flag concept is a copy of unity 3D features, allow you to find every element of ui 
or destroy every enemy sprite for exemple.

Exemple :
I have create a simple menu UI and I want to destroy it now, during her creation I gave them the flag "My_UI".

```c
#include <Class/t_class_sprite.h>
#include <Class/t_class_text.h>

void init_menu(scene *my_scene)
{
    sprite *my_play_button = new_sprite(my_scene);
    my_play_button->set_texture(my_play_button, "b_play.png");
    my_play_button->add_flag(my_play_button, "My_UI");
    
    text *score_text = new_text(scene_datas, tstr_concat("Your score : 0", "assets/Font/Fruit Days.ttf", 4210752);
    score_text->add_flag(score_text, "My_UI");
}

void destro_menu(scene *my_scene)
{
    text *temp_text;
    sprite *temp_sprite;
    
    list_foreach(my_scene->list_texts, node) { // traveled all text of the scene
        temp_text = node->value;
        if (temp_text->have_flag(temp_text, "My_UI")) {
            temp_text->destroy(temp_text);
        }
    }
    list_foreach(my_scene->list_sprites, node) { // traveled all sprite of the scene
        temp_sprite = node->value;
        if (temp_sprite->have_flag(temp_sprite, "My_UI")) {
            temp_sprite->destroy(temp_sprite);
        }
    }
}

```

## Functions Lists
### <ins>sprite/text->add_flag</ins>
The function add_flag allow you to add a new flag of your text or sprite object.

It's a function of class object text or sprite.

This function take 2 arguments :
- The text or sprite object.
- The string of the name of your flag.

This function return a Bool :
- True : The flag has been success fully add to the object.
- False : The flag already exists on the object.

#### Prototype :
```c
bool text_add_flag(text *self, char *flag);
bool sprite_add_flag(sprite *self, char *flag);
```

Exemple :
```c
void init_menu(scene *my_scene)
{
    sprite *my_play_button = new_sprite(my_scene);
    my_play_button->set_texture(my_play_button, "b_play.png");
    my_play_button->add_flag(my_play_button, "My_UI");
    
    text *score_text = new_text(scene_datas, tstr_concat("Your score : 0", "assets/Font/Fruit Days.ttf", 4210752);
    score_text->add_flag(score_text, "My_UI");
}
```

### <ins>sprite/text->remove_flag</ins>
The function remove_flag allow you to remove a existent flag of your text or sprite object.

It's a function of class object text or sprite.

This function take 2 arguments :
- The text or sprite object.
- The string of the name of your flag.

This function return a Bool :
- True : The flag has been success fully remove to the object.
- False : The flag didn't exist on the object.

#### Prototype :
```c
bool text_remove_flag(text *self, char *flag)
bool sprite_remove_flag(sprite *self, char *flag)
```

Exemple :
```c
void init_menu(scene *my_scene)
{
    sprite *my_play_button = new_sprite(my_scene);
    my_play_button->set_texture(my_play_button, "b_play.png");
    my_play_button->add_flag(my_play_button, "My_UI");
    my_play_button->remove_flag(my_play_button, "My_UI");
    
    text *score_text = new_text(scene_datas, tstr_concat("Your score : 0", "assets/Font/Fruit Days.ttf", 4210752);
    score_text->add_flag(score_text, "My_UI");
    score_text->remove_flag(score_text, "My_UI");
}
```

### <ins>sprite/text->have_flag</ins>
The function have_flag allow you to know if your object have the specified flag or no.

It's a function of class object text or sprite.

This function take 2 arguments :
- The text or sprite object.
- The string of the name of your flag.

This function return a Bool :
- True : The object have the specified flag.
- False : The object didn't have the specified flag.

#### Prototype :
```c
bool text_have_flag(text *self, char *flag);
bool sprite_have_flag(sprite *self, char *flag);
```

Exemple :
```c
void destro_menu(scene *my_scene)
{
    text *temp_text;
    sprite *temp_sprite;
    
    list_foreach(my_scene->list_texts, node) { // traveled all text of the scene
        temp_text = node->value;
        if (temp_text->have_flag(temp_text, "My_UI")) {
            temp_text->destroy(temp_text);
        }
    }
    list_foreach(my_scene->list_sprites, node) { // traveled all sprite of the scene
        temp_sprite = node->value;
        if (temp_sprite->have_flag(temp_sprite, "My_UI")) {
            temp_sprite->destroy(temp_sprite);
        }
    }
}
```