/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** get_element
*/

#include "serveur.h"

char *get_next_elem(char *command)
{
    int i = 0;
    int j = 0;
    char *str;

    while (command[i] != ' ')
        i = i + 1;
    i = i + 1;
    str = malloc(sizeof(char) * (strlen(command) - i) + 2);
    while (command[i] != '\r') {
        str[j] = command[i];
        i = i + 1;
        j = j + 1;
    }
    free(command);
    str[j] = '\0';
    return (str);
}

int get_one_port(char *buffer, int *i)
{
    char *str = malloc(sizeof(char) * 10);
    int j = 0;

    memset(str, '\0', 10);
    (*i) = (*i) + 1;
    while (buffer[(*i)] != ',' && buffer[(*i)] != '\0') {
        str[j] = buffer[(*i)];
        (*i) = (*i) + 1;
        j = j + 1;
    }
    str[j] = '\0';
    j = my_getnbr(str);
    free(str);
    return (j);
}

int get_port(char *buffer)
{
    int count = 0;
    int i = 0;
    int port_one = 0;
    int port_two = 0;

    while (count < 4) {
        if (buffer[i] == ',')
            count = count + 1;
        i = i + 1;
    }
    i = i - 1;
    port_one = get_one_port(buffer, &i);
    port_two = get_one_port(buffer, &i);
    return (((port_one) * 256) + port_two);
}

char *get_host(char *buffer)
{
    char *str = malloc(sizeof(char) * 20);
    int i = 0;
    int j = 0;
    int count = 0;

    memset(str, '\0', 20);
    while (buffer[i] != ' ')
        i = i + 1;
    i = i + 1;
    while (count < 4) {
        if (buffer[i] == ',') {
            count = count + 1;
            str[j] = '.';
        } else {
            str[j] = buffer[i];
        }
        i = i + 1;
        j = j + 1;
    }
    str[j - 1] = '\0';
    return (str);
}