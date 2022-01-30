/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** inic
*/

#include "serveur.h"

info_t *init_struct_info(char *path, int fd)
{
    info_t *info = malloc(sizeof(info_t));
    char *tmp = malloc(sizeof(char) * 1024);
    char *tmp2 = malloc(sizeof(char) * 1024);

    if (info == NULL || tmp == NULL)
        return (NULL);
    tmp = getcwd(tmp, 1024);
    chdir(path);
    tmp2 = getcwd(tmp2, 1024);
    chdir(tmp);
    info->path = strdup(tmp2);
    info->first_path = strdup(tmp2);
    info->fd_data = 0;
    info->fd = fd;
    info->username = malloc(sizeof(char) * 100);
    memset(info->username, '\0', 100);
    info->password = malloc(sizeof(char) * 100);
    memset(info->password, '\0', 100);
    free(tmp);
    free(tmp2);
    return (info);
}

int init_server(struct sockaddr_in addr)
{
    int fd = 0;

    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        perror("socket");
        return (-1);
    }
    if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return (-1);
    }
    if (listen(fd, 0) == -1) {
        perror("listen");
        return (-1);
    }
    return (fd);
}