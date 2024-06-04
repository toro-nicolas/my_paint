/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "csfml.h"

static void display_buttons(nodes_t *button_list, sfRenderWindow *window)
{
    button_t *button = NULL;

    for (nodes_t *tmp = button_list; tmp; tmp = tmp->next) {
        button = tmp->data;
        sfRenderWindow_drawRectangleShape(window, button->rect, NULL);
        sfRenderWindow_drawSprite(window, button->logo, NULL);
    }
}

static void check(game_info_t *game_info, sfFloatRect rect_i)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
        && sfFloatRect_contains(&rect_i,
        game_info->info_window->mouse_pos.x,
        game_info->info_window->mouse_pos.y)) {
        my_memset(game_info->popup->input_str, 0, 20);
        sfText_setString(game_info->popup->input, game_info->popup->input_str);
    }
}

static void display_the_text(game_info_t *game_info, sfFloatRect rect)
{
    sfFloatRect rect_t = sfText_getGlobalBounds(game_info->popup->text);
    sfFloatRect rect_i = sfText_getGlobalBounds(game_info->popup->input);
    sfVector2f pos;

    if (game_info->popup->text != NULL) {
        pos = (sfVector2f) {rect.left + (rect.width - rect_t.width) / 2,
        rect.top + (rect.height - (rect_t.height * 2))};
        sfText_setPosition(game_info->popup->text, pos);
        sfRenderWindow_drawText(game_info->info_window->window,
        game_info->popup->text, NULL);
    }
    if (game_info->popup->input != NULL) {
        pos = (sfVector2f) {rect.left + (rect.width - rect_i.width) / 2,
        rect.top + 30};
        sfText_setPosition(game_info->popup->input, pos);
        sfRenderWindow_drawText(game_info->info_window->window,
        game_info->popup->input, NULL);
    }
    check(game_info, rect_i);
}

void display_save_file(game_info_t *game_info)
{
    sfFloatRect rect;
    sfVector2i mouse_pos;

    display_all(game_info);
    handle_hover(game_info);
    analyse_events(game_info);
    display_all_layers(game_info->layers_list, game_info->info_window->window);
    sfRenderWindow_drawSprite(game_info->info_window->window,
    game_info->popup->popup_sprite_info->sprite, NULL);
    rect =
        sfSprite_getGlobalBounds(game_info->popup->popup_sprite_info->sprite);
    mouse_pos = game_info->info_window->mouse_pos;
    if (sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y))
        handle_hover(game_info);
    display_buttons(game_info->popup->buttons_list,
        game_info->info_window->window);
    display_the_text(game_info, rect);
    display_mouse(game_info);
}
