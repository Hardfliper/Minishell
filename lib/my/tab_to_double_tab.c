/*
** EPITECH PROJECT, 2018
** tab_to_double_tab
** File description:
** transform a * to **
*/

#include "my.h"

int line_double(char **str)
{
    int x = 0;
    int y = 0;

    while (str[y] != NULL) {
        if (str[y][x] == '\0')
            y++;
        x++;
    }
    return (y);
}

int line_len(char *str, int i, char chr)
{
    int len = 0;
    char letter = '\n';

    while (str[i] != '\0') {
        if (str[i] == chr || str[i] == '\0')
            return (len + 1);
        i++;
        len++;
    }
    len++;
    return (len);
}

int line_nb(char *str, char chr)
{
    int i = 0;
    int res = 1;

    while (str[i] != '\0') {
        if (str[i] == chr)
            res++;
        i++;
    }
    return (res);
}

char **end_alloc(char **dbl_str, int y, int x)
{
    if (dbl_str[y][x - 1] == '\n')
        dbl_str[y][x - 1] = '\0';
    else
        dbl_str[y][x] = '\0';
    dbl_str[y + 1] = NULL;
    return (dbl_str);
}

char **tab_to_double(char *str, char chr)
{
    tab_t tab;

    tab.i = 0;
    tab.y = 0;
    tab.x = 0;
    return (alloc_lines(str, tab, chr));
}
