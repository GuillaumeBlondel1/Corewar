/*
** EPITECH PROJECT, 2024
** asm_builder
** File description:
** free_llist.c
*/

#include "../include/llist.h"

#include <stdlib.h>

llist_t *free_llist(llist_t *llist)
{
    llist_t *tmp_node = NULL;

    if (llist == NULL) {
        return NULL;
    }
    while (llist != NULL) {
        tmp_node = llist->next_node;
        free(llist);
        llist = tmp_node;
    }
    return NULL;
}
