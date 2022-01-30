/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** command
*/

#include "serveur.h"

int connect_command_second(info_t *info, char *buffer)
{
    if (strcmp("NOOP\r\n", buffer) == 0) {
        write_communication(info->fd, COMMAND_GOOD);
    } else if (strncmp("PORT ", buffer, 5) == 0) {
        active(info, buffer);
        write_communication(info->fd, COMMAND_GOOD);
    } else if (strncmp("RETR ", buffer, 5) == 0) {
        buffer = download_file(info, buffer);
    } else if (strncmp("STOR ", buffer, 5) == 0) {
        buffer = upload_file(info, buffer);
    } else {
        write_communication(info->fd, SYNTAX);
    }
    free(buffer);
    return (0);
}

int connect_command_first(info_t *info, char *buffer)
{
    if (strcmp("QUIT\r\n", buffer) == 0) {
        logout(info->fd, buffer);
        return (84);
    } else if (strcmp("PASV\r\n", buffer) == 0) {
        write_communication(info->fd, "noop\r\n");
    } else if (strncmp("CWD ", buffer, 4) == 0) {
        buffer = move_dir(info, buffer);
    } else if (strcmp("CDUP\r\n", buffer) == 0) {
        move_parent_dir(info);
    } else if (strncmp("DELE ", buffer, 5) == 0) {
        buffer = delete_file(info, buffer);
    } else if (strcmp("PWD\r\n", buffer) == 0) {
        buffer = get_dir(info, buffer);
    } else if (strncmp("HELP", buffer, 4) == 0) {
        help(info->fd, buffer);
    } else {
        return (connect_command_second(info, buffer));
    }
    free(buffer);
    return (0);
}

int check_if_connect(info_t *info, char *buffer)
{
    if (strcmp(info->username, "USER Anonymous\r\n") == 0 &&
        strcmp(info->password, "PASS \r\n") == 0)
        return (connect_command_first(info, buffer));
    else if (strcmp("QUIT\r\n", buffer) == 0) {
        logout(info->fd, buffer);
        return (84);
    }
    return (1);
}

int make_command(info_t *info, char *buffer)
{
    int ret = 0;

    if ((ret = check_if_connect(info, buffer)) != 1)
        return (ret);
    if (strncmp(buffer, "USER ", 5) == 0) {
        info->username = strcpy(info->username, buffer);
        write_communication(info->fd, USERNAME_GOOD);
    } else if (strncmp(buffer, "PASS ", 5) == 0) {
        if (strcmp(buffer, "PASS \r\n") == 0 &&
        strcmp(info->username, "USER Anonymous\r\n") == 0) {
            info->password = strcpy(info->password, buffer);
            write_communication(info->fd, USER_LOGIN);
        } else if (strlen(info->username) < 6)
            write_communication(info->fd, LOGIN_PASS);
        else
            write_communication(info->fd, NOT_LOGGED);
    } else {
        write_communication(info->fd, NOT_LOGGED);
    }
    free(buffer);
    return (0);
}

rlist *check_if_command(rlist *list)
{
    int ret = 0;
    struct node *tmp = list->p_head;
    char *buffer;

    while (tmp) {
        ret = check_select_read(tmp);
        if (ret == -1) {
            perror("select");
        } else if (ret != 0) {
            buffer = read_communication(tmp->info->fd);
            if (make_command(tmp->info, buffer) == 84) {
                list = remove_client(list, tmp);
                return (list);
            }
        }
        if (list == NULL)
            break;
        tmp = tmp->p_next;
    }
    return (list);
}