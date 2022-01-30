/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** str_to_word_array
*/

#include "serveur.h"

int supress_space(char *str, int i)
{
    while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && STR)
        i = i + 1;
    return (i);
}

int count_words(char *str)
{
    int number = 0;
    int i = 0;
    int y = 0;

    i = supress_space(str, i);
    while (str[i] != '\0') {
        y = i;
        i = supress_space(str, i);
        if (i != y)
            number = number + 1;
        if (str[i] != '\0')
            i = i + 1;
    }
    number = number + 2;
    return (number);
}

void intern_while_one(int *i, int *y, int *x, int a)
{
    if (a == 1) {
        *i = *i + 1;
        *y = *y + 1;
    } else if (a == 2) {
        *y = 0;
        *x = *x + 1;
    }
}

char **str_to_word_array(char *str)
{
    char **tab;
    int i = 0;
    int x = 0;
    int y = 0;

    if ((tab = malloc(sizeof(char *) * count_words(str))) == NULL)
        return (NULL);
    i = supress_space(str, i);
    while (STR) {
        if ((tab[x] = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
            return (NULL);
        while (STR && str[i] != '\n' && str[i] != ' ' && str[i] != '\t') {
            tab[x][y] = str[i];
            intern_while_one(&i, &y, &x, 1);
        }
        tab[x][y] = '\0';
        i = supress_space(str, i);
        intern_while_one(&i, &y, &x, 2);
    }
    tab[x] = NULL;
    return (tab);
}

char **str_to_word_array_sec(char *str, char c)
{
    char **tab;
    int i = 0;
    int x = 0;
    int y = 0;

    if ((tab = malloc(sizeof(char *) * my_strlen(str))) == NULL)
        return (NULL);
    while (str[i] != '\0') {
        if ((tab[x] = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
            return (NULL);
        memset(tab[x], '\0', strlen(str) + 1);
        while (str[i] != '\0' && str[i] != c) {
            tab[x][y] = str[i];
            intern_while_one(&i, &y, &x, 1);
        }
        if (str[i] != '\0')
            i = i + 1;
        intern_while_one(&i, &y, &x, 2);
    }
    tab[x] = NULL;
    return (tab);
}