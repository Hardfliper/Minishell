/*
** EPITECH PROJECT, 2019
** my_put_error
** File description:
** write in the error output
*/

#include <unistd.h>

void my_putchar_err(char c)
{
    write(2, &c, 1);
}

void my_put_error(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar_err(str[i]);
        i = i + 1;
    }
    return;
}
