/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** command_directory
*/

#include "serveur.h"

char *move_dir(info_t *info, char *buffer)
{
    char **tab;
    char *tmp;

    buffer = get_next_elem(buffer);
    tab = str_to_word_array_sec(buffer, '/');
    if (buffer[0] == '/')
        tmp = strdup(buffer);
    else
        tmp = modif_tmp(info->path, tab, strlen(buffer) + 1);
    verif_cwd(info, tmp);
    free_tab(tab);
    return (buffer);
}

void move_parent_dir(info_t *info)
{
    char *str = strdup("../");
    char **tab;
    char *tmp;

    tab = str_to_word_array_sec(str, '/');
    tmp = modif_tmp(info->path, tab, 1);
    verif_cdup(info, tmp);
    free_tab(tab);
}

char *get_dir(info_t *info, char *buffer)
{
    memset(buffer, '\0', 1024);
    buffer = strcpy(buffer, "257 \"");
    buffer = strcat(buffer, info->path);
    buffer = strcat(buffer, "\" created.\r\n");
    write_communication(info->fd, buffer);
    return (buffer);
}