/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "csfml.h"

void display_all(game_info_t *game_info)
{
    display_all_dropdown(game_info->dropdown_list,
    game_info->info_window->window);
    display_side_menu(game_info->side_menu_list,
    game_info->info_window->window);
    display_all_buttons(game_info->buttons_list,
    game_info->info_window->window);
    display_size();
    display_color();
    display_layers_text();
    sfRenderWindow_drawSprite(game_info->info_window->window,
    game_info->tool_info->color_sprite, NULL);
}

static void display_rect(void)
{
    sfRenderWindow_drawRectangleShape(get_game_info()->info_window->window,
        get_selection_frame(), NULL);
}

void display_main(game_info_t *game_info)
{
    update_color(game_info);
    display_all(game_info);
    do_size(game_info);
    handle_hover(game_info);
    analyse_events(game_info);
    display_all_layers(game_info->layers_list,
        game_info->info_window->window);
    do_tools(game_info);
    display_mouse(game_info);
    display_rect();
}
