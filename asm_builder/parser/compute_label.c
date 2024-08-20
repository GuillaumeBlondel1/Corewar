/*
** EPITECH PROJECT, 2024
** asm_builder
** File description:
** compute_label.c
*/

#include "../include/parser.h"
#include "../include/llist.h"

#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

static int add_to_label(llist_t *node_label_declaration,
    llist_t *node_instruction, bool af_or_bf)
{
    int label_value = 0;
    llist_t *tmp_node_body = NULL;
    bytes_instruction_t *tmp_bytes_instruction = NULL;

    if (!af_or_bf) {
        label_value = MAX_SHORT_INT + 1;
        tmp_node_body = node_label_declaration->next_node;
    } else {
        tmp_node_body = node_label_declaration->prev_node;
    }
    while (tmp_node_body != node_instruction) {
        tmp_bytes_instruction = (bytes_instruction_t *)tmp_node_body->data;
        if (af_or_bf) {
            label_value += tmp_bytes_instruction->nb_bytes;
            tmp_node_body = tmp_node_body->prev_node;
        } else {
            label_value -= tmp_bytes_instruction->nb_bytes;
            tmp_node_body = tmp_node_body->next_node;
        }
    }
    return label_value;
}

static llist_t *research_node_instruction(llist_t *node_label)
{
    bytes_instruction_t *tmp_bytes_instruction = NULL;

    for (llist_t *tmp_node_body = node_label; tmp_node_body != NULL;
        tmp_node_body = tmp_node_body->prev_node) {
        tmp_bytes_instruction = (bytes_instruction_t *)tmp_node_body->data;
        if (tmp_bytes_instruction->type == T_INST) {
            return tmp_node_body;
        }
    }
    return NULL;
}

static llist_t *is_label_exist(llist_t *body, llist_t *node_label,
    bool *af_or_bf, const char *label)
{
    bytes_instruction_t *tmp_bytes_instruction = NULL;

    for (llist_t *tmp_node_body = body; tmp_node_body != NULL;
        tmp_node_body = tmp_node_body->next_node) {
        if (tmp_node_body == node_label) {
            *af_or_bf = true;
        }
        tmp_bytes_instruction = (bytes_instruction_t *)tmp_node_body->data;
        if (tmp_bytes_instruction->label_declaraction != NULL &&
            tmp_bytes_instruction->type_label_declaration) {
            if (!strcmp(tmp_bytes_instruction->label_declaraction, label)) {
                return tmp_node_body;
            }
        }
    }
    return NULL;
}

static int get_label_value(llist_t *body, llist_t *node_label,
    const char *label, bool *error)
{
    llist_t *node_label_declaration = NULL;
    llist_t *node_instruction = NULL;
    bool af_or_bf = false;
    int label_value = 0;

    node_label_declaration = is_label_exist(body, node_label, &af_or_bf, label);
    if (node_label_declaration == NULL) {
        *error = true;
        return 0;
    }
    node_instruction = research_node_instruction(node_label);
    label_value = add_to_label(node_label_declaration,
        node_instruction, af_or_bf);
    return label_value;
}

void compute_label(llist_t *body, bool *error)
{
    bytes_instruction_t *tmp_bytes_instruction = NULL;

    for (llist_t *tmp_node_body = body; tmp_node_body != NULL;
        tmp_node_body = tmp_node_body->next_node) {
        tmp_bytes_instruction = (bytes_instruction_t *)tmp_node_body->data;
        if (tmp_bytes_instruction->label_declaraction != NULL &&
            !tmp_bytes_instruction->type_label_declaration) {
            tmp_bytes_instruction->value = get_label_value(body, tmp_node_body,
                tmp_bytes_instruction->label_declaraction, error);
        }
        if (*error) {
            return;
        }
    }
}
