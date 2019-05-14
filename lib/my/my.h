/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** remove warnings
*/

#ifndef MY_H
#define MY_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct dbl_tab {
    int y;
    int x;
    int i;
}tab_t;

void my_show_word_array(char **str);
char **tab_to_double(char *str, char chr);
char **right_malloc(char **dbl_str, tab_t tab, char chr, char *str);
char **alloc_lines(char *str, tab_t tab, char chr);
int my_intlen(int nb);
void my_put_error(char *str);
void my_printf(char *str, ...);
void my_putchar(char c);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_revstr(char *str);
int my_put_nbr(int nb);
int number(char *str);
int my_putstr(char const *str);
int flag_nbr(int nb, int p);
int space_handle(char *str, int *i, va_list va, int *p);
char flag_string(char *str, int p);
int line_len(char *str, int i, char chr);
int line_double(char **str);
int line_nb(char *str, char chr);
char **end_alloc(char **dbl_str, int y, int x);
int flag_char(int letter, int p);

#endif
