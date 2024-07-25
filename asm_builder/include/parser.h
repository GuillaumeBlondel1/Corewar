/*
** EPITECH PROJECT, 2024
** asm_builder
** File description:
** parser.h
*/

#ifndef _PARSER_
    #define _PARSER_

    #include <stdbool.h>

    #define SPLIT_CHAR "\a"

    #define PROG_NAME_LENGTH 128
    #define COMMENT_LENGTH 2048
    #define COREWAR_EXEC_MAGIC 0xea83f3

typedef struct header_s {
    int magic_number;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

typedef struct byte_code_parser_s {
    header_t header;
} byte_code_parser_t;

bool parser(char *file, byte_code_parser_t *byte_code_parser);
header_t parser_name_comment(char **splited_lines_file, int *index);
void comment_mask(char *line);
int strlen_parser(const char *line);
char *body_line_mash(char *line);

#endif
