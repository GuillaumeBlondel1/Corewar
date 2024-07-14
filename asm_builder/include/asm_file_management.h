/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** asm_file_management.h
*/

#ifndef _ASM_FILE_MANAGEMENT_
    #define _ASM_FILE_MANAGEMENT_

    #include <stddef.h>

typedef struct path_data_s path_data_t;

typedef struct file_data_s {
    int fd;
    size_t size_file;
} file_data_t;

char *read_file(int argc, const char **argv, path_data_t *path_data);
int handling_path_data(int argc, const char **argv, path_data_t *path_data);

#endif
