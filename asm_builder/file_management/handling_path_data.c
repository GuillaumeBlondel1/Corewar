/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** handling_path_data.c
*/

#include "../include/builder.h"
#include "../include/utils.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int dest_path_option(int argc, const char **argv)
{
    if (argc >= 3) {
        if (strcmp(argv[2], "-f")) {
            dprintf(2, "%s: Unknow option...\n", argv[2]);
            return 2;
        }
        if (argc >= 4) {
            return 1;
        } else {
            dprintf(2, "Invalid: No path after -f !\n");
            return 2;
        }
    } else {
        return 0;
    }
}

int handling_path_data(int argc, const char **argv, path_data_t *path_data)
{
    int option = 0;

    option = dest_path_option(argc, argv);
    if (option == 0) {
        path_data->dest_filepath = recover_path(argv[1]);
        path_data->asm_file_name = recover_file_name(argv[1]);
        path_data->cor_file_name =
            change_extension(path_data->asm_file_name, ".cor");
        return 0;
    }
    if (option == 1) {
        path_data->dest_filepath = recover_path(argv[3]);
        path_data->asm_file_name = recover_file_name(argv[1]);
        path_data->cor_file_name =
            change_extension(path_data->asm_file_name, ".cor");
        return 0;
    }
    return 1;
}
