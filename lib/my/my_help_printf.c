/*
** EPITECH PROJECT, 2018
** my_help_printf
** File description:
** store some functions for printf
*/

#include "my.h"

int space_handle(char *str, int *i, va_list va, int *p)
{
    char *stock;

    *i = *i + 1;
    stock = malloc(sizeof(char) * (my_strlen(str) + 1));
    *p = 0;
    while (str[*i] == ' ' || str[*i] >= '0' && str[*i] <= '9') {
        if (str[*i] >= '0' && str[*i] <= '9') {
            stock[*p] = str[*i];
            *p = *p + 1;
        }
        if (str[*i] == ' ' && str[*i - 1] <= '9' && str[*i - 1] >= '0')
            return (*p);
        *i = *i + 1;
    }
    stock[*p] = '\0';
    *p = number(stock);
    free(stock);
    return (0);
}

char flag_string(char *str, int p)
{
    int i = 0;

    while (i < p - my_strlen(str)) {
        my_putchar(' ');
        i++;
    }
    my_putstr(str);
}

int flag_nbr(int nb, int p)
{
    int i = 0;

    while (i < p - my_intlen(nb)) {
        my_putchar(' ');
        i++;
    }
    my_put_nbr(nb);
}

int flag_char(int letter, int p)
{
    int i = 0;

    while (i < p - 1) {
        my_putchar(' ');
        i++;
    }
    my_putchar(letter);
}
