/*
** EPITECH PROJECT, 2024
** asm_builder
** File description:
** is_correct_char.c
*/

#include <stdbool.h>

static bool contains_correct_char(char c, const char *correct_char)
{
    for (int i = 0; correct_char[i] != '\0'; i++) {
        if (correct_char[i] == c) {
            return true;
        }
    }
    return false;
}

bool is_correct_char(const char *str, const char *correct_char)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!contains_correct_char(str[i], correct_char)) {
            return false;
        }
    }
    return true;
}
