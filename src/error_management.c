/*
** EPITECH PROJECT, 2019
** error_management
** File description:
** check errors cases
*/

#include "my.h"

int check_no_command(char *command)
{
    int i = 0;

    while (command[i] != '\0') {
        if (command[i] != ' ' && command[i] != '\n')
            return 1;
        i++;
    }
    return 0;
}
