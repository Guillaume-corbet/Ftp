/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** directory
*/

#include "serveur.h"

int get_point(char *str)
{
    int result = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.')
            result = result + 1;
    }
    return (result);
}

char *erase_path(char *tmp, int nb)
{
    for (int i = strlen(tmp) - 2; i > 0; i--) {
        if (tmp[i] == '/')
            nb = nb - 1;
        if (nb <= 1)
            break;
        tmp[i] = '\0';
    }
    return (tmp);
}

char *modif_tmp(char *path, char **tab, int size_new_path)
{
    int nb = 0;
    int i = 0;
    char *tmp = malloc(sizeof(char) * (strlen(path) + size_new_path) + 3);

    tmp = strcpy(tmp, path);
    while (i < length_tab(tab)) {
        nb = get_point(tab[i]);
        if (nb == 0) {
            if (tmp[strlen(tmp) - 1] != '/')
                tmp = strcat(tmp, "/");
            tmp = strcat(tmp, tab[i]);
            tmp = strcat(tmp, "/");
        } else if (nb > 1) {
            tmp = erase_path(tmp, nb);
        }
        i = i + 1;
    }
    return (tmp);
}

void verif_cwd(info_t *info, char *tmp)
{
    DIR *dir;
    int error = 0;

    if (strlen(info->first_path) > strlen(tmp))
        error = 1;
    else if (strncmp(tmp, info->first_path, strlen(info->first_path) -1) != 0)
        error = 1;
    dir = opendir(tmp);
    if (dir == NULL)
        error = 1;
    if (error == 1) {
        free(tmp);
        write_communication(info->fd, ERROR_CWD);
    } else {
        free(info->path);
        info->path = strdup(tmp);
        free(tmp);
        write_communication(info->fd, FILE_ACTION_GOOD);
    }
}

void verif_cdup(info_t *info, char *tmp)
{
    DIR *dir;
    int error = 0;

    if (strlen(info->first_path) > strlen(tmp))
        error = 1;
    else if (strncmp(tmp, info->first_path, strlen(info->first_path) -1) != 0)
        error = 1;
    dir = opendir(tmp);
    if (dir == NULL)
        error = 1;
    if (error == 1) {
        free(tmp);
        write_communication(info->fd, ERROR_CWD);
    } else {
        free(info->path);
        info->path = strdup(tmp);
        free(tmp);
        write_communication(info->fd, FILE_ACTION_GOOD);
    }
}