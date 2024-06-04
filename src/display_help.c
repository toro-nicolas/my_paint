/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "csfml.h"

void display_help(game_info_t *game_info)
{
    display_all(game_info);
    analyse_events(game_info);
    display_all_layers(game_info->layers_list, game_info->info_window->window);
    sfRenderWindow_drawSprite(game_info->info_window->window,
        game_info->popup->popup_sprite_info->sprite, NULL);
    display_mouse(game_info);
}
