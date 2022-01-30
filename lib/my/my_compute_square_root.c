/*
** EPITECH PROJECT, 2018
** Day_05
** File description:
** task05
*/

#include "./my.h"

int my_compute_square_root(int nb)
{
    int result = 1;
    int result_modulo = 0;
    int multi = 1;
    int result_multi = 0;

    if (nb <= 0)
        return (0);
    if (nb >= 2147483647)
        return (0);
    while (result_multi != nb) {
        result_multi = multi * multi;
        multi = multi + 1;
        if (multi > 46341)
            return (0);
    }
    result = multi - 1;
    return (result);
}
