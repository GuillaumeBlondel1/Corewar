/*
** EPITECH PROJECT, 2024
** asm_builder
** File description:
** parser_body.c
*/

#include "../include/llist.h"
#include "../include/parser.h"
#include "../include/utils.h"

#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

static llist_t *parser_bytes_instructions(char **splited_line,
    llist_t *body, bool *error)
{
    int current_index = 0;
    bool if_label_declaration = false;

    body = checking_label(splited_line[0], body, &if_label_declaration, error);
    if (*error) {
        return body;
    }
    if (if_label_declaration) {
        current_index = 1;
    }
    body = parser_instruction(&splited_line[current_index],
        body, if_label_declaration, error);
    return body;
}

static llist_t *parser_line(const char *line, llist_t *body, bool *error)
{
    char *cpy_line = NULL;
    char **splited_line = NULL;

    cpy_line = body_line_mask(line);
    splited_line = split_str(cpy_line, SPLIT_CHAR);
    body = parser_bytes_instructions(splited_line, body, error);
    free(cpy_line);
    free_split_str(splited_line);
    return body;
}

llist_t *parser_body(char **splited_lines_file)
{
    llist_t *body = NULL;
    bool error = false;

    for (int i = 0; splited_lines_file[i] != NULL; i++) {
        body = parser_line(splited_lines_file[i], body, &error);
        if (error) {
            return NULL;
        }
    }
    compute_label(body, &error);
    if (error) {
        return NULL;
    }
    return body;
}
