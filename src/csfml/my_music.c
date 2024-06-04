/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "csfml.h"

sfMusic *my_music(char const *filename)
{
    sfMusic *music = sfMusic_createFromFile(filename);

    sfMusic_setLoop(music, sfTrue);
    return music;
}
