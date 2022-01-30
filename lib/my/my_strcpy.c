/*
** EPITECH PROJECT, 2018
** Day06
** File description:
** task01
*/

#include "./my.h"
#include <stdlib.h>

char *my_strcpy(char *dest, char const *src)
{
    int counter = 0;

    while (src[counter] != '\0') {
        dest[counter] = src[counter];
        counter = counter + 1;
    }
    dest[counter] = '\0';
    return (dest);
}