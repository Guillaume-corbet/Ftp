/*
** EPITECH PROJECT, 2018
** Day07
** File description:
** task03
*/

#include "./my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int size2 = 0;
    int counter = 0;

    size2 = my_strlen(dest);
    while (counter < nb) {
        dest[size2] = src[counter];
        counter = counter + 1;
        size2 = size2 + 1;
    }
    return (dest);
}
