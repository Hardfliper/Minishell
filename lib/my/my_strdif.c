/*
** EPITECH PROJECT, 2018
** my_strdif
** File description:
** compare two strings
*/

int my_strdif(char *str1, char *str2)
{
    int verify1 = 0;
    int verify2 = 0;

    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] != str2[i])
            verify1 = 1;
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        if (str2[i] != str1[i])
            verify2 = 1;
    }
    if (verify1 == 1 || verify2 == 1)
        return (1);
    else
        return (0);
}
