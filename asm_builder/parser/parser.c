/*
** EPITECH PROJECT, 2024
** asm_builder
** File description:
** parser.c
*/

#include "../include/parser.h"
#include "../include/utils.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h>

static void free_file(char **splited_line_file)
{
    if (splited_line_file == NULL) {
        return;
    }
    for (int i = 0; splited_line_file[i] != NULL; i++) {
        free(splited_line_file[i]);
    }
    free(splited_line_file);
}

bool parser(char *file, byte_code_parser_t *byte_code_parser)
{
    char **splited_line_file = NULL;

    if (file == NULL) {
        return false;
    }
    splited_line_file = split_str(file, "\n");
    free_file(splited_line_file);
    return true;
}
