/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "csfml.h"

int convert_mouse_pos(game_info_t *game_info)
{
    sfVector2f mouse_pos;
    sfVector2f first_pos;

    mouse_pos = sfRenderWindow_mapPixelToCoords(game_info->info_window->window,
    game_info->info_window->mouse_pos, game_info->info_window->view);
    game_info->info_window->mouse_pos = (sfVector2i){mouse_pos.x, mouse_pos.y};
    first_pos = sfRenderWindow_mapPixelToCoords(game_info->info_window->window,
    game_info->first_spot, game_info->info_window->view);
    game_info->first_spot = (sfVector2i){first_pos.x, first_pos.y};
    return 0;
}

static void main_loop(game_info_t *game_info)
{
    sfTexture *texture = sfTexture_createFromFile("assets/texture.png", NULL);
    sfVector2f mouse_pos;
    sfRenderWindow *window = game_info->info_window->window;
    void (*display_scene[])
        (game_info_t *game_info) = {&display_main, &display_save_file,
        &display_help};

    while (sfRenderWindow_isOpen(game_info->info_window->window)) {
        sfRenderWindow_setView(window, game_info->tview);
        game_info->info_window->mouse_pos =
        sfMouse_getPositionRenderWindow(game_info->info_window->window);
        display_scene[game_info->state](game_info);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, (sfColor){96, 96, 96, 1});
    }
}

int print_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("    my_paint\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    A simple paint software ");
    my_putstr("made by Gianni TUERO and Nicolas TORO.\n");
    return 0;
}

int main(int argc, char **argv)
{
    game_info_t *game_info;

    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        return print_help();
    if (argc != 1)
        return 84;
    game_info = get_game_info();
    init_game_info(game_info);
    main_loop(game_info);
    free_game(game_info);
    return 0;
}
