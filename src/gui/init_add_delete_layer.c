/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** The init_dropdown_file.c
*/

#include "csfml.h"

void init_add_layer_button(game_info_t *game_info)
{
    sfVector2f pos = {443, 0};
    button_t *add_layer_b = init_button(pos,
        (sfVector2f){50, 50}, NULL, &button_add_layer);
    sfTexture *texture =
        sfTexture_createFromFile("assets/add_layer.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setScale(sprite, (sfVector2f){0.2, 0.2});
    sfSprite_setTexture(sprite, texture, false);
    sfSprite_setPosition(sprite, pos);
    add_layer_b->logo = sprite;
    push_b_doubly(&game_info->buttons_list, add_layer_b, UNKNOW);
}

void init_delete_layer_button(game_info_t *game_info)
{
    sfVector2f pos = {493, 0};
    button_t *delete_layer_b = init_button(pos,
        (sfVector2f){50, 50}, NULL, &button_delete_layer);
    sfTexture *texture =
        sfTexture_createFromFile("assets/delete_layer.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setScale(sprite, (sfVector2f){0.2, 0.2});
    sfSprite_setTexture(sprite, texture, false);
    sfSprite_setPosition(sprite, pos);
    delete_layer_b->logo = sprite;
    push_b_doubly(&game_info->buttons_list, delete_layer_b, UNKNOW);
}

int init_add_delete_layer_button(game_info_t *game_info)
{
    init_add_layer_button(game_info);
    init_delete_layer_button(game_info);
    return 0;
}

static int my_nbrlen(int nb)
{
    int len = 0;

    if (nb == 0)
        return 1;
    if (nb < 0) {
        len++;
        nb = -nb;
    }
    while (nb > 0) {
        nb = nb / 10;
        len++;
    }
    return len;
}

sfText *display_layers_text(void)
{
    text_t text = {.str = "", .size = 20,
        .position = (sfVector2f){18, 750}, .color = sfWhite, .scale = {1, 1}};
    static sfText *layers_text = NULL;
    char *str = MALLOC(sizeof(char) * (9 + my_nbrlen(get_game_info()->layer_id
        + 1) + my_nbrlen(list_size(&get_game_info()->layers_list))));

    my_strcat(str, "Layer: ");
    my_strcat(str, my_str_nbr(get_game_info()->layer_id + 1));
    my_strcat(str, "/");
    my_strcat(str, my_str_nbr(list_size(&get_game_info()->layers_list)));
    if (layers_text == NULL) {
        layers_text = my_text(&text);
        sfText_setFont(layers_text, FONT);
    }
    sfText_setString(layers_text, str);
    sfRenderWindow_drawText(get_game_info()->info_window->window,
        layers_text, NULL);
    return layers_text;
}
