/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "csfml.h"

int analyse_key_released(void)
{
    return 0;
}

static void analyse_arrow_pressed(game_info_t *game_info)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (get_game_info()->tool_info->size < 100)
            game_info->tool_info->size += 2;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        if (get_game_info()->tool_info->size > 2)
            game_info->tool_info->size -= 2;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && game_info->layer_id > 0)
        game_info->layer_id--;
    if (sfKeyboard_isKeyPressed(sfKeyRight) && game_info->layer_id <
    list_size(&game_info->layers_list) - 1)
        game_info->layer_id++;
}

int analyse_key_pressed(game_info_t *game_info)
{
    sfView *view = game_info->info_window->view;

    if (sfKeyboard_isKeyPressed(sfKeyX))
        sfView_zoom(view, 0.90);
    if (sfKeyboard_isKeyPressed(sfKeyW))
        sfView_zoom(view, 1.10);
    if (sfKeyboard_isKeyPressed(sfKeyP))
        button_pencil(init_pencil_button());
    if (sfKeyboard_isKeyPressed(sfKeyE))
        button_eraser(init_eraser_button());
    analyse_arrow_pressed(game_info);
    return 0;
}

int analyse_resize(sfRenderWindow *window, sfEvent event)
{
    sfFloatRect visible = {0, 0, event.size.width, event.size.height};
    sfView *view = sfView_createFromRect(visible);

    get_game_info()->tview = view;
    return 0;
}

static int already_clicked(button_dropdown_t *cur_dropdown,
    sfMouseButtonEvent mouse)
{
    button_t *button = NULL;

    if (cur_dropdown->main_button->clicked) {
        button =
        sub_button_is_clicked(cur_dropdown->button_options, mouse);
        if (button != NULL)
            button->action(button);
    }
}

int analyse_mouse_pressed(game_info_t *game_info)
{
    button_dropdown_t *cur_dropdown = NULL;
    button_t *button = NULL;
    sfMouseButtonEvent mouse = game_info->info_window->event.mouseButton;

    if (mouse_on_layer(game_info) || mouse_on_color(game_info))
        return 0;
    for (nodes_t *tmp = game_info->dropdown_list;
        tmp != NULL; tmp = tmp->next) {
        cur_dropdown = (button_dropdown_t *)tmp->data;
        already_clicked(cur_dropdown, mouse);
        is_clicked(cur_dropdown->main_button, mouse);
    }
    analyse_other_buttons(game_info, game_info->buttons_list);
    return 0;
}

void events_main(game_info_t *game_info, sfEvent event)
{
    if (event.type == sfEvtKeyPressed)
        analyse_key_pressed(game_info);
    if (event.type == sfEvtKeyReleased)
        analyse_key_released();
    if (event.type == sfEvtMouseButtonPressed) {
        if (game_info->mouse_state != HOLDED)
            game_info->first_spot = game_info->info_window->mouse_pos;
        game_info->mouse_state = HOLDED;
        analyse_mouse_pressed(game_info);
    }
    if (event.type == sfEvtMouseButtonReleased) {
        if (game_info->mouse_is_painting == true)
            save_in_undo_redo(game_info);
        game_info->mouse_is_painting = false;
        game_info->mouse_state = NONE;
        game_info->info_window->old_mouse_pos = (sfVector2i){-1, -1};
    }
}
