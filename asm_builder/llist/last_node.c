/*
** EPITECH PROJECT, 2024
** asm_builder
** File description:
** last_node.c
*/

#include "../include/llist.h"

#include <stdlib.h>

llist_t *last_node(llist_t *llist)
{
    llist_t *tmp_node = NULL;

    if (llist == NULL) {
        return NULL;
    }
    for (tmp_node = llist; tmp_node->next_node != NULL;
        tmp_node = tmp_node->next_node);
    return tmp_node;
}
