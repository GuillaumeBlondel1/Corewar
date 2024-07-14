/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** change_extension.c
*/

#include "../include/utils.h"

#include <stdlib.h>
#include <string.h>
#include <stddef.h>

static char *add_extension(const char *file_name,
    size_t size_file_name_nth_ext, const char *new_extension)
{
    char *new_file_name = NULL;
    char *file_name_nth_ext = NULL;

    file_name_nth_ext = calloc((size_file_name_nth_ext + 1) * sizeof(char),
        (size_file_name_nth_ext + 1) * sizeof(char));
    strncpy(file_name_nth_ext, file_name, size_file_name_nth_ext);
    new_file_name = stradd(file_name_nth_ext, new_extension);
    free(file_name_nth_ext);
    file_name_nth_ext = NULL;
    return new_file_name;
}

char *change_extension(const char *file_name, const char *new_extension)
{
    size_t size_file_name_nth_ext = 0;

    if (file_name == NULL || !strlen(file_name) ||
        new_extension == NULL || !strlen(new_extension)) {
        return NULL;
    }
    for (int i = 0; file_name[i] != '\0'; i++) {
        if (file_name[i] == '.') {
            break;
        }
        size_file_name_nth_ext++;
    }
    if (size_file_name_nth_ext == 0) {
        return NULL;
    }
    return add_extension(file_name, size_file_name_nth_ext, new_extension);
}
