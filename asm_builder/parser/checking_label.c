/*
** EPITECH PROJECT, 2024
** asm_builder
** File description:
** checking_label.c
*/

#include "../include/llist.h"
#include "../include/parser.h"

#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

static char *implement_label(const char *raw_label)
{
    char *label = NULL;
    size_t len_label = 0;

    for (int i = 0; raw_label[i] != '\0'; i++) {
        if (raw_label[i] == ':') {
            break;
        }
        len_label++;
    }
    label = calloc((len_label + 1) * sizeof(char),
        (len_label + 1) * sizeof(char));
    for (int i = 0; raw_label[i] != '\0'; i++) {
        if (raw_label[i] == ':') {
            break;
        }
        label[i] = raw_label[i];
    }
    return label;
}

llist_t *checking_label(const char *myb_label, llist_t *body,
    bool *if_label_declaration, bool *error)
{
    int last_char = 0;
    bytes_instruction_t *bytes_instruction = NULL;

    last_char = strlen(myb_label) - 1;
    if (myb_label[last_char] == ':') {
        if (last_char == 0) {
            *error = true;
            return body;
        }
        *if_label_declaration = true;
        bytes_instruction = calloc(sizeof(*bytes_instruction),
            sizeof(*bytes_instruction));
        bytes_instruction->label_declaraction = implement_label(myb_label);
        bytes_instruction->type_label_declaration = true;
        body = implement_llist(body, bytes_instruction);
    }
    return body;
}
