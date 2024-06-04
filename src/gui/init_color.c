/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** The init_color.c
*/

#include "csfml.h"

void init_color_button(void)
{
    sfVector2f pos[] = {{20, 440}, {50, 440}, {80, 440}, {110, 440}, {20, 470},
    {50, 470}, {80, 470}, {110, 470}};
    sfColor color[] = {sfRed, sfGreen, sfBlue, sfYellow, sfBlack, sfWhite,
    sfMagenta, sfCyan};
    button_t *color_button = NULL;

    for (int i = 0; i < 8; i++) {
        color_button =
            init_button(pos[i], (sfVector2f){20, 20}, NULL, &button_color);
        sfRectangleShape_setFillColor(color_button->rect, color[i]);
        push_b_doubly(&get_game_info()->buttons_list, color_button, UNKNOW);
    }
}

button_t *init_current_color(void)
{
    static sfVector2f pos = {50, 650};
    static button_t *current_color = NULL;

    if (current_color != NULL)
        return current_color;
    current_color = init_button(pos,
    (sfVector2f){50, 50}, NULL, &button_color);
    push_b_doubly(&get_game_info()->buttons_list, current_color, UNKNOW);
    return current_color;
}

char *get_color_text(sfColor color)
{
    char *text = MALLOC(sizeof(char) * 8);

    text[0] = '#';
    if (color.r < 16)
        my_strcat(text, "0");
    my_strcat(text, my_str_nbr_base_unsigned_short_short
    (color.r, "0123456789ABCDEF"));
    if (color.g < 16)
        my_strcat(text, "0");
    my_strcat(text, my_str_nbr_base_unsigned_short_short
    (color.g, "0123456789ABCDEF"));
    if (color.b < 16)
        my_strcat(text, "0");
    my_strcat(text, my_str_nbr_base_unsigned_short_short
    (color.b, "0123456789ABCDEF"));
    return text;
}

sfText *display_color(void)
{
    text_t text = {.str = "", .size = 30,
        .position = (sfVector2f){10, 700}, .color = sfWhite, .scale = {1, 1}};
    static sfText *color_text = NULL;
    char *str = get_color_text(get_game_info()->tool_info->color);

    if (color_text == NULL) {
        color_text = my_text(&text);
        sfText_setFont(color_text, FONT);
    }
    sfText_setString(color_text, str);
    sfRenderWindow_drawText(get_game_info()->info_window->window,
    color_text, NULL);
    return color_text;
}
