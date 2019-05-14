/*
** EPITECH PROJECT, 2019
** builtin.c
** File description:
** builtins
*/

#include "my.h"

int check_exit(char *command)
{
    int ok = 1;

    if (command[0] == 'e' && command[1] == 'x' &&
	command[2] == 'i' && command[3] == 't')
        ok = 0;
    else
        return 0;
    if (command[4] == '\0')
        return 1;
    if (ok == 0 && command[4] == ' ') {
        for (int i = 4; command[i] != '\0'; i++) {
            if (command[i] == ' ')
                return 1;
        }
    } else
        return 0;
}

void quit(char *command)
{
    if (check_exit(command) == 1) {
        my_putstr("exit\n");
	exit(0);
    }
}

int parsing(char **env, char *command)
{
    if (command[0] == 'c' && command[1] == 'd' &&
        (command[2] == '\0' || command[2] == ' ')) {
        cd_management(command, env);
        return 0;
    }
    quit(command);
    return 1;
}

int builtin(char **env, char **command)
{
    size_t size = 0;
    int i = 0;

    do {
        my_putstr("$> ");
        if (getline(command, &size, stdin) == -1)
            quit("exit");
    } while (check_no_command(*command) == 0);
    while (command[0][i] != '\0' && command[0][i] != '\n')
        i++;
    command[0][i] = '\0';
    if (parsing(env, command[0]) == 0)
        return 0;
    return 1;
}
