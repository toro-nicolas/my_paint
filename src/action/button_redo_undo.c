/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** The button_redo_undo.c
*/

#include "csfml.h"

nodes_t *dup_layer_list(nodes_t *list)
{
    nodes_t *new_list = NULL;
    sfImage *image;

    for (nodes_t *tmp = list; tmp != NULL; tmp = tmp->next) {
        image = sfImage_copy(tmp->data);
        push_b_doubly(&new_list, image, UNKNOW);
    }
    return new_list;
}

nodes_t *get_node_from_id(int id, nodes_t *list)
{
    int id_tmp = 0;

    for (nodes_t *tmp = list; tmp != NULL; tmp = tmp->next) {
        if (id_tmp == id)
            return tmp;
        id_tmp = id_tmp + 1;
    }
    return NULL;
}

void button_redo(button_t *button)
{
    nodes_t *node;

    get_game_info()->undo_redo_id = get_game_info()->undo_redo_id + 1;
    node = get_node_from_id(get_game_info()->undo_redo_id,
        get_game_info()->undo_redo_list);
    if (node != NULL) {
        get_game_info()->layers_list = dup_layer_list(
            ((layer_info_t *)node->data)->layer_list);
        get_game_info()->layer_id = ((layer_info_t *)node->data)->layer_id;
    } else {
        get_game_info()->undo_redo_id = get_game_info()->undo_redo_id - 1;
        return;
    }
}

void button_undo(button_t *button)
{
    nodes_t *node;

    if (get_game_info()->undo_redo_id <= -1)
        return;
    get_game_info()->undo_redo_id = get_game_info()->undo_redo_id - 1;
    node = get_node_from_id(get_game_info()->undo_redo_id,
        get_game_info()->undo_redo_list);
    if (node != NULL) {
        get_game_info()->layers_list = dup_layer_list(
            ((layer_info_t *)node->data)->layer_list);
        get_game_info()->layer_id = ((layer_info_t *)node->data)->layer_id;
    } else {
        get_game_info()->layers_list = NULL;
        get_game_info()->layer_id = -1;
    }
}

void save_in_undo_redo(game_info_t *game_info)
{
    layer_info_t *layer_info = MALLOC(sizeof(layer_info_t));
    int layer_added = 1;

    while (list_size(&game_info->undo_redo_list) - 1 >
    game_info->undo_redo_id)
        pop_b_doubly(&game_info->undo_redo_list);
    layer_info->layer_list = dup_layer_list(game_info->layers_list);
    layer_info->layer_id = game_info->layer_id;
    push_b_doubly(&game_info->undo_redo_list, layer_info, UNKNOW);
    get_game_info()->undo_redo_id += layer_added;
}
