/*
** EPITECH PROJECT, 2024
** asm_builder
** File description:
** op.c
*/

#include "../include/parser.h"

extern op_t op_tab[] = {
    {"live", 0x01, 1, {T_DIR}, false},
    {"ld", 0x02, 2, {T_DIR | T_IND, T_REG}, true},
    {"st", 0x03, 2, {T_REG, T_IND | T_REG}, true},
    {"add", 0x04, 3, {T_REG, T_REG, T_REG}, true},
    {"sub", 0x05, 3, {T_REG, T_REG, T_REG}, true},
    {"and", 0x06, 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, true},
    {"or", 0x07, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, true},
    {"xor", 0x08, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, true},
    {"zjmp", 0x09, 1, {T_IDX}, false},
    {"ldi", 0x0a, 3, {T_REG | T_IDX | T_IND, T_IDX | T_REG, T_REG}, true},
    {"sti", 0x0b, 3, {T_REG, T_REG | T_IDX | T_IND, T_IDX | T_REG}, true},
    {"fork", 0x0c, 1, {T_IDX}, false},
    {"lld", 0x0d, 2, {T_DIR | T_IND, T_REG}, true},
    {"lldi", 0x0e, 3, {T_REG | T_IDX | T_IND, T_IDX | T_REG, T_REG}, true},
    {"lfork", 0x0f, 1, {T_IDX}, false},
    {"aff", 0x10, 1, {T_REG}, true}
};
