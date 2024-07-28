/*
** EPITECH PROJECT, 2024
** asm_builder
** File description:
** parser.h
*/

#ifndef _PARSER_
    #define _PARSER_

    #include "llist.h"

    #include <stdbool.h>

    #define SPLIT_CHAR "\a"

    #define PROG_NAME_LENGTH 128
    #define COMMENT_LENGTH 2048
    #define COREWAR_EXEC_MAGIC 0xea83f3

    #define MAX_NBR_ARGS 4

    #define T_REG 1
    #define T_DIR 2
    #define T_IDX 16
    #define T_LAB 8
    #define T_IND 4
    #define T_INST 32
    #define T_COD_BYTE 64

    #define S_INST 1
    #define S_COD_BYTE 1
    #define S_REG 1
    #define S_DIR 4
    #define S_IND 2

    #define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

typedef struct header_s {
    int magic_number;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

typedef char args_type_t;
typedef char type_t;

typedef struct op_s {
    char *mnemonique;
    char mnemonique_value;
    int nbr_args;
    args_type_t args[MAX_NBR_ARGS];
    bool coding_byte;
} op_t;

typedef struct bytes_instruction_s {
    type_t type;
    int value;
    char nb_bytes;
    char *label_declaraction;
    bool type_label_declaration;
} bytes_instruction_t;

typedef struct byte_code_parser_s {
    header_t header;
    llist_t *body;
} byte_code_parser_t;

extern op_t op_tab[];

bool parser(char *file, byte_code_parser_t *byte_code_parser);
header_t parser_name_comment(char **splited_lines_file, int *index);
llist_t *parser_body(char **splited_lines_file);
void comment_mask(char *line);
int strlen_parser(const char *line);
char *body_line_mask(const char *line);
void arg_mask(char *arg);
llist_t *checking_label(const char *myb_label, llist_t *body,
    bool *if_label_declaration, bool *error);
llist_t *parser_instruction(char **splited_line, llist_t *body,
    bool if_label_declaration, bool *error);
llist_t *parser_args(char *arg, args_type_t arg_type,
    llist_t *body, bool *error);

#endif
