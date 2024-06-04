/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** The init_mouse.c
*/

#include "csfml.h"

sfSprite *init_pencil_mouse(void)
{
    static sfTexture *texture = NULL;
    static sfSprite *sprite = NULL;

    if (sprite != NULL)
        return sprite;
    texture = sfTexture_createFromFile("assets/pencil.png", NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, false);
    sfSprite_setScale(sprite, (sfVector2f){0.25, 0.25});
    return sprite;
}

sfSprite *init_eraser_mouse(void)
{
    static sfTexture *texture = NULL;
    static sfSprite *sprite = NULL;

    if (sprite != NULL)
        return sprite;
    texture = sfTexture_createFromFile("assets/eraser.png", NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, false);
    sfSprite_setScale(sprite, (sfVector2f){0.25, 0.25});
    return sprite;
}

sfSprite *init_select_mouse(void)
{
    static sfTexture *texture = NULL;
    static sfSprite *sprite = NULL;

    if (sprite != NULL)
        return sprite;
    texture = sfTexture_createFromFile("assets/select.png", NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, false);
    sfSprite_setScale(sprite, (sfVector2f){0.25, 0.25});
    return sprite;
}

void display_mouse(game_info_t *game_info)
{
    sfSprite *sprite = NULL;
    sfVector2f mouse_pos = {game_info->info_window->mouse_pos.x,
        game_info->info_window->mouse_pos.y};

    if (game_info->tool_info->tool == PENCIL ||
    game_info->tool_info->tool == BRUSH)
        sprite = init_pencil_mouse();
    if (game_info->tool_info->tool == ERASER)
        sprite = init_eraser_mouse();
    if (game_info->tool_info->tool == SELECTION)
        sprite = init_select_mouse();
    if (sprite == NULL)
        return;
    if (game_info->tool_info->tool != SELECTION)
        sfSprite_setPosition(sprite,
        (sfVector2f){mouse_pos.x, mouse_pos.y - 20});
    else
        sfSprite_setPosition(sprite,
        (sfVector2f){mouse_pos.x, mouse_pos.y - 3});
    sfRenderWindow_drawSprite(game_info->info_window->window, sprite, NULL);
}
