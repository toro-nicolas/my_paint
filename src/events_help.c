/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "csfml.h"

void events_help(game_info_t *game_info, sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyEscape)
            game_info->state = MAIN;
    }
    if (event.type == sfEvtMouseButtonPressed)
        game_info->mouse_state = HOLDED;
    if (event.type == sfEvtMouseButtonReleased) {
        game_info->mouse_state = NONE;
        game_info->info_window->old_mouse_pos = (sfVector2i){-1, -1};
    }
}
