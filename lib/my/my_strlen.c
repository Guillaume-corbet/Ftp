/*
** EPITECH PROJECT, 2018
** Day04
** File description:
** task03
*/

#include "./my.h"

int my_strlen(char const *str)
{
    int counter = 0;

    while (str[counter] != '\0')
        counter = counter + 1;
    return (counter);
}