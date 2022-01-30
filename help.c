/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** help
*/

#include "serveur.h"

void help(int fdAccept, char *buffer)
{
    write_communication(fdAccept, HELP);
}