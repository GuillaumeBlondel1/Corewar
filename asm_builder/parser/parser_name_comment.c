/*
** EPITECH PROJECT, 2024
** asm_builder
** File description:
** parser_name_comment.c
*/

#include "../include/parser.h"
#include "../include/utils.h"

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

static int search_name(char **splited_lines_file)
{
    for (int i = 0; splited_lines_file[i] != NULL; i++) {
        if (strstr(splited_lines_file[i], ".name") != NULL) {
            return i;
        }
        if (strlen_parser(splited_lines_file[i]) != 0) {
            return -1;
        }
    }
    return -1;
}

static bool apply_header_name(char **splited_lines_file, int index_name,
    header_t *header)
{
    char **splited_line = NULL;
    char key_word_name[1024] = {0};

    splited_line = split_str(splited_lines_file[index_name], "\"");
    if (split_strlen(splited_line) != 2) {
        free_split_str(splited_lines_file);
        return false;
    }
    for (int i = 0, j = 0; splited_line[0][i] != '\0'; i++) {
        if (splited_line[0][i] != ' ' &&
            splited_line[0][i] != '\t') {
            key_word_name[j] = splited_line[0][i];
            j++;
        }
    }
    if (strcmp(key_word_name, ".name") != 0) {
        free_split_str(splited_line);
        return false;
    }
    if (strlen(splited_line[1]) > PROG_NAME_LENGTH) {
        free_split_str(splited_line);
        return false;
    }
    strcpy(header->prog_name, splited_line[1]);
    free_split_str(splited_line);
    return true;
}

static int search_comment(char **splited_lines_file, int index_name)
{
    for (int i = index_name + 1; splited_lines_file[i] != NULL; i++) {
        if (strstr(splited_lines_file[i], ".comment") != NULL) {
            return i;
        }
        if (strlen_parser(splited_lines_file[i]) != 0) {
            return -1;
        }
    }
    return -1;
}

static bool apply_header_comment(char **splited_lines_file, int index_comment,
    header_t *header)
{
    char **splited_line = NULL;
    char key_word_comment[1024] = {0};

    splited_line = split_str(splited_lines_file[index_comment], "\"");
    if (split_strlen(splited_line) != 2) {
        free_split_str(splited_line);
        return false;
    }
    for (int i = 0, j = 0; splited_line[0][i] != '\0'; i++) {
        if (splited_line[0][i] != ' ' &&
            splited_line[0][i] != '\t') {
            key_word_comment[j] = splited_line[0][i];
            j++;
        }
    }
    if (strcmp(key_word_comment, ".comment") != 0) {
        free_split_str(splited_line);
        return false;
    }
    if (strlen(splited_line[1]) > COMMENT_LENGTH) {
        free_split_str(splited_line);
        return false;
    }
    strcpy(header->comment, splited_line[1]);
    free_split_str(splited_line);
    return true;
}

header_t parser_name_comment(char **splited_lines_file, int *index)
{
    header_t header = {0};
    int index_name = 0;
    int index_comment = 0;

    index_name = search_name(splited_lines_file);
    if (index_name == -1) {
        return header;
    }
    index_comment = search_comment(splited_lines_file, index_name);
    if (index_comment == -1) {
        return header;
    }
    if (!apply_header_name(splited_lines_file, index_name, &header)) {
        return header;
    }
    if (!apply_header_comment(splited_lines_file, index_comment, &header)) {
        return header;
    }
    *index = index_comment + 1;
    return header;
}
