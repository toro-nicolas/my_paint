/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** The button_redo_undo.c
*/

#include "csfml.h"

void button_zoom_out(button_t *button)
{
    sfView_zoom(get_game_info()->info_window->view, 1.1);
    return;
}

void button_zoom_in(button_t *button)
{
    sfView_zoom(get_game_info()->info_window->view, 0.9);
    return;
}
