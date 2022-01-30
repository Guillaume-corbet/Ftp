/*
** EPITECH PROJECT, 2018
** Day 04
** File description:
** task01
*/

#include "./my.h"

int my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
    return (0);
}