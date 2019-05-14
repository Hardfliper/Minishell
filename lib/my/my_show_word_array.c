/*
** EPITECH PROJECT, 2019
** my_show_word_array
** File description:
** show a word array
*/

#include "my.h"

void my_show_word_array(char **str)
{
    int y = 0;

    while (str[y] != NULL) {
        my_putstr(str[y]);
        my_putchar('\n');
        y++;
    }
    return;
}
