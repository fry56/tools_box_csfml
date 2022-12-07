
# T_map

## Struct of t_map
```c
typedef struct map_node {
    char *key;
    void *host;
    void *value;
    struct map_node *next;
    struct map_node *prev;
} t_map_node;

typedef struct map {
    t_map_node *head;
    t_map_node *tail;
    tsize_t length;
} t_map;
```

### Explain :

#### t_map :

this is your list struct you can get the length of the map and get the
first and the last value of the map with head(first) tail(lats)

- head : this is the pointer of the first t_map_node
- tail : this is the pointer of the last t_map_node
- length : this is an int egual the number of element in the list
#### t_map_node :

this is a element of you list :
- key : this is a string who your value is associated with in the map.
- host : this is the pointer of the parent t_map
- value : this is the pointer of the value
- next : this is the pointer of the next t_map_node
- prev : this is the pointer of the prev t_map_node

## Concept of T_map

The concept of t_map is realy simple, a t_map is chain link map with useful function.

Exemple :
Simple exemple of a t_map application.

```c
#include <t_map.h>

typedef struct my_game {
    t_map map_player;
} my_game;

typedef struct player {
    char *name;
} player;

void init_my_game(scene *my_scene)
{
    my_game *new_struct = malloc(sizeof(my_game));
    new_struct->map_player = tmap_new();
    add_new_player(new_struct);
}

void add_new_player(my_game *new_struct)
{
    player *new_player = malloc(sizeof(player));
    new_player->name = "Fry";
    tmap_add(new_struct->list_player, "Fry" new_player);
}

```

## Functions Lists
### <ins>tmap_new</ins>
The function tmap_new allow you to create a new t_map.

This function take 0 arguments.

This function return a pointer of your new t_map.

#### Prototype :
```c
t_map *tmap_new(void);
```

Exemple :
```c
void main(void)
{
    t_map *new_tmap = tmap_new();
}
```

### <ins>tmap_add</ins>
The function tmap_add allow you to add elements pointer in your t_map.

This function take 3 arguments :
- The t_map you want to add the element.
- The key you want associate to your element.
- The pointer of your element.

This function return the t_map_node pointer of your new element.

#### Prototype :
```c
    t_map_node *tmap_add(t_map *map, char *key, void *value);
```

Exemple :
```c
void main(void)
{
    char *my_string = "That my new string !";
    t_map *new_tmap = tmap_new();
    tmap_add(new_tmap, "String A", my_string); // <-- tmap_add
}
```

### <ins>tmap_remove</ins>
The function tlist_remove allow you to remove elements in your t_map.

This function take 2 arguments :
- The t_map you want to remove the element.
- The key associate to your element.

This function return a bool :
- True : The element success fully remove.
- False : Key not found key.

#### Prototype :
```c
bool tmap_remove(t_map *map, char *key);
```

Exemple :
```c
void main(void)
{
    char *my_string = "That my new string !";
    t_map *new_tmap = tmap_new();
    tmap_add(new_tmap, "String A", my_string);
    tmap_remove(new_tmap, "String A");
}
```

### <ins>tmap_get</ins>
The function tlist_get allow you to get the t_map_node of a elements in your t_map with her index.

This function take 2 arguments :
- The t_map you want to get the element.
- The key associate to your element.

This function return the t_map_node pointer of your element.

#### Prototype :
```c
t_map_node *tmap_get(t_map *map, char *key);
```

Exemple :
```c
void main(void)
{
    char *my_string = "That my new string !";
    
    t_map *new_tmap = tlist_new();
    t_map_node *my_new_element = tmap_add(new_tmap, "String A", my_string);
}

void delet(t_map *new_tmap)
{
    t_map_node *my_get_element = tmap_get(new_tmap, "String A"); // <-- tmap_get
    tmap_remove(new_tmap, my_get_element);
}
```

### <ins>map_foreach</ins>
The function map_foreach allow is a implementation of a simple foreach in c for t_map.

#### What is foreach ?
Foreach is like a for but instead of increment a int with which you go get the content of the index of your list
le foreach will give you directly the t_map_node with the variable node.

Exemple :
```c
void main(void)
{
    char *my_string_a = "That my new string A!";
    char *my_string_b = "That my new string B!";
    char *my_string_c = "That my new string C!"; // <-- this value will be remove
    char *my_string_d = "That my new string D!";
    
    t_map *new_tmap = tmap_new();
    tmap_add(new_tmap, "String A", my_string_a);
    tmap_add(new_tmap, "String B", my_string_b);
    tmap_add(new_tmap, "String C", my_string_c);
    tmap_add(new_tmap, "String D", my_string_d);
}

void delet(t_map *new_tmap) // <-- remove only t_map_node with the value = "That my new string C!"
{
    char *temp;
    map_foreach(new_tmap, node) { // <-- map_foreach
        temp = node->value;
        if (tstr_cmp(temp, "That my new string C!") == 0) // <-- function of the lib tools_box (compare 2 string)
            tmap_remove(new_tmap, node);
    }
}
```