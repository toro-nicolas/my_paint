/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** The button_file.c
*/

#include "csfml.h"

void button_jpg(button_t *button)
{
    my_printf(1, "JPG\n");
    get_format(JPG);
    get_game_info()->save_type = button;
}

void button_file(button_t *button)
{
    return;
}

void button_new(button_t *button)
{
    delete_list(&get_game_info()->layers_list, "n");
    get_game_info()->layer_id = -1;
    get_game_info()->layers_list = NULL;
}

void button_open(button_t *button)
{
    sprite_t si = {
    .texture = sfTexture_createFromFile("assets/popup.png", NULL),
    .rect = {0, 0, 400, 200}, .origin = {200, 100},
    .position = {1920 / 2, 1080 / 2}, .scale = {1, 1}, .id = "popup",
    .speed = (sfVector2f){0, 0}};

    get_game_info()->popup->popup_sprite_info = my_sprite(&si);
    init_png_format();
    init_bmp_format();
    init_jpg_format();
    get_game_info()->popup->state = OPEN_POPUP;
    get_game_info()->state = SAVE_FILE;
    sfText_setString(get_game_info()->popup->text, "OPEN FILE");
    sfText_setString(get_game_info()->popup->input, "name of file");
}

void button_save(button_t *button)
{
    sprite_t si = {
    .texture = sfTexture_createFromFile("assets/popup.png", NULL),
    .rect = {0, 0, 400, 200}, .origin = {200, 100},
    .position = {1920 / 2, 1080 / 2}, .scale = {1, 1}, .id = "popup",
    .speed = (sfVector2f){0, 0}};

    get_game_info()->popup->popup_sprite_info = my_sprite(&si);
    init_png_format();
    init_bmp_format();
    init_jpg_format();
    get_game_info()->state = SAVE_FILE;
    get_game_info()->popup->state = SAVE_POPUP;
    sfText_setString(get_game_info()->popup->text, "SAVE AS");
    sfText_setString(get_game_info()->popup->input, "name of file");
}
