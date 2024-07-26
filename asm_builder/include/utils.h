/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** utils.h
*/

#ifndef _UTILS_
    #define _UTILS_

char *recover_path(const char *absolute_path);
char *recover_file_name(const char *absolute_path);
char *stradd(const char *str1, const char *str2);
char *change_extension(const char *file_name, const char *new_extension);
char **split_str(char *str, const char *separators);
int split_strlen(char **split_str);
void free_split_str(char **split_str);
bool is_num(const char *str);
bool is_correct_char(const char *str, const char *correct_char);

#endif
