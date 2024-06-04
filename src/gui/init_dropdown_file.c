/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** The init_dropdown_file.c
*/

#include "csfml.h"

void fill_each_button2(sfVector2f pos, button_dropdown_t *dropdown,
    sfVector2f size)
{
    text_t new_filet =
    {.str = "new file", .size = 30,
    .position = (sfVector2f){pos.x + 12, pos.y + 50},
    .color = sfWhite, .scale = {1, 1}};
    text_t save_filet =
    {.str = "save file", .size = 30,
    .position = (sfVector2f){pos.x + 12, pos.y + 90},
    .color = sfWhite, .scale = {1, 1}};
    button_t *new_fileb =
    init_button((sfVector2f){pos.x, pos.y + 50},
    size, my_text(&new_filet), &button_new);
    button_t *save_fileb =
    init_button((sfVector2f){pos.x, pos.y + 90}, size,
    my_text(&save_filet), &button_save);

    push_b_doubly(&dropdown->button_options, new_fileb, UNKNOW);
    push_b_doubly(&dropdown->button_options, save_fileb, UNKNOW);
}

void fill_each_button(sfVector2f pos, button_dropdown_t *dropdown)
{
    text_t open_filet =
    {.str = "open file", .size = 30,
    .position = (sfVector2f){pos.x + 12, pos.y + 130 - 2},
    .color = sfWhite, .scale = {1, 1}};
    sfFloatRect text_rect = sfText_getGlobalBounds(my_text(&open_filet));
    sfVector2f size = {text_rect.width + 30, 40};
    button_t *open_fileb =
    init_button((sfVector2f){pos.x, pos.y + 130}, size,
    my_text(&open_filet), &button_open);

    push_b_doubly(&dropdown->button_options, open_fileb, UNKNOW);
    fill_each_button2(pos, dropdown, size);
}

button_dropdown_t *init_file_dropdown(void)
{
    button_dropdown_t *file_dropdown = MALLOC(sizeof(button_dropdown_t));
    sfVector2f pos = {0, 0};
    text_t file_text =
    {.str = "File", .size = 30,
    .position = (sfVector2f){pos.x + 12, pos.y + 5},
    .color = sfWhite, .scale = {1, 1}};
    sfFloatRect text_rect = sfText_getGlobalBounds(my_text(&file_text));
    sfVector2f size = {text_rect.width + 30, 50};
    button_t *file_button = init_button(pos, size, my_text(&file_text), NULL);

    file_dropdown->main_button = file_button;
    file_dropdown->button_options = NULL;
    fill_each_button(pos, file_dropdown);
    return file_dropdown;
}
