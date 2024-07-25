/*
** EPITECH PROJECT, 2024
** asm_builder
** File description:
** op.c
*/

#include "../include/parser.h"

extern op_t op_tab[] = {
    {"live", 0x01, 1, {T_DIR}},
    {"ld", 0x02, 2, {T_DIR | T_IND, T_REG}},
    {"st", 0x03, 2, {T_REG, T_IND | T_REG}},
    {"add", 0x04, 3, {T_REG, T_REG, T_REG}},
    {"sub", 0x05, 3, {T_REG, T_REG, T_REG}},
    {"and", 0x06, 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}},
    {"or", 0x07, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}},
    {"xor", 0x08, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}},
    {"zjmp", 0x09, 1, {T_DIR}},
    {"ldi", 0x0a, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}},
    {"sti", 0x0b, 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}},
    {"fork", 0x0c, 1, {T_DIR}},
    {"lld", 0x0d, 2, {T_DIR | T_IND, T_REG}},
    {"lldi", 0x0e, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}},
    {"lfork", 0x0f, 1, {T_DIR}},
    {"aff", 0x10, 1, {T_REG}}
};
