/*
** EPITECH PROJECT, 2024
** asm_builder
** File description:
** llist.h
*/

#ifndef _LLIST_
    #define _LLIST_

typedef struct llist_s {
    void *data;
    struct llist_s *next_node;
} llist_t;

llist_t *add_node_to_llist(llist_t *llist, void *new_data);
llist_t *add_node_in_llist(llist_t *llist, const llist_t *node, void *new_data);
llist_t *free_llist(llist_t *llist);
llist_t *last_node(llist_t *llist);

#endif
