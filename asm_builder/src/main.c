/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** main.c
*/

#include "../include/builder.h"
#include "../include/file_management.h"
#include "../include/parser.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char **argv)
{
    int exit_status = 0;
    path_data_t path_data = {0};
    byte_code_parser_t byte_code_parser = {0};
    char *file = NULL;

    file = read_file(argc, argv, &path_data);
    if (file == NULL) {
        return 84;
    }
    if (!parser(file, &byte_code_parser)) {
        exit_status = 84;
    }
    free_path_data(&path_data);
    free(file);
    file = NULL;
    return exit_status;
}
