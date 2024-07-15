/*
** EPITECH PROJECT, 2024
** asm_builder
** File description:
** split_str.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h>

static bool expect_separator(char c, const char *separators)
{
    for (int i = 0; separators[i] != '\0'; i++) {
        if (separators[i] == c) {
            return true;
        }
    }
    return false;
}

static size_t size_str_part(char *str, const char *separators)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (expect_separator(str[i], separators)) {
            return i;
        }
    }
    return i;
}

static char *str_part(char *str, const char *separators)
{
    char *part = NULL;
    size_t size_part = 0;

    size_part = size_str_part(str, separators);
    if (!size_part) {
        return NULL;
    }
    part = calloc((size_part + 1) * sizeof(char),
        (size_part + 1) * sizeof(char));
    strncpy(part, str, size_part);
    return part;
}

static void assign_char_ptn(char ***splited_str,
    size_t *size_splited_str, char *tmp_str)
{
    *size_splited_str += 1;
    (*splited_str) = realloc((*splited_str),
        *size_splited_str * sizeof(char *));
    (*splited_str)[*size_splited_str - 1] = tmp_str;
}

char **split_str(char *str, const char *separators)
{
    char **splited_str = NULL;
    size_t size_splited_str = 0;
    char *tmp_str = NULL;

    if (str == NULL || separators == NULL) {
        return NULL;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        tmp_str = str_part(&str[i], separators);
        if (tmp_str != NULL) {
            assign_char_ptn(&splited_str, &size_splited_str, tmp_str);
            i += strlen(splited_str[size_splited_str - 1]);
        }
    }
    assign_char_ptn(&splited_str, &size_splited_str, NULL);
    return splited_str;
}
