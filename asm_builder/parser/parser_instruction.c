/*
** EPITECH PROJECT, 2024
** asm_builder
** File description:
** parser_instruction.c
*/

#include "../include/llist.h"
#include "../include/parser.h"
#include "../include/utils.h"

#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

static int search_op_index(const char *myb_instruction)
{
    for (int i = 0; i < 16; i++) {
        if (!strcmp(myb_instruction, op_tab[i].mnemonique)) {
            return i;
        }
    }
    return -1;
}

static llist_t *implement_instruction(const char *myb_instruction, llist_t *body,
    bool if_label_declaration, bool *error)
{
    llist_t *last_bytes = NULL;
    bytes_instruction_t *bytes_instruction = NULL;
    int op_index = 0;

    last_bytes = last_node(body);
    if (if_label_declaration) {
        bytes_instruction = (bytes_instruction_t *)last_bytes->data;
    } else {
        bytes_instruction = calloc(sizeof(*bytes_instruction),
            sizeof(*bytes_instruction));
    }
    op_index = search_op_index(myb_instruction);
    if (op_index == -1) {
        *error = true;
        return body;
    }
    bytes_instruction->type = T_INST;
    bytes_instruction->nb_bytes = S_INST;
    bytes_instruction->value = op_tab[op_index].mnemonique_value;
    if (if_label_declaration) {
        return body;
    }
    body = implement_llist(body, bytes_instruction);
    return body;
}

llist_t *parser_instruction(char **splited_line, llist_t *body,
    bool if_label_declaration, bool *error)
{
    bytes_instruction_t *instruction = NULL;
    int op_index = 0;

    body = implement_instruction(splited_line[0], body,
        if_label_declaration, error);
    if (*error) {
        return body;
    }
    instruction = (bytes_instruction_t *)last_node(body)->data;
    op_index = instruction->value - 1;
    if (split_strlen(&splited_line[1]) != op_tab[op_index].nbr_args) {
        *error = true;
        return body;
    }
    for (int i = 1, j = 0; splited_line[i] != NULL; i++) {
        body = parser_args(splited_line[i],
            op_tab[op_index].args[j], body, error);
        j++;
        if (*error) {
            return body;
        }
    }
    return body;
}
