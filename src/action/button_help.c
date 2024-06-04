/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** The button_help.c
*/

#include "csfml.h"

void button_help(button_t *button)
{
    return;
}

void button_about(button_t *button)
{
    sprite_t si = {
    .texture = sfTexture_createFromFile("assets/credits.png", NULL),
    .rect = {0, 0, 400, 200}, .origin = {200, 100},
    .position = {1920 / 2, 1080 / 2}, .scale = {1, 1}, .id = "popup",
    .speed = (sfVector2f){0, 0}};

    get_game_info()->popup->popup_sprite_info = my_sprite(&si);
    get_game_info()->state = HELP;
    return;
}

void button_usage(button_t *button)
{
    sprite_t si = {
    .texture = sfTexture_createFromFile("assets/help.png", NULL),
    .rect = {0, 0, 400, 243}, .origin = {200, 100},
    .position = {1920 / 2, 1080 / 2}, .scale = {1, 1}, .id = "popup",
    .speed = (sfVector2f){0, 0}};

    get_game_info()->popup->popup_sprite_info = my_sprite(&si);
    get_game_info()->state = HELP;
    return;
}

void button_icon(button_t *button)
{
    return;
}
