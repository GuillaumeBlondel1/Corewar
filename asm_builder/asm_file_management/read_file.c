/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** read_file.c
*/

#include "../include/builder.h"
#include "../include/asm_file_management.h"

#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static bool expect_args(int argc)
{
    if (argc < 2) {
        return false;
    }
    return true;
}

static bool existing_file(const char *file_path)
{
    if (access(file_path, F_OK) != 0) {
        return false;
    }
    return true;
}

static bool open_file(const char *file_path, file_data_t *file_data)
{
    struct stat file_stats = {0};

    file_data->fd = open(file_path, O_RDONLY);
    if (file_data->fd == -1) {
        return false;
    }
    if (stat(file_path, &file_stats) == -1) {
        return false;
    }
    file_data->size_file = file_stats.st_size;
    return true;
}

char *read_file(int argc, const char **argv, path_data_t *path_data)
{
    file_data_t file_data = {0};
    char *file = NULL;

    if (expect_args(argc) == false) {
        return NULL;
    }
    if (existing_file(argv[1]) == false) {
        return NULL;
    }
    if (open_file(argv[1], &file_data) == false) {
        return NULL;
    }
    file = calloc(file_data.size_file * sizeof(char),
        file_data.size_file * sizeof(char));
    read(file_data.fd, file, file_data.size_file * sizeof(char));
    close(file_data.fd);
    return file;
}
