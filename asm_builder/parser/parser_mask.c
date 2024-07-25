/*
** EPITECH PROJECT, 2024
** asm_builder
** File description:
** mask_parser.c
*/

#include "../include/parser.h"

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void comment_mask(char *line)
{
    bool active_mask = false;

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '#' && !active_mask) {
            active_mask = true;
        }
        if (active_mask) {
            line[i] = '\0';
        }
    }
}

int strlen_parser(const char *line)
{
    int len = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] != ' ' && line[i] != '\t') {
            len++;
        }
    }
    return len;
}

char *body_line_mash(char *line)
{
    char *new_line = NULL;
    size_t len_new_line = 0;

    len_new_line = strlen(line) * 2;
    new_line = calloc((len_new_line + 1) * sizeof(char),
        (len_new_line + 1) * sizeof(char));
    for (int i = 0, j = 0; line[i] != '\0'; i++) {
        if (line[i] == ' ' || line[i] == '\t' || line[i] == ',') {
            new_line[j] = SPLIT_CHAR[0];
            j++;
            continue;
        }
        if (line[i] == ':') {
            new_line[j] = line[i];
            new_line[j + 1] = SPLIT_CHAR[0];
            j += 2;
            continue;
        }
        new_line[j] = line[i];
        j++;
    }
    free(line);
    return new_line;
}
