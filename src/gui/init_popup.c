/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "csfml.h"

popup_t *get_popup(void)
{
    static popup_t popup = {0};

    return &popup;
}

int init_popup(game_info_t *game_info)
{
    text_t ti = {
    .color = HOVER_COLOR, .font = NULL, .scale = {1, 1},
    .position = (sfVector2f){1920 / 2 - 100, 1080 / 2 - 50}, .size = 30,
    .str = "test"
    };

    game_info->popup = get_popup();
    game_info->popup->buttons_list = NULL;
    game_info->popup->text = my_text(&ti);
    game_info->popup->input = my_text(&ti);
    game_info->popup->input_str = MALLOC(sizeof(char) * 20);
    game_info->popup->state = NONE_POPUP;
    my_memset(game_info->popup->input_str, 0, 20);
    return 0;
}
