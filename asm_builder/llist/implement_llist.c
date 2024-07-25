/*
** EPITECH PROJECT, 2024
** asm_builder
** File description:
** implement_llist.c
*/

#include "../include/llist.h"

#include <stdlib.h>

llist_t *implement_llist(llist_t *llist, void *new_data)
{
    llist_t *new_node = NULL;
    llist_t *tmp_node = NULL;

    new_node = calloc(sizeof(*new_node), sizeof(*new_node));
    new_node->data = new_data;
    if (llist == NULL) {
        return new_node;
    }
    for (tmp_node = llist; tmp_node->next_node != NULL;
        tmp_node = tmp_node->next_node);
    tmp_node->next_node = new_node;
    return llist;
}
