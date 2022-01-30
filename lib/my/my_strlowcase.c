/*
** EPITECH PROJECT, 2018
** Day06
** File description:
** task08
*/

#include "./my.h"

char *my_strlowcase(char *str)
{
    int counter = 0;

    while (str[counter]) {
        if (str[counter] > 64 && str[counter] < 91) {
            str[counter] = str[counter] + 32;
        }
        counter = counter + 1;
    }
    return (str);
}
