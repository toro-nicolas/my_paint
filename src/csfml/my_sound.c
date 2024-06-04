/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "csfml.h"

sfSound *my_sound(char const *filename)
{
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(filename);
    sfSound *sound = sfSound_create();

    sfSound_setBuffer(sound, buffer);
    return sound;
}
