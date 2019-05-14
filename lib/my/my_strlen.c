/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** return the number of char in the string
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
