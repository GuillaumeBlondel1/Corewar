/*
** EPITECH PROJECT, 2024
** asm_builder
** File description:
** free_split_str.c
*/

#include <stdlib.h>

void free_split_str(char **split_str)
{
    for (int i = 0; split_str[i] != NULL; i++) {
        free(split_str[i]);
    }
    free(split_str);
}
