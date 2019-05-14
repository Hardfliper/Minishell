/*
** EPITECH PROJECT, 2019
** alloc for tab to double
** File description:
** allocs functions
*/

#include "my.h"

char **right_malloc(char **dbl_str, tab_t tab, char chr, char *str)
{
    dbl_str[tab.y] = malloc(sizeof(char) * line_len(str, tab.i, chr));
    if (dbl_str[tab.y] == NULL)
        return NULL;
    return (dbl_str);
}

char **alloc_lines(char *str, tab_t tab, char chr)
{
    char **dbl_str = NULL;

    dbl_str = malloc(sizeof(char*) * (line_nb(str, chr) + 1));
    dbl_str[0] = malloc(sizeof(char) * line_len(str, tab.i, chr));
    if (dbl_str[0] == NULL)
        return NULL;
    while (str[tab.i] != '\0') {
        if (str[tab.i] == chr && str[tab.i + 1] != '\0') {
            dbl_str[tab.y][tab.x] = '\0';
            tab.y = tab.y + 1;
            tab.i = tab.i + 1;
            if (right_malloc(dbl_str, tab, chr, str) == NULL)
                return NULL;
            tab.x = 0;
        }
        dbl_str[tab.y][tab.x] = str[tab.i];
        tab.x = tab.x + 1;
        tab.i = tab.i + 1;
    }
    return (end_alloc(dbl_str, tab.y, tab.x));
}
