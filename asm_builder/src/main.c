/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** main.c
*/

#include "../include/builder.h"
#include "../include/asm_file_management.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char **argv)
{
    path_data_t path_data = {0};
    char *file = NULL;

    file = read_file(argc, argv, &path_data);
    if (file == NULL) {
        return 84;
    }
    printf("%s\n", path_data.dest_filepath);
    return 0;
}
