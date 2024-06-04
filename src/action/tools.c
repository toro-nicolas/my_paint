/*
** EPITECH PROJECT, 2023
** tools
** File description:
** tools
*/

#include "csfml.h"

sfVector2i *get_point_list(sfVector2i point1, sfVector2i point2,
    int *nb_points)
{
    int err = abs(point2.x - point1.x) - abs(point2.y - point1.y);
    sfVector2i pos = {point1.x, point1.y};
    int nb = (abs(point2.x - point1.x) > abs(point2.y - point1.y)) ?
        abs(point2.x - point1.x) + 1 : abs(point2.y - point1.y) + 1;
    sfVector2i* points = MALLOC((nb) * sizeof(sfVector2i));

    for (int i = 0; i < nb && (pos.x != point2.x || pos.y != point2.y); i++) {
        points[i] = pos;
        if (2 * err > -abs(point2.y - point1.y)) {
            err -= abs(point2.y - point1.y);
            pos.x += (point1.x < point2.x) ? 1 : -1;
        }
        if (2 * err < abs(point2.x - point1.x)) {
            err += abs(point2.x - point1.x);
            pos.y += (point1.y < point2.y) ? 1 : -1;
        }
    }
    points[nb - 1] = point2;
    *nb_points = nb;
    return points;
}

static void put_pixel(sfImage *layer, sfVector2i pos, int i, int j)
{
    sfColor color = get_game_info()->tool_info->tool == ERASER ?
        sfTransparent : get_game_info()->tool_info->color;
    sfColor pixel_color = sfImage_getPixel(layer,
        pos.x + i - DECALE_W, pos.y + j - DECALE_H);

    if (get_game_info()->tool_info->tool == BRUSH)
        color = sfColor_fromRGBA(color.r, color.g, color.b,
        255 - (255 * (abs(i) + abs(j)) / (get_game_info()->tool_info->size)));
    if (pixel_color.r == color.r && pixel_color.g == color.g
    && pixel_color.b == color.b && pixel_color.a > color.a)
        color.a = pixel_color.a;
    sfImage_setPixel(layer, pos.x + i - DECALE_W,
        pos.y + j - DECALE_H, color);
}

static void set_pixels_shape_next(sfImage *layer, sfVector2i pos, int i, int j)
{
    int size = get_game_info()->tool_info->size / 2.0;

    if (get_game_info()->tool_info->shape == DIAMOND) {
        if (-size <= i <= size && abs(j) + abs(i) < size)
            put_pixel(layer, pos, i, j);
        return;
    }
    if (get_game_info()->tool_info->shape == HEXAGON) {
        if ((-size <= i <= size && abs(j) + abs(i) < size + 10))
            put_pixel(layer, pos, i, j);
        return;
    }
    put_pixel(layer, pos, i, j);
}

static void set_pixels_shape(sfImage *layer, sfVector2i pos, int i, int j)
{
    int size = get_game_info()->tool_info->size / 2.0;

    if (pos.x + i - DECALE_W < 0 || pos.x + i - DECALE_W >= 1000 ||
    pos.y + j - DECALE_H < 0 || pos.y + j - DECALE_H >= 600)
        return;
    if (get_game_info()->tool_info->shape == CIRCLE) {
        if (sqrt(pow(i, 2) + pow(j, 2)) <= size)
            put_pixel(layer, pos, i, j);
        return;
    }
    set_pixels_shape_next(layer, pos, i, j);
}

static void set_pixels(tool_info_t *tool, sfImage *layer, sfVector2i pos)
{
    int size = tool->size;

    if (tool->shape == DIAMOND || tool->shape == HEXAGON)
        size = size * 2;
    for (int i = -tool->size / 2; i < tool->size / 2; i++) {
        for (int j = -size / 2; j < size / 2; j++)
            set_pixels_shape(layer, pos, i, j);
    }
}

void pencil_tool(game_info_t *game_info)
{
    sfVector2i old_mouse_pos = game_info->info_window->old_mouse_pos;
    sfVector2i mouse_pos = game_info->info_window->mouse_pos;
    sfImage *layer = get_layer(game_info->layers_list, game_info->layer_id);
    sfVector2i *point_list;
    int nb = 0;

    if (game_info->mouse_state != HOLDED || layer == NULL)
        return;
    if (old_mouse_pos.x == -1 && old_mouse_pos.y == -1)
        old_mouse_pos = mouse_pos;
    point_list = get_point_list(old_mouse_pos, mouse_pos, &nb);
    for (int index = 0; index < nb; index++) {
        mouse_pos = point_list[index];
        set_pixels(game_info->tool_info, layer, mouse_pos);
    }
    game_info->info_window->old_mouse_pos = mouse_pos;
    game_info->mouse_is_painting = true;
}

sfRectangleShape *get_selection_frame(void)
{
    static sfRectangleShape *rect = NULL;

    if (rect == NULL) {
        rect = sfRectangleShape_create();
        sfRectangleShape_setOutlineColor(rect, sfGreen);
        sfRectangleShape_setOutlineThickness(rect, 4);
        sfRectangleShape_setFillColor(rect, sfTransparent);
        sfRectangleShape_setSize(rect, (sfVector2f){0, 0});
    }
    return rect;
}

void selection_tool(game_info_t *game_info)
{
    sfVector2i mouse_pos = game_info->info_window->mouse_pos;
    sfImage *layer = get_layer(game_info->layers_list, game_info->layer_id);
    sfRectangleShape *rect = get_selection_frame();

    if (game_info->mouse_state != HOLDED || layer == NULL)
        return;
    sfRectangleShape_setPosition(rect,
    (sfVector2f){game_info->first_spot.x, game_info->first_spot.y});
    sfRectangleShape_setSize(rect,
    (sfVector2f){mouse_pos.x - game_info->first_spot.x,
    mouse_pos.y - game_info->first_spot.y});
}

void do_tools(game_info_t *game_info)
{
    if (!mouse_on_layer(game_info))
        return;
    if (game_info->tool_info->tool != SELECTION)
        pencil_tool(game_info);
    else
        selection_tool(game_info);
}
