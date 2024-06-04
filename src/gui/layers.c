/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "csfml.h"

sfSprite *img_to_sprite(sfImage *img, sfVector2f pos)
{
    static sfTexture *texture = NULL;
    static sfSprite *sprite = NULL;
    sfVector2u size = sfImage_getSize(img);

    if (texture == NULL)
        texture = sfTexture_createFromImage(img, NULL);
    if (sprite == NULL)
        sprite = sfSprite_create();
    sfTexture_updateFromImage(texture, img, 0, 0);
    sfSprite_setTexture(sprite, texture, false);
    sfSprite_setPosition(sprite, pos);
    return sprite;
}

int mouse_on_layer(game_info_t *game_info)
{
    sfImage *layer = NULL;
    sfVector2i mouse_pos = game_info->info_window->mouse_pos;
    sfSprite *sprite;
    sfFloatRect rect;

    layer = get_layer(game_info->layers_list, game_info->layer_id);
    if (layer == NULL) {
        game_info->info_window->old_mouse_pos = (sfVector2i){-1, -1};
        return 0;
    }
    sprite = img_to_sprite(layer, (sfVector2f){DECALE_W, DECALE_H});
    rect = sfSprite_getGlobalBounds(sprite);
    if (sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y))
        return 1;
    game_info->info_window->old_mouse_pos = (sfVector2i){-1, -1};
    return 0;
}

sfImage *get_layer(nodes_t *layers_list, int id)
{
    sfImage *layer = NULL;
    int i = 0;

    for (nodes_t *tmp = layers_list; tmp; tmp = tmp->next) {
        layer = tmp->data;
        if (i == id)
            return layer;
        i++;
    }
    return NULL;
}

void display_all_layers(nodes_t *layers_list, sfRenderWindow *window)
{
    sfImage *cur_layer = NULL;
    static sfImage *base_layer = NULL;
    sfSprite *sprite;

    if (get_game_info()->layer_id != -1) {
        if (base_layer == NULL)
            base_layer = sfImage_createFromColor(1000, 600, sfWhite);
        sprite =
            img_to_sprite(base_layer, (sfVector2f){DECALE_W, DECALE_H});
        sfRenderWindow_drawSprite(window, sprite, NULL);
    }
    for (nodes_t *tmp = layers_list; tmp; tmp = tmp->next) {
        cur_layer = tmp->data;
        sprite =
        img_to_sprite(cur_layer, (sfVector2f){DECALE_W, DECALE_H});
        sfRenderWindow_drawSprite(window, sprite, NULL);
    }
}
