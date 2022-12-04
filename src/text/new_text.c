/*
** EPITECH PROJECT, 2022
** new_text.c
** File description:
** desc
*/

#include <Class/t_class_window.h>
#include <Class/t_class_text.h>
#include <stdlib.h>
#include <t_string.h>

void init_new_text(text *new_text, char *content, uint32_t integer_color)
{
    new_text->sf_text = sfText_create();
    new_text->sf_color = sfColor_fromInteger(integer_color);
    sfText_setFont(new_text->sf_text, new_text->sf_font);
    sfText_setString(new_text->sf_text, content);
    sfText_setColor(new_text->sf_text, new_text->sf_color);
    new_text->list_flags = tlist_new();
    new_text->have_flag = text_have_flag;
    new_text->add_flag = text_add_flag;
    new_text->remove_flag = text_remove_flag;
    new_text->set_pos = text_set_pos;
    new_text->set_content = text_set_content;
    new_text->set_font_color = text_set_font_color;
    new_text->set_font_size = text_set_font_size;
    new_text->destroy = text_destroy;
    new_text->set_origin_center = text_set_origin_center;
}

text *new_text(scene *scene_datas, char *content
    , char *font, uint32_t integer_color)
{
    text *new_text = malloc(sizeof(text));
    t_list_node *new_text_node;

    if (new_text == NULL)
        return NULL;
    if ((new_text_node = tlist_add(scene_datas->list_texts
        , new_text)) == NULL || tstr_len(content) == 0) {
        free(new_text);
        return NULL;
    }
    if (font == NULL)
        font = "assets/font/Fruit Days.ttf";
    if ((new_text->sf_font = sfFont_createFromFile(font)) == NULL) {
        free(new_text);
        return NULL;
    }
    new_text->host = scene_datas;
    new_text->text_node = new_text_node;
    init_new_text(new_text, content, integer_color);
    return new_text;
}
