/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "csfml.h"

sfRectangleShape *my_rectangle(sfVector2f position,
    sfVector2f size, sfColor color, int thickness)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    sfRectangleShape_setSize(rectangle, size);
    sfRectangleShape_setFillColor(rectangle, sfTransparent);
    sfRectangleShape_setOutlineColor(rectangle, color);
    sfRectangleShape_setOutlineThickness(rectangle, thickness);
    sfRectangleShape_setPosition(rectangle, position);
    return rectangle;
}

static void set_rectangle_shape_settings(rect_t *rectangle_shape,
    sfRectangleShape *rectangle)
{
    if (rectangle_shape->origin != NULL)
        sfRectangleShape_setOrigin(rectangle, *rectangle_shape->origin);
    if (rectangle_shape->scale != NULL)
        sfRectangleShape_setScale(rectangle, *rectangle_shape->scale);
    if (rectangle_shape->fill_color != 0)
        sfRectangleShape_setFillColor(rectangle,
        *rectangle_shape->fill_color);
    if (rectangle_shape->outline_color != 0)
        sfRectangleShape_setOutlineColor(rectangle,
        *rectangle_shape->outline_color);
    if (rectangle_shape->outline_thickness != 0.0)
        sfRectangleShape_setOutlineThickness(rectangle,
        rectangle_shape->outline_thickness);
    if (rectangle_shape->rotation != 0.0)
        sfRectangleShape_setRotation(rectangle, rectangle_shape->rotation);
    if (rectangle_shape->size != NULL)
        sfRectangleShape_setSize(rectangle, *rectangle_shape->size);
}

sfRectangleShape *create_rectangle_shape(rect_t *rectangle_shape,
    sfVector2f position)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    set_rectangle_shape_settings(rectangle_shape, rectangle);
    sfRectangleShape_setPosition(rectangle, position);
    return rectangle;
}
