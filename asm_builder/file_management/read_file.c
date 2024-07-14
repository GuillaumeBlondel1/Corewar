/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** read_file.c
*/

#include "../include/builder.h"
#include "../include/file_management.h"

#include <stdlib.h>
#include <stdio.h>
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

static bool open_file(const char *file_path, file_data_t *file_data)
{
    struct stat file_stat = {0};

    if (stat(file_path, &file_stat) == -1) {
        return false;
    }
    if (!(file_stat.st_mode & __S_IFREG)) {
        dprintf(2, "It's not a valid file...\n");
        return false;
    }
    file_data->fd = open(file_path, O_RDONLY);
    if (file_data->fd == -1) {
        return false;
    }
    file_data->size_file = file_stat.st_size;
    return true;
}

char *read_file(int argc, const char **argv, path_data_t *path_data)
{
    file_data_t file_data = {0};
    char *file = NULL;

    if (expect_args(argc) == false) {
        return NULL;
    }
    if (open_file(argv[1], &file_data) == false) {
        return NULL;
    }
    if (handling_path_data(argc, argv, path_data) == 1) {
        return NULL;
    }
    file = calloc((file_data.size_file + 1) * sizeof(char),
        (file_data.size_file + 1) * sizeof(char));
    read(file_data.fd, file, file_data.size_file * sizeof(char));
    close(file_data.fd);
    return file;
}
