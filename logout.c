/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** logout
*/

#include "serveur.h"

void logout(int fdAccept, char *buffer)
{
    write_communication(fdAccept, USER_LOGOUT);
    free(buffer);
}