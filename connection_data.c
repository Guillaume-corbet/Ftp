/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** type_connection_data
*/

#include "serveur.h"

void active(info_t *info, char *buffer)
{
    struct sockaddr_in addr;
    struct sockaddr addrRet;
    int len = sizeof(addr);

    if (info->fd_data > 0)
        close(info->fd_data);
    info->fd_data = socket(AF_INET, SOCK_STREAM, 0);
    if (info->fd_data == -1) {
        perror("socket");
    }
    memset((char*)&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(get_host(buffer));
    addr.sin_port = htons((unsigned short)get_port(buffer));
    memcpy((char *)&addrRet, (char *)&addr, sizeof(addrRet));
    if (connect(info->fd_data, &addrRet, sizeof(addrRet)) != 0) {
        my_putstr("ERROR\n");
        info->fd_data = 0;
    }
}