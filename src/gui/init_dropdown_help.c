/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** The init_dropdown_file.c
*/

#include "csfml.h"

button_t *init_help_button(void)
{
    sfVector2f pos = {154, 0};
    text_t help_t =
    {.str = "Help", .size = 30,
    .position = (sfVector2f){pos.x + 12, pos.y + 5},
    .color = sfWhite, .scale = {1, 1}};
    sfFloatRect text_rect = sfText_getGlobalBounds(my_text(&help_t));
    sfVector2f size = {text_rect.width + 30, 50};
    button_t *help_b = init_button(pos,
        size, my_text(&help_t), &button_help);

    return help_b;
}

button_t *init_about_button(void)
{
    sfVector2f pos = {154, 50};
    text_t pencil_text =
    {.str = "About", .size = 30,
    .position = (sfVector2f){pos.x + 12, pos.y - 2}, .color = sfWhite,
    .scale = {1, 1}};
    sfFloatRect text_rect = sfText_getGlobalBounds(my_text(&pencil_text));
    sfVector2f size = {text_rect.width + 30, 40};
    button_t *about_button = init_button(pos,
    size, my_text(&pencil_text), &button_about);

    return about_button;
}

button_t *init_usage_button(void)
{
    sfVector2f pos = {154, 90};
    text_t pencil_text =
    {.str = "Usage", .size = 30,
    .position = (sfVector2f){pos.x + 12, pos.y - 2}, .color = sfWhite,
    .scale = {1, 1}};
    sfFloatRect text_rect = sfText_getGlobalBounds(my_text(&pencil_text));
    sfVector2f size = {text_rect.width + 30, 40};
    button_t *usage_button = init_button(pos,
    size, my_text(&pencil_text), &button_usage);

    return usage_button;
}

button_dropdown_t *init_help_dropdown(void)
{
    button_dropdown_t *edit_dropdown = MALLOC(sizeof(button_dropdown_t));

    edit_dropdown->button_options = NULL;
    edit_dropdown->main_button = init_help_button();
    push_b_doubly(&edit_dropdown->button_options,
        init_about_button(), UNKNOW);
    push_b_doubly(&edit_dropdown->button_options,
        init_usage_button(), UNKNOW);
    return edit_dropdown;
}
