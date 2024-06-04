/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "csfml.h"

button_t *init_button(sfVector2f position, sfVector2f size, sfText *text,
    void (*action)(button_t *))
{
    sfColor color = sfColor_fromRGB(14, 19, 20);
    button_t *button = MALLOC(sizeof(button_t));
    rect_t rect = {.size = &size, .fill_color = &color,
        .outline_color = &sfBlack, .outline_thickness = -2};

    button->rect = create_rectangle_shape(&rect, position);
    button->action = action;
    button->hover = false;
    button->clicked = false;
    button->button_text = text;
    button->logo = NULL;
    return button;
}

button_t *sub_button_is_clicked(nodes_t *buttons_list,
    sfMouseButtonEvent mouse)
{
    button_t *cur_button = NULL;

    for (nodes_t *tmp = buttons_list; tmp != NULL; tmp = tmp->next) {
        cur_button = tmp->data;
        if (is_clicked(cur_button, mouse)) {
            return cur_button;
        }
    }
    return NULL;
}

button_dropdown_t *dropdown_is_clicked(nodes_t *dropdown_list,
    sfMouseButtonEvent mouse)
{
    button_dropdown_t *cur_dropdown = NULL;

    for (nodes_t *tmp = dropdown_list; tmp != NULL; tmp = tmp->next) {
        cur_dropdown = tmp->data;
        if (cur_dropdown->main_button->clicked) {
            return cur_dropdown;
        }
    }
    return NULL;
}

sfBool is_clicked(button_t *button, sfMouseButtonEvent mouse)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);
    sfVector2i mouse_pos = get_game_info()->info_window->mouse_pos;

    mouse.x = mouse_pos.x;
    mouse.y = mouse_pos.y;
    if (sfFloatRect_contains(&rect, mouse.x, mouse.y)) {
        button->clicked = true;
        my_printf(1, "clicked\n");
        return sfTrue;
    }
    button->clicked = false;
    return sfFalse;
}

sfBool is_hover(button_t *button, sfVector2i mouse)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfFloatRect_contains(&rect, mouse.x, mouse.y)) {
        button->hover = true;
        return sfTrue;
    }
    button->hover = false;
    return sfFalse;
}
