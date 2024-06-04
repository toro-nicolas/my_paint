/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** The init_redo_undo.c
*/

#include "csfml.h"

void init_redo_button(game_info_t *game_info)
{
    sfVector2f pos = {293, 0};
    button_t *redo_button = init_button(pos,
        (sfVector2f){50, 50}, NULL, &button_redo);
    sfTexture *texture = sfTexture_createFromFile("assets/redo.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, false);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, (sfVector2f){0.2, 0.2});
    redo_button->logo = sprite;
    push_b_doubly(&game_info->buttons_list, redo_button, UNKNOW);
}

void init_undo_button(game_info_t *game_info)
{
    sfVector2f pos = {243, 0};
    button_t *undo_button =
        init_button(pos, (sfVector2f) {50, 50}, NULL, &button_undo);
    sfTexture *texture = sfTexture_createFromFile("assets/undo.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, false);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, (sfVector2f){0.2, 0.2});
    undo_button->logo = sprite;
    push_b_doubly(&game_info->buttons_list, undo_button, UNKNOW);
}
