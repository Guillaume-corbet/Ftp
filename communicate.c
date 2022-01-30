/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** communicate
*/

#include "serveur.h"

char *read_communication(int fd)
{
    char *buffer;
    fd_set ensemble;
    struct timeval timeout;
    int ret = 0;

    timeout.tv_sec = 0;
    timeout.tv_usec = 1000;
    buffer = malloc(sizeof(char) * 1024);
    memset(buffer, '\0', 1024);
    FD_ZERO(&ensemble);
    FD_SET(fd, &ensemble);
    ret = select(FD_SETSIZE, &ensemble, NULL, NULL, &timeout);
    if (ret == -1) {
        perror("select");
    } else if (ret != 0) {
        ret = read(fd, buffer, 1024);
        if (ret == 0)
            buffer = strcpy(buffer, "QUIT\r\n");
    }
    return (buffer);
}

int write_communication(int fd, char *buffer)
{
    fd_set ensemble;
    struct timeval timeout;
    int ret = 0;

    timeout.tv_sec = 0;
    timeout.tv_usec = 1000;
    FD_ZERO(&ensemble);
    FD_SET(fd, &ensemble);
    ret = select(FD_SETSIZE, NULL, &ensemble, NULL, &timeout);
    if (ret == -1) {
        perror("select");
    } else if (ret != 0) {
        write(fd, buffer, my_strlen(buffer));
    }
    return (0);
}