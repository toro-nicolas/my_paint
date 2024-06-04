/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** The button_size.c
*/

#include "csfml.h"

/*
void button_plus_size(button_t *button)
{
    if (get_game_info()->tool_info->size < 100)
        get_game_info()->tool_info->size += 2;
}

void button_minus_size(button_t *button)
{
    if (get_game_info()->tool_info->size > 2)
        get_game_info()->tool_info->size -= 2;
}*/

void button_plus_size(button_t *button)
{
    return;
}

void button_minus_size(button_t *button)
{
    return;
}

void do_size(game_info_t *game_info)
{
    static int tick = 0;

    if (game_info->mouse_state != HOLDED)
        return;
    if (tick == 0 && sfIntRect_contains(&(sfIntRect){20, 370, 50, 50},
    game_info->info_window->mouse_pos.x,
    game_info->info_window->mouse_pos.y)) {
        if (get_game_info()->tool_info->size < 100)
            get_game_info()->tool_info->size += 2;
    }
    if (tick == 0 && sfIntRect_contains(&(sfIntRect){85, 370, 50, 50},
    game_info->info_window->mouse_pos.x,
    game_info->info_window->mouse_pos.y)) {
        if (get_game_info()->tool_info->size > 2)
            get_game_info()->tool_info->size -= 2;
    }
    tick++;
    if (tick > 8)
        tick = 0;
}
