/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** serveur
*/

#ifndef SERVEUR_H_
#define SERVEUR_H_

// man socket
#include <sys/types.h>
#include <sys/socket.h>
// man ip
#include <netinet/in.h>
#include <netinet/ip.h>
// man select
#include <sys/select.h>
//lib
#include "lib/my/my.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
//opendir
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <arpa/inet.h>

#define STR (str[i] != '\0')
typedef struct t_info
{
    int fd;
    int fd_data;
    char *path;
    char *first_path;
    char *username;
    char *password;
}info_t;

struct node
{
    info_t *info;
    struct node *p_next;
    struct node *p_prev;
};

typedef struct dlist
{
    size_t length;
    struct node *p_tail;
    struct node *p_head;
}rlist;

#define CONNECTION_SERVEUR "220 Service ready for new user.\r\n"
#define USERNAME_GOOD "331 User name okay, need password.\r\n"
#define PASSWORD_GOOD "332 Need account for login.\r\n"
#define USER_LOGIN "230 User logged in, proceed.\r\n"
#define USER_LOGOUT "221 Service closing control connection.\r\n"
#define FILE_ACTION_GOOD "250 Requested file action okay, completed.\r\n"
#define COMMAND_GOOD "200 Command okay.\r\n"
#define NOT_LOGGED "530 Not logged in.\r\n"
#define SYNTAX "500 Syntax error, command unrecognized and the requested \
action did not take place.\r\n"
#define PASSIVE_MODE "227 Entering Passive Mode (%s).\r\n"
#define ERROR_CWD "550 Requested action not taken. File unavailable\r\n"
#define BEGIN_DATA "150 File status okay; about to open data connection.\r\n"
#define END_DATA "226 Closing data connection.\r\n"
#define LOGIN_PASS "503 Login with USER first.\r\n"
#define HELP "214 CDUP, CWD, DELE, RETR, HELP, LIST, NOOT, PASS, PASV,\
USER, PWD, QUIT, PORT, STOR\r\n"

#ifndef INC_
#define INC_

/* remove_client.c */

rlist *remove_client(rlist *list, struct node *tmp);

/* logout.c */

void logout(int fdAccept, char *buffer);

/* remove_file.c */

void verif_remove(info_t *info, char *tmp);
char *delete_file(info_t *info, char *buffer);

/* serveur.c */

int check_select_read(struct node *tmp);
int serveur(int port, char *path);
int main(int argc, char **argv);

/* add_to_list.c */

rlist *dlist_new(struct node *new);
struct node *init_node(info_t *info);
struct node *add_node_end(info_t *info, struct node *old);
void add_element(struct node *new, rlist *p_list);
rlist *remove_element(rlist *p_list, struct node *tmp);

/* action_file.c */

char *download_file(info_t *info, char *buffer);
char *upload_file(info_t *info, char *buffer);

/* help.c */

void help(int fdAccept, char *buffer);

/* help_tab.c */

void display_tab(char **tab);
int length_tab(char **tab);
void free_tab(char **tab);

/* connection_data.c */

void active(info_t *info, char *buffer);

/* communicate.c */

char *read_communication(int fd);
int write_communication(int fd, char *buffer);

/* inic.c */

info_t *init_struct_info(char *path, int fd);
int init_server(struct sockaddr_in addr);

/* add_client.c */

int is_new_client(int fd);
rlist *add_client(int fd, struct sockaddr_in addr, rlist *list, char *path);

/* command.c */

int connect_command_second(info_t *info, char *buffer);
int connect_command_first(info_t *info, char *buffer);
int check_if_connect(info_t *info, char *buffer);
int make_command(info_t *info, char *buffer);
rlist *check_if_command(rlist *list);

/* get_element.c */

char *get_next_elem(char *command);
int get_one_port(char *buffer, int *i);
int get_port(char *buffer);
char *get_host(char *buffer);

/* client.c */

char *read_communication(int fd);
int write_communication(int fd, char *buffer);
int get_port(char *command);
char *get_next_elem(char *command);
void create_active_serv(char *str);
int client(int port);
int main(int argc, char **argv);

/* str_to_word_array.c */

int supress_space(char *str, int i);
int count_words(char *str);
void intern_while_one(int *i, int *y, int *x, int a);
char **str_to_word_array(char *str);
char **str_to_word_array_sec(char *str, char c);

/* directory.c */

int get_point(char *str);
char *erase_path(char *tmp, int nb);
char *modif_tmp(char *path, char **tab, int size_new_path);
void verif_cwd(info_t *info, char *tmp);
void verif_cdup(info_t *info, char *tmp);

/* command_directory.c */

char *move_dir(info_t *info, char *buffer);
void move_parent_dir(info_t *info);
char *get_dir(info_t *info, char *buffer);


#endif /* !INC_ */

#endif /* !SERVEUR_H_ */