/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** add_to_list
*/

#include "serveur.h"

rlist *dlist_new(struct node *new)
{
    rlist *p_new = malloc(sizeof(rlist));
    if (p_new != NULL) {
        p_new->length = 0;
        p_new->p_head = new;
        p_new->p_tail = new;
    }
    return (p_new);
}

struct node *init_node(info_t *info)
{
    struct node *new = malloc(sizeof(struct node));

    new->p_next = NULL;
    new->p_prev = NULL;
    new->info = info;
    return (new);
}

struct node *add_node_end(info_t *info, struct node *old)
{
    struct node *new = malloc(sizeof(struct node));

    new->p_next = NULL;
    new->p_prev = old;
    old->p_next = new;
    new->info = info;
    return (new);
}

void add_element(struct node *new, rlist *p_list)
{
    p_list->p_tail = new;
    p_list->length = p_list->length + 1;
}

rlist *remove_element(rlist *p_list, struct node *tmp)
{
    if (tmp->p_next == NULL && tmp->p_prev == NULL) {
        free(p_list);
        p_list = NULL;
    } else if (tmp->p_next == NULL) {
        p_list->p_tail = tmp->p_prev;
        p_list->p_tail->p_next = NULL;
    } else if (tmp->p_prev == NULL) {
        p_list->p_head = tmp->p_next;
        p_list->p_head->p_prev = NULL;
    } else {
        tmp->p_next->p_prev = tmp->p_prev;
        tmp->p_prev->p_next = tmp->p_next;
    }
    free(tmp->info);
    free(tmp);
    if (p_list != NULL)
        p_list->length = p_list->length - 1;
    return (p_list);
}