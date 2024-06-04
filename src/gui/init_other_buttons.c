/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** The init_other_buttons.c
*/

#include "csfml.h"

void init_other_buttons(game_info_t *game_info)
{
    init_redo_button(game_info);
    init_undo_button(game_info);
    init_add_delete_layer_button(game_info);
    init_size_button(game_info);
    init_shape_button(game_info);
    init_zoom_button(game_info);
}
