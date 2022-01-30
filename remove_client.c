/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** remove_client
*/

#include "serveur.h"

rlist *remove_client(rlist *list, struct node *tmp)
{
    close(tmp->info->fd);
    if (tmp->info->fd_data != 0)
        close(tmp->info->fd_data);
    free(tmp->info->first_path);
    free(tmp->info->password);
    free(tmp->info->path);
    free(tmp->info->username);
    list = remove_element(list, tmp);
    return (list);
}