/*
** EPITECH PROJECT, 2024
** asm_builder
** File description:
** implement_llist.c
*/

#include "../include/llist.h"

#include <stdlib.h>

llist_t *add_node_to_llist(llist_t *llist, void *new_data)
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
    new_node->prev_node = tmp_node;
    return llist;
}

llist_t *add_node_in_llist(llist_t *llist, const llist_t *node, void *new_data)
{
    llist_t *new_node = NULL;
    llist_t *tmp_node = NULL;
    llist_t *next_node = NULL;
    llist_t *prev_node = NULL;

    new_node = calloc(sizeof(*new_node), sizeof(*new_node));
    new_node->data = new_data;
    if (llist == NULL) {
        return new_node;
    }
    for (tmp_node = llist; tmp_node->next_node != NULL;
        tmp_node = tmp_node->next_node) {
        if (tmp_node == node) {
            prev_node = tmp_node;
            next_node = tmp_node->next_node;
            break;
        }
    }
    if (next_node == NULL) {
        return llist;
    }
    new_node->next_node = next_node;
    new_node->prev_node = prev_node;
    tmp_node->next_node = new_node;
    return llist;
}
