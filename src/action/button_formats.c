/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** The button_file.c
*/

#include "csfml.h"

void button_png(button_t *button)
{
    my_printf(1, "PNG\n");
    get_format(PNG);
    get_game_info()->save_type = button;
}

void button_bmp(button_t *button)
{
    my_printf(1, "BMP\n");
    get_format(BMP);
    get_game_info()->save_type = button;
}

button_t *init_png_format(void)
{
    static sfVector2f pos = {1920 / 2 - 120, 1080 / 2 - 25};
    static button_t *png_button = NULL;
    static sfTexture *texture = NULL;
    static sfSprite *sprite = NULL;

    if (png_button == NULL) {
        png_button = init_button(pos, (sfVector2f) {50, 50},
            NULL, &button_png);
        texture = sfTexture_createFromFile("assets/png.png", NULL);
        sprite = sfSprite_create();
        sfSprite_setTexture(sprite, texture, false);
        sfSprite_setPosition(sprite, pos);
        sfSprite_setScale(sprite, (sfVector2f) {0.2, 0.2});
        png_button->logo = sprite;
        push_b_doubly(&get_game_info()->popup->buttons_list,
            png_button, UNKNOW);
    }
    return png_button;
}

button_t *init_bmp_format(void)
{
    static sfVector2f pos = {1920 / 2 - 60, 1080 / 2 - 25};
    static button_t *bmp_button = NULL;
    static sfTexture *texture = NULL;
    static sfSprite *sprite = NULL;

    if (bmp_button == NULL) {
        bmp_button = init_button(pos, (sfVector2f) {50, 50},
            NULL, &button_bmp);
        texture = sfTexture_createFromFile("assets/bmp.png", NULL);
        sprite = sfSprite_create();
        sfSprite_setTexture(sprite, texture, false);
        sfSprite_setPosition(sprite, pos);
        sfSprite_setScale(sprite, (sfVector2f) {0.2, 0.2});
        bmp_button->logo = sprite;
        push_b_doubly(&get_game_info()->popup->buttons_list,
            bmp_button, UNKNOW);
    }
    return bmp_button;
}

button_t *init_jpg_format(void)
{
    static sfVector2f pos = {1920 / 2 - 180, 1080 / 2 - 25};
    static button_t *jpg_button = NULL;
    static sfTexture *texture = NULL;
    static sfSprite *sprite = NULL;

    if (jpg_button == NULL) {
        jpg_button = init_button(pos, (sfVector2f) {50, 50},
            NULL, &button_jpg);
        texture = sfTexture_createFromFile("assets/jpg.png", NULL);
        sprite = sfSprite_create();
        sfSprite_setTexture(sprite, texture, false);
        sfSprite_setPosition(sprite, pos);
        sfSprite_setScale(sprite, (sfVector2f) {0.2, 0.2});
        jpg_button->logo = sprite;
        push_b_doubly(&get_game_info()->popup->buttons_list,
            jpg_button, UNKNOW);
    }
    return jpg_button;
}
