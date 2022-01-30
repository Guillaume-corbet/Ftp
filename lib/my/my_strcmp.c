/*
** EPITECH PROJECT, 2018
** Day06
** File description:
** task05
*/

#include "./my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int counter = 0;

    if (my_strlen(s1) != my_strlen(s2))
        return (1);
    while (s1[counter] != '\0') {
        if (s1[counter] != s2[counter])
            return (1);
        counter = counter + 1;
    }
    return (0);
}