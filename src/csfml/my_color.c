/*
** EPITECH PROJECT, 2024
** mypaint
** File description:
** The my_color.c
*/

#include "csfml.h"

bool compare_color(sfColor color1, sfColor color2)
{
    if (color1.r == color2.r && color1.g == color2.g && color1.b == color2.b
    && color1.a == color2.a)
        return true;
    return false;
}
