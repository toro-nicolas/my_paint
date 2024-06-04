/*
** EPITECH PROJECT, 2023
** add layer
** File description:
** add layer
*/

#include "csfml.h"

void button_add_layer(button_t *button)
{
    sfImage *layer;

    get_game_info()->layer_id++;
    layer = sfImage_createFromColor(1000, 600, sfTransparent);
    push_b_doubly(&get_game_info()->layers_list, layer, UNKNOW);
    my_printf(1, "layer added\n");
    save_in_undo_redo(get_game_info());
}

void button_delete_layer(button_t *button)
{
    nodes_t *tmp = NULL;

    if (get_game_info()->layer_id == -1)
        return;
    tmp = pop_b_doubly(&get_game_info()->layers_list);
    if (tmp)
        sfImage_destroy(tmp->data);
    if (list_size(&get_game_info()->layers_list) == get_game_info()->layer_id)
        get_game_info()->layer_id--;
    my_printf(1, "layer removed\n");
    save_in_undo_redo(get_game_info());
}
