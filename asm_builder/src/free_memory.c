/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** free_memory.c
*/

#include "../include/builder.h"

#include <stdlib.h>


void free_path_data(path_data_t *path_data)
{
    if (path_data->dest_filepath != NULL) {
        free(path_data->dest_filepath);
        path_data->dest_filepath = NULL;
    }
    if (path_data->asm_file_name != NULL) {
        free(path_data->asm_file_name);
        path_data->asm_file_name = NULL;
    }
    if (path_data->cor_file_name != NULL) {
        free(path_data->cor_file_name);
        path_data->cor_file_name = NULL;
    }
}
