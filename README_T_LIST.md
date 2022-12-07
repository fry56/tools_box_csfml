
# T_list

## Struct of t_list
```c
typedef struct list_node {
    void *host;
    void *value;
    struct list_node *next;
    struct list_node *prev;
} t_list_node;

typedef struct list {
    t_list_node *head;
    t_list_node *tail;
    tsize_t length;
} t_list;
```

### Explain :

#### t_list :

this is your list struct you can get the length of the list and get the
first and the last value of the list with head(first) tail(lats)

- head : this is the pointer of the first t_list_node
- tail : this is the pointer of the last t_list_node
- length : this is an int egual the number of element in the list
#### t_list_node :
 
this is a element of you list :
    
- host : this is the pointer of the parent t_list
- value : this is the pointer of the value
- next : this is the pointer of the next t_list_node
- prev : this is the pointer of the prev t_list_node

## Concept of T_list

The concept of T_list is realy simple, a t_ist is chain link list with useful function.

Exemple :
Simple exemple of a t_list application.

```c
#include <t_list.h>

typedef struct my_game {
    t_list list_player;
} my_game;

typedef struct player {
    char *name;
} player;

void init_my_game(scene *my_scene)
{
    my_game *new_struct = malloc(sizeof(my_game));
    new_struct->list_player = tlist_new();
    add_new_player(new_struct);
}

void add_new_player(my_game *new_struct)
{
    player *new_player = malloc(sizeof(player));
    new_player->name = "Fry";
    tlist_add(new_struct->list_player, new_player);
}

```

## Functions Lists
### <ins>tlist_new</ins>
The function tlist_new allow you to create a new t_list.

This function take 0 arguments.

This function return a pointer of your new t_list.

#### Prototype :
```c
t_list *tlist_new(void);
```

Exemple :
```c
void main(void)
{
    t_list *new_tlist = tlist_new();
}
```

### <ins>tlist_add</ins>
The function tlist_add allow you to add elements pointer in your t_list.

This function take 2 arguments :
- The t_list you want to add the element.
- The pointer of your element.

This function return the t_list_node pointer of your new element.

#### Prototype :
```c
t_list_node *tlist_add(t_list *list, void *value);
```

Exemple :
```c
void main(void)
{
    char *my_string = "That my new string !";
    t_list *new_tlist = tlist_new();
    tlist_add(new_tlist, my_string); // <-- tlist_add
}
```

### <ins>tlist_remove</ins>
The function tlist_remove allow you to remove elements in your t_list.

This function take 2 arguments :
- The t_list you want to remove the element.
- The pointer of your t_list_node element.

This function return a bool :
- True : The element success fully remove.
- False : The element not found t_list_node == NULL or t_list_node does not belong to the list.

#### Prototype :
```c
bool tlist_remove(t_list *list, t_list_node *node)
```

Exemple :
```c
void main(void)
{
    char *my_string = "That my new string !";
    t_list *new_tlist = tlist_new();
    t_list_node *my_new_element = tlist_add(new_tlist, my_string);
    tlist_remove(new_tlist, my_new_element); // <-- tlist_remove
}
```

### <ins>tlist_get</ins>
The function tlist_get allow you to get the t_list_node of a elements in your t_list with her index.

This function take 2 arguments :
- The t_list you want to get the element.
- The index of your element.

This function return the t_list_node pointer of your element.

#### Prototype :
```c
t_list_node *tlist_get(t_list *list, tsize_t index);
```

Exemple :
```c
void main(void)
{
    char *my_string = "That my new string !";
    
    t_list *new_tlist = tlist_new();
    t_list_node *my_new_element = tlist_add(new_tlist, my_string);
}

void delet(t_list *new_tlist)
{
    t_list_node *my_get_element = tlist_get(new_tlist, 0); // <-- tlist_get
    tlist_remove(new_tlist, my_get_element);
}
```

### <ins>tlist_pop</ins>
The function tlist_pop allow you to destroy t_list.

This function take 2 arguments :
- The t_list you want to destroy.

This function return nothing.

#### Prototype :
```c
void *tlist_pop(t_list *list);
```

Exemple :
```c
void main(void)
{
    char *my_string = "That my new string !";
    
    t_list *new_tlist = tlist_new();
    t_list_node *my_new_element = tlist_add(new_tlist, my_string);
}

void destroy(t_list *new_tlist)
{
    tlist_pop(new_tlist);
}
```

### <ins>list_foreach</ins>
The function list_foreach allow is a implementation of a simple foreach in c for t_list.

#### What is foreach ?
Foreach is like a for but instead of increment a int with which you go get the content of the index of your list
le foreach will give you directly the t_list_node with the variable node.

Exemple :
```c
void main(void)
{
    char *my_string_a = "That my new string A!";
    char *my_string_b = "That my new string B!";
    char *my_string_c = "That my new string C!"; // <-- this value will be remove
    char *my_string_d = "That my new string D!";
    
    t_list *new_tlist = tlist_new();
    t_list_node *my_new_element = tlist_add(new_tlist, my_string_a);
    t_list_node *my_new_element = tlist_add(new_tlist, my_string_b);
    t_list_node *my_new_element = tlist_add(new_tlist, my_string_c);
    t_list_node *my_new_element = tlist_add(new_tlist, my_string_d);
}

void delet(t_list *new_tlist) // <-- remove only t_list_node with the value = "That my new string C!"
{
    char *temp;
    list_foreach(new_tlist, node) { // <-- list_foreach
        temp = node->value;
        if (tstr_cmp(temp, "That my new string C!") == 0) // <-- function of the lib tools_box (compare 2 string)
            tlist_remove(new_tlist, node);
    }
}
```