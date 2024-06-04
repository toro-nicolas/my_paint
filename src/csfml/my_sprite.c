/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "csfml.h"

//  How to use ?
// create a sprite_t info_sprite like this = {.texture =...
// .rect = ... etc etc}

sprite_t *my_sprite(sprite_t *info_sprite)
{
    sprite_t *sprite = MALLOC(sizeof(sprite_t));

    sprite->texture = info_sprite->texture;
    sprite->text = info_sprite->text;
    sprite->rect = info_sprite->rect;
    sprite->origin = info_sprite->origin;
    sprite->id = info_sprite->id;
    sprite->scale = info_sprite->scale;
    sprite->position = info_sprite->position;
    sprite->sprite = sfSprite_create();
    sprite->speed = info_sprite->speed;
    sprite->clock = sfClock_create();
    sfSprite_setTexture(sprite->sprite, sprite->texture, false);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    sfSprite_setOrigin(sprite->sprite, sprite->origin);
    sfSprite_setPosition(sprite->sprite, sprite->position);
    sfSprite_setScale(sprite->sprite, sprite->scale);
    return sprite;
}
