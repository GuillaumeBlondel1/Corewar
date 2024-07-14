/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** recover_path.c
*/

#include <stdlib.h>
#include <string.h>
#include <stddef.h>

char *recover_path(const char *absolute_path)
{
    char *path = NULL;
    size_t size_path = 0;

    if (absolute_path == NULL || !strlen(absolute_path)) {
        return NULL;
    }
    for (int i = 0; absolute_path[i] != '\0'; i++) {
        if (absolute_path[i] == '/') {
            size_path = i + 1;
        }
    }
    if (!size_path) {
        return NULL;
    }
    path = calloc((size_path + 1) * sizeof(char),
        (size_path + 1) * sizeof(char));
    strncpy(path, absolute_path, size_path);
    return path;
}
