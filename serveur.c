/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** serveur
*/

#include "serveur.h"

int check_select_read(struct node *tmp)
{
    fd_set ensemble;
    struct timeval timeout;
    int ret = 0;

    timeout.tv_sec = 0;
    timeout.tv_usec = 1000;
    FD_ZERO(&ensemble);
    FD_SET(tmp->info->fd, &ensemble);
    ret = select(FD_SETSIZE, &ensemble, NULL, NULL, &timeout);
    return (ret);
}

int serveur(int port, char *path)
{
    struct sockaddr_in addr;
    int fd = 0;
    rlist *list = NULL;

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons((unsigned short)port);
    fd = init_server(addr);
    while (1) {
        if (is_new_client(fd) == 1)
            list = add_client(fd, addr, list, path);
        if (list != NULL)
            list = check_if_command(list);
    }
    close(fd);
    return (0);
}

int main(int argc, char **argv)
{
    if (argc == 3 && my_getnbr(argv[1]) > 0) {
        if (serveur(my_getnbr(argv[1]), argv[2]) == 84)
            return (84);
    }
    return (84);
}