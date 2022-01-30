/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** add_client
*/

#include "serveur.h"

int is_new_client(int fd)
{
    fd_set ensemble;
    struct timeval timeout;
    int ret = 0;

    timeout.tv_sec = 0;
    timeout.tv_usec = 1000;
    FD_ZERO(&ensemble);
    FD_SET(fd, &ensemble);
    ret = select(FD_SETSIZE, &ensemble, NULL, NULL, &timeout);
    if (ret == -1) {
        perror("select");
        return (0);
    } else if (ret != 0)
        return (1);
    return (0);
}

rlist *add_client(int fd, struct sockaddr_in addr, rlist *list, char *path)
{
    unsigned int size = 0;
    int fd_accept;
    struct node *nd;

    size = sizeof(addr);
    fd_accept = accept(fd, (struct sockaddr *)&addr, &size);
    if (fd_accept == -1) {
        perror("accept");
        return (NULL);
    }
    write_communication(fd_accept, CONNECTION_SERVEUR);
    if (list == NULL) {
        nd = init_node(init_struct_info(path, fd_accept));
        list = dlist_new(nd);
        add_element(nd, list);
    } else {
        nd = add_node_end(init_struct_info(path, fd_accept), list->p_tail);
        add_element(nd, list);
    }
    return (list);
}