/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** recover_file_name.c
*/

#include <stdlib.h>
#include <string.h>
#include <stddef.h>

char *recover_file_name(const char *absolute_path)
{
    char *file_name = NULL;
    size_t size_file_name = 0;
    int i_beginning = 0;

    if (absolute_path == NULL || !strlen(absolute_path)) {
        return NULL;
    }
    for (int i = 0; absolute_path[i] != '\0'; i++) {
        if (absolute_path[i] == '/') {
            i_beginning = i + 1;
        }
    }
    size_file_name = strlen(&absolute_path[i_beginning]);
    if (size_file_name == 0) {
        return NULL;
    }
    file_name = calloc((size_file_name + 1) * sizeof(char),
        (size_file_name + 1) * sizeof(char));
    strcpy(file_name, &absolute_path[i_beginning]);
    return file_name;
}
