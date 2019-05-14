/*
** EPITECH PROJECT, 2019
** exec.c
** File description:
** exec
*/

#include <sys/types.h>
#include <dirent.h>
#include "my.h"

char *not_dev(char *file)
{
    DIR *is_dir;

    is_dir = opendir(file);
    if (is_dir != NULL) {
        my_printf("%s: Not a directory.\n", file);
        return NULL;
    }
    if (my_strlen(file) > 2) {
        if (file[0] == '.' && file[1] == '/' && access(&file[2], X_OK) != -1)
            return (&file[2]);
    }
    my_printf("%s: Command not found.\n", file);
    return NULL;
}

char *search(char *file, char **env)
{
    int col = 0;
    int start = 0;
    char *path = NULL;

    while (env[col] != NULL) {
        if (env[col][0] == 'P' && env[col][1] == 'A' &&
            env[col][2] == 'T' && env[col][3] == 'H')
            break;
        col++;
    }
    do {
        path = strcpy_after(file, env[col], &start);
        if (path == NULL || access(path, X_OK) != -1)
            break;
    } while (path != NULL);
    if (path == NULL)
        return not_dev(file);
    return (path);
}

int exec(char *arg, char **env)
{
    command_t command;

    command.other_arg = tab_to_double(arg, ' ');
    command.first_arg = search(command.other_arg[0], env);
    if (command.first_arg == NULL)
        return 84;
    if (execve(command.first_arg, command.other_arg, env) == -1) {
        perror("mysh");
        return 84;
    } else
        return 0;
}
