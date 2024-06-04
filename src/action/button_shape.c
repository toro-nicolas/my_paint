/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** The button_shape.c
*/

#include "csfml.h"

void button_square_shape(button_t *button)
{
    get_game_info()->tool_info->shape = SQUARE;
    get_game_info()->tool_info->shape_button = button;
}

void button_circle_shape(button_t *button)
{
    get_game_info()->tool_info->shape = CIRCLE;
    get_game_info()->tool_info->shape_button = button;
}

void button_diamond_shape(button_t *button)
{
    get_game_info()->tool_info->shape = DIAMOND;
    get_game_info()->tool_info->shape_button = button;
}

void button_hexagon_shape(button_t *button)
{
    get_game_info()->tool_info->shape = HEXAGON;
    get_game_info()->tool_info->shape_button = button;
}
