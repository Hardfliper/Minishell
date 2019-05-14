/*
** EPITECH PROJECT, 2018
** my_strncpy
** File description:
** cpy until n
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int p = 0;

    while (p != n) {
        dest[p] = src[p];
        p++;
    }
    dest[p] = '\0';
    return (0);
}
