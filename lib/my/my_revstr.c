/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** reverse a str
*/

char *my_revstr(char *str)
{
    int i = 0;
    int n = 0;
    int p;
    int cpy;

    while (str[n] != '\0')
        n = n + 1;
    p = n - 1;
    n = n / 2;
    while (n > 0) {
        cpy = str[i];
        str[i] = str[p];
        str[p] = cpy;
        n = n - 1;
        p = p - 1;
        i++;
    }
    return (str);
}
