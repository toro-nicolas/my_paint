/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "csfml.h"

void init_icon(void)
{
    sfVector2f pos = {20, 60};
    button_t *icon;
    sfTexture *texture =
        sfTexture_createFromFile("assets/icon.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setScale(sprite, (sfVector2f){0.21, 0.21});
    sfSprite_setTexture(sprite, texture, false);
    sfSprite_setPosition(sprite, pos);
    icon = init_button(pos, (sfVector2f){sfSprite_getGlobalBounds(sprite).width
    , sfSprite_getGlobalBounds(sprite).height}, NULL, &button_icon);
    icon->logo = sprite;
    sfRectangleShape_setFillColor(icon->rect, sfTransparent);
    push_b_doubly(&get_game_info()->buttons_list, icon, UNKNOW);
}

int init_side_menu(nodes_t **list)
{
    sfColor color = sfColor_fromRGB(14, 19, 20);
    rect_t rect_i = {
        .size = &(sfVector2f) {156, 1027},
        .fill_color = &color,
        .outline_color = &sfBlack,
        .outline_thickness = -2
    };
    sfRectangleShape *rectangle = create_rectangle_shape(&rect_i,
        (sfVector2f) {0, 50});

    push_b_doubly(list, rectangle, UNKNOW);
    init_icon();
    init_color_button();
    init_current_color();
    return 0;
}
