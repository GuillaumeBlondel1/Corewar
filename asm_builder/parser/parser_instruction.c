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

static int get_coding_byte_value(char type)
{
    switch (type) {
        case T_REG:
            return 0b01;
        case T_IND:
            return 0b11;
        case T_DIR:
            return 0b10;
        case T_IDX:
            return 0b10;
        case T_LAB:
            return 0b10;
        default:
            return 0;
    }
}

static llist_t *compute_coding_byte(int op_index, llist_t *body,
    const llist_t *node_instruction)
{
    llist_t *tmp_node_args = NULL;
    bytes_instruction_t *tmp_bytes_instruction = NULL;
    bytes_instruction_t *bytes_instruction = NULL;
    int coding_byte_tab[4] = {0};

    if (!op_tab[op_index].coding_byte) {
        return body;
    }
    tmp_node_args = node_instruction->next_node;
    for (int i = 0; tmp_node_args != NULL;
        tmp_node_args = tmp_node_args->next_node) {
        tmp_bytes_instruction = (bytes_instruction_t *)tmp_node_args->data;
        coding_byte_tab[i] = get_coding_byte_value(tmp_bytes_instruction->type);
        i++;
    }
    bytes_instruction = calloc(sizeof(*bytes_instruction),
        sizeof(*bytes_instruction));
    bytes_instruction->type = T_COD_BYTE;
    bytes_instruction->nb_bytes = S_COD_BYTE;
    bytes_instruction->value = (coding_byte_tab[0] << 6) +
        (coding_byte_tab[1] << 4) +
            (coding_byte_tab[2] << 2) + coding_byte_tab[3];
    body = add_node_in_llist(body, node_instruction, bytes_instruction);
    return body;
}

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
    body = add_node_to_llist(body, bytes_instruction);
    return body;
}

llist_t *parser_instruction(char **splited_line, llist_t *body,
    bool if_label_declaration, bool *error)
{
    llist_t *node_instruction = NULL;
    bytes_instruction_t *byte_instruction = NULL;
    int op_index = 0;

    body = implement_instruction(splited_line[0], body,
        if_label_declaration, error);
    if (*error) {
        return body;
    }
    node_instruction = last_node(body);
    byte_instruction = (bytes_instruction_t *)node_instruction->data;
    op_index = byte_instruction->value - 1;
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
    body = compute_coding_byte(op_index, body, node_instruction);
    return body;
}
