/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** concat 2 string
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    char *result = NULL;
    int i = 0;
    int o = 0;

    result = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
    if (result == NULL)
        return (NULL);
    while (dest[i] != '\0') {
        result[i] = dest[o];
        i++;
        o++;
    }
    o = 0;
    while (src[o] != '\0' && src[o] != '\n') {
        result[i] = src[o];
        i++;
        o++;
    }
    result[i] = '\0';
    return (result);
}
