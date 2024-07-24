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
