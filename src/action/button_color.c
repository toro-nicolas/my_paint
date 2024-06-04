/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** The button_pencil.c
*/

#include "csfml.h"

void button_color(button_t *button)
{
    get_game_info()->tool_info->color =
        sfRectangleShape_getFillColor(button->rect);
    my_printf(1, "COLOR\n");
}

static void change_color(game_info_t *game_info)
{
    sfColor color = sfImage_getPixel(game_info->tool_info->color_image,
    game_info->info_window->mouse_pos.x - 18,
    game_info->info_window->mouse_pos.y - 510);

    if (compare_color(color, sfTransparent) == false)
        game_info->tool_info->color = color;
}

int mouse_on_color(game_info_t *game_info)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(
        game_info->tool_info->color_sprite);

    if (sfFloatRect_contains(&rect, game_info->info_window->mouse_pos.x,
    game_info->info_window->mouse_pos.y)) {
        change_color(game_info);
        return 1;
    }
    return 0;
}

void update_color(game_info_t *game_info)
{
    sfRectangleShape_setFillColor(init_current_color()->rect,
    game_info->tool_info->color);
}
