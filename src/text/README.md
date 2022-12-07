
# Class Text

## Text struct
```c
typedef struct text {
    scene *host;
    t_list_node *text_node;
    
    t_list *list_flags;
    sfText *sf_text;
    sfFont *sf_font;
    sfColor sf_color;
} text;
```

## Create your first text

```c
#include <Class/t_class_window.h>
#include <Class/t_class_text.h>

int main(void)
{
    window *my_window = new_window("My Hunter", ((sfVideoMode){800, 600, 32}));
    my_window->global_clock = sfClock_create(); -- Create the global_clock
    window_update(new_window_datas);
    
    scene *game_scene = my_window->new_scene(my_window, "Game", NULL, NULL);
    
    text *score_text = new_text(game_scene, "Score : 0", "assets/Font/Fruit Days.ttf", 4210752);
    score_text->set_pos(score_text, 50, 50);
    score_text->add_flag(score_text, "score");
    return 0;
}

```
## Functions Lists
### <ins>new_text</ins>
The function new_text allow you tou create a new text object.

This function take 2 arguments :
- The parent scene object.
- The string content of your text.
- A string path to your font (.ttf) you can set it to null it's will be by default [Fruit Days](https://www.dafont.com/fr/fruit-days.font).
- A unsigned long int for the text color.

This function return a pointer of your new created text object.

#### Prototype :
```c
void init_new_text(text *new_text, char *content, uint32_t integer_color);
```

Exemple :
```c
text *my_text = new_text(my_scene, "This is my new text !", "assets/Font/Fruit Days.ttf", 4210752);
```

### <ins>destroy</ins>
The function destroy allow you to destroy a text object properly.

It's a function of class object text.

This function destroy recursively linked objects :

- text
    - [sfText](https://26.customprotocol.com/csfml/Graphics_2Types_8h.htm#acf1decff09b5b3a9d453909d07571117)
    - [sfFont](https://26.customprotocol.com/csfml/Graphics_2Types_8h.htm#ae23f460393aed22f5689c3dfd17a5c03)
    - flags list

#### Prototype :
```c
void text_destroy(text *self);
```

Exemple :
```c
void destroy_score_text(scene *my_scene)
{
    text *my_score;
    list_foreach(my_scene->list_texts, node) {
        my_score = node->value;
        if (my_score->have_flag(my_score, "score")) {
            my_score->destroy(my_score);
        }
    }
}
```

### <ins>set_content</ins>
The function set_content allow you to change the string content of your text object.

This function take 2 arguments :
- The text object.
- The string content of your text.

This function return nothing.

#### Prototype :
```c
void text_set_content(text *self, char *content);
```

Exemple :
```c
text *my_text = new_text(my_scene, "This is my new text !", "assets/Font/Fruit Days.ttf", 4210752);
my_text->set_content(my_text, "This is my updated text !");
```

### <ins>set_font_color</ins>
The function set_font_color allow you to change the text color of your text object.

This function take 2 arguments :
- The text object.
- A unsigned long int for the text color.

This function return nothing.

#### Prototype :
```c
void text_set_font_color(text *self, uint32_t integer_color);
```

Exemple :
```c
text *my_text = new_text(my_scene, "This is my new text !", "assets/Font/Fruit Days.ttf", 4210752);
my_text->text_set_font_color(my_text, 8460752);
```

### <ins>set_font_size</ins>
The function set_font_size allow you to change the text size of your text object.

This function take 2 arguments :
- The text object.
- A unsigned long int for the text size.

This function return nothing.

#### Prototype :
```c
void text_set_font_size(text *self, uint32_t font_size);
```

Exemple :
```c
text *my_text = new_text(my_scene, "This is my new text !", "assets/Font/Fruit Days.ttf", 4210752);
my_text->set_font_size(my_text, 50);
```

### <ins>set_origin_center</ins>
The function set_font_size allow you to change the origine point (Default is at the top left corner) of the text object,
it's useful in case you want to center it in a menu for exemple.

This function take 1 arguments :
- The text object.

This function return nothing.

#### Prototype :
```c
void text_set_origin_center(text *self)
```

Exemple :
```c
text *my_text = new_text(my_scene, "This is my new text !", "assets/Font/Fruit Days.ttf", 4210752);
my_text->set_origin_center(my_text);
```

### <ins>set_pos</ins>
The function set_font_size allow you to change the pos of your text object.

This function take 3 arguments :
- The text object.
- a int for the X position.
- a int for the Y position.

This function return nothing.

#### Prototype :
```c
void text_set_pos(text *self, int x, int y)
```

Exemple :
```c
text *my_text = new_text(my_scene, "This is my new text !", "assets/Font/Fruit Days.ttf", 4210752);
my_text->set_pos(my_text, 50, 50); // x = 0, y = 0 is the top left corner
```