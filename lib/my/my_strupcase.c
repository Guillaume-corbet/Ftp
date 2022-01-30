/*
** EPITECH PROJECT, 2018
** Day06
** File description:
** task07
*/

#include "./my.h"

char *my_strupcase(char *str)
{
    int counter = 0;

    while (str[counter]) {
        if (str[counter] > 90 && str[counter] < 123) {
            str[counter] = str[counter] - 32;
        }
        counter = counter + 1;
    }
    return (str);
}
