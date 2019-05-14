/*
** EPITECH PROJECT, 2019
** my_strspecialcpy.c
** File description:
** special_cpy searching path
*/

#include "my.h"

int my_other_strlen(char const *str, int i)
{
    int res = 0;

    while (str[i] != ':' && str[i] != '\0') {
        i++;
        res++;
    }
    return (res);
}

char *separate(char *path, char const *src, int *start, int *i)
{
    while (src[*start] != '\0' && src[*start] != ':') {
        path[*i] = src[*start];
        *start = *start + 1;
        *i = *i + 1;
    }
    return path;
}

char *strcpy_after(char *dest, char const *src, int *start)
{
    int i = 0;
    int cpy_start;
    char *path = NULL;

    while (src[*start] != '\0' && src[*start] != '/')
        *start = *start + 1;
    path = malloc(sizeof(char) * (my_other_strlen(src, *start) + 2));
    if (path == NULL)
        return NULL;
    path = separate(path, src, start, &i);
    if (i == 0)
        return NULL;
    path[i] = '/';
    path[i + 1] = '\0';
    dest = my_strcat(path, dest);
    free(path);
    return dest;
}
