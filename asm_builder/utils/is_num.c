/*
** EPITECH PROJECT, 2024
** asm_builder
** File description:
** is_num.c
*/

#include <stdbool.h>

bool is_num(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            continue;
        }
        return false;
    }
    return true;
}
