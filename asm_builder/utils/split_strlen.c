/*
** EPITECH PROJECT, 2024
** asm_builder
** File description:
** split_strlen.c
*/

#include <stdlib.h>

int split_strlen(char **split_str)
{
    int size = 0;

    for (int i = 0; split_str[i] != NULL; i++) {
        size++;
    }
    return size;
}
