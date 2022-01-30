/*
** EPITECH PROJECT, 2018
** Day07
** File description:
** task02
*/

#include "./my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    int size2 = my_strlen(dest);
    int counter = 0;

    while (src[counter] != '\0') {
        dest[size2] = src[counter];
        counter = counter + 1;
        size2 = size2 + 1;
    }
    dest[size2] = '\0';
    return (dest);
}