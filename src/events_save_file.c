/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "csfml.h"

static int str_cat(char *str, char *input)
{
    my_strcpy(str, input);
    if (*get_format(10) == PNG)
        my_strcat(str, ".png\0");
    if (*get_format(10) == BMP)
        my_strcat(str, ".bmp\0");
    if (*get_format(10) == JPG)
        my_strcat(str, ".jpg\0");
    return 0;
}

static int do_reste(sfImage *tmp_image, sfImage *image, int i)
{
    for (int j = 0; j < 600; j++) {
        if (compare_color(sfImage_getPixel(tmp_image, i, j),
            sfTransparent) == true && (*get_format(10) == JPG
            || *get_format(10) == BMP))
            sfImage_setPixel(image, i, j, sfWhite);
        if (compare_color(sfImage_getPixel(tmp_image, i, j),
            sfTransparent) == true)
            continue;
        sfImage_setPixel(image, i, j, sfImage_getPixel(tmp_image, i, j));
    }
    return 0;
}

static int save_file(game_info_t *game_info, char *input)
{
    sfImage *image = sfImage_createFromColor(1000, 600, sfTransparent);
    sfImage *tmp_image = NULL;
    char *str = MALLOC(my_strlen(input) + 5);

    if (my_strlen(input) == 0)
        return -1;
    str_cat(str, input);
    open(str, O_CREAT | O_RDWR, 0666);
    for (nodes_t *tmp = game_info->layers_list; tmp; tmp = tmp->next) {
        tmp_image = tmp->data;
        for (int i = 0; i < 1000; i++)
            do_reste(tmp_image, image, i);
    }
    sfImage_saveToFile(image, str);
    return 0;
}

static int get_letters(game_info_t *game_info, sfEvent event)
{
    if ((event.key.code >= 0 && event.key.code <= 25)) {
        if (my_strlen(game_info->popup->input_str) > 19)
            return 0;
        else {
            my_strcat(game_info->popup->input_str,
            (char[2]) {event.key.code + 97, 0});
            my_strcat(game_info->popup->input_str, "\0");
        }
        sfText_setString(game_info->popup->input, game_info->popup->input_str);
    }
}

static int open_file(game_info_t *game_info, char *input)
{
    char *str = MALLOC(my_strlen(input) + 5);
    sfImage *image;

    str_cat(str, input);
    image = sfImage_createFromFile(str);
    if (image == NULL) {
        sfText_setString(game_info->popup->input, "ERROR");
        return -1;
    }
    delete_list(&get_game_info()->layers_list, "n");
    get_game_info()->layer_id = -1;
    get_game_info()->layers_list = NULL;
    push_b_doubly(&game_info->layers_list, image, UNKNOW);
    game_info->layer_id = 0;
    game_info->state = MAIN;
    my_printf(1, "OPENED\n");
    delete_list(&game_info->popup->buttons_list, "n");
    return 0;
}

static int save_it(game_info_t *game_info, char *input)
{
    if (save_file(game_info, game_info->popup->input_str) == -1) {
        sfText_setString(game_info->popup->input, "ERROR");
    } else {
        sfText_setString(game_info->popup->input, "SAVED");
        game_info->state = MAIN;
        delete_list(&game_info->popup->buttons_list, "n");
    }
    return 0;
}

enum format *get_format(int format2)
{
    static enum format final_format = {0};

    if (format2 != 10)
        final_format = format2;
    return &final_format;
}

int analyse_key_pressed2(game_info_t *game_info, sfEvent event)
{
    int r = 0;

    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        game_info->state = MAIN;
        delete_list(&game_info->popup->buttons_list, "n");
    }
    get_letters(game_info, event);
    if (event.key.code == sfKeyBack) {
        game_info->popup->input_str
        [my_strlen(game_info->popup->input_str) - 1] = '\0';
        sfText_setString(game_info->popup->input, game_info->popup->input_str);
    }
    if (event.key.code == sfKeyReturn) {
        if (game_info->popup->state == OPEN_POPUP)
            open_file(game_info, game_info->popup->input_str);
        if (game_info->popup->state == SAVE_POPUP)
            save_it(game_info, game_info->popup->input_str);
        my_memset(game_info->popup->input_str, 0, 20);
    }
    return 0;
}

int analyse_mouse_pressed2(game_info_t *game_info)
{
    sfFloatRect rect = sfText_getGlobalBounds(game_info->popup->input);

    analyse_other_buttons(game_info, game_info->popup->buttons_list);
    return 0;
}

void events_save_file(game_info_t *game_info, sfEvent event)
{
    if (event.type == sfEvtKeyPressed)
        analyse_key_pressed2(game_info, event);
    if (event.type == sfEvtMouseButtonPressed) {
        game_info->mouse_state = HOLDED;
        analyse_mouse_pressed2(game_info);
    }
    if (event.type == sfEvtMouseButtonReleased) {
        game_info->mouse_state = NONE;
        game_info->info_window->old_mouse_pos = (sfVector2i){-1, -1};
    }
}
