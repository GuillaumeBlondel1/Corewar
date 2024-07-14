/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** builder.h
*/

#ifndef _BUILDER_
    #define _BUILDER_

typedef struct path_data_s {
    char *dest_filepath;
    char *asm_file_name;
    char *cor_file_name;
} path_data_t;

void free_path_data(path_data_t *path_data);

#endif
