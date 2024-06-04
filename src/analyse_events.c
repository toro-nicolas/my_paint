/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "csfml.h"

int analyse_other_buttons(game_info_t *game_info, nodes_t *button_list)
{
    button_t *button = NULL;
    sfMouseButtonEvent mouse = game_info->info_window->event.mouseButton;

    for (nodes_t *tmp = button_list; tmp; tmp = tmp->next) {
        button = tmp->data;
        if (is_clicked(button, mouse)) {
            button->action(button);
        }
    }
}

void analyse_events(game_info_t *game_info)
{
    sfEvent event;
    void (*manage_evt[]) (game_info_t *game_info, sfEvent event)
        = {&events_main, &events_save_file, &events_help};

    while (sfRenderWindow_pollEvent(game_info->info_window->window,
        &game_info->info_window->event)) {
        event = game_info->info_window->event;
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game_info->info_window->window);
        if (event.type == sfEvtResized)
            analyse_resize(game_info->info_window->window, event);
        manage_evt[game_info->state](game_info, event);
    }
    display_if_clicked(game_info);
    sfRenderWindow_setView(game_info->info_window->window,
        game_info->info_window->view);
    convert_mouse_pos(game_info);
}
