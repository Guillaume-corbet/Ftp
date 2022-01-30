/*
** EPITECH PROJECT, 2018
** Day06
** File description:
** task06
*/

#include "./my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int counter = 0;

    while (s1[counter] != '\0' && counter != n) {
        if (s1[counter] != s2[counter])
            return (1);
        counter = counter + 1;
    }
    return (0);
}
