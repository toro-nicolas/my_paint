/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "csfml.h"

void display_sub_buttons(game_info_t *game_info, nodes_t **button_options)
{
    button_t *cur_button = NULL;
    sfRenderWindow *window = game_info->info_window->window;

    for (nodes_t *tmp = *button_options; tmp != NULL; tmp = tmp->next) {
        cur_button = tmp->data;
        sfRenderWindow_drawRectangleShape(window, cur_button->rect, NULL);
        sfRenderWindow_drawText(window, cur_button->button_text, NULL);
        if (cur_button->logo != NULL)
            sfRenderWindow_drawSprite(window, cur_button->logo, NULL);
        if (is_hover(cur_button, sfMouse_getPositionRenderWindow(window))) {
            sfRectangleShape_setFillColor(cur_button->rect, HOVER_COLOR);
            continue;
        }
        if (game_info->tool_info->tool_button == cur_button ||
        game_info->save_type == cur_button)
            sfRectangleShape_setFillColor(cur_button->rect, HOLDED_COLOR);
        else
            sfRectangleShape_setFillColor(cur_button->rect, NONE_COLOR);
    }
}

static void check_is_color(button_t *cur_button, game_info_t *game_info)
{
    if (is_hover(cur_button, game_info->info_window->mouse_pos) &&
    compare_color(sfRectangleShape_getFillColor(cur_button->rect),
    NONE_COLOR) == false && compare_color(sfRectangleShape_getFillColor(
    cur_button->rect), HOLDED_COLOR) == false)
        sfRectangleShape_setOutlineColor(cur_button->rect,
        sfRectangleShape_getFillColor(cur_button->rect));
    if (is_hover(cur_button, game_info->info_window->mouse_pos) == 0 &&
    compare_color(sfRectangleShape_getFillColor(cur_button->rect),
    NONE_COLOR) == false && compare_color(sfRectangleShape_getFillColor(
    cur_button->rect), HOLDED_COLOR) == false)
        sfRectangleShape_setOutlineColor(cur_button->rect,
        sfColor_fromRGB(50, 50, 50));
    if (compare_color(sfRectangleShape_getFillColor(cur_button->rect),
    sfTransparent) == true)
        sfRectangleShape_setOutlineColor(cur_button->rect, sfTransparent);
}

static void check_holded_color(button_t *cur_button, game_info_t *game_info)
{
    if (game_info->tool_info->shape_button == cur_button ||
        game_info->save_type == cur_button)
        sfRectangleShape_setFillColor(cur_button->rect, HOLDED_COLOR);
    if (game_info->tool_info->shape_button != cur_button &&
        game_info->save_type != cur_button && compare_color(
        sfRectangleShape_getFillColor(cur_button->rect), HOLDED_COLOR))
        sfRectangleShape_setFillColor(cur_button->rect, NONE_COLOR);
}

void buttons_differs(button_t *cur_button, game_info_t *game_info,
    button_dropdown_t *cur_dropdown)
{
    check_holded_color(cur_button, game_info);
    if (is_hover(cur_button, game_info->info_window->mouse_pos)) {
        if (cur_button->button_text == NULL)
            sfRectangleShape_setOutlineColor(cur_button->rect, sfRed);
        else
            sfRectangleShape_setFillColor(cur_dropdown->main_button->rect,
            HOVER_COLOR);
    } else {
        if (cur_button->button_text == NULL)
            sfRectangleShape_setOutlineColor(cur_button->rect, sfBlack);
        else
            sfRectangleShape_setFillColor(cur_dropdown->main_button->rect,
            NONE_COLOR);
    }
    check_is_color(cur_button, game_info);
}

static void check_popup(game_info_t *game_info)
{
    button_t *cur_button = NULL;
    button_dropdown_t *cur_dropdown = NULL;

    for (nodes_t *tmp = game_info->popup->buttons_list;
        tmp != NULL; tmp = tmp->next) {
        cur_button = tmp->data;
        buttons_differs(cur_button, game_info, cur_dropdown);
    }
}

void handle_hover(game_info_t *game_info)
{
    button_dropdown_t *cur_dropdown = NULL;
    button_t *cur_button = NULL;

    for (nodes_t *tmp = game_info->dropdown_list; tmp != NULL;
        tmp = tmp->next) {
        cur_dropdown = tmp->data;
        if (is_hover(cur_dropdown->main_button,
            game_info->info_window->mouse_pos))
            sfRectangleShape_setFillColor(cur_dropdown->main_button->rect,
            HOVER_COLOR);
        else
            sfRectangleShape_setFillColor(cur_dropdown->main_button->rect,
            NONE_COLOR);
    }
    for (nodes_t *tmp = game_info->buttons_list;
        tmp != NULL; tmp = tmp->next) {
        cur_button = tmp->data;
        buttons_differs(cur_button, game_info, cur_dropdown);
    }
    check_popup(game_info);
}

void display_if_clicked(game_info_t *game_info)
{
    button_dropdown_t *cur_dropdown = NULL;

    for (nodes_t *tmp = game_info->dropdown_list;
        tmp != NULL; tmp = tmp->next) {
        cur_dropdown = (button_dropdown_t *)tmp->data;
        if (cur_dropdown->main_button->clicked) {
            display_sub_buttons(game_info, &cur_dropdown->button_options);
        }
    }
}
