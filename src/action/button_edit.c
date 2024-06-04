/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** The button_pencil.c
*/

#include "csfml.h"

void button_edit(button_t *button)
{
    return;
}

void button_pencil(button_t *button)
{
    get_game_info()->tool_info->tool = PENCIL;
    get_game_info()->tool_info->tool_button = button;
}

void button_eraser(button_t *button)
{
    get_game_info()->tool_info->tool = ERASER;
    get_game_info()->tool_info->tool_button = button;
}

void button_brush(button_t *button)
{
    get_game_info()->tool_info->tool = BRUSH;
    get_game_info()->tool_info->tool_button = button;
}

void button_selection(button_t *button)
{
    get_game_info()->tool_info->tool = SELECTION;
    get_game_info()->tool_info->tool_button = button;
}
