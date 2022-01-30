/*
** EPITECH PROJECT, 2018
** Day05
** File description:
** task04
*/

#include "./my.h"

int my_compute_power_rec(int nb, int p)
{
    long result = 1;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    result = nb * my_compute_power_rec(nb, p - 1);
    if (result > 2147483647 || result < -2147483647)
        return (0);
    return (result);
}
