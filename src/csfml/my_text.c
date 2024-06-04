/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "csfml.h"

sfText *my_text(text_t *info_text)
{
    sfText *text = sfText_create();
    sfFont *font = NULL;

    if (info_text->font != NULL)
        font = sfFont_createFromFile(info_text->font);
    if (font != NULL)
        sfText_setFont(text, font);
    else
        sfText_setFont(text, FONT);
    sfText_setString(text, info_text->str);
    sfText_setCharacterSize(text, info_text->size);
    sfText_setColor(text, info_text->color);
    sfText_setStyle(text, info_text->style);
    sfText_setOutlineColor(text, info_text->outline_color);
    sfText_setOutlineThickness(text, info_text->outline_size);
    sfText_setScale(text, info_text->scale);
    sfText_setPosition(text, info_text->position);
    return text;
}
