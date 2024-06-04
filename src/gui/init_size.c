/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** The init_size.c
*/

#include "csfml.h"

sfText *display_size(void)
{
    text_t text = {.str = "", .size = 30,
        .position = (sfVector2f){18, 320}, .color = sfWhite, .scale = {1, 1}};
    static sfText *size_text = NULL;
    char *str = MALLOC(sizeof(char) * 10);

    my_strcat(str, "Size: ");
    my_strcat(str, my_str_nbr(get_game_info()->tool_info->size));
    if (size_text == NULL) {
        size_text = my_text(&text);
        sfText_setFont(size_text, FONT);
    }
    sfText_setString(size_text, str);
    sfRenderWindow_drawText(get_game_info()->info_window->window,
        size_text, NULL);
    return size_text;
}

void init_plus_size(game_info_t *game_info)
{
    sfVector2f pos = {20, 370};
    button_t *plus_size = init_button(pos,
        (sfVector2f){50, 50}, NULL, &button_plus_size);
    sfTexture *texture =
        sfTexture_createFromFile("assets/plus.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setScale(sprite, (sfVector2f){0.21, 0.21});
    sfSprite_setTexture(sprite, texture, false);
    sfSprite_setPosition(sprite, pos);
    plus_size->logo = sprite;
    push_b_doubly(&game_info->buttons_list, plus_size, UNKNOW);
}

void init_minus_size(game_info_t *game_info)
{
    sfVector2f pos = {85, 370};
    button_t *minus_size = init_button(pos,
        (sfVector2f){50, 50}, NULL, &button_minus_size);
    sfTexture *texture =
        sfTexture_createFromFile("assets/minus.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setScale(sprite, (sfVector2f){0.21, 0.21});
    sfSprite_setTexture(sprite, texture, false);
    sfSprite_setPosition(sprite, pos);
    minus_size->logo = sprite;
    push_b_doubly(&game_info->buttons_list, minus_size, UNKNOW);
}

void init_size_button(game_info_t *game_info)
{
    init_plus_size(game_info);
    init_minus_size(game_info);
}
