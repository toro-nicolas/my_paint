/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** The display_functions.c
*/

#include "csfml.h"

void display_all_dropdown(nodes_t *dropdown_list, sfRenderWindow *window)
{
    button_dropdown_t *cur_dropdown = NULL;

    for (nodes_t *tmp = dropdown_list; tmp != NULL; tmp = tmp->next) {
        cur_dropdown = (button_dropdown_t *)tmp->data;
        sfRenderWindow_drawRectangleShape(window,
        cur_dropdown->main_button->rect, NULL);
        sfRenderWindow_drawText(window,
        cur_dropdown->main_button->button_text, NULL);
        if (cur_dropdown->main_button->logo != NULL) {
            sfRenderWindow_drawSprite(window,
            cur_dropdown->main_button->logo, NULL);
        }
    }
}

void display_all_buttons(nodes_t *buttons_list, sfRenderWindow *window)
{
    button_t *cur_button = NULL;

    for (nodes_t *tmp = buttons_list; tmp != NULL; tmp = tmp->next) {
        cur_button = (button_t *)tmp->data;
        sfRenderWindow_drawRectangleShape(window, cur_button->rect, NULL);
        if (cur_button->logo != NULL) {
            sfRenderWindow_drawSprite(window, cur_button->logo, NULL);
        }
    }
}

void display_side_menu(nodes_t *list, sfRenderWindow *window)
{
    sfRectangleShape *cur_rect = NULL;

    for (nodes_t *tmp = list; tmp != NULL; tmp = tmp->next) {
        cur_rect = (sfRectangleShape *)tmp->data;
        sfRectangleShape_setSize(cur_rect, (sfVector2f){
            sfRectangleShape_getSize(cur_rect).x,
            sfRenderWindow_getSize(window).y});
        sfRenderWindow_drawRectangleShape(window, cur_rect, NULL);
    }
}
