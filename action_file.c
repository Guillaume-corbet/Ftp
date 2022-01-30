/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** action_file
*/

#include "serveur.h"

char *download_file(info_t *info, char *buffer)
{
    struct stat sb;
    int fd = 0;
    char *str;

    buffer = get_next_elem(buffer);
    stat(buffer, &sb);
    if (info->fd_data <= 0) {
        write_communication(info->fd, SYNTAX);
        return (buffer);
    }
    write_communication(info->fd, BEGIN_DATA);
    str = malloc(sizeof(char) * (sb.st_size + 1));
    fd = open(buffer, O_RDONLY);
    read(fd, str, sb.st_size);
    write(info->fd_data, str, sb.st_size);
    free(str);
    close(info->fd_data);
    info->fd_data = 0;
    write_communication(info->fd, END_DATA);
    return (buffer);
}

char *upload_file(info_t *info, char *buffer)
{
    char *name;
    int fd = 0;
    char *str;

    buffer = get_next_elem(buffer);
    if (info->fd_data <= 0) {
        write_communication(info->fd, SYNTAX);
        return (buffer);
    }
    write_communication(info->fd, BEGIN_DATA);
    fd = open(buffer, O_WRONLY, O_APPEND, O_CREAT);
    buffer = read_communication(info->fd_data);
    while (strlen(buffer) > 0) {
        write(fd, buffer, strlen(buffer));
        free(buffer);
        buffer = read_communication(info->fd_data);
    }
    close(info->fd_data);
    info->fd_data = 0;
    write_communication(info->fd, END_DATA);
    return (buffer);
}