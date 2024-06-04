/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "csfml.h"

int init_dropdown(nodes_t **dropdown_list)
{
    button_dropdown_t *file_dropdown = init_file_dropdown();
    button_dropdown_t *edit_dropdown = init_edit_dropdown();
    button_dropdown_t *help_dropdown = init_help_dropdown();

    push_b_doubly(dropdown_list, file_dropdown, UNKNOW);
    push_b_doubly(dropdown_list, edit_dropdown, UNKNOW);
    push_b_doubly(dropdown_list, help_dropdown, UNKNOW);
    return 0;
}
