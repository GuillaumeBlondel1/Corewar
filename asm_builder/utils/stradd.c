/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** stradd.c
*/

#include <stdlib.h>
#include <string.h>
#include <stddef.h>

static size_t count_total_size(const char *str1, const char *str2)
{
    size_t total_size = 0;

    if (str1 != NULL) {
        total_size += strlen(str1);
    }
    if (str2 != NULL) {
        total_size += strlen(str2);
    }
    return total_size;
}

char *stradd(const char *str1, const char *str2)
{
    char *new_str = NULL;
    size_t total_size = 0;

    total_size = count_total_size(str1, str2);
    if (!total_size) {
        return NULL;
    }
    new_str = calloc((total_size + 1) * sizeof(char),
        (total_size + 1) * sizeof(char));
    if (str1 != NULL) {
        strcat(new_str, str1);
    }
    if (str2 != NULL) {
        strcat(new_str, str2);
    }
    return new_str;
}
