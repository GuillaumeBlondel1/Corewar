/*
** EPITECH PROJECT, 2024
** asm_builder
** File description:
** parser_args.c
*/

#include "../include/llist.h"
#include "../include/parser.h"
#include "../include/utils.h"

#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

static bool expect_register(const char *arg)
{
    if (arg[0] == 'r') {
        return true;
    }
    return false;
}

static bool expect_label(const char *arg)
{
    if (!strncmp(arg, "%:", 2)) {
        return true;
    }
    return false;
}

static bool expect_direct(const char *arg)
{
    if (arg[0] == '%') {
        return true;
    }
    return false;
}

static llist_t *implement_register(const char *arg, args_type_t arg_type,
    llist_t *body, bool *error)
{
    bytes_instruction_t *bytes_instruction = NULL;

    if (!is_num(&arg[1])) {
        *error = true;
        return body;
    }
    if (!(T_REG & arg_type)) {
        *error = true;
        return body;
    }
    bytes_instruction = calloc(sizeof(*bytes_instruction),
        sizeof(*bytes_instruction));
    bytes_instruction->type = T_REG;
    bytes_instruction->value = atoi(&arg[1]);
    bytes_instruction->nb_bytes = S_REG;
    body = implement_llist(body, bytes_instruction);
    return body;
}

static llist_t *implement_label(const char *arg, args_type_t arg_type,
    llist_t *body, bool *error)
{
    bytes_instruction_t *bytes_instruction = NULL;

    if (!is_correct_char(&arg[2], LABEL_CHARS)) {
        *error = true;
        return body;
    }
    if (!(T_IND & arg_type)) {
        *error = true;
        return body;
    }
    bytes_instruction = calloc(sizeof(*bytes_instruction),
        sizeof(*bytes_instruction));
    bytes_instruction->type = T_LAB;
    bytes_instruction->label_declaraction = strdup(&arg[2]);
    bytes_instruction->type_label_declaration = false;
    body = implement_llist(body, bytes_instruction);
    return body;
}

static llist_t *implement_direct(const char *arg, args_type_t arg_type,
    llist_t *body, bool *error)
{
    bytes_instruction_t *bytes_instruction = NULL;

    if (!is_num(&arg[1])) {
        *error = true;
        return body;
    }
    if (!(T_DIR & arg_type) && !(T_IDX & arg_type)) {
        *error = true;
        return body;
    }
    bytes_instruction = calloc(sizeof(*bytes_instruction),
        sizeof(*bytes_instruction));
    bytes_instruction->value = atoi(&arg[1]);
    if ((T_DIR & arg_type)) {
        bytes_instruction->type = T_DIR;
        bytes_instruction->value = S_DIR;
    }
    if ((T_IDX & arg_type)) {
        bytes_instruction->type = T_IDX;
        bytes_instruction->nb_bytes = S_IND;
    }
    body = implement_llist(body, bytes_instruction);
    return body;
}

static llist_t *implement_indirect(const char *arg, args_type_t arg_type,
    llist_t *body, bool *error)
{
    bytes_instruction_t *bytes_instruction = NULL;

    if (!is_num(arg)) {
        *error = true;
        return body;
    }
    if (!(T_IND & arg_type)) {
        *error = true;
        return body;
    }
    bytes_instruction = calloc(sizeof(*bytes_instruction),
        sizeof(*bytes_instruction));
    bytes_instruction->type = T_IND;
    bytes_instruction->value = atoi(arg);
    bytes_instruction->nb_bytes = S_IND;
    body = implement_llist(body, bytes_instruction);
    return body;
}

llist_t *parser_args(char *arg, args_type_t arg_type,
    llist_t *body, bool *error)
{
    arg_mask(arg);
    if (expect_register(arg)) {
        body = implement_register(arg, arg_type, body, error);
        return body;
    }
    if (expect_label(arg)) {
        body = implement_label(arg, arg_type, body, error);
        return body;
    }
    if (expect_direct(arg)) {
        body = implement_direct(arg, arg_type, body, error);
        return body;
    }
    body = implement_indirect(arg, arg_type, body, error);
    return body;
}
