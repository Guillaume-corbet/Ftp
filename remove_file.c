/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** remove_file
*/

#include "serveur.h"

void verif_remove(info_t *info, char *tmp)
{
    int error = 0;

    if (strlen(info->first_path) > strlen(tmp))
        error = 1;
    else if (strncmp(tmp, info->first_path, strlen(info->first_path) -1) != 0)
        error = 1;
    if (error == 1) {
        free(tmp);
        write_communication(info->fd, ERROR_CWD);
    } else {
        if (tmp[strlen(tmp) - 1] == '/')
            tmp[strlen(tmp) - 1] = '\0';
        if (remove(tmp) == -1)
            write_communication(info->fd, ERROR_CWD);
        else
            write_communication(info->fd, FILE_ACTION_GOOD);
        free(tmp);
    }
}

char *delete_file(info_t *info, char *buffer)
{
    char **tab;
    char *tmp;

    buffer = get_next_elem(buffer);
    tab = str_to_word_array_sec(buffer, '/');
    if (buffer[0] == '/')
        tmp = strdup(buffer);
    else
        tmp = modif_tmp(info->path, tab, strlen(buffer) + 1);
    if (tmp[strlen(tmp) - 1] == '/')
        tmp[strlen(tmp) - 1] = '\0';
    verif_remove(info, tmp);
    free_tab(tab);
    return (buffer);
}