/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** The init_shape.c
*/

#include "csfml.h"

button_t *init_square_shape(void)
{
    static sfVector2f pos = {20, 190};
    static button_t *square_shape = NULL;
    static sfTexture *texture = NULL;
    static sfSprite *sprite = NULL;

    if (square_shape != NULL)
        return square_shape;
    square_shape = init_button(pos,
        (sfVector2f){50, 50}, NULL, &button_square_shape);
    texture = sfTexture_createFromFile("assets/square.png", NULL);
    sprite = sfSprite_create();
    sfSprite_setScale(sprite, (sfVector2f){0.21, 0.21});
    sfSprite_setTexture(sprite, texture, false);
    sfSprite_setPosition(sprite, pos);
    square_shape->logo = sprite;
    return square_shape;
}

button_t *init_circle_shape(void)
{
    static sfVector2f pos = {85, 190};
    static button_t *circle_shape = NULL;
    static sfTexture *texture = NULL;
    static sfSprite *sprite = NULL;

    if (circle_shape != NULL)
        return circle_shape;
    circle_shape = init_button(pos,
        (sfVector2f){50, 50}, NULL, &button_circle_shape);
    texture = sfTexture_createFromFile("assets/circle.png", NULL);
    sprite = sfSprite_create();
    sfSprite_setScale(sprite, (sfVector2f){0.21, 0.21});
    sfSprite_setTexture(sprite, texture, false);
    sfSprite_setPosition(sprite, pos);
    circle_shape->logo = sprite;
    return circle_shape;
}

button_t *init_diamond_shape(void)
{
    static sfVector2f pos = {20, 260};
    static button_t *diamond_shape = NULL;
    static sfTexture *texture = NULL;
    static sfSprite *sprite = NULL;

    if (diamond_shape != NULL)
        return diamond_shape;
    diamond_shape = init_button(pos,
        (sfVector2f){50, 50}, NULL, &button_diamond_shape);
    texture = sfTexture_createFromFile("assets/diamond.png", NULL);
    sprite = sfSprite_create();
    sfSprite_setScale(sprite, (sfVector2f){0.21, 0.21});
    sfSprite_setTexture(sprite, texture, false);
    sfSprite_setPosition(sprite, pos);
    diamond_shape->logo = sprite;
    return diamond_shape;
}

button_t *init_hexagon_shape(void)
{
    static sfVector2f pos = {85, 260};
    static button_t *hexagon_shape = NULL;
    static sfTexture *texture = NULL;
    static sfSprite *sprite = NULL;

    if (hexagon_shape != NULL)
        return hexagon_shape;
    hexagon_shape = init_button(pos,
        (sfVector2f){50, 50}, NULL, &button_hexagon_shape);
    texture = sfTexture_createFromFile("assets/hexagon.png", NULL);
    sprite = sfSprite_create();
    sfSprite_setScale(sprite, (sfVector2f){0.21, 0.21});
    sfSprite_setTexture(sprite, texture, false);
    sfSprite_setPosition(sprite, pos);
    hexagon_shape->logo = sprite;
    return hexagon_shape;
}

void init_shape_button(game_info_t *game_info)
{
    push_b_doubly(&game_info->buttons_list, init_square_shape(), UNKNOW);
    push_b_doubly(&game_info->buttons_list, init_circle_shape(), UNKNOW);
    push_b_doubly(&game_info->buttons_list, init_diamond_shape(), UNKNOW);
    push_b_doubly(&game_info->buttons_list, init_hexagon_shape(), UNKNOW);
}
