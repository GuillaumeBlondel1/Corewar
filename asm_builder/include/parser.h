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

    #define MAX_NBR_ARGS 4

    #define T_REG 1
    #define T_DIR 2
    #define T_IND 4
    #define T_LAB 8

typedef struct header_s {
    int magic_number;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

typedef char args_type_t;

typedef struct op_s {
    char *mnemonique;
    char mnemonique_value;
    int nbr_args;
    args_type_t args[MAX_NBR_ARGS];
} op_t;

typedef struct byte_code_parser_s {
    header_t header;
} byte_code_parser_t;

extern op_t op_tab[];

bool parser(char *file, byte_code_parser_t *byte_code_parser);
header_t parser_name_comment(char **splited_lines_file, int *index);
void comment_mask(char *line);
int strlen_parser(const char *line);
char *body_line_mash(char *line);

#endif
