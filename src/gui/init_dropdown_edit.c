/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** The init_dropdown_file.c
*/

#include "csfml.h"

static button_t *init_edit_button(void)
{
    sfVector2f pos = {74, 0};
    text_t edit_text =
        {.str = "Edit",
        .size = 30,
        .position = (sfVector2f) {pos.x + 13, pos.y + 5},
        .color = sfWhite,
        .scale = {1, 1}
        };
    sfFloatRect text_rect = sfText_getGlobalBounds(my_text(&edit_text));
    sfVector2f size = {text_rect.width + 30, 50};
    button_t *edit_button = init_button(pos, size,
        my_text(&edit_text), &button_edit);

    return edit_button;
}

button_t *init_pencil_button(void)
{
    static sfVector2f pos = {74, 50};
    text_t pencil_text =
        {.str = "Pencil",
        .size = 30,
        .font = NULL,
        .position = (sfVector2f) {pos.x + 12, pos.y - 2},
        .color = sfWhite,
        .scale = {1, 1}
        };
    sfFloatRect text_rect = sfText_getGlobalBounds(my_text(&pencil_text));
    static sfVector2f size = {115, 40};
    static button_t *pencil_button = NULL;

    if (pencil_button == NULL)
        pencil_button = init_button(pos, size,
        my_text(&pencil_text), &button_pencil);
    return pencil_button;
}

button_t *init_eraser_button(void)
{
    sfVector2f pos = {74, 90};
    text_t eraser_text =
        {.str = "Eraser",
        .size = 30,
        .position = (sfVector2f) {pos.x + 12, pos.y - 2},
        .color = sfWhite,
        .scale = {1, 1}
        };
    sfFloatRect text_rect = sfText_getGlobalBounds(my_text(&eraser_text));
    sfVector2f size = {text_rect.width + 30, 40};
    button_t *eraser_button = init_button(pos,
        size, my_text(&eraser_text), &button_eraser);

    return eraser_button;
}

button_t *init_brush_button(void)
{
    static sfVector2f pos = {74, 130};
    text_t brush_text =
        {.str = "Brush",
            .size = 30,
            .font = NULL,
            .position = (sfVector2f) {pos.x + 12, pos.y - 2},
            .color = sfWhite,
            .scale = {1, 1}
        };
    sfFloatRect text_rect = sfText_getGlobalBounds(my_text(&brush_text));
    static sfVector2f size = {115, 40};
    static button_t *brush_button = NULL;

    if (brush_button == NULL)
        brush_button = init_button(pos, size,
        my_text(&brush_text), &button_brush);
    return brush_button;
}

button_t *init_selection_button(void)
{
    sfVector2f pos = {74, 170};
    text_t eraser_text =
        {.str = "Select",
        .size = 30,
        .position = (sfVector2f) {pos.x + 12, pos.y - 2},
        .color = sfWhite,
        .scale = {1, 1}
        };
    sfFloatRect text_rect = sfText_getGlobalBounds(my_text(&eraser_text));
    sfVector2f size = {text_rect.width + 32, 40};
    button_t *eraser_button = init_button(pos,
        size, my_text(&eraser_text), &button_selection);

    return eraser_button;
}

button_dropdown_t *init_edit_dropdown(void)
{
    button_dropdown_t *edit_dropdown = MALLOC(sizeof(button_dropdown_t));

    edit_dropdown->button_options = NULL;
    edit_dropdown->main_button = init_edit_button();
    push_b_doubly(&edit_dropdown->button_options,
        init_pencil_button(), UNKNOW);
    push_b_doubly(&edit_dropdown->button_options,
        init_eraser_button(), UNKNOW);
    push_b_doubly(&edit_dropdown->button_options,
        init_brush_button(), UNKNOW);
    push_b_doubly(&edit_dropdown->button_options,
        init_selection_button(), UNKNOW);
    return edit_dropdown;
}
