/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** printf
*/

#include "my.h"

int flag_verify(char *str, int i)
{
    while (str[i] == ' ' || str[i] >= '0' && str[i] <= '9') {
        if (str[i] == ' ' && str[i - 1] <= '9' && str[i - 1] >= '0')
            return (1);
        i = i + 1;
    }
    return (0);
}

char basic_flag(char *str, va_list va, int i, int p)
{
    switch (str[i]) {
    case 's' :
        flag_string(va_arg(va, char*), p);
        i++;
        break;
    case 'd' :
    case 'i' :
        flag_nbr(va_arg(va, int), p);
        i++;
        break;
    case 'c' :
        flag_char(va_arg(va, int), p);
        i++;
        break;
    default :
        return (0);
    }
    return (0);
}

void no_flag(char *str, int *i)
{
    my_putchar(str[*i]);
    my_putchar(str[*i + 1]);
    *i = *i + 1;
    while (str[*i] == ' ')
        *i = *i + 1;
    *i = *i - 1;
    return;
}

void put_string_char(char *str, int i)
{
    if (str[i] == '\\')
        switch (str[i + 1]) {
        case 'n' :
            my_putchar('\n');
            break;
        case 't' :
            my_putchar('\t');
            break;
        default :
            my_putchar('\\');
        }
    else
        my_putchar(str[i]);
}

void my_printf(char *str, ...)
{
    va_list va;
    int p = 0;

    va_start(va, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%' && flag_verify(str, i + 1) == 0) {
            space_handle(str, &i, va, &p);
            basic_flag(str, va, i, p);
        } else if (str[i] == '%' && flag_verify(str, i + 1) == 1)
            no_flag(str, &i);
        else
            put_string_char(str, i);
    }
    va_end(va);
    return;
}
