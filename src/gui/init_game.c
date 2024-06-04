/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** The init_game.c
*/

#include "csfml.h"

static void init_tool_info(game_info_t *game_info)
{
    tool_info_t *tool_info = MALLOC(sizeof(tool_info_t));
    sfTexture *texture;

    tool_info->tool = PENCIL;
    tool_info->tool_button = init_pencil_button();
    tool_info->color = sfBlack;
    tool_info->color_image = sfImage_createFromFile("assets/color.png");
    texture = sfTexture_createFromImage(tool_info->color_image, NULL);
    tool_info->color_sprite = sfSprite_create();
    sfSprite_setTexture(tool_info->color_sprite, texture, sfTrue);
    sfSprite_setPosition(tool_info->color_sprite, (sfVector2f){18, 510});
    tool_info->size = 50;
    tool_info->shape = CIRCLE;
    tool_info->shape_button = init_circle_shape();
    game_info->tool_info = tool_info;
    sfRenderWindow_setMouseCursorVisible(game_info->info_window->window,
        sfFalse);
}

static void init_window_info(game_info_t *game_info)
{
    window_info_t *info_window = MALLOC(sizeof(window_info_t));
    sfImage *icon = sfImage_createFromFile("assets/icon.png");

    info_window->video_mode = (sfVideoMode) {1920, 1080, 32};
    info_window->window = sfRenderWindow_create(info_window->video_mode,
        "my_paint", sfDefaultStyle, NULL);
    sfRenderWindow_setPosition(info_window->window, (sfVector2i){0, 0});
    info_window->font = sfFont_createFromFile("assets/Cantarell.ttf");
    info_window->clock = sfClock_create();
    sfRenderWindow_setFramerateLimit(info_window->window, 120);
    info_window->framerate = 120;
    sfRenderWindow_setIcon(info_window->window, 550, 550,
        sfImage_getPixelsPtr(icon));
    sfImage_destroy(icon);
    info_window->delay = 0;
    info_window->resize = 1.0;
    info_window->old_mouse_pos = (sfVector2i){-1, -1};
    info_window->view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    game_info->tview = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    game_info->info_window = info_window;
}

void init_game_info(game_info_t *game_info)
{
    init_window_info(game_info);
    game_info->fd = -1;
    game_info->dropdown_list = NULL;
    game_info->buttons_list = NULL;
    game_info->layers_list = NULL;
    game_info->side_menu_list = NULL;
    game_info->undo_redo_list = NULL;
    game_info->mouse_state = NONE;
    init_tool_info(game_info);
    game_info->layer_id = -1;
    game_info->undo_redo_id = -1;
    init_dropdown(&game_info->dropdown_list);
    init_side_menu(&game_info->side_menu_list);
    init_other_buttons(game_info);
    init_popup(game_info);
    game_info->state = MAIN;
    game_info->first_spot = (sfVector2i){-1, -1};
    game_info->save_type = init_jpg_format();
}

game_info_t *get_game_info(void)
{
    static game_info_t game_info = {0};

    return &game_info;
}

static void free_window_info(game_info_t *game_info)
{
    sfClock_destroy(game_info->info_window->clock);
    sfSprite_destroy(game_info->info_window->sprite);
    sfTexture_destroy(game_info->info_window->texture);
    sfFont_destroy(game_info->info_window->font);
    sfRenderWindow_destroy(game_info->info_window->window);
    sfView_destroy(game_info->info_window->view);
    sfView_destroy(game_info->tview);
}

static void free_tool_info(game_info_t *game_info)
{
    sfTexture_destroy((sfTexture *)
        sfSprite_getTexture(game_info->tool_info->color_sprite));
    sfSprite_destroy(game_info->tool_info->color_sprite);
    sfImage_destroy(game_info->tool_info->color_image);
}

void free_game(game_info_t *game_info)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfText_destroy(display_color());
    sfText_destroy(display_size());
    sfText_destroy(display_layers_text());
    free_window_info(game_info);
    free_tool_info(game_info);
    sfRectangleShape_destroy(game_info->side_menu_list->data);
    sfCircleShape_destroy(circle);
    FREE;
}
