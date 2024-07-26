/*
** EPITECH PROJECT, 2024
** asm_builder
** File description:
** parser.c
*/

#include "../include/parser.h"
#include "../include/utils.h"

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h>

static void apply_comment_mask(char **splited_lines_file)
{
    for (int i = 0; splited_lines_file[i] != NULL; i++) {
        comment_mask(splited_lines_file[i]);
    }
}

static bool error_name_comment(const header_t *header)
{
    if (!strlen(header->prog_name) || !strlen(header->comment)) {
        return true;
    }
    return false;
}

bool parser(char *file, byte_code_parser_t *byte_code_parser)
{
    char **splited_lines_file = NULL;
    int index = 0;

    if (file == NULL) {
        return false;
    }
    splited_lines_file = split_str(file, "\n");
    apply_comment_mask(splited_lines_file);
    byte_code_parser->header = parser_name_comment(splited_lines_file, &index);
    if (error_name_comment(&byte_code_parser->header)) {
        free_split_str(splited_lines_file);
        return false;
    }
    byte_code_parser->body = parser_body(&splited_lines_file[index]);
    if (byte_code_parser->body == NULL) {
        free_split_str(splited_lines_file);
        return false;
    }
    free_split_str(splited_lines_file);
    return true;
}
